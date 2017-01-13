// ReceiptStatus.cpp : Implementation of CZfpcomApp and DLL registration.

#include "stdafx.h"
#include "zfpcom.h"
#include "ReceiptStatus.h"

/////////////////////////////////////////////////////////////////////////////
//



STDMETHODIMP CReceiptStatus::get_is_sale(BYTE *pVal)
{
	*pVal = m_is_sale;

	return S_OK;
}

STDMETHODIMP CReceiptStatus::put_is_sale(BYTE newVal)
{
	m_is_sale = newVal;

	return S_OK;
}

STDMETHODIMP CReceiptStatus::get_is_open(BYTE *pVal)
{
	*pVal = m_is_open;

	return S_OK;
}

STDMETHODIMP CReceiptStatus::put_is_open(BYTE newVal)
{
	m_is_open = newVal;

	return S_OK;
}

STDMETHODIMP CReceiptStatus::get_is_payment_started(BYTE *pVal)
{
	*pVal = m_is_payment_started;

	return S_OK;
}

STDMETHODIMP CReceiptStatus::put_is_payment_started(BYTE newVal)
{
	m_is_payment_started = newVal;

	return S_OK;
}

STDMETHODIMP CReceiptStatus::get_is_payment_finished(BYTE *pVal)
{
	*pVal = m_is_payment_finished;

	return S_OK;
}

STDMETHODIMP CReceiptStatus::put_is_payment_finished(BYTE newVal)
{
	m_is_payment_finished = newVal;

	return S_OK;
}

STDMETHODIMP CReceiptStatus::get_has_power_interrupted(BYTE *pVal)
{
	*pVal = m_has_power_interrupted;

	return S_OK;
}

STDMETHODIMP CReceiptStatus::put_has_power_interrupted(BYTE newVal)
{
	m_has_power_interrupted = newVal;

	return S_OK;
}

STDMETHODIMP CReceiptStatus::get_transactions_count(int *pVal)
{
	*pVal = m_transactions_count;

	return S_OK;
}

STDMETHODIMP CReceiptStatus::put_transactions_count(int newVal)
{
	m_transactions_count = newVal;

	return S_OK;
}

STDMETHODIMP CReceiptStatus::get_taxgroup_subtotal_amount(double *pVal)
{
	*pVal = m_taxgroup_subtotal_amount;

	return S_OK;
}

STDMETHODIMP CReceiptStatus::put_taxgroup_subtotal_amount(double newVal)
{
	m_taxgroup_subtotal_amount = newVal;

	return S_OK;
}

STDMETHODIMP CReceiptStatus::get_change_amount(double *pVal)
{
	*pVal = m_change_amount;

	return S_OK;
}

STDMETHODIMP CReceiptStatus::put_change_amount(double newVal)
{
	m_change_amount = newVal;

	return S_OK;
}
