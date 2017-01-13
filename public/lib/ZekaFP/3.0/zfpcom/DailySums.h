//////////////////////////////////////////////////////////////////////
// Copyright (c) 2005 Tremol Ltd.
// License: Mozilla Public License 1.1
// Contacts: software@tremol.bg
//////////////////////////////////////////////////////////////////////
// DailySums.h : Declaration of the CDailySums

#ifndef __DAILYSUMS_H_
#define __DAILYSUMS_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CDailySums
class ATL_NO_VTABLE CDailySums : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CDailySums, &CLSID_DailySums>,
	public IDispatchImpl<IDailySums, &IID_IDailySums, &LIBID_ZFPCOMLib>
{
public:
	CDailySums()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_DAILYSUMS)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CDailySums)
	COM_INTERFACE_ENTRY(IDailySums)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IDailySums
public:
	STDMETHOD(get_sumvoids)(/*[out, retval]*/ double *pVal);
	STDMETHOD(put_sumvoids)(/*[in]*/ double newVal);
	STDMETHOD(get_voids)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_voids)(/*[in]*/ long newVal);
	STDMETHOD(get_sumadding)(/*[out, retval]*/ double *pVal);
	STDMETHOD(put_sumadding)(/*[in]*/ double newVal);
	STDMETHOD(get_adding)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_adding)(/*[in]*/ long newVal);
	STDMETHOD(get_sumdiscount)(/*[out, retval]*/ double *pVal);
	STDMETHOD(put_sumdiscount)(/*[in]*/ double newVal);
	STDMETHOD(get_discounts)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_discounts)(/*[in]*/ long newVal);
	STDMETHOD(get_clients)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_clients)(/*[in]*/ long newVal);

protected:
	long m_clients;
	long m_discounts;
	double m_sumdiscount;
	long m_adding;
	double m_sumadding;
	long m_voids;
	double m_sumvoids;
};

#endif //__DAILYSUMS_H_
