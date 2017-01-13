//////////////////////////////////////////////////////////////////////
// Copyright (c) 2005-2008 Tremol Ltd.
// License: Mozilla Public License 1.1
// Contacts: software@tremol.bg
//////////////////////////////////////////////////////////////////////
// ZekaFP_cmds.cpp: implementation of the CZekaFP commands
//
//////////////////////////////////////////////////////////////////////

#include <stdio.h>
#ifdef WIN32
#include <windows.h>
#include <shlwapi.h>
#include "../win32/SerialA.h"
#endif

#ifdef POSIX
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/times.h>
#include "../posix/SerialA.h"
#endif

#include "../../include/ZekaFPdefs.h"
#include "ZekaFPint.h"
#include "../../include/ZekaFP.h"

static DWORD modePrint = 0x80000000;
extern unsigned ZFP_TIMEOUT, ZFP_PINGTIMEOUT;

//////////////////////////////////////////////////////////////////////
// Commands
//////////////////////////////////////////////////////////////////////
int CZekaFP::GetStatus(BYTE* status)
{
	CSerialA serial(m_wCom, m_baudRate);
	int res = SendCommand(&serial, 0x20, FALSE);
	if (ZFPE_SUCCESS == res) {
		BYTE data[ZFP_MAXBUFLEN], len;
		res = GetResponse(&serial, data, &len);
		if (ZFPE_SUCCESS == res) {
			memcpy(status, data, (size_t)len);
		}
	}
	return res;
}

int CZekaFP::GetVersion(char* version)
{
	CSerialA serial(m_wCom, m_baudRate);
	int res = SendCommand(&serial, 0x21, FALSE);
	*version = 0;
	if (ZFPE_SUCCESS == res)
	{
		BYTE data[ZFP_MAXBUFLEN], len;
		res = GetResponse(&serial, data, &len);
		if (ZFPE_SUCCESS == res)
		{
			memcpy(version, data, (size_t)len);
			version[len] = 0;
			mystrtrim(version);
		}
	}
	return res;
}

int CZekaFP::Diagnostic()
{
	CSerialA serial(m_wCom, m_baudRate);
	return SendCommand(&serial, 0x22);
}

int CZekaFP::DisplayClear()
{
	CSerialA serial(m_wCom, m_baudRate);
	return SendCommand(&serial, 0x24);
}

int CZekaFP::DisplayLine1(const char* line)
{
	CSerialA serial(m_wCom, m_baudRate);
	char data[ZFP_MAXBUFLEN], data1[ZFP_MAXBUFLEN];
	sprintf(data, "%-20s", nstrcpy(data1, line, 20));
	return SendCommand(&serial, 0x25, TRUE, (BYTE *)&data, 20);
}

int CZekaFP::DisplayLine2(const char* line)
{
	CSerialA serial(m_wCom, m_baudRate);
	char data[ZFP_MAXBUFLEN], data1[ZFP_MAXBUFLEN];
	sprintf(data, "%-20s", nstrcpy(data1, line, 20));
	return SendCommand(&serial, 0x26, TRUE, (BYTE *)&data, 20);
}

int CZekaFP::Display(const char* line)
{
	CSerialA serial(m_wCom, m_baudRate);
	char data[ZFP_MAXBUFLEN], data1[ZFP_MAXBUFLEN];
	sprintf(data, "%-40s", nstrcpy(data1, line, 40));
	return SendCommand(&serial, 0x27, TRUE, (BYTE *)&data, 40);
}

int CZekaFP::DisplayDateTime()
{
	CSerialA serial(m_wCom, m_baudRate);
	return SendCommand(&serial, 0x28);
}

int CZekaFP::PaperCut()
{
	CSerialA serial(m_wCom, m_baudRate);
	return SendCommand(&serial, 0x29);
}

int CZekaFP::OpenTill()
{
	CSerialA serial(m_wCom, m_baudRate);
	return SendCommand(&serial, 0x2A);
}

int CZekaFP::LineFeed()
{
	CSerialA serial(m_wCom, m_baudRate);
	return SendCommand(&serial, 0x2B);
}

int CZekaFP::GetFactFiscNums(char* factory, char* fiscal)
{
	CSerialA serial(m_wCom, m_baudRate);
	int res = SendCommand(&serial, 0x60, FALSE);
	if (ZFPE_SUCCESS == res)
	{
		BYTE data[ZFP_MAXBUFLEN], len;
		res = GetResponse(&serial, data, &len);
		if (ZFPE_SUCCESS == res)
		{
			data[(int)len] = 0;
			if (len && data[len - 1] == ';')
				data[len - 1] = 0; // remove the last ';'
			char* limit = strchr((const char*)data, ';');
			if (NULL == limit)
				return ZFPE_BADRESPONSEDATA;
			len = limit - (const char*)data;
			if (12 < len)
				return ZFPE_BADRESPONSEDATA;
			nstrcpy(factory, (const char*)&data[0], len);
			nstrcpy(fiscal, (const char*)&data[len+1], 12);
			//if (2 != sscanf((const char*)&data, "%8s;%s", factory, fiscal))
			//	return ZFPE_BADRESPONSEDATA;
			mystrtrim(factory);
			mystrtrim(fiscal);
		}
	}
	return res;
}

int CZekaFP::GetTaxNumber(char* taxnumber)
{
	CSerialA serial(m_wCom, m_baudRate);
	int res = SendCommand(&serial, 0x61, FALSE);
	if (ZFPE_SUCCESS == res) {
		BYTE data[ZFP_MAXBUFLEN], len;
		res = GetResponse(&serial, data, &len);
		if (ZFPE_SUCCESS == res) {
			data[(int)len] = 0;
			mystrtrim((char*)data);
			nstrcpy(taxnumber, (const char*)data, 15);
			mystrtrim(taxnumber, ";");
		}
	}
	return res;
}

int CZekaFP::GetTaxPercents(double* tgr1, double* tgr2, double* tgr3, double* tgr4/* = NULL*/)
{
	if ((ZFPT_RO == m_zfpType) && (NULL == tgr4))
		return ZFPE_BADINPUTDATA;

	CSerialA serial(m_wCom, m_baudRate);
	int res = SendCommand(&serial, 0x62, FALSE);
	if (ZFPE_SUCCESS == res) {
		BYTE data[ZFP_MAXBUFLEN], len;
		res = GetResponse(&serial, data, &len);
		if (ZFPE_SUCCESS == res) {
			data[(int)len] = 0;
			strreplace((char *)data, ' ', '0');
			if (ZFPT_RO == m_zfpType) {
				if (4 != sscanf((const char*)&data, "%le%%;%le%%;%le%%;%le", tgr1, tgr2, tgr3, tgr4))
					return ZFPE_BADRESPONSEDATA;
			}
			else {
				if (3 != sscanf((const char*)&data, "%le%%;%le%%;%le", tgr1, tgr2, tgr3))
					return ZFPE_BADRESPONSEDATA;
			}
		}
	}
	return res;
}

int CZekaFP::GetDecimalPoint(int* point)
{
	CSerialA serial(m_wCom, m_baudRate);
	int res = SendCommand(&serial, 0x63, FALSE);
	if (ZFPE_SUCCESS == res) {
		BYTE data[ZFP_MAXBUFLEN], len;
		res = GetResponse(&serial, data, &len);
		if (ZFPE_SUCCESS == res) {
			data[(int)len] = 0;
			if (1 != sscanf((const char*)&data, "%u", point))
				return ZFPE_BADRESPONSEDATA;
		}
	}
	return res;
}

int CZekaFP::GetPayTypes(char* type1, char* type2, char* type3, char* type4, char* type5)
{
	CSerialA serial(m_wCom, m_baudRate);
	int res = SendCommand(&serial, 0x64, FALSE);
	if (ZFPE_SUCCESS == res) {
		BYTE data[ZFP_MAXBUFLEN], len;
		res = GetResponse(&serial, data, &len);
		if (ZFPE_SUCCESS == res) {
			nstrcpy(type1, (const char*)&data[0], 10);
			nstrcpy(type2, (const char*)&data[11], 10);
			nstrcpy(type3, (const char*)&data[22], 10);
			nstrcpy(type4, (const char*)&data[33], 10);
			nstrcpy(type5, (const char*)&data[44], 10);
			mystrtrim(type1);
			mystrtrim(type2);
			mystrtrim(type3);
			mystrtrim(type4);
			mystrtrim(type5);
		}
	}
	return res;
}

int CZekaFP::GetParameters(int* fpNum, int* logo, int* till, int* autocut, int* transparent)
{
	CSerialA serial(m_wCom, m_baudRate);
	int res = SendCommand(&serial, 0x65, FALSE);
	if (ZFPE_SUCCESS == res) {
		BYTE data[ZFP_MAXBUFLEN], len;
		res = GetResponse(&serial, data, &len);
		if (ZFPE_SUCCESS == res) {
			data[(int)len] = 0;
			if (5 != sscanf((const char*)&data, "%04u;%1u;%1u;%1u;%1u", 
						fpNum, logo, till, autocut, transparent))
				return ZFPE_BADRESPONSEDATA;
		}
	}
	return res;
}

int CZekaFP::GetEJMode(int* isShort)
{
	CSerialA serial(m_wCom, m_baudRate);
	int res = SendCommand(&serial, 0x65, FALSE);
	if (ZFPE_SUCCESS == res) {
		BYTE data[ZFP_MAXBUFLEN], len;
		res = GetResponse(&serial, data, &len);
		if (ZFPE_SUCCESS == res) {
			int fpNum, logo, till, autocut, transparent;
			data[(int)len] = 0;
			if (6 != sscanf((const char*)&data, "%04u;%1u;%1u;%1u;%1u;%1u", 
						&fpNum, &logo, &till, &autocut, &transparent, isShort))
				return ZFPE_BADRESPONSEDATA;
		}
	}
	return res;
}

int CZekaFP::GetDateTime(int* dd, int* mm, int* yy, int* hh, int* mmm)
{
	CSerialA serial(m_wCom, m_baudRate);
	int res = SendCommand(&serial, 0x68, FALSE);
	if (ZFPE_SUCCESS == res) {
		BYTE data[ZFP_MAXBUFLEN], len;
		res = GetResponse(&serial, data, &len);
		if (ZFPE_SUCCESS == res) {
			data[(int)len] = 0;
			if (5 != sscanf((const char*)&data, "%u-%u-%u %u:%u", dd, mm, yy, hh, mmm))
				return ZFPE_BADRESPONSEDATA;
		}
	}
	return res;
}

int CZekaFP::GetClicheLine(BYTE lineNum, char* text)
{
	CSerialA serial(m_wCom, m_baudRate);
	BYTE data[ZFP_MAXBUFLEN], len;
	data[0] = lineNum + ( lineNum < 32 ? 0x30 : 0 );
	int res = SendCommand(&serial, 0x69, FALSE, data, 1);
	if (ZFPE_SUCCESS == res)
	{
		res = GetResponse(&serial, data, &len);
		if (ZFPE_SUCCESS == res)
		{
			data[(int)len] = 0;
			nstrcpy(text, (const char*)&data[2], len - 3);
		}
	}
	return res;
}

int CZekaFP::GetOperatorUserPass(BYTE oper, char* name, char* passwd)
{
	if ((20 < oper) || (1 > oper))
		return ZFPE_BADINPUTDATA;

	CSerialA serial(m_wCom, m_baudRate);
	BYTE data[ZFP_MAXBUFLEN], len;
	sprintf( (char *)data, "%u", (unsigned)oper );
	int add = strlen((char *)data);
	int res = SendCommand(&serial, 0x6A, FALSE, data, add);
	if (ZFPE_SUCCESS == res)
	{
		res = GetResponse(&serial, data, &len);
		if (ZFPE_SUCCESS == res)
		{
			data[(int)len] = 0;
			nstrcpy(name, (const char*)data + add + 1, 20);
			nstrcpy(passwd, (const char*)data + add + 22, 4);
			mystrtrim(name);
			mystrtrim(passwd);
		}
	}
	return res;
}

int CZekaFP::PrintLogo()
{
	CSerialA serial(m_wCom, m_baudRate);
	return SendCommand(&serial, 0x6C);
}

int CZekaFP::OpenBon(BYTE oper, const char* passwd)
{
	if ((20 < oper) || (1 > oper))
		return ZFPE_BADINPUTDATA;

	int com = (int)m_wCom;
	if (PrintModeFlag(PMFLAG_NONFISCAL_RECEIPT) && PrintModeFlag(PMFLAG_KEEP_OPEN_COM))
		com = -com;
	CSerialA serial(com, m_baudRate);
	char newpass[ZFP_MAXBUFLEN];
	BYTE data[ZFP_MAXBUFLEN];
	nstrcpy(newpass, passwd, 4);
	sprintf((char *)data, "%u;%-4s;0", (unsigned)oper, newpass);
	if (PrintModeFlag(PMFLAG_NONFISCAL_RECEIPT) && PrintModeFlag(PMFLAG_DEFER_PRINT))
		strcat((char *)data, ";1");
	int res = SendCommand(&serial, 0x2E, FALSE, data, strlen((char *)data));
	if (ZFPE_SUCCESS == res)
	{
		BYTE len;
		res = GetResponse(&serial, data, &len);
	}
	if (res != ZFPE_SUCCESS && com < 0)
	{
		CloseSerialPort();
	}
	return res;
}

