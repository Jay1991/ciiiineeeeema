// zfpcom.cpp : Implementation of DLL Exports.


// Note: Proxy/Stub Information
//      To build a separate proxy/stub DLL, 
//      run nmake -f zfpcomps.mk in the project directory.

#include "stdafx.h"
#include "resource.h"
#include <initguid.h>
#include "zfpcom.h"

#include "zfpcom_i.c"
#include "ZekaFPCom.h"
#include "GetCurrentBonInfoRes.h"
#include "TaxNumbers.h"
#include "PayTypes.h"
#include "ZFPParameters.h"
#include "OperatorInfo.h"
#include "ArticleInfo.h"
#include "DailySums.h"
#include "FiscalReportData.h"
#include "DailyReport.h"
#include "ZFPStatus.h"
#include "InvoiceNumbers.h"
#include "CurrencyInfo.h"
#include "ReceiptStatus.h"


CComModule _Module;

BEGIN_OBJECT_MAP(ObjectMap)
OBJECT_ENTRY(CLSID_ZekaFP, CZekaFPCom)
OBJECT_ENTRY(CLSID_GetCurrentBonInfoRes, CGetCurrentBonInfoRes)
OBJECT_ENTRY(CLSID_TaxNumbers, CTaxNumbers)
OBJECT_ENTRY(CLSID_PayTypes, CPayTypes)
OBJECT_ENTRY(CLSID_ZFPParameters, CZFPParameters)
OBJECT_ENTRY(CLSID_OperatorInfo, COperatorInfo)
OBJECT_ENTRY(CLSID_ArticleInfo, CArticleInfo)
OBJECT_ENTRY(CLSID_DailySums, CDailySums)
OBJECT_ENTRY(CLSID_FiscalReportData, CFiscalReportData)
OBJECT_ENTRY(CLSID_DailyReport, CDailyReport)
OBJECT_ENTRY(CLSID_ZFPStatus, CZFPStatus)
OBJECT_ENTRY(CLSID_InvoiceNumbers, CInvoiceNumbers)
OBJECT_ENTRY(CLSID_CurrencyInfo, CCurrencyInfo)
OBJECT_ENTRY(CLSID_ReceiptStatus, CReceiptStatus)
END_OBJECT_MAP()

/////////////////////////////////////////////////////////////////////////////
// DLL Entry Point

extern "C"
BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID /*lpReserved*/)
{
    if (dwReason == DLL_PROCESS_ATTACH)
    {
        _Module.Init(ObjectMap, hInstance, &LIBID_ZFPCOMLib);
        DisableThreadLibraryCalls(hInstance);
    }
    else if (dwReason == DLL_PROCESS_DETACH)
        _Module.Term();
    return TRUE;    // ok
}

/////////////////////////////////////////////////////////////////////////////
// Used to determine whether the DLL can be unloaded by OLE

STDAPI DllCanUnloadNow(void)
{
    return (_Module.GetLockCount()==0) ? S_OK : S_FALSE;
}

/////////////////////////////////////////////////////////////////////////////
// Returns a class factory to create an object of the requested type

STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv)
{
    return _Module.GetClassObject(rclsid, riid, ppv);
}

/////////////////////////////////////////////////////////////////////////////
// DllRegisterServer - Adds entries to the system registry

STDAPI DllRegisterServer(void)
{
    // registers object, typelib and all interfaces in typelib
    return _Module.RegisterServer(TRUE);
}

/////////////////////////////////////////////////////////////////////////////
// DllUnregisterServer - Removes entries from the system registry

STDAPI DllUnregisterServer(void)
{
    return _Module.UnregisterServer(TRUE);
}


