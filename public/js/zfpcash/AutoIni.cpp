//////////////////////////////////////////////////////////////////////
// AutoIni.cpp: implementation of the CAutoIni class.
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AutoIni.h"

#define MAX_MYSTRING_SIZE	1000
#define DEFAULT_SIZE_X		400
#define DEFAULT_SIZE_Y		250
#define MIN_SIZE_X			10
#define MIN_SIZE_Y			10
#define DEFAULT_POS_X		100
#define DEFAULT_POS_Y		50

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
CAutoIni::CAutoIni() : CIniFile()
{
}

CAutoIni::CAutoIni(TCHAR *szFileName) : CIniFile(szFileName)
{
}

CAutoIni::~CAutoIni()
{

}


BOOL CAutoIni::Store(HWND hWnd, TAutoInit *PAI, DWORD dwElements)
{
WINDOWPLACEMENT wp;
TAutoInit *pai = PAI;
TCHAR sTemp[MAX_MYSTRING_SIZE+1];

	wp.length = sizeof(WINDOWPLACEMENT);
	for (DWORD dwCounter = 0; dwCounter < dwElements; dwCounter++) {
		switch (pai->eType) {
		case eDlgPosX: 
			if (!GetWindowPlacement(hWnd, &wp))
				return FALSE;
			SetInt(pai->sSection, pai->sKey, wp.rcNormalPosition.left);
			break;

		case eDlgSizeX: 
			if (!GetWindowPlacement(hWnd, &wp))
				return FALSE;
			SetInt(pai->sSection, pai->sKey, wp.rcNormalPosition.right - wp.rcNormalPosition.left);
			break;

		case eDlgPosY: 
			if (!GetWindowPlacement(hWnd, &wp))
				return FALSE;
			SetInt(pai->sSection, pai->sKey, wp.rcNormalPosition.top);
			break;
		
		case eDlgSizeY: 
			if (!GetWindowPlacement(hWnd, &wp))
				return FALSE;
			SetInt(pai->sSection, pai->sKey, wp.rcNormalPosition.bottom - wp.rcNormalPosition.top);
			break;

		case eEdit:
			SendDlgItemMessage(hWnd, pai->dwId, WM_GETTEXT, MAX_MYSTRING_SIZE, (LPARAM)sTemp);
			SetString(pai->sSection, pai->sKey, sTemp);
			break;
		
		case eComboSel:
			SetInt(pai->sSection, pai->sKey, SendDlgItemMessage(hWnd, pai->dwId, CB_GETCURSEL, 0, 0));
			break;

		case eCheckBox:
			SetInt(pai->sSection, pai->sKey, SendDlgItemMessage(hWnd, pai->dwId, BM_GETCHECK, 0, 0));
			break;

		case eSlider:
			SetInt(pai->sSection, pai->sKey, SendDlgItemMessage(hWnd, pai->dwId, TBM_GETPOS, 0, 0));
			break;

		case eWndShow:
			WINDOWPLACEMENT wp;
			GetWindowPlacement(hWnd, &wp);
			SetInt(pai->sSection, pai->sKey, wp.showCmd);
			break;

		default: return FALSE;
		} // switch
		pai++;
	} // for
	return TRUE;
}