int CZekaFP::OpenBonWithEJ(BYTE oper, const char* passwd, BOOL hasEJ)
{
	if ((20 < oper) || (1 > oper))
		return ZFPE_BADINPUTDATA;

	int com = (int)m_wCom;
	if (PrintModeFlag(PMFLAG_NONFISCAL_RECEIPT) && PrintModeFlag(PMFLAG_KEEP_OPEN_COM))
		com = -com;
	CSerialA serial(com, m_baudRate);
	char newpass[ZFP_MAXBUFLEN];
	BYTE data[ZFP_MAXBUFLEN];
	nstrcpy(newpass, passwd, 4);
	if (hasEJ)
		sprintf((char *)data, "%u;%-4s;J", (unsigned)oper, newpass);
	else
		sprintf((char *)data, "%u;%-4s;0", (unsigned)oper, newpass);
	if (PrintModeFlag(PMFLAG_NONFISCAL_RECEIPT) && PrintModeFlag(PMFLAG_DEFER_PRINT))
		strcat((char *)data, ";1");
	int res = SendCommand(&serial, 0x2E, FALSE, data, strlen((char *)data));
	if (ZFPE_SUCCESS == res)
	{
		BYTE len;
		res = GetResponse(&serial, data, &len);
	}
	if (res != ZFPE_SUCCESS && com < 0)
	{
		CloseSerialPort();
	}
	return res;
}

int CZekaFP::CloseBon()
{
	CSerialA serial(m_wCom, m_baudRate);
#ifndef POSIX
	if (serial.fKeepOpen == 1)
		serial.fKeepOpen = 0;
#endif
	if (PrintModeFlag(PMFLAG_ONE_TIME))
		SetPrintMode(0);
	return SendCommand(&serial, 0x2F);
}

int CZekaFP::OpenFiscalBon(BYTE oper, const char* passwd, BYTE detailed, BYTE dds)
{
	if ((20 < oper) || (1 > oper))
		return ZFPE_BADINPUTDATA;

	int com = (int)m_wCom;
	if ( PrintModeFlag(PMFLAG_FISCAL_RECEIPT) && PrintModeFlag(PMFLAG_KEEP_OPEN_COM) && com > 0 )
		com = -com;
	CSerialA serial(com, m_baudRate);
	char newpass[ZFP_MAXBUFLEN];
	BYTE data[ZFP_MAXBUFLEN];
	nstrcpy(newpass, passwd, 4);
	char invoice = '0';
	if ( PrintModeFlag(PMFLAG_FISCAL_RECEIPT) && PrintModeFlag(PMFLAG_DEFER_PRINT) )
		invoice = '2';
	sprintf((char *)data, "%u;%-4s;%1c;%1c;%1c", (unsigned)oper, newpass, detailed ? '1' : '0', dds ? '1' : '0', invoice);
	int res = SendCommand(&serial, 0x30, TRUE, data, strlen((char *)data));
	if (res != ZFPE_SUCCESS && com < 0)
	{
		CloseSerialPort();
	}
	return res;
}

// Read FP line width from the registry
int CZekaFP::GetLineWidth()
{
	int res = 0;
#ifndef POSIX
	DWORD rs, type = REG_DWORD;

	if (SHGetValue(HKEY_LOCAL_MACHINE, "Software\\Tremol\\ZFPLib", "FPLineWidth", &type, &res, &rs) != ERROR_SUCCESS)
#endif
	{
		res = 38;
	}

	return res;
}

int CZekaFP::OpenInvoice(BYTE oper, const char* passwd, const char* client, const char* receiver, 
		const char* vatNum, const char* identNum, const char* address)
{
	if ((20 < oper) || (1 > oper))
		return ZFPE_BADINPUTDATA;

	int com = (int)m_wCom;
	if (PrintModeFlag(PMFLAG_FISCAL_RECEIPT) && PrintModeFlag(PMFLAG_KEEP_OPEN_COM))
		com = -com;
	CSerialA serial(com, m_baudRate);
	char newpass[5], newclient[30], newreceiver[20];
	char newvatnum[15], newidentnum[15], newaddress[32];

	char invoice = '1';
	if (PrintModeFlag(PMFLAG_FISCAL_RECEIPT) && PrintModeFlag(PMFLAG_DEFER_PRINT))
		invoice = '3';
	BYTE data[ZFP_MAXBUFLEN];
	sprintf((char *)data, "%u;%-4s;0;0;%1c;%-26s;%-16s;%-13s;%-13s;%-30s", (unsigned)oper, 
		nstrcpy(newpass, passwd, 4), invoice,
		nstrcpy(newclient, client, 26), 
		nstrcpy(newreceiver, receiver, 16), nstrcpy(newvatnum, vatNum, 13), 
		nstrcpy(newidentnum, identNum, 13), nstrcpy(newaddress, address, 30));
	int res = SendCommand(&serial, 0x30, TRUE, data, strlen((const char *)data));
	if (res != ZFPE_SUCCESS && com < 0)
	{
		CloseSerialPort();
	}
	return res;
}

int CZekaFP::SellFreeEx(const char* name, char taxgrp, double price, double quantity, double discount, BYTE flag, DWORD divider)
{
	if ( (-99999999.0 > price) || (99999999.0 < price) || (quantity < 0.0 && (flag & 4) == 0) || 
		(999999.999 < quantity) || ( (flag & 1) == 0 && (-999.0 > discount || 999.0 < discount)) )
		return ZFPE_BADINPUTDATA;

	if (flag > 7) // flag: bit 0 - percent/value discount; bit 1 - storno; bit 2 - divider available (> 1)
		return ZFPE_BADINPUTDATA;

	if ( (flag & 4) != 0 && divider == 0)
		return ZFPE_BADINPUTDATA;

	CSerialA serial(m_wCom, m_baudRate);

	if (10 > taxgrp) 
		taxgrp |= 0x30;

	char num1[MAX_NUM_LEN], num2[MAX_NUM_LEN], newname[ZFP_MAXBUFLEN], fmt[40];
	BYTE data[ZFP_MAXBUFLEN];
	*data = 0;
	int lw = 36;
	nstrcpy(newname, name, lw);
	getfloatformat(num1, price);
	getfloatformat(num2, quantity, 3);
	BYTE cmd_code = 0x31;

	if ( (flag & 2) != 0 ) // storno
	{
		cmd_code = 0x3C;
	}
	if ( (flag & 4) != 0 ) // vulgar fraction
	{
		if ( quantity != (double)(int)quantity )
			return ZFPE_BADINPUTDATA;
		cmd_code = 0x3D;
		sprintf(num2, "%d/%u", (int)quantity, divider);
	}
	if (discount == 0.0)
	{
		sprintf(fmt, "%%-%us;%%c;%%s*%%s", lw);
		sprintf((char *)&data, fmt, newname, taxgrp, num1, num2);
	}
	else
	{
		if ((flag & 1) == 0) // percent
		{
			sprintf(fmt, "%%-%us;%%c;%%s*%%s,%%06.2f%%%%", lw);
			sprintf((char *)&data, fmt, newname, taxgrp, num1, num2, discount);
		}

		if ((flag & 1) == 1) // value
		{
			sprintf(fmt, "%%-%us;%%c;%%s*%%s:%%010.2f", lw);
			sprintf((char *)&data, fmt, newname, taxgrp, num1, num2, discount);
		}
	}

	return SendCommand(&serial, cmd_code, TRUE, data, strlen((char *)&data));
}

int CZekaFP::Storno(const char* name, char taxgrp, double price, double quantity)
{
	return SellFreeEx(name, taxgrp, -price, quantity, 0, 2);
}

int CZekaFP::SellFree(const char* name, char taxgrp, double price, double quantity, double discount)
{
	return SellFreeEx(name, taxgrp, price, quantity, discount, 0);
}

int CZekaFP::SellDBEx2(BOOL isVoid, DWORD number, double price, double quantity, double discount, BYTE flag)
{
	if ( (0 > quantity) || (9999999999.0 < quantity) || (flag == 0 && (-999.0 > discount || 999.0 < discount)) )
		return ZFPE_BADINPUTDATA;

	if (flag > 1 || number > 99999)
		return ZFPE_BADINPUTDATA;

	CSerialA serial(m_wCom, m_baudRate);
	char num1[MAX_NUM_LEN], num2[MAX_NUM_LEN];
	BYTE data[ZFP_MAXBUFLEN];
	getfloatformat(num1, quantity, 3);
	getfloatformat(num2, price, 2);

	if (discount == 0.0)
	{
		sprintf((char *)&data, "%c%05u$%s*%s", isVoid ? '-' : '+', number, num2, num1);
	}
	else
	{
		if (flag == 0)
			sprintf((char *)&data, "%c%05u$%s*%s,%06.2f%%", isVoid ? '-' : '+', number, num2, num1, discount);

		if (flag == 1)
			sprintf((char *)&data, "%c%05u$%s*%s:%010.2f", isVoid ? '-' : '+', number, num2, num1, discount);
	}
	return SendCommand(&serial, 0x32, TRUE, data, strlen((char *)&data));
}

int CZekaFP::SellDBEx(BOOL isVoid, DWORD number, double quantity, double discount, BYTE flag)
{
	if ( (0 > quantity) || (9999999999.0 < quantity) || (flag == 0 && (-999.0 > discount || 999.0 < discount)) )
		return ZFPE_BADINPUTDATA;

	if (flag > 1 || number > 99999)
		return ZFPE_BADINPUTDATA;

	CSerialA serial(m_wCom, m_baudRate);
	char num1[MAX_NUM_LEN];
	BYTE data[ZFP_MAXBUFLEN];
	getfloatformat(num1, quantity, 3);

	if (discount == 0.0)
	{
		sprintf((char *)&data, "%c%05u*%s", isVoid ? '-' : '+', number, num1);
	}
	else
	{
		if (flag == 0)
			sprintf((char *)&data, "%c%05u*%s,%06.2f%%", isVoid ? '-' : '+', number, num1, discount);

		if (flag == 1)
			sprintf((char *)&data, "%c%05u*%s:%010.2f", isVoid ? '-' : '+', number, num1, discount);
	}
	return SendCommand(&serial, 0x32, TRUE, data, strlen((char *)&data));
}

int CZekaFP::SellDB(BOOL isVoid, WORD number, double quantity, double discount)
{
	if (number > 1000)
		return ZFPE_BADINPUTDATA;

	return SellDBEx(isVoid, number, quantity, discount, 0);
}

int CZekaFP::CalcIntermediateSum(double* sum, DWORD flags, double discount, char taxgrp/* = -1*/)
{
	CSerialA serial(m_wCom, m_baudRate);
	BYTE data[ZFP_MAXBUFLEN];
	if (discount == 0.0)
	{
		sprintf((char *)&data, "%c;%c", flags & ZFP_ISPRINT ? '1' : '0', flags & ZFP_ISSHOW ? '1' : '0');
	}
	else 
	{
		if (flags & ZFP_ISPERCENT) 
		{
			if ((-99.99 > discount) || (999.99 < discount))
				return ZFPE_BADINPUTDATA;

			sprintf((char *)&data, "%c;%c,%6.2f%%", flags & ZFP_ISPRINT ? '1' : '0', flags & ZFP_ISSHOW ? '1' : '0', discount);
		}
		else 
		{
			if ((-999999999.0 > discount) || (9999999999.0 < discount))
				return ZFPE_BADINPUTDATA;
			char num1[MAX_NUM_LEN];
			sprintf((char *)&data, "%c;%c:%s", flags & ZFP_ISPRINT ? '1' : '0', flags & ZFP_ISSHOW ? '1' : '0', getfloatformat(num1, discount));
		}

		if ((ZFPT_RO == m_zfpType) && (0 <= taxgrp)) 
		{
			int len = strlen((char *)&data);
			data[len++] = ';';
			data[len++] = taxgrp ? taxgrp : taxgrp | 0x30;
			data[len] = 0;
		}
	}

	int res = SendCommand(&serial, 0x33, FALSE, data, strlen((char *)&data));
	if (ZFPE_SUCCESS == res) 
	{
		BYTE len;
		res = GetResponse(&serial, data, &len);
		if (ZFPE_SUCCESS == res) 
		{
			data[(int)len] = 0;
			if (1 != sscanf((const char*)&data, "%le", sum))
				return ZFPE_BADRESPONSEDATA;
		}
	}
	return res;
}

int CZekaFP::AddDiscount(DWORD flags, double discount)
{
	CSerialA serial(m_wCom, m_baudRate);
	char data[ZFP_MAXBUFLEN], cmd = '1';

	if (flags & ZFP_ADAUTO) cmd = '2';
	if (flags & ZFP_ADTRANS) cmd = '0';
	if (flags & ZFP_ADPERCENT) 
	{
		if ((-99.99 > discount) || (999.99 < discount))
			return ZFPE_BADINPUTDATA;

		sprintf(data, "%c;%c,%6.2f%%", cmd, flags & ZFP_ADSHOW ? '1' : '0', discount);
	}
	else 
	{
		if ((-999999999.0 > discount) || (9999999999.0 < discount))
			return ZFPE_BADINPUTDATA;

		char num1[MAX_NUM_LEN];
		sprintf(data, "%c;%c:%s", cmd, flags & ZFP_ADSHOW ? '1' : '0', getfloatformat(num1, discount));
	}

	return SendCommand(&serial, 0x3E, TRUE, (BYTE *)data, strlen(data));
}

int CZekaFP::Payment(double sum, BYTE type, BOOL noRest)
{
	CSerialA serial(m_wCom, m_baudRate);
	if ((9 < type) || (0.0 > sum && sum != -1) || (9999999999.0 < sum))
		return ZFPE_BADINPUTDATA;
	BYTE data[ZFP_MAXBUFLEN];
	char num1[MAX_NUM_LEN];

	sprintf((char *)&data, "%1u;%c;%s", type, noRest ? '1' : '0', sum == -1 ? "-" : getfloatformat(num1, sum));
	return SendCommand(&serial, 0x35, TRUE, data, strlen((char *)&data));
}

