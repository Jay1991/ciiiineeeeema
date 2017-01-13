//////////////////////////////////////////////////////////////////////
// Copyright (c) 2005-2008 Tremol Ltd.
// License: Mozilla Public License 1.1
// Contacts: software@tremol.bg
//////////////////////////////////////////////////////////////////////
// ZekaFPCom.h : Declaration of the CZekaFPCom

#ifndef __ZEKAFPCOM_H_
#define __ZEKAFPCOM_H_

#include "resource.h"       // main symbols
#include "../include/ZekaFP.h"
#include <atlctl.h>

/////////////////////////////////////////////////////////////////////////////
// CZekaFPCom
class ATL_NO_VTABLE CZekaFPCom : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CZekaFPCom, &CLSID_ZekaFP>,
	public IConnectionPointContainerImpl<CZekaFPCom>,
	public IDispatchImpl<IZekaFP, &IID_IZekaFP, &LIBID_ZFPCOMLib>,
	public IObjectSafetyImpl <CZekaFPCom, INTERFACESAFE_FOR_UNTRUSTED_CALLER|INTERFACESAFE_FOR_UNTRUSTED_DATA>
{
public:
	CZekaFPCom() {}
	~CZekaFPCom() {}

DECLARE_REGISTRY_RESOURCEID(IDR_ZEKAFP)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CZekaFPCom)
	COM_INTERFACE_ENTRY(IZekaFP)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
	COM_INTERFACE_ENTRY(IObjectSafety)
END_COM_MAP()
BEGIN_CONNECTION_POINT_MAP(CZekaFPCom)
END_CONNECTION_POINT_MAP()


