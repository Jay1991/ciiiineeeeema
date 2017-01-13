//////////////////////////////////////////////////////////////////////
// Copyright (c) 2005 Tremol Ltd.
// License: Mozilla Public License 1.1
// Contacts: software@tremol.bg
//////////////////////////////////////////////////////////////////////
// zfpexe.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "zfpexe.h"
#include "work.h"
#include "zfpexe_dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CZfpExeApp

BEGIN_MESSAGE_MAP(CZfpExeApp, CWinApp)
	//{{AFX_MSG_MAP(CZfpExeApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CZfpExeApp construction

CZfpExeApp::CZfpExeApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CZfpExeApp object

CZfpExeApp theApp;

// globals //////////////////////////////////////////////////////////////////
CAutoIni g_AutoIni;

/////////////////////////////////////////////////////////////////////////////
// CZfpExeApp initialization

BOOL CZfpExeApp::InitInstance()
{
	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	if (__argc > 1) {
		exit(DoWork());
	}
	else {
		// Change extension for help file
		CString strHelpFile = m_pszHelpFilePath;
		strHelpFile.MakeUpper();
		strHelpFile.Replace(_T(".HLP"), _T(".CHM"));
		free((void*)m_pszHelpFilePath);
		m_pszHelpFilePath = _tcsdup(strHelpFile);

		CZfpExeDlg dlg;
		m_pMainWnd = &dlg;
		dlg.DoModal();
	}

	// return FALSE so that we exit the
	// application, rather than start the application's message pump.
	return FALSE;
}
