//////////////////////////////////////////////////////////////////////
// Copyright (c) 2005 Tremol Ltd.
// License: Mozilla Public License 1.1
// Contacts: software@tremol.bg
//////////////////////////////////////////////////////////////////////
// CashFileMan.cpp: implementation of the CCashFileMan class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <shlwapi.h>
#include "zfpexe.h"
#include "Work.h"
#include "CashFileMan.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

static const char g_szTrimChars[] = " \r\n";

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCashFileMan::CCashFileMan()
{
	m_root = NULL;
	m_last = &m_root;
}

CCashFileMan::~CCashFileMan()
{
	Clean();
}

void CCashFileMan::Clean()
{
	TFileLine *temp, *cur = m_root;
	while (cur) {
		temp = cur->next;
		delete cur;
		cur = temp;
	}

	m_root = NULL;
	m_last = &m_root;
}

BOOL CCashFileMan::LoadFile(const char* szFileName)
{
	Clean();

	FILE* f = fopen(szFileName, "rt");
	if (NULL == f)
		return FALSE;

	char buf[MAX_LINE_LEN];
	int lineNum = 0;

	while (fgets(buf, MAX_LINE_LEN, f)) {
		StrTrim(buf, g_szTrimChars);
		TFileLine* temp = new TFileLine;
		memset(temp, 0, sizeof(TFileLine));
		strcpy(temp->line, buf);
		temp->startIndex = IsGoodLine(temp->line, temp->process);
		temp->lineNum = ++lineNum;

		*m_last = temp;
		m_last = &temp->next;
	}

	fclose(f);

	return TRUE;
}

BOOL CCashFileMan::WriteFile(const char* szFileName)
{
	if (NULL == m_root)
		return FALSE;

	FILE* f = fopen(szFileName, "w");
	if (NULL == f)
		return FALSE;

	TFileLine *cur = m_root;
	while (cur) {
		fwrite(cur->line, 1, strlen(cur->line), f);
		fwrite("\n", 1, 1, f);

		cur = cur->next;
	}

	fclose(f);

	return TRUE;
}

int CCashFileMan::IsGoodLine(const char* szLine, BOOL& process)
{
	process = FALSE;
	if (15 > strlen(szLine))
		return 0;

	int startIndex = (szLine[3] == ',') ? 4 : 5;
	if (0 != memcmp(&szLine[startIndex], "______,_,__", 11))
		return 0;

	process = (0 == strcspn(szLine, "STPIYZD:")) ? TRUE : FALSE;

	return startIndex;
}
