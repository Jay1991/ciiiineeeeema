//////////////////////////////////////////////////////////////////////
// Copyright (c) 2005 Tremol Ltd.
// License: Mozilla Public License 1.1
// Contacts: software@tremol.bg
//////////////////////////////////////////////////////////////////////
// zfpexe_dlg.cpp : implementation file
//

#include "stdafx.h"
#include "zfpexe.h"
#include "zfpexe_dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//static const TCHAR szPosX[] = _T("posx");
//static const TCHAR szPosY[] = _T("posy");

const TCHAR szMain[] = _T("setup");
const TCHAR szUseOutput[] = _T("useoutput");
const TCHAR szOutput[] = _T("output");
const TCHAR szInput[] = _T("input");
const TCHAR szEncoding[] = _T("encode");
const TCHAR szErrorType[] = _T("errortype");
const TCHAR szErrorMsg[] = _T("errormsg");
const TCHAR szInfoMsg[] = _T("infomsg");
const TCHAR szComPort[] = _T("comport");
const TCHAR szBaudRate[] = _T("baudrate");
const TCHAR szOperator[] = _T("operator");
const TCHAR szPassword[] = _T("password");
const TCHAR szEmpty[] = _T("");

const TCHAR szTxtFilter[] = _T("Текстови файлове (*.txt)|*.txt|Всички файлове (*.*)|*.*||");

static TAutoInit ai[] = {
	//{0, eDlgPosX, szMain, szPosX},
	//{0, eDlgPosY, szMain, szPosY},
	{IDC_USEOUTPUT, eCheckBox, szMain, szUseOutput},
	{IDC_INPUTFILE, eEdit, szMain, szInput},
	{IDC_OUTPUTFILE, eEdit, szMain, szOutput},
	{IDC_ERRORMSG, eCheckBox, szMain, szErrorMsg},
	{IDC_INFOMSG, eCheckBox, szMain, szInfoMsg},
	{IDC_COM, eComboSel, szMain, szComPort},
	{IDC_BAUD, eComboSel, szMain, szBaudRate},
	{IDC_OPER, eComboSel, szMain, szOperator},
	{IDC_PASS, eEdit, szMain, szPassword},
};

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CZfpExeDlg dialog

CZfpExeDlg::CZfpExeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CZfpExeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CZfpExeDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CZfpExeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CZfpExeDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CZfpExeDlg, CDialog)
	//{{AFX_MSG_MAP(CZfpExeDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_USEOUTPUT, OnUseOutput)
	ON_BN_CLICKED(IDC_BROWSEINPUT, OnBrowseInput)
	ON_BN_CLICKED(IDC_BROWSEOUTPUT, OnBrowseOutput)
	ON_BN_CLICKED(IDC_SEARCH, OnSearch)
	ON_BN_CLICKED(IDC_HELPME, OnHelpme)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CZfpExeDlg message handlers

