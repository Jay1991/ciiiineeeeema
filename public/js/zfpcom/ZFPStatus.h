//////////////////////////////////////////////////////////////////////
// Copyright (c) 2005 Tremol Ltd.
// License: Mozilla Public License 1.1
// Contacts: software@tremol.bg
//////////////////////////////////////////////////////////////////////
// ZFPStatus.h : Declaration of the CZFPStatus

#ifndef __ZFPSTATUS_H_
#define __ZFPSTATUS_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CZFPStatus
class ATL_NO_VTABLE CZFPStatus : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CZFPStatus, &CLSID_ZFPStatus>,
	public IDispatchImpl<IZFPStatus, &IID_IZFPStatus, &LIBID_ZFPCOMLib>
{
public:
	CZFPStatus()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_ZFPSTATUS)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CZFPStatus)
	COM_INTERFACE_ENTRY(IZFPStatus)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IZFPStatus
public:
	STDMETHOD(get_printCurrency)(/*[out, retval]*/ BOOL *pVal);
	STDMETHOD(get_fullEJ)(/*[out, retval]*/ BOOL *pVal);
	STDMETHOD(get_EJLimitNear)(/*[out, retval]*/ BOOL *pVal);
	STDMETHOD(get_shortEJMode)(/*[out, retval]*/ BOOL *pVal);
	STDMETHOD(get_missingDisplay)(/*[out, retval]*/ BOOL *pVal);
	STDMETHOD(get_Blocked24HoursReport)(/*[out, retval]*/ BOOL *pVal);
	STDMETHOD(get_printerOverheat)(/*[out, retval]*/ BOOL *pVal);
	STDMETHOD(get_powerDown)(/*[out, retval]*/ BOOL *pVal);
	STDMETHOD(get_readOnlyFM)(/*[out, retval]*/ BOOL *pVal);
	STDMETHOD(get_autoTillOpen)(/*[out, retval]*/ BOOL *pVal);
	STDMETHOD(get_baud9600)(/*[out, retval]*/ BOOL *pVal);
	STDMETHOD(get_hasTransparentDisplay)(/*[out, retval]*/ BOOL *pVal);
	STDMETHOD(get_autoCutter)(/*[out, retval]*/ BOOL *pVal);
	STDMETHOD(get_hasFiscalAndFactoryNum)(/*[out, retval]*/ BOOL *pVal);
	STDMETHOD(get_isFiscal)(/*[out, retval]*/ BOOL *pVal);
	STDMETHOD(get_hasDecimalPoint)(/*[out, retval]*/ BOOL *pVal);
	STDMETHOD(get_fiscalMemoryLimitNear)(/*[out, retval]*/ BOOL *pVal);
	STDMETHOD(get_fullFiscalMemory)(/*[out, retval]*/ BOOL *pVal);
	STDMETHOD(get_wrongFiscalMemory)(/*[out, retval]*/ BOOL *pVal);
	STDMETHOD(get_missingFiscalMemory)(/*[out, retval]*/ BOOL *pVal);
	STDMETHOD(get_VATinfo)(/*[out, retval]*/ BOOL *pVal);
	STDMETHOD(get_detailedInfo)(/*[out, retval]*/ BOOL *pVal);
	STDMETHOD(get_OpenFiscalBon)(/*[out, retval]*/ BOOL *pVal);
	STDMETHOD(get_openOfficialBon)(/*[out, retval]*/ BOOL *pVal);
	STDMETHOD(get_duplicateNotPrinted)(/*[out, retval]*/ BOOL *pVal);
	STDMETHOD(get_nonzeroOperatorReport)(/*[out, retval]*/ BOOL *pVal);
	STDMETHOD(get_nonzeroArticleReport)(/*[out, retval]*/ BOOL *pVal);
	STDMETHOD(get_nonzeroDailyReport)(/*[out, retval]*/ BOOL *pVal);
	STDMETHOD(get_printLogo)(/*[out, retval]*/ BOOL *pVal);
	STDMETHOD(get_reportSumOverflow)(/*[out, retval]*/ BOOL *pVal);
	STDMETHOD(get_paperOutPrinterError)(/*[out, retval]*/ BOOL *pVal);
	STDMETHOD(get_clockHardwareError)(/*[out, retval]*/ BOOL *pVal);
	STDMETHOD(get_wrongRAM)(/*[out, retval]*/ BOOL *pVal);
	STDMETHOD(get_wrongDate)(/*[out, retval]*/ BOOL *pVal);
	STDMETHOD(get_wrongTimer)(/*[out, retval]*/ BOOL *pVal);
	STDMETHOD(get_ST4)(/*[out, retval]*/ BYTE *pVal);
	STDMETHOD(put_ST4)(/*[in]*/ BYTE newVal);
	STDMETHOD(get_ST3)(/*[out, retval]*/ BYTE *pVal);
	STDMETHOD(put_ST3)(/*[in]*/ BYTE newVal);
	STDMETHOD(get_ST2)(/*[out, retval]*/ BYTE *pVal);
	STDMETHOD(put_ST2)(/*[in]*/ BYTE newVal);
	STDMETHOD(get_ST1)(/*[out, retval]*/ BYTE *pVal);
	STDMETHOD(put_ST1)(/*[in]*/ BYTE newVal);
	STDMETHOD(get_ST0)(/*[out, retval]*/ BYTE *pVal);
	STDMETHOD(put_ST0)(/*[in]*/ BYTE newVal);

protected:
	BYTE m_st0, m_st1, m_st2, m_st3, m_st4;
};

#endif //__ZFPSTATUS_H_
