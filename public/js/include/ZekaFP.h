//////////////////////////////////////////////////////////////////////
// Copyright (c) 2005-2008 Tremol Ltd.
// License: Mozilla Public License 1.1
// Contacts: software@tremol.bg
//////////////////////////////////////////////////////////////////////

#ifndef _ZEKAFPCLASS_
#define _ZEKAFPCLASS_

#ifdef POSIX
typedef int                 BOOL;
typedef unsigned char       BYTE;
typedef unsigned short      WORD;
//typedef unsigned int        DWORD;
#define DWORD               unsigned int

#define MAKEWORD(a, b)      (((WORD)((BYTE)a)) | ((WORD)((BYTE)b)) << 8 )
#define MAKELONG(a, b)      (((DWORD)((WORD)a)) | ((DWORD)((WORD)b)) << 16 )
#endif

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#include "ZekaFPdefs.h"

#define MAX_NUM_LEN		16

// Receipt print mode
#define PMFLAG_SAVE               0x40000000 // Save mode to Registry
#define PMFLAG_DEFER_PRINT        0x00000001 // Print all sale lines when closing receipt (0=print immediately)
#define PMFLAG_KEEP_OPEN_COM      0x00000002 // Keep open Com port until CloseBon() (0=open & close for each line)
#define PMFLAG_FISCAL_RECEIPT     0x00000004 // Apply flag 1 & 2 for fiscal receipt
#define PMFLAG_NONFISCAL_RECEIPT  0x00000008 // Apply flag 1 & 2 for non-fiscal receipt
#define PMFLAG_ONE_TIME           0x00000010 // Use flags for next receipt only (0=permanent)

class CSerialA;

class CZekaFP  
{
private:
	int _SetLogoFile(int logo_id, const char* filename);
	int GSCmdPrepare(CSerialA * serial, BOOL checkPrn = TRUE);
	BOOL PrintModeFlag(DWORD flag);

public:
	CZekaFP();
	CZekaFP(WORD wCom, DWORD baud = ZBR_9600, WORD retries = 3, DWORD retryWait = 1000);
	virtual ~CZekaFP();

public:
	void Setup(WORD wCom, DWORD baud = ZBR_9600, WORD retries = 3, DWORD retryWait = 1000);
	WORD GetCOM();
	DWORD GetBaudRate();
	int GetInputBuffer(BYTE* buf);
	int GetResponseBuffer(BYTE* buf);
	void GetInputHexFormated(char* buf);
	void GetResponseHexFormated(char* buf);
	
	int SetZFPType(int type); // ZFPT_BG or ZFPT_RO
	int GetZFPType();

	int BusyWait(DWORD timeout);
	void SetAutoBusyWait(DWORD timeout);
	int SendCommandDirect(const char* cmd, char* data = NULL, BYTE* len = NULL);

	static void GetErrorString(int error, int lang, char* buf);
	static int GetLibraryVersion();


//////////////////////////////////////////////////////////////////////
// Commands
//////////////////////////////////////////////////////////////////////
	int GetStatus(BYTE* status);
	int GetVersion(char* version);
	int Diagnostic();
	int DisplayClear();
	int DisplayLine1(const char* line);
	int DisplayLine2(const char* line);
	int Display(const char* line);
	int DisplayDateTime();
	int PaperCut();
	int OpenTill();
	int OpenTillEx(char num);
	int LineFeed();
	int OpenSerialPort();
	int CloseSerialPort();

