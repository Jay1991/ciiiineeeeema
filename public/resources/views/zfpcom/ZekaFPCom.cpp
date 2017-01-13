//////////////////////////////////////////////////////////////////////
// Copyright (c) 2005-2008 Tremol Ltd.
// License: Mozilla Public License 1.1
// Contacts: software@tremol.bg
//////////////////////////////////////////////////////////////////////
// ZekaFPCom.cpp : Implementation of CZekaFPCom
#include "stdafx.h"
#include <stdio.h>
#include "Zfpcom.h"
#include "GetCurrentBonInfoRes.h"
#include "ComTools.h"

#include "ZekaFPCom.h"

// This is a slow method to convert but looks like IE6 SP1 is working with
// doubles only and fail to convert double to double without adding too much
// random data after the decimal point => double 532.210 goes to double 532.21008937174
__inline double toDouble(double param, int count)
{
	char buf[50], match[20], *endptr;

	sprintf(match, "%%.%df", count);
	sprintf(buf, match, param);

	return strtod(buf, &endptr);
}

/////////////////////////////////////////////////////////////////////////////
// CZekaFPCom

STDMETHODIMP CZekaFPCom::GetCurrentBonInfo(LPDISPATCH *pVal)
{
	IGetCurrentBonInfoRes *res = NULL;

	HRESULT hr = CoCreateInstance (CLSID_GetCurrentBonInfoRes, NULL, CLSCTX_SERVER,
		IID_IGetCurrentBonInfoRes, (LPVOID*)&res);
	
	if (S_OK == hr) {
		TZfpReceiptInfo info;
		ZeroMemory(&info, sizeof(TZfpReceiptInfo));
		m_errorCode = m_zfp.GetCurrentBonInfoEU(info);
		res->put_flags(info.flags);
		res->put_purchases(info.purchases);
		res->put_change(toDouble(info.change, 2));
		res->put_changeType(info.changeType);
		res->put_taxgrp1(toDouble(info.taxGroups.taxGrp1, 2));
		res->put_taxgrp2(toDouble(info.taxGroups.taxGrp2, 2));
		res->put_taxgrp3(toDouble(info.taxGroups.taxGrp3, 2));
		res->put_taxgrp4(toDouble(info.taxGroups.taxGrp4, 2));
		res->put_taxgrp5(toDouble(info.taxGroups.taxGrp5, 2));
		res->put_taxgrp6(toDouble(info.taxGroups.taxGrp6, 2));
		res->put_taxgrp7(toDouble(info.taxGroups.taxGrp7, 2));
		res->put_taxgrp8(toDouble(info.taxGroups.taxGrp8, 2));
		res->put_novoid(info.flags & ZFPB_NOVOID ? TRUE : FALSE);
		res->put_dds(info.flags & ZFPB_DDS ? TRUE : FALSE);
		res->put_detailed(info.flags & ZFPB_PODRBON ? TRUE : FALSE);
		res->put_paystarted(info.flags & ZFPB_PAYSTART ? TRUE : FALSE);
		res->put_paid(info.flags & ZFPB_PAYEND ? TRUE : FALSE);
		res->put_powerdown(info.flags & ZFPB_POWERDOWN ? TRUE : FALSE);
		res->put_invoice(info.flags & ZFPB_INVOICE ? TRUE : FALSE);
		*pVal = res;
	}
	return hr;
}

STDMETHODIMP CZekaFPCom::Setup(WORD wCom, DWORD baud, WORD retries, DWORD retryWait)
{
	m_zfp.Setup(wCom, baud, retries, retryWait);
	return S_OK;
}

