// InvoiceNumbers.h : Declaration of the CInvoiceNumbers

#ifndef __INVOICENUMBERS_H_
#define __INVOICENUMBERS_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CInvoiceNumbers
class ATL_NO_VTABLE CInvoiceNumbers : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CInvoiceNumbers, &CLSID_InvoiceNumbers>,
	public IDispatchImpl<IInvoiceNumbers, &IID_IInvoiceNumbers, &LIBID_ZFPCOMLib>
{
public:
	CInvoiceNumbers()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_INVOICENUMBERS)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CInvoiceNumbers)
	COM_INTERFACE_ENTRY(IInvoiceNumbers)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IInvoiceNumbers
public:
	STDMETHOD(get_lastNum)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(put_lastNum)(/*[in]*/ BSTR newVal);
	STDMETHOD(get_nextNum)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(put_nextNum)(/*[in]*/ BSTR newVal);

protected:
	CComBSTR m_lastNum;
	CComBSTR m_nextNum;
	
};

#endif //__INVOICENUMBERS_H_