int CZekaFP::PrintText(const char *text, int align)
{
	CSerialA serial(m_wCom, m_baudRate);
	char data[ZFP_MAXBUFLEN], data1[ZFP_MAXBUFLEN], fmt[16];
	int lw = GetLineWidth();
	if (lw <= 38) lw = 34; else lw -= 4;
	nstrcpy(data1, text, lw);
	int len = strlen(data1);
	int newalign = align;
	if (len >= lw)
		newalign = ZFP_TEXTALIGNLEFT;

	switch (newalign)
	{
	case ZFP_TEXTALIGNRIGHT:
		sprintf(fmt, "%%%us", lw);
		sprintf(data, fmt, data1);
		break;
	
	case ZFP_TEXTALIGNCENTER:
		{
			memset(data, ' ', lw);
			data[lw] = data[lw + 1] = 0;
			int pos = (lw - len) / 2;
			memcpy(data + pos, data1, len);
		}
		break;
	
	default:
		sprintf(fmt, "%%-%us", lw);
		sprintf(data, fmt, data1);
	}

	return SendCommand(&serial, 0x37, TRUE, (BYTE *)&data, strlen(data));
}

// Print text on POS printer
int CZekaFP::PrintTextKP( const char *text, int flags, const char *text_param, double numeric_param )
{
	int res = ZFPE_SUCCESS;
	char data[512];
	CSerialA serial(m_wCom, m_baudRate);

	data[0] = 0;
	if ( strlen( text ) < sizeof data )
	{
		if ( ( flags & 3 ) != 0 )
		{
			if ( ( flags & 2 ) != 0 )
				sprintf( data, text, text_param, (char)numeric_param );
			else
				sprintf( data, text, text_param, numeric_param );
		}
		else
		{
			sprintf( data, "%s\n", text );
		}
	}
	else
	{
		sprintf( data, "ERR: Text too long.\n" );
		res = ZFPE_BADINPUTDATA;
	}
	if ( data[0] )
	{
		serial.WriteToComPort( data, strlen( data ) );
	}
	return res;
}

int CZekaFP::CloseFiscalBon()
{
	CSerialA serial(m_wCom, m_baudRate);

#ifndef POSIX
	if (serial.fKeepOpen == 1)
		serial.fKeepOpen = 0;
#endif
	if (PrintModeFlag(PMFLAG_ONE_TIME))
		SetPrintMode(0);
	return SendCommand(&serial, 0x38);
}

int CZekaFP::PrintDuplicate()
{
	CSerialA serial(m_wCom, m_baudRate);
	
	int res = SendCommand(&serial, 0x3A);
//	if ((ZFPE_SUCCESS == res) && (ZFP_NOBUSYWAIT != m_autoBusyTimeout))
//		return DoBusyWait(&serial, m_autoBusyTimeout);
	return res;
}

int CZekaFP::OfficialSums(BYTE oper, const char* passwd, BYTE type, double sum, const char* note)
{
	if ((20 < oper) || (1 > oper) || (9 < type) || (-999999999.0 > sum) || (9999999999.0 < sum))
		return ZFPE_BADINPUTDATA;
	CSerialA serial(m_wCom, m_baudRate);
	BYTE data[ZFP_MAXBUFLEN];
	char num1[MAX_NUM_LEN];
	char newpass[ZFP_MAXBUFLEN];
	nstrcpy(newpass, passwd, 4);

	sprintf((char *)data, "%u;%-4s;%1u;%s", oper, newpass, type, getfloatformat(num1, sum));
	if (note && note[0])
	{
		char fmt[16];

		sprintf(fmt, ";@%%-%us", GetLineWidth() - 4);
		sprintf((char *)data + strlen((char *)data), fmt, note);
	}
	return SendCommand(&serial, 0x3B, TRUE, data, strlen((char *)&data));
}

int CZekaFP::GetArticleInfo(WORD number, char* name, double* price, char* taxgrp, double* turnover, 
		double* sells, WORD* counter, int* dd, int* mm, int* yy, int* hh, int* mmm, WORD* dep)
{
	if (1000 < number)
		return ZFPE_BADINPUTDATA;

	return GetArticleInfoEx(number, name, price, taxgrp, turnover, sells, counter, dd, mm, yy, hh, mmm, dep);
}

int CZekaFP::GetArticleInfoEx(DWORD number, char* name, double* price, char* taxgrp, double* turnover, 
		double* sells, WORD* counter, int* dd, int* mm, int* yy, int* hh, int* mmm, WORD* dep, char* units)
{
	if (number > 99999)
		return ZFPE_BADINPUTDATA;

	CSerialA serial(m_wCom, m_baudRate);
	BYTE data[ZFP_MAXBUFLEN], name0[ZFP_MAXBUFLEN];
	unsigned _counter = 0;
	sprintf((char *)&data, "%05u", number);
	int res = SendCommand(&serial, 0x6B, FALSE, data, strlen((char *)&data));
	if ( units ) units[0] = units[2] = 0;
	memset( name0, 0, sizeof name0 );
	if (ZFPE_SUCCESS == res)
	{
		BYTE len;

		res = GetResponse(&serial, data, &len);
		if (ZFPE_SUCCESS == res)
		{
			data[(int)len] = 0;
			nstrcpy(name, (const char*)&data[6], 20);
			if (dep) 
			{ // departments are supported only for the new firmware versions
				char cDep;

				if ( ( !units || 14 != sscanf((const char*)&data[27], "%le;%c;%le;%le;%u;%u-%u-%u %u:%u;%c;%c%c;%12s", 
					price, taxgrp, turnover, sells, &_counter, dd, mm, yy, hh, mmm, &cDep, units, units + 1, name0 ) )
				  && 11 != sscanf((const char*)&data[27], "%le;%c;%le;%le;%u;%u-%u-%u %u:%u;%c", 
					price, taxgrp, turnover, sells, &_counter, dd, mm, yy, hh, mmm, &cDep))
				{
					// read the data without the department
					if (10 != sscanf((const char*)&data[27], "%le;%c;%le;%le;%u;%u-%u-%u %u:%u", 
							price, taxgrp, turnover, sells, &_counter, dd, mm, yy, hh, mmm)) 
						return ZFPE_BADRESPONSEDATA;
					else
						*dep = 0;
				}
				else 
					*dep = (WORD)cDep & 0x7F; // remove the last 0x80 OR
			}
			else
			{
				if (10 != sscanf((const char*)&data[27], "%le;%c;%le;%le;%u;%u-%u-%u %u:%u", 
						price, taxgrp, turnover, sells, &_counter, dd, mm, yy, hh, mmm))
					return ZFPE_BADRESPONSEDATA;
			}
			strcat( name, (char *)name0 );
		}
	}
	mystrtrim(name);
	*counter = (WORD)_counter;
	return res;
}

int CZekaFP::GetDailySums(double* taxgrp1, double* taxgrp2, double* taxgrp3, double* taxgrp4/* = NULL*/, double* taxgrp5/* = NULL*/)
{
	if ((ZFPT_RO == m_zfpType) && ((NULL == taxgrp4) || (NULL == taxgrp5)))
		return ZFPE_BADINPUTDATA;

	CSerialA serial(m_wCom, m_baudRate);
	int res = SendCommand(&serial, 0x6D, FALSE);
	if (ZFPE_SUCCESS == res)
	{
		BYTE data[ZFP_MAXBUFLEN], len;
		res = GetResponse(&serial, data, &len);
		if (ZFPE_SUCCESS == res)
		{
			data[(int)len] = 0;
			if (ZFPT_RO == m_zfpType)
			{
				if (5 != sscanf((const char*)&data, "%le;%le;%le;%le;%le", taxgrp1, taxgrp2, taxgrp3, taxgrp4, taxgrp5))
					return ZFPE_BADRESPONSEDATA;
			}
			else
			{
				if (3 != sscanf((const char*)&data, "%le;%le;%le", taxgrp1, taxgrp2, taxgrp3))
					return ZFPE_BADRESPONSEDATA;
			}
		}
	}
	return res;
}

int CZekaFP::GetDailyInfo(int* clients, int* discounts, double* sumdiscount, int* adding, double* sumadding, int* voids, double* sumvoids)
{
	CSerialA serial(m_wCom, m_baudRate);
	BYTE data[ZFP_MAXBUFLEN], len;
	data[0] = '1';
	int res = SendCommand(&serial, 0x6E, FALSE, data, 1);
	if (ZFPE_SUCCESS == res) {
		res = GetResponse(&serial, data, &len);
		if (ZFPE_SUCCESS == res) {
			data[(int)len] = 0;
			if (7 != sscanf((const char*)&data[2], "%u;%u;%le;%u;%le;%u;%le", clients, discounts, sumdiscount, adding, sumadding, voids, sumvoids))
				return ZFPE_BADRESPONSEDATA;
		}
	}
	return res;
}

int CZekaFP::GetDailyPaymentSums(BYTE type, double* paytype0, double* paytype1, double* paytype2, double* paytype3, double* paytype4)
{
	CSerialA serial(m_wCom, m_baudRate);
	BYTE data[ZFP_MAXBUFLEN], len;
	data[0] = type;
	int res = SendCommand(&serial, 0x6E, FALSE, data, 1);
	if (ZFPE_SUCCESS == res)
	{
		res = GetResponse(&serial, data, &len);
		if (ZFPE_SUCCESS == res)
		{
			data[(int)len] = 0;
			*paytype0 = *paytype1 = *paytype2 = *paytype3 = *paytype4 = 0;
			if ( sscanf((const char*)&data[2], "%le;%le;%le;%le;%le", paytype0, paytype1, paytype2, paytype3, paytype4) != 5
					&& sscanf((const char*)&data[2], "%le;", paytype0) != 1 )
				return ZFPE_BADRESPONSEDATA;
		}
	}
	return res;
}

int CZekaFP::GetDailyPayments(double* paytype0, double* paytype1, double* paytype2, double* paytype3, double* paytype4)
{
	return GetDailyPaymentSums('0', paytype0, paytype1, paytype2, paytype3, paytype4);
}

int CZekaFP::GetDailyIncomes(double* paytype0, double* paytype1, double* paytype2, double* paytype3, double* paytype4)
{
	return GetDailyPaymentSums('4', paytype0, paytype1, paytype2, paytype3, paytype4);
}

int CZekaFP::GetDailyOfficialSums(BYTE type, double* paytype0, double* paytype1, double* paytype2, double* paytype3, double* paytype4, DWORD* operations)
{
	CSerialA serial(m_wCom, m_baudRate);
	BYTE data[ZFP_MAXBUFLEN], len;
	data[0] = type;
	int res = SendCommand(&serial, 0x6E, FALSE, data, 1);
	if (ZFPE_SUCCESS == res) {
		res = GetResponse(&serial, data, &len);
		if (ZFPE_SUCCESS == res) {
			data[(int)len] = 0;
			if (6 != sscanf((const char*)&data[2], "%le;%le;%le;%le;%le;%u", paytype0, paytype1, paytype2, paytype3, paytype4, operations))
				return ZFPE_BADRESPONSEDATA;
		}
	}
	return res;
}

int CZekaFP::GetDailyOfficialIncomes(double* paytype0, double* paytype1, double* paytype2, double* paytype3, double* paytype4, DWORD* operations)
{
	return GetDailyOfficialSums('2', paytype0, paytype1, paytype2, paytype3, paytype4, operations);
}

int CZekaFP::GetDailyOfficialExpenses(double* paytype0, double* paytype1, double* paytype2, double* paytype3, double* paytype4, DWORD* operations)
{
	return GetDailyOfficialSums('3', paytype0, paytype1, paytype2, paytype3, paytype4, operations);
}

int CZekaFP::GetDailyReport(DWORD* counter, DWORD* lastreport, DWORD* ejNum, int* dd, int* mm, int* yy, int* hh, int* mmm)
{
	CSerialA serial(m_wCom, m_baudRate);
	BYTE data[ZFP_MAXBUFLEN], len;
	data[0] = '5';
	int res = SendCommand(&serial, 0x6E, FALSE, data, 1);
	if (ZFPE_SUCCESS == res) {
		res = GetResponse(&serial, data, &len);
		if (ZFPE_SUCCESS == res) {
			data[(int)len] = 0;
			if (8 != sscanf((const char*)&data[2], "%u;%u;%u;%u-%u-%u %u:%u", counter, lastreport, ejNum, dd, mm, yy, hh, mmm))
  				return ZFPE_BADRESPONSEDATA;
		}
	}
	return res;
}

int CZekaFP::GetOperatorInfo(BYTE oper, int* clients, int* discounts, double* sumdiscount, int* adding, double* sumadding, int* voids, double* sumvoids)
{
	CSerialA serial(m_wCom, m_baudRate);
	if ((1 > oper) || (20 < oper))
		return ZFPE_BADINPUTDATA;
	BYTE data[ZFP_MAXBUFLEN], len;
	sprintf((char *)data, "1;%u", (unsigned)oper);
	int add = strlen((char *)data);
	int res = SendCommand(&serial, 0x6F, FALSE, data, add);
	if (ZFPE_SUCCESS == res)
	{
		res = GetResponse(&serial, data, &len);
		if (ZFPE_SUCCESS == res)
		{
			data[(int)len] = 0;
			if (7 != sscanf((const char*)data + add + 1, "%u;%u;%le;%u;%le;%u;%le", clients, discounts, sumdiscount, adding, sumadding, voids, sumvoids))
				return ZFPE_BADRESPONSEDATA;
		}
	}
	return res;
}

