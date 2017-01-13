//////////////////////////////////////////////////////////////////////
// Copyright (c) 2005 Tremol Ltd.
// License: Mozilla Public License 1.1
// Contacts: software@tremol.bg
//////////////////////////////////////////////////////////////////////
// DailySums.cpp : Implementation of CDailySums
#include "stdafx.h"
#include "Zfpcom.h"
#include "DailySums.h"

/////////////////////////////////////////////////////////////////////////////
// CDailySums

STDMETHODIMP CDailySums::get_clients(long *pVal)
{
	*pVal = m_clients;
	return S_OK;
}

STDMETHODIMP CDailySums::put_clients(long newVal)
{
	m_clients = newVal;
	return S_OK;
}

STDMETHODIMP CDailySums::get_discounts(long *pVal)
{
	*pVal = m_discounts;
	return S_OK;
}

STDMETHODIMP CDailySums::put_discounts(long newVal)
{
	m_discounts = newVal;
	return S_OK;
}

STDMETHODIMP CDailySums::get_sumdiscount(double *pVal)
{
	*pVal = m_sumdiscount;
	return S_OK;
}

STDMETHODIMP CDailySums::put_sumdiscount(double newVal)
{
	m_sumdiscount = newVal;
	return S_OK;
}

STDMETHODIMP CDailySums::get_adding(long *pVal)
{
	*pVal = m_adding;
	return S_OK;
}

STDMETHODIMP CDailySums::put_adding(long newVal)
{
	m_adding = newVal;
	return S_OK;
}

STDMETHODIMP CDailySums::get_sumadding(double *pVal)
{
	*pVal = m_sumadding;
	return S_OK;
}

STDMETHODIMP CDailySums::put_sumadding(double newVal)
{
	m_sumadding = newVal;
	return S_OK;
}

STDMETHODIMP CDailySums::get_voids(long *pVal)
{
	*pVal = m_voids;
	return S_OK;
}

STDMETHODIMP CDailySums::put_voids(long newVal)
{
	m_voids = newVal;
	return S_OK;
}

STDMETHODIMP CDailySums::get_sumvoids(double *pVal)
{
	*pVal = m_sumvoids;
	return S_OK;
}

STDMETHODIMP CDailySums::put_sumvoids(double newVal)
{
	m_sumvoids = newVal;
	return S_OK;
}
