//////////////////////////////////////////////////////////////////////
// Copyright (c) 2005 Tremol Ltd.
// License: Mozilla Public License 1.1
// Contacts: software@tremol.bg
//////////////////////////////////////////////////////////////////////
// PayTypes.cpp : Implementation of CPayTypes
#include "stdafx.h"
#include "Zfpcom.h"
#include "PayTypes.h"

/////////////////////////////////////////////////////////////////////////////
// CPayTypes

STDMETHODIMP CPayTypes::get_paytype1(BSTR *pVal)
{
	*pVal = m_pt1.Copy();
	return S_OK;
}

STDMETHODIMP CPayTypes::put_paytype1(BSTR newVal)
{
	m_pt1 = newVal;
	return S_OK;
}

STDMETHODIMP CPayTypes::get_paytype2(BSTR *pVal)
{
	*pVal = m_pt2.Copy();
	return S_OK;
}

STDMETHODIMP CPayTypes::put_paytype2(BSTR newVal)
{
	m_pt2 = newVal;
	return S_OK;
}

STDMETHODIMP CPayTypes::get_paytype3(BSTR *pVal)
{
	*pVal = m_pt3.Copy();
	return S_OK;
}

STDMETHODIMP CPayTypes::put_paytype3(BSTR newVal)
{
	m_pt3 = newVal;
	return S_OK;
}

STDMETHODIMP CPayTypes::get_paytype4(BSTR *pVal)
{
	*pVal = m_pt4.Copy();
	return S_OK;
}

STDMETHODIMP CPayTypes::put_paytype4(BSTR newVal)
{
	m_pt4 = newVal;
	return S_OK;
}

STDMETHODIMP CPayTypes::get_paytype0(BSTR *pVal)
{
	*pVal = m_pt0.Copy();
	return S_OK;
}

STDMETHODIMP CPayTypes::put_paytype0(BSTR newVal)
{
	m_pt0 = newVal;
	return S_OK;
}

STDMETHODIMP CPayTypes::get_paytype1sum(double *pVal)
{
	*pVal = m_pt1sum;
	return S_OK;
}

STDMETHODIMP CPayTypes::put_paytype1sum(double newVal)
{
	m_pt1sum = newVal;
	return S_OK;
}

STDMETHODIMP CPayTypes::get_paytype2sum(double *pVal)
{
	*pVal = m_pt2sum;
	return S_OK;
}

STDMETHODIMP CPayTypes::put_paytype2sum(double newVal)
{
	m_pt2sum = newVal;
	return S_OK;
}

STDMETHODIMP CPayTypes::get_paytype3sum(double *pVal)
{
	*pVal = m_pt3sum;
	return S_OK;
}

STDMETHODIMP CPayTypes::put_paytype3sum(double newVal)
{
	m_pt3sum = newVal;
	return S_OK;
}

STDMETHODIMP CPayTypes::get_paytype4sum(double *pVal)
{
	*pVal = m_pt4sum;
	return S_OK;
}

STDMETHODIMP CPayTypes::put_paytype4sum(double newVal)
{
	m_pt4sum = newVal;
	return S_OK;
}

STDMETHODIMP CPayTypes::get_paytype0sum(double *pVal)
{
	*pVal = m_pt0sum;
	return S_OK;
}

STDMETHODIMP CPayTypes::put_paytype0sum(double newVal)
{
	m_pt0sum = newVal;
	return S_OK;
}

STDMETHODIMP CPayTypes::get_operations(long *pVal)
{
	*pVal = m_operations;
	return S_OK;
}

STDMETHODIMP CPayTypes::put_operations(long newVal)
{
	m_operations = newVal;
	return S_OK;
}

STDMETHODIMP CPayTypes::get_exchRate(double *pVal)
{
	*pVal = m_exchRate;
	return S_OK;
}

STDMETHODIMP CPayTypes::put_exchRate(double newVal)
{
	m_exchRate = newVal;
	return S_OK;
}
