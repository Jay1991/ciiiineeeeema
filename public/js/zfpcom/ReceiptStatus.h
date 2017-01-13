// ReceiptStatus.h: Definition of the CReceiptStatus class
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RECEIPTSTATUS_H__43F5936D_E989_43FC_A496_8E0073DD083F__INCLUDED_)
#define AFX_RECEIPTSTATUS_H__43F5936D_E989_43FC_A496_8E0073DD083F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CReceiptStatus

class CReceiptStatus : 
	public IDispatchImpl<IReceiptStatus, &IID_IReceiptStatus, &LIBID_ZFPCOMLib>, 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CReceiptStatus,&CLSID_ReceiptStatus>
{
public:
	CReceiptStatus() {}
BEGIN_COM_MAP(CReceiptStatus)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IReceiptStatus)
END_COM_MAP()
//DECLARE_NOT_AGGREGATABLE(CReceiptStatus) 
// Remove the comment from the line above if you don't want your object to 
// support aggregation. 

DECLARE_REGISTRY_RESOURCEID(IDR_ReceiptStatus)
// ISupportsErrorInfo

// IReceiptStatus
public:
	STDMETHOD(get_change_amount)(/*[out, retval]*/ double *pVal);
	STDMETHOD(put_change_amount)(/*[in]*/ double newVal);
	STDMETHOD(get_taxgroup_subtotal_amount)(/*[out, retval]*/ double *pVal);
	STDMETHOD(put_taxgroup_subtotal_amount)(/*[in]*/ double newVal);
	STDMETHOD(get_transactions_count)(/*[out, retval]*/ int *pVal);
	STDMETHOD(put_transactions_count)(/*[in]*/ int newVal);
	STDMETHOD(get_has_power_interrupted)(/*[out, retval]*/ BYTE *pVal);
	STDMETHOD(put_has_power_interrupted)(/*[in]*/ BYTE newVal);
	STDMETHOD(get_is_payment_finished)(/*[out, retval]*/ BYTE *pVal);
	STDMETHOD(put_is_payment_finished)(/*[in]*/ BYTE newVal);
	STDMETHOD(get_is_payment_started)(/*[out, retval]*/ BYTE *pVal);
	STDMETHOD(put_is_payment_started)(/*[in]*/ BYTE newVal);
	STDMETHOD(get_is_open)(/*[out, retval]*/ BYTE *pVal);
	STDMETHOD(put_is_open)(/*[in]*/ BYTE newVal);
	STDMETHOD(get_is_sale)(/*[out, retval]*/ BYTE *pVal);
	STDMETHOD(put_is_sale)(/*[in]*/ BYTE newVal);
protected:
	BYTE m_is_open;
	BYTE m_is_sale;
	BYTE m_is_payment_started;
	BYTE m_is_payment_finished;
	BYTE m_has_power_interrupted;
	int  m_transactions_count;
	double m_taxgroup_subtotal_amount;
	double m_change_amount;
};

#endif // !defined(AFX_RECEIPTSTATUS_H__43F5936D_E989_43FC_A496_8E0073DD083F__INCLUDED_)
