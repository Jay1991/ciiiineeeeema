// CurrencyInfo.cpp : Implementation of CZfpcomApp and DLL registration.

#include "stdafx.h"
#include "zfpcom.h"
#include "CurrencyInfo.h"

/////////////////////////////////////////////////////////////////////////////
//

STDMETHODIMP CCurrencyInfo::get_price_buy(double *pVal)
{
	*pVal = m_price_buy;

	return S_OK;
}

STDMETHODIMP CCurrencyInfo::put_price_buy(double newVal)
{
	m_price_buy = newVal;

	return S_OK;
}

STDMETHODIMP CCurrencyInfo::get_price_sell(double *pVal)
{
	*pVal = m_price_sell;

	return S_OK;
}

STDMETHODIMP CCurrencyInfo::put_price_sell(double newVal)
{
	m_price_sell = newVal;

	return S_OK;
}

STDMETHODIMP CCurrencyInfo::get_price_central_bank(double *pVal)
{
	*pVal = m_price_central_bank;

	return S_OK;
}

STDMETHODIMP CCurrencyInfo::put_price_central_bank(double newVal)
{
	m_price_central_bank = newVal;

	return S_OK;
}

STDMETHODIMP CCurrencyInfo::get_amount_available(double *pVal)
{
	*pVal = m_amount_available;

	return S_OK;
}

STDMETHODIMP CCurrencyInfo::put_amount_available(double newVal)
{
	m_amount_available = newVal;

	return S_OK;
}

STDMETHODIMP CCurrencyInfo::get_amount_bought(double *pVal)
{
	*pVal = m_amount_bought;

	return S_OK;
}

STDMETHODIMP CCurrencyInfo::put_amount_bought(double newVal)
{
	m_amount_bought = newVal;

	return S_OK;
}

STDMETHODIMP CCurrencyInfo::get_amount_sold(double *pVal)
{
	*pVal = m_amount_sold;

	return S_OK;
}

STDMETHODIMP CCurrencyInfo::put_amount_sold(double newVal)
{
	m_amount_sold = newVal;

	return S_OK;
}

STDMETHODIMP CCurrencyInfo::get_amount_in(double *pVal)
{
	*pVal = m_amount_in;

	return S_OK;
}

STDMETHODIMP CCurrencyInfo::put_amount_in(double newVal)
{
	m_amount_in = newVal;

	return S_OK;
}

STDMETHODIMP CCurrencyInfo::get_amount_out(double *pVal)
{
	*pVal = m_amount_out;

	return S_OK;
}

STDMETHODIMP CCurrencyInfo::put_amount_out(double newVal)
{
	m_amount_out = newVal;

	return S_OK;
}