	int TerminateBon(BOOL);
	int GetFactFiscNums(char* factory, char* fiscal);
	int GetTaxNumber(char* taxnumber);
	int GetTaxPercents(double* tgr1, double* tgr2, double* tgr3, double* tgr4 = NULL);
	int GetDecimalPoint(int* point);
	int GetPayTypes(char* type1, char* type2, char* type3, char* type4, char* type5);
	int GetParameters(int* fpNum, int* logo, int* till, int* autocut, int* transparent);
	int GetEJMode(int* isShort);
	int GetDateTime(int* dd, int* mm, int* yy, int* hh, int* mmm);
	int GetClicheLine(BYTE lineNum, char* text);
	int GetDepartment(WORD number, char* name, char* taxgrp, double* turnover);
	int GetDepartmentEx(WORD number, char* name, char* taxgrp, double* turnover, double* quantity, WORD* counter, int* dd, int* mm, int* yy, int* hh, int* mmm);
	int GetOperatorUserPass(BYTE oper, char* name, char* passwd);
	int PrintLogo();
	int PrintLogoEx(BYTE logo);
	int OpenBon(BYTE oper, const char* passwd);
	int OpenBonWithEJ(BYTE oper, const char* passwd, BOOL hasEJ);
	int CloseBon();
	int CloseBonInCash();
	int CloseBonCancel();
	int OpenFiscalBon(BYTE oper, const char* passwd, BYTE detailed, BYTE dds);
	int OpenInvoice(BYTE oper, const char* passwd, const char* client, const char* receiver, 
		const char* vatNum, const char* identNum, const char* address);
	int SellFree(const char* name, char taxgrp, double price, double quantity = 1.0, double discount = 0.0);
	int SellFreeEx(const char* name, char taxgrp, double price, double quantity = 1.0, double discount = 0.0, BYTE flag = 0, DWORD = 1);
	int Storno(const char* name, char taxgrp, double price, double quantity = 1.0);
	int SellDB(BOOL isVoid, WORD number, double quantity = 1.0, double discount = 0.0);
	int SellDBEx(BOOL isVoid, DWORD number, double quantity = 1.0, double discount = 0.0, BYTE flag = 0);
	int SellDBEx2(BOOL isVoid, DWORD number, double price, double quantity = 1.0, double discount = 0.0, BYTE flag = 0);
	int SellDepartment(const char* name, WORD depNum, double price, double quantity, double discount);
	int SellDepartmentEx(const char* name, WORD depNum, double price, double quantity, double discount, BYTE flag);
	int CalcIntermediateSum(double* sum, DWORD flags = 0, double discount = 0.0, char taxgrp = -1);
	int AddDiscount(DWORD flags, double discount);
	int Payment(double sum, BYTE type = 0, BOOL noRest = FALSE);
	int PrintText(const char *text, int align = ZFP_TEXTALIGNLEFT);
	int PrintTextKP(const char *text, int flags = 0, const char *text_param = NULL, double numeric_param = 0);
	int CloseFiscalBon();
	int PrintDuplicate();
	int OfficialSums(BYTE oper, const char* passwd, BYTE type, double sum, const char* note = NULL);
	int GetArticleInfo(WORD number, char* name, double* price, char* taxgrp, double* turnover, double* sells,
			WORD* counter, int* dd, int* mm, int* yy, int* hh, int* mmm, WORD* dep = NULL);
	int GetArticleInfoEx(DWORD number, char* name, double* price, char* taxgrp, double* turnover, double* sells,
			WORD* counter, int* dd, int* mm, int* yy, int* hh, int* mmm, WORD* dep, char* units = NULL);
	int GetDailySums(double* taxgrp1, double* taxgrp2, double* taxgrp3, double* taxgrp4 = NULL, double* taxgrp5 = NULL);
	int GetDailyInfo(int* clients, int* discounts, double* sumdiscount, int* adding, double* sumadding, int* voids, double* sumvoids);

	int GetDailyPayments(double* paytype0, double* paytype1, double* paytype2, double* paytype3, double* paytype4);
	int GetDailyIncomes(double* paytype0, double* paytype1, double* paytype2, double* paytype3, double* paytype4);
	
	int GetDailyOfficialIncomes(double* paytype0, double* paytype1, double* paytype2, double* paytype3, double* paytype4, DWORD* operations);
	int GetDailyOfficialExpenses(double* paytype0, double* paytype1, double* paytype2, double* paytype3, double* paytype4, DWORD* operations);
	
	int GetDailyReport(DWORD* counter, DWORD* lastreport, DWORD* ejNum, int* dd, int* mm, int* yy, int* hh, int* mmm);
	int GetCurrentBonInfo(DWORD* flags, int* purchases, double* taxgrp1, double* taxgrp2, double* taxgrp3, double* taxgrp4 = NULL, double* taxgrp5 = NULL);

	int GetOperatorInfo(BYTE oper, int* clients, int* discounts, double* sumdiscount, int* adding, double* sumadding, int* voids, double* sumvoids);

