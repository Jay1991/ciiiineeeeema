//////////////////////////////////////////////////////////////////////
// Copyright (c) 2005 Tremol Ltd.
// License: Mozilla Public License 1.1
// Contacts: software@tremol.bg
//////////////////////////////////////////////////////////////////////
// GetCurrentBonInfoRes.cpp : Implementation of CGetCurrentBonInfoRes
#include "stdafx.h"
#include "Zfpcom.h"
#include "GetCurrentBonInfoRes.h"

/////////////////////////////////////////////////////////////////////////////
// CGetCurrentBonInfoRes


STDMETHODIMP CGetCurrentBonInfoRes::get_flags(long *pVal)
{
	*pVal = m_flags;
	return S_OK;
}

STDMETHODIMP CGetCurrentBonInfoRes::put_flags(long newVal)
{
	m_flags = newVal;
	return S_OK;
}

STDMETHODIMP CGetCurrentBonInfoRes::get_purchases(long *pVal)
{
	*pVal = m_purchases;
	return S_OK;
}

STDMETHODIMP CGetCurrentBonInfoRes::put_purchases(long newVal)
{
	m_purchases = newVal;
	return S_OK;
}

STDMETHODIMP CGetCurrentBonInfoRes::get_taxgrp1(double *pVal)
{
	*pVal = m_taxgrp1;
	return S_OK;
}

STDMETHODIMP CGetCurrentBonInfoRes::put_taxgrp1(double newVal)
{
	m_taxgrp1 = newVal;
	return S_OK;
}

STDMETHODIMP CGetCurrentBonInfoRes::get_taxgrp2(double *pVal)
{
	*pVal = m_taxgrp2;
	return S_OK;
}

STDMETHODIMP CGetCurrentBonInfoRes::put_taxgrp2(double newVal)
{
	m_taxgrp2 = newVal;
	return S_OK;
}

STDMETHODIMP CGetCurrentBonInfoRes::get_taxgrp3(double *pVal)
{
	*pVal = m_taxgrp3;
	return S_OK;
}

STDMETHODIMP CGetCurrentBonInfoRes::put_taxgrp3(double newVal)
{
	m_taxgrp3 = newVal;
	return S_OK;
}

STDMETHODIMP CGetCurrentBonInfoRes::get_novoid(BOOL *pVal)
{
	*pVal = m_novoid;
	return S_OK;
}

STDMETHODIMP CGetCurrentBonInfoRes::put_novoid(BOOL newVal)
{
	m_novoid = newVal;
	return S_OK;
}

STDMETHODIMP CGetCurrentBonInfoRes::get_dds(BOOL *pVal)
{
	*pVal = m_dds;
	return S_OK;
}

STDMETHODIMP CGetCurrentBonInfoRes::put_dds(BOOL newVal)
{
	m_dds = newVal;
	return S_OK;
}

STDMETHODIMP CGetCurrentBonInfoRes::get_detailed(BOOL *pVal)
{
	*pVal = m_detailed;
	return S_OK;
}

STDMETHODIMP CGetCurrentBonInfoRes::put_detailed(BOOL newVal)
{
	m_detailed = newVal;
	return S_OK;
}

STDMETHODIMP CGetCurrentBonInfoRes::get_paystarted(BOOL *pVal)
{
	*pVal = m_paystarted;
	return S_OK;
}

STDMETHODIMP CGetCurrentBonInfoRes::put_paystarted(BOOL newVal)
{
	m_paystarted = newVal;
	return S_OK;
}

STDMETHODIMP CGetCurrentBonInfoRes::get_paid(BOOL *pVal)
{
	*pVal = m_paid;
	return S_OK;
}

STDMETHODIMP CGetCurrentBonInfoRes::put_paid(BOOL newVal)
{
	m_paid = newVal;
	return S_OK;
}

STDMETHODIMP CGetCurrentBonInfoRes::get_taxgrp4(double *pVal)
{
	*pVal = m_taxgrp4;
	return S_OK;
}

STDMETHODIMP CGetCurrentBonInfoRes::put_taxgrp4(double newVal)
{
	m_taxgrp4 = newVal;
	return S_OK;
}

STDMETHODIMP CGetCurrentBonInfoRes::get_taxgrp5(double *pVal)
{
	*pVal = m_taxgrp5;
	return S_OK;
}

STDMETHODIMP CGetCurrentBonInfoRes::put_taxgrp5(double newVal)
{
	m_taxgrp5 = newVal;
	return S_OK;
}

STDMETHODIMP CGetCurrentBonInfoRes::get_powerdown(long *pVal)
{
	*pVal = m_powerdown;
	return S_OK;
}

STDMETHODIMP CGetCurrentBonInfoRes::put_powerdown(long newVal)
{
	m_powerdown = newVal;
	return S_OK;
}

STDMETHODIMP CGetCurrentBonInfoRes::get_invoice(long *pVal)
{
	*pVal = m_invoice;
	return S_OK;
}

STDMETHODIMP CGetCurrentBonInfoRes::put_invoice(long newVal)
{
	m_invoice = newVal;
	return S_OK;
}

STDMETHODIMP CGetCurrentBonInfoRes::get_taxgrp6(double *pVal)
{
	*pVal = m_taxgrp6;
	return S_OK;
}

STDMETHODIMP CGetCurrentBonInfoRes::put_taxgrp6(double newVal)
{
	m_taxgrp6 = newVal;
	return S_OK;
}

STDMETHODIMP CGetCurrentBonInfoRes::get_taxgrp7(double *pVal)
{
	*pVal = m_taxgrp7;
	return S_OK;
}

STDMETHODIMP CGetCurrentBonInfoRes::put_taxgrp7(double newVal)
{
	m_taxgrp7 = newVal;
	return S_OK;
}

STDMETHODIMP CGetCurrentBonInfoRes::get_taxgrp8(double *pVal)
{
	*pVal = m_taxgrp8;
	return S_OK;
}

STDMETHODIMP CGetCurrentBonInfoRes::put_taxgrp8(double newVal)
{
	m_taxgrp8 = newVal;
	return S_OK;
}

STDMETHODIMP CGetCurrentBonInfoRes::get_change(double *pVal)
{
	*pVal = m_change;
	return S_OK;
}

STDMETHODIMP CGetCurrentBonInfoRes::put_change(double newVal)
{
	m_change = newVal;
	return S_OK;
}

STDMETHODIMP CGetCurrentBonInfoRes::get_changeType(short *pVal)
{
	*pVal = m_changeType;
	return S_OK;
}

STDMETHODIMP CGetCurrentBonInfoRes::put_changeType(short newVal)
{
	m_changeType = newVal;
	return S_OK;
}