int CZekaFP::GetOperatorSums(WORD type, BYTE oper, double* paytype0, double* paytype1, double* paytype2, double* paytype3, double* paytype4, DWORD* operations)
{
	CSerialA serial(m_wCom, m_baudRate);
	if ((9 < type) || (1 > oper) || (20 < oper))
		return ZFPE_BADINPUTDATA;
	BYTE data[ZFP_MAXBUFLEN], len;
	sprintf((char *)data, "%c;%u", (type == 3) ? '3' : '2', (unsigned)oper);
	int add = strlen((char *)data);
	int res = SendCommand(&serial, 0x6F, FALSE, data, add);
	if (ZFPE_SUCCESS == res)
	{
		res = GetResponse(&serial, data, &len);
		if (ZFPE_SUCCESS == res)
		{
			data[(int)len] = 0;
			if (6 != sscanf((const char*)data + add + 1, "%le;%le;%le;%le;%le;%u", paytype0, paytype1, paytype2, paytype3, paytype4, operations))
				return ZFPE_BADRESPONSEDATA;
		}
	}
	return res;
}

int CZekaFP::GetOperatorIncomes(BYTE oper, double* paytype0, double* paytype1, double* paytype2, double* paytype3, double* paytype4, DWORD* operations)
{
	return GetOperatorSums(2, oper, paytype0, paytype1, paytype2, paytype3, paytype4, operations);
}

int CZekaFP::GetOperatorExpenses(BYTE oper, double* paytype0, double* paytype1, double* paytype2, double* paytype3, double* paytype4, DWORD* operations)
{
	return GetOperatorSums(3, oper, paytype0, paytype1, paytype2, paytype3, paytype4, operations);
}

int CZekaFP::GetOperatorReceives(BYTE oper, double* paytype0, double* paytype1, double* paytype2, double* paytype3, double* paytype4)
{
	CSerialA serial(m_wCom, m_baudRate);
	if ((1 > oper) || (20 < oper))
		return ZFPE_BADINPUTDATA;
	BYTE data[ZFP_MAXBUFLEN], len;
	sprintf((char *)data, "4;%u", (unsigned)oper);
	int add = strlen((char *)data);
	int res = SendCommand(&serial, 0x6F, FALSE, data, add);
	if (ZFPE_SUCCESS == res)
	{
		res = GetResponse(&serial, data, &len);
		if (ZFPE_SUCCESS == res)
		{
			data[(int)len] = 0;
			if (5 != sscanf((const char*)data + add + 1, "%le;%le;%le;%le;%le", paytype0, paytype1, paytype2, paytype3, paytype4))
				return ZFPE_BADRESPONSEDATA;
		}
	}
	return res;
}

int CZekaFP::GetOperatorCounter(BYTE oper, DWORD* count, int* dd, int* mm, int* yy, int* hh, int* mmm)
{
	CSerialA serial(m_wCom, m_baudRate);
	if ((1 > oper) || (20 < oper))
		return ZFPE_BADINPUTDATA;
	BYTE data[ZFP_MAXBUFLEN], len;
	sprintf((char *)data, "5;%u", (unsigned)oper);
	int add = strlen((char *)data);
	int res = SendCommand(&serial, 0x6F, FALSE, data, add);
	if (ZFPE_SUCCESS == res) {
		res = GetResponse(&serial, data, &len);
		if (ZFPE_SUCCESS == res) {
			data[(int)len] = 0;
			if (6 != sscanf((const char*)data + add + 1, "%u;%u-%u-%u %u:%u", count, dd, mm, yy, hh, mmm))
  				return ZFPE_BADRESPONSEDATA;
		}
	}
	return res;
}

int CZekaFP::GetBonNumber(int* number)
{
	CSerialA serial(m_wCom, m_baudRate);
	int res = SendCommand(&serial, 0x71, FALSE);
	if (ZFPE_SUCCESS == res) {
		BYTE data[ZFP_MAXBUFLEN], len;
		res = GetResponse(&serial, data, &len);
		if (ZFPE_SUCCESS == res) {
			data[(int)len] = 0;
			if (1 != sscanf((const char*)&data, "%u", number))
				return ZFPE_BADRESPONSEDATA;
		}
	}
	return res;
}

int CZekaFP::GetCurrentBonInfo(DWORD* flags, int* purchases, double* taxgrp1, double* taxgrp2, double* taxgrp3, double* taxgrp4/* = NULL*/, double* taxgrp5/* = NULL*/)
{
	if ((ZFPT_RO == m_zfpType) && ((NULL == taxgrp4) || (NULL == taxgrp5)))
		return ZFPE_BADINPUTDATA;

	CSerialA serial(m_wCom, m_baudRate);
	int res = SendCommand(&serial, 0x72, FALSE);
	if (ZFPE_SUCCESS == res) {
		BYTE data[ZFP_MAXBUFLEN], len;
		res = GetResponse(&serial, data, &len);
		if (ZFPE_SUCCESS == res) {
			if ('0' == data[0]) {
				*flags = 0;
			}
			else {
				*flags = ZFPB_OPENBON;
				char noVoid, dds, podr, payStart, payEnd, powerDown, invoice;
				data[(int)len] = 0;
				if (ZFPT_RO == m_zfpType) {
					if (12 != sscanf((const char*)&data[2], "%u;%le;%le;%le;%le;%le;%1c;%1c;%1c;%1c;%1c;%1c", 
							purchases, taxgrp1, taxgrp2, taxgrp3, taxgrp4, taxgrp5, &noVoid, &dds, &podr, &payStart, &payEnd, &powerDown))
						return ZFPE_BADRESPONSEDATA;
				}
				else {
					if (11 != sscanf((const char*)&data[2], "%u;%le;%le;%le;%1c;%1c;%1c;%1c;%1c;%1c;%1c", 
							purchases, taxgrp1, taxgrp2, taxgrp3, &noVoid, &dds, &podr, &payStart, &payEnd, &powerDown, &invoice))
						return ZFPE_BADRESPONSEDATA;
				}
				*flags |= ('1' == noVoid) ? ZFPB_NOVOID : 0;
				*flags |= ('1' == dds) ? ZFPB_DDS : 0;
				*flags |= ('1' == podr) ? ZFPB_PODRBON : 0;
				*flags |= ('1' == payStart) ? ZFPB_PAYSTART : 0;
				*flags |= ('1' == payEnd) ? ZFPB_PAYEND : 0;
				*flags |= ('1' == powerDown) ? ZFPB_POWERDOWN : 0;
				*flags |= ('1' == invoice) ? ZFPB_INVOICE : 0;
			}
		}
	}
	return res;
}

//////////////////////////////////////////////////////////////////////
// Setup commands & tools
//////////////////////////////////////////////////////////////////////
int CZekaFP::SetPayType(BYTE type, const char* line)
{
	CSerialA serial(m_wCom, m_baudRate);
	if ((1 > type) || (9 < type))
		return ZFPE_BADINPUTDATA;
	char data[ZFP_MAXBUFLEN], data1[ZFP_MAXBUFLEN];
	sprintf(data, "%1u;%-10s", type, nstrcpy(data1, line, 10));
	return SendCommand(&serial, 0x44, TRUE, (BYTE *)&data, 12);
}

int CZekaFP::SetParameters(WORD fpnum, BOOL logo, BOOL till, BOOL autocut, BOOL transparent)
{
	CSerialA serial(m_wCom, m_baudRate);
	if (9999 < fpnum)
		return ZFPE_BADINPUTDATA;
	char data[ZFP_MAXBUFLEN];
	sprintf(data, "%04u;%c;%c;%c;%c", fpnum, logo ? '1' : '0', till ? '1' : '0', 
		autocut ? '1' : '0', transparent ? '1' : '0');
	return SendCommand(&serial, 0x45, TRUE, (BYTE *)&data, 12);
}

int CZekaFP::SetEJMode(BOOL bShort)
{
	char data[ZFP_MAXBUFLEN];

	TZfpParams params;
	int res = GetParametersEU(params);
	if (ZFPE_SUCCESS != res)
		return res;
	
	sprintf(data, "%04u;%c;%c;%c;%c;%c;%c", params.fpnum, params.logo ? '1' : '0', params.till ? '1' : '0', 
		params.autocut ? '1' : '0', params.transparent ? '1' : '0', bShort ? '1' : '0', params.currency ? '1' : '0');

	CSerialA serial(m_wCom, m_baudRate);
	return SendCommand(&serial, 0x45, TRUE, (BYTE *)&data, 16);
}

int CZekaFP::SetDateTime(WORD dd, WORD mm, WORD yy, WORD hh, WORD mmm, WORD ss)
{
	CSerialA serial(m_wCom, m_baudRate);
	if ((1 > dd) || (31 < dd) || (1 > mm) || (12 < mm) || (99 < yy) || (23 < hh) || (59 < mmm) || (59 < ss))
		return ZFPE_BADINPUTDATA;
	char data[ZFP_MAXBUFLEN];
	sprintf(data, "%02u-%02u-%02u %02u:%02u:%02u", dd, mm, yy, hh, mmm, ss);
	return SendCommand(&serial, 0x48, TRUE, (BYTE *)&data, strlen((const char *)data));
}

int CZekaFP::SetClicheLine(BYTE lineNum, const char* text)
{
	CSerialA serial(m_wCom, m_baudRate);
	char data[ZFP_MAXBUFLEN], data1[ZFP_MAXBUFLEN], fmt[16];
	int lw = GetLineWidth();
	sprintf(fmt, "%%c;%%-%us", lw);
	sprintf(data, fmt, lineNum + ( lineNum < 32 ? 0x30 : 0 ), nstrcpy(data1, text, lw));
	return SendCommand(&serial, 0x49, TRUE, (BYTE *)&data, strlen(data));
}

int CZekaFP::SetOperatorUserPass(BYTE oper, const char* name, const char* password)
{
	CSerialA serial(m_wCom, m_baudRate);
	if ((1 > oper) || (20 < oper))
		return ZFPE_BADINPUTDATA;
	char data[ZFP_MAXBUFLEN], data1[ZFP_MAXBUFLEN], data2[ZFP_MAXBUFLEN];
	sprintf(data, "%u;%-20s;%-4s", oper, nstrcpy(data1, name, 20), nstrcpy(data2, password, 4));
	return SendCommand(&serial, 0x4A, TRUE, (BYTE *)&data, strlen((char *)data));
}

int CZekaFP::SetArticleInfoEx(DWORD number, const char* name, double price, char taxgrp, WORD depNum, const char* units)
{
	if (number > 99999 || (-999999999.0 > price) || (9999999999.0 < price) || (99 < depNum))
		return ZFPE_BADINPUTDATA;

	CSerialA serial(m_wCom, m_baudRate);
	BYTE dep = (BYTE)(depNum | 0x80);
	char data[ZFP_MAXBUFLEN], data1[ZFP_MAXBUFLEN];

	char num1[MAX_NUM_LEN];

	if (10 > taxgrp) 
		taxgrp |= 0x30;

	sprintf(data, "%05u;%-20s;%s;%c;%c", number, nstrcpy(data1, name, 20), getfloatformat(num1, taxgrp == '#' ? 1 : price), taxgrp, dep);
	if ( strlen( name ) > 20 || units )
	{
		if ( units )
		  sprintf( data + strlen( data ), ";%c%c", units[0] ? units[0] : 32, units[1] ? units[1] : 32 );
		else
		  sprintf( data + strlen( data ), ";  " );
		if ( strlen( name ) > 20 )
			sprintf( data + strlen( data ), ";%s", nstrcpy(data1, name, 32) + 20 );
		else
		{
			if ( taxgrp == '#' )
				sprintf( data + strlen( data ), ";%20s", "" );
		}
		if ( taxgrp == '#' )
			sprintf( data + strlen( data ), ";%s", getfloatformat(num1, price, 3) );
	}
	int len = strlen( data );

	return SendCommand(&serial, 0x4B, TRUE, (BYTE *)&data, len);
}

int CZekaFP::SetArticleInfo(WORD number, const char* name, double price, char taxgrp, WORD depNum)
{
	if (number > 1000)
		return ZFPE_BADINPUTDATA;

	return SetArticleInfoEx(number, name, price, taxgrp, depNum);
}

int CZekaFP::_SetLogoFile(int logo_id, const char* filename)
{
	if (filename == NULL || logo_id > 9 || logo_id < -1)
		return ZFPE_BADINPUTDATA;

	CSerialA serial(m_wCom, m_baudRate);
	FILE* f = fopen(filename, "rb");
	if (NULL == f) 
		return ZFPE_BADINPUTDATA;
	
	fseek(f, 0, 2); // Go to end of file
	int extra = 4;
	if (logo_id != -1) extra++;
	DWORD buf_size = ftell(f) + extra;
	fseek(f, 0, 0); // Go to start position
	BYTE * buf = new BYTE[buf_size];
	int res = ZFPE_BADLOGOFILE;
	int read = fread(buf + extra, 1, buf_size, f);
	fclose(f);
	if (buf && read > 6 && buf[extra] == 'B' && buf[extra + 1] == 'M' && *((DWORD *)(buf + extra + 2)) == buf_size - extra) // check for valid BITMAPFILEHEADER
	{
		buf[0] = ZFP_STX;
		buf[1] = 0x39;
		buf[2] = 0x37;
		if (logo_id == -1)
		{
			buf[3] = 0x4C;
		}
		else
		{
			buf[3] = 0x4D;
			buf[4] = logo_id + '0';
		}
		serial.WriteToComPort(buf, read + extra);
		res = GetResponse(&serial);
	}
	delete buf;

	return res;
}

