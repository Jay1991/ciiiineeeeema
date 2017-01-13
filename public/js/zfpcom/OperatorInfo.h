//////////////////////////////////////////////////////////////////////
// Copyright (c) 2005 Tremol Ltd.
// License: Mozilla Public License 1.1
// Contacts: software@tremol.bg
//////////////////////////////////////////////////////////////////////
// OperatorInfo.h : Declaration of the COperatorInfo

#ifndef __OPERATORINFO_H_
#define __OPERATORINFO_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// COperatorInfo
class ATL_NO_VTABLE COperatorInfo : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<COperatorInfo, &CLSID_OperatorInfo>,
	public IDispatchImpl<IOperatorInfo, &IID_IOperatorInfo, &LIBID_ZFPCOMLib>
{
public:
	COperatorInfo()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_OPERATORINFO)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(COperatorInfo)
	COM_INTERFACE_ENTRY(IOperatorInfo)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IOperatorInfo
public:
	STDMETHOD(get_name)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(put_name)(/*[in]*/ BSTR newVal);
	STDMETHOD(get_passwd)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(put_passwd)(/*[in]*/ BSTR newVal);

protected:
	CComBSTR m_name;
	CComBSTR m_passwd;
	
};

#endif //__OPERATORINFO_H_
