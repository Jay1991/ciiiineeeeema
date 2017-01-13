// zfpexe_dlg.h : header file
//

#if !defined(AFX_ZFPEXE_DLG_H__AA51203F_B6C4_4659_B79E_7D88616046BE__INCLUDED_)
#define AFX_ZFPEXE_DLG_H__AA51203F_B6C4_4659_B79E_7D88616046BE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CZfpExeDlg dialog

class CZfpExeDlg : public CDialog
{
// Construction
public:
	CZfpExeDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CZfpExeDlg)
	enum { IDD = IDD_ZFPEXE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CZfpExeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	void FixOutput(BOOL state);
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CZfpExeDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnUseOutput();
	virtual void OnOK();
	afx_msg void OnBrowseInput();
	afx_msg void OnBrowseOutput();
	afx_msg void OnSearch();
	afx_msg void OnHelpme();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ZFPEXE_DLG_H__AA51203F_B6C4_4659_B79E_7D88616046BE__INCLUDED_)