int CZekaFP::SetLogoFile(const char* filename)
{
	return _SetLogoFile(-1, filename);
}

int CZekaFP::SetLogoFileEx(BYTE logo_id, const char* filename)
{
	return _SetLogoFile((BYTE)logo_id, filename);
}

int CZekaFP::SetLocalDateTime()
{
#ifdef WIN32
// WARNING: win32 specific API calls !
	SYSTEMTIME st;
	GetLocalTime(&st);
	if (2000 > st.wYear)
		return ZFPE_BADINPUTDATA;
	return SetDateTime(st.wDay, st.wMonth, st.wYear - 2000, st.wHour, st.wMinute, st.wSecond);
#endif
#ifdef POSIX
	struct tm *st = localtime((const time_t*)time(NULL));
	return SetDateTime(st->tm_mday, st->tm_mon, st->tm_year - 100, st->tm_hour, st->tm_min, st->tm_sec);
#endif
}

//////////////////////////////////////////////////////////////////////
// Reports
//////////////////////////////////////////////////////////////////////
int CZekaFP::GetLastFiscalReportData(int* dd, int* mm, int* yy, int* lastReport, int* lastZeroRam)
{
	CSerialA serial(m_wCom, m_baudRate);
	int res = SendCommand(&serial, 0x73, FALSE);
	if (ZFPE_SUCCESS == res) {
		BYTE data[ZFP_MAXBUFLEN], len;
		res = GetResponse(&serial, data, &len);
		if (ZFPE_SUCCESS == res) {
			data[(int)len] = 0;
			if (5 != sscanf((const char*)&data, "%u-%u-%u;%u;%u", dd, mm, yy, lastReport, lastZeroRam))
				return ZFPE_BADRESPONSEDATA;
		}
	}
	return res;
}

int CZekaFP::ReportSpecialFiscal()
{
	CSerialA serial(m_wCom, m_baudRate);
	int res = SendCommand(&serial, 0x77);
	if ((ZFPE_SUCCESS == res) && (ZFP_NOBUSYWAIT != m_autoBusyTimeout))
		return DoBusyWait(&serial, m_autoBusyTimeout);
	return res;
}

int CZekaFP::ReportFiscalByBlock(BOOL detailed, WORD startNumber, WORD endNumber)
{
	CSerialA serial(m_wCom, m_baudRate);
	if ((9999 < startNumber) || (9999 < endNumber))
		return ZFPE_BADINPUTDATA;
	BYTE data[ZFP_MAXBUFLEN];
	sprintf((char *)&data, "%04u;%04u", startNumber, endNumber);
	int res = SendCommand(&serial, detailed ? 0x78 : 0x79, TRUE, data, 9);
	if ((ZFPE_SUCCESS == res) && (ZFP_NOBUSYWAIT != m_autoBusyTimeout))
		return DoBusyWait(&serial, m_autoBusyTimeout);
	return res;
}

int CZekaFP::ReportFiscalByDate(BOOL detailed, WORD sdd, WORD smm, WORD syy, WORD edd, WORD emm, WORD eyy)
{
	CSerialA serial(m_wCom, m_baudRate);
	if ((99 < syy) && (2000 > syy))
		return ZFPE_BADINPUTDATA;
	if ((99 < eyy) && (2000 > eyy))
		return ZFPE_BADINPUTDATA;
	BYTE data[ZFP_MAXBUFLEN];
	sprintf((char *)&data, "%02u%02u%02u;%02u%02u%02u", sdd, smm, syy, edd, emm, eyy);
	int res = SendCommand(&serial, detailed ? 0x7A : 0x7B, TRUE, data, 13);
	if ((ZFPE_SUCCESS == res) && (ZFP_NOBUSYWAIT != m_autoBusyTimeout))
		return DoBusyWait(&serial, m_autoBusyTimeout);
	return res;
}

int CZekaFP::ReportDaily(BOOL zero, BOOL extended)
{
	CSerialA serial(m_wCom, m_baudRate);
	BYTE byZero = zero ? 'Z' : 'X';
	int res = SendCommand(&serial, extended ? 0x7F : 0x7C, TRUE, &byZero, 1);
	if ((ZFPE_SUCCESS == res) && (ZFP_NOBUSYWAIT != m_autoBusyTimeout))
		return DoBusyWait(&serial, m_autoBusyTimeout);
	return res;
}

int CZekaFP::ReportEJ(WORD num)
{
	CSerialA serial(m_wCom, m_baudRate);
	int res;
	if (ZFPT_RO == m_zfpType) {
		BYTE data[10];
		sprintf((char *)&data, "E%04u", num);
		res = SendCommand(&serial, 0x7C, TRUE, data, 5);
	}
	else {
		BYTE mode = 'E';
		res = SendCommand(&serial, 0x7C, TRUE, &mode, 1);
	}
	if ((ZFPE_SUCCESS == res) && (ZFP_NOBUSYWAIT != m_autoBusyTimeout))
		return DoBusyWait(&serial, m_autoBusyTimeout);
	return res;
}

int CZekaFP::ReportOperator(BOOL zero, BYTE oper)
{
	CSerialA serial(m_wCom, m_baudRate);
	if (20 < oper)
		return ZFPE_BADINPUTDATA;
	BYTE data[10];
	sprintf((char *)data, "%c;%u", zero ? 'Z' : 'X', (unsigned)oper);
	int res = SendCommand(&serial, 0x7D, TRUE, data, strlen((char *)data));
	if ((ZFPE_SUCCESS == res) && (ZFP_NOBUSYWAIT != m_autoBusyTimeout))
		return DoBusyWait(&serial, m_autoBusyTimeout);
	return res;
}

int CZekaFP::ReportArticles(BOOL zero)
{
	CSerialA serial(m_wCom, m_baudRate);
	BYTE byZero = zero ? 'Z' : 'X';
	int res = SendCommand(&serial, 0x7E, TRUE, &byZero, 1);
	if ((ZFPE_SUCCESS == res) && (ZFP_NOBUSYWAIT != m_autoBusyTimeout))
		return DoBusyWait(&serial, m_autoBusyTimeout);
	return res;
}

int CZekaFP::ReportDepartments(BOOL zero)
{
	CSerialA serial(m_wCom, m_baudRate);
	BYTE byZero = zero ? 'Z' : 'X';
	int res = SendCommand(&serial, 0x76, TRUE, &byZero, 1);
	if ((ZFPE_SUCCESS == res) && (ZFP_NOBUSYWAIT != m_autoBusyTimeout))
		return DoBusyWait(&serial, m_autoBusyTimeout);
	return res;
}

//////////////////////////////////////////////////////////////////////
// Service
//////////////////////////////////////////////////////////////////////
int CZekaFP::SetExternalDisplayData(const char* password, const BYTE* data, int datalen)
{
	if ((NULL == password) || (NULL == data))
		return ZFPE_BADINPUTDATA;

	CSerialA serial(m_wCom, m_baudRate);
	if (0 > datalen)
		return ZFPE_BADINPUTDATA;
	BYTE mydata[110];
	char passwd[10];
	sprintf((char *)mydata, "%-6s", nstrcpy(passwd, password, 6));
	int len = datalen > 101 ? 101 : datalen;
	memcpy(&mydata[6], data, len);
	return SendCommand(&serial, 0x46, TRUE, mydata, len + 6);
}

int CZekaFP::SetExternalDisplayFile(const char* password, const char* filename)
{
	if ((NULL == password) || (NULL == filename))
		return ZFPE_BADINPUTDATA;

	FILE* f = fopen(filename, "rb");
	if (NULL == f) 
		return ZFPE_BADINPUTDATA;
	
	BYTE mydata[110];
	int len = fread(mydata, 1, 101, f);
	fclose(f);

	if (0 == len)
		return ZFPE_BADINPUTDATA;

	return SetExternalDisplayData(password, mydata, len);
}

int CZekaFP::ReadFiscalMemory(const char* filename)
{
	if (NULL == filename)
		return ZFPE_BADINPUTDATA;

	FILE* f = fopen(filename, "wb");
	if (NULL == f) 
		return ZFPE_BADINPUTDATA;
	
	CSerialA serial(m_wCom, m_baudRate);
	int res = SendCommand(&serial, 0x75, TRUE);
	if (ZFPE_SUCCESS == res) {
		// get the data
		DWORD dwRead = 0;
		DWORD dwTicks = GetTickCount();
		BYTE buf;
		do {
			serial.ReadFromComPort(&buf, 1, &dwRead);
			
			if (dwRead) {
				dwTicks = GetTickCount(); // refresh the timeout
				if (dwRead != fwrite(&buf, 1, dwRead, f)) {
					res = ZFPE_FILEIOERROR;
					break;
				}
			}

			if ((GetTickCount() - dwTicks) > ZFP_TIMEOUT) {
				res = ZFPE_TIMEOUT;
				break;
			}
			Sleep(0);
		}
		while ('@' != buf);
	}

	fclose(f);
	return res;
}

// Remove system info and store fiscal memory to file
int CZekaFP::ReadFiscalMemory2(const char* filename)
{
	if (NULL == filename)
		return ZFPE_BADINPUTDATA;

	FILE* f = fopen(filename, "wb");
	if (NULL == f) 
		return ZFPE_BADINPUTDATA;
	
	CSerialA serial(m_wCom, m_baudRate);
	int res = SendCommand(&serial, 0x75, TRUE);
	if (ZFPE_SUCCESS == res)
	{
		int i;
		DWORD dwRead = 0;
		BYTE buf;
		static BYTE line[256];
		DWORD dwTicks = GetTickCount();

#ifndef POSIX
		COMMTIMEOUTS ct;

		memset(&ct, 0, sizeof ct);
		ct.ReadTotalTimeoutConstant = ZFP_TIMEOUT;
		serial.SetCommTimeouts(&ct);
#endif

	  next_line:
		memset(line, 0, sizeof line);
		for (i = 0; i < sizeof line; )
		{
			serial.ReadFromComPort(&buf, 1, &dwRead);

			if (dwRead)
			{
				line[i++] = buf;
				if (i > 1 && buf == '@')
				{
					fclose(f);
					return res;
				}
				if (buf == 0x0A)
					break;
				dwTicks = GetTickCount();
			}
			if ((GetTickCount() - dwTicks) > ZFP_TIMEOUT)
			{
				fclose(f);
				return ZFPE_TIMEOUT;
			}
		}
		if (i < 7 || line[1] - 0x20 != i - 4)
		{
			res = ZFPE_BADINPUTDATA;
		}
		else
		{
			BYTE crc1, crc2;
			MakeCRC( line + 1, i - 4, &crc1, &crc2 );
			if ( crc1 == line[i - 3] && crc2 == line[i - 2] )
			{
				static BYTE crlf[] = { 13, 10};

				if (fwrite(line + 4, 1, i - 7, f) == (unsigned)i - 7 && fwrite(crlf, 1, sizeof crlf, f) == sizeof crlf)
				{
					goto next_line;
				}
				res = ZFPE_FILEIOERROR;
			}
			else
			{
				res = ZFPE_CRCERROR;
			}
		}
	}

	fclose(f);
	return res;
}

int CZekaFP::GetFreeFiscalSpace(int* records)
{
	CSerialA serial(m_wCom, m_baudRate);
	int res = SendCommand(&serial, 0x74, FALSE);
	if (ZFPE_SUCCESS == res) {
		BYTE data[ZFP_MAXBUFLEN], len;
		res = GetResponse(&serial, data, &len);
		if (ZFPE_SUCCESS == res) {
			data[(int)len] = 0;
			if (1 != sscanf((const char*)&data, "%u", records))
				return ZFPE_BADRESPONSEDATA;
		}
	}
	return res;
}

int CZekaFP::GetStartDateFM( char * date )
{
	CSerialA serial(m_wCom, m_baudRate);
	int res = SendCommand(&serial, 0x74, FALSE);
	if (ZFPE_SUCCESS == res)
	{
		BYTE data[ZFP_MAXBUFLEN], len;
		res = GetResponse(&serial, data, &len);
		if (ZFPE_SUCCESS == res)
		{
			int i;

			data[(int)len] = 0;

			for ( i = 0; data[i] && data[i] != ';'; i++ );
			if ( data[i] == ';' && data[i + 1] )
			{
				int j = i + 1;

				do i++; while ( data[i] && data[i] != ';' );
				if ( data[i] ) data[i] = 0;
				strcpy( date, (char *)data + j );
			}
			else
			{
				return ZFPE_BADRESPONSEDATA;
			}
		}
	}
	return res;
}

int CZekaFP::SetSerialNumber(const char* password, const char* manifactureNum, 
							 const char* fiscalNum, const char* controlSum)
{
	if ((NULL == password) || (NULL == manifactureNum) || !manifactureNum || strlen(manifactureNum) > 32)
		return ZFPE_BADINPUTDATA;

	CSerialA serial(m_wCom, m_baudRate);
	BYTE mydata[128];
	char passwd[8], fnum[8], cs[8];
	if (ZFPT_RO == m_zfpType)
	{
		sprintf((char *)mydata, "%-6s;%-6s;", nstrcpy(passwd, password, 6), manifactureNum);
	}
	else
	{
		if ((NULL == fiscalNum) || (NULL == controlSum))
			return ZFPE_BADINPUTDATA;
		sprintf((char *)mydata, "%-6s;%-6s;%-6s;%-6s", nstrcpy(passwd, password, 6), 
			manifactureNum, nstrcpy(fnum, fiscalNum, 6), nstrcpy(cs, controlSum, 6));
	}
	return SendCommand(&serial, 0x40, TRUE, mydata, strlen((char *)mydata));
}

