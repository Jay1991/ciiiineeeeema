//////////////////////////////////////////////////////////////////////
// Copyright (c) 2005 Tremol Ltd.
// License: Mozilla Public License 1.1
// Contacts: software@tremol.bg
//////////////////////////////////////////////////////////////////////
// FiscalReportData.h : Declaration of the CFiscalReportData

#ifndef __FISCALREPORTDATA_H_
#define __FISCALREPORTDATA_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CFiscalReportData
class ATL_NO_VTABLE CFiscalReportData : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CFiscalReportData, &CLSID_FiscalReportData>,
	public IDispatchImpl<IFiscalReportData, &IID_IFiscalReportData, &LIBID_ZFPCOMLib>
{
public:
	CFiscalReportData()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_FISCALREPORTDATA)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CFiscalReportData)
	COM_INTERFACE_ENTRY(IFiscalReportData)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IFiscalReportData
public:
	STDMETHOD(get_reportdate)(/*[out, retval]*/ DATE *pVal);
	STDMETHOD(put_reportdate)(/*[in]*/ DATE newVal);
	STDMETHOD(get_lastzeroram)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_lastzeroram)(/*[in]*/ long newVal);
	STDMETHOD(get_lastreport)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_lastreport)(/*[in]*/ long newVal);

protected:
	DATE  m_reportdate;
	long  m_lastreport;
	long  m_lastzeroram;

};

#endif //__FISCALREPORTDATA_H_
