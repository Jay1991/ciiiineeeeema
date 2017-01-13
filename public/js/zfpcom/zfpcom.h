/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Tue Feb 21 10:24:48 2012
 */
/* Compiler settings for C:\Projects\ZekaFP\3.0\zfpcom\zfpcom.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __zfpcom_h__
#define __zfpcom_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IZekaFP_FWD_DEFINED__
#define __IZekaFP_FWD_DEFINED__
typedef interface IZekaFP IZekaFP;
#endif 	/* __IZekaFP_FWD_DEFINED__ */


#ifndef ___IZekaFPEvents_FWD_DEFINED__
#define ___IZekaFPEvents_FWD_DEFINED__
typedef interface _IZekaFPEvents _IZekaFPEvents;
#endif 	/* ___IZekaFPEvents_FWD_DEFINED__ */


#ifndef __IGetCurrentBonInfoRes_FWD_DEFINED__
#define __IGetCurrentBonInfoRes_FWD_DEFINED__
typedef interface IGetCurrentBonInfoRes IGetCurrentBonInfoRes;
#endif 	/* __IGetCurrentBonInfoRes_FWD_DEFINED__ */


#ifndef __ITaxNumbers_FWD_DEFINED__
#define __ITaxNumbers_FWD_DEFINED__
typedef interface ITaxNumbers ITaxNumbers;
#endif 	/* __ITaxNumbers_FWD_DEFINED__ */


#ifndef __IPayTypes_FWD_DEFINED__
#define __IPayTypes_FWD_DEFINED__
typedef interface IPayTypes IPayTypes;
#endif 	/* __IPayTypes_FWD_DEFINED__ */


#ifndef __IZFPParameters_FWD_DEFINED__
#define __IZFPParameters_FWD_DEFINED__
typedef interface IZFPParameters IZFPParameters;
#endif 	/* __IZFPParameters_FWD_DEFINED__ */


#ifndef __IOperatorInfo_FWD_DEFINED__
#define __IOperatorInfo_FWD_DEFINED__
typedef interface IOperatorInfo IOperatorInfo;
#endif 	/* __IOperatorInfo_FWD_DEFINED__ */


#ifndef __IArticleInfo_FWD_DEFINED__
#define __IArticleInfo_FWD_DEFINED__
typedef interface IArticleInfo IArticleInfo;
#endif 	/* __IArticleInfo_FWD_DEFINED__ */


#ifndef __IDailySums_FWD_DEFINED__
#define __IDailySums_FWD_DEFINED__
typedef interface IDailySums IDailySums;
#endif 	/* __IDailySums_FWD_DEFINED__ */


#ifndef __IFiscalReportData_FWD_DEFINED__
#define __IFiscalReportData_FWD_DEFINED__
typedef interface IFiscalReportData IFiscalReportData;
#endif 	/* __IFiscalReportData_FWD_DEFINED__ */


#ifndef __IDailyReport_FWD_DEFINED__
#define __IDailyReport_FWD_DEFINED__
typedef interface IDailyReport IDailyReport;
#endif 	/* __IDailyReport_FWD_DEFINED__ */


#ifndef __IZFPStatus_FWD_DEFINED__
#define __IZFPStatus_FWD_DEFINED__
typedef interface IZFPStatus IZFPStatus;
#endif 	/* __IZFPStatus_FWD_DEFINED__ */


#ifndef __IInvoiceNumbers_FWD_DEFINED__
#define __IInvoiceNumbers_FWD_DEFINED__
typedef interface IInvoiceNumbers IInvoiceNumbers;
#endif 	/* __IInvoiceNumbers_FWD_DEFINED__ */


#ifndef __ICurrencyInfo_FWD_DEFINED__
#define __ICurrencyInfo_FWD_DEFINED__
typedef interface ICurrencyInfo ICurrencyInfo;
#endif 	/* __ICurrencyInfo_FWD_DEFINED__ */


#ifndef __IReceiptStatus_FWD_DEFINED__
#define __IReceiptStatus_FWD_DEFINED__
typedef interface IReceiptStatus IReceiptStatus;
#endif 	/* __IReceiptStatus_FWD_DEFINED__ */


#ifndef __ZekaFP_FWD_DEFINED__
#define __ZekaFP_FWD_DEFINED__

#ifdef __cplusplus
typedef class ZekaFP ZekaFP;
#else
typedef struct ZekaFP ZekaFP;
#endif /* __cplusplus */

#endif 	/* __ZekaFP_FWD_DEFINED__ */


#ifndef __GetCurrentBonInfoRes_FWD_DEFINED__
#define __GetCurrentBonInfoRes_FWD_DEFINED__

#ifdef __cplusplus
typedef class GetCurrentBonInfoRes GetCurrentBonInfoRes;
#else
typedef struct GetCurrentBonInfoRes GetCurrentBonInfoRes;
#endif /* __cplusplus */

#endif 	/* __GetCurrentBonInfoRes_FWD_DEFINED__ */


#ifndef __TaxNumbers_FWD_DEFINED__
#define __TaxNumbers_FWD_DEFINED__

#ifdef __cplusplus
typedef class TaxNumbers TaxNumbers;
#else
typedef struct TaxNumbers TaxNumbers;
#endif /* __cplusplus */

#endif 	/* __TaxNumbers_FWD_DEFINED__ */


#ifndef __PayTypes_FWD_DEFINED__
#define __PayTypes_FWD_DEFINED__

#ifdef __cplusplus
typedef class PayTypes PayTypes;
#else
typedef struct PayTypes PayTypes;
#endif /* __cplusplus */

#endif 	/* __PayTypes_FWD_DEFINED__ */


#ifndef __ZFPParameters_FWD_DEFINED__
#define __ZFPParameters_FWD_DEFINED__

#ifdef __cplusplus
typedef class ZFPParameters ZFPParameters;
#else
typedef struct ZFPParameters ZFPParameters;
#endif /* __cplusplus */

#endif 	/* __ZFPParameters_FWD_DEFINED__ */


#ifndef __OperatorInfo_FWD_DEFINED__
#define __OperatorInfo_FWD_DEFINED__

#ifdef __cplusplus
typedef class OperatorInfo OperatorInfo;
#else
typedef struct OperatorInfo OperatorInfo;
#endif /* __cplusplus */

#endif 	/* __OperatorInfo_FWD_DEFINED__ */


#ifndef __ArticleInfo_FWD_DEFINED__
#define __ArticleInfo_FWD_DEFINED__

#ifdef __cplusplus
typedef class ArticleInfo ArticleInfo;
#else
typedef struct ArticleInfo ArticleInfo;
#endif /* __cplusplus */

#endif 	/* __ArticleInfo_FWD_DEFINED__ */


#ifndef __DailySums_FWD_DEFINED__
#define __DailySums_FWD_DEFINED__

#ifdef __cplusplus
typedef class DailySums DailySums;
#else
typedef struct DailySums DailySums;
#endif /* __cplusplus */

#endif 	/* __DailySums_FWD_DEFINED__ */


#ifndef __FiscalReportData_FWD_DEFINED__
#define __FiscalReportData_FWD_DEFINED__

#ifdef __cplusplus
typedef class FiscalReportData FiscalReportData;
#else
typedef struct FiscalReportData FiscalReportData;
#endif /* __cplusplus */

#endif 	/* __FiscalReportData_FWD_DEFINED__ */


#ifndef __DailyReport_FWD_DEFINED__
#define __DailyReport_FWD_DEFINED__

#ifdef __cplusplus
typedef class DailyReport DailyReport;
#else
typedef struct DailyReport DailyReport;
#endif /* __cplusplus */

#endif 	/* __DailyReport_FWD_DEFINED__ */


#ifndef __ZFPStatus_FWD_DEFINED__
#define __ZFPStatus_FWD_DEFINED__

#ifdef __cplusplus
typedef class ZFPStatus ZFPStatus;
#else
typedef struct ZFPStatus ZFPStatus;
#endif /* __cplusplus */

#endif 	/* __ZFPStatus_FWD_DEFINED__ */


#ifndef __InvoiceNumbers_FWD_DEFINED__
#define __InvoiceNumbers_FWD_DEFINED__

#ifdef __cplusplus
typedef class InvoiceNumbers InvoiceNumbers;
#else
typedef struct InvoiceNumbers InvoiceNumbers;
#endif /* __cplusplus */

#endif 	/* __InvoiceNumbers_FWD_DEFINED__ */


#ifndef __CurrencyInfo_FWD_DEFINED__
#define __CurrencyInfo_FWD_DEFINED__

#ifdef __cplusplus
typedef class CurrencyInfo CurrencyInfo;
#else
typedef struct CurrencyInfo CurrencyInfo;
#endif /* __cplusplus */

#endif 	/* __CurrencyInfo_FWD_DEFINED__ */


#ifndef __ReceiptStatus_FWD_DEFINED__
#define __ReceiptStatus_FWD_DEFINED__

#ifdef __cplusplus
typedef class ReceiptStatus ReceiptStatus;
#else
typedef struct ReceiptStatus ReceiptStatus;
#endif /* __cplusplus */

#endif 	/* __ReceiptStatus_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

/* interface __MIDL_itf_zfpcom_0000 */
/* [local] */ 




extern RPC_IF_HANDLE __MIDL_itf_zfpcom_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_zfpcom_0000_v0_0_s_ifspec;

#ifndef __IZekaFP_INTERFACE_DEFINED__
#define __IZekaFP_INTERFACE_DEFINED__

