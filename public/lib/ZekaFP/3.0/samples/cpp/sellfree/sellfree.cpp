//////////////////////////////////////////////////////////////////////
// Copyright (c) 2005,2008 Tremol Ltd.
// License: Mozilla Public License 1.1
// Contacts: software@tremol.bg
//////////////////////////////////////////////////////////////////////
// This is a sample program for zfplib C++ library (Zeka FP)
//////////////////////////////////////////////////////////////////////

#include <stdio.h>

#ifdef WIN32
#include <windows.h>
#endif

#ifdef POSIX
#include <string.h>
#endif

#include "../../../include/ZekaFP.h"

BOOL ShowError(int error)
{
	if (ZFPE_SUCCESS != error)
	{
		char errorStr[ZFP_MAXERRORBUFLEN];
		CZekaFP::GetErrorString(error, ZFP_LANG_EN, errorStr);
		printf("%s\nPress <Enter> to quit", errorStr);
		return TRUE;
	}
	return FALSE;
}

int main(int argc, char* argv[])
{
	// Find the first available fiscal printer
	// In your programs you should ask users instead of this auto searching!
	printf("Searching for the first available Zeka Fiscal Printer ...\n");
	DWORD com = CZekaFP::FindFirstFPCOMEx();
	WORD wCom = (WORD)(com >> 24);
	DWORD baud = com & 0x00FFFFFFL;

	if (com)
	{
		printf("Found Zeka Fiscal Printer at COM%u, baud rate: %u\n", wCom, baud);
	}
	else
	{
		printf("Cannot find Zeka Fiscal Printer attached to any COM port\nPress <Enter> to quit");
		getchar();
		return 1;
	}

	int err;

	// declare the main class
	CZekaFP zfp(wCom, baud);

	// show some text
	err = zfp.PrintText("Hello Zeka Fiscal Printer");
	if (ShowError(err))
	{
		getchar();
		return 2;
	}

	err = zfp.PrintText("Това е текст на кирилица. Този текст е много дълаг затова ще бъде автоматично отрязан");
	if (ShowError(err))
	{
		getchar();
		return 3;
	}
	// open a fiscal bon
	err = zfp.OpenFiscalBon(1, "0000", 0, 0);
	if (ShowError(err))
	{
		getchar();
		return 4;
	}

	// do some sells
	// also demonstrates addition and discounting
	// demonstrates different types of using tax groups too
	ShowError( zfp.SellFree("Test Article", 'Б', 1.23f) );
	ShowError( zfp.SellFree("Артикул на кирилица", 0, 0.54f, 10.372f) );
	ShowError( zfp.PrintText("Free text inside the receipt"));
	ShowError( zfp.SellFree("Артикул с отстъпка", '2', 0.97f, 2.0f, -2.5f) );

	// calculate the sum so far
	double sum;
	ShowError( zfp.CalcIntermediateSum(&sum) );

	// do the payment
	// for this example we will pay it in two passes
	ShowError( zfp.Payment(sum / 2, 0) );
	ShowError( zfp.Payment(sum / 2 + 4.76f, 1) ); // 4.76f is a sample value, we need some remainer

	ShowError( zfp.PrintText("Have a nice day!", ZFP_TEXTALIGNCENTER) );

	// close the bon
	err = zfp.CloseFiscalBon();
	if (ShowError(err)) 
	{
		getchar();
		return 5;
	}

	printf("Operation completed successfully\nPress <Enter> to quit");
	getchar();

	return 0;
}