BOOL CAutoIni::Retrieve(HWND hWnd, TAutoInit *PAI, DWORD dwElements, CREATESTRUCT *pcs)
{
WINDOWPLACEMENT wp;
TAutoInit *pai = PAI;
TCHAR sTemp[MAX_MYSTRING_SIZE+1];
BOOL sized = FALSE;

	wp.length = sizeof(WINDOWPLACEMENT);
	for (DWORD dwCounter = 0; dwCounter < dwElements; dwCounter++) {
		switch (pai->eType) {

		case eDlgPosX: 
			if (!GetWindowPlacement(hWnd, &wp))
				return FALSE;
			wp.rcNormalPosition.left = (LONG)GetInt(pai->sSection, pai->sKey, DEFAULT_POS_X);
			if (pcs)
				pcs->x = wp.rcNormalPosition.left;
			else {
				if (!SetWindowPos(hWnd, HWND_TOP, wp.rcNormalPosition.left, 
					wp.rcNormalPosition.top, 0, 0, SWP_NOSIZE))
					return FALSE;
			}
			break;

		case eDlgSizeX: 
			if (!GetWindowPlacement(hWnd, &wp))
				return FALSE;
			wp.rcNormalPosition.right = (LONG)GetInt(pai->sSection, pai->sKey, DEFAULT_SIZE_X);
			if (wp.rcNormalPosition.right < MIN_SIZE_X)
				wp.rcNormalPosition.right = DEFAULT_SIZE_X;
			if (pcs)
				pcs->x = wp.rcNormalPosition.left;
			else {
				if (!SetWindowPos(hWnd, HWND_TOP, 0, 0, wp.rcNormalPosition.right, 
					wp.rcNormalPosition.bottom - wp.rcNormalPosition.bottom, SWP_NOMOVE))
					return FALSE;
			}
			sized = TRUE;
			break;

		case eDlgPosY: 
			if (!GetWindowPlacement(hWnd, &wp))
				return FALSE;
			wp.rcNormalPosition.top = (LONG)GetInt(pai->sSection, pai->sKey, DEFAULT_POS_Y);
			if (pcs)
				pcs->y = wp.rcNormalPosition.left;
			else {
				if (!SetWindowPos(hWnd, HWND_TOP, wp.rcNormalPosition.left, 
					wp.rcNormalPosition.top, 0, 0, SWP_NOSIZE))
					return FALSE;
			}
			break;

		case eDlgSizeY: 
			if (!GetWindowPlacement(hWnd, &wp))
				return FALSE;
			wp.rcNormalPosition.bottom = (LONG)GetInt(pai->sSection, pai->sKey, DEFAULT_SIZE_Y);
			if (wp.rcNormalPosition.bottom < MIN_SIZE_Y)
				wp.rcNormalPosition.bottom = DEFAULT_SIZE_Y;
			if (pcs)
				pcs->x = wp.rcNormalPosition.left;
			else {
				if (!SetWindowPos(hWnd, HWND_TOP, 0, 0, 
					wp.rcNormalPosition.right - wp.rcNormalPosition.left, 
					wp.rcNormalPosition.bottom, SWP_NOMOVE))
					return FALSE;
			}
			sized = TRUE;
			break;

		case eEdit:
			GetString(pai->sSection, pai->sKey, pai->sDefault, sTemp, MAX_MYSTRING_SIZE);
			SendDlgItemMessage(hWnd, pai->dwId, WM_SETTEXT, 0, (LPARAM)sTemp);
			break;

		case eComboSel:
			SendDlgItemMessage(hWnd, pai->dwId, CB_SETCURSEL, GetInt(pai->sSection, pai->sKey, pai->iDefault), 0);
			break;

		case eCheckBox:
			SendDlgItemMessage(hWnd, pai->dwId, BM_SETCHECK, GetInt(pai->sSection, pai->sKey, pai->iDefault), 0);
			break;

		case eSlider:
			SendDlgItemMessage(hWnd, pai->dwId, TBM_SETPOS, TRUE, GetInt(pai->sSection, pai->sKey, pai->iDefault));
			break;

		case eWndShow: {
			int iState = GetInt(pai->sSection, pai->sKey, SW_SHOWNORMAL);
			if ((SW_SHOWNORMAL != iState) && (SW_SHOWMAXIMIZED != iState))
				iState = SW_SHOWNORMAL;
			ShowWindow(hWnd, iState);
			}
			break;

		default: return FALSE;
		} // switch
		pai++;
	} // for

	// if we didn't size the dialog and we don't have stopred info for X,Y pos
	// then center the window
	if ((!sized) && GetWindowPlacement(hWnd, &wp)) {
		if ((DEFAULT_POS_X == wp.rcNormalPosition.left) && (DEFAULT_POS_Y == wp.rcNormalPosition.top)) 
			CWnd::FromHandle(hWnd)->CenterWindow(CWnd::GetDesktopWindow());
	}

	return TRUE;
}
