//////////////////////////////////////////////////////////////////////
// Copyright (c) 2005-2008 Tremol Ltd.
// License: Mozilla Public License 1.1
// Contacts: software@tremol.bg
//////////////////////////////////////////////////////////////////////

#ifndef _ZEKA_FP_
#define _ZEKA_FP_

// GetErrorString languages
#define ZFP_LANG_EN					0		// english
#define ZFP_LANG_BG					1		// bulgarian

// PrintText modes
#define ZFP_TEXTALIGNLEFT			0		// left alignment
#define ZFP_TEXTALIGNRIGHT			1		// right alignment
#define ZFP_TEXTALIGNCENTER			2		// center text

// baud rates
#define ZBR_9600					9600
#define ZBR_19200					19200
#define ZBR_38400					38400
#define ZBR_57600					57600
#define ZBR_115200					115200

// Fiscal Printer types SetZFPType() and GetZFPType()
#define ZFPT_BG						0		// bulgarian
#define ZFPT_RO						1		// romanian
#define ZFPT_BGEU					2		// bulgarian euro

// flags CalcIntermediateSum
#define ZFP_ISPRINT					1		// print the intermediate sum
#define ZFP_ISSHOW					2		// show the intermediate sum on the display
#define ZFP_ISPERCENT				4       // the discount/addition is in percents

#define ZFP_ADSHOW					2		// show the intermediate sum on the display
#define ZFP_ADPERCENT				4       // the discount/addition is in percents
#define ZFP_ADTRANS					8       // discount on transaction amount
#define ZFP_ADAUTO					16      // automatic selection - intermediate sum or transaction amount

// flags GetCurrentBonInfo flags
#define ZFPB_OPENBON				1		// the receipt is open
#define ZFPB_NOVOID					2		// void operations are not allowed
#define ZFPB_DDS					4		// DDS info is printed
#define ZFPB_PODRBON				8       // detailed info is printed
#define ZFPB_PAYSTART				16		// payment is started
#define ZFPB_PAYEND					32		// payment is finished
#define ZFPB_POWERDOWN				64		// power down inside fiscal receipt
#define ZFPB_INVOICE				128		// receipt is an invoice

// change types used by PaymentEU
#define ZFP_CHANGEINCASH			0		// change is in cash
#define ZFP_CHANGEINPAYTYPE			1		// change is in selected paytype
#define ZFP_CHANGEINCURRENCY		2       // change is in currency

// general
#define ZFP_STX						0x02	// start transaction
#define ZFP_PING					0x04	// ping!
#define ZFP_BUSY					0x05	// is busy
#define ZFP_OUTOFPAPER				0x07	// No Paper - Romanian ///
#define ZFP_PING2					0x09
#define ZFP_ETX						0x0A	// end transaction
#define ZFP_ACK						0x06    
#define ZFP_NACK					0x15
#define ZFP_RETRY					0x0E
#define ZFP_ANTIECHO				0x03	// prevent working with echo modems

#define ZFP_BASEDATA				0x20    // the ' ' base
#define ZFP_INFINITE				0xFFFFFFFF // infinite timeout
#define ZFP_NOBUSYWAIT				0		// no auto busy wait

// errors
#define ZFPE_SUCCESS				0
#define ZFPE_ERRORBASE				0x100
#define ZFPE_BADINPUTDATA			(ZFPE_ERRORBASE + 1)
#define ZFPE_TIMEOUT				(ZFPE_ERRORBASE + 2)
#define ZFPE_NACKRECEIVED			(ZFPE_ERRORBASE + 3)
#define ZFPE_CRCERROR				(ZFPE_ERRORBASE + 4)
#define ZFPE_BADRECEIPTDATA			(ZFPE_ERRORBASE + 5)
#define ZFPE_BADRESPONSEDATA		(ZFPE_ERRORBASE + 6)
#define ZFPE_RETRIED				(ZFPE_ERRORBASE + 7)
#define ZFPE_BADLOGOFILE			(ZFPE_ERRORBASE + 8)
#define ZFPE_NOFPRINTER				(ZFPE_ERRORBASE + 9)
#define ZFPE_FPRINTERBUSY			(ZFPE_ERRORBASE + 10)
#define ZFPE_NBLNOTSAME				(ZFPE_ERRORBASE + 11)
#define ZFPE_FILEIOERROR			(ZFPE_ERRORBASE + 12)
#define ZFPE_FPBUSYTIMEOUT			(ZFPE_ERRORBASE + 13)
#define ZFPE_INVALIDDEVICE			(ZFPE_ERRORBASE + 14)

// lengths
#define ZFP_PRIVATELEN				0x03    // length of LEN + NBL + CMD
#define ZFP_ENDLEN					0x03    // length of CS + ETX
#define ZFP_FULLPRIVATELEN			0x07    // length of LEN + NBL + CMD + CS + ETX + STX
#define ZFP_MAXDATALEN				(0xFF - ZFP_BASEDATA)
#define ZFP_MAXBUFLEN				0xFF
#define ZFP_MAXHEXBUFLEN			(ZFP_MAXBUFLEN * 6)
#define ZFP_MAXERRORBUFLEN			0x200
#define ZFP_RECEIPTLEN				0x07

// structures
typedef struct {
	double taxGrp1;	// sum accumulated in tax group A
	double taxGrp2;	// sum accumulated in tax group B
	double taxGrp3;	// sum accumulated in tax group C
	double taxGrp4;	// sum accumulated in tax group D
	double taxGrp5;	// sum accumulated in tax group E
	double taxGrp6;	// sum accumulated in tax group F
	double taxGrp7;	// sum accumulated in tax group G
	double taxGrp8;	// sum accumulated in tax group H
} TZfpTaxGroups;

typedef struct {
	WORD fpnum;			// Fiscal Printer place number
	BOOL logo;			// information about logo printing status (0 = not printed, otherwise printed)
	BOOL till;			// till status (0 = don't have a till, otherwise till is present)
	BOOL autocut;		// auto cutter status (0 = don't have one, otherwise present)
	BOOL transparent;	// transparent display status (0 = no display or not transparent, otherwise transparent display)
	BOOL shortEJ;		// Electronic Journal mode (0 = full, 1 = short)
	BOOL currency;		// use currnecy in receipt (0 = no, 1 = yes)
} TZfpParams;

typedef struct {
	DWORD flags;		// receipt's flags
	int purchases;		// the total number of purchases in the receipt
	double change;		// last receipt change sum
	BYTE changeType;	// last receipt change payment type
	TZfpTaxGroups taxGroups; // tax sums
} TZfpReceiptInfo;

typedef struct {
	char type0[12];		// name of payment type 0
	char type1[12];		// name of payment type 1
	char type2[12];		// name of payment type 2
	char type3[12];		// name of payment type 3
	char type4[12];		// name of payment type 4
	double exchRate;		// exchange rate
} TZfpPayTypes;

typedef struct
{
	double price_buy;
	double price_sell;
	double price_central_bank;
	double amount_available;
	double amount_bought;
	double amount_sold;
	double amount_in;
	double amount_out;
} TZfpCurrencyInfo;

#endif
