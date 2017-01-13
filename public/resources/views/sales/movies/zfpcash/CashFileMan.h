//////////////////////////////////////////////////////////////////////
// Copyright (c) 2005 Tremol Ltd.
// License: Mozilla Public License 1.1
// Contacts: software@tremol.bg
//////////////////////////////////////////////////////////////////////
// CashFileMan.h: interface for the CCashFileMan class.
//
//////////////////////////////////////////////////////////////////////

#ifndef _CASHFILEMAN_H_
#define _CASHFILEMAN_H_

#define MAX_LINE_LEN	500

typedef struct _TFileLine {
	char line[MAX_LINE_LEN];
	int startIndex;
	int lineNum;
	BOOL process;
	_TFileLine* next;
} TFileLine;

class CCashFileMan  
{
public:
	CCashFileMan();
	virtual ~CCashFileMan();

	BOOL LoadFile(const char* szFileName);
	BOOL WriteFile(const char* szFileName);

	void Clean();

	TFileLine* m_root;

protected:
	TFileLine** m_last;

	int IsGoodLine(const char* szLine, BOOL& process);
};

#endif
