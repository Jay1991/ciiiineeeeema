//////////////////////////////////////////////////////////////////////
// Copyright (c) 2005 Tremol Ltd.
// License: Mozilla Public License 1.1
// Contacts: software@tremol.bg
//////////////////////////////////////////////////////////////////////
// ArticleInfo.cpp : Implementation of CArticleInfo
#include "stdafx.h"
#include "Zfpcom.h"
#include "ComTools.h"
#include "ArticleInfo.h"

/////////////////////////////////////////////////////////////////////////////
// CArticleInfo

STDMETHODIMP CArticleInfo::get_name(BSTR *pVal)
{
	*pVal = m_name.Copy();
	return S_OK;
}

STDMETHODIMP CArticleInfo::put_name(BSTR newVal)
{
	m_name = newVal;
	return S_OK;
}

STDMETHODIMP CArticleInfo::get_price(double *pVal)
{
	*pVal = m_price;
	return S_OK;
}

STDMETHODIMP CArticleInfo::put_price(double newVal)
{
	m_price = newVal;
	return S_OK;
}

STDMETHODIMP CArticleInfo::get_taxgroup(short *pVal)
{
	*pVal = m_taxgroup;
	return S_OK;
}

STDMETHODIMP CArticleInfo::put_taxgroup(short newVal)
{
	m_taxgroup = newVal;
	return S_OK;
}

STDMETHODIMP CArticleInfo::get_turnover(double *pVal)
{
	*pVal = m_turnover;
	return S_OK;
}

STDMETHODIMP CArticleInfo::put_turnover(double newVal)
{
	m_turnover = newVal;
	return S_OK;
}

STDMETHODIMP CArticleInfo::get_sells(double *pVal)
{
	*pVal = m_sells;
	return S_OK;
}

STDMETHODIMP CArticleInfo::put_sells(double newVal)
{
	m_sells = newVal;
	return S_OK;
}

STDMETHODIMP CArticleInfo::get_counter(long *pVal)
{
	*pVal = m_counter;
	return S_OK;
}

STDMETHODIMP CArticleInfo::put_counter(long newVal)
{
	m_counter = newVal;
	return S_OK;
}

STDMETHODIMP CArticleInfo::get_reportdate(DATE *pVal)
{
	*pVal = m_reportdate;
	return S_OK;
}

STDMETHODIMP CArticleInfo::put_reportdate(DATE newVal)
{
	m_reportdate = newVal;
	return S_OK;
}

STDMETHODIMP CArticleInfo::get_department(short *pVal)
{
	*pVal = m_department;
	return S_OK;
}

STDMETHODIMP CArticleInfo::put_department(short newVal)
{
	m_department = newVal;
	return S_OK;
}

STDMETHODIMP CArticleInfo::get_quantity(double *pVal)
{
	*pVal = m_quantity;
	return S_OK;
}

STDMETHODIMP CArticleInfo::put_quantity(double newVal)
{
	m_quantity = newVal;
	return S_OK;
}
