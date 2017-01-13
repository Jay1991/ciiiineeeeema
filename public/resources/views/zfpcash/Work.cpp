//////////////////////////////////////////////////////////////////////
// Copyright (c) 2005,2008 Tremol Ltd.
// License: Mozilla Public License 1.1
// Contacts: software@tremol.bg
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "zfpexe.h"
#include "CashFileMan.h"
#include "Work.h"

static const TCHAR g_szError[] = _T("Грешка - Zeka FP");
static const TCHAR g_szInfo[] = _T("Zeka FP");

// Zeka FP работи с ASCII кодова таблица cp1251
static BYTE szAlphabeEncode[256];      // Азбуката за конвертиране DOS COMP -> ECR
static BYTE szAlphabeDecode[256];      // Азбуката за конвертиране ECR  -> DOS COMP

static BOOL g_isOEM = FALSE;
static BOOL g_isStdErr = FALSE;
static BOOL g_isErrMsg = FALSE;
static BOOL g_isInfoMsg = FALSE;
static int g_counter = 0;
static int g_errors = 0;
static int g_processed = 0;
static BYTE g_operator = 0;
static char g_password[6] = "";

void InitGlobals()
{
	g_isOEM = g_AutoIni.GetInt(szMain, szEncoding, IDC_DOS) == IDC_DOS ? TRUE : FALSE;
	g_isStdErr = g_AutoIni.GetInt(szMain, szErrorType, IDC_STANDARD) == IDC_STANDARD ? TRUE : FALSE;
	g_isErrMsg = g_AutoIni.GetInt(szMain, szErrorMsg, FALSE);
	g_isInfoMsg = g_AutoIni.GetInt(szMain, szInfoMsg, FALSE);
	g_counter = g_errors = g_processed = 0;
	g_operator = g_AutoIni.GetInt(szMain, szOperator, 0);
	g_AutoIni.GetString(szMain, szPassword, "0000", g_password, 5);
}

///////////////////////////////////////////////////////////////////////////
// Инициализира преобразуващата таблица за символите
void InitOEMTables()
{
int iCounter;
	for (iCounter = 0x00; iCounter <= 0xFF; iCounter++)			// Инициализация
		szAlphabeEncode[iCounter] = ' ';
	for (iCounter = 0x21; iCounter <= 0x7F; iCounter++)			// от "!" до "'"
		szAlphabeEncode[iCounter] = (BYTE)(iCounter);
	for (iCounter = 0xC0; iCounter <= 0xFF; iCounter++)			// кирилица
		szAlphabeEncode[iCounter] = (BYTE)(iCounter - 0x40);		

	for (iCounter = 0x00; iCounter <= 0xFF; iCounter++)			// Инициализация
		szAlphabeDecode[iCounter] = ' ';
	for (iCounter = 0x21; iCounter <= 0x7F; iCounter++)			// от "!" до "~"
		szAlphabeDecode[iCounter] = (BYTE)(iCounter);
	for (iCounter = 0x80; iCounter <= 0xBF; iCounter++)			// кирилица
		szAlphabeDecode[iCounter] = (BYTE)(iCounter + 0x40);		
}
///////////////////////////////////////////////////////////////////////////
// Преобразува във валидни за касовия притер символи
void MyOEMConvert(BYTE* szText, BOOL bEncode)
{
int iCounter = 0;
	while (szText[iCounter] != 0) {
		if (bEncode)
			szText[iCounter] = szAlphabeEncode[(WORD)szText[iCounter]];
		else
			szText[iCounter] = szAlphabeDecode[(WORD)szText[iCounter]];
		iCounter++;
	}
}
///////////////////////////////////////////////////////////////////////////
void DoError(TFileLine* cur, int zfpError, int lineError, const char* lineErrorSz)
{
	char szErr[12];
	if (g_isStdErr)
		sprintf(szErr, "%06d,%1d,%-2s", 123456, ++g_counter % 10, lineErrorSz);
	else
		sprintf(szErr, "%06d,%1d,%02d", 123456, ++g_counter % 10, lineError);
	memcpy(&cur->line[cur->startIndex], szErr, 11);

	if (g_isErrMsg) {
		CString msg;
		msg.Format("Възникна грешка при обработката на ред: %d\r\n\r\n", cur->lineNum);

		char line[MAX_LINE_LEN];
		strcpy(line, cur->line);
		if (g_isOEM)
			MyOEMConvert((BYTE *)line, FALSE);

		msg += line;
		msg += "\r\n\r\n";
		
		if (ZFPE_SUCCESS != zfpError) {
			char buf[ZFP_MAXERRORBUFLEN];
			CZekaFP::GetErrorString(zfpError, ZFP_LANG_BG, buf);
			msg += buf;
		}
		::MessageBox(0, msg, g_szError, MB_OK | MB_ICONERROR);
	}

	g_counter = 0;
	g_errors++;
}
///////////////////////////////////////////////////////////////////////////
void DoOK(TFileLine* cur)
{
	char szErr[12];
	sprintf(szErr, "%06d,%1d,%-2s", 123456, ++g_counter % 10, g_isStdErr ? "Ok" : "00");
	memcpy(&cur->line[cur->startIndex], szErr, 11);
	g_processed++;
}
///////////////////////////////////////////////////////////////////////////
// При Zeka FP всички отстъпки и надбавки са в самите операции
// затова е нужно да сканираме дали следващата фискална операция е отстъпка/надбавка
///////////////////////////////////////////////////////////////////////////
double GetDiscount(TFileLine* cur1)
{
	TFileLine* cur = cur1->next;
	while (cur) {
		switch (cur->line[0]) {
		case 'F':
		case 'H':
		case 'B': break;
		
		case 'C': {
					int type;
					double percents = 0;
					int scaned = sscanf(&cur->line[cur->startIndex + 12], "%d;%lf", 
						&type, &percents);
					if (2 == scaned) {
						if (type)
							percents = -percents;
						DoOK(cur);
						return percents;			
					}
					return 0.0;
				  }

		default: return 0.0;
		}
		cur = cur->next;
	}
	return 0.0;
}

