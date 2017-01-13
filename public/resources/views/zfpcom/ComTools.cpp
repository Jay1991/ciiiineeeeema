//////////////////////////////////////////////////////////////////////
// Copyright (c) 2005 Tremol Ltd.
// License: Mozilla Public License 1.1
// Contacts: software@tremol.bg
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <math.h>
#include "ComTools.h"

BOOL MyOleDateFromTm(WORD wYear, WORD wMonth, WORD wDay,
	WORD wHour, WORD wMinute, WORD wSecond, DATE& dtDest)
{
	UDATE dt;
	dt.st.wYear = wYear;
	dt.st.wMonth = wMonth;
	dt.st.wDay = wDay;
	dt.st.wHour = wHour;
	dt.st.wMinute = wMinute;
	dt.st.wSecond = wSecond;
	return VarDateFromUdate(&dt, 0, &dtDest) == S_OK;
}

BOOL MyTmFromOleDate(DATE dtSrc, UDATE& tmDest)
{
	return VarUdateFromDate(dtSrc, 0, &tmDest) == S_OK;
}