// IZekaFP
public:
	STDMETHOD(GetInvoiceNextNumberEU)(/*[out, retval]*/ LPDISPATCH *pRes);
	STDMETHOD(get_zfplibVersion)(/*[out, retval]*/ long *pVal);
	STDMETHOD(OpenBonWithEJ)(/*[in]*/BYTE oper, /*[in]*/ BSTR passwd, /*[in]*/ BOOL hasEJ, /*[out, retval]*/ long *pRes);
	STDMETHOD(Setup2)(/*[in]*/ BYTE wCom, /*[in]*/ long baud, /*[in]*/ long retries, /*[in]*/ long retryWait);
	STDMETHOD(UpdateClicheKE)(/*[in]*/BYTE mode, /*[in]*/ BSTR password, /*[out, retval]*/ long *pRes);
	STDMETHOD(GetDailyChangeEU)(/*[out, retval]*/ LPDISPATCH *pRes);
	STDMETHOD(SendCommandDirect)(/*[in]*/ BSTR cmd, /*[out, retval]*/ BSTR *pRes);
	STDMETHOD(SetParametersEU)(/*[in]*/ WORD fpnum, /*[in]*/ BOOL logo, /*[in]*/ BOOL till, /*[in]*/ BOOL autocut, /*[in]*/ BOOL transparent, /*[in]*/ BOOL shortEJ, /*[in]*/ BOOL currency, /*[out, retval]*/ long *pRes);
	STDMETHOD(PaymentEU)(/*[in]*/ double sum, /*[in]*/ BYTE type, /*[in]*/ BOOL noChange, /*[in]*/ BYTE changeType, /*[out, retval]*/ long *pRes);
	STDMETHOD(PaymentEx)(/*[in]*/ double sum, /*[in]*/ BYTE type, /*[in]*/ BOOL noChange, /*[in]*/ BYTE changeType, /*[in]*/ BOOL fPaidExactSum, /*[out, retval]*/ long *pRes);
	STDMETHOD(SetInvoiceNumbersRangeEU)(/*[in]*/ BSTR startNum, /*[in]*/ BSTR lastNum, /*[out, retval]*/ long *pRes);
	STDMETHOD(GetOperatorChangeEU)(/*[in]*/ BYTE oper, /*[out, retval]*/ LPDISPATCH *pRes);
	STDMETHOD(SetPayTypeEU)(/*[in]*/BYTE type, /*[in]*/ BSTR line, /*[in]*/ double exchRate, /*[out, retval]*/ long *pRes);
	STDMETHOD(SetPayTypeEx)(/*[in]*/BYTE type, /*[in]*/ BSTR line, /*[in]*/ double exchRate, int code, /*[out, retval]*/ long *pRes);
	STDMETHOD(SetTaxPercentsEU)(/*[in]*/ BSTR password, /*[in]*/ double tgr1, /*[in]*/ double tgr2, /*[in]*/ double tgr3, /*[in]*/ double tgr4, /*[in]*/ double tgr5, /*[in]*/ double tgr6, /*[in]*/ double tgr7, /*[in]*/ double tgr8, /*[out, retval]*/ long *pRes);
	STDMETHOD(ReportEJ2)(/*[in]*/ WORD num, /*[out, retval]*/ long *pRes);
	STDMETHOD(CalcIntermediateSum2)(/*[in]*/ BOOL doprint, /*[in]*/ BOOL dodisplay, /*[in]*/ BOOL dopercents, /*[in]*/ double discount, /*[in]*/ short taxgrp, /*[out, retval]*/ double *pRes);
	STDMETHOD(SetArticleInfoEx)(/*[in]*/ WORD num, /*[in]*/ BSTR name, /*[in]*/ double price, /*[in]*/ BYTE taxgrp, /*[in]*/ WORD department, /*[out, retval]*/ long *pRes);
	STDMETHOD(SetArticleInfo2)(/*[in]*/ DWORD num, /*[in]*/ BSTR name, /*[in]*/ double price, /*[in]*/ BYTE taxgrp, /*[in]*/ WORD department, /*[out, retval]*/ long *pRes);
	STDMETHOD(SetArticleInfo3)(/*[in]*/ DWORD num, /*[in]*/ BSTR name, /*[in]*/ double price, /*[in]*/ BYTE taxgrp, /*[in]*/ WORD department, /*[in]*/ BSTR unit, /*[out, retval]*/ long *pRes);
	STDMETHOD(GetDepartment)(/*[in]*/ WORD number, /*[out, retval]*/ LPDISPATCH *pRes);
	STDMETHOD(SetDepartment)(/*[in]*/WORD number, /*[in]*/ BSTR name, /*[in]*/ BYTE taxgrp, /*[out, retval]*/ long *pRes);
	STDMETHOD(SellDepartment)(/*[in]*/ BSTR name, /*[in]*/ WORD depNum, /*[in]*/ double price, /*[in]*/ double quantity, /*[in]*/ double discount, /*[out, retval]*/ long *pRes);
	STDMETHOD(SellDepartmentEx)(/*[in]*/ BSTR name, /*[in]*/ WORD depNum, /*[in]*/ double price, /*[in]*/ double quantity, /*[in]*/ double discount, /*[in]*/ BYTE flag, /*[out, retval]*/ long *pRes);
	STDMETHOD(ReportEJ)(/*[out, retval]*/ long *pRes);
	STDMETHOD(SetEJMode)(/*[in]*/ BOOL bShort, /*[out, retval]*/ long *pRes);
	STDMETHOD(GetEJMode)(/*[out, retval]*/ long *pIsShort);
	STDMETHOD(SetDecimalPoint)(/*[in]*/ BSTR password, /*[in]*/ int point, /*[out, retval]*/ long *pRes);
	STDMETHOD(SetTaxPercents)(/*[in]*/ BSTR password, /*[in]*/ double tgr1, /*[in]*/ double tgr2, /*[in]*/ double tgr3, /*[in]*/ double tgr4, /*[out, retval]*/ long *pRes);
	STDMETHOD(MakeFiscal)(/*[in]*/ BSTR password, /*[out, retval]*/ long *pRes);
	STDMETHOD(SetTaxNumber)(/*[in]*/ BSTR password, /*[in]*/ BSTR taxNum, BSTR fiscalNum, /*[out, retval]*/ long *pRes);
	STDMETHOD(SetSerialNumber)(/*[in]*/ BSTR password, /*[in]*/ BSTR manifactureNum, /*[in]*/ BSTR fiscalNum, /*[in]*/ BSTR controlSum, /*[out, retval]*/ long *pRes);
	STDMETHOD(SetAutoBusyWait)(/*[in]*/ DWORD timeout);
	STDMETHOD(BusyWait)(/*[in]*/ DWORD timeout, /*[out, retval]*/ long *pRes);
	STDMETHOD(OpenInvoice)(/*[in]*/ BYTE oper, /*[in]*/ BSTR pass, /*[in]*/ BSTR client, /*[in]*/ BSTR receiver, /*[in]*/ BSTR taxnum, /*[in]*/ BSTR bulstat, /*[in]*/ BSTR address, /*[out, retval]*/ long *pRes);
	STDMETHOD(get_zfpType)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_zfpType)(/*[in]*/ long newVal);
	STDMETHOD(GetFreeFiscalSpace)(/*[out, retval]*/ long *pRecords);
	STDMETHOD(GetStatus)(/*[out, retval]*/ LPDISPATCH *pRes);
	STDMETHOD(PaperCut)(/*[out, retval]*/ long *pRes);
	STDMETHOD(FindFirstFPCOM)(/*[out, retval]*/ DWORD *pRes);
	STDMETHOD(FindFirstFPCOMEx)(/*[out, retval]*/ DWORD *pRes);
	STDMETHOD(ReadFiscalMemory)(/*[in]*/ BSTR filename, /*[out, retval]*/ long *pRes);
	STDMETHOD(ReadFiscalMemory2)(/*[in]*/ BSTR filename, /*[out, retval]*/ long *pRes);
	STDMETHOD(SetExternalDisplayFile)(/*[in]*/ BSTR password, /*[in]*/ BSTR filename, /*[out, retval]*/ long *pRes);
	STDMETHOD(GetOperatorCounter)(/*[in]*/ BYTE oper, /*[out, retval]*/ LPDISPATCH *pRes);
	STDMETHOD(GetDailyReport)(/*[out, retval]*/ LPDISPATCH *pRes);
	STDMETHOD(PrintText)(/*[in]*/ BSTR text, /*[in]*/ int align, /*[out, retval]*/ long *pRes);
	STDMETHOD(PrintTextKP)(/*[in]*/ BSTR text, long *pRes);
	STDMETHOD(PrintTextKP2)(/*[in]*/ BSTR format, int flags, BSTR text_param, double numeric_param, long *pRes);
	STDMETHOD(ReportOperator)(/*[in]*/ BOOL zero, /*[in]*/ BYTE oper, /*[out, retval]*/ long *pRes);
	STDMETHOD(ReportFiscalByDate)(/*[in]*/ BOOL detailed, /*[in]*/ DATE start, /*[in]*/ DATE end, /*[out, retval]*/ long *pRes);
	STDMETHOD(SetDateTime)(/*[in]*/ DATE datetime, /*[out, retval]*/ long *pRes);
	STDMETHOD(ReportArticles)(/*[in]*/ BOOL zero, /*[out, retval]*/ long *pRes);
	STDMETHOD(ReportDepartments)(/*[in]*/ BOOL zero, /*[out, retval]*/ long *pRes);
	STDMETHOD(ReportDaily)(/*[in]*/ BOOL zero, /*[in]*/ BOOL extended, /*[out, retval]*/ long *pRes);
	STDMETHOD(ReportFiscalByBlock)(/*[in]*/ BOOL detailed, /*[in]*/ WORD startNumber, /*[in]*/ WORD endNumber, /*[out, retval]*/ long *pRes);
	STDMETHOD(ReportSpecialFiscal)(/*[out, retval]*/ long *pRes);
	STDMETHOD(GetLastFiscalReportData)(/*[out, retval]*/ LPDISPATCH *pRes);
	STDMETHOD(CalcIntermediateSum)(/*[in]*/ BOOL doprint, /*[in]*/ BOOL dodisplay, /*[in]*/ BOOL dopercents, /*[in]*/ double discount, /*[out, retval]*/ double *pRes);
	STDMETHOD(AddDiscount)(/*[in]*/ BOOL dotrans, /*[in]*/ BOOL doauto, /*[in]*/ BOOL dodisplay, /*[in]*/ BOOL dopercents, /*[in]*/ double discount, /*[out, retval]*/ long *pRes);
	STDMETHOD(GetDailyOfficialExpenses)(/*[out, retval]*/ LPDISPATCH *pRes);
	STDMETHOD(GetDailyOfficialIncomes)(/*[out, retval]*/ LPDISPATCH *pRes);
	STDMETHOD(GetDailyIncomes)(/*[out, retval]*/ LPDISPATCH *pRes);
	STDMETHOD(GetDailyPayments)(/*[out, retval]*/ LPDISPATCH *pRes);
	STDMETHOD(GetOperatorExpenses)(/*[in]*/ BYTE oper, /*[out, retval]*/ LPDISPATCH *pRes);
	STDMETHOD(GetOperatorIncomes)(/*[in]*/ BYTE oper, /*[out, retval]*/ LPDISPATCH *pRes);
	STDMETHOD(GetErrorString)(/*[in]*/ int error, /*[in]*/ int lang, /*[out, retval]*/ BSTR *pRes);
	STDMETHOD(GetResponseHexFormated)(/*[out, retval]*/ BSTR *pRes);
	STDMETHOD(GetInputHexFormated)(/*[out, retval]*/ BSTR *pRes);
	STDMETHOD(GetResponseBuffer)(/*[out, retval]*/ BSTR *pRes);
	STDMETHOD(GetInputBuffer)(/*[out, retval]*/ BSTR *pRes);
	STDMETHOD(GetVersion)(/*[out, retval]*/ BSTR *pRes);
	STDMETHOD(DisplayLine2)(/*[in]*/ BSTR line, /*[out, retval]*/ long *pRes);
	STDMETHOD(DisplayLine1)(/*[in]*/ BSTR line, /*[out, retval]*/ long *pRes);
	STDMETHOD(Display)(/*[in]*/ BSTR line, /*[out, retval]*/ long *pRes);
	STDMETHOD(GetDateTime)(/*[out, retval]*/ DATE* pVal);
	STDMETHOD(GetOperatorReceives)(/*[in]*/ BYTE oper, /*[out, retval]*/ LPDISPATCH *pRes);
	STDMETHOD(GetOperatorInfo)(/*[in]*/ BYTE oper, /*[out, retval]*/ LPDISPATCH *pRes);
	STDMETHOD(GetDailyInfo)(/*[out, retval]*/ LPDISPATCH *pRes);
	STDMETHOD(GetArticleInfo)(/*[in]*/ WORD number, /*[out, retval]*/ LPDISPATCH *pRes);
	STDMETHOD(GetArticleInfoEx)(/*[in]*/ DWORD number, /*[out, retval]*/ LPDISPATCH *pRes);
	STDMETHOD(GetArticleUnit)(/*[in]*/ DWORD number, /*[out, retval]*/ BSTR *pRes);
	STDMETHOD(GetDailySums)(/*[out, retval]*/ LPDISPATCH *pRes);
	STDMETHOD(GetOperatorUserPass)(/*[in]*/ BYTE oper, /*[out, retval]*/ LPDISPATCH *pRes);
	STDMETHOD(GetParameters)(/*[out, retval]*/ LPDISPATCH *pRes);
	STDMETHOD(GetPayTypes)(/*[out, retval]*/ LPDISPATCH *pRes);
	STDMETHOD(GetTaxPercents)(/*[out, retval]*/ LPDISPATCH *pRes);
	STDMETHOD(SellDB)(/*[in]*/ BOOL isVoid, /*[in]*/ WORD number, /*[in]*/ double quantity, /*[in]*/ double discount, /*[out, retval]*/ long *pRes);
	STDMETHOD(SellDBEx)(/*[in]*/ BOOL isVoid, /*[in]*/ DWORD number, /*[in]*/ double quantity, /*[in]*/ double discount, /*[in]*/ BYTE flag, /*[out, retval]*/ long *pRes);
	STDMETHOD(SellDBEx2)(/*[in]*/ BOOL isVoid, /*[in]*/ DWORD number, /*[in]*/ double price, /*[in]*/ double quantity, /*[in]*/ double discount, /*[in]*/ BYTE flag, /*[out, retval]*/ long *pRes);
	STDMETHOD(Storno)(/*[in]*/ BSTR name, /*[in]*/BYTE taxgrp, /*[in]*/ double price, /*[in]*/ double quantity, /*[out, retval]*/ long *pRes);
	STDMETHOD(GetFiscalNumber)(/*[out, retval]*/ BSTR *pRes);
	STDMETHOD(GetStartDateFM)(/*[out, retval]*/ BSTR *pRes);
	STDMETHOD(GetFactoryNumber)(/*[out, retval]*/ BSTR *pRes);
	STDMETHOD(SetLogoFile)(/*[in]*/ BSTR filename, /*[out, retval]*/ long *pRes);
	STDMETHOD(SetLogoFileEx)(/*[in]*/BYTE logo, /*[in]*/ BSTR filename, /*[out, retval]*/ long *pRes);
	STDMETHOD(SetArticleInfo)(/*[in]*/ WORD num, /*[in]*/ BSTR name, /*[in]*/ double price, /*[in]*/ BYTE taxgrp, /*[out, retval]*/ long *pRes);
	STDMETHOD(SetOperatorUserPass)(/*[in]*/ BYTE oper, /*[in]*/ BSTR name, /*[in]*/ BSTR pass, /*[out, retval]*/ long *pRes);
	STDMETHOD(SetClicheLine)(/*[in]*/BYTE num, /*[in]*/ BSTR text, /*[out, retval]*/ long *pRes);
	STDMETHOD(SetParameters)(/*[in]*/ WORD fpnum, /*[in]*/ BOOL logo, /*[in]*/ BOOL till, BOOL autocut, BOOL transparent, /*[out, retval]*/ long *pRes);
	STDMETHOD(SetPayType)(/*[in]*/BYTE type, /*[in]*/ BSTR line, /*[out, retval]*/ long *pRes);
	STDMETHOD(GetBonNumber)(/*[out, retval]*/ long *pNumber);
	STDMETHOD(OfficialSums)(/*[in]*/BYTE num, /*[in]*/ BSTR pass, /*[in]*/ BYTE type, /*[in]*/ double sum, /*[out, retval]*/ long *pRes);
	STDMETHOD(OfficialSumsEx)(/*[in]*/BYTE num, /*[in]*/ BSTR pass, /*[in]*/ BYTE type, /*[in]*/ double sum, BSTR note, /*[out, retval]*/ long *pRes);
	STDMETHOD(Payment)(/*[in]*/ double sum, /*[in]*/ BYTE type, /*[in]*/ BOOL noRest, /*[out, retval]*/ long *pRes);
	STDMETHOD(SellFree)(/*[in]*/ BSTR name, /*[in]*/BYTE taxgrp, /*[in]*/ double price, /*[in]*/ double quantity, /*[in]*/ double discount, /*[out, retval]*/ long *pRes);
	STDMETHOD(SellFreeEx)(/*[in]*/ BSTR name, /*[in]*/BYTE taxgrp, /*[in]*/ double price, /*[in]*/ double quantity, /*[in]*/ double discount, /*[in]*/ BYTE flag, /*[out, retval]*/ long *pRes);
	STDMETHOD(SellFreeDiv)(/*[in]*/ BSTR name, /*[in]*/BYTE taxgrp, /*[in]*/ double price, /*[in]*/ double quantity, /*[in]*/ double discount, /*[in]*/ BYTE flag, DWORD divider, /*[out, retval]*/ long *pRes);
	STDMETHOD(OpenFiscalBon)(/*[in]*/ BYTE oper, /*[in]*/ BSTR pass, /*[in]*/ BYTE defPass, /*[in]*/ BYTE dds, /*[out, retval]*/ long *pRes);
	STDMETHOD(OpenBon)(/*[in]*/BYTE oper, /*[in]*/ BSTR pass, /*[out, retval]*/ long *pRes);
	STDMETHOD(GetClicheLine)(/*[in]*/BYTE num, /*[out, retval]*/ BSTR *pRes);
	STDMETHOD(GetDecimalPoint)(/*[out, retval]*/ long *pPoint);
	STDMETHOD(GetTaxNumber)(/*[out, retval]*/ BSTR *pRes);
	STDMETHOD(SetLocalDateTime)(/*[out, retval]*/ long *pRes);
	STDMETHOD(PrintDuplicate)(/*[out, retval]*/ long *pRes);
	STDMETHOD(CloseFiscalBon)(/*[out, retval]*/ long *pRes);
	STDMETHOD(CloseBon)(/*[out, retval]*/ long *pRes);
	STDMETHOD(CloseBonInCash)(/*[out, retval]*/ long *pRes);
	STDMETHOD(TerminateBon)(BOOL finish, /*[out, retval]*/ long *pRes);
	STDMETHOD(PrintLogo)(/*[out, retval]*/ long *pRes);
	STDMETHOD(PrintLogoEx)(/*[in]*/BYTE logo, /*[out, retval]*/ long *pRes);
	STDMETHOD(LineFeed)(/*[out, retval]*/ long *pRes);
	STDMETHOD(OpenTill)(/*[out, retval]*/ long *pRes);
	STDMETHOD(OpenTillEx)(/*[in]*/ BYTE num, /*[out, retval]*/ long *pRes);
	STDMETHOD(DisplayDateTime)(/*[out, retval]*/ long *pRes);
	STDMETHOD(DisplayClear)(/*[out, retval]*/ long *pRes);
	STDMETHOD(Diagnostic)(/*[out, retval]*/ long *pRes);
	STDMETHOD(get_errorCode)(/*[out, retval]*/ long *pVal);
	STDMETHOD(Setup)(/*[in]*/ WORD wCom, /*[in]*/ DWORD baud, /*[in]*/ WORD retries, /*[in]*/ DWORD retryWait);
	STDMETHOD(GetCurrentBonInfo)(/*[out, retval]*/ LPDISPATCH *pVal);
	STDMETHOD(SetLogo)(/*[in]*/BYTE logo, /*[out, retval]*/ long *pRes);
	STDMETHOD(GetLogoInfo)(/*[out, retval]*/ BSTR *pRes);
	STDMETHOD(GetVersionGS)(/*[out, retval]*/ BSTR *pRes);
	STDMETHOD(FormatBarcode)(/*[in]*/ BSTR fmt, /*[out, retval]*/ long *pRes);
	STDMETHOD(EnableBarcode)(/*[in]*/ BYTE state, /*[out, retval]*/ long *pRes);
	STDMETHOD(PrintBarcode)(/*[in]*/ BSTR barcode, BYTE type, /*[out, retval]*/ long *pRes);
	STDMETHOD(SetLineWidth)(/*[in]*/int num_chars, /*[out, retval]*/ long *pRes);
	STDMETHOD(GetLineWidth)(/*[out, retval]*/ long *pChars);
	STDMETHOD(SetPrintMode)(/*[in]*/DWORD mode, /*[out, retval]*/ long *pRes);
	STDMETHOD(OpenSerialPort)(/*[out, retval]*/ long *pRes);
	STDMETHOD(CloseSerialPort)(/*[out, retval]*/ long *pRes);

	STDMETHOD(EnableCommGS)(/*[in]*/BYTE enable, /*[in]*/ WORD device_no, /*[out, retval]*/ long *pRes);
	STDMETHOD(SetSpeedGS)(/*[in]*/BYTE speed, /*[out, retval]*/ long *pRes);
	STDMETHOD(LoadScaleProtocolGS)(/*[in]*/ BSTR protocol, /*[out, retval]*/ long *pRes);

protected:
	CZekaFP m_zfp;
	int m_errorCode;
};

#endif //__ZEKAFPCOM_H_
