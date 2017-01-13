//////////////////////////////////////////////////////////////////////
// Copyright (c) 2005 Tremol Ltd.
// License: Mozilla Public License 1.1
// Contacts: software@tremol.bg
//////////////////////////////////////////////////////////////////////
// GetCurrentBonInfoRes.h : Declaration of the CGetCurrentBonInfoRes

#ifndef __GETCURRENTBONINFORES_H_
#define __GETCURRENTBONINFORES_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CGetCurrentBonInfoRes
class ATL_NO_VTABLE CGetCurrentBonInfoRes : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CGetCurrentBonInfoRes, &CLSID_GetCurrentBonInfoRes>,
	public IDispatchImpl<IGetCurrentBonInfoRes, &IID_IGetCurrentBonInfoRes, &LIBID_ZFPCOMLib>
{
		
public:
	CGetCurrentBonInfoRes()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_GETCURRENTBONINFORES)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CGetCurrentBonInfoRes)
	COM_INTERFACE_ENTRY(IGetCurrentBonInfoRes)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IGetCurrentBonInfoRes
public:
	STDMETHOD(get_changeType)(/*[out, retval]*/ short *pVal);
	STDMETHOD(put_changeType)(/*[in]*/ short newVal);
	STDMETHOD(get_change)(/*[out, retval]*/ double *pVal);
	STDMETHOD(put_change)(/*[in]*/ double newVal);
	STDMETHOD(get_taxgrp8)(/*[out, retval]*/ double *pVal);
	STDMETHOD(put_taxgrp8)(/*[in]*/ double newVal);
	STDMETHOD(get_taxgrp7)(/*[out, retval]*/ double *pVal);
	STDMETHOD(put_taxgrp7)(/*[in]*/ double newVal);
	STDMETHOD(get_taxgrp6)(/*[out, retval]*/ double *pVal);
	STDMETHOD(put_taxgrp6)(/*[in]*/ double newVal);
	STDMETHOD(get_invoice)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_invoice)(/*[in]*/ long newVal);
	STDMETHOD(get_powerdown)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_powerdown)(/*[in]*/ long newVal);
	STDMETHOD(get_taxgrp5)(/*[out, retval]*/ double *pVal);
	STDMETHOD(put_taxgrp5)(/*[in]*/ double newVal);
	STDMETHOD(get_taxgrp4)(/*[out, retval]*/ double *pVal);
	STDMETHOD(put_taxgrp4)(/*[in]*/ double newVal);
	STDMETHOD(get_paid)(/*[out, retval]*/ BOOL *pVal);
	STDMETHOD(put_paid)(/*[in]*/ BOOL newVal);
	STDMETHOD(get_paystarted)(/*[out, retval]*/ BOOL *pVal);
	STDMETHOD(put_paystarted)(/*[in]*/ BOOL newVal);
	STDMETHOD(get_detailed)(/*[out, retval]*/ BOOL *pVal);
	STDMETHOD(put_detailed)(/*[in]*/ BOOL newVal);
	STDMETHOD(get_dds)(/*[out, retval]*/ BOOL *pVal);
	STDMETHOD(put_dds)(/*[in]*/ BOOL newVal);
	STDMETHOD(get_novoid)(/*[out, retval]*/ BOOL *pVal);
	STDMETHOD(put_novoid)(/*[in]*/ BOOL newVal);
	STDMETHOD(get_taxgrp3)(/*[out, retval]*/ double *pVal);
	STDMETHOD(put_taxgrp3)(/*[in]*/ double newVal);
	STDMETHOD(get_taxgrp2)(/*[out, retval]*/ double *pVal);
	STDMETHOD(put_taxgrp2)(/*[in]*/ double newVal);
	STDMETHOD(get_taxgrp1)(/*[out, retval]*/ double *pVal);
	STDMETHOD(put_taxgrp1)(/*[in]*/ double newVal);
	STDMETHOD(get_purchases)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_purchases)(/*[in]*/ long newVal);
	STDMETHOD(get_flags)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_flags)(/*[in]*/ long newVal);

protected:
	DWORD	m_flags;
	int		m_purchases;
	double	m_change;
	short   m_changeType;

	double	m_taxgrp1;
	double	m_taxgrp2;
	double	m_taxgrp3;
	double	m_taxgrp4;
	double	m_taxgrp5;
	double	m_taxgrp6;
	double	m_taxgrp7;
	double	m_taxgrp8;
	
	BOOL    m_novoid;
	BOOL    m_dds;
	BOOL    m_detailed;
	BOOL    m_paystarted;
	BOOL    m_paid;
	BOOL    m_powerdown;
	BOOL    m_invoice;
};

#endif //__GETCURRENTBONINFORES_H_