/* interface IZekaFP */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IZekaFP;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("955B3931-1A9C-4E6D-8343-000BEF1E4C27")
    IZekaFP : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCurrentBonInfo( 
            /* [retval][out] */ LPDISPATCH __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Setup( 
            /* [in] */ WORD wCom,
            /* [in] */ DWORD baud,
            /* [in] */ WORD retries,
            /* [in] */ DWORD retryWait) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_errorCode( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Diagnostic( 
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DisplayClear( 
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DisplayDateTime( 
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OpenTill( 
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LineFeed( 
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PrintLogo( 
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CloseBon( 
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CloseFiscalBon( 
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PrintDuplicate( 
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetLocalDateTime( 
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetTaxNumber( 
            /* [retval][out] */ BSTR __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDecimalPoint( 
            /* [retval][out] */ long __RPC_FAR *pPoint) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetClicheLine( 
            /* [in] */ BYTE num,
            /* [retval][out] */ BSTR __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OpenBon( 
            /* [in] */ BYTE oper,
            /* [in] */ BSTR passwd,
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OpenFiscalBon( 
            /* [in] */ BYTE oper,
            /* [in] */ BSTR passwd,
            /* [in] */ BYTE defPass,
            /* [in] */ BYTE dds,
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SellFree( 
            /* [in] */ BSTR name,
            /* [in] */ BYTE taxgrp,
            /* [in] */ double price,
            /* [in] */ double quantity,
            /* [in] */ double discount,
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Payment( 
            /* [in] */ double sum,
            /* [in] */ BYTE type,
            /* [in] */ BOOL noRest,
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OfficialSums( 
            /* [in] */ BYTE num,
            /* [in] */ BSTR passwd,
            /* [in] */ BYTE type,
            /* [in] */ double sum,
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetBonNumber( 
            /* [retval][out] */ long __RPC_FAR *pNumber) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetPayType( 
            /* [in] */ BYTE type,
            /* [in] */ BSTR line,
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetParameters( 
            /* [in] */ WORD fpnum,
            /* [in] */ BOOL logo,
            /* [in] */ BOOL till,
            /* [in] */ BOOL autocut,
            /* [in] */ BOOL transparent,
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetClicheLine( 
            /* [in] */ BYTE num,
            /* [in] */ BSTR text,
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetOperatorUserPass( 
            /* [in] */ BYTE oper,
            /* [in] */ BSTR name,
            /* [in] */ BSTR passwd,
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetArticleInfo( 
            /* [in] */ WORD num,
            /* [in] */ BSTR name,
            /* [in] */ double price,
            /* [in] */ BYTE taxgrp,
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetLogoFile( 
            /* [in] */ BSTR filename,
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetFactoryNumber( 
            /* [retval][out] */ BSTR __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetFiscalNumber( 
            /* [retval][out] */ BSTR __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SellDB( 
            /* [in] */ BOOL isVoid,
            /* [in] */ WORD number,
            /* [in] */ double quantity,
            /* [in] */ double discount,
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetTaxPercents( 
            /* [retval][out] */ LPDISPATCH __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetPayTypes( 
            /* [retval][out] */ LPDISPATCH __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetParameters( 
            /* [retval][out] */ LPDISPATCH __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetOperatorUserPass( 
            /* [in] */ BYTE oper,
            /* [retval][out] */ LPDISPATCH __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDailySums( 
            /* [retval][out] */ LPDISPATCH __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetArticleInfo( 
            /* [in] */ WORD number,
            /* [retval][out] */ LPDISPATCH __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDailyInfo( 
            /* [retval][out] */ LPDISPATCH __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetOperatorInfo( 
            /* [in] */ BYTE oper,
            /* [retval][out] */ LPDISPATCH __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetOperatorReceives( 
            /* [in] */ BYTE oper,
            /* [retval][out] */ LPDISPATCH __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDateTime( 
            /* [retval][out] */ DATE __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Display( 
            /* [in] */ BSTR line,
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DisplayLine1( 
            /* [in] */ BSTR line,
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DisplayLine2( 
            /* [in] */ BSTR line,
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetVersion( 
            /* [retval][out] */ BSTR __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetInputBuffer( 
            /* [retval][out] */ BSTR __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetResponseBuffer( 
            /* [retval][out] */ BSTR __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetInputHexFormated( 
            /* [retval][out] */ BSTR __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetResponseHexFormated( 
            /* [retval][out] */ BSTR __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetErrorString( 
            /* [in] */ int error,
            /* [in] */ int lang,
            /* [retval][out] */ BSTR __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetOperatorIncomes( 
            /* [in] */ BYTE oper,
            /* [retval][out] */ LPDISPATCH __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetOperatorExpenses( 
            /* [in] */ BYTE oper,
            /* [retval][out] */ LPDISPATCH __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDailyPayments( 
            /* [retval][out] */ LPDISPATCH __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDailyIncomes( 
            /* [retval][out] */ LPDISPATCH __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDailyOfficialIncomes( 
            /* [retval][out] */ LPDISPATCH __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDailyOfficialExpenses( 
            /* [retval][out] */ LPDISPATCH __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CalcIntermediateSum( 
            /* [in] */ BOOL doprint,
            /* [in] */ BOOL dodisplay,
            /* [in] */ BOOL dopercents,
            /* [in] */ double discount,
            /* [retval][out] */ double __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetLastFiscalReportData( 
            /* [retval][out] */ LPDISPATCH __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReportSpecialFiscal( 
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReportFiscalByBlock( 
            /* [in] */ BOOL detailed,
            /* [in] */ WORD startNumber,
            /* [in] */ WORD endNumber,
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReportDaily( 
            /* [in] */ BOOL zero,
            /* [in] */ BOOL extended,
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReportArticles( 
            /* [in] */ BOOL zero,
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetDateTime( 
            /* [in] */ DATE datetime,
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReportFiscalByDate( 
            /* [in] */ BOOL detailed,
            /* [in] */ DATE start,
            /* [in] */ DATE end,
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReportOperator( 
            /* [in] */ BOOL zero,
            /* [in] */ BYTE oper,
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PrintText( 
            /* [in] */ BSTR text,
            /* [in] */ int align,
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDailyReport( 
            /* [retval][out] */ LPDISPATCH __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetOperatorCounter( 
            /* [in] */ BYTE oper,
            /* [retval][out] */ LPDISPATCH __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetExternalDisplayFile( 
            /* [in] */ BSTR password,
            /* [in] */ BSTR filename,
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadFiscalMemory( 
            /* [in] */ BSTR filename,
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FindFirstFPCOM( 
            /* [retval][out] */ DWORD __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PaperCut( 
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetStatus( 
            /* [retval][out] */ LPDISPATCH __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetFreeFiscalSpace( 
            /* [retval][out] */ long __RPC_FAR *pRecords) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_zfpType( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_zfpType( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OpenInvoice( 
            /* [in] */ BYTE oper,
            /* [in] */ BSTR passwd,
            /* [in] */ BSTR client,
            /* [in] */ BSTR receiver,
            /* [in] */ BSTR vatNum,
            /* [in] */ BSTR identNum,
            /* [in] */ BSTR address,
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE BusyWait( 
            /* [in] */ DWORD timeout,
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetAutoBusyWait( 
            /* [in] */ DWORD timeout) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetSerialNumber( 
            /* [in] */ BSTR password,
            /* [in] */ BSTR manifactureNum,
            /* [in] */ BSTR fiscalNum,
            /* [in] */ BSTR controlSum,
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetTaxNumber( 
            /* [in] */ BSTR password,
            /* [in] */ BSTR taxNum,
            /* [in] */ BSTR fiscalNum,
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MakeFiscal( 
            /* [in] */ BSTR password,
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetTaxPercents( 
            /* [in] */ BSTR password,
            /* [in] */ double tgr1,
            /* [in] */ double tgr2,
            /* [in] */ double tgr3,
            /* [in] */ double tgr4,
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetDecimalPoint( 
            /* [in] */ BSTR password,
            /* [in] */ int point,
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetEJMode( 
            /* [retval][out] */ long __RPC_FAR *pIsShort) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetEJMode( 
            /* [in] */ BOOL bShort,
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReportEJ( 
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SellDepartment( 
            /* [in] */ BSTR name,
            /* [in] */ WORD depNum,
            /* [in] */ double price,
            /* [in] */ double quantity,
            /* [in] */ double discount,
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetDepartment( 
            /* [in] */ WORD number,
            /* [in] */ BSTR name,
            /* [in] */ BYTE taxgrp,
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDepartment( 
            /* [in] */ WORD number,
            /* [retval][out] */ LPDISPATCH __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetArticleInfoEx( 
            /* [in] */ WORD num,
            /* [in] */ BSTR name,
            /* [in] */ double price,
            /* [in] */ BYTE taxgrp,
            /* [in] */ WORD department,
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CalcIntermediateSum2( 
            /* [in] */ BOOL doprint,
            /* [in] */ BOOL dodisplay,
            /* [in] */ BOOL dopercents,
            /* [in] */ double discount,
            /* [in] */ short taxgrp,
            /* [retval][out] */ double __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReportEJ2( 
            /* [in] */ WORD num,
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetTaxPercentsEU( 
            /* [in] */ BSTR password,
            /* [in] */ double tgr1,
            /* [in] */ double tgr2,
            /* [in] */ double tgr3,
            /* [in] */ double tgr4,
            /* [in] */ double tgr5,
            /* [in] */ double tgr6,
            /* [in] */ double tgr7,
            /* [in] */ double tgr8,
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetPayTypeEU( 
            /* [in] */ BYTE type,
            /* [in] */ BSTR line,
            /* [in] */ double exchRate,
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetOperatorChangeEU( 
            /* [in] */ BYTE oper,
            /* [retval][out] */ LPDISPATCH __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetInvoiceNumbersRangeEU( 
            /* [in] */ BSTR startNum,
            /* [in] */ BSTR lastNum,
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PaymentEU( 
            /* [in] */ double sum,
            /* [in] */ BYTE type,
            /* [in] */ BOOL noChange,
            /* [in] */ BYTE changeType,
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetParametersEU( 
            /* [in] */ WORD fpnum,
            /* [in] */ BOOL logo,
            /* [in] */ BOOL till,
            /* [in] */ BOOL autocut,
            /* [in] */ BOOL transparent,
            /* [in] */ BOOL shortEJ,
            /* [in] */ BOOL currency,
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SendCommandDirect( 
            /* [in] */ BSTR cmd,
            /* [retval][out] */ BSTR __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDailyChangeEU( 
            /* [retval][out] */ LPDISPATCH __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UpdateClicheKE( 
            /* [in] */ BYTE mode,
            /* [in] */ BSTR password,
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Setup2( 
            /* [in] */ BYTE wCom,
            /* [in] */ long baud,
            /* [in] */ long retries,
            /* [in] */ long retryWait) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OpenBonWithEJ( 
            /* [in] */ BYTE oper,
            /* [in] */ BSTR passwd,
            /* [in] */ BOOL hasEJ,
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_zfplibVersion( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetInvoiceNextNumberEU( 
            /* [retval][out] */ LPDISPATCH __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetLogo( 
            /* [in] */ unsigned char logo,
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetLogoInfo( 
            /* [retval][out] */ BSTR __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FindFirstFPCOMEx( 
            /* [retval][out] */ DWORD __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetLogoFileEx( 
            /* [in] */ unsigned char logo_id,
            /* [in] */ BSTR filename,
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PrintLogoEx( 
            /* [in] */ unsigned char logo_id,
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CloseBonInCash( 
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PaymentEx( 
            /* [in] */ double sum,
            /* [in] */ BYTE type,
            /* [in] */ BOOL noChange,
            /* [in] */ BYTE changeType,
            /* [in] */ BOOL fPaidExactSum,
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetVersionGS( 
            /* [retval][out] */ BSTR __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EnableCommGS( 
            /* [in] */ unsigned char __MIDL_0015,
            /* [in] */ WORD device_no,
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetSpeedGS( 
            /* [in] */ unsigned char speed,
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LoadScaleProtocolGS( 
            /* [in] */ BSTR protocol,
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SellDepartmentEx( 
            /* [in] */ BSTR name,
            /* [in] */ WORD depNum,
            /* [in] */ double price,
            /* [in] */ double quantity,
            /* [in] */ double discount,
            /* [in] */ unsigned char flag,
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SellFreeEx( 
            /* [in] */ BSTR name,
            /* [in] */ BYTE taxgrp,
            /* [in] */ double price,
            /* [in] */ double quantity,
            /* [in] */ double discount,
            /* [in] */ unsigned char flag,
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SellDBEx( 
            /* [in] */ BOOL isVoid,
            /* [in] */ DWORD number,
            /* [in] */ double quantity,
            /* [in] */ double discount,
            /* [in] */ unsigned char flag,
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetArticleInfoEx( 
            /* [in] */ DWORD number,
            /* [retval][out] */ LPDISPATCH __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetArticleInfo2( 
            /* [in] */ DWORD num,
            /* [in] */ BSTR name,
            /* [in] */ double price,
            /* [in] */ BYTE taxgrp,
            /* [in] */ WORD department,
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReportDepartments( 
            /* [in] */ BOOL zero,
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OfficialSumsEx( 
            /* [in] */ BYTE num,
            /* [in] */ BSTR passwd,
            /* [in] */ BYTE type,
            /* [in] */ double sum,
            /* [in] */ BSTR note,
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EnableBarcode( 
            /* [in] */ unsigned char __MIDL_0016,
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FormatBarcode( 
            /* [in] */ BSTR __MIDL_0017,
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PrintBarcode( 
            /* [in] */ BSTR __MIDL_0018,
            /* [in] */ BYTE __MIDL_0019,
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetLineWidth( 
            /* [in] */ int __MIDL_0020,
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetPrintMode( 
            /* [in] */ DWORD __MIDL_0021,
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OpenTillEx( 
            /* [in] */ unsigned char __MIDL_0022,
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OpenSerialPort( 
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CloseSerialPort( 
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Storno( 
            /* [in] */ BSTR name,
            /* [in] */ BYTE taxgrp,
            /* [in] */ double price,
            /* [in] */ double quantity,
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SellFreeDiv( 
            /* [in] */ BSTR name,
            /* [in] */ BYTE taxgrp,
            /* [in] */ double price,
            /* [in] */ double quantity,
            /* [in] */ double discount,
            /* [in] */ unsigned char flag,
            DWORD divider,
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE TerminateBon( 
            /* [in] */ BOOL __MIDL_0023,
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadFiscalMemory2( 
            /* [in] */ BSTR filename,
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddDiscount( 
            /* [in] */ BOOL dotrans,
            /* [in] */ BOOL doauto,
            /* [in] */ BOOL dodisplay,
            /* [in] */ BOOL dopercents,
            /* [in] */ double discount,
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SellDBEx2( 
            /* [in] */ BOOL isVoid,
            /* [in] */ DWORD number,
            /* [in] */ double price,
            /* [in] */ double quantity,
            /* [in] */ double discount,
            /* [in] */ unsigned char flag,
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetLineWidth( 
            /* [retval][out] */ long __RPC_FAR *pChars) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetArticleInfo3( 
            /* [in] */ DWORD num,
            /* [in] */ BSTR name,
            /* [in] */ double price,
            /* [in] */ BYTE taxgrp,
            /* [in] */ WORD department,
            /* [in] */ BSTR unit,
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetArticleUnit( 
            /* [in] */ DWORD number,
            /* [retval][out] */ BSTR __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetPayTypeEx( 
            /* [in] */ BYTE type,
            /* [in] */ BSTR line,
            /* [in] */ double exchRate,
            /* [in] */ int code,
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetStartDateFM( 
            /* [retval][out] */ BSTR __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PrintTextKP( 
            /* [in] */ BSTR text,
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PrintTextKP2( 
            /* [in] */ BSTR format,
            /* [in] */ int flags,
            /* [in] */ BSTR text_param,
            /* [in] */ double numeric_param,
            /* [retval][out] */ long __RPC_FAR *pRes) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IZekaFPVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IZekaFP __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IZekaFP __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IZekaFP __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCurrentBonInfo )( 
            IZekaFP __RPC_FAR * This,
            /* [retval][out] */ LPDISPATCH __RPC_FAR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Setup )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ WORD wCom,
            /* [in] */ DWORD baud,
            /* [in] */ WORD retries,
            /* [in] */ DWORD retryWait);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_errorCode )( 
            IZekaFP __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Diagnostic )( 
            IZekaFP __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DisplayClear )( 
            IZekaFP __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DisplayDateTime )( 
            IZekaFP __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OpenTill )( 
            IZekaFP __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LineFeed )( 
            IZekaFP __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *PrintLogo )( 
            IZekaFP __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CloseBon )( 
            IZekaFP __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CloseFiscalBon )( 
            IZekaFP __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *PrintDuplicate )( 
            IZekaFP __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetLocalDateTime )( 
            IZekaFP __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTaxNumber )( 
            IZekaFP __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDecimalPoint )( 
            IZekaFP __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pPoint);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClicheLine )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ BYTE num,
            /* [retval][out] */ BSTR __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OpenBon )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ BYTE oper,
            /* [in] */ BSTR passwd,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OpenFiscalBon )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ BYTE oper,
            /* [in] */ BSTR passwd,
            /* [in] */ BYTE defPass,
            /* [in] */ BYTE dds,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SellFree )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ BSTR name,
            /* [in] */ BYTE taxgrp,
            /* [in] */ double price,
            /* [in] */ double quantity,
            /* [in] */ double discount,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Payment )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ double sum,
            /* [in] */ BYTE type,
            /* [in] */ BOOL noRest,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OfficialSums )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ BYTE num,
            /* [in] */ BSTR passwd,
            /* [in] */ BYTE type,
            /* [in] */ double sum,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetBonNumber )( 
            IZekaFP __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pNumber);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPayType )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ BYTE type,
            /* [in] */ BSTR line,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetParameters )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ WORD fpnum,
            /* [in] */ BOOL logo,
            /* [in] */ BOOL till,
            /* [in] */ BOOL autocut,
            /* [in] */ BOOL transparent,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClicheLine )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ BYTE num,
            /* [in] */ BSTR text,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetOperatorUserPass )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ BYTE oper,
            /* [in] */ BSTR name,
            /* [in] */ BSTR passwd,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetArticleInfo )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ WORD num,
            /* [in] */ BSTR name,
            /* [in] */ double price,
            /* [in] */ BYTE taxgrp,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetLogoFile )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ BSTR filename,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFactoryNumber )( 
            IZekaFP __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFiscalNumber )( 
            IZekaFP __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SellDB )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ BOOL isVoid,
            /* [in] */ WORD number,
            /* [in] */ double quantity,
            /* [in] */ double discount,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTaxPercents )( 
            IZekaFP __RPC_FAR * This,
            /* [retval][out] */ LPDISPATCH __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPayTypes )( 
            IZekaFP __RPC_FAR * This,
            /* [retval][out] */ LPDISPATCH __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetParameters )( 
            IZekaFP __RPC_FAR * This,
            /* [retval][out] */ LPDISPATCH __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetOperatorUserPass )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ BYTE oper,
            /* [retval][out] */ LPDISPATCH __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDailySums )( 
            IZekaFP __RPC_FAR * This,
            /* [retval][out] */ LPDISPATCH __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetArticleInfo )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ WORD number,
            /* [retval][out] */ LPDISPATCH __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDailyInfo )( 
            IZekaFP __RPC_FAR * This,
            /* [retval][out] */ LPDISPATCH __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetOperatorInfo )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ BYTE oper,
            /* [retval][out] */ LPDISPATCH __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetOperatorReceives )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ BYTE oper,
            /* [retval][out] */ LPDISPATCH __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDateTime )( 
            IZekaFP __RPC_FAR * This,
            /* [retval][out] */ DATE __RPC_FAR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Display )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ BSTR line,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DisplayLine1 )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ BSTR line,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DisplayLine2 )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ BSTR line,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVersion )( 
            IZekaFP __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetInputBuffer )( 
            IZekaFP __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetResponseBuffer )( 
            IZekaFP __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetInputHexFormated )( 
            IZekaFP __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetResponseHexFormated )( 
            IZekaFP __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetErrorString )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ int error,
            /* [in] */ int lang,
            /* [retval][out] */ BSTR __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetOperatorIncomes )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ BYTE oper,
            /* [retval][out] */ LPDISPATCH __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetOperatorExpenses )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ BYTE oper,
            /* [retval][out] */ LPDISPATCH __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDailyPayments )( 
            IZekaFP __RPC_FAR * This,
            /* [retval][out] */ LPDISPATCH __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDailyIncomes )( 
            IZekaFP __RPC_FAR * This,
            /* [retval][out] */ LPDISPATCH __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDailyOfficialIncomes )( 
            IZekaFP __RPC_FAR * This,
            /* [retval][out] */ LPDISPATCH __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDailyOfficialExpenses )( 
            IZekaFP __RPC_FAR * This,
            /* [retval][out] */ LPDISPATCH __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CalcIntermediateSum )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ BOOL doprint,
            /* [in] */ BOOL dodisplay,
            /* [in] */ BOOL dopercents,
            /* [in] */ double discount,
            /* [retval][out] */ double __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetLastFiscalReportData )( 
            IZekaFP __RPC_FAR * This,
            /* [retval][out] */ LPDISPATCH __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReportSpecialFiscal )( 
            IZekaFP __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReportFiscalByBlock )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ BOOL detailed,
            /* [in] */ WORD startNumber,
            /* [in] */ WORD endNumber,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReportDaily )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ BOOL zero,
            /* [in] */ BOOL extended,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReportArticles )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ BOOL zero,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDateTime )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ DATE datetime,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReportFiscalByDate )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ BOOL detailed,
            /* [in] */ DATE start,
            /* [in] */ DATE end,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReportOperator )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ BOOL zero,
            /* [in] */ BYTE oper,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *PrintText )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ BSTR text,
            /* [in] */ int align,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDailyReport )( 
            IZekaFP __RPC_FAR * This,
            /* [retval][out] */ LPDISPATCH __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetOperatorCounter )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ BYTE oper,
            /* [retval][out] */ LPDISPATCH __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetExternalDisplayFile )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ BSTR password,
            /* [in] */ BSTR filename,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadFiscalMemory )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ BSTR filename,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FindFirstFPCOM )( 
            IZekaFP __RPC_FAR * This,
            /* [retval][out] */ DWORD __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *PaperCut )( 
            IZekaFP __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetStatus )( 
            IZekaFP __RPC_FAR * This,
            /* [retval][out] */ LPDISPATCH __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFreeFiscalSpace )( 
            IZekaFP __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pRecords);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_zfpType )( 
            IZekaFP __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_zfpType )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OpenInvoice )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ BYTE oper,
            /* [in] */ BSTR passwd,
            /* [in] */ BSTR client,
            /* [in] */ BSTR receiver,
            /* [in] */ BSTR vatNum,
            /* [in] */ BSTR identNum,
            /* [in] */ BSTR address,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *BusyWait )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ DWORD timeout,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetAutoBusyWait )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ DWORD timeout);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetSerialNumber )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ BSTR password,
            /* [in] */ BSTR manifactureNum,
            /* [in] */ BSTR fiscalNum,
            /* [in] */ BSTR controlSum,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetTaxNumber )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ BSTR password,
            /* [in] */ BSTR taxNum,
            /* [in] */ BSTR fiscalNum,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *MakeFiscal )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ BSTR password,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetTaxPercents )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ BSTR password,
            /* [in] */ double tgr1,
            /* [in] */ double tgr2,
            /* [in] */ double tgr3,
            /* [in] */ double tgr4,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDecimalPoint )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ BSTR password,
            /* [in] */ int point,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEJMode )( 
            IZekaFP __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pIsShort);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetEJMode )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ BOOL bShort,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReportEJ )( 
            IZekaFP __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SellDepartment )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ BSTR name,
            /* [in] */ WORD depNum,
            /* [in] */ double price,
            /* [in] */ double quantity,
            /* [in] */ double discount,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDepartment )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ WORD number,
            /* [in] */ BSTR name,
            /* [in] */ BYTE taxgrp,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDepartment )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ WORD number,
            /* [retval][out] */ LPDISPATCH __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetArticleInfoEx )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ WORD num,
            /* [in] */ BSTR name,
            /* [in] */ double price,
            /* [in] */ BYTE taxgrp,
            /* [in] */ WORD department,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CalcIntermediateSum2 )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ BOOL doprint,
            /* [in] */ BOOL dodisplay,
            /* [in] */ BOOL dopercents,
            /* [in] */ double discount,
            /* [in] */ short taxgrp,
            /* [retval][out] */ double __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReportEJ2 )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ WORD num,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetTaxPercentsEU )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ BSTR password,
            /* [in] */ double tgr1,
            /* [in] */ double tgr2,
            /* [in] */ double tgr3,
            /* [in] */ double tgr4,
            /* [in] */ double tgr5,
            /* [in] */ double tgr6,
            /* [in] */ double tgr7,
            /* [in] */ double tgr8,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPayTypeEU )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ BYTE type,
            /* [in] */ BSTR line,
            /* [in] */ double exchRate,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetOperatorChangeEU )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ BYTE oper,
            /* [retval][out] */ LPDISPATCH __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetInvoiceNumbersRangeEU )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ BSTR startNum,
            /* [in] */ BSTR lastNum,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *PaymentEU )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ double sum,
            /* [in] */ BYTE type,
            /* [in] */ BOOL noChange,
            /* [in] */ BYTE changeType,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetParametersEU )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ WORD fpnum,
            /* [in] */ BOOL logo,
            /* [in] */ BOOL till,
            /* [in] */ BOOL autocut,
            /* [in] */ BOOL transparent,
            /* [in] */ BOOL shortEJ,
            /* [in] */ BOOL currency,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SendCommandDirect )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ BSTR cmd,
            /* [retval][out] */ BSTR __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDailyChangeEU )( 
            IZekaFP __RPC_FAR * This,
            /* [retval][out] */ LPDISPATCH __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *UpdateClicheKE )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ BYTE mode,
            /* [in] */ BSTR password,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Setup2 )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ BYTE wCom,
            /* [in] */ long baud,
            /* [in] */ long retries,
            /* [in] */ long retryWait);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OpenBonWithEJ )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ BYTE oper,
            /* [in] */ BSTR passwd,
            /* [in] */ BOOL hasEJ,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_zfplibVersion )( 
            IZekaFP __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetInvoiceNextNumberEU )( 
            IZekaFP __RPC_FAR * This,
            /* [retval][out] */ LPDISPATCH __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetLogo )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ unsigned char logo,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetLogoInfo )( 
            IZekaFP __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FindFirstFPCOMEx )( 
            IZekaFP __RPC_FAR * This,
            /* [retval][out] */ DWORD __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetLogoFileEx )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ unsigned char logo_id,
            /* [in] */ BSTR filename,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *PrintLogoEx )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ unsigned char logo_id,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CloseBonInCash )( 
            IZekaFP __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *PaymentEx )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ double sum,
            /* [in] */ BYTE type,
            /* [in] */ BOOL noChange,
            /* [in] */ BYTE changeType,
            /* [in] */ BOOL fPaidExactSum,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVersionGS )( 
            IZekaFP __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EnableCommGS )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ unsigned char __MIDL_0015,
            /* [in] */ WORD device_no,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetSpeedGS )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ unsigned char speed,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LoadScaleProtocolGS )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ BSTR protocol,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SellDepartmentEx )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ BSTR name,
            /* [in] */ WORD depNum,
            /* [in] */ double price,
            /* [in] */ double quantity,
            /* [in] */ double discount,
            /* [in] */ unsigned char flag,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SellFreeEx )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ BSTR name,
            /* [in] */ BYTE taxgrp,
            /* [in] */ double price,
            /* [in] */ double quantity,
            /* [in] */ double discount,
            /* [in] */ unsigned char flag,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SellDBEx )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ BOOL isVoid,
            /* [in] */ DWORD number,
            /* [in] */ double quantity,
            /* [in] */ double discount,
            /* [in] */ unsigned char flag,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetArticleInfoEx )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ DWORD number,
            /* [retval][out] */ LPDISPATCH __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetArticleInfo2 )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ DWORD num,
            /* [in] */ BSTR name,
            /* [in] */ double price,
            /* [in] */ BYTE taxgrp,
            /* [in] */ WORD department,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReportDepartments )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ BOOL zero,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OfficialSumsEx )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ BYTE num,
            /* [in] */ BSTR passwd,
            /* [in] */ BYTE type,
            /* [in] */ double sum,
            /* [in] */ BSTR note,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EnableBarcode )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ unsigned char __MIDL_0016,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FormatBarcode )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ BSTR __MIDL_0017,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *PrintBarcode )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ BSTR __MIDL_0018,
            /* [in] */ BYTE __MIDL_0019,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetLineWidth )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ int __MIDL_0020,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPrintMode )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ DWORD __MIDL_0021,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OpenTillEx )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ unsigned char __MIDL_0022,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OpenSerialPort )( 
            IZekaFP __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CloseSerialPort )( 
            IZekaFP __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Storno )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ BSTR name,
            /* [in] */ BYTE taxgrp,
            /* [in] */ double price,
            /* [in] */ double quantity,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SellFreeDiv )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ BSTR name,
            /* [in] */ BYTE taxgrp,
            /* [in] */ double price,
            /* [in] */ double quantity,
            /* [in] */ double discount,
            /* [in] */ unsigned char flag,
            DWORD divider,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *TerminateBon )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ BOOL __MIDL_0023,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadFiscalMemory2 )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ BSTR filename,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddDiscount )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ BOOL dotrans,
            /* [in] */ BOOL doauto,
            /* [in] */ BOOL dodisplay,
            /* [in] */ BOOL dopercents,
            /* [in] */ double discount,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SellDBEx2 )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ BOOL isVoid,
            /* [in] */ DWORD number,
            /* [in] */ double price,
            /* [in] */ double quantity,
            /* [in] */ double discount,
            /* [in] */ unsigned char flag,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetLineWidth )( 
            IZekaFP __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pChars);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetArticleInfo3 )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ DWORD num,
            /* [in] */ BSTR name,
            /* [in] */ double price,
            /* [in] */ BYTE taxgrp,
            /* [in] */ WORD department,
            /* [in] */ BSTR unit,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetArticleUnit )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ DWORD number,
            /* [retval][out] */ BSTR __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPayTypeEx )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ BYTE type,
            /* [in] */ BSTR line,
            /* [in] */ double exchRate,
            /* [in] */ int code,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetStartDateFM )( 
            IZekaFP __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *PrintTextKP )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ BSTR text,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *PrintTextKP2 )( 
            IZekaFP __RPC_FAR * This,
            /* [in] */ BSTR format,
            /* [in] */ int flags,
            /* [in] */ BSTR text_param,
            /* [in] */ double numeric_param,
            /* [retval][out] */ long __RPC_FAR *pRes);
        
        END_INTERFACE
    } IZekaFPVtbl;

    interface IZekaFP
    {
        CONST_VTBL struct IZekaFPVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IZekaFP_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IZekaFP_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IZekaFP_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IZekaFP_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IZekaFP_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IZekaFP_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IZekaFP_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IZekaFP_GetCurrentBonInfo(This,pVal)	\
    (This)->lpVtbl -> GetCurrentBonInfo(This,pVal)

#define IZekaFP_Setup(This,wCom,baud,retries,retryWait)	\
    (This)->lpVtbl -> Setup(This,wCom,baud,retries,retryWait)

#define IZekaFP_get_errorCode(This,pVal)	\
    (This)->lpVtbl -> get_errorCode(This,pVal)

#define IZekaFP_Diagnostic(This,pRes)	\
    (This)->lpVtbl -> Diagnostic(This,pRes)

#define IZekaFP_DisplayClear(This,pRes)	\
    (This)->lpVtbl -> DisplayClear(This,pRes)

#define IZekaFP_DisplayDateTime(This,pRes)	\
    (This)->lpVtbl -> DisplayDateTime(This,pRes)

#define IZekaFP_OpenTill(This,pRes)	\
    (This)->lpVtbl -> OpenTill(This,pRes)

#define IZekaFP_LineFeed(This,pRes)	\
    (This)->lpVtbl -> LineFeed(This,pRes)

#define IZekaFP_PrintLogo(This,pRes)	\
    (This)->lpVtbl -> PrintLogo(This,pRes)

#define IZekaFP_CloseBon(This,pRes)	\
    (This)->lpVtbl -> CloseBon(This,pRes)

#define IZekaFP_CloseFiscalBon(This,pRes)	\
    (This)->lpVtbl -> CloseFiscalBon(This,pRes)

#define IZekaFP_PrintDuplicate(This,pRes)	\
    (This)->lpVtbl -> PrintDuplicate(This,pRes)

#define IZekaFP_SetLocalDateTime(This,pRes)	\
    (This)->lpVtbl -> SetLocalDateTime(This,pRes)

#define IZekaFP_GetTaxNumber(This,pRes)	\
    (This)->lpVtbl -> GetTaxNumber(This,pRes)

#define IZekaFP_GetDecimalPoint(This,pPoint)	\
    (This)->lpVtbl -> GetDecimalPoint(This,pPoint)

#define IZekaFP_GetClicheLine(This,num,pRes)	\
    (This)->lpVtbl -> GetClicheLine(This,num,pRes)

#define IZekaFP_OpenBon(This,oper,passwd,pRes)	\
    (This)->lpVtbl -> OpenBon(This,oper,passwd,pRes)

#define IZekaFP_OpenFiscalBon(This,oper,passwd,defPass,dds,pRes)	\
    (This)->lpVtbl -> OpenFiscalBon(This,oper,passwd,defPass,dds,pRes)

#define IZekaFP_SellFree(This,name,taxgrp,price,quantity,discount,pRes)	\
    (This)->lpVtbl -> SellFree(This,name,taxgrp,price,quantity,discount,pRes)

#define IZekaFP_Payment(This,sum,type,noRest,pRes)	\
    (This)->lpVtbl -> Payment(This,sum,type,noRest,pRes)

#define IZekaFP_OfficialSums(This,num,passwd,type,sum,pRes)	\
    (This)->lpVtbl -> OfficialSums(This,num,passwd,type,sum,pRes)

#define IZekaFP_GetBonNumber(This,pNumber)	\
    (This)->lpVtbl -> GetBonNumber(This,pNumber)

#define IZekaFP_SetPayType(This,type,line,pRes)	\
    (This)->lpVtbl -> SetPayType(This,type,line,pRes)

#define IZekaFP_SetParameters(This,fpnum,logo,till,autocut,transparent,pRes)	\
    (This)->lpVtbl -> SetParameters(This,fpnum,logo,till,autocut,transparent,pRes)

#define IZekaFP_SetClicheLine(This,num,text,pRes)	\
    (This)->lpVtbl -> SetClicheLine(This,num,text,pRes)

#define IZekaFP_SetOperatorUserPass(This,oper,name,passwd,pRes)	\
    (This)->lpVtbl -> SetOperatorUserPass(This,oper,name,passwd,pRes)

#define IZekaFP_SetArticleInfo(This,num,name,price,taxgrp,pRes)	\
    (This)->lpVtbl -> SetArticleInfo(This,num,name,price,taxgrp,pRes)

#define IZekaFP_SetLogoFile(This,filename,pRes)	\
    (This)->lpVtbl -> SetLogoFile(This,filename,pRes)

#define IZekaFP_GetFactoryNumber(This,pRes)	\
    (This)->lpVtbl -> GetFactoryNumber(This,pRes)

#define IZekaFP_GetFiscalNumber(This,pRes)	\
    (This)->lpVtbl -> GetFiscalNumber(This,pRes)

#define IZekaFP_SellDB(This,isVoid,number,quantity,discount,pRes)	\
    (This)->lpVtbl -> SellDB(This,isVoid,number,quantity,discount,pRes)

#define IZekaFP_GetTaxPercents(This,pRes)	\
    (This)->lpVtbl -> GetTaxPercents(This,pRes)

#define IZekaFP_GetPayTypes(This,pRes)	\
    (This)->lpVtbl -> GetPayTypes(This,pRes)

#define IZekaFP_GetParameters(This,pRes)	\
    (This)->lpVtbl -> GetParameters(This,pRes)

#define IZekaFP_GetOperatorUserPass(This,oper,pRes)	\
    (This)->lpVtbl -> GetOperatorUserPass(This,oper,pRes)

#define IZekaFP_GetDailySums(This,pRes)	\
    (This)->lpVtbl -> GetDailySums(This,pRes)

#define IZekaFP_GetArticleInfo(This,number,pRes)	\
    (This)->lpVtbl -> GetArticleInfo(This,number,pRes)

#define IZekaFP_GetDailyInfo(This,pRes)	\
    (This)->lpVtbl -> GetDailyInfo(This,pRes)

#define IZekaFP_GetOperatorInfo(This,oper,pRes)	\
    (This)->lpVtbl -> GetOperatorInfo(This,oper,pRes)

#define IZekaFP_GetOperatorReceives(This,oper,pRes)	\
    (This)->lpVtbl -> GetOperatorReceives(This,oper,pRes)

#define IZekaFP_GetDateTime(This,pVal)	\
    (This)->lpVtbl -> GetDateTime(This,pVal)

#define IZekaFP_Display(This,line,pRes)	\
    (This)->lpVtbl -> Display(This,line,pRes)

#define IZekaFP_DisplayLine1(This,line,pRes)	\
    (This)->lpVtbl -> DisplayLine1(This,line,pRes)

#define IZekaFP_DisplayLine2(This,line,pRes)	\
    (This)->lpVtbl -> DisplayLine2(This,line,pRes)

#define IZekaFP_GetVersion(This,pRes)	\
    (This)->lpVtbl -> GetVersion(This,pRes)

#define IZekaFP_GetInputBuffer(This,pRes)	\
    (This)->lpVtbl -> GetInputBuffer(This,pRes)

#define IZekaFP_GetResponseBuffer(This,pRes)	\
    (This)->lpVtbl -> GetResponseBuffer(This,pRes)

#define IZekaFP_GetInputHexFormated(This,pRes)	\
    (This)->lpVtbl -> GetInputHexFormated(This,pRes)

#define IZekaFP_GetResponseHexFormated(This,pRes)	\
    (This)->lpVtbl -> GetResponseHexFormated(This,pRes)

#define IZekaFP_GetErrorString(This,error,lang,pRes)	\
    (This)->lpVtbl -> GetErrorString(This,error,lang,pRes)

#define IZekaFP_GetOperatorIncomes(This,oper,pRes)	\
    (This)->lpVtbl -> GetOperatorIncomes(This,oper,pRes)

#define IZekaFP_GetOperatorExpenses(This,oper,pRes)	\
    (This)->lpVtbl -> GetOperatorExpenses(This,oper,pRes)

#define IZekaFP_GetDailyPayments(This,pRes)	\
    (This)->lpVtbl -> GetDailyPayments(This,pRes)

#define IZekaFP_GetDailyIncomes(This,pRes)	\
    (This)->lpVtbl -> GetDailyIncomes(This,pRes)

#define IZekaFP_GetDailyOfficialIncomes(This,pRes)	\
    (This)->lpVtbl -> GetDailyOfficialIncomes(This,pRes)

#define IZekaFP_GetDailyOfficialExpenses(This,pRes)	\
    (This)->lpVtbl -> GetDailyOfficialExpenses(This,pRes)

#define IZekaFP_CalcIntermediateSum(This,doprint,dodisplay,dopercents,discount,pRes)	\
    (This)->lpVtbl -> CalcIntermediateSum(This,doprint,dodisplay,dopercents,discount,pRes)

#define IZekaFP_GetLastFiscalReportData(This,pRes)	\
    (This)->lpVtbl -> GetLastFiscalReportData(This,pRes)

#define IZekaFP_ReportSpecialFiscal(This,pRes)	\
    (This)->lpVtbl -> ReportSpecialFiscal(This,pRes)

#define IZekaFP_ReportFiscalByBlock(This,detailed,startNumber,endNumber,pRes)	\
    (This)->lpVtbl -> ReportFiscalByBlock(This,detailed,startNumber,endNumber,pRes)

#define IZekaFP_ReportDaily(This,zero,extended,pRes)	\
    (This)->lpVtbl -> ReportDaily(This,zero,extended,pRes)

#define IZekaFP_ReportArticles(This,zero,pRes)	\
    (This)->lpVtbl -> ReportArticles(This,zero,pRes)

#define IZekaFP_SetDateTime(This,datetime,pRes)	\
    (This)->lpVtbl -> SetDateTime(This,datetime,pRes)

#define IZekaFP_ReportFiscalByDate(This,detailed,start,end,pRes)	\
    (This)->lpVtbl -> ReportFiscalByDate(This,detailed,start,end,pRes)

#define IZekaFP_ReportOperator(This,zero,oper,pRes)	\
    (This)->lpVtbl -> ReportOperator(This,zero,oper,pRes)

#define IZekaFP_PrintText(This,text,align,pRes)	\
    (This)->lpVtbl -> PrintText(This,text,align,pRes)

#define IZekaFP_GetDailyReport(This,pRes)	\
    (This)->lpVtbl -> GetDailyReport(This,pRes)

#define IZekaFP_GetOperatorCounter(This,oper,pRes)	\
    (This)->lpVtbl -> GetOperatorCounter(This,oper,pRes)

#define IZekaFP_SetExternalDisplayFile(This,password,filename,pRes)	\
    (This)->lpVtbl -> SetExternalDisplayFile(This,password,filename,pRes)

#define IZekaFP_ReadFiscalMemory(This,filename,pRes)	\
    (This)->lpVtbl -> ReadFiscalMemory(This,filename,pRes)

#define IZekaFP_FindFirstFPCOM(This,pRes)	\
    (This)->lpVtbl -> FindFirstFPCOM(This,pRes)

#define IZekaFP_PaperCut(This,pRes)	\
    (This)->lpVtbl -> PaperCut(This,pRes)

#define IZekaFP_GetStatus(This,pRes)	\
    (This)->lpVtbl -> GetStatus(This,pRes)

#define IZekaFP_GetFreeFiscalSpace(This,pRecords)	\
    (This)->lpVtbl -> GetFreeFiscalSpace(This,pRecords)

#define IZekaFP_get_zfpType(This,pVal)	\
    (This)->lpVtbl -> get_zfpType(This,pVal)

#define IZekaFP_put_zfpType(This,newVal)	\
    (This)->lpVtbl -> put_zfpType(This,newVal)

#define IZekaFP_OpenInvoice(This,oper,passwd,client,receiver,vatNum,identNum,address,pRes)	\
    (This)->lpVtbl -> OpenInvoice(This,oper,passwd,client,receiver,vatNum,identNum,address,pRes)

#define IZekaFP_BusyWait(This,timeout,pRes)	\
    (This)->lpVtbl -> BusyWait(This,timeout,pRes)

#define IZekaFP_SetAutoBusyWait(This,timeout)	\
    (This)->lpVtbl -> SetAutoBusyWait(This,timeout)

#define IZekaFP_SetSerialNumber(This,password,manifactureNum,fiscalNum,controlSum,pRes)	\
    (This)->lpVtbl -> SetSerialNumber(This,password,manifactureNum,fiscalNum,controlSum,pRes)

#define IZekaFP_SetTaxNumber(This,password,taxNum,fiscalNum,pRes)	\
    (This)->lpVtbl -> SetTaxNumber(This,password,taxNum,fiscalNum,pRes)

#define IZekaFP_MakeFiscal(This,password,pRes)	\
    (This)->lpVtbl -> MakeFiscal(This,password,pRes)

#define IZekaFP_SetTaxPercents(This,password,tgr1,tgr2,tgr3,tgr4,pRes)	\
    (This)->lpVtbl -> SetTaxPercents(This,password,tgr1,tgr2,tgr3,tgr4,pRes)

#define IZekaFP_SetDecimalPoint(This,password,point,pRes)	\
    (This)->lpVtbl -> SetDecimalPoint(This,password,point,pRes)

#define IZekaFP_GetEJMode(This,pIsShort)	\
    (This)->lpVtbl -> GetEJMode(This,pIsShort)

#define IZekaFP_SetEJMode(This,bShort,pRes)	\
    (This)->lpVtbl -> SetEJMode(This,bShort,pRes)

#define IZekaFP_ReportEJ(This,pRes)	\
    (This)->lpVtbl -> ReportEJ(This,pRes)

#define IZekaFP_SellDepartment(This,name,depNum,price,quantity,discount,pRes)	\
    (This)->lpVtbl -> SellDepartment(This,name,depNum,price,quantity,discount,pRes)

#define IZekaFP_SetDepartment(This,number,name,taxgrp,pRes)	\
    (This)->lpVtbl -> SetDepartment(This,number,name,taxgrp,pRes)

#define IZekaFP_GetDepartment(This,number,pRes)	\
    (This)->lpVtbl -> GetDepartment(This,number,pRes)

#define IZekaFP_SetArticleInfoEx(This,num,name,price,taxgrp,department,pRes)	\
    (This)->lpVtbl -> SetArticleInfoEx(This,num,name,price,taxgrp,department,pRes)

#define IZekaFP_CalcIntermediateSum2(This,doprint,dodisplay,dopercents,discount,taxgrp,pRes)	\
    (This)->lpVtbl -> CalcIntermediateSum2(This,doprint,dodisplay,dopercents,discount,taxgrp,pRes)

#define IZekaFP_ReportEJ2(This,num,pRes)	\
    (This)->lpVtbl -> ReportEJ2(This,num,pRes)

#define IZekaFP_SetTaxPercentsEU(This,password,tgr1,tgr2,tgr3,tgr4,tgr5,tgr6,tgr7,tgr8,pRes)	\
    (This)->lpVtbl -> SetTaxPercentsEU(This,password,tgr1,tgr2,tgr3,tgr4,tgr5,tgr6,tgr7,tgr8,pRes)

#define IZekaFP_SetPayTypeEU(This,type,line,exchRate,pRes)	\
    (This)->lpVtbl -> SetPayTypeEU(This,type,line,exchRate,pRes)

#define IZekaFP_GetOperatorChangeEU(This,oper,pRes)	\
    (This)->lpVtbl -> GetOperatorChangeEU(This,oper,pRes)

#define IZekaFP_SetInvoiceNumbersRangeEU(This,startNum,lastNum,pRes)	\
    (This)->lpVtbl -> SetInvoiceNumbersRangeEU(This,startNum,lastNum,pRes)

#define IZekaFP_PaymentEU(This,sum,type,noChange,changeType,pRes)	\
    (This)->lpVtbl -> PaymentEU(This,sum,type,noChange,changeType,pRes)

#define IZekaFP_SetParametersEU(This,fpnum,logo,till,autocut,transparent,shortEJ,currency,pRes)	\
    (This)->lpVtbl -> SetParametersEU(This,fpnum,logo,till,autocut,transparent,shortEJ,currency,pRes)

#define IZekaFP_SendCommandDirect(This,cmd,pRes)	\
    (This)->lpVtbl -> SendCommandDirect(This,cmd,pRes)

#define IZekaFP_GetDailyChangeEU(This,pRes)	\
    (This)->lpVtbl -> GetDailyChangeEU(This,pRes)

#define IZekaFP_UpdateClicheKE(This,mode,password,pRes)	\
    (This)->lpVtbl -> UpdateClicheKE(This,mode,password,pRes)

#define IZekaFP_Setup2(This,wCom,baud,retries,retryWait)	\
    (This)->lpVtbl -> Setup2(This,wCom,baud,retries,retryWait)

#define IZekaFP_OpenBonWithEJ(This,oper,passwd,hasEJ,pRes)	\
    (This)->lpVtbl -> OpenBonWithEJ(This,oper,passwd,hasEJ,pRes)

#define IZekaFP_get_zfplibVersion(This,pVal)	\
    (This)->lpVtbl -> get_zfplibVersion(This,pVal)

#define IZekaFP_GetInvoiceNextNumberEU(This,pRes)	\
    (This)->lpVtbl -> GetInvoiceNextNumberEU(This,pRes)

#define IZekaFP_SetLogo(This,logo,pRes)	\
    (This)->lpVtbl -> SetLogo(This,logo,pRes)

#define IZekaFP_GetLogoInfo(This,pRes)	\
    (This)->lpVtbl -> GetLogoInfo(This,pRes)

#define IZekaFP_FindFirstFPCOMEx(This,pRes)	\
    (This)->lpVtbl -> FindFirstFPCOMEx(This,pRes)

#define IZekaFP_SetLogoFileEx(This,logo_id,filename,pRes)	\
    (This)->lpVtbl -> SetLogoFileEx(This,logo_id,filename,pRes)

#define IZekaFP_PrintLogoEx(This,logo_id,pRes)	\
    (This)->lpVtbl -> PrintLogoEx(This,logo_id,pRes)

#define IZekaFP_CloseBonInCash(This,pRes)	\
    (This)->lpVtbl -> CloseBonInCash(This,pRes)

#define IZekaFP_PaymentEx(This,sum,type,noChange,changeType,fPaidExactSum,pRes)	\
    (This)->lpVtbl -> PaymentEx(This,sum,type,noChange,changeType,fPaidExactSum,pRes)

#define IZekaFP_GetVersionGS(This,pRes)	\
    (This)->lpVtbl -> GetVersionGS(This,pRes)

#define IZekaFP_EnableCommGS(This,__MIDL_0015,device_no,pRes)	\
    (This)->lpVtbl -> EnableCommGS(This,__MIDL_0015,device_no,pRes)

#define IZekaFP_SetSpeedGS(This,speed,pRes)	\
    (This)->lpVtbl -> SetSpeedGS(This,speed,pRes)

#define IZekaFP_LoadScaleProtocolGS(This,protocol,pRes)	\
    (This)->lpVtbl -> LoadScaleProtocolGS(This,protocol,pRes)

#define IZekaFP_SellDepartmentEx(This,name,depNum,price,quantity,discount,flag,pRes)	\
    (This)->lpVtbl -> SellDepartmentEx(This,name,depNum,price,quantity,discount,flag,pRes)

#define IZekaFP_SellFreeEx(This,name,taxgrp,price,quantity,discount,flag,pRes)	\
    (This)->lpVtbl -> SellFreeEx(This,name,taxgrp,price,quantity,discount,flag,pRes)

#define IZekaFP_SellDBEx(This,isVoid,number,quantity,discount,flag,pRes)	\
    (This)->lpVtbl -> SellDBEx(This,isVoid,number,quantity,discount,flag,pRes)

#define IZekaFP_GetArticleInfoEx(This,number,pRes)	\
    (This)->lpVtbl -> GetArticleInfoEx(This,number,pRes)

#define IZekaFP_SetArticleInfo2(This,num,name,price,taxgrp,department,pRes)	\
    (This)->lpVtbl -> SetArticleInfo2(This,num,name,price,taxgrp,department,pRes)

#define IZekaFP_ReportDepartments(This,zero,pRes)	\
    (This)->lpVtbl -> ReportDepartments(This,zero,pRes)

#define IZekaFP_OfficialSumsEx(This,num,passwd,type,sum,note,pRes)	\
    (This)->lpVtbl -> OfficialSumsEx(This,num,passwd,type,sum,note,pRes)

#define IZekaFP_EnableBarcode(This,__MIDL_0016,pRes)	\
    (This)->lpVtbl -> EnableBarcode(This,__MIDL_0016,pRes)

#define IZekaFP_FormatBarcode(This,__MIDL_0017,pRes)	\
    (This)->lpVtbl -> FormatBarcode(This,__MIDL_0017,pRes)

#define IZekaFP_PrintBarcode(This,__MIDL_0018,__MIDL_0019,pRes)	\
    (This)->lpVtbl -> PrintBarcode(This,__MIDL_0018,__MIDL_0019,pRes)

#define IZekaFP_SetLineWidth(This,__MIDL_0020,pRes)	\
    (This)->lpVtbl -> SetLineWidth(This,__MIDL_0020,pRes)

#define IZekaFP_SetPrintMode(This,__MIDL_0021,pRes)	\
    (This)->lpVtbl -> SetPrintMode(This,__MIDL_0021,pRes)

#define IZekaFP_OpenTillEx(This,__MIDL_0022,pRes)	\
    (This)->lpVtbl -> OpenTillEx(This,__MIDL_0022,pRes)

#define IZekaFP_OpenSerialPort(This,pRes)	\
    (This)->lpVtbl -> OpenSerialPort(This,pRes)

#define IZekaFP_CloseSerialPort(This,pRes)	\
    (This)->lpVtbl -> CloseSerialPort(This,pRes)

#define IZekaFP_Storno(This,name,taxgrp,price,quantity,pRes)	\
    (This)->lpVtbl -> Storno(This,name,taxgrp,price,quantity,pRes)

#define IZekaFP_SellFreeDiv(This,name,taxgrp,price,quantity,discount,flag,divider,pRes)	\
    (This)->lpVtbl -> SellFreeDiv(This,name,taxgrp,price,quantity,discount,flag,divider,pRes)

#define IZekaFP_TerminateBon(This,__MIDL_0023,pRes)	\
    (This)->lpVtbl -> TerminateBon(This,__MIDL_0023,pRes)

#define IZekaFP_ReadFiscalMemory2(This,filename,pRes)	\
    (This)->lpVtbl -> ReadFiscalMemory2(This,filename,pRes)

#define IZekaFP_AddDiscount(This,dotrans,doauto,dodisplay,dopercents,discount,pRes)	\
    (This)->lpVtbl -> AddDiscount(This,dotrans,doauto,dodisplay,dopercents,discount,pRes)

#define IZekaFP_SellDBEx2(This,isVoid,number,price,quantity,discount,flag,pRes)	\
    (This)->lpVtbl -> SellDBEx2(This,isVoid,number,price,quantity,discount,flag,pRes)

#define IZekaFP_GetLineWidth(This,pChars)	\
    (This)->lpVtbl -> GetLineWidth(This,pChars)

#define IZekaFP_SetArticleInfo3(This,num,name,price,taxgrp,department,unit,pRes)	\
    (This)->lpVtbl -> SetArticleInfo3(This,num,name,price,taxgrp,department,unit,pRes)

#define IZekaFP_GetArticleUnit(This,number,pRes)	\
    (This)->lpVtbl -> GetArticleUnit(This,number,pRes)

#define IZekaFP_SetPayTypeEx(This,type,line,exchRate,code,pRes)	\
    (This)->lpVtbl -> SetPayTypeEx(This,type,line,exchRate,code,pRes)

#define IZekaFP_GetStartDateFM(This,pRes)	\
    (This)->lpVtbl -> GetStartDateFM(This,pRes)

#define IZekaFP_PrintTextKP(This,text,pRes)	\
    (This)->lpVtbl -> PrintTextKP(This,text,pRes)

#define IZekaFP_PrintTextKP2(This,format,flags,text_param,numeric_param,pRes)	\
    (This)->lpVtbl -> PrintTextKP2(This,format,flags,text_param,numeric_param,pRes)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_GetCurrentBonInfo_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [retval][out] */ LPDISPATCH __RPC_FAR *pVal);


void __RPC_STUB IZekaFP_GetCurrentBonInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_Setup_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ WORD wCom,
    /* [in] */ DWORD baud,
    /* [in] */ WORD retries,
    /* [in] */ DWORD retryWait);


void __RPC_STUB IZekaFP_Setup_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IZekaFP_get_errorCode_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IZekaFP_get_errorCode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_Diagnostic_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_Diagnostic_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_DisplayClear_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_DisplayClear_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_DisplayDateTime_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_DisplayDateTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_OpenTill_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_OpenTill_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_LineFeed_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_LineFeed_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_PrintLogo_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_PrintLogo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_CloseBon_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_CloseBon_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_CloseFiscalBon_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_CloseFiscalBon_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_PrintDuplicate_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_PrintDuplicate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_SetLocalDateTime_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_SetLocalDateTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_GetTaxNumber_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_GetTaxNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_GetDecimalPoint_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pPoint);


void __RPC_STUB IZekaFP_GetDecimalPoint_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_GetClicheLine_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ BYTE num,
    /* [retval][out] */ BSTR __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_GetClicheLine_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_OpenBon_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ BYTE oper,
    /* [in] */ BSTR passwd,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_OpenBon_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_OpenFiscalBon_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ BYTE oper,
    /* [in] */ BSTR passwd,
    /* [in] */ BYTE defPass,
    /* [in] */ BYTE dds,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_OpenFiscalBon_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_SellFree_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ BSTR name,
    /* [in] */ BYTE taxgrp,
    /* [in] */ double price,
    /* [in] */ double quantity,
    /* [in] */ double discount,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_SellFree_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_Payment_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ double sum,
    /* [in] */ BYTE type,
    /* [in] */ BOOL noRest,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_Payment_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_OfficialSums_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ BYTE num,
    /* [in] */ BSTR passwd,
    /* [in] */ BYTE type,
    /* [in] */ double sum,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_OfficialSums_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_GetBonNumber_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pNumber);


void __RPC_STUB IZekaFP_GetBonNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_SetPayType_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ BYTE type,
    /* [in] */ BSTR line,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_SetPayType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_SetParameters_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ WORD fpnum,
    /* [in] */ BOOL logo,
    /* [in] */ BOOL till,
    /* [in] */ BOOL autocut,
    /* [in] */ BOOL transparent,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_SetParameters_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_SetClicheLine_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ BYTE num,
    /* [in] */ BSTR text,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_SetClicheLine_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_SetOperatorUserPass_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ BYTE oper,
    /* [in] */ BSTR name,
    /* [in] */ BSTR passwd,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_SetOperatorUserPass_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_SetArticleInfo_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ WORD num,
    /* [in] */ BSTR name,
    /* [in] */ double price,
    /* [in] */ BYTE taxgrp,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_SetArticleInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_SetLogoFile_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ BSTR filename,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_SetLogoFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_GetFactoryNumber_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_GetFactoryNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_GetFiscalNumber_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_GetFiscalNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_SellDB_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ BOOL isVoid,
    /* [in] */ WORD number,
    /* [in] */ double quantity,
    /* [in] */ double discount,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_SellDB_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_GetTaxPercents_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [retval][out] */ LPDISPATCH __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_GetTaxPercents_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_GetPayTypes_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [retval][out] */ LPDISPATCH __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_GetPayTypes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_GetParameters_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [retval][out] */ LPDISPATCH __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_GetParameters_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_GetOperatorUserPass_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ BYTE oper,
    /* [retval][out] */ LPDISPATCH __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_GetOperatorUserPass_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_GetDailySums_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [retval][out] */ LPDISPATCH __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_GetDailySums_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_GetArticleInfo_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ WORD number,
    /* [retval][out] */ LPDISPATCH __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_GetArticleInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_GetDailyInfo_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [retval][out] */ LPDISPATCH __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_GetDailyInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_GetOperatorInfo_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ BYTE oper,
    /* [retval][out] */ LPDISPATCH __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_GetOperatorInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_GetOperatorReceives_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ BYTE oper,
    /* [retval][out] */ LPDISPATCH __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_GetOperatorReceives_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_GetDateTime_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [retval][out] */ DATE __RPC_FAR *pVal);


void __RPC_STUB IZekaFP_GetDateTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_Display_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ BSTR line,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_Display_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_DisplayLine1_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ BSTR line,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_DisplayLine1_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_DisplayLine2_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ BSTR line,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_DisplayLine2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_GetVersion_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_GetVersion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_GetInputBuffer_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_GetInputBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_GetResponseBuffer_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_GetResponseBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_GetInputHexFormated_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_GetInputHexFormated_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_GetResponseHexFormated_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_GetResponseHexFormated_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_GetErrorString_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ int error,
    /* [in] */ int lang,
    /* [retval][out] */ BSTR __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_GetErrorString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_GetOperatorIncomes_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ BYTE oper,
    /* [retval][out] */ LPDISPATCH __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_GetOperatorIncomes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_GetOperatorExpenses_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ BYTE oper,
    /* [retval][out] */ LPDISPATCH __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_GetOperatorExpenses_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_GetDailyPayments_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [retval][out] */ LPDISPATCH __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_GetDailyPayments_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_GetDailyIncomes_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [retval][out] */ LPDISPATCH __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_GetDailyIncomes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_GetDailyOfficialIncomes_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [retval][out] */ LPDISPATCH __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_GetDailyOfficialIncomes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_GetDailyOfficialExpenses_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [retval][out] */ LPDISPATCH __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_GetDailyOfficialExpenses_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_CalcIntermediateSum_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ BOOL doprint,
    /* [in] */ BOOL dodisplay,
    /* [in] */ BOOL dopercents,
    /* [in] */ double discount,
    /* [retval][out] */ double __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_CalcIntermediateSum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_GetLastFiscalReportData_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [retval][out] */ LPDISPATCH __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_GetLastFiscalReportData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_ReportSpecialFiscal_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_ReportSpecialFiscal_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_ReportFiscalByBlock_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ BOOL detailed,
    /* [in] */ WORD startNumber,
    /* [in] */ WORD endNumber,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_ReportFiscalByBlock_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_ReportDaily_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ BOOL zero,
    /* [in] */ BOOL extended,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_ReportDaily_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_ReportArticles_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ BOOL zero,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_ReportArticles_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_SetDateTime_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ DATE datetime,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_SetDateTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_ReportFiscalByDate_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ BOOL detailed,
    /* [in] */ DATE start,
    /* [in] */ DATE end,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_ReportFiscalByDate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_ReportOperator_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ BOOL zero,
    /* [in] */ BYTE oper,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_ReportOperator_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_PrintText_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ BSTR text,
    /* [in] */ int align,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_PrintText_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_GetDailyReport_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [retval][out] */ LPDISPATCH __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_GetDailyReport_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_GetOperatorCounter_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ BYTE oper,
    /* [retval][out] */ LPDISPATCH __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_GetOperatorCounter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_SetExternalDisplayFile_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ BSTR password,
    /* [in] */ BSTR filename,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_SetExternalDisplayFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_ReadFiscalMemory_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ BSTR filename,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_ReadFiscalMemory_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_FindFirstFPCOM_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [retval][out] */ DWORD __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_FindFirstFPCOM_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_PaperCut_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_PaperCut_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_GetStatus_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [retval][out] */ LPDISPATCH __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_GetStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_GetFreeFiscalSpace_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pRecords);


void __RPC_STUB IZekaFP_GetFreeFiscalSpace_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IZekaFP_get_zfpType_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IZekaFP_get_zfpType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IZekaFP_put_zfpType_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IZekaFP_put_zfpType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_OpenInvoice_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ BYTE oper,
    /* [in] */ BSTR passwd,
    /* [in] */ BSTR client,
    /* [in] */ BSTR receiver,
    /* [in] */ BSTR vatNum,
    /* [in] */ BSTR identNum,
    /* [in] */ BSTR address,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_OpenInvoice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_BusyWait_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ DWORD timeout,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_BusyWait_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_SetAutoBusyWait_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ DWORD timeout);


void __RPC_STUB IZekaFP_SetAutoBusyWait_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_SetSerialNumber_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ BSTR password,
    /* [in] */ BSTR manifactureNum,
    /* [in] */ BSTR fiscalNum,
    /* [in] */ BSTR controlSum,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_SetSerialNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_SetTaxNumber_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ BSTR password,
    /* [in] */ BSTR taxNum,
    /* [in] */ BSTR fiscalNum,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_SetTaxNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_MakeFiscal_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ BSTR password,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_MakeFiscal_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_SetTaxPercents_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ BSTR password,
    /* [in] */ double tgr1,
    /* [in] */ double tgr2,
    /* [in] */ double tgr3,
    /* [in] */ double tgr4,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_SetTaxPercents_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_SetDecimalPoint_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ BSTR password,
    /* [in] */ int point,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_SetDecimalPoint_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_GetEJMode_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pIsShort);


void __RPC_STUB IZekaFP_GetEJMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_SetEJMode_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ BOOL bShort,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_SetEJMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_ReportEJ_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_ReportEJ_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_SellDepartment_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ BSTR name,
    /* [in] */ WORD depNum,
    /* [in] */ double price,
    /* [in] */ double quantity,
    /* [in] */ double discount,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_SellDepartment_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_SetDepartment_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ WORD number,
    /* [in] */ BSTR name,
    /* [in] */ BYTE taxgrp,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_SetDepartment_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_GetDepartment_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ WORD number,
    /* [retval][out] */ LPDISPATCH __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_GetDepartment_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_SetArticleInfoEx_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ WORD num,
    /* [in] */ BSTR name,
    /* [in] */ double price,
    /* [in] */ BYTE taxgrp,
    /* [in] */ WORD department,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_SetArticleInfoEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_CalcIntermediateSum2_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ BOOL doprint,
    /* [in] */ BOOL dodisplay,
    /* [in] */ BOOL dopercents,
    /* [in] */ double discount,
    /* [in] */ short taxgrp,
    /* [retval][out] */ double __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_CalcIntermediateSum2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_ReportEJ2_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ WORD num,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_ReportEJ2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_SetTaxPercentsEU_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ BSTR password,
    /* [in] */ double tgr1,
    /* [in] */ double tgr2,
    /* [in] */ double tgr3,
    /* [in] */ double tgr4,
    /* [in] */ double tgr5,
    /* [in] */ double tgr6,
    /* [in] */ double tgr7,
    /* [in] */ double tgr8,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_SetTaxPercentsEU_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_SetPayTypeEU_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ BYTE type,
    /* [in] */ BSTR line,
    /* [in] */ double exchRate,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_SetPayTypeEU_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_GetOperatorChangeEU_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ BYTE oper,
    /* [retval][out] */ LPDISPATCH __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_GetOperatorChangeEU_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_SetInvoiceNumbersRangeEU_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ BSTR startNum,
    /* [in] */ BSTR lastNum,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_SetInvoiceNumbersRangeEU_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_PaymentEU_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ double sum,
    /* [in] */ BYTE type,
    /* [in] */ BOOL noChange,
    /* [in] */ BYTE changeType,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_PaymentEU_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_SetParametersEU_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ WORD fpnum,
    /* [in] */ BOOL logo,
    /* [in] */ BOOL till,
    /* [in] */ BOOL autocut,
    /* [in] */ BOOL transparent,
    /* [in] */ BOOL shortEJ,
    /* [in] */ BOOL currency,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_SetParametersEU_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_SendCommandDirect_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ BSTR cmd,
    /* [retval][out] */ BSTR __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_SendCommandDirect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_GetDailyChangeEU_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [retval][out] */ LPDISPATCH __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_GetDailyChangeEU_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_UpdateClicheKE_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ BYTE mode,
    /* [in] */ BSTR password,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_UpdateClicheKE_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_Setup2_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ BYTE wCom,
    /* [in] */ long baud,
    /* [in] */ long retries,
    /* [in] */ long retryWait);


void __RPC_STUB IZekaFP_Setup2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_OpenBonWithEJ_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ BYTE oper,
    /* [in] */ BSTR passwd,
    /* [in] */ BOOL hasEJ,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_OpenBonWithEJ_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IZekaFP_get_zfplibVersion_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IZekaFP_get_zfplibVersion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_GetInvoiceNextNumberEU_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [retval][out] */ LPDISPATCH __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_GetInvoiceNextNumberEU_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_SetLogo_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ unsigned char logo,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_SetLogo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_GetLogoInfo_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_GetLogoInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_FindFirstFPCOMEx_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [retval][out] */ DWORD __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_FindFirstFPCOMEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_SetLogoFileEx_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ unsigned char logo_id,
    /* [in] */ BSTR filename,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_SetLogoFileEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_PrintLogoEx_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ unsigned char logo_id,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_PrintLogoEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_CloseBonInCash_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_CloseBonInCash_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_PaymentEx_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ double sum,
    /* [in] */ BYTE type,
    /* [in] */ BOOL noChange,
    /* [in] */ BYTE changeType,
    /* [in] */ BOOL fPaidExactSum,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_PaymentEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_GetVersionGS_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_GetVersionGS_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_EnableCommGS_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ unsigned char __MIDL_0015,
    /* [in] */ WORD device_no,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_EnableCommGS_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_SetSpeedGS_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ unsigned char speed,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_SetSpeedGS_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_LoadScaleProtocolGS_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ BSTR protocol,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_LoadScaleProtocolGS_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_SellDepartmentEx_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ BSTR name,
    /* [in] */ WORD depNum,
    /* [in] */ double price,
    /* [in] */ double quantity,
    /* [in] */ double discount,
    /* [in] */ unsigned char flag,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_SellDepartmentEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_SellFreeEx_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ BSTR name,
    /* [in] */ BYTE taxgrp,
    /* [in] */ double price,
    /* [in] */ double quantity,
    /* [in] */ double discount,
    /* [in] */ unsigned char flag,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_SellFreeEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_SellDBEx_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ BOOL isVoid,
    /* [in] */ DWORD number,
    /* [in] */ double quantity,
    /* [in] */ double discount,
    /* [in] */ unsigned char flag,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_SellDBEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_GetArticleInfoEx_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ DWORD number,
    /* [retval][out] */ LPDISPATCH __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_GetArticleInfoEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_SetArticleInfo2_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ DWORD num,
    /* [in] */ BSTR name,
    /* [in] */ double price,
    /* [in] */ BYTE taxgrp,
    /* [in] */ WORD department,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_SetArticleInfo2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_ReportDepartments_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ BOOL zero,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_ReportDepartments_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_OfficialSumsEx_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ BYTE num,
    /* [in] */ BSTR passwd,
    /* [in] */ BYTE type,
    /* [in] */ double sum,
    /* [in] */ BSTR note,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_OfficialSumsEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_EnableBarcode_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ unsigned char __MIDL_0016,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_EnableBarcode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_FormatBarcode_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ BSTR __MIDL_0017,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_FormatBarcode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_PrintBarcode_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ BSTR __MIDL_0018,
    /* [in] */ BYTE __MIDL_0019,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_PrintBarcode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_SetLineWidth_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ int __MIDL_0020,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_SetLineWidth_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_SetPrintMode_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ DWORD __MIDL_0021,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_SetPrintMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_OpenTillEx_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ unsigned char __MIDL_0022,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_OpenTillEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_OpenSerialPort_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_OpenSerialPort_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_CloseSerialPort_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_CloseSerialPort_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_Storno_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ BSTR name,
    /* [in] */ BYTE taxgrp,
    /* [in] */ double price,
    /* [in] */ double quantity,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_Storno_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_SellFreeDiv_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ BSTR name,
    /* [in] */ BYTE taxgrp,
    /* [in] */ double price,
    /* [in] */ double quantity,
    /* [in] */ double discount,
    /* [in] */ unsigned char flag,
    DWORD divider,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_SellFreeDiv_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_TerminateBon_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ BOOL __MIDL_0023,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_TerminateBon_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_ReadFiscalMemory2_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ BSTR filename,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_ReadFiscalMemory2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_AddDiscount_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ BOOL dotrans,
    /* [in] */ BOOL doauto,
    /* [in] */ BOOL dodisplay,
    /* [in] */ BOOL dopercents,
    /* [in] */ double discount,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_AddDiscount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_SellDBEx2_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ BOOL isVoid,
    /* [in] */ DWORD number,
    /* [in] */ double price,
    /* [in] */ double quantity,
    /* [in] */ double discount,
    /* [in] */ unsigned char flag,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_SellDBEx2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_GetLineWidth_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pChars);


void __RPC_STUB IZekaFP_GetLineWidth_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_SetArticleInfo3_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ DWORD num,
    /* [in] */ BSTR name,
    /* [in] */ double price,
    /* [in] */ BYTE taxgrp,
    /* [in] */ WORD department,
    /* [in] */ BSTR unit,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_SetArticleInfo3_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_GetArticleUnit_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ DWORD number,
    /* [retval][out] */ BSTR __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_GetArticleUnit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_SetPayTypeEx_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ BYTE type,
    /* [in] */ BSTR line,
    /* [in] */ double exchRate,
    /* [in] */ int code,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_SetPayTypeEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_GetStartDateFM_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_GetStartDateFM_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_PrintTextKP_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ BSTR text,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_PrintTextKP_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IZekaFP_PrintTextKP2_Proxy( 
    IZekaFP __RPC_FAR * This,
    /* [in] */ BSTR format,
    /* [in] */ int flags,
    /* [in] */ BSTR text_param,
    /* [in] */ double numeric_param,
    /* [retval][out] */ long __RPC_FAR *pRes);


void __RPC_STUB IZekaFP_PrintTextKP2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IZekaFP_INTERFACE_DEFINED__ */



#ifndef __ZFPCOMLib_LIBRARY_DEFINED__
#define __ZFPCOMLib_LIBRARY_DEFINED__

/* library ZFPCOMLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_ZFPCOMLib;

#ifndef ___IZekaFPEvents_DISPINTERFACE_DEFINED__
#define ___IZekaFPEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IZekaFPEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IZekaFPEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("1CF92986-79B9-418F-9D84-F8052A9C6286")
    _IZekaFPEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IZekaFPEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            _IZekaFPEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            _IZekaFPEvents __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            _IZekaFPEvents __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            _IZekaFPEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            _IZekaFPEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            _IZekaFPEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            _IZekaFPEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } _IZekaFPEventsVtbl;

    interface _IZekaFPEvents
    {
        CONST_VTBL struct _IZekaFPEventsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IZekaFPEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _IZekaFPEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _IZekaFPEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _IZekaFPEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _IZekaFPEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _IZekaFPEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _IZekaFPEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IZekaFPEvents_DISPINTERFACE_DEFINED__ */


#ifndef __IGetCurrentBonInfoRes_INTERFACE_DEFINED__
#define __IGetCurrentBonInfoRes_INTERFACE_DEFINED__

/* interface IGetCurrentBonInfoRes */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IGetCurrentBonInfoRes;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("15F4A466-C600-48AD-9138-AE4E5734ED8B")
    IGetCurrentBonInfoRes : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_flags( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_flags( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_purchases( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_purchases( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_taxgrp1( 
            /* [retval][out] */ double __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_taxgrp1( 
            /* [in] */ double newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_taxgrp2( 
            /* [retval][out] */ double __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_taxgrp2( 
            /* [in] */ double newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_taxgrp3( 
            /* [retval][out] */ double __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_taxgrp3( 
            /* [in] */ double newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_novoid( 
            /* [retval][out] */ BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_novoid( 
            /* [in] */ BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_dds( 
            /* [retval][out] */ BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_dds( 
            /* [in] */ BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_detailed( 
            /* [retval][out] */ BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_detailed( 
            /* [in] */ BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_paystarted( 
            /* [retval][out] */ BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_paystarted( 
            /* [in] */ BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_paid( 
            /* [retval][out] */ BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_paid( 
            /* [in] */ BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_taxgrp4( 
            /* [retval][out] */ double __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_taxgrp4( 
            /* [in] */ double newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_taxgrp5( 
            /* [retval][out] */ double __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_taxgrp5( 
            /* [in] */ double newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_powerdown( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_powerdown( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_invoice( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_invoice( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_taxgrp6( 
            /* [retval][out] */ double __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_taxgrp6( 
            /* [in] */ double newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_taxgrp7( 
            /* [retval][out] */ double __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_taxgrp7( 
            /* [in] */ double newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_taxgrp8( 
            /* [retval][out] */ double __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_taxgrp8( 
            /* [in] */ double newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_change( 
            /* [retval][out] */ double __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_change( 
            /* [in] */ double newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_changeType( 
            /* [retval][out] */ short __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_changeType( 
            /* [in] */ short newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IGetCurrentBonInfoResVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IGetCurrentBonInfoRes __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IGetCurrentBonInfoRes __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IGetCurrentBonInfoRes __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IGetCurrentBonInfoRes __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IGetCurrentBonInfoRes __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IGetCurrentBonInfoRes __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IGetCurrentBonInfoRes __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_flags )( 
            IGetCurrentBonInfoRes __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_flags )( 
            IGetCurrentBonInfoRes __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_purchases )( 
            IGetCurrentBonInfoRes __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_purchases )( 
            IGetCurrentBonInfoRes __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_taxgrp1 )( 
            IGetCurrentBonInfoRes __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_taxgrp1 )( 
            IGetCurrentBonInfoRes __RPC_FAR * This,
            /* [in] */ double newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_taxgrp2 )( 
            IGetCurrentBonInfoRes __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_taxgrp2 )( 
            IGetCurrentBonInfoRes __RPC_FAR * This,
            /* [in] */ double newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_taxgrp3 )( 
            IGetCurrentBonInfoRes __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_taxgrp3 )( 
            IGetCurrentBonInfoRes __RPC_FAR * This,
            /* [in] */ double newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_novoid )( 
            IGetCurrentBonInfoRes __RPC_FAR * This,
            /* [retval][out] */ BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_novoid )( 
            IGetCurrentBonInfoRes __RPC_FAR * This,
            /* [in] */ BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_dds )( 
            IGetCurrentBonInfoRes __RPC_FAR * This,
            /* [retval][out] */ BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_dds )( 
            IGetCurrentBonInfoRes __RPC_FAR * This,
            /* [in] */ BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_detailed )( 
            IGetCurrentBonInfoRes __RPC_FAR * This,
            /* [retval][out] */ BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_detailed )( 
            IGetCurrentBonInfoRes __RPC_FAR * This,
            /* [in] */ BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_paystarted )( 
            IGetCurrentBonInfoRes __RPC_FAR * This,
            /* [retval][out] */ BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_paystarted )( 
            IGetCurrentBonInfoRes __RPC_FAR * This,
            /* [in] */ BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_paid )( 
            IGetCurrentBonInfoRes __RPC_FAR * This,
            /* [retval][out] */ BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_paid )( 
            IGetCurrentBonInfoRes __RPC_FAR * This,
            /* [in] */ BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_taxgrp4 )( 
            IGetCurrentBonInfoRes __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_taxgrp4 )( 
            IGetCurrentBonInfoRes __RPC_FAR * This,
            /* [in] */ double newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_taxgrp5 )( 
            IGetCurrentBonInfoRes __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_taxgrp5 )( 
            IGetCurrentBonInfoRes __RPC_FAR * This,
            /* [in] */ double newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_powerdown )( 
            IGetCurrentBonInfoRes __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_powerdown )( 
            IGetCurrentBonInfoRes __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_invoice )( 
            IGetCurrentBonInfoRes __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_invoice )( 
            IGetCurrentBonInfoRes __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_taxgrp6 )( 
            IGetCurrentBonInfoRes __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_taxgrp6 )( 
            IGetCurrentBonInfoRes __RPC_FAR * This,
            /* [in] */ double newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_taxgrp7 )( 
            IGetCurrentBonInfoRes __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_taxgrp7 )( 
            IGetCurrentBonInfoRes __RPC_FAR * This,
            /* [in] */ double newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_taxgrp8 )( 
            IGetCurrentBonInfoRes __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_taxgrp8 )( 
            IGetCurrentBonInfoRes __RPC_FAR * This,
            /* [in] */ double newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_change )( 
            IGetCurrentBonInfoRes __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_change )( 
            IGetCurrentBonInfoRes __RPC_FAR * This,
            /* [in] */ double newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_changeType )( 
            IGetCurrentBonInfoRes __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_changeType )( 
            IGetCurrentBonInfoRes __RPC_FAR * This,
            /* [in] */ short newVal);
        
        END_INTERFACE
    } IGetCurrentBonInfoResVtbl;

    interface IGetCurrentBonInfoRes
    {
        CONST_VTBL struct IGetCurrentBonInfoResVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGetCurrentBonInfoRes_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IGetCurrentBonInfoRes_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IGetCurrentBonInfoRes_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IGetCurrentBonInfoRes_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IGetCurrentBonInfoRes_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IGetCurrentBonInfoRes_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IGetCurrentBonInfoRes_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IGetCurrentBonInfoRes_get_flags(This,pVal)	\
    (This)->lpVtbl -> get_flags(This,pVal)

#define IGetCurrentBonInfoRes_put_flags(This,newVal)	\
    (This)->lpVtbl -> put_flags(This,newVal)

#define IGetCurrentBonInfoRes_get_purchases(This,pVal)	\
    (This)->lpVtbl -> get_purchases(This,pVal)

#define IGetCurrentBonInfoRes_put_purchases(This,newVal)	\
    (This)->lpVtbl -> put_purchases(This,newVal)

#define IGetCurrentBonInfoRes_get_taxgrp1(This,pVal)	\
    (This)->lpVtbl -> get_taxgrp1(This,pVal)

#define IGetCurrentBonInfoRes_put_taxgrp1(This,newVal)	\
    (This)->lpVtbl -> put_taxgrp1(This,newVal)

#define IGetCurrentBonInfoRes_get_taxgrp2(This,pVal)	\
    (This)->lpVtbl -> get_taxgrp2(This,pVal)

#define IGetCurrentBonInfoRes_put_taxgrp2(This,newVal)	\
    (This)->lpVtbl -> put_taxgrp2(This,newVal)

#define IGetCurrentBonInfoRes_get_taxgrp3(This,pVal)	\
    (This)->lpVtbl -> get_taxgrp3(This,pVal)

#define IGetCurrentBonInfoRes_put_taxgrp3(This,newVal)	\
    (This)->lpVtbl -> put_taxgrp3(This,newVal)

#define IGetCurrentBonInfoRes_get_novoid(This,pVal)	\
    (This)->lpVtbl -> get_novoid(This,pVal)

#define IGetCurrentBonInfoRes_put_novoid(This,newVal)	\
    (This)->lpVtbl -> put_novoid(This,newVal)

#define IGetCurrentBonInfoRes_get_dds(This,pVal)	\
    (This)->lpVtbl -> get_dds(This,pVal)

#define IGetCurrentBonInfoRes_put_dds(This,newVal)	\
    (This)->lpVtbl -> put_dds(This,newVal)

#define IGetCurrentBonInfoRes_get_detailed(This,pVal)	\
    (This)->lpVtbl -> get_detailed(This,pVal)

#define IGetCurrentBonInfoRes_put_detailed(This,newVal)	\
    (This)->lpVtbl -> put_detailed(This,newVal)

#define IGetCurrentBonInfoRes_get_paystarted(This,pVal)	\
    (This)->lpVtbl -> get_paystarted(This,pVal)

#define IGetCurrentBonInfoRes_put_paystarted(This,newVal)	\
    (This)->lpVtbl -> put_paystarted(This,newVal)

#define IGetCurrentBonInfoRes_get_paid(This,pVal)	\
    (This)->lpVtbl -> get_paid(This,pVal)

#define IGetCurrentBonInfoRes_put_paid(This,newVal)	\
    (This)->lpVtbl -> put_paid(This,newVal)

#define IGetCurrentBonInfoRes_get_taxgrp4(This,pVal)	\
    (This)->lpVtbl -> get_taxgrp4(This,pVal)

#define IGetCurrentBonInfoRes_put_taxgrp4(This,newVal)	\
    (This)->lpVtbl -> put_taxgrp4(This,newVal)

#define IGetCurrentBonInfoRes_get_taxgrp5(This,pVal)	\
    (This)->lpVtbl -> get_taxgrp5(This,pVal)

#define IGetCurrentBonInfoRes_put_taxgrp5(This,newVal)	\
    (This)->lpVtbl -> put_taxgrp5(This,newVal)

#define IGetCurrentBonInfoRes_get_powerdown(This,pVal)	\
    (This)->lpVtbl -> get_powerdown(This,pVal)

#define IGetCurrentBonInfoRes_put_powerdown(This,newVal)	\
    (This)->lpVtbl -> put_powerdown(This,newVal)

#define IGetCurrentBonInfoRes_get_invoice(This,pVal)	\
    (This)->lpVtbl -> get_invoice(This,pVal)

#define IGetCurrentBonInfoRes_put_invoice(This,newVal)	\
    (This)->lpVtbl -> put_invoice(This,newVal)

#define IGetCurrentBonInfoRes_get_taxgrp6(This,pVal)	\
    (This)->lpVtbl -> get_taxgrp6(This,pVal)

#define IGetCurrentBonInfoRes_put_taxgrp6(This,newVal)	\
    (This)->lpVtbl -> put_taxgrp6(This,newVal)

#define IGetCurrentBonInfoRes_get_taxgrp7(This,pVal)	\
    (This)->lpVtbl -> get_taxgrp7(This,pVal)

#define IGetCurrentBonInfoRes_put_taxgrp7(This,newVal)	\
    (This)->lpVtbl -> put_taxgrp7(This,newVal)

#define IGetCurrentBonInfoRes_get_taxgrp8(This,pVal)	\
    (This)->lpVtbl -> get_taxgrp8(This,pVal)

#define IGetCurrentBonInfoRes_put_taxgrp8(This,newVal)	\
    (This)->lpVtbl -> put_taxgrp8(This,newVal)

#define IGetCurrentBonInfoRes_get_change(This,pVal)	\
    (This)->lpVtbl -> get_change(This,pVal)

#define IGetCurrentBonInfoRes_put_change(This,newVal)	\
    (This)->lpVtbl -> put_change(This,newVal)

#define IGetCurrentBonInfoRes_get_changeType(This,pVal)	\
    (This)->lpVtbl -> get_changeType(This,pVal)

#define IGetCurrentBonInfoRes_put_changeType(This,newVal)	\
    (This)->lpVtbl -> put_changeType(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGetCurrentBonInfoRes_get_flags_Proxy( 
    IGetCurrentBonInfoRes __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IGetCurrentBonInfoRes_get_flags_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IGetCurrentBonInfoRes_put_flags_Proxy( 
    IGetCurrentBonInfoRes __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IGetCurrentBonInfoRes_put_flags_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGetCurrentBonInfoRes_get_purchases_Proxy( 
    IGetCurrentBonInfoRes __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IGetCurrentBonInfoRes_get_purchases_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IGetCurrentBonInfoRes_put_purchases_Proxy( 
    IGetCurrentBonInfoRes __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IGetCurrentBonInfoRes_put_purchases_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGetCurrentBonInfoRes_get_taxgrp1_Proxy( 
    IGetCurrentBonInfoRes __RPC_FAR * This,
    /* [retval][out] */ double __RPC_FAR *pVal);


void __RPC_STUB IGetCurrentBonInfoRes_get_taxgrp1_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IGetCurrentBonInfoRes_put_taxgrp1_Proxy( 
    IGetCurrentBonInfoRes __RPC_FAR * This,
    /* [in] */ double newVal);


void __RPC_STUB IGetCurrentBonInfoRes_put_taxgrp1_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGetCurrentBonInfoRes_get_taxgrp2_Proxy( 
    IGetCurrentBonInfoRes __RPC_FAR * This,
    /* [retval][out] */ double __RPC_FAR *pVal);


void __RPC_STUB IGetCurrentBonInfoRes_get_taxgrp2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IGetCurrentBonInfoRes_put_taxgrp2_Proxy( 
    IGetCurrentBonInfoRes __RPC_FAR * This,
    /* [in] */ double newVal);


void __RPC_STUB IGetCurrentBonInfoRes_put_taxgrp2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGetCurrentBonInfoRes_get_taxgrp3_Proxy( 
    IGetCurrentBonInfoRes __RPC_FAR * This,
    /* [retval][out] */ double __RPC_FAR *pVal);


void __RPC_STUB IGetCurrentBonInfoRes_get_taxgrp3_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IGetCurrentBonInfoRes_put_taxgrp3_Proxy( 
    IGetCurrentBonInfoRes __RPC_FAR * This,
    /* [in] */ double newVal);


void __RPC_STUB IGetCurrentBonInfoRes_put_taxgrp3_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGetCurrentBonInfoRes_get_novoid_Proxy( 
    IGetCurrentBonInfoRes __RPC_FAR * This,
    /* [retval][out] */ BOOL __RPC_FAR *pVal);


void __RPC_STUB IGetCurrentBonInfoRes_get_novoid_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IGetCurrentBonInfoRes_put_novoid_Proxy( 
    IGetCurrentBonInfoRes __RPC_FAR * This,
    /* [in] */ BOOL newVal);


void __RPC_STUB IGetCurrentBonInfoRes_put_novoid_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGetCurrentBonInfoRes_get_dds_Proxy( 
    IGetCurrentBonInfoRes __RPC_FAR * This,
    /* [retval][out] */ BOOL __RPC_FAR *pVal);


void __RPC_STUB IGetCurrentBonInfoRes_get_dds_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IGetCurrentBonInfoRes_put_dds_Proxy( 
    IGetCurrentBonInfoRes __RPC_FAR * This,
    /* [in] */ BOOL newVal);


void __RPC_STUB IGetCurrentBonInfoRes_put_dds_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGetCurrentBonInfoRes_get_detailed_Proxy( 
    IGetCurrentBonInfoRes __RPC_FAR * This,
    /* [retval][out] */ BOOL __RPC_FAR *pVal);


void __RPC_STUB IGetCurrentBonInfoRes_get_detailed_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IGetCurrentBonInfoRes_put_detailed_Proxy( 
    IGetCurrentBonInfoRes __RPC_FAR * This,
    /* [in] */ BOOL newVal);


void __RPC_STUB IGetCurrentBonInfoRes_put_detailed_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGetCurrentBonInfoRes_get_paystarted_Proxy( 
    IGetCurrentBonInfoRes __RPC_FAR * This,
    /* [retval][out] */ BOOL __RPC_FAR *pVal);


void __RPC_STUB IGetCurrentBonInfoRes_get_paystarted_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IGetCurrentBonInfoRes_put_paystarted_Proxy( 
    IGetCurrentBonInfoRes __RPC_FAR * This,
    /* [in] */ BOOL newVal);


void __RPC_STUB IGetCurrentBonInfoRes_put_paystarted_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGetCurrentBonInfoRes_get_paid_Proxy( 
    IGetCurrentBonInfoRes __RPC_FAR * This,
    /* [retval][out] */ BOOL __RPC_FAR *pVal);


void __RPC_STUB IGetCurrentBonInfoRes_get_paid_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IGetCurrentBonInfoRes_put_paid_Proxy( 
    IGetCurrentBonInfoRes __RPC_FAR * This,
    /* [in] */ BOOL newVal);


void __RPC_STUB IGetCurrentBonInfoRes_put_paid_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGetCurrentBonInfoRes_get_taxgrp4_Proxy( 
    IGetCurrentBonInfoRes __RPC_FAR * This,
    /* [retval][out] */ double __RPC_FAR *pVal);


void __RPC_STUB IGetCurrentBonInfoRes_get_taxgrp4_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IGetCurrentBonInfoRes_put_taxgrp4_Proxy( 
    IGetCurrentBonInfoRes __RPC_FAR * This,
    /* [in] */ double newVal);


void __RPC_STUB IGetCurrentBonInfoRes_put_taxgrp4_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGetCurrentBonInfoRes_get_taxgrp5_Proxy( 
    IGetCurrentBonInfoRes __RPC_FAR * This,
    /* [retval][out] */ double __RPC_FAR *pVal);


void __RPC_STUB IGetCurrentBonInfoRes_get_taxgrp5_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IGetCurrentBonInfoRes_put_taxgrp5_Proxy( 
    IGetCurrentBonInfoRes __RPC_FAR * This,
    /* [in] */ double newVal);


void __RPC_STUB IGetCurrentBonInfoRes_put_taxgrp5_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGetCurrentBonInfoRes_get_powerdown_Proxy( 
    IGetCurrentBonInfoRes __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IGetCurrentBonInfoRes_get_powerdown_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IGetCurrentBonInfoRes_put_powerdown_Proxy( 
    IGetCurrentBonInfoRes __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IGetCurrentBonInfoRes_put_powerdown_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGetCurrentBonInfoRes_get_invoice_Proxy( 
    IGetCurrentBonInfoRes __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IGetCurrentBonInfoRes_get_invoice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IGetCurrentBonInfoRes_put_invoice_Proxy( 
    IGetCurrentBonInfoRes __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IGetCurrentBonInfoRes_put_invoice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGetCurrentBonInfoRes_get_taxgrp6_Proxy( 
    IGetCurrentBonInfoRes __RPC_FAR * This,
    /* [retval][out] */ double __RPC_FAR *pVal);


void __RPC_STUB IGetCurrentBonInfoRes_get_taxgrp6_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IGetCurrentBonInfoRes_put_taxgrp6_Proxy( 
    IGetCurrentBonInfoRes __RPC_FAR * This,
    /* [in] */ double newVal);


void __RPC_STUB IGetCurrentBonInfoRes_put_taxgrp6_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGetCurrentBonInfoRes_get_taxgrp7_Proxy( 
    IGetCurrentBonInfoRes __RPC_FAR * This,
    /* [retval][out] */ double __RPC_FAR *pVal);


void __RPC_STUB IGetCurrentBonInfoRes_get_taxgrp7_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IGetCurrentBonInfoRes_put_taxgrp7_Proxy( 
    IGetCurrentBonInfoRes __RPC_FAR * This,
    /* [in] */ double newVal);


void __RPC_STUB IGetCurrentBonInfoRes_put_taxgrp7_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGetCurrentBonInfoRes_get_taxgrp8_Proxy( 
    IGetCurrentBonInfoRes __RPC_FAR * This,
    /* [retval][out] */ double __RPC_FAR *pVal);


void __RPC_STUB IGetCurrentBonInfoRes_get_taxgrp8_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IGetCurrentBonInfoRes_put_taxgrp8_Proxy( 
    IGetCurrentBonInfoRes __RPC_FAR * This,
    /* [in] */ double newVal);


void __RPC_STUB IGetCurrentBonInfoRes_put_taxgrp8_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGetCurrentBonInfoRes_get_change_Proxy( 
    IGetCurrentBonInfoRes __RPC_FAR * This,
    /* [retval][out] */ double __RPC_FAR *pVal);


void __RPC_STUB IGetCurrentBonInfoRes_get_change_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IGetCurrentBonInfoRes_put_change_Proxy( 
    IGetCurrentBonInfoRes __RPC_FAR * This,
    /* [in] */ double newVal);


void __RPC_STUB IGetCurrentBonInfoRes_put_change_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IGetCurrentBonInfoRes_get_changeType_Proxy( 
    IGetCurrentBonInfoRes __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *pVal);


void __RPC_STUB IGetCurrentBonInfoRes_get_changeType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IGetCurrentBonInfoRes_put_changeType_Proxy( 
    IGetCurrentBonInfoRes __RPC_FAR * This,
    /* [in] */ short newVal);


void __RPC_STUB IGetCurrentBonInfoRes_put_changeType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IGetCurrentBonInfoRes_INTERFACE_DEFINED__ */


#ifndef __ITaxNumbers_INTERFACE_DEFINED__
#define __ITaxNumbers_INTERFACE_DEFINED__

/* interface ITaxNumbers */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ITaxNumbers;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C58962A1-28FB-422A-B3BB-2435C4CB559F")
    ITaxNumbers : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_taxgrp1( 
            /* [retval][out] */ double __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_taxgrp1( 
            /* [in] */ double newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_taxgrp2( 
            /* [retval][out] */ double __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_taxgrp2( 
            /* [in] */ double newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_taxgrp3( 
            /* [retval][out] */ double __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_taxgrp3( 
            /* [in] */ double newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_taxgrp4( 
            /* [retval][out] */ double __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_taxgrp4( 
            /* [in] */ double newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_taxgrp5( 
            /* [retval][out] */ double __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_taxgrp5( 
            /* [in] */ double newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_taxgrp6( 
            /* [retval][out] */ double __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_taxgrp6( 
            /* [in] */ double newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_taxgrp7( 
            /* [retval][out] */ double __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_taxgrp7( 
            /* [in] */ double newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_taxgrp8( 
            /* [retval][out] */ double __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_taxgrp8( 
            /* [in] */ double newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITaxNumbersVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ITaxNumbers __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ITaxNumbers __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ITaxNumbers __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            ITaxNumbers __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            ITaxNumbers __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            ITaxNumbers __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            ITaxNumbers __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_taxgrp1 )( 
            ITaxNumbers __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_taxgrp1 )( 
            ITaxNumbers __RPC_FAR * This,
            /* [in] */ double newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_taxgrp2 )( 
            ITaxNumbers __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_taxgrp2 )( 
            ITaxNumbers __RPC_FAR * This,
            /* [in] */ double newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_taxgrp3 )( 
            ITaxNumbers __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_taxgrp3 )( 
            ITaxNumbers __RPC_FAR * This,
            /* [in] */ double newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_taxgrp4 )( 
            ITaxNumbers __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_taxgrp4 )( 
            ITaxNumbers __RPC_FAR * This,
            /* [in] */ double newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_taxgrp5 )( 
            ITaxNumbers __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_taxgrp5 )( 
            ITaxNumbers __RPC_FAR * This,
            /* [in] */ double newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_taxgrp6 )( 
            ITaxNumbers __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_taxgrp6 )( 
            ITaxNumbers __RPC_FAR * This,
            /* [in] */ double newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_taxgrp7 )( 
            ITaxNumbers __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_taxgrp7 )( 
            ITaxNumbers __RPC_FAR * This,
            /* [in] */ double newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_taxgrp8 )( 
            ITaxNumbers __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_taxgrp8 )( 
            ITaxNumbers __RPC_FAR * This,
            /* [in] */ double newVal);
        
        END_INTERFACE
    } ITaxNumbersVtbl;

    interface ITaxNumbers
    {
        CONST_VTBL struct ITaxNumbersVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITaxNumbers_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITaxNumbers_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITaxNumbers_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITaxNumbers_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ITaxNumbers_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ITaxNumbers_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ITaxNumbers_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ITaxNumbers_get_taxgrp1(This,pVal)	\
    (This)->lpVtbl -> get_taxgrp1(This,pVal)

#define ITaxNumbers_put_taxgrp1(This,newVal)	\
    (This)->lpVtbl -> put_taxgrp1(This,newVal)

#define ITaxNumbers_get_taxgrp2(This,pVal)	\
    (This)->lpVtbl -> get_taxgrp2(This,pVal)

#define ITaxNumbers_put_taxgrp2(This,newVal)	\
    (This)->lpVtbl -> put_taxgrp2(This,newVal)

#define ITaxNumbers_get_taxgrp3(This,pVal)	\
    (This)->lpVtbl -> get_taxgrp3(This,pVal)

#define ITaxNumbers_put_taxgrp3(This,newVal)	\
    (This)->lpVtbl -> put_taxgrp3(This,newVal)

#define ITaxNumbers_get_taxgrp4(This,pVal)	\
    (This)->lpVtbl -> get_taxgrp4(This,pVal)

#define ITaxNumbers_put_taxgrp4(This,newVal)	\
    (This)->lpVtbl -> put_taxgrp4(This,newVal)

#define ITaxNumbers_get_taxgrp5(This,pVal)	\
    (This)->lpVtbl -> get_taxgrp5(This,pVal)

#define ITaxNumbers_put_taxgrp5(This,newVal)	\
    (This)->lpVtbl -> put_taxgrp5(This,newVal)

#define ITaxNumbers_get_taxgrp6(This,pVal)	\
    (This)->lpVtbl -> get_taxgrp6(This,pVal)

#define ITaxNumbers_put_taxgrp6(This,newVal)	\
    (This)->lpVtbl -> put_taxgrp6(This,newVal)

#define ITaxNumbers_get_taxgrp7(This,pVal)	\
    (This)->lpVtbl -> get_taxgrp7(This,pVal)

#define ITaxNumbers_put_taxgrp7(This,newVal)	\
    (This)->lpVtbl -> put_taxgrp7(This,newVal)

#define ITaxNumbers_get_taxgrp8(This,pVal)	\
    (This)->lpVtbl -> get_taxgrp8(This,pVal)

#define ITaxNumbers_put_taxgrp8(This,newVal)	\
    (This)->lpVtbl -> put_taxgrp8(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ITaxNumbers_get_taxgrp1_Proxy( 
    ITaxNumbers __RPC_FAR * This,
    /* [retval][out] */ double __RPC_FAR *pVal);


void __RPC_STUB ITaxNumbers_get_taxgrp1_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ITaxNumbers_put_taxgrp1_Proxy( 
    ITaxNumbers __RPC_FAR * This,
    /* [in] */ double newVal);


void __RPC_STUB ITaxNumbers_put_taxgrp1_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ITaxNumbers_get_taxgrp2_Proxy( 
    ITaxNumbers __RPC_FAR * This,
    /* [retval][out] */ double __RPC_FAR *pVal);


void __RPC_STUB ITaxNumbers_get_taxgrp2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ITaxNumbers_put_taxgrp2_Proxy( 
    ITaxNumbers __RPC_FAR * This,
    /* [in] */ double newVal);


void __RPC_STUB ITaxNumbers_put_taxgrp2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ITaxNumbers_get_taxgrp3_Proxy( 
    ITaxNumbers __RPC_FAR * This,
    /* [retval][out] */ double __RPC_FAR *pVal);


void __RPC_STUB ITaxNumbers_get_taxgrp3_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ITaxNumbers_put_taxgrp3_Proxy( 
    ITaxNumbers __RPC_FAR * This,
    /* [in] */ double newVal);


void __RPC_STUB ITaxNumbers_put_taxgrp3_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ITaxNumbers_get_taxgrp4_Proxy( 
    ITaxNumbers __RPC_FAR * This,
    /* [retval][out] */ double __RPC_FAR *pVal);


void __RPC_STUB ITaxNumbers_get_taxgrp4_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ITaxNumbers_put_taxgrp4_Proxy( 
    ITaxNumbers __RPC_FAR * This,
    /* [in] */ double newVal);


void __RPC_STUB ITaxNumbers_put_taxgrp4_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ITaxNumbers_get_taxgrp5_Proxy( 
    ITaxNumbers __RPC_FAR * This,
    /* [retval][out] */ double __RPC_FAR *pVal);


void __RPC_STUB ITaxNumbers_get_taxgrp5_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ITaxNumbers_put_taxgrp5_Proxy( 
    ITaxNumbers __RPC_FAR * This,
    /* [in] */ double newVal);


void __RPC_STUB ITaxNumbers_put_taxgrp5_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ITaxNumbers_get_taxgrp6_Proxy( 
    ITaxNumbers __RPC_FAR * This,
    /* [retval][out] */ double __RPC_FAR *pVal);


void __RPC_STUB ITaxNumbers_get_taxgrp6_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ITaxNumbers_put_taxgrp6_Proxy( 
    ITaxNumbers __RPC_FAR * This,
    /* [in] */ double newVal);


void __RPC_STUB ITaxNumbers_put_taxgrp6_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ITaxNumbers_get_taxgrp7_Proxy( 
    ITaxNumbers __RPC_FAR * This,
    /* [retval][out] */ double __RPC_FAR *pVal);


void __RPC_STUB ITaxNumbers_get_taxgrp7_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ITaxNumbers_put_taxgrp7_Proxy( 
    ITaxNumbers __RPC_FAR * This,
    /* [in] */ double newVal);


void __RPC_STUB ITaxNumbers_put_taxgrp7_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ITaxNumbers_get_taxgrp8_Proxy( 
    ITaxNumbers __RPC_FAR * This,
    /* [retval][out] */ double __RPC_FAR *pVal);


void __RPC_STUB ITaxNumbers_get_taxgrp8_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ITaxNumbers_put_taxgrp8_Proxy( 
    ITaxNumbers __RPC_FAR * This,
    /* [in] */ double newVal);


void __RPC_STUB ITaxNumbers_put_taxgrp8_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITaxNumbers_INTERFACE_DEFINED__ */


#ifndef __IPayTypes_INTERFACE_DEFINED__
#define __IPayTypes_INTERFACE_DEFINED__

/* interface IPayTypes */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IPayTypes;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("29F4A8DC-786A-4274-A771-4B5C05003536")
    IPayTypes : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_paytype1( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_paytype1( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_paytype2( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_paytype2( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_paytype3( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_paytype3( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_paytype4( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_paytype4( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_paytype0( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_paytype0( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_paytype1sum( 
            /* [retval][out] */ double __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_paytype1sum( 
            /* [in] */ double newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_paytype2sum( 
            /* [retval][out] */ double __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_paytype2sum( 
            /* [in] */ double newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_paytype3sum( 
            /* [retval][out] */ double __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_paytype3sum( 
            /* [in] */ double newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_paytype4sum( 
            /* [retval][out] */ double __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_paytype4sum( 
            /* [in] */ double newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_paytype0sum( 
            /* [retval][out] */ double __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_paytype0sum( 
            /* [in] */ double newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_operations( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_operations( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_exchRate( 
            /* [retval][out] */ double __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_exchRate( 
            /* [in] */ double newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPayTypesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPayTypes __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPayTypes __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPayTypes __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IPayTypes __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IPayTypes __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IPayTypes __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IPayTypes __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_paytype1 )( 
            IPayTypes __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_paytype1 )( 
            IPayTypes __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_paytype2 )( 
            IPayTypes __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_paytype2 )( 
            IPayTypes __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_paytype3 )( 
            IPayTypes __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_paytype3 )( 
            IPayTypes __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_paytype4 )( 
            IPayTypes __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_paytype4 )( 
            IPayTypes __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_paytype0 )( 
            IPayTypes __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_paytype0 )( 
            IPayTypes __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_paytype1sum )( 
            IPayTypes __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_paytype1sum )( 
            IPayTypes __RPC_FAR * This,
            /* [in] */ double newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_paytype2sum )( 
            IPayTypes __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_paytype2sum )( 
            IPayTypes __RPC_FAR * This,
            /* [in] */ double newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_paytype3sum )( 
            IPayTypes __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_paytype3sum )( 
            IPayTypes __RPC_FAR * This,
            /* [in] */ double newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_paytype4sum )( 
            IPayTypes __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_paytype4sum )( 
            IPayTypes __RPC_FAR * This,
            /* [in] */ double newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_paytype0sum )( 
            IPayTypes __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_paytype0sum )( 
            IPayTypes __RPC_FAR * This,
            /* [in] */ double newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_operations )( 
            IPayTypes __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_operations )( 
            IPayTypes __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_exchRate )( 
            IPayTypes __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_exchRate )( 
            IPayTypes __RPC_FAR * This,
            /* [in] */ double newVal);
        
        END_INTERFACE
    } IPayTypesVtbl;

    interface IPayTypes
    {
        CONST_VTBL struct IPayTypesVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPayTypes_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPayTypes_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPayTypes_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPayTypes_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IPayTypes_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IPayTypes_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IPayTypes_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IPayTypes_get_paytype1(This,pVal)	\
    (This)->lpVtbl -> get_paytype1(This,pVal)

#define IPayTypes_put_paytype1(This,newVal)	\
    (This)->lpVtbl -> put_paytype1(This,newVal)

#define IPayTypes_get_paytype2(This,pVal)	\
    (This)->lpVtbl -> get_paytype2(This,pVal)

#define IPayTypes_put_paytype2(This,newVal)	\
    (This)->lpVtbl -> put_paytype2(This,newVal)

#define IPayTypes_get_paytype3(This,pVal)	\
    (This)->lpVtbl -> get_paytype3(This,pVal)

#define IPayTypes_put_paytype3(This,newVal)	\
    (This)->lpVtbl -> put_paytype3(This,newVal)

#define IPayTypes_get_paytype4(This,pVal)	\
    (This)->lpVtbl -> get_paytype4(This,pVal)

#define IPayTypes_put_paytype4(This,newVal)	\
    (This)->lpVtbl -> put_paytype4(This,newVal)

#define IPayTypes_get_paytype0(This,pVal)	\
    (This)->lpVtbl -> get_paytype0(This,pVal)

#define IPayTypes_put_paytype0(This,newVal)	\
    (This)->lpVtbl -> put_paytype0(This,newVal)

#define IPayTypes_get_paytype1sum(This,pVal)	\
    (This)->lpVtbl -> get_paytype1sum(This,pVal)

#define IPayTypes_put_paytype1sum(This,newVal)	\
    (This)->lpVtbl -> put_paytype1sum(This,newVal)

#define IPayTypes_get_paytype2sum(This,pVal)	\
    (This)->lpVtbl -> get_paytype2sum(This,pVal)

#define IPayTypes_put_paytype2sum(This,newVal)	\
    (This)->lpVtbl -> put_paytype2sum(This,newVal)

#define IPayTypes_get_paytype3sum(This,pVal)	\
    (This)->lpVtbl -> get_paytype3sum(This,pVal)

#define IPayTypes_put_paytype3sum(This,newVal)	\
    (This)->lpVtbl -> put_paytype3sum(This,newVal)

#define IPayTypes_get_paytype4sum(This,pVal)	\
    (This)->lpVtbl -> get_paytype4sum(This,pVal)

#define IPayTypes_put_paytype4sum(This,newVal)	\
    (This)->lpVtbl -> put_paytype4sum(This,newVal)

#define IPayTypes_get_paytype0sum(This,pVal)	\
    (This)->lpVtbl -> get_paytype0sum(This,pVal)

#define IPayTypes_put_paytype0sum(This,newVal)	\
    (This)->lpVtbl -> put_paytype0sum(This,newVal)

#define IPayTypes_get_operations(This,pVal)	\
    (This)->lpVtbl -> get_operations(This,pVal)

#define IPayTypes_put_operations(This,newVal)	\
    (This)->lpVtbl -> put_operations(This,newVal)

#define IPayTypes_get_exchRate(This,pVal)	\
    (This)->lpVtbl -> get_exchRate(This,pVal)

#define IPayTypes_put_exchRate(This,newVal)	\
    (This)->lpVtbl -> put_exchRate(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IPayTypes_get_paytype1_Proxy( 
    IPayTypes __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IPayTypes_get_paytype1_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IPayTypes_put_paytype1_Proxy( 
    IPayTypes __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IPayTypes_put_paytype1_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IPayTypes_get_paytype2_Proxy( 
    IPayTypes __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IPayTypes_get_paytype2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IPayTypes_put_paytype2_Proxy( 
    IPayTypes __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IPayTypes_put_paytype2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IPayTypes_get_paytype3_Proxy( 
    IPayTypes __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IPayTypes_get_paytype3_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IPayTypes_put_paytype3_Proxy( 
    IPayTypes __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IPayTypes_put_paytype3_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IPayTypes_get_paytype4_Proxy( 
    IPayTypes __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IPayTypes_get_paytype4_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IPayTypes_put_paytype4_Proxy( 
    IPayTypes __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IPayTypes_put_paytype4_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IPayTypes_get_paytype0_Proxy( 
    IPayTypes __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IPayTypes_get_paytype0_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IPayTypes_put_paytype0_Proxy( 
    IPayTypes __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IPayTypes_put_paytype0_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IPayTypes_get_paytype1sum_Proxy( 
    IPayTypes __RPC_FAR * This,
    /* [retval][out] */ double __RPC_FAR *pVal);


void __RPC_STUB IPayTypes_get_paytype1sum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IPayTypes_put_paytype1sum_Proxy( 
    IPayTypes __RPC_FAR * This,
    /* [in] */ double newVal);


void __RPC_STUB IPayTypes_put_paytype1sum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IPayTypes_get_paytype2sum_Proxy( 
    IPayTypes __RPC_FAR * This,
    /* [retval][out] */ double __RPC_FAR *pVal);


void __RPC_STUB IPayTypes_get_paytype2sum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IPayTypes_put_paytype2sum_Proxy( 
    IPayTypes __RPC_FAR * This,
    /* [in] */ double newVal);


void __RPC_STUB IPayTypes_put_paytype2sum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IPayTypes_get_paytype3sum_Proxy( 
    IPayTypes __RPC_FAR * This,
    /* [retval][out] */ double __RPC_FAR *pVal);


void __RPC_STUB IPayTypes_get_paytype3sum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IPayTypes_put_paytype3sum_Proxy( 
    IPayTypes __RPC_FAR * This,
    /* [in] */ double newVal);


void __RPC_STUB IPayTypes_put_paytype3sum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IPayTypes_get_paytype4sum_Proxy( 
    IPayTypes __RPC_FAR * This,
    /* [retval][out] */ double __RPC_FAR *pVal);


void __RPC_STUB IPayTypes_get_paytype4sum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IPayTypes_put_paytype4sum_Proxy( 
    IPayTypes __RPC_FAR * This,
    /* [in] */ double newVal);


void __RPC_STUB IPayTypes_put_paytype4sum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IPayTypes_get_paytype0sum_Proxy( 
    IPayTypes __RPC_FAR * This,
    /* [retval][out] */ double __RPC_FAR *pVal);


void __RPC_STUB IPayTypes_get_paytype0sum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IPayTypes_put_paytype0sum_Proxy( 
    IPayTypes __RPC_FAR * This,
    /* [in] */ double newVal);


void __RPC_STUB IPayTypes_put_paytype0sum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IPayTypes_get_operations_Proxy( 
    IPayTypes __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IPayTypes_get_operations_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IPayTypes_put_operations_Proxy( 
    IPayTypes __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IPayTypes_put_operations_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IPayTypes_get_exchRate_Proxy( 
    IPayTypes __RPC_FAR * This,
    /* [retval][out] */ double __RPC_FAR *pVal);


void __RPC_STUB IPayTypes_get_exchRate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IPayTypes_put_exchRate_Proxy( 
    IPayTypes __RPC_FAR * This,
    /* [in] */ double newVal);


void __RPC_STUB IPayTypes_put_exchRate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPayTypes_INTERFACE_DEFINED__ */


#ifndef __IZFPParameters_INTERFACE_DEFINED__
#define __IZFPParameters_INTERFACE_DEFINED__

/* interface IZFPParameters */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IZFPParameters;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("71FD4FFE-545C-4CE3-B3CF-8F2A7DEA8277")
    IZFPParameters : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_fpnum( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_fpnum( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_logo( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_logo( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_till( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_till( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_autocut( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_autocut( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_transparent( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_transparent( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_shortEJ( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_shortEJ( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_currency( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_currency( 
            /* [in] */ long newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IZFPParametersVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IZFPParameters __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IZFPParameters __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IZFPParameters __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IZFPParameters __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IZFPParameters __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IZFPParameters __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IZFPParameters __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_fpnum )( 
            IZFPParameters __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_fpnum )( 
            IZFPParameters __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_logo )( 
            IZFPParameters __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_logo )( 
            IZFPParameters __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_till )( 
            IZFPParameters __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_till )( 
            IZFPParameters __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_autocut )( 
            IZFPParameters __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_autocut )( 
            IZFPParameters __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_transparent )( 
            IZFPParameters __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_transparent )( 
            IZFPParameters __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_shortEJ )( 
            IZFPParameters __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_shortEJ )( 
            IZFPParameters __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_currency )( 
            IZFPParameters __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_currency )( 
            IZFPParameters __RPC_FAR * This,
            /* [in] */ long newVal);
        
        END_INTERFACE
    } IZFPParametersVtbl;

    interface IZFPParameters
    {
        CONST_VTBL struct IZFPParametersVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IZFPParameters_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IZFPParameters_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IZFPParameters_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IZFPParameters_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IZFPParameters_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IZFPParameters_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IZFPParameters_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IZFPParameters_get_fpnum(This,pVal)	\
    (This)->lpVtbl -> get_fpnum(This,pVal)

#define IZFPParameters_put_fpnum(This,newVal)	\
    (This)->lpVtbl -> put_fpnum(This,newVal)

#define IZFPParameters_get_logo(This,pVal)	\
    (This)->lpVtbl -> get_logo(This,pVal)

#define IZFPParameters_put_logo(This,newVal)	\
    (This)->lpVtbl -> put_logo(This,newVal)

#define IZFPParameters_get_till(This,pVal)	\
    (This)->lpVtbl -> get_till(This,pVal)

#define IZFPParameters_put_till(This,newVal)	\
    (This)->lpVtbl -> put_till(This,newVal)

#define IZFPParameters_get_autocut(This,pVal)	\
    (This)->lpVtbl -> get_autocut(This,pVal)

#define IZFPParameters_put_autocut(This,newVal)	\
    (This)->lpVtbl -> put_autocut(This,newVal)

#define IZFPParameters_get_transparent(This,pVal)	\
    (This)->lpVtbl -> get_transparent(This,pVal)

#define IZFPParameters_put_transparent(This,newVal)	\
    (This)->lpVtbl -> put_transparent(This,newVal)

#define IZFPParameters_get_shortEJ(This,pVal)	\
    (This)->lpVtbl -> get_shortEJ(This,pVal)

#define IZFPParameters_put_shortEJ(This,newVal)	\
    (This)->lpVtbl -> put_shortEJ(This,newVal)

#define IZFPParameters_get_currency(This,pVal)	\
    (This)->lpVtbl -> get_currency(This,pVal)

#define IZFPParameters_put_currency(This,newVal)	\
    (This)->lpVtbl -> put_currency(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IZFPParameters_get_fpnum_Proxy( 
    IZFPParameters __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IZFPParameters_get_fpnum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IZFPParameters_put_fpnum_Proxy( 
    IZFPParameters __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IZFPParameters_put_fpnum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IZFPParameters_get_logo_Proxy( 
    IZFPParameters __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IZFPParameters_get_logo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IZFPParameters_put_logo_Proxy( 
    IZFPParameters __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IZFPParameters_put_logo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IZFPParameters_get_till_Proxy( 
    IZFPParameters __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IZFPParameters_get_till_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IZFPParameters_put_till_Proxy( 
    IZFPParameters __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IZFPParameters_put_till_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IZFPParameters_get_autocut_Proxy( 
    IZFPParameters __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IZFPParameters_get_autocut_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IZFPParameters_put_autocut_Proxy( 
    IZFPParameters __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IZFPParameters_put_autocut_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IZFPParameters_get_transparent_Proxy( 
    IZFPParameters __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IZFPParameters_get_transparent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IZFPParameters_put_transparent_Proxy( 
    IZFPParameters __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IZFPParameters_put_transparent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IZFPParameters_get_shortEJ_Proxy( 
    IZFPParameters __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IZFPParameters_get_shortEJ_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IZFPParameters_put_shortEJ_Proxy( 
    IZFPParameters __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IZFPParameters_put_shortEJ_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IZFPParameters_get_currency_Proxy( 
    IZFPParameters __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IZFPParameters_get_currency_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IZFPParameters_put_currency_Proxy( 
    IZFPParameters __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IZFPParameters_put_currency_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IZFPParameters_INTERFACE_DEFINED__ */


#ifndef __IOperatorInfo_INTERFACE_DEFINED__
#define __IOperatorInfo_INTERFACE_DEFINED__

/* interface IOperatorInfo */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IOperatorInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("72495AB9-215A-4C8F-AE1F-BC88FD92B788")
    IOperatorInfo : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_name( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_name( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_passwd( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_passwd( 
            /* [in] */ BSTR newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IOperatorInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IOperatorInfo __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IOperatorInfo __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IOperatorInfo __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IOperatorInfo __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IOperatorInfo __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IOperatorInfo __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IOperatorInfo __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_name )( 
            IOperatorInfo __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_name )( 
            IOperatorInfo __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_passwd )( 
            IOperatorInfo __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_passwd )( 
            IOperatorInfo __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        END_INTERFACE
    } IOperatorInfoVtbl;

    interface IOperatorInfo
    {
        CONST_VTBL struct IOperatorInfoVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOperatorInfo_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IOperatorInfo_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IOperatorInfo_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IOperatorInfo_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IOperatorInfo_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IOperatorInfo_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IOperatorInfo_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IOperatorInfo_get_name(This,pVal)	\
    (This)->lpVtbl -> get_name(This,pVal)

#define IOperatorInfo_put_name(This,newVal)	\
    (This)->lpVtbl -> put_name(This,newVal)

#define IOperatorInfo_get_passwd(This,pVal)	\
    (This)->lpVtbl -> get_passwd(This,pVal)

#define IOperatorInfo_put_passwd(This,newVal)	\
    (This)->lpVtbl -> put_passwd(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOperatorInfo_get_name_Proxy( 
    IOperatorInfo __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IOperatorInfo_get_name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOperatorInfo_put_name_Proxy( 
    IOperatorInfo __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IOperatorInfo_put_name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOperatorInfo_get_passwd_Proxy( 
    IOperatorInfo __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IOperatorInfo_get_passwd_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOperatorInfo_put_passwd_Proxy( 
    IOperatorInfo __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IOperatorInfo_put_passwd_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IOperatorInfo_INTERFACE_DEFINED__ */


#ifndef __IArticleInfo_INTERFACE_DEFINED__
#define __IArticleInfo_INTERFACE_DEFINED__

/* interface IArticleInfo */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IArticleInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("96CAD3E3-70CD-4BED-AB8B-ADDD77D301D3")
    IArticleInfo : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_name( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_name( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_price( 
            /* [retval][out] */ double __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_price( 
            /* [in] */ double newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_taxgroup( 
            /* [retval][out] */ short __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_taxgroup( 
            /* [in] */ short newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_turnover( 
            /* [retval][out] */ double __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_turnover( 
            /* [in] */ double newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_sells( 
            /* [retval][out] */ double __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_sells( 
            /* [in] */ double newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_counter( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_counter( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_reportdate( 
            /* [retval][out] */ DATE __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_reportdate( 
            /* [in] */ DATE newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_department( 
            /* [retval][out] */ short __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_department( 
            /* [in] */ short newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_quantity( 
            /* [retval][out] */ double __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_quantity( 
            /* [in] */ double newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IArticleInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IArticleInfo __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IArticleInfo __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IArticleInfo __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IArticleInfo __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IArticleInfo __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IArticleInfo __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IArticleInfo __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_name )( 
            IArticleInfo __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_name )( 
            IArticleInfo __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_price )( 
            IArticleInfo __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_price )( 
            IArticleInfo __RPC_FAR * This,
            /* [in] */ double newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_taxgroup )( 
            IArticleInfo __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_taxgroup )( 
            IArticleInfo __RPC_FAR * This,
            /* [in] */ short newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_turnover )( 
            IArticleInfo __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_turnover )( 
            IArticleInfo __RPC_FAR * This,
            /* [in] */ double newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_sells )( 
            IArticleInfo __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_sells )( 
            IArticleInfo __RPC_FAR * This,
            /* [in] */ double newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_counter )( 
            IArticleInfo __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_counter )( 
            IArticleInfo __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_reportdate )( 
            IArticleInfo __RPC_FAR * This,
            /* [retval][out] */ DATE __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_reportdate )( 
            IArticleInfo __RPC_FAR * This,
            /* [in] */ DATE newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_department )( 
            IArticleInfo __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_department )( 
            IArticleInfo __RPC_FAR * This,
            /* [in] */ short newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_quantity )( 
            IArticleInfo __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_quantity )( 
            IArticleInfo __RPC_FAR * This,
            /* [in] */ double newVal);
        
        END_INTERFACE
    } IArticleInfoVtbl;

    interface IArticleInfo
    {
        CONST_VTBL struct IArticleInfoVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IArticleInfo_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IArticleInfo_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IArticleInfo_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IArticleInfo_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IArticleInfo_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IArticleInfo_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IArticleInfo_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IArticleInfo_get_name(This,pVal)	\
    (This)->lpVtbl -> get_name(This,pVal)

#define IArticleInfo_put_name(This,newVal)	\
    (This)->lpVtbl -> put_name(This,newVal)

#define IArticleInfo_get_price(This,pVal)	\
    (This)->lpVtbl -> get_price(This,pVal)

#define IArticleInfo_put_price(This,newVal)	\
    (This)->lpVtbl -> put_price(This,newVal)

#define IArticleInfo_get_taxgroup(This,pVal)	\
    (This)->lpVtbl -> get_taxgroup(This,pVal)

#define IArticleInfo_put_taxgroup(This,newVal)	\
    (This)->lpVtbl -> put_taxgroup(This,newVal)

#define IArticleInfo_get_turnover(This,pVal)	\
    (This)->lpVtbl -> get_turnover(This,pVal)

#define IArticleInfo_put_turnover(This,newVal)	\
    (This)->lpVtbl -> put_turnover(This,newVal)

#define IArticleInfo_get_sells(This,pVal)	\
    (This)->lpVtbl -> get_sells(This,pVal)

#define IArticleInfo_put_sells(This,newVal)	\
    (This)->lpVtbl -> put_sells(This,newVal)

#define IArticleInfo_get_counter(This,pVal)	\
    (This)->lpVtbl -> get_counter(This,pVal)

#define IArticleInfo_put_counter(This,newVal)	\
    (This)->lpVtbl -> put_counter(This,newVal)

#define IArticleInfo_get_reportdate(This,pVal)	\
    (This)->lpVtbl -> get_reportdate(This,pVal)

#define IArticleInfo_put_reportdate(This,newVal)	\
    (This)->lpVtbl -> put_reportdate(This,newVal)

#define IArticleInfo_get_department(This,pVal)	\
    (This)->lpVtbl -> get_department(This,pVal)

#define IArticleInfo_put_department(This,newVal)	\
    (This)->lpVtbl -> put_department(This,newVal)

#define IArticleInfo_get_quantity(This,pVal)	\
    (This)->lpVtbl -> get_quantity(This,pVal)

#define IArticleInfo_put_quantity(This,newVal)	\
    (This)->lpVtbl -> put_quantity(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IArticleInfo_get_name_Proxy( 
    IArticleInfo __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IArticleInfo_get_name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IArticleInfo_put_name_Proxy( 
    IArticleInfo __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IArticleInfo_put_name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IArticleInfo_get_price_Proxy( 
    IArticleInfo __RPC_FAR * This,
    /* [retval][out] */ double __RPC_FAR *pVal);


void __RPC_STUB IArticleInfo_get_price_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IArticleInfo_put_price_Proxy( 
    IArticleInfo __RPC_FAR * This,
    /* [in] */ double newVal);


void __RPC_STUB IArticleInfo_put_price_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IArticleInfo_get_taxgroup_Proxy( 
    IArticleInfo __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *pVal);


void __RPC_STUB IArticleInfo_get_taxgroup_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IArticleInfo_put_taxgroup_Proxy( 
    IArticleInfo __RPC_FAR * This,
    /* [in] */ short newVal);


void __RPC_STUB IArticleInfo_put_taxgroup_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IArticleInfo_get_turnover_Proxy( 
    IArticleInfo __RPC_FAR * This,
    /* [retval][out] */ double __RPC_FAR *pVal);


void __RPC_STUB IArticleInfo_get_turnover_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IArticleInfo_put_turnover_Proxy( 
    IArticleInfo __RPC_FAR * This,
    /* [in] */ double newVal);


void __RPC_STUB IArticleInfo_put_turnover_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IArticleInfo_get_sells_Proxy( 
    IArticleInfo __RPC_FAR * This,
    /* [retval][out] */ double __RPC_FAR *pVal);


void __RPC_STUB IArticleInfo_get_sells_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IArticleInfo_put_sells_Proxy( 
    IArticleInfo __RPC_FAR * This,
    /* [in] */ double newVal);


void __RPC_STUB IArticleInfo_put_sells_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IArticleInfo_get_counter_Proxy( 
    IArticleInfo __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IArticleInfo_get_counter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IArticleInfo_put_counter_Proxy( 
    IArticleInfo __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IArticleInfo_put_counter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IArticleInfo_get_reportdate_Proxy( 
    IArticleInfo __RPC_FAR * This,
    /* [retval][out] */ DATE __RPC_FAR *pVal);


void __RPC_STUB IArticleInfo_get_reportdate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IArticleInfo_put_reportdate_Proxy( 
    IArticleInfo __RPC_FAR * This,
    /* [in] */ DATE newVal);


void __RPC_STUB IArticleInfo_put_reportdate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IArticleInfo_get_department_Proxy( 
    IArticleInfo __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *pVal);


void __RPC_STUB IArticleInfo_get_department_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IArticleInfo_put_department_Proxy( 
    IArticleInfo __RPC_FAR * This,
    /* [in] */ short newVal);


void __RPC_STUB IArticleInfo_put_department_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IArticleInfo_get_quantity_Proxy( 
    IArticleInfo __RPC_FAR * This,
    /* [retval][out] */ double __RPC_FAR *pVal);


void __RPC_STUB IArticleInfo_get_quantity_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IArticleInfo_put_quantity_Proxy( 
    IArticleInfo __RPC_FAR * This,
    /* [in] */ double newVal);


void __RPC_STUB IArticleInfo_put_quantity_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IArticleInfo_INTERFACE_DEFINED__ */


#ifndef __IDailySums_INTERFACE_DEFINED__
#define __IDailySums_INTERFACE_DEFINED__

/* interface IDailySums */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IDailySums;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9DF5E8A6-B16D-4F5E-92BC-70E2670E2AFB")
    IDailySums : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_clients( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_clients( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_discounts( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_discounts( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_sumdiscount( 
            /* [retval][out] */ double __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_sumdiscount( 
            /* [in] */ double newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_adding( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_adding( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_sumadding( 
            /* [retval][out] */ double __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_sumadding( 
            /* [in] */ double newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_voids( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_voids( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_sumvoids( 
            /* [retval][out] */ double __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_sumvoids( 
            /* [in] */ double newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDailySumsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IDailySums __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IDailySums __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IDailySums __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IDailySums __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IDailySums __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IDailySums __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IDailySums __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_clients )( 
            IDailySums __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_clients )( 
            IDailySums __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_discounts )( 
            IDailySums __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_discounts )( 
            IDailySums __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_sumdiscount )( 
            IDailySums __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_sumdiscount )( 
            IDailySums __RPC_FAR * This,
            /* [in] */ double newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_adding )( 
            IDailySums __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_adding )( 
            IDailySums __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_sumadding )( 
            IDailySums __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_sumadding )( 
            IDailySums __RPC_FAR * This,
            /* [in] */ double newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_voids )( 
            IDailySums __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_voids )( 
            IDailySums __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_sumvoids )( 
            IDailySums __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_sumvoids )( 
            IDailySums __RPC_FAR * This,
            /* [in] */ double newVal);
        
        END_INTERFACE
    } IDailySumsVtbl;

    interface IDailySums
    {
        CONST_VTBL struct IDailySumsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDailySums_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDailySums_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDailySums_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDailySums_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IDailySums_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IDailySums_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IDailySums_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IDailySums_get_clients(This,pVal)	\
    (This)->lpVtbl -> get_clients(This,pVal)

#define IDailySums_put_clients(This,newVal)	\
    (This)->lpVtbl -> put_clients(This,newVal)

#define IDailySums_get_discounts(This,pVal)	\
    (This)->lpVtbl -> get_discounts(This,pVal)

#define IDailySums_put_discounts(This,newVal)	\
    (This)->lpVtbl -> put_discounts(This,newVal)

#define IDailySums_get_sumdiscount(This,pVal)	\
    (This)->lpVtbl -> get_sumdiscount(This,pVal)

#define IDailySums_put_sumdiscount(This,newVal)	\
    (This)->lpVtbl -> put_sumdiscount(This,newVal)

#define IDailySums_get_adding(This,pVal)	\
    (This)->lpVtbl -> get_adding(This,pVal)

#define IDailySums_put_adding(This,newVal)	\
    (This)->lpVtbl -> put_adding(This,newVal)

#define IDailySums_get_sumadding(This,pVal)	\
    (This)->lpVtbl -> get_sumadding(This,pVal)

#define IDailySums_put_sumadding(This,newVal)	\
    (This)->lpVtbl -> put_sumadding(This,newVal)

#define IDailySums_get_voids(This,pVal)	\
    (This)->lpVtbl -> get_voids(This,pVal)

#define IDailySums_put_voids(This,newVal)	\
    (This)->lpVtbl -> put_voids(This,newVal)

#define IDailySums_get_sumvoids(This,pVal)	\
    (This)->lpVtbl -> get_sumvoids(This,pVal)

#define IDailySums_put_sumvoids(This,newVal)	\
    (This)->lpVtbl -> put_sumvoids(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IDailySums_get_clients_Proxy( 
    IDailySums __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IDailySums_get_clients_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IDailySums_put_clients_Proxy( 
    IDailySums __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IDailySums_put_clients_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IDailySums_get_discounts_Proxy( 
    IDailySums __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IDailySums_get_discounts_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IDailySums_put_discounts_Proxy( 
    IDailySums __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IDailySums_put_discounts_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IDailySums_get_sumdiscount_Proxy( 
    IDailySums __RPC_FAR * This,
    /* [retval][out] */ double __RPC_FAR *pVal);


void __RPC_STUB IDailySums_get_sumdiscount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IDailySums_put_sumdiscount_Proxy( 
    IDailySums __RPC_FAR * This,
    /* [in] */ double newVal);


void __RPC_STUB IDailySums_put_sumdiscount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IDailySums_get_adding_Proxy( 
    IDailySums __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IDailySums_get_adding_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IDailySums_put_adding_Proxy( 
    IDailySums __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IDailySums_put_adding_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IDailySums_get_sumadding_Proxy( 
    IDailySums __RPC_FAR * This,
    /* [retval][out] */ double __RPC_FAR *pVal);


void __RPC_STUB IDailySums_get_sumadding_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IDailySums_put_sumadding_Proxy( 
    IDailySums __RPC_FAR * This,
    /* [in] */ double newVal);


void __RPC_STUB IDailySums_put_sumadding_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IDailySums_get_voids_Proxy( 
    IDailySums __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IDailySums_get_voids_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IDailySums_put_voids_Proxy( 
    IDailySums __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IDailySums_put_voids_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IDailySums_get_sumvoids_Proxy( 
    IDailySums __RPC_FAR * This,
    /* [retval][out] */ double __RPC_FAR *pVal);


void __RPC_STUB IDailySums_get_sumvoids_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IDailySums_put_sumvoids_Proxy( 
    IDailySums __RPC_FAR * This,
    /* [in] */ double newVal);


void __RPC_STUB IDailySums_put_sumvoids_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDailySums_INTERFACE_DEFINED__ */


#ifndef __IFiscalReportData_INTERFACE_DEFINED__
#define __IFiscalReportData_INTERFACE_DEFINED__

/* interface IFiscalReportData */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IFiscalReportData;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C80831C3-069A-4D31-A042-CD5A2D1BF43B")
    IFiscalReportData : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_reportdate( 
            /* [retval][out] */ DATE __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_reportdate( 
            /* [in] */ DATE newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_lastreport( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_lastreport( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_lastzeroram( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_lastzeroram( 
            /* [in] */ long newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFiscalReportDataVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IFiscalReportData __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IFiscalReportData __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IFiscalReportData __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IFiscalReportData __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IFiscalReportData __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IFiscalReportData __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IFiscalReportData __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_reportdate )( 
            IFiscalReportData __RPC_FAR * This,
            /* [retval][out] */ DATE __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_reportdate )( 
            IFiscalReportData __RPC_FAR * This,
            /* [in] */ DATE newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_lastreport )( 
            IFiscalReportData __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_lastreport )( 
            IFiscalReportData __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_lastzeroram )( 
            IFiscalReportData __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_lastzeroram )( 
            IFiscalReportData __RPC_FAR * This,
            /* [in] */ long newVal);
        
        END_INTERFACE
    } IFiscalReportDataVtbl;

    interface IFiscalReportData
    {
        CONST_VTBL struct IFiscalReportDataVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFiscalReportData_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFiscalReportData_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFiscalReportData_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFiscalReportData_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IFiscalReportData_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IFiscalReportData_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IFiscalReportData_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IFiscalReportData_get_reportdate(This,pVal)	\
    (This)->lpVtbl -> get_reportdate(This,pVal)

#define IFiscalReportData_put_reportdate(This,newVal)	\
    (This)->lpVtbl -> put_reportdate(This,newVal)

#define IFiscalReportData_get_lastreport(This,pVal)	\
    (This)->lpVtbl -> get_lastreport(This,pVal)

#define IFiscalReportData_put_lastreport(This,newVal)	\
    (This)->lpVtbl -> put_lastreport(This,newVal)

#define IFiscalReportData_get_lastzeroram(This,pVal)	\
    (This)->lpVtbl -> get_lastzeroram(This,pVal)

#define IFiscalReportData_put_lastzeroram(This,newVal)	\
    (This)->lpVtbl -> put_lastzeroram(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFiscalReportData_get_reportdate_Proxy( 
    IFiscalReportData __RPC_FAR * This,
    /* [retval][out] */ DATE __RPC_FAR *pVal);


void __RPC_STUB IFiscalReportData_get_reportdate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFiscalReportData_put_reportdate_Proxy( 
    IFiscalReportData __RPC_FAR * This,
    /* [in] */ DATE newVal);


void __RPC_STUB IFiscalReportData_put_reportdate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFiscalReportData_get_lastreport_Proxy( 
    IFiscalReportData __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IFiscalReportData_get_lastreport_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFiscalReportData_put_lastreport_Proxy( 
    IFiscalReportData __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IFiscalReportData_put_lastreport_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFiscalReportData_get_lastzeroram_Proxy( 
    IFiscalReportData __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IFiscalReportData_get_lastzeroram_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFiscalReportData_put_lastzeroram_Proxy( 
    IFiscalReportData __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IFiscalReportData_put_lastzeroram_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IFiscalReportData_INTERFACE_DEFINED__ */


#ifndef __IDailyReport_INTERFACE_DEFINED__
#define __IDailyReport_INTERFACE_DEFINED__

/* interface IDailyReport */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IDailyReport;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("79B6621A-0804-4742-859A-333D1CB3EFBD")
    IDailyReport : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_counter( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_counter( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_lastreport( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_lastreport( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ecl( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ecl( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_datetime( 
            /* [retval][out] */ DATE __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_datetime( 
            /* [in] */ DATE newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDailyReportVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IDailyReport __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IDailyReport __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IDailyReport __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IDailyReport __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IDailyReport __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IDailyReport __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IDailyReport __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_counter )( 
            IDailyReport __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_counter )( 
            IDailyReport __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_lastreport )( 
            IDailyReport __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_lastreport )( 
            IDailyReport __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ecl )( 
            IDailyReport __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ecl )( 
            IDailyReport __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_datetime )( 
            IDailyReport __RPC_FAR * This,
            /* [retval][out] */ DATE __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_datetime )( 
            IDailyReport __RPC_FAR * This,
            /* [in] */ DATE newVal);
        
        END_INTERFACE
    } IDailyReportVtbl;

    interface IDailyReport
    {
        CONST_VTBL struct IDailyReportVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDailyReport_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDailyReport_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDailyReport_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDailyReport_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IDailyReport_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IDailyReport_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IDailyReport_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IDailyReport_get_counter(This,pVal)	\
    (This)->lpVtbl -> get_counter(This,pVal)

#define IDailyReport_put_counter(This,newVal)	\
    (This)->lpVtbl -> put_counter(This,newVal)

#define IDailyReport_get_lastreport(This,pVal)	\
    (This)->lpVtbl -> get_lastreport(This,pVal)

#define IDailyReport_put_lastreport(This,newVal)	\
    (This)->lpVtbl -> put_lastreport(This,newVal)

#define IDailyReport_get_ecl(This,pVal)	\
    (This)->lpVtbl -> get_ecl(This,pVal)

#define IDailyReport_put_ecl(This,newVal)	\
    (This)->lpVtbl -> put_ecl(This,newVal)

#define IDailyReport_get_datetime(This,pVal)	\
    (This)->lpVtbl -> get_datetime(This,pVal)

#define IDailyReport_put_datetime(This,newVal)	\
    (This)->lpVtbl -> put_datetime(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IDailyReport_get_counter_Proxy( 
    IDailyReport __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IDailyReport_get_counter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IDailyReport_put_counter_Proxy( 
    IDailyReport __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IDailyReport_put_counter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IDailyReport_get_lastreport_Proxy( 
    IDailyReport __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IDailyReport_get_lastreport_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IDailyReport_put_lastreport_Proxy( 
    IDailyReport __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IDailyReport_put_lastreport_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IDailyReport_get_ecl_Proxy( 
    IDailyReport __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IDailyReport_get_ecl_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IDailyReport_put_ecl_Proxy( 
    IDailyReport __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IDailyReport_put_ecl_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IDailyReport_get_datetime_Proxy( 
    IDailyReport __RPC_FAR * This,
    /* [retval][out] */ DATE __RPC_FAR *pVal);


void __RPC_STUB IDailyReport_get_datetime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IDailyReport_put_datetime_Proxy( 
    IDailyReport __RPC_FAR * This,
    /* [in] */ DATE newVal);


void __RPC_STUB IDailyReport_put_datetime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDailyReport_INTERFACE_DEFINED__ */


#ifndef __IZFPStatus_INTERFACE_DEFINED__
#define __IZFPStatus_INTERFACE_DEFINED__

/* interface IZFPStatus */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IZFPStatus;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6C75FC08-31BD-4B9E-B5E0-BBF69AA9F041")
    IZFPStatus : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ST0( 
            /* [retval][out] */ BYTE __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ST0( 
            /* [in] */ BYTE newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ST1( 
            /* [retval][out] */ BYTE __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ST1( 
            /* [in] */ BYTE newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ST2( 
            /* [retval][out] */ BYTE __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ST2( 
            /* [in] */ BYTE newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ST3( 
            /* [retval][out] */ BYTE __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ST3( 
            /* [in] */ BYTE newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ST4( 
            /* [retval][out] */ BYTE __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ST4( 
            /* [in] */ BYTE newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_wrongTimer( 
            /* [retval][out] */ BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_wrongDate( 
            /* [retval][out] */ BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_wrongRAM( 
            /* [retval][out] */ BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_clockHardwareError( 
            /* [retval][out] */ BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_paperOutPrinterError( 
            /* [retval][out] */ BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_reportSumOverflow( 
            /* [retval][out] */ BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_printLogo( 
            /* [retval][out] */ BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_nonzeroDailyReport( 
            /* [retval][out] */ BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_nonzeroArticleReport( 
            /* [retval][out] */ BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_nonzeroOperatorReport( 
            /* [retval][out] */ BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_duplicateNotPrinted( 
            /* [retval][out] */ BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_openOfficialBon( 
            /* [retval][out] */ BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OpenFiscalBon( 
            /* [retval][out] */ BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_detailedInfo( 
            /* [retval][out] */ BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_VATinfo( 
            /* [retval][out] */ BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_missingFiscalMemory( 
            /* [retval][out] */ BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_wrongFiscalMemory( 
            /* [retval][out] */ BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_fullFiscalMemory( 
            /* [retval][out] */ BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_fiscalMemoryLimitNear( 
            /* [retval][out] */ BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_hasDecimalPoint( 
            /* [retval][out] */ BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_isFiscal( 
            /* [retval][out] */ BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_hasFiscalAndFactoryNum( 
            /* [retval][out] */ BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_autoCutter( 
            /* [retval][out] */ BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_hasTransparentDisplay( 
            /* [retval][out] */ BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_baud9600( 
            /* [retval][out] */ BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_autoTillOpen( 
            /* [retval][out] */ BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_readOnlyFM( 
            /* [retval][out] */ BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_powerDown( 
            /* [retval][out] */ BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_printerOverheat( 
            /* [retval][out] */ BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Blocked24HoursReport( 
            /* [retval][out] */ BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_missingDisplay( 
            /* [retval][out] */ BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_shortEJMode( 
            /* [retval][out] */ BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EJLimitNear( 
            /* [retval][out] */ BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_fullEJ( 
            /* [retval][out] */ BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_printCurrency( 
            /* [retval][out] */ BOOL __RPC_FAR *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IZFPStatusVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IZFPStatus __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IZFPStatus __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IZFPStatus __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IZFPStatus __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IZFPStatus __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IZFPStatus __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IZFPStatus __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ST0 )( 
            IZFPStatus __RPC_FAR * This,
            /* [retval][out] */ BYTE __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ST0 )( 
            IZFPStatus __RPC_FAR * This,
            /* [in] */ BYTE newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ST1 )( 
            IZFPStatus __RPC_FAR * This,
            /* [retval][out] */ BYTE __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ST1 )( 
            IZFPStatus __RPC_FAR * This,
            /* [in] */ BYTE newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ST2 )( 
            IZFPStatus __RPC_FAR * This,
            /* [retval][out] */ BYTE __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ST2 )( 
            IZFPStatus __RPC_FAR * This,
            /* [in] */ BYTE newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ST3 )( 
            IZFPStatus __RPC_FAR * This,
            /* [retval][out] */ BYTE __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ST3 )( 
            IZFPStatus __RPC_FAR * This,
            /* [in] */ BYTE newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ST4 )( 
            IZFPStatus __RPC_FAR * This,
            /* [retval][out] */ BYTE __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ST4 )( 
            IZFPStatus __RPC_FAR * This,
            /* [in] */ BYTE newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_wrongTimer )( 
            IZFPStatus __RPC_FAR * This,
            /* [retval][out] */ BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_wrongDate )( 
            IZFPStatus __RPC_FAR * This,
            /* [retval][out] */ BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_wrongRAM )( 
            IZFPStatus __RPC_FAR * This,
            /* [retval][out] */ BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_clockHardwareError )( 
            IZFPStatus __RPC_FAR * This,
            /* [retval][out] */ BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_paperOutPrinterError )( 
            IZFPStatus __RPC_FAR * This,
            /* [retval][out] */ BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_reportSumOverflow )( 
            IZFPStatus __RPC_FAR * This,
            /* [retval][out] */ BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_printLogo )( 
            IZFPStatus __RPC_FAR * This,
            /* [retval][out] */ BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_nonzeroDailyReport )( 
            IZFPStatus __RPC_FAR * This,
            /* [retval][out] */ BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_nonzeroArticleReport )( 
            IZFPStatus __RPC_FAR * This,
            /* [retval][out] */ BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_nonzeroOperatorReport )( 
            IZFPStatus __RPC_FAR * This,
            /* [retval][out] */ BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_duplicateNotPrinted )( 
            IZFPStatus __RPC_FAR * This,
            /* [retval][out] */ BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_openOfficialBon )( 
            IZFPStatus __RPC_FAR * This,
            /* [retval][out] */ BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_OpenFiscalBon )( 
            IZFPStatus __RPC_FAR * This,
            /* [retval][out] */ BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_detailedInfo )( 
            IZFPStatus __RPC_FAR * This,
            /* [retval][out] */ BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_VATinfo )( 
            IZFPStatus __RPC_FAR * This,
            /* [retval][out] */ BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_missingFiscalMemory )( 
            IZFPStatus __RPC_FAR * This,
            /* [retval][out] */ BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_wrongFiscalMemory )( 
            IZFPStatus __RPC_FAR * This,
            /* [retval][out] */ BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_fullFiscalMemory )( 
            IZFPStatus __RPC_FAR * This,
            /* [retval][out] */ BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_fiscalMemoryLimitNear )( 
            IZFPStatus __RPC_FAR * This,
            /* [retval][out] */ BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_hasDecimalPoint )( 
            IZFPStatus __RPC_FAR * This,
            /* [retval][out] */ BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_isFiscal )( 
            IZFPStatus __RPC_FAR * This,
            /* [retval][out] */ BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_hasFiscalAndFactoryNum )( 
            IZFPStatus __RPC_FAR * This,
            /* [retval][out] */ BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_autoCutter )( 
            IZFPStatus __RPC_FAR * This,
            /* [retval][out] */ BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_hasTransparentDisplay )( 
            IZFPStatus __RPC_FAR * This,
            /* [retval][out] */ BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_baud9600 )( 
            IZFPStatus __RPC_FAR * This,
            /* [retval][out] */ BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_autoTillOpen )( 
            IZFPStatus __RPC_FAR * This,
            /* [retval][out] */ BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_readOnlyFM )( 
            IZFPStatus __RPC_FAR * This,
            /* [retval][out] */ BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_powerDown )( 
            IZFPStatus __RPC_FAR * This,
            /* [retval][out] */ BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_printerOverheat )( 
            IZFPStatus __RPC_FAR * This,
            /* [retval][out] */ BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Blocked24HoursReport )( 
            IZFPStatus __RPC_FAR * This,
            /* [retval][out] */ BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_missingDisplay )( 
            IZFPStatus __RPC_FAR * This,
            /* [retval][out] */ BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_shortEJMode )( 
            IZFPStatus __RPC_FAR * This,
            /* [retval][out] */ BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_EJLimitNear )( 
            IZFPStatus __RPC_FAR * This,
            /* [retval][out] */ BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_fullEJ )( 
            IZFPStatus __RPC_FAR * This,
            /* [retval][out] */ BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_printCurrency )( 
            IZFPStatus __RPC_FAR * This,
            /* [retval][out] */ BOOL __RPC_FAR *pVal);
        
        END_INTERFACE
    } IZFPStatusVtbl;

    interface IZFPStatus
    {
        CONST_VTBL struct IZFPStatusVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IZFPStatus_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IZFPStatus_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IZFPStatus_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IZFPStatus_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IZFPStatus_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IZFPStatus_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IZFPStatus_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IZFPStatus_get_ST0(This,pVal)	\
    (This)->lpVtbl -> get_ST0(This,pVal)

#define IZFPStatus_put_ST0(This,newVal)	\
    (This)->lpVtbl -> put_ST0(This,newVal)

#define IZFPStatus_get_ST1(This,pVal)	\
    (This)->lpVtbl -> get_ST1(This,pVal)

#define IZFPStatus_put_ST1(This,newVal)	\
    (This)->lpVtbl -> put_ST1(This,newVal)

#define IZFPStatus_get_ST2(This,pVal)	\
    (This)->lpVtbl -> get_ST2(This,pVal)

#define IZFPStatus_put_ST2(This,newVal)	\
    (This)->lpVtbl -> put_ST2(This,newVal)

#define IZFPStatus_get_ST3(This,pVal)	\
    (This)->lpVtbl -> get_ST3(This,pVal)

#define IZFPStatus_put_ST3(This,newVal)	\
    (This)->lpVtbl -> put_ST3(This,newVal)

#define IZFPStatus_get_ST4(This,pVal)	\
    (This)->lpVtbl -> get_ST4(This,pVal)

#define IZFPStatus_put_ST4(This,newVal)	\
    (This)->lpVtbl -> put_ST4(This,newVal)

#define IZFPStatus_get_wrongTimer(This,pVal)	\
    (This)->lpVtbl -> get_wrongTimer(This,pVal)

#define IZFPStatus_get_wrongDate(This,pVal)	\
    (This)->lpVtbl -> get_wrongDate(This,pVal)

#define IZFPStatus_get_wrongRAM(This,pVal)	\
    (This)->lpVtbl -> get_wrongRAM(This,pVal)

#define IZFPStatus_get_clockHardwareError(This,pVal)	\
    (This)->lpVtbl -> get_clockHardwareError(This,pVal)

#define IZFPStatus_get_paperOutPrinterError(This,pVal)	\
    (This)->lpVtbl -> get_paperOutPrinterError(This,pVal)

#define IZFPStatus_get_reportSumOverflow(This,pVal)	\
    (This)->lpVtbl -> get_reportSumOverflow(This,pVal)

#define IZFPStatus_get_printLogo(This,pVal)	\
    (This)->lpVtbl -> get_printLogo(This,pVal)

#define IZFPStatus_get_nonzeroDailyReport(This,pVal)	\
    (This)->lpVtbl -> get_nonzeroDailyReport(This,pVal)

#define IZFPStatus_get_nonzeroArticleReport(This,pVal)	\
    (This)->lpVtbl -> get_nonzeroArticleReport(This,pVal)

#define IZFPStatus_get_nonzeroOperatorReport(This,pVal)	\
    (This)->lpVtbl -> get_nonzeroOperatorReport(This,pVal)

#define IZFPStatus_get_duplicateNotPrinted(This,pVal)	\
    (This)->lpVtbl -> get_duplicateNotPrinted(This,pVal)

#define IZFPStatus_get_openOfficialBon(This,pVal)	\
    (This)->lpVtbl -> get_openOfficialBon(This,pVal)

#define IZFPStatus_get_OpenFiscalBon(This,pVal)	\
    (This)->lpVtbl -> get_OpenFiscalBon(This,pVal)

#define IZFPStatus_get_detailedInfo(This,pVal)	\
    (This)->lpVtbl -> get_detailedInfo(This,pVal)

#define IZFPStatus_get_VATinfo(This,pVal)	\
    (This)->lpVtbl -> get_VATinfo(This,pVal)

#define IZFPStatus_get_missingFiscalMemory(This,pVal)	\
    (This)->lpVtbl -> get_missingFiscalMemory(This,pVal)

#define IZFPStatus_get_wrongFiscalMemory(This,pVal)	\
    (This)->lpVtbl -> get_wrongFiscalMemory(This,pVal)

#define IZFPStatus_get_fullFiscalMemory(This,pVal)	\
    (This)->lpVtbl -> get_fullFiscalMemory(This,pVal)

#define IZFPStatus_get_fiscalMemoryLimitNear(This,pVal)	\
    (This)->lpVtbl -> get_fiscalMemoryLimitNear(This,pVal)

#define IZFPStatus_get_hasDecimalPoint(This,pVal)	\
    (This)->lpVtbl -> get_hasDecimalPoint(This,pVal)

#define IZFPStatus_get_isFiscal(This,pVal)	\
    (This)->lpVtbl -> get_isFiscal(This,pVal)

#define IZFPStatus_get_hasFiscalAndFactoryNum(This,pVal)	\
    (This)->lpVtbl -> get_hasFiscalAndFactoryNum(This,pVal)

#define IZFPStatus_get_autoCutter(This,pVal)	\
    (This)->lpVtbl -> get_autoCutter(This,pVal)

#define IZFPStatus_get_hasTransparentDisplay(This,pVal)	\
    (This)->lpVtbl -> get_hasTransparentDisplay(This,pVal)

#define IZFPStatus_get_baud9600(This,pVal)	\
    (This)->lpVtbl -> get_baud9600(This,pVal)

#define IZFPStatus_get_autoTillOpen(This,pVal)	\
    (This)->lpVtbl -> get_autoTillOpen(This,pVal)

#define IZFPStatus_get_readOnlyFM(This,pVal)	\
    (This)->lpVtbl -> get_readOnlyFM(This,pVal)

#define IZFPStatus_get_powerDown(This,pVal)	\
    (This)->lpVtbl -> get_powerDown(This,pVal)

#define IZFPStatus_get_printerOverheat(This,pVal)	\
    (This)->lpVtbl -> get_printerOverheat(This,pVal)

#define IZFPStatus_get_Blocked24HoursReport(This,pVal)	\
    (This)->lpVtbl -> get_Blocked24HoursReport(This,pVal)

#define IZFPStatus_get_missingDisplay(This,pVal)	\
    (This)->lpVtbl -> get_missingDisplay(This,pVal)

#define IZFPStatus_get_shortEJMode(This,pVal)	\
    (This)->lpVtbl -> get_shortEJMode(This,pVal)

#define IZFPStatus_get_EJLimitNear(This,pVal)	\
    (This)->lpVtbl -> get_EJLimitNear(This,pVal)

#define IZFPStatus_get_fullEJ(This,pVal)	\
    (This)->lpVtbl -> get_fullEJ(This,pVal)

#define IZFPStatus_get_printCurrency(This,pVal)	\
    (This)->lpVtbl -> get_printCurrency(This,pVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IZFPStatus_get_ST0_Proxy( 
    IZFPStatus __RPC_FAR * This,
    /* [retval][out] */ BYTE __RPC_FAR *pVal);


void __RPC_STUB IZFPStatus_get_ST0_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IZFPStatus_put_ST0_Proxy( 
    IZFPStatus __RPC_FAR * This,
    /* [in] */ BYTE newVal);


void __RPC_STUB IZFPStatus_put_ST0_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IZFPStatus_get_ST1_Proxy( 
    IZFPStatus __RPC_FAR * This,
    /* [retval][out] */ BYTE __RPC_FAR *pVal);


void __RPC_STUB IZFPStatus_get_ST1_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IZFPStatus_put_ST1_Proxy( 
    IZFPStatus __RPC_FAR * This,
    /* [in] */ BYTE newVal);


void __RPC_STUB IZFPStatus_put_ST1_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IZFPStatus_get_ST2_Proxy( 
    IZFPStatus __RPC_FAR * This,
    /* [retval][out] */ BYTE __RPC_FAR *pVal);


void __RPC_STUB IZFPStatus_get_ST2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IZFPStatus_put_ST2_Proxy( 
    IZFPStatus __RPC_FAR * This,
    /* [in] */ BYTE newVal);


void __RPC_STUB IZFPStatus_put_ST2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IZFPStatus_get_ST3_Proxy( 
    IZFPStatus __RPC_FAR * This,
    /* [retval][out] */ BYTE __RPC_FAR *pVal);


void __RPC_STUB IZFPStatus_get_ST3_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IZFPStatus_put_ST3_Proxy( 
    IZFPStatus __RPC_FAR * This,
    /* [in] */ BYTE newVal);


void __RPC_STUB IZFPStatus_put_ST3_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IZFPStatus_get_ST4_Proxy( 
    IZFPStatus __RPC_FAR * This,
    /* [retval][out] */ BYTE __RPC_FAR *pVal);


void __RPC_STUB IZFPStatus_get_ST4_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IZFPStatus_put_ST4_Proxy( 
    IZFPStatus __RPC_FAR * This,
    /* [in] */ BYTE newVal);


void __RPC_STUB IZFPStatus_put_ST4_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IZFPStatus_get_wrongTimer_Proxy( 
    IZFPStatus __RPC_FAR * This,
    /* [retval][out] */ BOOL __RPC_FAR *pVal);


void __RPC_STUB IZFPStatus_get_wrongTimer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IZFPStatus_get_wrongDate_Proxy( 
    IZFPStatus __RPC_FAR * This,
    /* [retval][out] */ BOOL __RPC_FAR *pVal);


void __RPC_STUB IZFPStatus_get_wrongDate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IZFPStatus_get_wrongRAM_Proxy( 
    IZFPStatus __RPC_FAR * This,
    /* [retval][out] */ BOOL __RPC_FAR *pVal);


void __RPC_STUB IZFPStatus_get_wrongRAM_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IZFPStatus_get_clockHardwareError_Proxy( 
    IZFPStatus __RPC_FAR * This,
    /* [retval][out] */ BOOL __RPC_FAR *pVal);


void __RPC_STUB IZFPStatus_get_clockHardwareError_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IZFPStatus_get_paperOutPrinterError_Proxy( 
    IZFPStatus __RPC_FAR * This,
    /* [retval][out] */ BOOL __RPC_FAR *pVal);


void __RPC_STUB IZFPStatus_get_paperOutPrinterError_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IZFPStatus_get_reportSumOverflow_Proxy( 
    IZFPStatus __RPC_FAR * This,
    /* [retval][out] */ BOOL __RPC_FAR *pVal);


void __RPC_STUB IZFPStatus_get_reportSumOverflow_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IZFPStatus_get_printLogo_Proxy( 
    IZFPStatus __RPC_FAR * This,
    /* [retval][out] */ BOOL __RPC_FAR *pVal);


void __RPC_STUB IZFPStatus_get_printLogo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IZFPStatus_get_nonzeroDailyReport_Proxy( 
    IZFPStatus __RPC_FAR * This,
    /* [retval][out] */ BOOL __RPC_FAR *pVal);


void __RPC_STUB IZFPStatus_get_nonzeroDailyReport_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IZFPStatus_get_nonzeroArticleReport_Proxy( 
    IZFPStatus __RPC_FAR * This,
    /* [retval][out] */ BOOL __RPC_FAR *pVal);


void __RPC_STUB IZFPStatus_get_nonzeroArticleReport_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IZFPStatus_get_nonzeroOperatorReport_Proxy( 
    IZFPStatus __RPC_FAR * This,
    /* [retval][out] */ BOOL __RPC_FAR *pVal);


void __RPC_STUB IZFPStatus_get_nonzeroOperatorReport_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IZFPStatus_get_duplicateNotPrinted_Proxy( 
    IZFPStatus __RPC_FAR * This,
    /* [retval][out] */ BOOL __RPC_FAR *pVal);


void __RPC_STUB IZFPStatus_get_duplicateNotPrinted_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IZFPStatus_get_openOfficialBon_Proxy( 
    IZFPStatus __RPC_FAR * This,
    /* [retval][out] */ BOOL __RPC_FAR *pVal);


void __RPC_STUB IZFPStatus_get_openOfficialBon_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IZFPStatus_get_OpenFiscalBon_Proxy( 
    IZFPStatus __RPC_FAR * This,
    /* [retval][out] */ BOOL __RPC_FAR *pVal);


void __RPC_STUB IZFPStatus_get_OpenFiscalBon_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IZFPStatus_get_detailedInfo_Proxy( 
    IZFPStatus __RPC_FAR * This,
    /* [retval][out] */ BOOL __RPC_FAR *pVal);


void __RPC_STUB IZFPStatus_get_detailedInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IZFPStatus_get_VATinfo_Proxy( 
    IZFPStatus __RPC_FAR * This,
    /* [retval][out] */ BOOL __RPC_FAR *pVal);


void __RPC_STUB IZFPStatus_get_VATinfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IZFPStatus_get_missingFiscalMemory_Proxy( 
    IZFPStatus __RPC_FAR * This,
    /* [retval][out] */ BOOL __RPC_FAR *pVal);


void __RPC_STUB IZFPStatus_get_missingFiscalMemory_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IZFPStatus_get_wrongFiscalMemory_Proxy( 
    IZFPStatus __RPC_FAR * This,
    /* [retval][out] */ BOOL __RPC_FAR *pVal);


void __RPC_STUB IZFPStatus_get_wrongFiscalMemory_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IZFPStatus_get_fullFiscalMemory_Proxy( 
    IZFPStatus __RPC_FAR * This,
    /* [retval][out] */ BOOL __RPC_FAR *pVal);


void __RPC_STUB IZFPStatus_get_fullFiscalMemory_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IZFPStatus_get_fiscalMemoryLimitNear_Proxy( 
    IZFPStatus __RPC_FAR * This,
    /* [retval][out] */ BOOL __RPC_FAR *pVal);


void __RPC_STUB IZFPStatus_get_fiscalMemoryLimitNear_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IZFPStatus_get_hasDecimalPoint_Proxy( 
    IZFPStatus __RPC_FAR * This,
    /* [retval][out] */ BOOL __RPC_FAR *pVal);


void __RPC_STUB IZFPStatus_get_hasDecimalPoint_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IZFPStatus_get_isFiscal_Proxy( 
    IZFPStatus __RPC_FAR * This,
    /* [retval][out] */ BOOL __RPC_FAR *pVal);


void __RPC_STUB IZFPStatus_get_isFiscal_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IZFPStatus_get_hasFiscalAndFactoryNum_Proxy( 
    IZFPStatus __RPC_FAR * This,
    /* [retval][out] */ BOOL __RPC_FAR *pVal);


void __RPC_STUB IZFPStatus_get_hasFiscalAndFactoryNum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IZFPStatus_get_autoCutter_Proxy( 
    IZFPStatus __RPC_FAR * This,
    /* [retval][out] */ BOOL __RPC_FAR *pVal);


void __RPC_STUB IZFPStatus_get_autoCutter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IZFPStatus_get_hasTransparentDisplay_Proxy( 
    IZFPStatus __RPC_FAR * This,
    /* [retval][out] */ BOOL __RPC_FAR *pVal);


void __RPC_STUB IZFPStatus_get_hasTransparentDisplay_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IZFPStatus_get_baud9600_Proxy( 
    IZFPStatus __RPC_FAR * This,
    /* [retval][out] */ BOOL __RPC_FAR *pVal);


void __RPC_STUB IZFPStatus_get_baud9600_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IZFPStatus_get_autoTillOpen_Proxy( 
    IZFPStatus __RPC_FAR * This,
    /* [retval][out] */ BOOL __RPC_FAR *pVal);


void __RPC_STUB IZFPStatus_get_autoTillOpen_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IZFPStatus_get_readOnlyFM_Proxy( 
    IZFPStatus __RPC_FAR * This,
    /* [retval][out] */ BOOL __RPC_FAR *pVal);


void __RPC_STUB IZFPStatus_get_readOnlyFM_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IZFPStatus_get_powerDown_Proxy( 
    IZFPStatus __RPC_FAR * This,
    /* [retval][out] */ BOOL __RPC_FAR *pVal);


void __RPC_STUB IZFPStatus_get_powerDown_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IZFPStatus_get_printerOverheat_Proxy( 
    IZFPStatus __RPC_FAR * This,
    /* [retval][out] */ BOOL __RPC_FAR *pVal);


void __RPC_STUB IZFPStatus_get_printerOverheat_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IZFPStatus_get_Blocked24HoursReport_Proxy( 
    IZFPStatus __RPC_FAR * This,
    /* [retval][out] */ BOOL __RPC_FAR *pVal);


void __RPC_STUB IZFPStatus_get_Blocked24HoursReport_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IZFPStatus_get_missingDisplay_Proxy( 
    IZFPStatus __RPC_FAR * This,
    /* [retval][out] */ BOOL __RPC_FAR *pVal);


void __RPC_STUB IZFPStatus_get_missingDisplay_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IZFPStatus_get_shortEJMode_Proxy( 
    IZFPStatus __RPC_FAR * This,
    /* [retval][out] */ BOOL __RPC_FAR *pVal);


void __RPC_STUB IZFPStatus_get_shortEJMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IZFPStatus_get_EJLimitNear_Proxy( 
    IZFPStatus __RPC_FAR * This,
    /* [retval][out] */ BOOL __RPC_FAR *pVal);


void __RPC_STUB IZFPStatus_get_EJLimitNear_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IZFPStatus_get_fullEJ_Proxy( 
    IZFPStatus __RPC_FAR * This,
    /* [retval][out] */ BOOL __RPC_FAR *pVal);


void __RPC_STUB IZFPStatus_get_fullEJ_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IZFPStatus_get_printCurrency_Proxy( 
    IZFPStatus __RPC_FAR * This,
    /* [retval][out] */ BOOL __RPC_FAR *pVal);


void __RPC_STUB IZFPStatus_get_printCurrency_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IZFPStatus_INTERFACE_DEFINED__ */


#ifndef __IInvoiceNumbers_INTERFACE_DEFINED__
#define __IInvoiceNumbers_INTERFACE_DEFINED__

/* interface IInvoiceNumbers */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IInvoiceNumbers;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6591F815-2562-43F2-888C-6E5653B00284")
    IInvoiceNumbers : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_nextNum( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_nextNum( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_lastNum( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_lastNum( 
            /* [in] */ BSTR newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInvoiceNumbersVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IInvoiceNumbers __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IInvoiceNumbers __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IInvoiceNumbers __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IInvoiceNumbers __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IInvoiceNumbers __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IInvoiceNumbers __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IInvoiceNumbers __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_nextNum )( 
            IInvoiceNumbers __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_nextNum )( 
            IInvoiceNumbers __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_lastNum )( 
            IInvoiceNumbers __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_lastNum )( 
            IInvoiceNumbers __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        END_INTERFACE
    } IInvoiceNumbersVtbl;

    interface IInvoiceNumbers
    {
        CONST_VTBL struct IInvoiceNumbersVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInvoiceNumbers_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IInvoiceNumbers_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IInvoiceNumbers_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IInvoiceNumbers_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IInvoiceNumbers_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IInvoiceNumbers_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IInvoiceNumbers_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IInvoiceNumbers_get_nextNum(This,pVal)	\
    (This)->lpVtbl -> get_nextNum(This,pVal)

#define IInvoiceNumbers_put_nextNum(This,newVal)	\
    (This)->lpVtbl -> put_nextNum(This,newVal)

#define IInvoiceNumbers_get_lastNum(This,pVal)	\
    (This)->lpVtbl -> get_lastNum(This,pVal)

#define IInvoiceNumbers_put_lastNum(This,newVal)	\
    (This)->lpVtbl -> put_lastNum(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IInvoiceNumbers_get_nextNum_Proxy( 
    IInvoiceNumbers __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IInvoiceNumbers_get_nextNum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IInvoiceNumbers_put_nextNum_Proxy( 
    IInvoiceNumbers __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IInvoiceNumbers_put_nextNum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IInvoiceNumbers_get_lastNum_Proxy( 
    IInvoiceNumbers __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IInvoiceNumbers_get_lastNum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IInvoiceNumbers_put_lastNum_Proxy( 
    IInvoiceNumbers __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IInvoiceNumbers_put_lastNum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IInvoiceNumbers_INTERFACE_DEFINED__ */


#ifndef __ICurrencyInfo_INTERFACE_DEFINED__
#define __ICurrencyInfo_INTERFACE_DEFINED__

/* interface ICurrencyInfo */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ICurrencyInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B5B0717B-6103-4569-8DE7-BD3A1F161049")
    ICurrencyInfo : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_price_buy( 
            /* [retval][out] */ double __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_price_buy( 
            /* [in] */ double newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_price_sell( 
            /* [retval][out] */ double __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_price_sell( 
            /* [in] */ double newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_price_central_bank( 
            /* [retval][out] */ double __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_price_central_bank( 
            /* [in] */ double newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_amount_available( 
            /* [retval][out] */ double __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_amount_available( 
            /* [in] */ double newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_amount_bought( 
            /* [retval][out] */ double __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_amount_bought( 
            /* [in] */ double newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_amount_sold( 
            /* [retval][out] */ double __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_amount_sold( 
            /* [in] */ double newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_amount_in( 
            /* [retval][out] */ double __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_amount_in( 
            /* [in] */ double newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_amount_out( 
            /* [retval][out] */ double __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_amount_out( 
            /* [in] */ double newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ICurrencyInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ICurrencyInfo __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ICurrencyInfo __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ICurrencyInfo __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            ICurrencyInfo __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            ICurrencyInfo __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            ICurrencyInfo __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            ICurrencyInfo __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_price_buy )( 
            ICurrencyInfo __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_price_buy )( 
            ICurrencyInfo __RPC_FAR * This,
            /* [in] */ double newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_price_sell )( 
            ICurrencyInfo __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_price_sell )( 
            ICurrencyInfo __RPC_FAR * This,
            /* [in] */ double newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_price_central_bank )( 
            ICurrencyInfo __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_price_central_bank )( 
            ICurrencyInfo __RPC_FAR * This,
            /* [in] */ double newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_amount_available )( 
            ICurrencyInfo __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_amount_available )( 
            ICurrencyInfo __RPC_FAR * This,
            /* [in] */ double newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_amount_bought )( 
            ICurrencyInfo __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_amount_bought )( 
            ICurrencyInfo __RPC_FAR * This,
            /* [in] */ double newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_amount_sold )( 
            ICurrencyInfo __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_amount_sold )( 
            ICurrencyInfo __RPC_FAR * This,
            /* [in] */ double newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_amount_in )( 
            ICurrencyInfo __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_amount_in )( 
            ICurrencyInfo __RPC_FAR * This,
            /* [in] */ double newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_amount_out )( 
            ICurrencyInfo __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_amount_out )( 
            ICurrencyInfo __RPC_FAR * This,
            /* [in] */ double newVal);
        
        END_INTERFACE
    } ICurrencyInfoVtbl;

    interface ICurrencyInfo
    {
        CONST_VTBL struct ICurrencyInfoVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICurrencyInfo_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ICurrencyInfo_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ICurrencyInfo_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ICurrencyInfo_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ICurrencyInfo_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ICurrencyInfo_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ICurrencyInfo_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ICurrencyInfo_get_price_buy(This,pVal)	\
    (This)->lpVtbl -> get_price_buy(This,pVal)

#define ICurrencyInfo_put_price_buy(This,newVal)	\
    (This)->lpVtbl -> put_price_buy(This,newVal)

#define ICurrencyInfo_get_price_sell(This,pVal)	\
    (This)->lpVtbl -> get_price_sell(This,pVal)

#define ICurrencyInfo_put_price_sell(This,newVal)	\
    (This)->lpVtbl -> put_price_sell(This,newVal)

#define ICurrencyInfo_get_price_central_bank(This,pVal)	\
    (This)->lpVtbl -> get_price_central_bank(This,pVal)

#define ICurrencyInfo_put_price_central_bank(This,newVal)	\
    (This)->lpVtbl -> put_price_central_bank(This,newVal)

#define ICurrencyInfo_get_amount_available(This,pVal)	\
    (This)->lpVtbl -> get_amount_available(This,pVal)

#define ICurrencyInfo_put_amount_available(This,newVal)	\
    (This)->lpVtbl -> put_amount_available(This,newVal)

#define ICurrencyInfo_get_amount_bought(This,pVal)	\
    (This)->lpVtbl -> get_amount_bought(This,pVal)

#define ICurrencyInfo_put_amount_bought(This,newVal)	\
    (This)->lpVtbl -> put_amount_bought(This,newVal)

#define ICurrencyInfo_get_amount_sold(This,pVal)	\
    (This)->lpVtbl -> get_amount_sold(This,pVal)

#define ICurrencyInfo_put_amount_sold(This,newVal)	\
    (This)->lpVtbl -> put_amount_sold(This,newVal)

#define ICurrencyInfo_get_amount_in(This,pVal)	\
    (This)->lpVtbl -> get_amount_in(This,pVal)

#define ICurrencyInfo_put_amount_in(This,newVal)	\
    (This)->lpVtbl -> put_amount_in(This,newVal)

#define ICurrencyInfo_get_amount_out(This,pVal)	\
    (This)->lpVtbl -> get_amount_out(This,pVal)

#define ICurrencyInfo_put_amount_out(This,newVal)	\
    (This)->lpVtbl -> put_amount_out(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ICurrencyInfo_get_price_buy_Proxy( 
    ICurrencyInfo __RPC_FAR * This,
    /* [retval][out] */ double __RPC_FAR *pVal);


void __RPC_STUB ICurrencyInfo_get_price_buy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ICurrencyInfo_put_price_buy_Proxy( 
    ICurrencyInfo __RPC_FAR * This,
    /* [in] */ double newVal);


void __RPC_STUB ICurrencyInfo_put_price_buy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ICurrencyInfo_get_price_sell_Proxy( 
    ICurrencyInfo __RPC_FAR * This,
    /* [retval][out] */ double __RPC_FAR *pVal);


void __RPC_STUB ICurrencyInfo_get_price_sell_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ICurrencyInfo_put_price_sell_Proxy( 
    ICurrencyInfo __RPC_FAR * This,
    /* [in] */ double newVal);


void __RPC_STUB ICurrencyInfo_put_price_sell_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ICurrencyInfo_get_price_central_bank_Proxy( 
    ICurrencyInfo __RPC_FAR * This,
    /* [retval][out] */ double __RPC_FAR *pVal);


void __RPC_STUB ICurrencyInfo_get_price_central_bank_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ICurrencyInfo_put_price_central_bank_Proxy( 
    ICurrencyInfo __RPC_FAR * This,
    /* [in] */ double newVal);


void __RPC_STUB ICurrencyInfo_put_price_central_bank_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ICurrencyInfo_get_amount_available_Proxy( 
    ICurrencyInfo __RPC_FAR * This,
    /* [retval][out] */ double __RPC_FAR *pVal);


void __RPC_STUB ICurrencyInfo_get_amount_available_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ICurrencyInfo_put_amount_available_Proxy( 
    ICurrencyInfo __RPC_FAR * This,
    /* [in] */ double newVal);


void __RPC_STUB ICurrencyInfo_put_amount_available_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ICurrencyInfo_get_amount_bought_Proxy( 
    ICurrencyInfo __RPC_FAR * This,
    /* [retval][out] */ double __RPC_FAR *pVal);


void __RPC_STUB ICurrencyInfo_get_amount_bought_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ICurrencyInfo_put_amount_bought_Proxy( 
    ICurrencyInfo __RPC_FAR * This,
    /* [in] */ double newVal);


void __RPC_STUB ICurrencyInfo_put_amount_bought_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ICurrencyInfo_get_amount_sold_Proxy( 
    ICurrencyInfo __RPC_FAR * This,
    /* [retval][out] */ double __RPC_FAR *pVal);


void __RPC_STUB ICurrencyInfo_get_amount_sold_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ICurrencyInfo_put_amount_sold_Proxy( 
    ICurrencyInfo __RPC_FAR * This,
    /* [in] */ double newVal);


void __RPC_STUB ICurrencyInfo_put_amount_sold_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ICurrencyInfo_get_amount_in_Proxy( 
    ICurrencyInfo __RPC_FAR * This,
    /* [retval][out] */ double __RPC_FAR *pVal);


void __RPC_STUB ICurrencyInfo_get_amount_in_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ICurrencyInfo_put_amount_in_Proxy( 
    ICurrencyInfo __RPC_FAR * This,
    /* [in] */ double newVal);


void __RPC_STUB ICurrencyInfo_put_amount_in_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ICurrencyInfo_get_amount_out_Proxy( 
    ICurrencyInfo __RPC_FAR * This,
    /* [retval][out] */ double __RPC_FAR *pVal);


void __RPC_STUB ICurrencyInfo_get_amount_out_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ICurrencyInfo_put_amount_out_Proxy( 
    ICurrencyInfo __RPC_FAR * This,
    /* [in] */ double newVal);


void __RPC_STUB ICurrencyInfo_put_amount_out_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ICurrencyInfo_INTERFACE_DEFINED__ */


#ifndef __IReceiptStatus_INTERFACE_DEFINED__
#define __IReceiptStatus_INTERFACE_DEFINED__

/* interface IReceiptStatus */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IReceiptStatus;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1411DFB5-89AD-47A4-98AC-5F53A3628633")
    IReceiptStatus : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_is_sale( 
            /* [retval][out] */ BYTE __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_is_sale( 
            /* [in] */ BYTE newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_is_open( 
            /* [retval][out] */ BYTE __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_is_open( 
            /* [in] */ BYTE newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_is_payment_started( 
            /* [retval][out] */ BYTE __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_is_payment_started( 
            /* [in] */ BYTE newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_is_payment_finished( 
            /* [retval][out] */ BYTE __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_is_payment_finished( 
            /* [in] */ BYTE newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_has_power_interrupted( 
            /* [retval][out] */ BYTE __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_has_power_interrupted( 
            /* [in] */ BYTE newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_transactions_count( 
            /* [retval][out] */ int __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_transactions_count( 
            /* [in] */ int newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_taxgroup_subtotal_amount( 
            /* [retval][out] */ double __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_taxgroup_subtotal_amount( 
            /* [in] */ double newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_change_amount( 
            /* [retval][out] */ double __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_change_amount( 
            /* [in] */ double newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IReceiptStatusVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IReceiptStatus __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IReceiptStatus __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IReceiptStatus __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IReceiptStatus __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IReceiptStatus __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IReceiptStatus __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IReceiptStatus __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_is_sale )( 
            IReceiptStatus __RPC_FAR * This,
            /* [retval][out] */ BYTE __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_is_sale )( 
            IReceiptStatus __RPC_FAR * This,
            /* [in] */ BYTE newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_is_open )( 
            IReceiptStatus __RPC_FAR * This,
            /* [retval][out] */ BYTE __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_is_open )( 
            IReceiptStatus __RPC_FAR * This,
            /* [in] */ BYTE newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_is_payment_started )( 
            IReceiptStatus __RPC_FAR * This,
            /* [retval][out] */ BYTE __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_is_payment_started )( 
            IReceiptStatus __RPC_FAR * This,
            /* [in] */ BYTE newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_is_payment_finished )( 
            IReceiptStatus __RPC_FAR * This,
            /* [retval][out] */ BYTE __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_is_payment_finished )( 
            IReceiptStatus __RPC_FAR * This,
            /* [in] */ BYTE newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_has_power_interrupted )( 
            IReceiptStatus __RPC_FAR * This,
            /* [retval][out] */ BYTE __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_has_power_interrupted )( 
            IReceiptStatus __RPC_FAR * This,
            /* [in] */ BYTE newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_transactions_count )( 
            IReceiptStatus __RPC_FAR * This,
            /* [retval][out] */ int __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_transactions_count )( 
            IReceiptStatus __RPC_FAR * This,
            /* [in] */ int newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_taxgroup_subtotal_amount )( 
            IReceiptStatus __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_taxgroup_subtotal_amount )( 
            IReceiptStatus __RPC_FAR * This,
            /* [in] */ double newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_change_amount )( 
            IReceiptStatus __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_change_amount )( 
            IReceiptStatus __RPC_FAR * This,
            /* [in] */ double newVal);
        
        END_INTERFACE
    } IReceiptStatusVtbl;

    interface IReceiptStatus
    {
        CONST_VTBL struct IReceiptStatusVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IReceiptStatus_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IReceiptStatus_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IReceiptStatus_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IReceiptStatus_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IReceiptStatus_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IReceiptStatus_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IReceiptStatus_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IReceiptStatus_get_is_sale(This,pVal)	\
    (This)->lpVtbl -> get_is_sale(This,pVal)

#define IReceiptStatus_put_is_sale(This,newVal)	\
    (This)->lpVtbl -> put_is_sale(This,newVal)

#define IReceiptStatus_get_is_open(This,pVal)	\
    (This)->lpVtbl -> get_is_open(This,pVal)

#define IReceiptStatus_put_is_open(This,newVal)	\
    (This)->lpVtbl -> put_is_open(This,newVal)

#define IReceiptStatus_get_is_payment_started(This,pVal)	\
    (This)->lpVtbl -> get_is_payment_started(This,pVal)

#define IReceiptStatus_put_is_payment_started(This,newVal)	\
    (This)->lpVtbl -> put_is_payment_started(This,newVal)

#define IReceiptStatus_get_is_payment_finished(This,pVal)	\
    (This)->lpVtbl -> get_is_payment_finished(This,pVal)

#define IReceiptStatus_put_is_payment_finished(This,newVal)	\
    (This)->lpVtbl -> put_is_payment_finished(This,newVal)

#define IReceiptStatus_get_has_power_interrupted(This,pVal)	\
    (This)->lpVtbl -> get_has_power_interrupted(This,pVal)

#define IReceiptStatus_put_has_power_interrupted(This,newVal)	\
    (This)->lpVtbl -> put_has_power_interrupted(This,newVal)

#define IReceiptStatus_get_transactions_count(This,pVal)	\
    (This)->lpVtbl -> get_transactions_count(This,pVal)

#define IReceiptStatus_put_transactions_count(This,newVal)	\
    (This)->lpVtbl -> put_transactions_count(This,newVal)

#define IReceiptStatus_get_taxgroup_subtotal_amount(This,pVal)	\
    (This)->lpVtbl -> get_taxgroup_subtotal_amount(This,pVal)

#define IReceiptStatus_put_taxgroup_subtotal_amount(This,newVal)	\
    (This)->lpVtbl -> put_taxgroup_subtotal_amount(This,newVal)

#define IReceiptStatus_get_change_amount(This,pVal)	\
    (This)->lpVtbl -> get_change_amount(This,pVal)

#define IReceiptStatus_put_change_amount(This,newVal)	\
    (This)->lpVtbl -> put_change_amount(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IReceiptStatus_get_is_sale_Proxy( 
    IReceiptStatus __RPC_FAR * This,
    /* [retval][out] */ BYTE __RPC_FAR *pVal);


void __RPC_STUB IReceiptStatus_get_is_sale_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IReceiptStatus_put_is_sale_Proxy( 
    IReceiptStatus __RPC_FAR * This,
    /* [in] */ BYTE newVal);


void __RPC_STUB IReceiptStatus_put_is_sale_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IReceiptStatus_get_is_open_Proxy( 
    IReceiptStatus __RPC_FAR * This,
    /* [retval][out] */ BYTE __RPC_FAR *pVal);


void __RPC_STUB IReceiptStatus_get_is_open_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IReceiptStatus_put_is_open_Proxy( 
    IReceiptStatus __RPC_FAR * This,
    /* [in] */ BYTE newVal);


void __RPC_STUB IReceiptStatus_put_is_open_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IReceiptStatus_get_is_payment_started_Proxy( 
    IReceiptStatus __RPC_FAR * This,
    /* [retval][out] */ BYTE __RPC_FAR *pVal);


void __RPC_STUB IReceiptStatus_get_is_payment_started_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IReceiptStatus_put_is_payment_started_Proxy( 
    IReceiptStatus __RPC_FAR * This,
    /* [in] */ BYTE newVal);


void __RPC_STUB IReceiptStatus_put_is_payment_started_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IReceiptStatus_get_is_payment_finished_Proxy( 
    IReceiptStatus __RPC_FAR * This,
    /* [retval][out] */ BYTE __RPC_FAR *pVal);


void __RPC_STUB IReceiptStatus_get_is_payment_finished_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IReceiptStatus_put_is_payment_finished_Proxy( 
    IReceiptStatus __RPC_FAR * This,
    /* [in] */ BYTE newVal);


void __RPC_STUB IReceiptStatus_put_is_payment_finished_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IReceiptStatus_get_has_power_interrupted_Proxy( 
    IReceiptStatus __RPC_FAR * This,
    /* [retval][out] */ BYTE __RPC_FAR *pVal);


void __RPC_STUB IReceiptStatus_get_has_power_interrupted_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IReceiptStatus_put_has_power_interrupted_Proxy( 
    IReceiptStatus __RPC_FAR * This,
    /* [in] */ BYTE newVal);


void __RPC_STUB IReceiptStatus_put_has_power_interrupted_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IReceiptStatus_get_transactions_count_Proxy( 
    IReceiptStatus __RPC_FAR * This,
    /* [retval][out] */ int __RPC_FAR *pVal);


void __RPC_STUB IReceiptStatus_get_transactions_count_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IReceiptStatus_put_transactions_count_Proxy( 
    IReceiptStatus __RPC_FAR * This,
    /* [in] */ int newVal);


void __RPC_STUB IReceiptStatus_put_transactions_count_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IReceiptStatus_get_taxgroup_subtotal_amount_Proxy( 
    IReceiptStatus __RPC_FAR * This,
    /* [retval][out] */ double __RPC_FAR *pVal);


void __RPC_STUB IReceiptStatus_get_taxgroup_subtotal_amount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IReceiptStatus_put_taxgroup_subtotal_amount_Proxy( 
    IReceiptStatus __RPC_FAR * This,
    /* [in] */ double newVal);


void __RPC_STUB IReceiptStatus_put_taxgroup_subtotal_amount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IReceiptStatus_get_change_amount_Proxy( 
    IReceiptStatus __RPC_FAR * This,
    /* [retval][out] */ double __RPC_FAR *pVal);


void __RPC_STUB IReceiptStatus_get_change_amount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IReceiptStatus_put_change_amount_Proxy( 
    IReceiptStatus __RPC_FAR * This,
    /* [in] */ double newVal);


void __RPC_STUB IReceiptStatus_put_change_amount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IReceiptStatus_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_ZekaFP;

#ifdef __cplusplus

class DECLSPEC_UUID("2394FFB1-BB5E-4454-9B40-6F75006D27AA")
ZekaFP;
#endif

EXTERN_C const CLSID CLSID_GetCurrentBonInfoRes;

#ifdef __cplusplus

class DECLSPEC_UUID("A52D1058-A873-4BE7-A94C-1A5DF6E6D345")
GetCurrentBonInfoRes;
#endif

EXTERN_C const CLSID CLSID_TaxNumbers;

#ifdef __cplusplus

class DECLSPEC_UUID("5C5335AF-6042-4246-94CE-4343FD3F7872")
TaxNumbers;
#endif

EXTERN_C const CLSID CLSID_PayTypes;

#ifdef __cplusplus

class DECLSPEC_UUID("5F26D9CE-4B61-43B6-900F-ABB48F5AA6A6")
PayTypes;
#endif

EXTERN_C const CLSID CLSID_ZFPParameters;

#ifdef __cplusplus

class DECLSPEC_UUID("75E2C498-0DAE-4CFC-BD3F-20CBEC338EA7")
ZFPParameters;
#endif

EXTERN_C const CLSID CLSID_OperatorInfo;

#ifdef __cplusplus

class DECLSPEC_UUID("97866887-9FF8-4D60-A7EE-132E46587FA5")
OperatorInfo;
#endif

EXTERN_C const CLSID CLSID_ArticleInfo;

#ifdef __cplusplus

class DECLSPEC_UUID("4B2E1B2E-4C07-471E-BC18-7497D0104348")
ArticleInfo;
#endif

EXTERN_C const CLSID CLSID_DailySums;

#ifdef __cplusplus

class DECLSPEC_UUID("52F50CD0-B861-457C-9F2C-6D1295060DC3")
DailySums;
#endif

EXTERN_C const CLSID CLSID_FiscalReportData;

#ifdef __cplusplus

class DECLSPEC_UUID("DDFA7C5F-E120-4293-97D6-2467DBED2B9B")
FiscalReportData;
#endif

EXTERN_C const CLSID CLSID_DailyReport;

#ifdef __cplusplus

class DECLSPEC_UUID("1B381FCB-9A9E-456B-87D8-D5883007620C")
DailyReport;
#endif

EXTERN_C const CLSID CLSID_ZFPStatus;

#ifdef __cplusplus

class DECLSPEC_UUID("046BF363-4057-4489-B9C6-5C28D48DAF8D")
ZFPStatus;
#endif

EXTERN_C const CLSID CLSID_InvoiceNumbers;

#ifdef __cplusplus

class DECLSPEC_UUID("BEBD9667-9A17-44A0-B568-E1A9232619C5")
InvoiceNumbers;
#endif

EXTERN_C const CLSID CLSID_CurrencyInfo;

#ifdef __cplusplus

class DECLSPEC_UUID("F661C687-5A22-40AB-B4A9-5C396057120A")
CurrencyInfo;
#endif

EXTERN_C const CLSID CLSID_ReceiptStatus;

#ifdef __cplusplus

class DECLSPEC_UUID("7C5D7CBE-0071-433B-A5F5-311D47DA43F2")
ReceiptStatus;
#endif
#endif /* __ZFPCOMLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long __RPC_FAR *, unsigned long            , BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long __RPC_FAR *, BSTR __RPC_FAR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