int CZekaFP::SetTaxNumber(const char* password, const char* taxNum, const char* fiscalNum)
{
	if ((NULL == password) || (NULL == taxNum))
		return ZFPE_BADINPUTDATA;

	CSerialA serial(m_wCom, m_baudRate);
	BYTE mydata[40];
	char passwd[8], tn[20], fn[20];
	if (ZFPT_RO == m_zfpType) {
		if (NULL == fiscalNum)
			return ZFPE_BADINPUTDATA;
		sprintf((char *)mydata, "%-6s;1;%-15s;%-12s;", nstrcpy(passwd, password, 6), nstrcpy(tn, taxNum, 15),
			nstrcpy(fn, fiscalNum, 12));
	}
	else 
		sprintf((char *)mydata, "%-6s;1;%-13s", nstrcpy(passwd, password, 6), nstrcpy(tn, taxNum, 13));
	return SendCommand(&serial, 0x41, TRUE, mydata, strlen((char *)mydata));
}

int CZekaFP::MakeFiscal(const char* password)
{
	if (NULL == password)
		return ZFPE_BADINPUTDATA;

	CSerialA serial(m_wCom, m_baudRate);
	BYTE mydata[20];
	char passwd[8];
	sprintf((char *)mydata, "%-6s;2", nstrcpy(passwd, password, 6));
	return SendCommand(&serial, 0x41, TRUE, mydata, 8);
}

int CZekaFP::SetTaxPercents(const char* password, double tgr1, double tgr2, double tgr3, double tgr4)
{
	if ((NULL == password) || (100.0 < tgr1) || (100.0 < tgr2) || (100.0 < tgr3) || (100.0 < tgr4))
		return ZFPE_BADINPUTDATA;

	CSerialA serial(m_wCom, m_baudRate);
	BYTE mydata[40];
	char passwd[8];
	if (ZFPT_RO == m_zfpType)
		sprintf((char *)mydata, "%-6s;%.2f%%;%.2f%%;%.2f%%;%.2f%%", nstrcpy(passwd, password, 6), tgr1, tgr2, tgr3, tgr4);
	else
		sprintf((char *)mydata, "%-6s;%.2f%%;%.2f%%;%.2f%%", nstrcpy(passwd, password, 6), tgr1, tgr2, tgr3);
	return SendCommand(&serial, 0x42, TRUE, mydata, strlen((char *)mydata));
}

int CZekaFP::SetDecimalPoint(const char* password, int point)
{
	if ((NULL == password) || (0 > point) || (9 < point))
		return ZFPE_BADINPUTDATA;

	CSerialA serial(m_wCom, m_baudRate);
	BYTE mydata[30];
	char passwd[8];
	sprintf((char *)mydata, "%-6s;%1u", nstrcpy(passwd, password, 6), point);
	return SendCommand(&serial, 0x43, TRUE, mydata, 8);
}

int CZekaFP::SetDepartment(WORD number, const char* name, char taxgrp)
{
	CSerialA serial(m_wCom, m_baudRate);
	if (99 < number)
		return ZFPE_BADINPUTDATA;

	if (10 > taxgrp) 
		taxgrp |= 0x30;

	char data[ZFP_MAXBUFLEN], data1[ZFP_MAXBUFLEN];
	sprintf(data, "%02u;%-20s;%c", number, nstrcpy(data1, name, 20), taxgrp);
	return SendCommand(&serial, 0x47, TRUE, (BYTE *)&data, 25);
}

int CZekaFP::GetDepartment(WORD number, char* name, char* taxgrp, double* turnover)
{
	CSerialA serial(m_wCom, m_baudRate);
	if (99 < number)
		return ZFPE_BADINPUTDATA;
	BYTE data[ZFP_MAXBUFLEN], len;
	sprintf((char *)data, "%02u", number);
	int res = SendCommand(&serial, 0x67, FALSE, data, 2);
	if (ZFPE_SUCCESS == res) {
		res = GetResponse(&serial, data, &len);
		if (ZFPE_SUCCESS == res) {
			data[(int)len] = 0;
			nstrcpy(name, (const char*)&data[3], 20);
			if (2 != sscanf((const char*)&data[24], "%c;%le", taxgrp, turnover))
				return ZFPE_BADRESPONSEDATA;
		}
	}
	return res;
}

int CZekaFP::SellDepartmentEx(const char* name, WORD depNum, double price, double quantity, double discount, BYTE flag)
{
	if ( (-99999999.0 > price) || (99999999.0 < price) || (0.0 > quantity) || 
		(999999.999 < quantity) || (flag == 0 && (-999.0 > discount || 999.0 < discount)) || 99 < depNum )
		return ZFPE_BADINPUTDATA;

	if (flag > 1)
		return ZFPE_BADINPUTDATA;

	CSerialA serial(m_wCom, m_baudRate);
	BYTE dep = (BYTE)(depNum | 0x80);

	char num1[MAX_NUM_LEN], num2[MAX_NUM_LEN], newname[ZFP_MAXBUFLEN], fmt[40];
	BYTE data[ZFP_MAXBUFLEN];
	int lw = 36;
	nstrcpy(newname, name, lw);
	getfloatformat(num1, price);
	getfloatformat(num2, quantity, 3);

	if (discount == 0.0)
	{
		sprintf(fmt, "%%-%us;%%c;%%s*%%s", lw);
		sprintf((char *)&data, fmt, newname, dep, num1, num2);
	}
	else
	{
		if (flag == 0) // percent
		{
			sprintf(fmt, "%%-%us;%%c;%%s*%%s,%%06.2f%%%%", lw);
			sprintf((char *)&data, fmt, newname, dep, num1, num2, discount);
		}

		if (flag == 1) // value
		{
			sprintf(fmt, "%%-%us;%%c;%%s*%%s:%%010.2f", lw);
			sprintf((char *)&data, fmt, newname, dep, num1, num2, discount);
		}
	}
	return SendCommand(&serial, 0x34, TRUE, data, strlen((char *)&data));
}

int CZekaFP::SellDepartment(const char* name, WORD depNum, double price, double quantity, double discount)
{
	return SellDepartmentEx(name, depNum, price, quantity, discount, 0);
}


//////////////////////////////////////////////////////////////////////
// EURO compatible functions
//////////////////////////////////////////////////////////////////////
int CZekaFP::SetTaxPercentsEU(const char* password, const TZfpTaxGroups& taxGroups)
{
	if ((NULL == password) || (100.0 < taxGroups.taxGrp1) || (100.0 < taxGroups.taxGrp2) || (100.0 < taxGroups.taxGrp3))
		return ZFPE_BADINPUTDATA;

	CSerialA serial(m_wCom, m_baudRate);
	BYTE mydata[ZFP_MAXBUFLEN];
	char passwd[8];
	/*switch (m_zfpType) {
	case ZFPT_RO:
		sprintf((char *)mydata, "%-6s;%.2f%%;%.2f%%;%.2f%%;%.2f%%", nstrcpy(passwd, password, 6), taxGroups.taxGrp1, taxGroups.taxGrp2, taxGroups.taxGrp3, taxGroups.taxGrp4);
		break;
	case ZFPT_BGEU:*/
		sprintf((char *)mydata, "%-6s;%.2f%%;%.2f%%;%.2f%%;%.2f%%;%.2f%%;%.2f%%;%.2f%%;%.2f%%", nstrcpy(passwd, password, 6), taxGroups.taxGrp1, taxGroups.taxGrp2, taxGroups.taxGrp3, 
			taxGroups.taxGrp4, taxGroups.taxGrp5, taxGroups.taxGrp6, taxGroups.taxGrp7, taxGroups.taxGrp8);
/*		break;
	default:
		sprintf((char *)mydata, "%-6s;%.2f%%;%.2f%%;%.2f%%", nstrcpy(passwd, password, 6), taxGroups.taxGrp1, taxGroups.taxGrp2, taxGroups.taxGrp3);
		break;
	}*/
		
	return SendCommand(&serial, 0x42, TRUE, mydata, strlen((char *)mydata));
}

int CZekaFP::SetPayTypeEU(BYTE type, const char* line, double exchRate, int code)
{
	CSerialA serial(m_wCom, m_baudRate);
	if ((1 > type) || (9 < type))
		return ZFPE_BADINPUTDATA;
	char data[ZFP_MAXBUFLEN], data1[ZFP_MAXBUFLEN], scode[3];
	scode[0] = 0;
	if ( code >= 0 && type != 4 )
	{
		scode[0] = ';';
		scode[1] = (char)( code < 32 ? code + '0' : (BYTE)code );
		scode[2] = 0;
	}
	//if ((ZFPT_BGEU == m_zfpType) && (0.0 < exchRate))
		sprintf(data, "%1u;%-10s;%10.5f%s", type, nstrcpy(data1, line, 10), exchRate, scode);
	//else
	//	sprintf(data, "%1u;%-10s", type, nstrcpy(data1, line, 10));
	return SendCommand(&serial, 0x44, TRUE, (BYTE *)&data, strlen(data));
}

int CZekaFP::SetParametersEU(const TZfpParams& parameters)
{
	CSerialA serial(m_wCom, m_baudRate);
	if (9999 < parameters.fpnum)
		return ZFPE_BADINPUTDATA;
	char data[ZFP_MAXBUFLEN];
	if (((WORD)parameters.currency & 0x8000) != 0)
	{
		sprintf(data, "%04u;%c;%c;%c;%c;%c;%c;%c;%c;%c", parameters.fpnum, parameters.logo ? '1' : '0', parameters.till ? '1' : '0', 
			parameters.autocut ? '1' : '0', parameters.transparent ? '1' : '0', parameters.shortEJ ? '1' : '0', parameters.currency & 1 ? '1' : '0', parameters.currency & 2 ? '1' : '0', parameters.currency & 4 ? '1' : '0', parameters.currency & 8 ? '1' : '0');
	}
	else
	{
		sprintf(data, "%04u;%c;%c;%c;%c;%c;%c", parameters.fpnum, parameters.logo ? '1' : '0', parameters.till ? '1' : '0', 
			parameters.autocut ? '1' : '0', parameters.transparent ? '1' : '0', parameters.shortEJ ? '1' : '0', parameters.currency ? '1' : '0');
	}
	return SendCommand(&serial, 0x45, TRUE, (BYTE *)&data, strlen(data));
}

int CZekaFP::GetTaxPercentsEU(TZfpTaxGroups& taxGroups)
{
	CSerialA serial(m_wCom, m_baudRate);
	int res = SendCommand(&serial, 0x62, FALSE);
	if (ZFPE_SUCCESS == res) {
		BYTE data[ZFP_MAXBUFLEN], len;
		res = GetResponse(&serial, data, &len);
		if (ZFPE_SUCCESS == res) {
			data[(int)len] = 0;
			strreplace((char *)data, ' ', '0');
			if (ZFPT_RO == m_zfpType) {
				if (4 != sscanf((const char*)&data, "%le%%;%le%%;%le%%;%le", &taxGroups.taxGrp1, &taxGroups.taxGrp2, 
							&taxGroups.taxGrp3, &taxGroups.taxGrp4))
					return ZFPE_BADRESPONSEDATA;
			}
			else {
				if (8 != sscanf((const char*)&data, "%le%%;%le%%;%le%%;%le%%;%le%%;%le%%;%le%%;%le", &taxGroups.taxGrp1, 
							&taxGroups.taxGrp2, &taxGroups.taxGrp3, &taxGroups.taxGrp4, &taxGroups.taxGrp5, 
							&taxGroups.taxGrp6, &taxGroups.taxGrp7, &taxGroups.taxGrp8)) // zeka fp/fp01 - E
					if (5 != sscanf((const char*)&data, "%le%%;%le%%;%le%%;%le%%;%le%%", &taxGroups.taxGrp1, 
								&taxGroups.taxGrp2, &taxGroups.taxGrp3, &taxGroups.taxGrp4, &taxGroups.taxGrp5))  // kenya
						if (3 != sscanf((const char*)&data, "%le%%;%le%%;%le", &taxGroups.taxGrp1, &taxGroups.taxGrp2, 
							&taxGroups.taxGrp3)) { // zeka fp/fp01
							taxGroups.taxGrp4 = -1.0;
							taxGroups.taxGrp5 = -1.0;
							taxGroups.taxGrp6 = -1.0;
							taxGroups.taxGrp7 = -1.0;
							taxGroups.taxGrp8 = -1.0;
							return ZFPE_BADRESPONSEDATA;
						}
			}
		}
	}
	return res;
}

