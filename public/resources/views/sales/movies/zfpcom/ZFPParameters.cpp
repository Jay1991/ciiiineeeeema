//////////////////////////////////////////////////////////////////////
// Copyright (c) 2005 Tremol Ltd.
// License: Mozilla Public License 1.1
// Contacts: software@tremol.bg
//////////////////////////////////////////////////////////////////////
// ZFPParameters.cpp : Implementation of CZFPParameters
#include "stdafx.h"
#include "Zfpcom.h"
#include "ZFPParameters.h"

/////////////////////////////////////////////////////////////////////////////
// CZFPParameters

STDMETHODIMP CZFPParameters::get_fpnum(long *pVal)
{
	*pVal = m_fpnum;
	return S_OK;
}

STDMETHODIMP CZFPParameters::put_fpnum(long newVal)
{
	m_fpnum = newVal;
	return S_OK;
}

STDMETHODIMP CZFPParameters::get_logo(long *pVal)
{
	*pVal = m_logo;
	return S_OK;
}

STDMETHODIMP CZFPParameters::put_logo(long newVal)
{
	m_logo = newVal;
	return S_OK;
}

STDMETHODIMP CZFPParameters::get_till(long *pVal)
{
	*pVal = m_till;
	return S_OK;
}

STDMETHODIMP CZFPParameters::put_till(long newVal)
{
	m_till = newVal;
	return S_OK;
}

STDMETHODIMP CZFPParameters::get_autocut(long *pVal)
{
	*pVal = m_autocut;
	return S_OK;
}

STDMETHODIMP CZFPParameters::put_autocut(long newVal)
{
	m_autocut = newVal;
	return S_OK;
}

STDMETHODIMP CZFPParameters::get_transparent(long *pVal)
{
	*pVal = m_transparent;
	return S_OK;
}

STDMETHODIMP CZFPParameters::put_transparent(long newVal)
{
	m_transparent = newVal;
	return S_OK;
}

STDMETHODIMP CZFPParameters::get_shortEJ(long *pVal)
{
	*pVal = m_shortEJ;
	return S_OK;
}

STDMETHODIMP CZFPParameters::put_shortEJ(long newVal)
{
	m_shortEJ = newVal;
	return S_OK;
}

STDMETHODIMP CZFPParameters::get_currency(long *pVal)
{
	*pVal = m_currency;
	return S_OK;
}

STDMETHODIMP CZFPParameters::put_currency(long newVal)
{
	m_currency = newVal;
	return S_OK;
}
