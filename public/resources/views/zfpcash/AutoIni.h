
//////////////////////////////////////////////////////////////////////
// AutoIni.h: interface for the CAutoIni class.
//////////////////////////////////////////////////////////////////////

#if !defined(_AUTOINI_H_)
#define _AUTOINI_H_

#include "IniFile.h"

typedef enum {eDlgPosX, eDlgPosY, eDlgSizeX, eDlgSizeY, eEdit, eComboSel, 
				eCheckBox, eSlider, eWndShow} TAutoType;

typedef struct {
	DWORD dwId;
	TAutoType eType;
	LPCTSTR sSection;
	LPCTSTR sKey;
	int iDefault;
	LPCTSTR sDefault;
} TAutoInit, *PAutoInit;

class CAutoIni : public CIniFile
{
public:
	CAutoIni();
	CAutoIni(TCHAR *szFileName);
	virtual ~CAutoIni();

	BOOL Store(HWND hWnd, TAutoInit *PAI, DWORD dwElements);
	BOOL Retrieve(HWND hWnd, TAutoInit *PAI, DWORD dwElements, CREATESTRUCT *pcs = NULL);

private:

};

#endif // !defined(_AUTOINI_H_)
