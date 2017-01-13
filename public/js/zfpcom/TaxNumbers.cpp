//////////////////////////////////////////////////////////////////////
// Copyright (c) 2005 Tremol Ltd.
// License: Mozilla Public License 1.1
// Contacts: software@tremol.bg
//////////////////////////////////////////////////////////////////////
// TaxNumbers.cpp : Implementation of CTaxNumbers
#include "stdafx.h"
#include "Zfpcom.h"
#include "TaxNumbers.h"

/////////////////////////////////////////////////////////////////////////////
// CTaxNumbers


STDMETHODIMP CTaxNumbers::get_taxgrp1(double *pVal)
{
	*pVal = m_taxGrp1;
	return S_OK;
}

STDMETHODIMP CTaxNumbers::put_taxgrp1(double newVal)
{
	m_taxGrp1 = newVal;
	return S_OK;
}

STDMETHODIMP CTaxNumbers::get_taxgrp2(double *pVal)
{
	*pVal = m_taxGrp2;
	return S_OK;
}

STDMETHODIMP CTaxNumbers::put_taxgrp2(double newVal)
{
	m_taxGrp2 = newVal;
	return S_OK;
}

STDMETHODIMP CTaxNumbers::get_taxgrp3(double *pVal)
{
	*pVal = m_taxGrp3;
	return S_OK;
}

STDMETHODIMP CTaxNumbers::put_taxgrp3(double newVal)
{
	m_taxGrp3 = newVal;
	return S_OK;
}

STDMETHODIMP CTaxNumbers::get_taxgrp4(double *pVal)
{
	*pVal = m_taxGrp4;
	return S_OK;
}

STDMETHODIMP CTaxNumbers::put_taxgrp4(double newVal)
{
	m_taxGrp4 = newVal;
	return S_OK;
}

STDMETHODIMP CTaxNumbers::get_taxgrp5(double *pVal)
{
	*pVal = m_taxGrp5;
	return S_OK;
}

STDMETHODIMP CTaxNumbers::put_taxgrp5(double newVal)
{
	m_taxGrp5 = newVal;
	return S_OK;
}

STDMETHODIMP CTaxNumbers::get_taxgrp6(double *pVal)
{
	*pVal = m_taxGrp6;
	return S_OK;
}

STDMETHODIMP CTaxNumbers::put_taxgrp6(double newVal)
{
	m_taxGrp6 = newVal;
	return S_OK;
}

STDMETHODIMP CTaxNumbers::get_taxgrp7(double *pVal)
{
	*pVal = m_taxGrp7;
	return S_OK;
}

STDMETHODIMP CTaxNumbers::put_taxgrp7(double newVal)
{
	m_taxGrp7 = newVal;
	return S_OK;
}

STDMETHODIMP CTaxNumbers::get_taxgrp8(double *pVal)
{
	*pVal = m_taxGrp8;
	return S_OK;
}

STDMETHODIMP CTaxNumbers::put_taxgrp8(double newVal)
{
	m_taxGrp8 = newVal;
	return S_OK;
}
