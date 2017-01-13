//////////////////////////////////////////////////////////////////////
// Copyright (c) 2005 Tremol Ltd.
// License: Mozilla Public License 1.1
// Contacts: software@tremol.bg
//////////////////////////////////////////////////////////////////////
// OperatorInfo.cpp : Implementation of COperatorInfo
#include "stdafx.h"
#include "Zfpcom.h"
#include "OperatorInfo.h"

/////////////////////////////////////////////////////////////////////////////
// COperatorInfo

STDMETHODIMP COperatorInfo::get_name(BSTR *pVal)
{
	*pVal = m_name.Copy();
	return S_OK;
}

STDMETHODIMP COperatorInfo::put_name(BSTR newVal)
{
	m_name = newVal;
	return S_OK;
}

STDMETHODIMP COperatorInfo::get_passwd(BSTR *pVal)
{
	*pVal = m_passwd.Copy();
	return S_OK;
}

STDMETHODIMP COperatorInfo::put_passwd(BSTR newVal)
{
	m_passwd = newVal;
	return S_OK;
}