int CZekaFP::GetParametersEU(TZfpParams& parameters)
{
	CSerialA serial(m_wCom, m_baudRate);
	int res = SendCommand(&serial, 0x65, FALSE);
	if (ZFPE_SUCCESS == res)
	{
		BYTE data[ZFP_MAXBUFLEN], len;
		memset(data, 0, sizeof data);
		res = GetResponse(&serial, data, &len);
		if (ZFPE_SUCCESS == res)
		{
			memset(&parameters, 0, sizeof(TZfpParams));
			data[(int)len] = 0;
			int crn = 0, low_font = 0;
			if ( sscanf((const char*)&data, "%04hu;%1u;%1u;%1u;%1u;%1u;%1u;%1u", &parameters.fpnum, &parameters.logo, 
					&parameters.till, &parameters.autocut, &parameters.transparent, &parameters.shortEJ, &crn, &low_font) == 8 )
			{
				int ej_note = 0, single_op = 0;

				if (data[18] == ';' && data[19] == '1') ej_note = 1;
				if (data[20] == ';' && data[21] == '1') single_op = 1;
				parameters.currency = 0x8000 | crn | (low_font << 1) | ( ej_note << 2 ) | ( single_op << 3 );
			}
			else
			{
				sscanf((const char*)data, "%04hu;", &parameters.fpnum);
				parameters.logo        = data[5] == '1';
				parameters.till        = data[7] == '1';
				parameters.autocut     = data[9] == '1';
				parameters.transparent = data[11] == '1';
				parameters.shortEJ     = data[13] == '1';
				parameters.currency    = data[15] == '1';
			}
		}
	}
	return res;
}

int CZekaFP::GetPayTypesEU(TZfpPayTypes& payTypes)
{
	CSerialA serial(m_wCom, m_baudRate);
	int res = SendCommand(&serial, 0x64, FALSE);
	if (ZFPE_SUCCESS == res) {
		BYTE data[ZFP_MAXBUFLEN], len;
		res = GetResponse(&serial, data, &len);
		if (ZFPE_SUCCESS == res) {
			nstrcpy(payTypes.type0, (const char*)&data[0], 10);
			nstrcpy(payTypes.type1, (const char*)&data[11], 10);
			nstrcpy(payTypes.type2, (const char*)&data[22], 10);
			nstrcpy(payTypes.type3, (const char*)&data[33], 10);
			nstrcpy(payTypes.type4, (const char*)&data[44], 10);
			mystrtrim(payTypes.type0);
			mystrtrim(payTypes.type1);
			mystrtrim(payTypes.type2);
			mystrtrim(payTypes.type3);
			mystrtrim(payTypes.type4);
			if (55 < len) {
				if (1 != sscanf((char *)&data[55], "%le", &payTypes.exchRate)) 
					return ZFPE_BADRESPONSEDATA;
			}
			else
				payTypes.exchRate = -1.0;
		}
	}
	return res;
}

int CZekaFP::PaymentEU(double sum, BYTE type, BOOL noChange, BYTE changeType)
{
	return PaymentEx(sum, type, noChange, changeType, 0);
}

int CZekaFP::PaymentEx(double sum, BYTE type, BOOL noChange, BYTE changeType, BOOL fPaidExactSum)
{
	CSerialA serial(m_wCom, m_baudRate);
	if ( ( sum < 0.0 && sum != -1 ) || (9999999999.0 < sum))
		return ZFPE_BADINPUTDATA;
	BYTE data[ZFP_MAXBUFLEN];
	char num1[MAX_NUM_LEN];

	sprintf((char *)&data, "%1u;%c;%s;%1u", type, noChange ? '1' : '0', fPaidExactSum ? "\"" : ( sum == -1 ? "-" : getfloatformat(num1, sum) ), changeType);
	return SendCommand(&serial, 0x35, TRUE, data, strlen((char *)&data));
}

int CZekaFP::GetCurrentBonInfoEU(TZfpReceiptInfo& info)
{
	memset(&info, 0, sizeof(TZfpReceiptInfo));
	CSerialA serial(m_wCom, m_baudRate);
	unsigned _changeType;
	int res = SendCommand(&serial, 0x72, FALSE);
	if (ZFPE_SUCCESS == res) {
		BYTE data[ZFP_MAXBUFLEN], len;
		res = GetResponse(&serial, data, &len);
		if (ZFPE_SUCCESS == res) {
			if ('0' != data[0]) {
				info.flags = ZFPB_OPENBON;
				char noVoid, dds, podr, payStart, payEnd, powerDown, invoice;
				data[(int)len] = 0;
				if (ZFPT_RO == m_zfpType)
				{
					if (16 != sscanf((const char*)&data[2], "%u;%le;%le;%le;%le;%le;%1c;%1c;%1c;%1c;%1c;%1c;%1c;%le;%1d;%le",
								&info.purchases, &info.taxGroups.taxGrp1, &info.taxGroups.taxGrp2, &info.taxGroups.taxGrp3, 
								&info.taxGroups.taxGrp4, &info.taxGroups.taxGrp5, &noVoid, &dds, &podr, &payStart, &payEnd, &powerDown, &invoice, 
								&info.change, &_changeType, &info.taxGroups.taxGrp6))
						if (12 != sscanf((const char*)&data[2], "%u;%le;%le;%le;%le;%le;%1c;%1c;%1c;%1c;%1c;%1c", 
								&info.purchases, &info.taxGroups.taxGrp1, &info.taxGroups.taxGrp2, &info.taxGroups.taxGrp3, 
								&info.taxGroups.taxGrp4, &info.taxGroups.taxGrp5, 
								&noVoid, &dds, &podr, &payStart, &payEnd, &powerDown))
							return ZFPE_BADRESPONSEDATA;
				}
				else
				{
					if (18 != sscanf((const char*)&data[2], "%u;%le;%le;%le;%1c;%1c;%1c;%1c;%1c;%1c;%1c;%le;%1d;%le;%le;%le;%le;%le",
							&info.purchases, &info.taxGroups.taxGrp1, &info.taxGroups.taxGrp2, &info.taxGroups.taxGrp3, 
							&noVoid, &dds, &podr, &payStart, &payEnd, &powerDown, &invoice, 
							&info.change, &_changeType, &info.taxGroups.taxGrp4, &info.taxGroups.taxGrp5, 
							&info.taxGroups.taxGrp6, &info.taxGroups.taxGrp7, &info.taxGroups.taxGrp8))
						if (16 != sscanf((const char*)&data[2], "%u;%le;%le;%le;%le;%le;%1c;%1c;%1c;%1c;%1c;%1c;%1c;%le;%1d;%le",
								&info.purchases, &info.taxGroups.taxGrp1, &info.taxGroups.taxGrp2, &info.taxGroups.taxGrp3, 
								&info.taxGroups.taxGrp4, &info.taxGroups.taxGrp5, &noVoid, &dds, &podr, &payStart, &payEnd, &powerDown, &invoice, 
								&info.change, &_changeType, &info.taxGroups.taxGrp6))
						if (15 != sscanf((const char*)&data[2], "%u;%le;%le;%le;%le;%le;%1c;%1c;%1c;%1c;%1c;%1c;%1c;%le;%1d",
								&info.purchases, &info.taxGroups.taxGrp1, &info.taxGroups.taxGrp2, &info.taxGroups.taxGrp3, 
								&info.taxGroups.taxGrp4, &info.taxGroups.taxGrp5, &noVoid, &dds, &podr, &payStart, &payEnd, &powerDown, &invoice, 
								&info.change, &_changeType))
							if (11 != sscanf((const char*)&data[2], "%u;%le;%le;%le;%1c;%1c;%1c;%1c;%1c;%1c;%1c", 
									&info.purchases, &info.taxGroups.taxGrp1, &info.taxGroups.taxGrp2, &info.taxGroups.taxGrp3, 
									&noVoid, &dds, &podr, &payStart, &payEnd, &powerDown, &invoice))
								return ZFPE_BADRESPONSEDATA;
				}
				info.flags |= ('1' == noVoid) ? ZFPB_NOVOID : 0;
				info.flags |= ('1' == dds) ? ZFPB_DDS : 0;
				info.flags |= ('1' == podr) ? ZFPB_PODRBON : 0;
				info.flags |= ('1' == payStart) ? ZFPB_PAYSTART : 0;
				info.flags |= ('1' == payEnd) ? ZFPB_PAYEND : 0;
				info.flags |= ('1' == powerDown) ? ZFPB_POWERDOWN : 0;
				info.flags |= ('1' == invoice) ? ZFPB_INVOICE : 0;
			}
			else {
				if ((2 != sscanf((const char*)&data[56], "%le;%1d", &info.change, &_changeType)) && (82 < len)) 
					sscanf((const char*)&data[80], "%le;%1d", &info.change, &_changeType);
			}
		}
	}
	info.changeType = (BYTE)_changeType;
	return res;
}

int CZekaFP::GetDailySumsEU(TZfpTaxGroups& taxGroups)
{
	CSerialA serial(m_wCom, m_baudRate);
	int res = SendCommand(&serial, 0x6D, FALSE);
	if (ZFPE_SUCCESS == res) {
		BYTE data[ZFP_MAXBUFLEN], len;
		res = GetResponse(&serial, data, &len);
		if (ZFPE_SUCCESS == res)
		{
			data[(int)len] = 0;
			if (ZFPT_RO == m_zfpType)
			{
				if (5 != sscanf((const char*)&data, "%le;%le;%le;%le;%le", &taxGroups.taxGrp1, 
					&taxGroups.taxGrp2, &taxGroups.taxGrp3, &taxGroups.taxGrp4, &taxGroups.taxGrp5))
					return ZFPE_BADRESPONSEDATA;
			}
			else
			{
				if (8 != sscanf((const char*)&data, "%le;%le;%le;%le;%le;%le;%le;%le", &taxGroups.taxGrp1, 
					&taxGroups.taxGrp2, &taxGroups.taxGrp3, &taxGroups.taxGrp4, &taxGroups.taxGrp5,
					&taxGroups.taxGrp6, &taxGroups.taxGrp7, &taxGroups.taxGrp8))
					return ZFPE_BADRESPONSEDATA;
			}
		}
	}
	return res;
}

int CZekaFP::GetOperatorChangeEU(BYTE oper, double* paytype0, double* paytype1, double* paytype2, double* paytype3, double* paytype4)
{
	CSerialA serial(m_wCom, m_baudRate);
	if ((1 > oper) || (20 < oper))
		return ZFPE_BADINPUTDATA;
	BYTE data[ZFP_MAXBUFLEN], len;
	sprintf((char *)data, "6;%u", (unsigned)oper);
	int add = strlen((char *)data);
	int res = SendCommand(&serial, 0x6F, FALSE, data, add);
	if (ZFPE_SUCCESS == res) {
		res = GetResponse(&serial, data, &len);
		if (ZFPE_SUCCESS == res) {
			data[(int)len] = 0;
			if (5 != sscanf((const char*)data + add + 1, "%le;%le;%le;%le;%le", paytype0, paytype1, paytype2, paytype3, paytype4))
				return ZFPE_BADRESPONSEDATA;
		}
	}
	return res;
}

int CZekaFP::GetInvoiceNextNumberEU(char* nextNum, char* lastNum)
{
	CSerialA serial(m_wCom, m_baudRate);
	BYTE data[ZFP_MAXBUFLEN], len;
	int res = SendCommand(&serial, 0x70, FALSE);
	if (ZFPE_SUCCESS == res) {
		res = GetResponse(&serial, data, &len);
		if (ZFPE_SUCCESS == res) {
			data[(int)len] = 0;
			nstrcpy(nextNum, (const char*)&data[0], 10);
			nstrcpy(lastNum, (const char*)&data[11], 10);
			mystrtrim(nextNum);
			mystrtrim(lastNum);
		}
	}
	return res;
}

int CZekaFP::SetInvoiceNumbersRangeEU(const char* startNum, const char* lastNum)
{
	CSerialA serial(m_wCom, m_baudRate);
	char data[ZFP_MAXBUFLEN], data1[ZFP_MAXBUFLEN], data2[ZFP_MAXBUFLEN];
	sprintf(data, "%010s;%010s", nstrcpy(data1, startNum, 10), nstrcpy(data2, lastNum, 10));
	return SendCommand(&serial, 0x50, TRUE, (BYTE *)&data, 21);
}

int CZekaFP::GetDepartmentEU(WORD number, char* name, char* taxgrp, double* turnover, double* quantity)
{
	WORD counter;
	int dd, mm, yy, hh, mmm;

	return GetDepartmentEx(number, name, taxgrp, turnover, quantity, &counter, &dd, &mm, &yy, &hh, &mmm);
}

int CZekaFP::GetDepartmentEx(WORD number, char* name, char* taxgrp, double* turnover, double* quantity, WORD* counter, int* dd, int* mm, int* yy, int* hh, int* mmm)
{
	if (number > 99)
		return ZFPE_BADINPUTDATA;

	CSerialA serial(m_wCom, m_baudRate);
	BYTE data[ZFP_MAXBUFLEN], len;
	sprintf((char *)data, "%02u", (unsigned)number);
	int res = SendCommand(&serial, 0x67, FALSE, data, 2);
	if (ZFPE_SUCCESS == res)
	{
		res = GetResponse(&serial, data, &len);
		if (ZFPE_SUCCESS == res) 
		{
			data[(int)len] = 0;
			nstrcpy(name, (const char*)&data[3], 20);

			if (3 != sscanf((const char*)&data[24], "%c;%le;%le", taxgrp, turnover, quantity)) 
			{
				if (2 != sscanf((const char*)&data[24], "%c;%le", taxgrp, turnover))
					return ZFPE_BADRESPONSEDATA;
				else
					*quantity = -1.0;
			}
			else
			{
				if (len < 71 || sscanf((const char*)data + 50, "%hu;%u-%u-%u %u:%u", counter, dd, mm, yy, hh, mmm) != 6)
				{
					*counter = 65535;
					*dd = 1;
					*mm = 1;
					*yy = 2000;
					*hh = 0;
					*mmm = 0;
				}
			}
		}
	}
	return res;
}