const int g_monthDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int GetDaysInMonth(int month, int year){
	
	int days = g_monthDays[month-1];
	

	if ((month == 2) && !(year % 4)){
		days++;
	}
	return days;
}

///////////////////////////////////////////////////////////////////////////
int DoProcess(CZekaFP& zfp, CCashFileMan& cf)
{
	int res = 0;

	TFileLine* cur = cf.m_root;
	BOOL bOpenBon = FALSE;
	BOOL bOpenFiscalBon = FALSE;
	BOOL bToOpenFisc = FALSE;
	if (cur && cur->process && cur->line[0] == 'P'){
		while (cur && !bToOpenFisc) {
			if (cur->process) {
				switch (cur->line[0]) {
				case 'S': 
				case ':':  {
							
							bToOpenFisc = TRUE;
							break;
						  }				


				}
			}

			
			cur = cur->next;
		}
	}

	cur = cf.m_root;
	
	while (cur) {
		TRACE("INPUT: %s\n", cur->line);
		if (cur->process) {
			DoOK(cur);
			switch (cur->line[0]) {
			case 'S': {
						char name[50], line[MAX_LINE_LEN];
						double price = 0, quantity = 0;
						int s, g, taxGrp;

						strcpy(line, cur->line);
						if (g_isOEM)
							MyOEMConvert((BYTE *)line, FALSE);
			
						char* delimiter = strchr(&line[cur->startIndex + 12], ';');
						if (NULL == delimiter) {
							DoError(cur, ZFPE_SUCCESS, 5, "Er");
							cur = cur->next;
							continue;
						}

						*delimiter = 0;
						strcpy(name, &line[cur->startIndex + 12]);
						*delimiter = ';';

						int scaned = sscanf(delimiter + 1, "%lf;%lf;%d;%d;%d", 
							&price, &quantity, &s, &g, &taxGrp);

						if (5 != scaned) {
							DoError(cur, ZFPE_SUCCESS, 5, "Er");
							cur = cur->next;
							continue;
						}

						if (!(bOpenBon || bOpenFiscalBon))
						{
							zfp.SetPrintMode( PMFLAG_FISCAL_RECEIPT | PMFLAG_DEFER_PRINT );
							int err = zfp.OpenFiscalBon(g_operator + 1, g_password, FALSE, 0);
							/*if (ZFPE_SUCCESS != err) {
								DoError(cur, err, 2, "Er");
								cur = cur->next;
								continue;
							}*/
							if (0x109 == err) { // no Zeka FP
								CString text;
								if (g_isErrMsg) {
									text.LoadString(IDS_NOZEKAFP);
									::MessageBox(0, text, g_szError, MB_OK | MB_ICONERROR);
								}
								return 1;
							}
							if ((ZFPE_SUCCESS != err) && (0x42 != err)) {
								DoError(cur, err, 5, "Er");
								return 11;
							}
							bOpenFiscalBon = TRUE;
						}

						int err = zfp.SellFree(name, taxGrp + 0xC0 - 1, price, quantity, GetDiscount(cur));
						if (ZFPE_SUCCESS != err) {
							DoError(cur, err, 2, "Er");
							cur = cur->next;
							continue;
						}

						break;
					  }
			case ':': {
						char line[MAX_LINE_LEN];
						double price = 0, quantity = 0, discP = 0, discS = 0;
						int plu = 0, dep =0;

						strcpy(line, cur->line);
						if (g_isOEM)
							MyOEMConvert((BYTE *)line, FALSE);
			
						char* delimiter = strchr(&line[cur->startIndex], ';');
						if (NULL == delimiter) {
							DoError(cur, ZFPE_SUCCESS, 5, "Er");
							cur = cur->next;
							continue;
						}
						
						*delimiter = ';';

						int scaned = sscanf(delimiter + 1, "%d;%d;%lf;%lf;%lf", 
							&plu, &dep, &quantity, &discP, &discS);

						if (5 != scaned) {
							DoError(cur, ZFPE_SUCCESS, 5, "Er");
							cur = cur->next;
							continue;
						}

						if (!(bOpenBon || bOpenFiscalBon))
						{
							zfp.SetPrintMode( PMFLAG_FISCAL_RECEIPT | PMFLAG_DEFER_PRINT );
							int err = zfp.OpenFiscalBon(g_operator + 1, g_password, FALSE, 0);
							/*if (ZFPE_SUCCESS != err) {
								DoError(cur, err, 2, "Er");
								cur = cur->next;
								continue;
							}*/
							if (0x109 == err) { // no Zeka FP
								CString text;
								if (g_isErrMsg) {
									text.LoadString(IDS_NOZEKAFP);
									::MessageBox(0, text, g_szError, MB_OK | MB_ICONERROR);
								}
								return 1;
							}
							if ((ZFPE_SUCCESS != err) && (0x42 != err)) {
								DoError(cur, err, 5, "Er");
								return 11;
							}
							bOpenFiscalBon = TRUE;
						}

						int err = zfp.SellDBEx(FALSE, plu, quantity, (discP != 0)? discP : discS, (discP != 0)? 0 : 1);
						if (ZFPE_SUCCESS != err) {
							DoError(cur, err, 2, "Er");
							cur = cur->next;
							continue;
						}

						break;
					  }

			case 'P': {
						char line[MAX_LINE_LEN];
						strcpy(line, cur->line);
						if (g_isOEM)
							MyOEMConvert((BYTE *)line, FALSE);

						if (!(bOpenBon || bOpenFiscalBon))
						{
							if (bToOpenFisc)
							{
								zfp.SetPrintMode( PMFLAG_FISCAL_RECEIPT | PMFLAG_DEFER_PRINT );
								int err = zfp.OpenFiscalBon(g_operator + 1, g_password, FALSE, 0);
								/*if (ZFPE_SUCCESS != err) {
									DoError(cur, err, 2, "Er");
									cur = cur->next;
									continue;
								}*/
								if (0x109 == err) { // no Zeka FP
									CString text;
									if (g_isErrMsg) {
										text.LoadString(IDS_NOZEKAFP);
										::MessageBox(0, text, g_szError, MB_OK | MB_ICONERROR);
									}
									return 1;
								}
								if ((ZFPE_SUCCESS != err) && (0x42 != err)) {
									DoError(cur, err, 5, "Er");
									return 11;
								}
								bOpenFiscalBon = TRUE;
							}
							else {
								int err = zfp.OpenBon(1, g_password);
								if (ZFPE_SUCCESS != err) {
									DoError(cur, err, 2, "Er");
									cur = cur->next;
									continue;
								}
									
								bOpenBon = TRUE;
							}
						}

						char* newLine = strtok(&line[cur->startIndex + 12], ";");
						int err = ZFPE_SUCCESS;
						while (newLine) {
							err |= zfp.PrintText(newLine);
							newLine = strtok(NULL, ";");
						}
						if (ZFPE_SUCCESS != err) {
							DoError(cur, err, 2, "Er");
							cur = cur->next;
							continue;
						}
						break;
					  }

			case 'Z': {
				
						char line[MAX_LINE_LEN];
						int opt, yy, mm = 0;
						bool ext = true;;

						strcpy(line, cur->line);
						if (g_isOEM)
							MyOEMConvert((BYTE *)line, FALSE);
			
						char* delimiter = strchr(&line[cur->startIndex], ';');
						if (NULL == delimiter) {
							DoError(cur, ZFPE_SUCCESS, 5, "Er");
							cur = cur->next;
							continue;
						}						
						*delimiter = ';';

						int scaned = sscanf(delimiter + 1, "%d", 
							&opt);

						if (1 != scaned) {
							DoError(cur, ZFPE_SUCCESS, 5, "Er");
							cur = cur->next;
							continue;
						}						

						int err;
						switch(opt){
						case 0: 									
							err = zfp.ReportDaily(FALSE, TRUE);	
							break;
						
						case 1: 
							err = zfp.ReportDaily(TRUE, TRUE);	
							break;
								
						case 2: 
								ext = false;
						case 3:
								delimiter = strchr(delimiter + 1, ';');
								if (NULL == delimiter) {
									DoError(cur, ZFPE_SUCCESS, 5, "Er");
									cur = cur->next;
									continue;
								}
								*delimiter = ';';

								scaned = sscanf(delimiter + 1, "%d", 
									&yy);
								if (1 != scaned) {
									DoError(cur, ZFPE_SUCCESS, 5, "Er");
									cur = cur->next;
									continue;
								}	
								
								delimiter = strchr(delimiter + 1, ';');
								if (NULL == delimiter) {
									DoError(cur, ZFPE_SUCCESS, 5, "Er");
									cur = cur->next;
									continue;
								}
								*delimiter = ';';

								if (*(delimiter + 1) != ';'){
									scaned = sscanf(delimiter + 1, "%d", 
										&mm);
									if ((1 != scaned) || (mm > 12) || (mm <1)){
										DoError(cur, ZFPE_SUCCESS, 5, "Er");
										cur = cur->next;
										continue;
									}	
									err = zfp.ReportFiscalByDate(ext, 1, mm, yy, GetDaysInMonth(mm, 2000 + yy), mm, yy);
								}
								else {										
										
									err = zfp.ReportFiscalByDate(ext, 1, 1, yy, 31, 12, yy);																		
								}								
							
								break;
								

						}
						
						
						if (ZFPE_SUCCESS != err) {
							DoError(cur, err, 2, "Er");
							cur = cur->next;
							continue;
						}
						
						break;
					  }

			case 'D': {
						int err = zfp.PrintDuplicate();
						zfp.BusyWait(ZFP_INFINITE);
						if (ZFPE_SUCCESS != err) {
							DoError(cur, err, 2, "Er");
							cur = cur->next;
							continue;
						}
						break;
					  }

			case 'Y': {
						int err = zfp.OpenBon(1, g_password);
						if (ZFPE_SUCCESS != err) {
							DoError(cur, err, 2, "Er");
							cur = cur->next;
							continue;
						}
							
						bOpenBon = TRUE;

						char line[MAX_LINE_LEN];
						strcpy(line, cur->line);
						if (g_isOEM)
							MyOEMConvert((BYTE *)line, FALSE);
						
						char* newLine = strtok(&line[cur->startIndex + 12], ";");
						while (newLine) {
							if (0 < strlen(newLine))
								zfp.PrintText(newLine);
	
							newLine = strtok(NULL, ";");
						}
						break;
					  }

			case 'I': {
						int type;
						double sum;
						int scaned = sscanf(&cur->line[cur->startIndex + 12], "%d;%lf", 
							&type, &sum);
						if (2 != scaned) {
							DoError(cur, ZFPE_SUCCESS, 5, "Er");
							cur = cur->next;
							continue;
						}
						if (type) 
							sum = -sum;

						int err = zfp.OfficialSums(1, "0000", 0, sum);
						if (ZFPE_SUCCESS != err) {
							DoError(cur, err, 2, "Er");
							cur = cur->next;
							continue;
						}
						break;
					  }

			case 'T': {
						int type;
						double sum;
						int scaned = sscanf(&cur->line[cur->startIndex + 12], "%d;%lf", 
							&type, &sum);

						switch (scaned) {
						case -1: 
						case 0: 
							if (bOpenBon)
							{
								zfp.CloseBon();
								bOpenBon = FALSE;
							}
							else {
								double intSum;
								int err = zfp.CalcIntermediateSum(&intSum);
								if (ZFPE_SUCCESS != err) {
									DoError(cur, err, 2, "Er");
									cur = cur->next;
									continue;
								}
								if (0.0f < intSum) {
									err = zfp.Payment(intSum);
									if (ZFPE_SUCCESS != err) {
										DoError(cur, err, 2, "Er");
										cur = cur->next;
										continue;
									}
								}

								err = zfp.CloseFiscalBon();
								if (ZFPE_SUCCESS != err)
								{
									DoError(cur, err, 2, "Er");
									cur = cur->next;
									continue;
								}
								else bOpenFiscalBon = FALSE;
							}

							break;

						case 1:
							if (4 == type) {
								double intSum;
								int err = zfp.CalcIntermediateSum(&intSum, 
									ZFP_ISPRINT | ZFP_ISSHOW | ZFP_ISPERCENT, GetDiscount(cur));
								if (ZFPE_SUCCESS != err) {
									DoError(cur, err, 2, "Er");
									cur = cur->next;
									continue;
								}
							}
							break;

						case 2: {
									int err = zfp.Payment(sum, type);
									if (ZFPE_SUCCESS != err) {
										DoError(cur, err, 2, "Er");
										cur = cur->next;
										continue;
									}

									// The receipt will not close if not entirely paid
									err = zfp.CloseFiscalBon(); 
									if (ZFPE_SUCCESS == err)
										bOpenFiscalBon = FALSE;
								}

							break;

						default:
							DoError(cur, ZFPE_SUCCESS, 5, "Er");
							cur = cur->next;
							continue;

							break;
						}

						break;
					  }
			}
		}

		TRACE("OUTPUT: %s\n", cur->line);

		cur = cur->next;
	}

	if (bOpenBon) {
		zfp.CloseBon();
		bOpenBon = FALSE;
	}
	else if (bOpenFiscalBon) {				
		int err = zfp.CloseBonInCash();
		if (ZFPE_SUCCESS != err)
		{
			DoError(cur, err, 2, "Er");						
		}
		else bOpenFiscalBon = FALSE;
	}

	return res;
}