STDMETHODIMP CZekaFPCom::get_errorCode(long *pVal)
{
	*pVal = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::Diagnostic(long *pRes)
{
	m_errorCode = m_zfp.Diagnostic();
	*pRes = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::DisplayClear(long *pRes)
{
	m_errorCode = m_zfp.DisplayClear();
	*pRes = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::DisplayDateTime(long *pRes)
{
	m_errorCode = m_zfp.DisplayDateTime();
	*pRes = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::OpenTill(long *pRes)
{
	m_errorCode = m_zfp.OpenTill();
	*pRes = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::OpenTillEx(BYTE num, long *pRes)
{
	m_errorCode = m_zfp.OpenTillEx(num);
	*pRes = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::OpenSerialPort(long *pRes)
{
	m_errorCode = m_zfp.OpenSerialPort();
	*pRes = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::CloseSerialPort(long *pRes)
{
	m_errorCode = m_zfp.CloseSerialPort();
	*pRes = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::LineFeed(long *pRes)
{
	m_errorCode = m_zfp.LineFeed();
	*pRes = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::GetFactoryNumber(BSTR *pRes)
{
	USES_CONVERSION;
	char szFactory[ZFP_MAXBUFLEN], szFiscal[ZFP_MAXBUFLEN];
	m_errorCode = m_zfp.GetFactFiscNums(szFactory, szFiscal);
	if (ZFPE_SUCCESS == m_errorCode)
		*pRes = A2BSTR(szFactory);
	return S_OK;
}

STDMETHODIMP CZekaFPCom::GetFiscalNumber(BSTR *pRes)
{
	USES_CONVERSION;
	char szFactory[ZFP_MAXBUFLEN], szFiscal[ZFP_MAXBUFLEN];
	m_errorCode = m_zfp.GetFactFiscNums(szFactory, szFiscal);
	if (ZFPE_SUCCESS == m_errorCode)
		*pRes = A2BSTR(szFiscal);
	return S_OK;
}

STDMETHODIMP CZekaFPCom::GetTaxNumber(BSTR *pRes)
{
	USES_CONVERSION;
	char szTaxNum[ZFP_MAXBUFLEN];
	m_errorCode = m_zfp.GetTaxNumber(szTaxNum);
	if (ZFPE_SUCCESS == m_errorCode)
		*pRes = A2BSTR(szTaxNum);
	return S_OK;
}

STDMETHODIMP CZekaFPCom::GetTaxPercents(LPDISPATCH *pRes)
{
	ITaxNumbers *res = NULL;

	HRESULT hr = CoCreateInstance(CLSID_TaxNumbers, NULL, CLSCTX_SERVER,
		IID_ITaxNumbers, (LPVOID*)&res);
	
	if (S_OK == hr) {
		TZfpTaxGroups tg;
		ZeroMemory(&tg, sizeof(TZfpTaxGroups));
		m_errorCode = m_zfp.GetTaxPercentsEU(tg);
		res->put_taxgrp1(toDouble(tg.taxGrp1, 2));
		res->put_taxgrp2(toDouble(tg.taxGrp2, 2));
		res->put_taxgrp3(toDouble(tg.taxGrp3, 2));
		res->put_taxgrp4(toDouble(tg.taxGrp4, 2));
		res->put_taxgrp5(toDouble(tg.taxGrp5, 2));
		res->put_taxgrp6(toDouble(tg.taxGrp6, 2));
		res->put_taxgrp7(toDouble(tg.taxGrp7, 2));
		res->put_taxgrp8(toDouble(tg.taxGrp8, 2));
		*pRes = res;
	}

	return hr;
}

STDMETHODIMP CZekaFPCom::GetDecimalPoint(long *pPoint)
{
	int point;
	m_errorCode = m_zfp.GetDecimalPoint(&point);
	if (ZFPE_SUCCESS == m_errorCode)
		*pPoint = point;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::GetPayTypes(LPDISPATCH *pRes)
{
	USES_CONVERSION;
	IPayTypes *res = NULL;

	HRESULT hr = CoCreateInstance(CLSID_PayTypes, NULL, CLSCTX_SERVER,
		IID_IPayTypes, (LPVOID*)&res);
	
	if (S_OK == hr) {
		TZfpPayTypes pt;
		m_errorCode = m_zfp.GetPayTypesEU(pt);
		res->put_paytype0(A2BSTR(pt.type0));
		res->put_paytype1(A2BSTR(pt.type1));
		res->put_paytype2(A2BSTR(pt.type2));
		res->put_paytype3(A2BSTR(pt.type3));
		res->put_paytype4(A2BSTR(pt.type4));
		res->put_exchRate(toDouble(pt.exchRate, 5));
		*pRes = res;
	}

	return hr;
}

STDMETHODIMP CZekaFPCom::GetParameters(LPDISPATCH *pRes)
{
	IZFPParameters *res = NULL;

	HRESULT hr = CoCreateInstance(CLSID_ZFPParameters, NULL, CLSCTX_SERVER,
		IID_IZFPParameters, (LPVOID*)&res);
	
	if (S_OK == hr) {
		int fpnum = 0, logo = 0, till = 0, autocut = 0, transparent = 0;
		TZfpParams params;
		ZeroMemory(&params, sizeof(TZfpParams));
		m_errorCode = m_zfp.GetParametersEU(params);
		res->put_fpnum(params.fpnum);
		res->put_logo(params.logo);
		res->put_till(params.till);
		res->put_autocut(params.autocut);
		res->put_transparent(params.transparent);
		res->put_shortEJ(params.shortEJ);
		res->put_currency(params.currency);
		*pRes = res;
	}

	return hr;
}

STDMETHODIMP CZekaFPCom::PrintLogo(long *pRes)
{
	m_errorCode = m_zfp.PrintLogo();
	*pRes = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::PrintLogoEx(BYTE logo, long *pRes)
{
	m_errorCode = m_zfp.PrintLogoEx(logo);
	*pRes = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::CloseBon(long *pRes)
{
	m_errorCode = m_zfp.CloseBon();
	*pRes = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::CloseBonInCash(long *pRes)
{
	m_errorCode = m_zfp.CloseBonInCash();
	*pRes = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::TerminateBon(BOOL finish, long *pRes)
{
	m_errorCode = m_zfp.TerminateBon(finish);
	*pRes = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::GetClicheLine(BYTE num, BSTR *pRes)
{
	USES_CONVERSION;
	char line[ZFP_MAXBUFLEN];
	m_errorCode = m_zfp.GetClicheLine(num, line);
	if (ZFPE_SUCCESS == m_errorCode)
		*pRes = A2BSTR(line);
	return S_OK;
}

STDMETHODIMP CZekaFPCom::GetOperatorUserPass(BYTE oper, LPDISPATCH *pRes)
{
	USES_CONVERSION;
	IOperatorInfo *res = NULL;

	HRESULT hr = CoCreateInstance(CLSID_OperatorInfo, NULL, CLSCTX_SERVER,
		IID_IOperatorInfo, (LPVOID*)&res);
	
	if (S_OK == hr)
	{
		char name[ZFP_MAXBUFLEN], passwd[ZFP_MAXBUFLEN];

		name[0] = 0;
		passwd[0] = 0;
		m_errorCode = m_zfp.GetOperatorUserPass(oper, name, passwd);
		res->put_name(A2BSTR(name));
		res->put_passwd(A2BSTR(passwd));
		*pRes = res;
	}

	return hr;
}

STDMETHODIMP CZekaFPCom::OpenBon(BYTE oper, BSTR passwd, long *pRes)
{
	USES_CONVERSION;
	m_errorCode = m_zfp.OpenBon(oper, OLE2A(passwd));
	*pRes = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::SetLineWidth(int num_chars, long *pRes)
{
	m_errorCode = m_zfp.SetLineWidth(num_chars);
	*pRes = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::GetLineWidth(long *pChars)
{
	*pChars = m_zfp.GetLineWidth();
	return S_OK;
}

STDMETHODIMP CZekaFPCom::SetPrintMode(DWORD mode, long *pRes)
{
	m_errorCode = m_zfp.SetPrintMode(mode);
	*pRes = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::FormatBarcode(BSTR fmt, long *pRes)
{
	USES_CONVERSION;
	m_errorCode = m_zfp.FormatBarcode(OLE2A(fmt));
	*pRes = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::EnableBarcode(BYTE state, long *pRes)
{
	m_errorCode = m_zfp.EnableBarcode(state);
	*pRes = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::PrintBarcode(BSTR barcode, BYTE type, long *pRes)
{
	USES_CONVERSION;
	m_errorCode = m_zfp.PrintBarcode(OLE2A(barcode), type);
	*pRes = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::OpenBonWithEJ(BYTE oper, BSTR passwd, BOOL hasEJ, long *pRes)
{
	USES_CONVERSION;
	m_errorCode = m_zfp.OpenBonWithEJ(oper, OLE2A(passwd), hasEJ);
	*pRes = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::OpenFiscalBon(BYTE oper, BSTR passwd, BYTE defPass, BYTE dds, long *pRes)
{
	USES_CONVERSION;
	m_errorCode = m_zfp.OpenFiscalBon(oper, OLE2A(passwd), defPass, dds);
	*pRes = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::SellFree(BSTR name, BYTE taxgrp, double price, double quantity, double discount, long *pRes)
{
	USES_CONVERSION;
	m_errorCode = m_zfp.SellFree(OLE2A(name), taxgrp, price, quantity, discount);
	*pRes = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::SellFreeEx(BSTR name, BYTE taxgrp, double price, double quantity, double discount, BYTE flag, long *pRes)
{
	USES_CONVERSION;
	m_errorCode = m_zfp.SellFreeEx(OLE2A(name), taxgrp, price, quantity, discount, flag);
	*pRes = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::SellFreeDiv(BSTR name, BYTE taxgrp, double price, double quantity, double discount, BYTE flag, DWORD divider, long *pRes)
{
	USES_CONVERSION;
	m_errorCode = m_zfp.SellFreeEx(OLE2A(name), taxgrp, price, quantity, discount, flag | 4, divider);
	*pRes = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::Storno(BSTR name, BYTE taxgrp, double price, double quantity, long *pRes)
{
	USES_CONVERSION;
	m_errorCode = m_zfp.Storno(OLE2A(name), taxgrp, price, quantity);
	*pRes = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::SellDB(BOOL isVoid, WORD number, double quantity, double discount, long *pRes)
{
	m_errorCode = m_zfp.SellDB(isVoid, number, quantity, discount);
	*pRes = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::SellDBEx(BOOL isVoid, DWORD number, double quantity, double discount, BYTE flag, long *pRes)
{
	m_errorCode = m_zfp.SellDBEx(isVoid, number, quantity, discount, flag);
	*pRes = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::SellDBEx2(BOOL isVoid, DWORD number, double price, double quantity, double discount, BYTE flag, long *pRes)
{
	m_errorCode = m_zfp.SellDBEx2(isVoid, number, price, quantity, discount, flag);
	*pRes = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::Payment(double sum, BYTE type, BOOL noRest, long *pRes)
{
	m_errorCode = m_zfp.Payment(sum, type, noRest);
	*pRes = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::CloseFiscalBon(long *pRes)
{
	m_errorCode = m_zfp.CloseFiscalBon();
	*pRes = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::PrintDuplicate(long *pRes)
{
	m_errorCode = m_zfp.PrintDuplicate();
	*pRes = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::OfficialSums(BYTE num, BSTR passwd, BYTE type, double sum, long *pRes)
{
	USES_CONVERSION;
	m_errorCode = m_zfp.OfficialSums(num, OLE2A(passwd), type, sum);
	*pRes = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::OfficialSumsEx(BYTE num, BSTR passwd, BYTE type, double sum, BSTR note, long *pRes)
{
	USES_CONVERSION;
	m_errorCode = m_zfp.OfficialSums(num, OLE2A(passwd), type, sum, OLE2A(note));
	*pRes = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::GetArticleInfo(WORD number, LPDISPATCH *pRes)
{
	USES_CONVERSION;
	IArticleInfo *res = NULL;

	HRESULT hr = CoCreateInstance(CLSID_ArticleInfo, NULL, CLSCTX_SERVER,
		IID_IArticleInfo, (LPVOID*)&res);
	
	if (S_OK == hr)
	{
		double price = 0.0, turnover = 0.0, sells = 0.0;
		char name[ZFP_MAXBUFLEN] = "", taxgroup = 'À';
		WORD counter = 0, dep = 0;
		int dd = 0, mm = 0, yy = 0, hh = 0, mmm = 0;
		m_errorCode = m_zfp.GetArticleInfo(number, name, &price, &taxgroup, &turnover, &sells, &counter, &dd, &mm, &yy, &hh, &mmm, &dep);
		res->put_name(A2BSTR(name));
		res->put_price(toDouble(price, 2));
		res->put_taxgroup((short)((BYTE)taxgroup));
		res->put_turnover(toDouble(turnover, 3));
		res->put_sells(toDouble(sells, 3));
		res->put_counter(counter);
		res->put_department(dep);
		res->put_quantity(0.0);
		DATE date;
		MyOleDateFromTm(yy, mm, dd, hh, mmm, 0, date);
		res->put_reportdate(date);
		*pRes = res;
	}

	return hr;
}

STDMETHODIMP CZekaFPCom::GetArticleInfoEx(DWORD number, LPDISPATCH *pRes)
{
	USES_CONVERSION;
	IArticleInfo *res = NULL;

	HRESULT hr = CoCreateInstance(CLSID_ArticleInfo, NULL, CLSCTX_SERVER,
		IID_IArticleInfo, (LPVOID*)&res);
	
	if (S_OK == hr)
	{
		double price = 0.0, turnover = 0.0, sells = 0.0;
		char name[ZFP_MAXBUFLEN] = "", taxgroup = 'À', unit[10];
		WORD counter = 0, dep = 0;
		int dd = 0, mm = 0, yy = 0, hh = 0, mmm = 0;
		m_errorCode = m_zfp.GetArticleInfoEx(number, name, &price, &taxgroup, &turnover, &sells, &counter, &dd, &mm, &yy, &hh, &mmm, &dep, unit);
		res->put_name(A2BSTR(name));
		res->put_price(toDouble(price, 2));
		res->put_taxgroup((short)((BYTE)taxgroup));
		res->put_turnover(toDouble(turnover, 3));
		res->put_sells(toDouble(sells, 3));
		res->put_counter(counter);
		res->put_department(dep);
		res->put_quantity(0.0);
		DATE date;
		MyOleDateFromTm(yy, mm, dd, hh, mmm, 0, date);
		res->put_reportdate(date);
		*pRes = res;
	}

	return hr;
}

STDMETHODIMP CZekaFPCom::GetArticleUnit(DWORD number, BSTR *pRes)
{
	USES_CONVERSION;

	double price = 0.0, turnover = 0.0, sells = 0.0;
	char name[ZFP_MAXBUFLEN] = "", taxgroup = 'À', unit[10];
	WORD counter = 0, dep = 0;
	int dd = 0, mm = 0, yy = 0, hh = 0, mmm = 0;
	m_errorCode = m_zfp.GetArticleInfoEx(number, name, &price, &taxgroup, &turnover, &sells, &counter, &dd, &mm, &yy, &hh, &mmm, &dep, unit);
	*pRes = A2BSTR(unit);

	return S_OK;
}

STDMETHODIMP CZekaFPCom::GetDailySums(LPDISPATCH *pRes)
{
	ITaxNumbers *res = NULL;

	HRESULT hr = CoCreateInstance(CLSID_TaxNumbers, NULL, CLSCTX_SERVER,
		IID_ITaxNumbers, (LPVOID*)&res);
	
	if (S_OK == hr) {
		TZfpTaxGroups tg;
		ZeroMemory(&tg, sizeof(TZfpTaxGroups));
		m_errorCode = m_zfp.GetDailySumsEU(tg);
		res->put_taxgrp1(toDouble(tg.taxGrp1, 2));
		res->put_taxgrp2(toDouble(tg.taxGrp2, 2));
		res->put_taxgrp3(toDouble(tg.taxGrp3, 2));
		res->put_taxgrp4(toDouble(tg.taxGrp4, 2));
		res->put_taxgrp5(toDouble(tg.taxGrp5, 2));
		res->put_taxgrp6(toDouble(tg.taxGrp6, 2));
		res->put_taxgrp7(toDouble(tg.taxGrp7, 2));
		res->put_taxgrp8(toDouble(tg.taxGrp8, 2));
		*pRes = res;
	}

	return hr;
}


STDMETHODIMP CZekaFPCom::GetDailyInfo(LPDISPATCH *pRes)
{
	IDailySums *res = NULL;

	HRESULT hr = CoCreateInstance(CLSID_DailySums, NULL, CLSCTX_SERVER,
		IID_IDailySums, (LPVOID*)&res);
	
	if (S_OK == hr) {
		int clients = 0, discounts = 0, adding = 0, voids = 0;
		double sumdiscount = 0.0, sumadding = 0.0, sumvoids = 0.0;
		m_errorCode = m_zfp.GetDailyInfo(&clients, &discounts, &sumdiscount, &adding, &sumadding, &voids, &sumvoids);
		res->put_clients(clients);
		res->put_discounts(discounts);
		res->put_sumdiscount(toDouble(sumdiscount, 2));
		res->put_adding(adding);
		res->put_sumadding(toDouble(sumadding, 2));
		res->put_voids(voids);
		res->put_sumvoids(toDouble(sumvoids, 2));
		*pRes = res;
	}

	return hr;
}

STDMETHODIMP CZekaFPCom::GetBonNumber(long *pNumber)
{
	int num;
	m_errorCode = m_zfp.GetBonNumber(&num);
	if (ZFPE_SUCCESS == m_errorCode)
		*pNumber = num;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::SetPayType(BYTE type, BSTR line, long *pRes)
{
	USES_CONVERSION;
	m_errorCode = m_zfp.SetPayType(type, OLE2A(line));
	*pRes = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::SetParameters(WORD fpnum, BOOL logo, BOOL till, BOOL autocut, BOOL transparent, long *pRes)
{
	m_errorCode = m_zfp.SetParameters(fpnum, logo, till, autocut, transparent);
	*pRes = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::SetClicheLine(BYTE num, BSTR text, long *pRes)
{
	USES_CONVERSION;
	m_errorCode = m_zfp.SetClicheLine(num, OLE2A(text));
	*pRes = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::SetOperatorUserPass(BYTE oper, BSTR name, BSTR passwd, long *pRes)
{
	USES_CONVERSION;
	m_errorCode = m_zfp.SetOperatorUserPass(oper, OLE2A(name), OLE2A(passwd));
	*pRes = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::SetArticleInfo(WORD num, BSTR name, double price, BYTE taxgrp, long *pRes)
{
	USES_CONVERSION;
	m_errorCode = m_zfp.SetArticleInfo(num, OLE2A(name), price, taxgrp);
	*pRes = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::SetLogoFile(BSTR filename, long *pRes)
{
	USES_CONVERSION;
	m_errorCode = m_zfp.SetLogoFile(OLE2A(filename));
	*pRes = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::SetLogoFileEx(BYTE logo_id, BSTR filename, long *pRes)
{
	USES_CONVERSION;
	m_errorCode = m_zfp.SetLogoFileEx(logo_id, OLE2A(filename));
	*pRes = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::SetLocalDateTime(long *pRes)
{
	m_errorCode = m_zfp.SetLocalDateTime();
	*pRes = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::GetOperatorInfo(BYTE oper, LPDISPATCH *pRes)
{
	IDailySums *res = NULL;

	HRESULT hr = CoCreateInstance(CLSID_DailySums, NULL, CLSCTX_SERVER,
		IID_IDailySums, (LPVOID*)&res);
	
	if (S_OK == hr) {
		int clients = 0, discounts = 0, adding = 0, voids = 0;
		double sumdiscount = 0.0, sumadding = 0.0, sumvoids = 0.0;
		m_errorCode = m_zfp.GetOperatorInfo(oper, &clients, &discounts, &sumdiscount, &adding, &sumadding, &voids, &sumvoids);
		res->put_clients(clients);
		res->put_discounts(discounts);
		res->put_sumdiscount(toDouble(sumdiscount, 2));
		res->put_adding(adding);
		res->put_sumadding(toDouble(sumadding, 2));
		res->put_voids(voids);
		res->put_sumvoids(toDouble(sumvoids, 2));
		*pRes = res;
	}

	return hr;
}

STDMETHODIMP CZekaFPCom::GetOperatorReceives(BYTE oper, LPDISPATCH *pRes)
{
	IPayTypes *res = NULL;

	HRESULT hr = CoCreateInstance(CLSID_PayTypes, NULL, CLSCTX_SERVER,
		IID_IPayTypes, (LPVOID*)&res);
	
	if (S_OK == hr) {
		double pt1 = 0.0, pt2 = 0.0, pt3 = 0.0, pt4 = 0.0, pt0 = 0.0; 
		m_errorCode = m_zfp.GetOperatorReceives(oper, &pt0, &pt1, &pt2, &pt3, &pt4);
		res->put_paytype0sum(toDouble(pt0, 2));
		res->put_paytype1sum(toDouble(pt1, 2));
		res->put_paytype2sum(toDouble(pt2, 2));
		res->put_paytype3sum(toDouble(pt3, 2));
		res->put_paytype4sum(toDouble(pt4, 2));
		*pRes = res;
	}

	return hr;
}

STDMETHODIMP CZekaFPCom::GetDateTime(DATE *pVal)
{
	int dd = 0, mm = 0, yy = 0, hh = 0, mmm = 0;
	m_errorCode = m_zfp.GetDateTime(&dd, &mm, &yy, &hh, &mmm);
	MyOleDateFromTm(yy, mm, dd, hh, mmm, 0, *pVal);
	return S_OK;
}

STDMETHODIMP CZekaFPCom::Display(BSTR line, long *pRes)
{
	USES_CONVERSION;
	m_errorCode = m_zfp.Display(OLE2A(line));
	*pRes = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::DisplayLine1(BSTR line, long *pRes)
{
	USES_CONVERSION;
	m_errorCode = m_zfp.DisplayLine1(OLE2A(line));
	*pRes = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::DisplayLine2(BSTR line, long *pRes)
{
	USES_CONVERSION;
	m_errorCode = m_zfp.DisplayLine2(OLE2A(line));
	*pRes = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::GetVersion(BSTR *pRes)
{
	USES_CONVERSION;
	char ver[ZFP_MAXBUFLEN];
	m_errorCode = m_zfp.GetVersion(ver);
	if (ZFPE_SUCCESS == m_errorCode)
		*pRes = A2BSTR(ver);
	return S_OK;
}

STDMETHODIMP CZekaFPCom::GetVersionGS(BSTR *pRes)
{
	USES_CONVERSION;
	char ver[ZFP_MAXBUFLEN];
	m_errorCode = m_zfp.GetVersionGS(ver);
	if (ZFPE_SUCCESS == m_errorCode)
		*pRes = A2BSTR(ver);
	return S_OK;
}

STDMETHODIMP CZekaFPCom::EnableCommGS(BYTE enable, WORD device_no, long *pRes)
{
	m_errorCode = m_zfp.EnableCommGS(enable, device_no);
	*pRes = m_errorCode;
	return S_OK;

}

STDMETHODIMP CZekaFPCom::SetSpeedGS(BYTE speed, long *pRes)
{
	m_errorCode = m_zfp.SetSpeedGS(speed);
	*pRes = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::LoadScaleProtocolGS(BSTR protocol, long *pRes)
{
	USES_CONVERSION;
	m_errorCode = m_zfp.LoadScaleProtocolGS(OLE2A(protocol));
	*pRes = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::GetInputBuffer(BSTR *pRes)
{
	USES_CONVERSION;
	char buf[ZFP_MAXBUFLEN];
	int len = m_zfp.GetInputBuffer((BYTE *)buf);
	buf[len] = 0;
	m_errorCode = ZFPE_SUCCESS;
	*pRes = A2BSTR(buf);
	return S_OK;
}

STDMETHODIMP CZekaFPCom::GetResponseBuffer(BSTR *pRes)
{
	USES_CONVERSION;
	char buf[ZFP_MAXBUFLEN];
	int len = m_zfp.GetResponseBuffer((BYTE *)buf);
	buf[len] = 0;
	m_errorCode = ZFPE_SUCCESS;
	*pRes = A2BSTR(buf);
	return S_OK;
}

STDMETHODIMP CZekaFPCom::GetInputHexFormated(BSTR *pRes)
{
	USES_CONVERSION;
	char buf[ZFP_MAXHEXBUFLEN];
	m_zfp.GetInputHexFormated(buf);
	m_errorCode = ZFPE_SUCCESS;
	*pRes = A2BSTR(buf);
	return S_OK;
}

STDMETHODIMP CZekaFPCom::GetResponseHexFormated(BSTR *pRes)
{
	USES_CONVERSION;
	char buf[ZFP_MAXHEXBUFLEN];
	m_zfp.GetResponseHexFormated(buf);
	m_errorCode = ZFPE_SUCCESS;
	*pRes = A2BSTR(buf);
	return S_OK;
}

STDMETHODIMP CZekaFPCom::GetErrorString(int error, int lang, BSTR *pRes)
{
	USES_CONVERSION;
	char buf[ZFP_MAXERRORBUFLEN];
	m_zfp.GetErrorString(error, lang, buf);
	m_errorCode = ZFPE_SUCCESS;
	*pRes = A2BSTR(buf);
	return S_OK;
}

STDMETHODIMP CZekaFPCom::GetOperatorIncomes(BYTE oper, LPDISPATCH *pRes)
{
	IPayTypes *res = NULL;

	HRESULT hr = CoCreateInstance(CLSID_PayTypes, NULL, CLSCTX_SERVER,
		IID_IPayTypes, (LPVOID*)&res);
	
	if (S_OK == hr) {
		DWORD operations;
		double pt1 = 0.0, pt2 = 0.0, pt3 = 0.0, pt4 = 0.0, pt0 = 0.0; 
		m_errorCode = m_zfp.GetOperatorIncomes(oper, &pt0, &pt1, &pt2, &pt3, &pt4, &operations);
		res->put_paytype0sum(toDouble(pt0, 2));
		res->put_paytype1sum(toDouble(pt1, 2));
		res->put_paytype2sum(toDouble(pt2, 2));
		res->put_paytype3sum(toDouble(pt3, 2));
		res->put_paytype4sum(toDouble(pt4, 2));
		res->put_operations(operations);
		*pRes = res;
	}

	return hr;
}

STDMETHODIMP CZekaFPCom::GetOperatorExpenses(BYTE oper, LPDISPATCH *pRes)
{
	IPayTypes *res = NULL;

	HRESULT hr = CoCreateInstance(CLSID_PayTypes, NULL, CLSCTX_SERVER,
		IID_IPayTypes, (LPVOID*)&res);
	
	if (S_OK == hr) {
		DWORD operations;
		double pt1 = 0.0, pt2 = 0.0, pt3 = 0.0, pt4 = 0.0, pt0 = 0.0; 
		m_errorCode = m_zfp.GetOperatorExpenses(oper, &pt0, &pt1, &pt2, &pt3, &pt4, &operations);
		res->put_paytype0sum(toDouble(pt0, 2));
		res->put_paytype1sum(toDouble(pt1, 2));
		res->put_paytype2sum(toDouble(pt2, 2));
		res->put_paytype3sum(toDouble(pt3, 2));
		res->put_paytype4sum(toDouble(pt4, 2));
		res->put_operations(operations);
		*pRes = res;
	}

	return hr;
}

STDMETHODIMP CZekaFPCom::GetDailyPayments(LPDISPATCH *pRes)
{
	IPayTypes *res = NULL;

	HRESULT hr = CoCreateInstance(CLSID_PayTypes, NULL, CLSCTX_SERVER,
		IID_IPayTypes, (LPVOID*)&res);
	
	if (S_OK == hr) {
		double pt1 = 0.0, pt2 = 0.0, pt3 = 0.0, pt4 = 0.0, pt0 = 0.0; 
		m_errorCode = m_zfp.GetDailyPayments(&pt0, &pt1, &pt2, &pt3, &pt4);
		res->put_paytype0sum(toDouble(pt0, 2));
		res->put_paytype1sum(toDouble(pt1, 2));
		res->put_paytype2sum(toDouble(pt2, 2));
		res->put_paytype3sum(toDouble(pt3, 2));
		res->put_paytype4sum(toDouble(pt4, 2));
		*pRes = res;
	}

	return hr;
}

STDMETHODIMP CZekaFPCom::GetDailyIncomes(LPDISPATCH *pRes)
{
	IPayTypes *res = NULL;

	HRESULT hr = CoCreateInstance(CLSID_PayTypes, NULL, CLSCTX_SERVER,
		IID_IPayTypes, (LPVOID*)&res);
	
	if (S_OK == hr) {
		double pt1 = 0.0, pt2 = 0.0, pt3 = 0.0, pt4 = 0.0, pt0 = 0.0; 
		m_errorCode = m_zfp.GetDailyIncomes(&pt0, &pt1, &pt2, &pt3, &pt4);
		res->put_paytype0sum(toDouble(pt0, 2));
		res->put_paytype1sum(toDouble(pt1, 2));
		res->put_paytype2sum(toDouble(pt2, 2));
		res->put_paytype3sum(toDouble(pt3, 2));
		res->put_paytype4sum(toDouble(pt4, 2));
		*pRes = res;
	}

	return hr;
}

STDMETHODIMP CZekaFPCom::GetDailyOfficialIncomes(LPDISPATCH *pRes)
{
	IPayTypes *res = NULL;

	HRESULT hr = CoCreateInstance(CLSID_PayTypes, NULL, CLSCTX_SERVER,
		IID_IPayTypes, (LPVOID*)&res);
	
	if (S_OK == hr) {
		DWORD operations;
		double pt1 = 0.0, pt2 = 0.0, pt3 = 0.0, pt4 = 0.0, pt0 = 0.0; 
		m_errorCode = m_zfp.GetDailyOfficialIncomes(&pt0, &pt1, &pt2, &pt3, &pt4, &operations);
		res->put_paytype0sum(toDouble(pt0, 2));
		res->put_paytype1sum(toDouble(pt1, 2));
		res->put_paytype2sum(toDouble(pt2, 2));
		res->put_paytype3sum(toDouble(pt3, 2));
		res->put_paytype4sum(toDouble(pt4, 2));
		res->put_operations(operations);
		*pRes = res;
	}

	return hr;
}

STDMETHODIMP CZekaFPCom::GetDailyOfficialExpenses(LPDISPATCH *pRes)
{
	IPayTypes *res = NULL;

	HRESULT hr = CoCreateInstance(CLSID_PayTypes, NULL, CLSCTX_SERVER,
		IID_IPayTypes, (LPVOID*)&res);
	
	if (S_OK == hr) {
		DWORD operations;
		double pt1 = 0.0, pt2 = 0.0, pt3 = 0.0, pt4 = 0.0, pt0 = 0.0; 
		m_errorCode = m_zfp.GetDailyOfficialExpenses(&pt0, &pt1, &pt2, &pt3, &pt4, &operations);
		res->put_paytype0sum(toDouble(pt0, 2));
		res->put_paytype1sum(toDouble(pt1, 2));
		res->put_paytype2sum(toDouble(pt2, 2));
		res->put_paytype3sum(toDouble(pt3, 2));
		res->put_paytype4sum(toDouble(pt4, 2));
		res->put_operations(operations);
		*pRes = res;
	}

	return hr;
}

STDMETHODIMP CZekaFPCom::CalcIntermediateSum(BOOL doprint, BOOL dodisplay, BOOL dopercents, double discount, double *pRes)
{
	DWORD flags = doprint ? ZFP_ISPRINT : 0;
	flags |= dodisplay ? ZFP_ISSHOW : 0;
	flags |= dopercents ? ZFP_ISPERCENT : 0;
	double res = 0.0;
	m_errorCode = m_zfp.CalcIntermediateSum(&res, flags, discount);
	*pRes = toDouble(res, 2);
	return S_OK;
}

STDMETHODIMP CZekaFPCom::GetLastFiscalReportData(LPDISPATCH *pRes)
{
	IFiscalReportData *res = NULL;

	HRESULT hr = CoCreateInstance(CLSID_FiscalReportData, NULL, CLSCTX_SERVER,
		IID_IFiscalReportData, (LPVOID*)&res);
	
	if (S_OK == hr) {
		int dd = 0, mm = 0, yy = 0, lastReport = 0, lastZeroRam = 0;
		m_errorCode = m_zfp.GetLastFiscalReportData(&dd, &mm, &yy, &lastReport, &lastZeroRam);
		res->put_lastreport(lastReport);
		res->put_lastzeroram(lastZeroRam);
		DATE date;
		MyOleDateFromTm(yy, mm, dd, 0, 0, 0, date);
		res->put_reportdate(date);
		*pRes = res;
	}

	return hr;
}

STDMETHODIMP CZekaFPCom::ReportSpecialFiscal(long *pRes)
{
	m_errorCode = m_zfp.ReportSpecialFiscal();
	*pRes = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::ReportFiscalByBlock(BOOL detailed, WORD startNumber, WORD endNumber, long *pRes)
{
	m_errorCode = m_zfp.ReportFiscalByBlock(detailed, startNumber, endNumber);
	*pRes = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::ReportDaily(BOOL zero, BOOL extended, long *pRes)
{
	m_errorCode = m_zfp.ReportDaily(zero, extended);
	*pRes = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::ReportArticles(BOOL zero, long *pRes)
{
	m_errorCode = m_zfp.ReportArticles(zero);
	*pRes = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::ReportDepartments(BOOL zero, long *pRes)
{
	m_errorCode = m_zfp.ReportDepartments(zero);
	*pRes = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::SetDateTime(DATE datetime, long *pRes)
{
	UDATE zt;
	MyTmFromOleDate(datetime, zt);
	m_errorCode = m_zfp.SetDateTime(zt.st.wDay, zt.st.wMonth, zt.st.wYear - 2000, zt.st.wHour, zt.st.wMinute, zt.st.wSecond);
	*pRes = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::ReportFiscalByDate(BOOL detailed, DATE start, DATE end, long *pRes)
{
	UDATE zs, ze;
	MyTmFromOleDate(start, zs);
	MyTmFromOleDate(end, ze);
	m_errorCode = m_zfp.ReportFiscalByDate(detailed, zs.st.wDay, zs.st.wMonth, zs.st.wYear - 2000, 
		ze.st.wDay, ze.st.wMonth, ze.st.wYear - 2000);
	*pRes = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::ReportOperator(BOOL zero, BYTE oper, long *pRes)
{
	m_errorCode = m_zfp.ReportOperator(zero, oper);
	*pRes = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::PrintText(BSTR text, int align, long *pRes)
{
	USES_CONVERSION;
	m_errorCode = m_zfp.PrintText(OLE2A(text), align);
	*pRes = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::PrintTextKP(BSTR text, long *pRes)
{
	USES_CONVERSION;
	m_errorCode = m_zfp.PrintTextKP(OLE2A(text));
	*pRes = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::PrintTextKP2(BSTR format, int flags, BSTR text_param, double numeric_param, long *pRes)
{
	USES_CONVERSION;
	m_errorCode = m_zfp.PrintTextKP(OLE2A(format), flags, OLE2A(text_param), numeric_param);
	*pRes = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::GetDailyReport(LPDISPATCH *pRes)
{
	IDailyReport *res = NULL;

	HRESULT hr = CoCreateInstance(CLSID_DailyReport, NULL, CLSCTX_SERVER,
		IID_IDailyReport, (LPVOID*)&res);
	
	if (S_OK == hr) {
		DWORD counter = 0, lastreport = 0, ecl = 0;
		int dd = 0, mm = 0, yy = 0, hh = 0, mmm = 0;
		m_errorCode = m_zfp.GetDailyReport(&counter, &lastreport, &ecl, &dd, &mm, &yy, &hh, &mmm);
		res->put_counter(counter);
		res->put_lastreport(lastreport);
		res->put_ecl(ecl);
		DATE date;
		MyOleDateFromTm(yy, mm, dd, hh, mmm, 0, date);
		res->put_datetime(date);
		*pRes = res;
	}

	return hr;
}

STDMETHODIMP CZekaFPCom::GetOperatorCounter(BYTE oper, LPDISPATCH *pRes)
{
	IDailyReport *res = NULL;

	HRESULT hr = CoCreateInstance(CLSID_DailyReport, NULL, CLSCTX_SERVER,
		IID_IDailyReport, (LPVOID*)&res);
	
	if (S_OK == hr) {
		DWORD counter = 0;
		int dd = 0, mm = 0, yy = 0, hh = 0, mmm = 0;
		m_errorCode = m_zfp.GetOperatorCounter(oper, &counter, &dd, &mm, &yy, &hh, &mmm);
		res->put_counter(counter);
		DATE date;
		MyOleDateFromTm(yy, mm, dd, hh, mmm, 0, date);
		res->put_datetime(date);
		*pRes = res;
	}

	return hr;
}

STDMETHODIMP CZekaFPCom::SetExternalDisplayFile(BSTR password, BSTR filename, long *pRes)
{
	USES_CONVERSION;
	m_errorCode = m_zfp.SetExternalDisplayFile(OLE2A(password), OLE2A(filename));
	*pRes = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::ReadFiscalMemory(BSTR filename, long *pRes)
{
	USES_CONVERSION;
	m_errorCode = m_zfp.ReadFiscalMemory(OLE2A(filename));
	*pRes = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::ReadFiscalMemory2(BSTR filename, long *pRes)
{
	USES_CONVERSION;
	m_errorCode = m_zfp.ReadFiscalMemory2(OLE2A(filename));
	*pRes = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::FindFirstFPCOM(DWORD *pRes)
{
	*pRes = CZekaFP::FindFirstFPCOM();
	return S_OK;
}

STDMETHODIMP CZekaFPCom::FindFirstFPCOMEx(DWORD *pRes)
{
	*pRes = CZekaFP::FindFirstFPCOMEx();
	return S_OK;
}

STDMETHODIMP CZekaFPCom::PaperCut(long *pRes)
{
	m_errorCode = m_zfp.PaperCut();
	*pRes = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::GetStatus(LPDISPATCH *pRes)
{
	IZFPStatus *res = NULL;

	HRESULT hr = CoCreateInstance(CLSID_ZFPStatus, NULL, CLSCTX_SERVER,
		IID_IZFPStatus, (LPVOID*)&res);
	
	if (S_OK == hr) {
		BYTE st[20];
		st[0] = st[1] = st[2] = st[3] = st[4] = 0;
		m_errorCode = m_zfp.GetStatus(st);
		res->put_ST0(st[0]);
		res->put_ST1(st[1]);
		res->put_ST2(st[2]);
		res->put_ST3(st[3]);
		res->put_ST4(st[4]);
		*pRes = res;
	}

	return hr;
}

STDMETHODIMP CZekaFPCom::GetFreeFiscalSpace(long *pRecords)
{
	int records;
	m_errorCode = m_zfp.GetFreeFiscalSpace(&records);
	if (ZFPE_SUCCESS == m_errorCode)
		*pRecords = records;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::GetStartDateFM(BSTR *pRes)
{
	USES_CONVERSION;
	char szDate[ZFP_MAXBUFLEN];
	*szDate = 0;
	m_errorCode = m_zfp.GetStartDateFM(szDate);
//	if (ZFPE_SUCCESS == m_errorCode)
		*pRes = A2BSTR(szDate);
	return S_OK;
}

STDMETHODIMP CZekaFPCom::get_zfpType(long *pVal)
{
	m_errorCode = ZFPE_SUCCESS;
	*pVal = (long)m_zfp.GetZFPType();
	return S_OK;
}

STDMETHODIMP CZekaFPCom::put_zfpType(long newVal)
{
	m_errorCode = m_zfp.SetZFPType((int)newVal);
	return S_OK;
}

STDMETHODIMP CZekaFPCom::OpenInvoice(BYTE oper, BSTR passwd, BSTR client, BSTR receiver, 
									 BSTR taxnum, BSTR bulstat, BSTR address, long *pRes)
{
	USES_CONVERSION;
	m_errorCode = m_zfp.OpenInvoice(oper, OLE2A(passwd), OLE2A(client), OLE2A(receiver), 
		OLE2A(taxnum), OLE2A(bulstat), OLE2A(address));
	*pRes = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::BusyWait(DWORD timeout, long *pRes)
{
	m_errorCode = m_zfp.BusyWait(timeout);
	*pRes = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::SetAutoBusyWait(DWORD timeout)
{
	m_errorCode = ZFPE_SUCCESS;
	m_zfp.SetAutoBusyWait(timeout);
	return S_OK;
}

STDMETHODIMP CZekaFPCom::SetSerialNumber(BSTR password, BSTR manifactureNum, BSTR fiscalNum, BSTR controlSum, long *pRes)
{
	USES_CONVERSION;
	m_errorCode = m_zfp.SetSerialNumber(OLE2A(password), OLE2A(manifactureNum), OLE2A(fiscalNum), OLE2A(controlSum));
	*pRes = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::SetTaxNumber(BSTR password, BSTR taxNum, BSTR fiscalNum, long *pRes)
{
	USES_CONVERSION;
	m_errorCode = m_zfp.SetTaxNumber(OLE2A(password), OLE2A(taxNum), OLE2A(fiscalNum));
	*pRes = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::MakeFiscal(BSTR password, long *pRes)
{
	USES_CONVERSION;
	m_errorCode = m_zfp.MakeFiscal(OLE2A(password));
	*pRes = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::SetTaxPercents(BSTR password, double tgr1, double tgr2, double tgr3, double tgr4, long *pRes)
{
	USES_CONVERSION;
	m_errorCode = m_zfp.SetTaxPercents(OLE2A(password), tgr1, tgr2, tgr3, tgr4);
	*pRes = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::SetDecimalPoint(BSTR password, int point, long *pRes)
{
	USES_CONVERSION;
	m_errorCode = m_zfp.SetDecimalPoint(OLE2A(password), point);
	*pRes = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::GetEJMode(long *pIsShort)
{
	int isShort;
	m_errorCode = m_zfp.GetEJMode(&isShort);
	if (ZFPE_SUCCESS == m_errorCode)
		*pIsShort = isShort;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::SetEJMode(BOOL bShort, long *pRes)
{
	m_errorCode = m_zfp.SetEJMode(bShort);
	*pRes = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::ReportEJ(long *pRes)
{
	m_errorCode = m_zfp.ReportEJ();
	*pRes = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::SellDepartmentEx(BSTR name, WORD depNum, double price, double quantity, double discount, BYTE flag, long *pRes)
{
	USES_CONVERSION;
	m_errorCode = m_zfp.SellDepartmentEx(OLE2A(name), depNum, price, quantity, discount, flag);
	*pRes = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::SellDepartment(BSTR name, WORD depNum, double price, double quantity, double discount, long *pRes)
{
	USES_CONVERSION;
	m_errorCode = m_zfp.SellDepartment(OLE2A(name), depNum, price, quantity, discount);
	*pRes = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::SetDepartment(WORD number, BSTR name, BYTE taxgrp, long *pRes)
{
	USES_CONVERSION;
	m_errorCode = m_zfp.SetDepartment(number, OLE2A(name), taxgrp);
	*pRes = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::GetDepartment(WORD number, LPDISPATCH *pRes)
{
	USES_CONVERSION;
	IArticleInfo *res = NULL;

	HRESULT hr = CoCreateInstance(CLSID_ArticleInfo, NULL, CLSCTX_SERVER,
		IID_IArticleInfo, (LPVOID*)&res);
	
	if (S_OK == hr) {
		double turnover = 0.0;
		double quantity = -1.0;
		char name[ZFP_MAXBUFLEN] = "", taxgroup = 'À';
		WORD counter = 0;
		int dd = 0, mm = 0, yy = 0, hh = 0, mmm = 0;
		m_errorCode = m_zfp.GetDepartmentEx(number, name, &taxgroup, &turnover, &quantity, &counter, &dd, &mm, &yy, &hh, &mmm);
		res->put_name(A2BSTR(name));
		res->put_price(0.0);
		res->put_taxgroup((short)((BYTE)taxgroup));
		res->put_turnover(turnover);
		res->put_sells(0.0);
		res->put_counter(counter);
		res->put_department((short)number);
		res->put_quantity(quantity);
		DATE date;
		MyOleDateFromTm(yy, mm, dd, hh, mmm, 0, date);
		res->put_reportdate(date);

		*pRes = res;
	}

	return hr;
}

STDMETHODIMP CZekaFPCom::SetArticleInfo2(DWORD num, BSTR name, double price, BYTE taxgrp, WORD department, long *pRes)
{
	USES_CONVERSION;
	m_errorCode = m_zfp.SetArticleInfoEx(num, OLE2A(name), price, taxgrp, department);
	*pRes = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::SetArticleInfo3(DWORD num, BSTR name, double price, BYTE taxgrp, WORD department, BSTR unit, long *pRes)
{
	USES_CONVERSION;
	m_errorCode = m_zfp.SetArticleInfoEx(num, OLE2A(name), price, taxgrp, department, OLE2A(unit));
	*pRes = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::SetArticleInfoEx(WORD num, BSTR name, double price, BYTE taxgrp, WORD department, long *pRes)
{
	USES_CONVERSION;
	m_errorCode = m_zfp.SetArticleInfo(num, OLE2A(name), price, taxgrp, department);
	*pRes = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::CalcIntermediateSum2(BOOL doprint, BOOL dodisplay, BOOL dopercents, double discount, short taxgrp, double *pRes)
{
	DWORD flags = doprint ? ZFP_ISPRINT : 0;
	flags |= dodisplay ? ZFP_ISSHOW : 0;
	flags |= dopercents ? ZFP_ISPERCENT : 0;
	double res = 0.0;
	m_errorCode = m_zfp.CalcIntermediateSum(&res, flags, discount, (char)taxgrp);
	*pRes = toDouble(res, 2);
	return S_OK;
}

STDMETHODIMP CZekaFPCom::AddDiscount(BOOL dotrans, BOOL doauto, BOOL dodisplay, BOOL dopercents, double discount, long *pRes)
{
	DWORD flags = 0;

	if ( dotrans ) flags |= ZFP_ADTRANS;
	if ( doauto && !dotrans ) flags |= ZFP_ADAUTO;
	if ( dodisplay ) flags |= ZFP_ADSHOW;
	if ( dopercents ) flags |= ZFP_ADPERCENT;
	m_errorCode = m_zfp.AddDiscount(flags, discount);
	*pRes = m_errorCode;

	return S_OK;
}

STDMETHODIMP CZekaFPCom::ReportEJ2(WORD num, long *pRes)
{
	m_errorCode = m_zfp.ReportEJ(num);
	*pRes = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::SetTaxPercentsEU(BSTR password, double tgr1, double tgr2, double tgr3, double tgr4, double tgr5, double tgr6, double tgr7, double tgr8, long *pRes)
{
	USES_CONVERSION;
	TZfpTaxGroups tg;
	tg.taxGrp1 = tgr1;
	tg.taxGrp2 = tgr2;
	tg.taxGrp3 = tgr3;
	tg.taxGrp4 = tgr4;
	tg.taxGrp5 = tgr5;
	tg.taxGrp6 = tgr6;
	tg.taxGrp7 = tgr7;
	tg.taxGrp8 = tgr8;

	m_errorCode = m_zfp.SetTaxPercentsEU(OLE2A(password), tg);
	*pRes = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::SetPayTypeEU(BYTE type, BSTR line, double exchRate, long *pRes)
{
	USES_CONVERSION;
	m_errorCode = m_zfp.SetPayTypeEU(type, OLE2A(line), exchRate);
	*pRes = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::SetPayTypeEx(BYTE type, BSTR line, double exchRate, int code, long *pRes)
{
	USES_CONVERSION;
	m_errorCode = m_zfp.SetPayTypeEU(type, OLE2A(line), exchRate, code);
	*pRes = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::GetOperatorChangeEU(BYTE oper, LPDISPATCH *pRes)
{
	IPayTypes *res = NULL;

	HRESULT hr = CoCreateInstance(CLSID_PayTypes, NULL, CLSCTX_SERVER,
		IID_IPayTypes, (LPVOID*)&res);
	
	if (S_OK == hr) {
		double pt1 = 0.0, pt2 = 0.0, pt3 = 0.0, pt4 = 0.0, pt0 = 0.0; 
		m_errorCode = m_zfp.GetOperatorChangeEU(oper, &pt0, &pt1, &pt2, &pt3, &pt4);
		res->put_paytype0sum(toDouble(pt0, 2));
		res->put_paytype1sum(toDouble(pt1, 2));
		res->put_paytype2sum(toDouble(pt2, 2));
		res->put_paytype3sum(toDouble(pt3, 2));
		res->put_paytype4sum(toDouble(pt4, 2));
		*pRes = res;
	}

	return hr;
}

STDMETHODIMP CZekaFPCom::SetInvoiceNumbersRangeEU(BSTR startNum, BSTR lastNum, long *pRes)
{
	USES_CONVERSION;
	m_errorCode = m_zfp.SetInvoiceNumbersRangeEU(OLE2A(startNum), OLE2A(lastNum));
	*pRes = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::PaymentEU(double sum, BYTE type, BOOL noChange, BYTE changeType, long *pRes)
{
	m_errorCode = m_zfp.PaymentEU(sum, type, noChange, changeType);
	*pRes = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::PaymentEx(double sum, BYTE type, BOOL noChange, BYTE changeType, BOOL fPaidExactSum, long *pRes)
{
	m_errorCode = m_zfp.PaymentEx(sum, type, noChange, changeType, fPaidExactSum);
	*pRes = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::SetParametersEU(WORD fpnum, BOOL logo, BOOL till, BOOL autocut, BOOL transparent, BOOL shortEJ, BOOL currency, long *pRes)
{
	TZfpParams p;
	p.fpnum = fpnum;
	p.logo = logo;
	p.till = till;
	p.autocut = autocut;
	p.transparent = transparent;
	p.shortEJ = shortEJ;
	p.currency = currency;
	m_errorCode = m_zfp.SetParametersEU(p);
	*pRes = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::SendCommandDirect(BSTR cmd, BSTR *pRes)
{
	USES_CONVERSION;
	char data[ZFP_MAXBUFLEN];
	BYTE len;
	m_errorCode = m_zfp.SendCommandDirect(OLE2A(cmd), data, &len);
	if (ZFPE_SUCCESS == m_errorCode) {
		data[len] = 0;
		*pRes = A2BSTR(data);
	}
	return S_OK;
}

STDMETHODIMP CZekaFPCom::GetDailyChangeEU(LPDISPATCH *pRes)
{
	IPayTypes *res = NULL;

	HRESULT hr = CoCreateInstance(CLSID_PayTypes, NULL, CLSCTX_SERVER,
		IID_IPayTypes, (LPVOID*)&res);
	
	if (S_OK == hr) {
		double pt1 = 0.0, pt2 = 0.0, pt3 = 0.0, pt4 = 0.0, pt0 = 0.0; 
		m_errorCode = m_zfp.GetDailyChangeEU(&pt0, &pt1, &pt2, &pt3, &pt4);
		res->put_paytype0sum(toDouble(pt0, 2));
		res->put_paytype1sum(toDouble(pt1, 2));
		res->put_paytype2sum(toDouble(pt2, 2));
		res->put_paytype3sum(toDouble(pt3, 2));
		res->put_paytype4sum(toDouble(pt4, 2));
		*pRes = res;
	}

	return hr;
}

STDMETHODIMP CZekaFPCom::UpdateClicheKE(BYTE mode, BSTR password, long *pRes)
{
	USES_CONVERSION;
	m_errorCode = m_zfp.UpdateClicheKE(mode, OLE2A(password));
	*pRes = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::Setup2(BYTE wCom, long baud, long retries, long retryWait)
{
	m_zfp.Setup((WORD)wCom, (DWORD)baud, (WORD)retries, (DWORD)retryWait);
	return S_OK;
}

STDMETHODIMP CZekaFPCom::get_zfplibVersion(long *pVal)
{
	*pVal = (long)CZekaFP::GetLibraryVersion();
	return S_OK;
}

STDMETHODIMP CZekaFPCom::GetInvoiceNextNumberEU(LPDISPATCH *pRes)
{
	USES_CONVERSION;
	IInvoiceNumbers *res = NULL;

	HRESULT hr = CoCreateInstance(CLSID_InvoiceNumbers, NULL, CLSCTX_SERVER,
		IID_IInvoiceNumbers, (LPVOID*)&res);
	
	if (S_OK == hr) {
		char nextNum[ZFP_MAXBUFLEN] = "", lastNum[ZFP_MAXBUFLEN] = "";
		m_errorCode = m_zfp.GetInvoiceNextNumberEU(nextNum, lastNum);
		res->put_nextNum(A2BSTR(nextNum));
		res->put_lastNum(A2BSTR(lastNum));
		*pRes = res;
	}

	return hr;
}

STDMETHODIMP CZekaFPCom::SetLogo(BYTE logo, long *pRes)
{
	m_errorCode = m_zfp.SetLogo(logo);
	*pRes = m_errorCode;
	return S_OK;
}

STDMETHODIMP CZekaFPCom::GetLogoInfo(BSTR *pRes)
{
	USES_CONVERSION;
	char li[ZFP_MAXBUFLEN];
	m_errorCode = m_zfp.GetLogoInfo(li);
	if (m_errorCode == ZFPE_SUCCESS)
		*pRes = A2BSTR(li);
	return S_OK;
}