int CZekaFP::GetDailyChangeEU(double* paytype0, double* paytype1, double* paytype2, double* paytype3, double* paytype4)
{
	CSerialA serial(m_wCom, m_baudRate);
	BYTE data[ZFP_MAXBUFLEN], len;
	int res = SendCommand(&serial, 0x6E, FALSE, (BYTE *)"6", 1);
	if (ZFPE_SUCCESS == res) {
		res = GetResponse(&serial, data, &len);
		if (ZFPE_SUCCESS == res) {
			data[(int)len] = 0;
			if (5 != sscanf((const char*)&data[2], "%le;%le;%le;%le;%le", paytype0, paytype1, paytype2, paytype3, paytype4))
				return ZFPE_BADRESPONSEDATA;
		}
	}
	return res;
}

int CZekaFP::UpdateClicheKE(BYTE mode, const char* passwd)
{
	CSerialA serial(m_wCom, m_baudRate);

	BYTE data[ZFP_MAXBUFLEN];
	if (2 != mode)
		sprintf((char *)data, "%1u", mode);
	else {
		char newpass[7];
		sprintf((char *)data, "%1u;%-6s", mode, nstrcpy(newpass, passwd, 6));
	}
	return SendCommand(&serial, 0x57, TRUE, data, strlen((const char *)data));
}

int CZekaFP::SetLogo(BYTE logo)
{
	CSerialA serial(m_wCom, m_baudRate);

	if (logo < 0 || logo > 9)
		return ZFPE_BADINPUTDATA;

	BYTE data = logo + '0';
	return SendCommand(&serial, 0x23, TRUE, (BYTE *)&data, 1);
}

int CZekaFP::GetLogoInfo(char * logo_info)
{
	CSerialA serial(m_wCom, m_baudRate);

	BYTE data[ZFP_MAXBUFLEN], len;
	data[0] = '?';
	int res = SendCommand(&serial, 0x23, FALSE, (BYTE *)&data, 1);

	if (res == ZFPE_SUCCESS)
	{
		res = GetResponse(&serial, data, &len);

		if (res == ZFPE_SUCCESS)
		{
			if (len == 12)
			{
				strncpy(logo_info, (const char *)data, len + 1);
			}
			else
			{
				return ZFPE_BADRESPONSEDATA;
			}
		}
	}
	return res;
}

int CZekaFP::PrintLogoEx(BYTE logo)
{
	if (logo < 0 || logo > 9)
		return ZFPE_BADINPUTDATA;

	CSerialA serial(m_wCom, m_baudRate);

	BYTE data = logo + '0';
	return SendCommand(&serial, 0x6C, TRUE, (BYTE *)&data, 1);
}

int CZekaFP::CloseBonInCash()
{
	CSerialA serial(m_wCom, m_baudRate);
#ifndef POSIX
	if (serial.fKeepOpen == 1)
		serial.fKeepOpen = 0;
#endif
	if (PrintModeFlag(PMFLAG_ONE_TIME))
		SetPrintMode(0);

	return SendCommand(&serial, 0x36);
}

int CZekaFP::CloseBonCancel()
{
	CSerialA serial(m_wCom, m_baudRate);
#ifndef POSIX
	if (serial.fKeepOpen == 1)
		serial.fKeepOpen = 0;
#endif
	if (PrintModeFlag(PMFLAG_ONE_TIME))
		SetPrintMode(0);

	return SendCommand(&serial, 0x39);
}

int CZekaFP::GetVersionGS(char* version)
{
	CSerialA serial(m_wCom, m_baudRate);

	int res = GSCmdPrepare(&serial);
	if (res != ZFPE_SUCCESS)
		return res;
	m_inputBuf[1] = '?';
	m_inputLen = 2;
	serial.WriteToComPort((BYTE *)m_inputBuf, m_inputLen);

	res = ZFPE_SUCCESS;

	DWORD dwRead = ZFP_MAXBUFLEN;
	DWORD dwTicks = GetTickCount();
	DWORD start = 0;
	do
	{
		serial.ReadFromComPort(m_responseBuf + start, ZFP_MAXBUFLEN - start, &dwRead);
		Sleep(20);
		start += dwRead;
		if ((GetTickCount() - dwTicks) > ZFP_TIMEOUT)
		{
			return ZFPE_TIMEOUT;
		}

	}
	while (start < 4 || dwRead > 0 || (GetTickCount() - dwTicks) < 100);

	m_responseLen = start;

	strncpy(version, (char *)m_responseBuf + 3, m_responseLen - 2);

	return ZFPE_SUCCESS;
}

int CZekaFP::GSCmdPrepare(CSerialA * serial, BOOL checkPrn)
{
	if (checkPrn)
	{
		if (CheckForFPrinter(serial))
			return ZFPE_NOFPRINTER;
		if (CheckForBusy(serial))
			return ZFPE_FPRINTERBUSY;
	}
	
	Clear();
	serial->ClearInQueue();
	m_inputBuf[ZFP_MAXBUFLEN];
	m_inputBuf[0] = 0x1D;

	return ZFPE_SUCCESS;
}

int CZekaFP::EnableCommGS(BYTE enable, WORD device_no)
{
	if (enable != 0 && enable != 1)
		return ZFPE_BADINPUTDATA;

	CSerialA serial(m_wCom, m_baudRate);
	int res = GSCmdPrepare(&serial, !enable);
	if (res != ZFPE_SUCCESS)
		return res;
	sprintf((char *)m_inputBuf + 1, "=%cF%04u", enable ? '1' : '0', device_no);
	m_inputLen = strlen((char *)m_inputBuf);
	serial.WriteToComPort((BYTE *)m_inputBuf, m_inputLen);

	return ZFPE_SUCCESS;
}

int CZekaFP::SetSpeedGS(BYTE speed)
{
	if (speed > 4)
		return ZFPE_BADINPUTDATA;

	CSerialA serial(m_wCom, m_baudRate);

	int res = GSCmdPrepare(&serial);
	if (res != ZFPE_SUCCESS)
		return res;
	sprintf((char *)m_inputBuf + 1, "S%u", (int)speed);
	m_inputLen = strlen((char *)m_inputBuf);
	serial.WriteToComPort((BYTE *)m_inputBuf, m_inputLen);

	return ZFPE_SUCCESS;
}

int CZekaFP::LoadScaleProtocolGS(const char * protocol)
{
	if (!protocol)
		return ZFPE_BADINPUTDATA;

	CSerialA serial(m_wCom, m_baudRate);
	int res = GSCmdPrepare(&serial);
	if (res != ZFPE_SUCCESS)
		return res;
	char * tmp = new char[strlen(protocol) + 1];
	char * t = tmp;
	for (const char *p = protocol; *p; p++)
	{
		*t = *p;
		if (*p == '\\')
		{
			switch (p[1])
			{
			case 'n':
				*t = 10;
				p++;
				break;

			case 'r':
				*t = 13;
				p++;
				break;

			case '\\':
				p++;
				break;
			}
		}
		t++;
	}
	*t = 0;
	if (strlen(tmp) >= ZFP_MAXBUFLEN - 6)
		tmp[ZFP_MAXBUFLEN - 7] = 0;
	sprintf((char *)m_inputBuf + 1, "s%04u;%s", strlen(tmp), tmp);
	delete tmp;
	m_inputLen = strlen((char *)m_inputBuf);
	serial.WriteToComPort((BYTE *)m_inputBuf, m_inputLen);

	DWORD dwPtr = 0, dwRead = 0;
	DWORD dwTicks = GetTickCount();
	m_responseBuf[0] = 0;
	m_responseBuf[1] = 0;
	do
	{
		serial.ReadFromComPort(m_responseBuf, 2, &dwRead);
		dwPtr += dwRead;
		if ((GetTickCount() - dwTicks) > 100) // 0.1 sec
		{
			m_responseLen = (BYTE)dwPtr;
			break;
		}
		Sleep(0);
	}
	while (dwPtr < 2);
	if (m_responseBuf[0] == 0x1D && m_responseBuf[1] == '-') return ZFPE_BADRESPONSEDATA;

	return ZFPE_SUCCESS;
}

int CZekaFP::EnableBarcode(BYTE state)
{
	if (state > 1)
		return ZFPE_BADINPUTDATA;

	CSerialA serial(m_wCom, m_baudRate);

	BYTE data = state == 1 ? 'E' : 'D';
	return SendCommand(&serial, 'Q', TRUE, (BYTE *)&data, 1);
}

int CZekaFP::FormatBarcode(const char * fmt)
{
	if (!fmt || fmt[0] == 0)
		return ZFPE_BADINPUTDATA;
	CSerialA serial(m_wCom, m_baudRate);

	char data[64];

	sprintf(data, "F;%s", fmt);
	return SendCommand(&serial, 'Q', TRUE, (BYTE *)data, strlen(data));
}

int CZekaFP::PrintBarcode(const char * barcode, char type)
{
	if (!barcode || barcode[0] == 0)
		return ZFPE_BADINPUTDATA;

	CSerialA serial(m_wCom, m_baudRate);

	char data[64];

	if ((BYTE)type < 10) type += '0';
	sprintf(data, "P;%c;%02u;%s", type, strlen(barcode), barcode);
	return SendCommand(&serial, 'Q', TRUE, (BYTE *)data, strlen(data));
}

int CZekaFP::SetLineWidth(int num_chars)
{
	if (num_chars == 0) // get length from printer
	{
		char line[ZFP_MAXBUFLEN];

		if (GetClicheLine(0, line) != ZFPE_SUCCESS)
			return 0;

		num_chars = strlen(line);
	}
	if (num_chars < 16) num_chars = 16;
#ifndef POSIX
	SHRegSetUSValue("Software\\Tremol\\ZFPLib", "FPLineWidth", REG_DWORD, &num_chars, sizeof num_chars, SHREGSET_FORCE_HKLM);
#endif

	return ZFPE_SUCCESS;
}

BOOL CZekaFP::PrintModeFlag(DWORD flag)
{
	if (modePrint == 0x80000000)
	{
#ifndef POSIX
		DWORD rs, type = REG_DWORD;

		rs = sizeof modePrint;
		if (SHGetValue(HKEY_LOCAL_MACHINE, "Software\\Tremol\\ZFPLib", "PrintMode", &type, &modePrint, &rs) != ERROR_SUCCESS)
#endif
			modePrint = 0;
	}
	return modePrint & flag ? 1 : 0;
}

int CZekaFP::SetPrintMode(DWORD mode)
{
	if (modePrint == 0x80000000)
		PrintModeFlag(0);
	DWORD prev = modePrint;

	modePrint = mode;
	if ((mode & PMFLAG_SAVE) != 0)
	{
		mode &= ~(PMFLAG_SAVE | 0x80000000 | PMFLAG_ONE_TIME);
#ifndef POSIX
		SHRegSetUSValue("Software\\Tremol\\ZFPLib", "PrintMode", REG_DWORD, &mode, sizeof mode, SHREGSET_FORCE_HKLM);
#endif
	}
	return int( prev & 0x7FFFFFFF );
}

int CZekaFP::OpenTillEx(char num)
{
	if (num != '1' && num != '2' && num != 1 && num != 2)
		return ZFPE_BADINPUTDATA;

	CSerialA serial(m_wCom, m_baudRate);
	BYTE data = 'B';
	return SendCommand(&serial, 0x2A, TRUE, &data, (num & 15) == 1 ? 0 : 1);
}

int CZekaFP::OpenSerialPort()
{
	CSerialA serial(WORD(-(int)m_wCom), m_baudRate);
#ifndef POSIX
	serial.fKeepOpen = 2;
#endif

	return ZFPE_SUCCESS;
}

int CZekaFP::CloseSerialPort()
{
	CSerialA serial(m_wCom, m_baudRate);
#ifndef POSIX
	serial.fKeepOpen = 0;
#endif

	return ZFPE_SUCCESS;
}

int CZekaFP::TerminateBon(BOOL finish)
{
	BYTE status[20];

	int res = GetStatus(status);

	if (res == ZFPE_SUCCESS)
	{
		if ( (status[2] & 1) != 0) // Check for open nonfiscal receipt
		{
			res = CloseBon();
		}
		if ( (status[2] & 2) != 0) // Check for open fiscal receipt
		{
			double pay = 0;

			if (finish && CloseBonInCash() == ZFPE_SUCCESS)
			{
				return ZFPE_SUCCESS;
			}
			if (!finish && CloseBonCancel() == ZFPE_SUCCESS)
			{
				return ZFPE_SUCCESS;
			}
			if (finish == 0) // void
			{
				TZfpReceiptInfo info;

				res = GetCurrentBonInfoEU(info);
				if (res != ZFPE_SUCCESS)
				{
					return res;
				}
				if ( ( info.flags & ( ZFPB_PAYSTART | ZFPB_PAYEND ) ) != 0 )
				{
					Payment(-1,0,0);
				}

				double * taxgr = &info.taxGroups.taxGrp1;
				for (int i = 0; i < 8; i++)
				{
					if (taxgr[i] != 0)
					{
						res = SellFree("(void)", '0' + i, -taxgr[i]);
						if (res != ZFPE_SUCCESS)
							return res;
					}
				}
			}
			else
			{
				res = CalcIntermediateSum(&pay);
				if (res != ZFPE_SUCCESS)
					return res;
			}
			if ( pay == 0.0 )
			{
				res = PaymentEx( 0.01, 0, FALSE, 1, TRUE );
				if ( res != ZFPE_SUCCESS )
				{
					pay = 0.01;
					res = Payment(pay);
				}
			}
			else
			{
				res = Payment(pay);
			}
			if (res == ZFPE_SUCCESS)
			{
				res = CloseFiscalBon();
			}
		}
	}
	return res;
}