///////////////////////////////////////////////////////////////////////////
int DoWork()
{
	InitGlobals();
	InitOEMTables();

	WORD wCom = g_AutoIni.GetInt(szMain, szComPort, 0);
	DWORD temp, baud = g_AutoIni.GetInt(szMain, szBaudRate, 0);

	switch (baud)
	{
	case 1: baud = 9600; break;
	case 2: baud = 19200; break;
	case 3: baud = 38400; break;
	case 4: baud = 57600; break;
	case 5: baud = 115200; break;
	default: baud = 0; break;
	}

	int inputarg = 3;

	// process the parameters
	char* szCom = strdup(__argv[1]);
	strupr(szCom);
	
	if (szCom[0] == 'C') { // command line C??????
		if (0 == sscanf(szCom, "COM%u", &wCom)) {
			if (1 <= __argc) // not COMx ... should be file name
				inputarg = 1;
		}
		else {
			if ((__argc > 2) && (1 == sscanf(__argv[2], "%u", &temp))) { // a number ? 
				if (temp == 9600 || temp == 19200 || temp == 38400 || temp == 57600 || temp == 115200)
				{ // is this number a baud rate?
					baud = temp;
					inputarg = 3;
				}
				else
				{
					if (g_isErrMsg)
					{
						CString msg, syntax;
						msg.Format(IDS_BADCOM, __argv[2]);
						syntax.LoadString(IDS_SYNTAX);
						msg += _T("\r\n\r\n");
						msg += syntax;
						::MessageBox(0, msg, g_szError, MB_OK | MB_ICONERROR);
					}
					return 1;
				}
			}
			else {
				inputarg = 2;
			}
		}
	}
	else {
		if (1 == sscanf(szCom, "%u", &temp)) { // command line start with a number
			if (temp == 9600 || temp == 19200 || temp == 38400 || temp == 57600 || temp == 115200)
			{ // is this number a baud rate?
				baud = temp;
				inputarg = 2;
			}
			else {
				if (255 >= temp) { // I assume no COM bigger than 255
					wCom = (WORD)temp;
					if ((__argc > 2) && (1 == sscanf(__argv[2], "%u", &temp))) { // a number ? 
						if (temp == 9600 || temp == 19200 || temp == 38400 || temp == 57600 || temp == 115200)
						{ // is this number a baud rate?
							baud = temp;
							inputarg = 3;
						}
						else {
							if (g_isErrMsg) {
								CString msg, syntax;
								msg.Format(IDS_BADCOM, __argv[2]);
								syntax.LoadString(IDS_SYNTAX);
								msg += _T("\r\n\r\n");
								msg += syntax;
								::MessageBox(0, msg, g_szError, MB_OK | MB_ICONERROR);
							}
							return 1;
						}
					}
					else {
						inputarg = 2;
					}
				}
				else {
					if (g_isErrMsg) {
						CString msg, syntax;
						msg.Format(IDS_BADCOM, __argv[1]);
						syntax.LoadString(IDS_SYNTAX);
						msg += _T("\r\n\r\n");
						msg += syntax;
						::MessageBox(0, msg, g_szError, MB_OK | MB_ICONERROR);
					}
					return 1;
				}
			}
		}
		else { // first parameter is not a number
			inputarg = 1;
		}
	}

	free(szCom);

	CString text;
	// get automatic COM and baud rates
	if ((0 == wCom) && (0 == baud))
	{
		temp = CZekaFP::FindFirstFPCOMEx();
		if (0 == temp)
		{
			if (g_isErrMsg)
			{
				text.LoadString(IDS_NOZEKAFP);
				::MessageBox(0, text, g_szError, MB_OK | MB_ICONERROR);
			}
			return 5;
		}
		wCom = (WORD)(temp >> 24);
		baud = temp & 0x00FFFFFF;
	}
	else {
		if (0 == wCom) {
			wCom = CZekaFP::FindFirstFPCOMbyBaud(baud);
			if (0 == wCom) {
				if (g_isErrMsg) {
					text.LoadString(IDS_NOZEKAFP);
					::MessageBox(0, text, g_szError, MB_OK | MB_ICONERROR);
				}
				return 6;
			}
		}
		else if (0 == baud) {
			baud = CZekaFP::FindBaudByCOM(wCom);
			if (0 == baud) {
				if (g_isErrMsg) {
					text.LoadString(IDS_NOZEKAFP);
					::MessageBox(0, text, g_szError, MB_OK | MB_ICONERROR);
				}
				return 7;
			}
		}
	}

	char szInputFile[MAX_PATH], szOutputFile[MAX_PATH] = "";

	// input file processing
	if (__argc > inputarg)
		strcpy(szInputFile, __argv[inputarg]);
	else
		g_AutoIni.GetString(szMain, szInput, szEmpty, szInputFile, MAX_PATH);
	
	// output file processing
	if (__argc > inputarg + 1)
		strcpy(szOutputFile, __argv[inputarg + 1]);
	else {
		int iUseOutput = g_AutoIni.GetInt(szMain, szUseOutput, 0);
		if (iUseOutput)
			g_AutoIni.GetString(szMain, szOutput, szEmpty, szOutputFile, MAX_PATH);
		if (0 == strlen(szOutputFile)) 
			strcpy(szOutputFile, szInputFile);
	}

	if ((0 == strlen(szOutputFile)) || (0 == strlen(szInputFile))) {
		if (g_isErrMsg) {
			CString msg, syntax;
			msg.Format(IDS_BADINOUTFILE, szInputFile, szOutputFile);
			syntax.LoadString(IDS_SYNTAX);
			msg += _T("\r\n\r\n");
			msg += syntax;
			::MessageBox(0, msg, g_szError, MB_OK | MB_ICONERROR);
		}
		return 2;
	}

	CCashFileMan cf;
	if (!cf.LoadFile(szInputFile)) {
		if (g_isErrMsg) {
			CString msg;
			msg.Format(IDS_BADINFILE, szInputFile);
			::MessageBox(0, msg, g_szError, MB_OK | MB_ICONERROR);
		}
		return 3;
	}

	short _port = (short)wCom;
	if ( _port > 0 ) _port = -_port;
	CZekaFP zfp((WORD)_port, baud);
	zfp.SetAutoBusyWait(ZFP_INFINITE);
	DoProcess(zfp, cf);

	if (!cf.WriteFile(szOutputFile)) {
		if (g_isErrMsg) {
			CString msg;
			msg.Format(IDS_BADOUTFILE, szOutputFile);
			::MessageBox(0, msg, g_szError, MB_OK | MB_ICONERROR);
		}
		return 4;
	}

	if (g_isInfoMsg) {
		CString msg;
		msg.Format(g_errors ? IDS_SUCCESSERRORS : IDS_SUCCESS, g_processed, g_errors);
		::MessageBox(0, msg, g_szInfo, MB_OK | g_errors ? MB_ICONEXCLAMATION : MB_ICONINFORMATION);
	}
	
	return 0;
}