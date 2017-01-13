//////////////////////////////////////////////////////////////////////
// Copyright (c) 2005 Tremol Ltd.
// License: Mozilla Public License 1.1
// Contacts: software@tremol.bg
//////////////////////////////////////////////////////////////////////
// PayTypes.h : Declaration of the CPayTypes

#ifndef __PAYTYPES_H_
#define __PAYTYPES_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CPayTypes
class ATL_NO_VTABLE CPayTypes : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CPayTypes, &CLSID_PayTypes>,
	public IDispatchImpl<IPayTypes, &IID_IPayTypes, &LIBID_ZFPCOMLib>
{
public:
	CPayTypes()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_PAYTYPES)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CPayTypes)
	COM_INTERFACE_ENTRY(IPayTypes)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IPayTypes
public:
	STDMETHOD(get_exchRate)(/*[out, retval]*/ double *pVal);
	STDMETHOD(put_exchRate)(/*[in]*/ double newVal);
	STDMETHOD(get_operations)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_operations)(/*[in]*/ long newVal);
	STDMETHOD(get_paytype0sum)(/*[out, retval]*/ double *pVal);
	STDMETHOD(put_paytype0sum)(/*[in]*/ double newVal);
	STDMETHOD(get_paytype4sum)(/*[out, retval]*/ double *pVal);
	STDMETHOD(put_paytype4sum)(/*[in]*/ double newVal);
	STDMETHOD(get_paytype3sum)(/*[out, retval]*/ double *pVal);
	STDMETHOD(put_paytype3sum)(/*[in]*/ double newVal);
	STDMETHOD(get_paytype2sum)(/*[out, retval]*/ double *pVal);
	STDMETHOD(put_paytype2sum)(/*[in]*/ double newVal);
	STDMETHOD(get_paytype1sum)(/*[out, retval]*/ double *pVal);
	STDMETHOD(put_paytype1sum)(/*[in]*/ double newVal);
	STDMETHOD(get_paytype0)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(put_paytype0)(/*[in]*/ BSTR newVal);
	STDMETHOD(get_paytype4)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(put_paytype4)(/*[in]*/ BSTR newVal);
	STDMETHOD(get_paytype3)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(put_paytype3)(/*[in]*/ BSTR newVal);
	STDMETHOD(get_paytype2)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(put_paytype2)(/*[in]*/ BSTR newVal);
	STDMETHOD(get_paytype1)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(put_paytype1)(/*[in]*/ BSTR newVal);

protected:
	CComBSTR m_pt1;
	CComBSTR m_pt2;
	CComBSTR m_pt3;
	CComBSTR m_pt4;
	CComBSTR m_pt0;

	double m_pt1sum;
	double m_pt2sum;
	double m_pt3sum;
	double m_pt4sum;
	double m_pt0sum;
	
	double m_exchRate;

	long m_operations;
};

#endif //__PAYTYPES_H_
