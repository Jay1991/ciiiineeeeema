//////////////////////////////////////////////////////////////////////
// Copyright (c) 2005-2006 Tremol Ltd.
// License: Mozilla Public License 1.1
// Contacts: software@tremol.bg
//////////////////////////////////////////////////////////////////////
// ZFPStatus.cpp : Implementation of CZFPStatus
#include "stdafx.h"
#include "Zfpcom.h"
#include "ZFPStatus.h"

/////////////////////////////////////////////////////////////////////////////
// CZFPStatus


STDMETHODIMP CZFPStatus::get_ST0(BYTE *pVal)
{
	*pVal = m_st0;
	return S_OK;
}

STDMETHODIMP CZFPStatus::put_ST0(BYTE newVal)
{
	m_st0 = newVal;
	return S_OK;
}

STDMETHODIMP CZFPStatus::get_ST1(BYTE *pVal)
{
	*pVal = m_st1;
	return S_OK;
}

STDMETHODIMP CZFPStatus::put_ST1(BYTE newVal)
{
	m_st1 = newVal;
	return S_OK;
}

STDMETHODIMP CZFPStatus::get_ST2(BYTE *pVal)
{
	*pVal = m_st2;
	return S_OK;
}

STDMETHODIMP CZFPStatus::put_ST2(BYTE newVal)
{
	m_st2 = newVal;
	return S_OK;
}

STDMETHODIMP CZFPStatus::get_ST3(BYTE *pVal)
{
	*pVal = m_st3;
	return S_OK;
}

STDMETHODIMP CZFPStatus::put_ST3(BYTE newVal)
{
	m_st3 = newVal;
	return S_OK;
}

STDMETHODIMP CZFPStatus::get_ST4(BYTE *pVal)
{
	*pVal = m_st4;
	return S_OK;
}

STDMETHODIMP CZFPStatus::put_ST4(BYTE newVal)
{
	m_st4 = newVal;
	return S_OK;
}

STDMETHODIMP CZFPStatus::get_readOnlyFM(BOOL *pVal)
{
	(m_st0 & 0x01) ? *pVal = TRUE : *pVal = FALSE;
	return S_OK;
}

STDMETHODIMP CZFPStatus::get_powerDown(BOOL *pVal)
{
	(m_st0 & 0x02) ? *pVal = TRUE : *pVal = FALSE;
	return S_OK;
}

STDMETHODIMP CZFPStatus::get_printerOverheat(BOOL *pVal)
{
	(m_st0 & 0x04) ? *pVal = TRUE : *pVal = FALSE;
	return S_OK;
}

STDMETHODIMP CZFPStatus::get_wrongTimer(BOOL *pVal)
{
	(m_st0 & 0x08) ? *pVal = TRUE : *pVal = FALSE;
	return S_OK;
}

STDMETHODIMP CZFPStatus::get_wrongDate(BOOL *pVal)
{
	(m_st0 & 0x10) ? *pVal = TRUE : *pVal = FALSE;
	return S_OK;
}

STDMETHODIMP CZFPStatus::get_wrongRAM(BOOL *pVal)
{
	(m_st0 & 0x20) ? *pVal = TRUE : *pVal = FALSE;
	return S_OK;
}

STDMETHODIMP CZFPStatus::get_clockHardwareError(BOOL *pVal)
{
	(m_st0 & 0x40) ? *pVal = TRUE : *pVal = FALSE;
	return S_OK;
}

STDMETHODIMP CZFPStatus::get_paperOutPrinterError(BOOL *pVal)
{
	(m_st1 & 0x01) ? *pVal = TRUE : *pVal = FALSE;
	return S_OK;
}

STDMETHODIMP CZFPStatus::get_reportSumOverflow(BOOL *pVal)
{
	(m_st1 & 0x02) ? *pVal = TRUE : *pVal = FALSE;
	return S_OK;
}

STDMETHODIMP CZFPStatus::get_Blocked24HoursReport(BOOL *pVal)
{
	(m_st1 & 0x04) ? *pVal = TRUE : *pVal = FALSE;
	return S_OK;
}

STDMETHODIMP CZFPStatus::get_nonzeroDailyReport(BOOL *pVal)
{
	(m_st1 & 0x08) ? *pVal = TRUE : *pVal = FALSE;
	return S_OK;
}

STDMETHODIMP CZFPStatus::get_nonzeroArticleReport(BOOL *pVal)
{
	(m_st1 & 0x10) ? *pVal = TRUE : *pVal = FALSE;
	return S_OK;
}

STDMETHODIMP CZFPStatus::get_nonzeroOperatorReport(BOOL *pVal)
{
	(m_st1 & 0x20) ? *pVal = TRUE : *pVal = FALSE;
	return S_OK;
}

