// CurrencyInfo.h: Definition of the CCurrencyInfo class
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CURRENCYINFO_H__2B501125_9F92_461B_896D_869E9A8FCEA9__INCLUDED_)
#define AFX_CURRENCYINFO_H__2B501125_9F92_461B_896D_869E9A8FCEA9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CCurrencyInfo

class CCurrencyInfo : 
	public IDispatchImpl<ICurrencyInfo, &IID_ICurrencyInfo, &LIBID_ZFPCOMLib>, 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CCurrencyInfo,&CLSID_CurrencyInfo>
{
public:
	CCurrencyInfo() {}
BEGIN_COM_MAP(CCurrencyInfo)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ICurrencyInfo)
END_COM_MAP()
//DECLARE_NOT_AGGREGATABLE(CCurrencyInfo) 
// Remove the comment from the line above if you don't want your object to 
// support aggregation. 

DECLARE_REGISTRY_RESOURCEID(IDR_CurrencyInfo)
// ISupportsErrorInfo

// ICurrencyInfo
public:
	STDMETHOD(get_amount_out)(/*[out, retval]*/ double *pVal);
	STDMETHOD(put_amount_out)(/*[in]*/ double newVal);
	STDMETHOD(get_amount_in)(/*[out, retval]*/ double *pVal);
	STDMETHOD(put_amount_in)(/*[in]*/ double newVal);
	STDMETHOD(get_amount_sold)(/*[out, retval]*/ double *pVal);
	STDMETHOD(put_amount_sold)(/*[in]*/ double newVal);
	STDMETHOD(get_amount_bought)(/*[out, retval]*/ double *pVal);
	STDMETHOD(put_amount_bought)(/*[in]*/ double newVal);
	STDMETHOD(get_amount_available)(/*[out, retval]*/ double *pVal);
	STDMETHOD(put_amount_available)(/*[in]*/ double newVal);
	STDMETHOD(get_price_central_bank)(/*[out, retval]*/ double *pVal);
	STDMETHOD(put_price_central_bank)(/*[in]*/ double newVal);
	STDMETHOD(get_price_sell)(/*[out, retval]*/ double *pVal);
	STDMETHOD(put_price_sell)(/*[in]*/ double newVal);
	STDMETHOD(get_price_buy)(/*[out, retval]*/ double *pVal);
	STDMETHOD(put_price_buy)(/*[in]*/ double newVal);
protected:
	double m_price_buy;
	double m_price_sell;
	double m_price_central_bank;
	double m_amount_available;
	double m_amount_bought;
	double m_amount_sold;
	double m_amount_in;
	double m_amount_out;
};

#endif // !defined(AFX_CURRENCYINFO_H__2B501125_9F92_461B_896D_869E9A8FCEA9__INCLUDED_)
