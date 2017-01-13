// zfpexe.h : main header file for the ZFPEXE application
//

#if !defined(AFX_ZFPEXE_H__C538FE56_5753_4315_B8C2_8ED897A9E8F1__INCLUDED_)
#define AFX_ZFPEXE_H__C538FE56_5753_4315_B8C2_8ED897A9E8F1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

#include "../include/ZekaFP.h"
#include "AutoIni.h"

extern CAutoIni g_AutoIni;

extern const TCHAR szMain[];
extern const TCHAR szUseOutput[];
extern const TCHAR szOutput[];
extern const TCHAR szInput[];
extern const TCHAR szEncoding[];
extern const TCHAR szErrorType[];
extern const TCHAR szErrorMsg[];
extern const TCHAR szComPort[];
extern const TCHAR szBaudRate[];
extern const TCHAR szEmpty[];
extern const TCHAR szInfoMsg[];
extern const TCHAR szOperator[];
extern const TCHAR szPassword[];

/////////////////////////////////////////////////////////////////////////////
// CZfpExeApp:
// See zfpexe.cpp for the implementation of this class
//

class CZfpExeApp : public CWinApp
{
public:
	CZfpExeApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CZfpExeApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CZfpExeApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ZFPEXE_H__C538FE56_5753_4315_B8C2_8ED897A9E8F1__INCLUDED_)
