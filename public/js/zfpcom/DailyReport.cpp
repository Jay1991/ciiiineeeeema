//////////////////////////////////////////////////////////////////////
// Copyright (c) 2005 Tremol Ltd.
// License: Mozilla Public License 1.1
// Contacts: software@tremol.bg
//////////////////////////////////////////////////////////////////////
// DailyReport.cpp : Implementation of CDailyReport
#include "stdafx.h"
#include "Zfpcom.h"
#include "DailyReport.h"

/////////////////////////////////////////////////////////////////////////////
// CDailyReport
STDMETHODIMP CDailyReport::get_counter(long *pVal)
{
	*pVal = m_counter;
	return S_OK;
}

STDMETHODIMP CDailyReport::put_counter(long newVal)
{
	m_counter = newVal;
	return S_OK;
}

STDMETHODIMP CDailyReport::get_lastreport(long *pVal)
{
	*pVal = m_lastreport;
	return S_OK;
}

STDMETHODIMP CDailyReport::put_lastreport(long newVal)
{
	m_lastreport = newVal;
	return S_OK;
}

STDMETHODIMP CDailyReport::get_ecl(long *pVal)
{
	*pVal = m_ecl;
	return S_OK;
}

STDMETHODIMP CDailyReport::put_ecl(long newVal)
{
	m_ecl = newVal;
	return S_OK;
}

STDMETHODIMP CDailyReport::get_datetime(DATE *pVal)
{
	*pVal = m_datetime;
	return S_OK;
}

STDMETHODIMP CDailyReport::put_datetime(DATE newVal)
{
	m_datetime = newVal;
	return S_OK;
}