BOOL CZfpExeDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL) {
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty()) {
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
		pSysMenu->DeleteMenu(SC_MAXIMIZE, MF_BYCOMMAND);
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	SendDlgItemMessage(IDC_INPUTFILE, EM_LIMITTEXT, _MAX_PATH, 0);
	SendDlgItemMessage(IDC_OUTPUTFILE, EM_LIMITTEXT, _MAX_PATH, 0);
	SendDlgItemMessage(IDC_PASS, EM_LIMITTEXT, 4, 0);
	CheckRadioButton(IDC_STANDARD, IDC_ERRORCODE, g_AutoIni.GetInt(szMain, szErrorType, IDC_STANDARD));
	CheckRadioButton(IDC_DOS, IDC_WINDOWS, g_AutoIni.GetInt(szMain, szEncoding, IDC_DOS));

	g_AutoIni.Retrieve(m_hWnd, ai, sizeof(ai) / sizeof(TAutoInit));
	OnUseOutput();

	CString s;
	GetDlgItemText(IDC_PASS, s);
	if (s.IsEmpty())
		SetDlgItemText(IDC_PASS, "0000");
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CZfpExeDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CZfpExeDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CZfpExeDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CZfpExeDlg::FixOutput(BOOL state)
{
	GetDlgItem(IDC_OUTPUTFILE)->EnableWindow(state);
	GetDlgItem(IDC_BROWSEOUTPUT)->EnableWindow(state);
}

void CZfpExeDlg::OnUseOutput() 
{
	FixOutput(SendDlgItemMessage(IDC_USEOUTPUT, BM_GETCHECK, 0, 0));
}

void CZfpExeDlg::OnOK() 
{
	g_AutoIni.SetInt(szMain, szErrorType, GetCheckedRadioButton(IDC_STANDARD, IDC_ERRORCODE));
	g_AutoIni.SetInt(szMain, szEncoding, GetCheckedRadioButton(IDC_DOS, IDC_WINDOWS));
	
	g_AutoIni.Store(m_hWnd, ai, sizeof(ai) / sizeof(TAutoInit));

	CDialog::OnOK();
}

void CZfpExeDlg::OnBrowseInput() 
{
CString sDestinationPath, sTitle;
TCHAR szTemp[_MAX_PATH];

	CFileDialog fd(TRUE, _T(".txt"), NULL, OFN_HIDEREADONLY | OFN_ENABLESIZING, szTxtFilter);
	sTitle.LoadString(IDS_INPUTSELECT);
	fd.m_ofn.lpstrTitle = (LPCTSTR)sTitle;
	g_AutoIni.GetString(szMain, szInput, szEmpty, szTemp, _MAX_PATH);
	fd.m_ofn.lpstrFile = szTemp;
	if (fd.DoModal() == IDOK) {
		sDestinationPath = fd.GetPathName();
		g_AutoIni.SetString(szMain, szInput, (LPCTSTR)sDestinationPath);
		GetDlgItem(IDC_INPUTFILE)->SetWindowText(sDestinationPath);
	}
}

void CZfpExeDlg::OnBrowseOutput() 
{
CString sDestinationPath, sTitle;
TCHAR szTemp[_MAX_PATH];

	CFileDialog fd(FALSE, _T(".txt"), NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT | OFN_ENABLESIZING, szTxtFilter);
	sTitle.LoadString(IDS_OUTPUTSELECT);
	fd.m_ofn.lpstrTitle = (LPCTSTR)sTitle;
	g_AutoIni.GetString(szMain, szOutput, szEmpty, szTemp, _MAX_PATH);
	fd.m_ofn.lpstrFile = szTemp;
	if (fd.DoModal() == IDOK) {
		sDestinationPath = fd.GetPathName();
		g_AutoIni.SetString(szMain, szOutput, (LPCTSTR)sDestinationPath);
		GetDlgItem(IDC_OUTPUTFILE)->SetWindowText(sDestinationPath);
	}
}

void CZfpExeDlg::OnSearch() 
{
	CWaitCursor wc;
	DWORD com = CZekaFP::FindFirstFPCOMEx();
	DWORD baud = com & 0x00FFFFFF;
	WORD wCom = (WORD)(com >> 24);
	CString text;
	if (com)
	{
		CZekaFP zfp(wCom, baud);
		char ver[40];
		if (ZFPE_SUCCESS == zfp.GetVersion(ver))
		{
			text.Format(IDS_ZEKAVER, wCom, baud, ver);
		}
		else
		{
			text.Format(IDS_ZEKANOVER, wCom, baud);
		}
	}
	else
	{
		text.LoadString(IDS_NOZEKAFP);
	}
	SetDlgItemText(IDC_SEARCHRES, (LPCTSTR)text);
}

void CZfpExeDlg::OnHelpme() 
{
	ShellExecute(m_hWnd, _T("open"), AfxGetApp()->m_pszHelpFilePath, NULL, NULL, SW_SHOWNORMAL);
}
