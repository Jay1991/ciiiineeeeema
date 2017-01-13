//////////////////////////////////////////////////////////////////////
// Copyright (c) 2005 Tremol Ltd.
// License: Mozilla Public License 1.1
// Contacts: software@tremol.bg
//////////////////////////////////////////////////////////////////////
// FiscalReportData.cpp : Implementation of CFiscalReportData
#include "stdafx.h"
#include "Zfpcom.h"
#include "FiscalReportData.h"

/////////////////////////////////////////////////////////////////////////////
// CFiscalReportData

STDMETHODIMP CFiscalReportData::get_reportdate(DATE *pVal)
{
	*pVal = m_reportdate;
	return S_OK;
}

STDMETHODIMP CFiscalReportData::put_reportdate(DATE newVal)
{
	m_reportdate = newVal;
	return S_OK;
}

STDMETHODIMP CFiscalReportData::get_lastreport(long *pVal)
{
	*pVal = m_lastreport;
	return S_OK;
}

STDMETHODIMP CFiscalReportData::put_lastreport(long newVal)
{
	m_lastreport = newVal;
	return S_OK;
}

STDMETHODIMP CFiscalReportData::get_lastzeroram(long *pVal)
{
	*pVal = m_lastzeroram;
	return S_OK;
}

STDMETHODIMP CFiscalReportData::put_lastzeroram(long newVal)
{
	m_lastzeroram = newVal;
	return S_OK;
}
