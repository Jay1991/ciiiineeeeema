//////////////////////////////////////////////////////////////////////
// Copyright (c) 2005 Tremol Ltd.
// License: Mozilla Public License 1.1
// Contacts: software@tremol.bg
//////////////////////////////////////////////////////////////////////
// DailyReport.h : Declaration of the CDailyReport

#ifndef __DAILYREPORT_H_
#define __DAILYREPORT_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CDailyReport
class ATL_NO_VTABLE CDailyReport : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CDailyReport, &CLSID_DailyReport>,
	public IDispatchImpl<IDailyReport, &IID_IDailyReport, &LIBID_ZFPCOMLib>
{
public:
	CDailyReport()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_DAILYREPORT)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CDailyReport)
	COM_INTERFACE_ENTRY(IDailyReport)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IDailyReport
public:
	STDMETHOD(get_datetime)(/*[out, retval]*/ DATE *pVal);
	STDMETHOD(put_datetime)(/*[in]*/ DATE newVal);
	STDMETHOD(get_ecl)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_ecl)(/*[in]*/ long newVal);
	STDMETHOD(get_lastreport)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_lastreport)(/*[in]*/ long newVal);
	STDMETHOD(get_counter)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_counter)(/*[in]*/ long newVal);

protected:
	long m_counter;
	long m_lastreport;
	long m_ecl;
	DATE m_datetime;
};

#endif //__DAILYREPORT_H_
