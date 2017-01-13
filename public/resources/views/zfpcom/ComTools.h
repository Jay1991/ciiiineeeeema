//////////////////////////////////////////////////////////////////////
// Copyright (c) 2005 Tremol Ltd.
// License: Mozilla Public License 1.1
// Contacts: software@tremol.bg
//////////////////////////////////////////////////////////////////////

#ifndef _COM_TOOLS_
#define _COM_TOOLS_

BOOL MyOleDateFromTm(WORD wYear, WORD wMonth, WORD wDay,
	WORD wHour, WORD wMinute, WORD wSecond, DATE& dtDest);

BOOL MyTmFromOleDate(DATE dtSrc, UDATE& tmDest);

#endif