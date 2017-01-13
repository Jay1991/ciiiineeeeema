//////////////////////////////////////////////////////////////////////
// Copyright (c) 2005 Tremol Ltd.
// License: Mozilla Public License 1.1
// Contacts: software@tremol.bg
//////////////////////////////////////////////////////////////////////
// ZFPParameters.h : Declaration of the CZFPParameters

#ifndef __ZFPPARAMETERS_H_
#define __ZFPPARAMETERS_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CZFPParameters
class ATL_NO_VTABLE CZFPParameters : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CZFPParameters, &CLSID_ZFPParameters>,
	public IDispatchImpl<IZFPParameters, &IID_IZFPParameters, &LIBID_ZFPCOMLib>
{
public:
	CZFPParameters()
	{
		m_fpnum = m_logo = m_till = m_autocut = m_transparent = 0;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_ZFPPARAMETERS)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CZFPParameters)
	COM_INTERFACE_ENTRY(IZFPParameters)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IZFPParameters
public:
	STDMETHOD(get_currency)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_currency)(/*[in]*/ long newVal);
	STDMETHOD(get_shortEJ)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_shortEJ)(/*[in]*/ long newVal);
	STDMETHOD(get_transparent)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_transparent)(/*[in]*/ long newVal);
	STDMETHOD(get_autocut)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_autocut)(/*[in]*/ long newVal);
	STDMETHOD(get_till)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_till)(/*[in]*/ long newVal);
	STDMETHOD(get_logo)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_logo)(/*[in]*/ long newVal);
	STDMETHOD(get_fpnum)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_fpnum)(/*[in]*/ long newVal);

protected:
	long m_fpnum;
	long m_logo;
	long m_till;
	long m_autocut;
	long m_transparent;
	long m_shortEJ;
	long m_currency;
};

#endif //__ZFPPARAMETERS_H_