	int GetOperatorIncomes(BYTE oper, double* paytype0, double* paytype1, double* paytype2, double* paytype3, double* paytype4, DWORD* operations);
	int GetOperatorExpenses(BYTE oper, double* paytype0, double* paytype1, double* paytype2, double* paytype3, double* paytype4, DWORD* operations);
	
	int GetOperatorReceives(BYTE oper, double* paytype0, double* paytype1, double* paytype2, double* paytype3, double* paytype4);
	int GetOperatorCounter(BYTE oper, DWORD* count, int* dd, int* mm, int* yy, int* hh, int* mmm);
	int GetBonNumber(int* number);
	int GetLastFiscalReportData(int* dd, int* mm, int* yy, int* lastReport, int* lastZeroRam);
	int GetFreeFiscalSpace(int* records);
	int GetStartDateFM( char * date );
	int GetLogoInfo(char * logo_info);

//////////////////////////////////////////////////////////////////////
// Barcode commands
//////////////////////////////////////////////////////////////////////

	int EnableBarcode(BYTE state);
	int FormatBarcode(const char * fmt);
	int PrintBarcode(const char * barcode, char type);

//////////////////////////////////////////////////////////////////////
// GS commands
//////////////////////////////////////////////////////////////////////
	int GetVersionGS(char* version);
	int EnableCommGS(BYTE enable, WORD device_no);
	int SetSpeedGS(BYTE speed);
	int LoadScaleProtocolGS(const char * protocol);

//////////////////////////////////////////////////////////////////////
// Setup commands & tools
//////////////////////////////////////////////////////////////////////
	int SetPayType(BYTE type, const char* line);
	int SetParameters(WORD fpnum, BOOL logo, BOOL till, BOOL autocut, BOOL transparent);
	int SetEJMode(BOOL bShort);
	int SetDateTime(WORD dd, WORD mm, WORD yy, WORD hh, WORD mmm, WORD ss);
	int SetClicheLine(BYTE lineNum, const char* text);
	int SetOperatorUserPass(BYTE oper, const char* name, const char* password);
	int SetArticleInfo(WORD number, const char* name, double price, char taxgrp, WORD depNum = 0);
	int SetArticleInfoEx(DWORD number, const char* name, double price, char taxgrp, WORD depNum, const char* units = NULL);
	int SetLogoFile(const char* filename);
	int SetLogoFileEx(BYTE logo_id, const char* filename);
	int SetLocalDateTime();
	int SetExternalDisplayData(const char* password, const BYTE* data, int datalen);
	int SetExternalDisplayFile(const char* password, const char* filename);
	int SetDepartment(WORD number, const char* name, char taxgrp);
	int SetLogo(BYTE logo);
	int SetLineWidth(int num_chars = 0);
	int GetLineWidth();
	int SetPrintMode(DWORD mode);

	static DWORD FindFirstFPCOM();
	static DWORD FindFirstFPCOMEx();
	static DWORD FindBaudByCOM(WORD wCom);
	static WORD FindFirstFPCOMbyBaud(DWORD baud);

//////////////////////////////////////////////////////////////////////
// Reports
//////////////////////////////////////////////////////////////////////
	int ReportSpecialFiscal();
	int ReportFiscalByBlock(BOOL detailed, WORD startNumber, WORD endNumber);
	int ReportFiscalByDate(BOOL detailed, WORD sdd, WORD smm, WORD syy, WORD edd, WORD emm, WORD eyy);
	int ReportDaily(BOOL zero, BOOL extended);
	int ReportEJ(WORD num = 0);
	int ReportOperator(BOOL zero, BYTE oper);
	int ReportArticles(BOOL zero);
	int ReportDepartments(BOOL zero);

