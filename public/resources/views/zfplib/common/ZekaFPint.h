//////////////////////////////////////////////////////////////////////
// Copyright (c) 2005-2006 Tremol Ltd.
// License: Mozilla Public License 1.1
// Contacts: software@tremol.bg
//////////////////////////////////////////////////////////////////////

// internal tools definitions

#ifndef _ZEKAFPINT_
#define _ZEKAFPINT_

//////////////////////////////////////////////////////////////////////
// Tools
//////////////////////////////////////////////////////////////////////
char* nstrcpy(char* dest, const char* src, int len);
int strreplace(char* str, char fromCh, char toCh);
BOOL mystrtrim(char* str, const char* trimChars = NULL);
char* getfloatformat(char* dest, double num, int count = 2);

#ifdef POSIX
void Sleep(unsigned long msec);
DWORD GetTickCount();
#endif

#endif
