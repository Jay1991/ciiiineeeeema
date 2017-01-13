//////////////////////////////////////////////////////////////////////
// Copyright (c) 2005 Tremol Ltd.
// License: Mozilla Public License 1.1
// Contacts: software@tremol.bg
//////////////////////////////////////////////////////////////////////
// ArticleInfo.h : Declaration of the CArticleInfo

#ifndef __ARTICLEINFO_H_
#define __ARTICLEINFO_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CArticleInfo
class ATL_NO_VTABLE CArticleInfo : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CArticleInfo, &CLSID_ArticleInfo>,
	public IDispatchImpl<IArticleInfo, &IID_IArticleInfo, &LIBID_ZFPCOMLib>
{
public:
	CArticleInfo()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_ARTICLEINFO)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CArticleInfo)
	COM_INTERFACE_ENTRY(IArticleInfo)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IArticleInfo
public:
	STDMETHOD(get_quantity)(/*[out, retval]*/ double *pVal);
	STDMETHOD(put_quantity)(/*[in]*/ double newVal);
	STDMETHOD(get_department)(/*[out, retval]*/ short *pVal);
	STDMETHOD(put_department)(/*[in]*/ short newVal);
	STDMETHOD(get_reportdate)(/*[out, retval]*/ DATE *pVal);
	STDMETHOD(put_reportdate)(/*[in]*/ DATE newVal);
	STDMETHOD(get_counter)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_counter)(/*[in]*/ long newVal);
	STDMETHOD(get_sells)(/*[out, retval]*/ double *pVal);
	STDMETHOD(put_sells)(/*[in]*/ double newVal);
	STDMETHOD(get_turnover)(/*[out, retval]*/ double *pVal);
	STDMETHOD(put_turnover)(/*[in]*/ double newVal);
	STDMETHOD(get_taxgroup)(/*[out, retval]*/ short *pVal);
	STDMETHOD(put_taxgroup)(/*[in]*/ short newVal);
	STDMETHOD(get_price)(/*[out, retval]*/ double *pVal);
	STDMETHOD(put_price)(/*[in]*/ double newVal);
	STDMETHOD(get_name)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(put_name)(/*[in]*/ BSTR newVal);

protected:
	CComBSTR m_name;
	double m_price;
	double m_turnover;
	double m_sells;
	double m_quantity;
	short m_taxgroup;
	short m_department;
	long  m_counter;
	DATE  m_reportdate;
};

#endif //__ARTICLEINFO_H_