	int ReadFiscalMemory(const char* filename);
	int ReadFiscalMemory2(const char* filename);

//////////////////////////////////////////////////////////////////////
// Service
//////////////////////////////////////////////////////////////////////
	int SetSerialNumber(const char* password, const char* manifactureNum, const char* fiscalNum = NULL, const char* controlSum = NULL);
	int SetTaxNumber(const char* password, const char* taxNum, const char* fiscalNum = NULL);
	int MakeFiscal(const char* password);
	int SetTaxPercents(const char* password, double tgr1, double tgr2, double tgr3, double tgr4 = 0.0);
	int SetDecimalPoint(const char* password, int point);
	int UpdateClicheKE(BYTE mode, const char* passwd); // for kenya only

//////////////////////////////////////////////////////////////////////
// EURO compatible functions
//////////////////////////////////////////////////////////////////////
	int SetTaxPercentsEU(const char* password, const TZfpTaxGroups& taxGroups);
	int SetPayTypeEU(BYTE type, const char* line, double exchRate, int code = -1);
	int SetParametersEU(const TZfpParams& options);
	int GetTaxPercentsEU(TZfpTaxGroups& taxGroups);
	int GetParametersEU(TZfpParams& parameters);
	int GetPayTypesEU(TZfpPayTypes& payTypes);
	int PaymentEU(double sum, BYTE type, BOOL noChange, BYTE changeType);
	int PaymentEx(double sum, BYTE type, BOOL noChange, BYTE changeType, BOOL fPaidExactSum);
	int GetCurrentBonInfoEU(TZfpReceiptInfo& info);
	int GetDailySumsEU(TZfpTaxGroups& taxGroups);
	int GetOperatorChangeEU(BYTE oper, double* paytype0, double* paytype1, double* paytype2, double* paytype3, double* paytype4);
	int GetInvoiceNextNumberEU(char* nextNum, char* lastNum);
	int SetInvoiceNumbersRangeEU(const char* startNum, const char* lastNum);
	int GetDepartmentEU(WORD number, char* name, char* taxgrp, double* turnover, double* quantity);
	int GetDailyChangeEU(double* paytype0, double* paytype1, double* paytype2, double* paytype3, double* paytype4);

protected:
	static BYTE m_lastNBL;					// NBL last index
	static BYTE m_antiEcho;					// use to check for echo enabled modems :)

	WORD m_wCom;							// COM port number (1 = COM1)
	DWORD m_baudRate;
	WORD m_retries;
	WORD m_curRetry;
	DWORD m_retryWait;
	BYTE m_inputBuf[ZFP_MAXBUFLEN];			// buffer that goes to the FP
	BYTE m_responseBuf[ZFP_MAXBUFLEN];		// buffer that get the response
	DWORD m_inputLen;
	DWORD m_responseLen;
	int m_zfpType;							// Fiscal Printer type
	DWORD m_autoBusyTimeout;
	short m_pingType;                       // -1 = unknown mode, 0 = default 04/05, 1 = new ping 09
	BYTE  m_pingStatus;                     // status bits "01ssssss" for last ping (ZFP_PING2)

	int GetDailyPaymentSums(BYTE type, double* paytype0, double* paytype1, double* paytype2, double* paytype3, double* paytype4);
	int GetDailyOfficialSums(BYTE type, double* paytype0, double* paytype1, double* paytype2, double* paytype3, double* paytype4, DWORD* operations);
	int GetOperatorSums(WORD type, BYTE oper, double* paytype0, double* paytype1, double* paytype2, double* paytype3, double* paytype4, DWORD* operations);

	static void GetErrorStringBG(int error, char* buf);
	static void GetErrorStringEN(int error, char* buf);

//////////////////////////////////////////////////////////////////////
// Communications
//////////////////////////////////////////////////////////////////////
	void Clear();
	int SendCommand(CSerialA *serial, BYTE cmd, BOOL getReceipt = TRUE, BYTE* data = NULL, BYTE len = 0);
	int GetReceipt(CSerialA *serial, DWORD ptr = 0);
	int GetResponse(CSerialA *serial, BYTE* data = NULL, BYTE* len = NULL);
	void MakeCRC(BYTE* data, BYTE len, BYTE* crc1, BYTE* crc2);
	void GetBufferHex(const BYTE *pBuf, DWORD dwLen, char* buffer);
	
	int CheckForFPrinter(CSerialA *serial, int retries = 10);
	int CheckForBusy(CSerialA *serial, int retries = 10);
	int DoPing(CSerialA *serial, BYTE ping, int result, int retries);
	int Ping2(CSerialA *serial, int retries);
	
	int DoBusyWait(CSerialA *serial, DWORD timeout);
};

#endif
