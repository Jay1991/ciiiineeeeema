// InvoiceNumbers.cpp : Implementation of CInvoiceNumbers
#include "stdafx.h"
#include "Zfpcom.h"
#include "InvoiceNumbers.h"

/////////////////////////////////////////////////////////////////////////////
// CInvoiceNumbers


STDMETHODIMP CInvoiceNumbers::get_nextNum(BSTR *pVal)
{
	*pVal = m_nextNum.Copy();
	return S_OK;
}

STDMETHODIMP CInvoiceNumbers::put_nextNum(BSTR newVal)
{
	m_nextNum = newVal;
	return S_OK;
}

STDMETHODIMP CInvoiceNumbers::get_lastNum(BSTR *pVal)
{
	*pVal = m_lastNum.Copy();
	return S_OK;
}

STDMETHODIMP CInvoiceNumbers::put_lastNum(BSTR newVal)
{
	m_lastNum = newVal;
	return S_OK;
}