STDMETHODIMP CZFPStatus::get_duplicateNotPrinted(BOOL *pVal)
{
	(m_st1 & 0x40) ? *pVal = TRUE : *pVal = FALSE;
	return S_OK;
}

STDMETHODIMP CZFPStatus::get_openOfficialBon(BOOL *pVal)
{
	(m_st2 & 0x01) ? *pVal = TRUE : *pVal = FALSE;
	return S_OK;
}

STDMETHODIMP CZFPStatus::get_OpenFiscalBon(BOOL *pVal)
{
	(m_st2 & 0x02) ? *pVal = TRUE : *pVal = FALSE;
	return S_OK;
}

STDMETHODIMP CZFPStatus::get_detailedInfo(BOOL *pVal)
{
	(m_st2 & 0x04) ? *pVal = TRUE : *pVal = FALSE;
	return S_OK;
}

STDMETHODIMP CZFPStatus::get_VATinfo(BOOL *pVal)
{
	(m_st2 & 0x08) ? *pVal = TRUE : *pVal = FALSE;
	return S_OK;
}

STDMETHODIMP CZFPStatus::get_missingFiscalMemory(BOOL *pVal)
{
	(m_st3 & 0x01) ? *pVal = TRUE : *pVal = FALSE;
	return S_OK;
}

STDMETHODIMP CZFPStatus::get_wrongFiscalMemory(BOOL *pVal)
{
	(m_st3 & 0x02) ? *pVal = TRUE : *pVal = FALSE;
	return S_OK;
}

STDMETHODIMP CZFPStatus::get_fullFiscalMemory(BOOL *pVal)
{
	(m_st3 & 0x04) ? *pVal = TRUE : *pVal = FALSE;
	return S_OK;
}

STDMETHODIMP CZFPStatus::get_fiscalMemoryLimitNear(BOOL *pVal)
{
	(m_st3 & 0x08) ? *pVal = TRUE : *pVal = FALSE;
	return S_OK;
}

STDMETHODIMP CZFPStatus::get_hasDecimalPoint(BOOL *pVal)
{
	(m_st3 & 0x10) ? *pVal = TRUE : *pVal = FALSE;
	return S_OK;
}

STDMETHODIMP CZFPStatus::get_isFiscal(BOOL *pVal)
{
	(m_st3 & 0x20) ? *pVal = TRUE : *pVal = FALSE;
	return S_OK;
}

STDMETHODIMP CZFPStatus::get_hasFiscalAndFactoryNum(BOOL *pVal)
{
	(m_st3 & 0x40) ? *pVal = TRUE : *pVal = FALSE;
	return S_OK;
}

STDMETHODIMP CZFPStatus::get_autoCutter(BOOL *pVal)
{
	(m_st4 & 0x01) ? *pVal = TRUE : *pVal = FALSE;
	return S_OK;
}

STDMETHODIMP CZFPStatus::get_hasTransparentDisplay(BOOL *pVal)
{
	(m_st4 & 0x02) ? *pVal = TRUE : *pVal = FALSE;
	return S_OK;
}

STDMETHODIMP CZFPStatus::get_baud9600(BOOL *pVal)
{
	(m_st4 & 0x04) ? *pVal = TRUE : *pVal = FALSE;
	return S_OK;
}

STDMETHODIMP CZFPStatus::get_autoTillOpen(BOOL *pVal)
{
	(m_st4 & 0x10) ? *pVal = TRUE : *pVal = FALSE;
	return S_OK;
}

STDMETHODIMP CZFPStatus::get_printLogo(BOOL *pVal)
{
	(m_st4 & 0x20) ? *pVal = TRUE : *pVal = FALSE;
	return S_OK;
}

STDMETHODIMP CZFPStatus::get_missingDisplay(BOOL *pVal)
{
	(m_st4 & 0x08) ? *pVal = TRUE : *pVal = FALSE;
	return S_OK;
}

STDMETHODIMP CZFPStatus::get_shortEJMode(BOOL *pVal)
{
	(m_st4 & 0x08) ? *pVal = TRUE : *pVal = FALSE;
	return S_OK;
}

STDMETHODIMP CZFPStatus::get_EJLimitNear(BOOL *pVal)
{
	(m_st2 & 0x20) ? *pVal = TRUE : *pVal = FALSE;
	return S_OK;
}

STDMETHODIMP CZFPStatus::get_fullEJ(BOOL *pVal)
{
	(m_st2 & 0x40) ? *pVal = TRUE : *pVal = FALSE;
	return S_OK;
}

STDMETHODIMP CZFPStatus::get_printCurrency(BOOL *pVal)
{
	(m_st4 & 0x40) ? *pVal = TRUE : *pVal = FALSE;
	return S_OK;
}
