//////////////////////////////////////////////////////////////////////
// Copyright (c) 2005 Tremol Ltd.
// License: Mozilla Public License 1.1
// Contacts: software@tremol.bg
//////////////////////////////////////////////////////////////////////
// TaxNumbers.h : Declaration of the CTaxNumbers

#ifndef __TAXNUMBERS_H_
#define __TAXNUMBERS_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CTaxNumbers
class ATL_NO_VTABLE CTaxNumbers : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CTaxNumbers, &CLSID_TaxNumbers>,
	public IDispatchImpl<ITaxNumbers, &IID_ITaxNumbers, &LIBID_ZFPCOMLib>
{
public:
	CTaxNumbers()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_TAXNUMBERS)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CTaxNumbers)
	COM_INTERFACE_ENTRY(ITaxNumbers)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// ITaxNumbers
public:
	STDMETHOD(get_taxgrp8)(/*[out, retval]*/ double *pVal);
	STDMETHOD(put_taxgrp8)(/*[in]*/ double newVal);
	STDMETHOD(get_taxgrp7)(/*[out, retval]*/ double *pVal);
	STDMETHOD(put_taxgrp7)(/*[in]*/ double newVal);
	STDMETHOD(get_taxgrp6)(/*[out, retval]*/ double *pVal);
	STDMETHOD(put_taxgrp6)(/*[in]*/ double newVal);
	STDMETHOD(get_taxgrp5)(/*[out, retval]*/ double *pVal);
	STDMETHOD(put_taxgrp5)(/*[in]*/ double newVal);
	STDMETHOD(get_taxgrp4)(/*[out, retval]*/ double *pVal);
	STDMETHOD(put_taxgrp4)(/*[in]*/ double newVal);
	STDMETHOD(get_taxgrp1)(/*[out, retval]*/ double *pVal);
	STDMETHOD(put_taxgrp1)(/*[in]*/ double newVal);
	STDMETHOD(get_taxgrp2)(/*[out, retval]*/ double *pVal);
	STDMETHOD(put_taxgrp2)(/*[in]*/ double newVal);
	STDMETHOD(get_taxgrp3)(/*[out, retval]*/ double *pVal);
	STDMETHOD(put_taxgrp3)(/*[in]*/ double newVal);

protected:
	double m_taxGrp1;
	double m_taxGrp2;
	double m_taxGrp3;
	double m_taxGrp4;
	double m_taxGrp5;
	double m_taxGrp6;
	double m_taxGrp7;
	double m_taxGrp8;
};

#endif //__TAXNUMBERS_H_
