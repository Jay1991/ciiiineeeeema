//////////////////////////////////////////////////////////////////////
// Copyright (c) 2005-2006 Tremol Ltd.
// License: Mozilla Public License 1.1
// Contacts: software@tremol.bg
//////////////////////////////////////////////////////////////////////
// ZekaFP_error.cpp: implementation of the CZekaFP error routines
//
//////////////////////////////////////////////////////////////////////

#include <stdio.h>

#ifdef WIN32
#include <windows.h>
#endif

#ifdef POSIX
#include <string.h>
#endif

#include "../../include/ZekaFP.h"
#include "../../include/ZekaFPdefs.h"

// WARNING: localization specific code

void CZekaFP::GetErrorString(int error, int lang, char* buf)
{
	switch (lang) {
	case ZFP_LANG_BG: 
		GetErrorStringBG(error, buf);
		break;
	default: 
		GetErrorStringEN(error, buf);
		break;
	}
}

void CZekaFP::GetErrorStringBG(int error, char* buf)
{
	sprintf(buf, "%d (%04x hex) ", error, error);
	if (ZFPE_SUCCESS == error) {
		strcat(buf, "операцията завърши успешно!");
	}
	else if (ZFPE_ERRORBASE < error) {
		switch (error) {
		case ZFPE_BADINPUTDATA:
			strcat(buf, "некоректни входни данни!");
			break;

		case ZFPE_TIMEOUT:
			strcat(buf, "просрочено време за отговор от фискалния принтер!");
			break;

		case ZFPE_NACKRECEIVED:
			strcat(buf, "отрицателен (NACK) отговор от фискалния принтер!");
			break;

		case ZFPE_CRCERROR:
			strcat(buf, "грешна контролна сума!");
			break;

		case ZFPE_BADRECEIPTDATA:
			strcat(buf, "получен е грешен отговор от фискалния принтер / грешка при комуникация!");
			break;

		case ZFPE_BADRESPONSEDATA:
			strcat(buf, "получени са грешни данни от фискалния принтер / грешка при комуникация!");
			break;

		case ZFPE_RETRIED:
			strcat(buf, "фискалния принтер не може да изпълни операцията / опитайте по-късно!");
			break;

		case ZFPE_BADLOGOFILE:
			strcat(buf, "невалиден файл за лого!");
			break;

		case ZFPE_NOFPRINTER:
			strcat(buf, "фискалния принтер не може да бъде открит!");
			break;

		case ZFPE_FPRINTERBUSY:
			strcat(buf, "фискалния принтер е зает / опитайте по-късно!");
			break;

		case ZFPE_NBLNOTSAME:
			strcat(buf, "различен номер на блок на данните / грешка при комуникация!");
			break;

		case ZFPE_FILEIOERROR:
			strcat(buf, "входно / изходна грешка!");
			break;

		case ZFPE_FPBUSYTIMEOUT:
			strcat(buf, "фискалния принтер е зает (просрочено време за отговор)!");
			break;

		case ZFPE_INVALIDDEVICE:
			strcat(buf, "непознато устройство!");
			break;

		default:
			strcat(buf, "непозната грешка!");
			break;
		} // switch
	}
	else {
		int err = error >> 4;
		switch (err) {
		case 0:
			strcat(buf, "Ф.П.: ОК");
			break;

		case 1:
			strcat(buf, "Ф.П.: няма хартия");
			break;

		case 2:
			strcat(buf, "Ф.П.: препълване в общите регистри");
			break;

		case 3:
			strcat(buf, "Ф.П.: несверен / грешен часовник");
			break;

		case 4:
			strcat(buf, "Ф.П.: отворен фискален бон");
			break;

		case 5:
			strcat(buf, "Ф.П.: сметка с остатък за плащане (отворен бон)");
			break;

		case 6:
			strcat(buf, "Ф.П.: отворен нефискален бон");
			break;

		case 7:
			strcat(buf, "Ф.П.: сметка с приключено плащане (отворен бон)");
			break;

		case 8:
			strcat(buf, "Ф.П.: фискална памет само за четене");
			break;

		case 9:
			strcat(buf, "Ф.П.: грешна парола или непозволена команда");
			break;

		case 0x0A:
			strcat(buf, "Ф.П.: липсващ външен дисплей");
			break;

		case 0x0B:
			strcat(buf, "Ф.П.: 24 часа без дневен отчет (блокировка)");
			break;

		case 0x0C:
			strcat(buf, "Ф.П.: прегрят принтер");
			break;

		case 0x0D:
			strcat(buf, "Ф.П.: спад на напрежение във фискален бон");
			break;

		case 0x0E:
			strcat(buf, "Ф.П.: препълване в електронната контролна лента");
			break;

		case 0x0F:
			strcat(buf, "Ф.П.: недостатъчни условия");
			break;

		default:
			strcat(buf, "Ф.П.: непозната грешка");
			break;
		} // switch

		strcat(buf, " / ");
		err = error & 0x0F;
		switch (err) {
		case 0:
			strcat(buf, "команда: ОК!");
			break;

		case 1:
			strcat(buf, "команда: невалидна!");
			break;

		case 2:
			strcat(buf, "команда: непозволена!");
			break;

		case 3:
			strcat(buf, "команда: непозволена поради ненулев отчет!");
			break;

		case 4:
			strcat(buf, "команда: синтактична грешка!");
			break;

		case 5:
			strcat(buf, "команда: синтактична грешка / препълване на входните регистри!");
			break;

		case 6:
			strcat(buf, "команда: синтактична грешка / нулев входен регистър!");
			break;

		case 7:
			strcat(buf, "команда: липсва транзакция която да се войдира!");
			break;

		case 8:
			strcat(buf, "команда: недостатъчна налична сума!");
			break;

		case 9:
			strcat(buf, "команда: конфликт в данъчните групи!");
			break;

		default:
			strcat(buf, "команда: непозната грешка!");
			break;
		} // switch
	} // else
}

void CZekaFP::GetErrorStringEN(int error, char* buf)
{
	sprintf(buf, "%d (%04x hex) ", error, error);
	if (ZFPE_SUCCESS == error) {
		strcat(buf, "operation completed successfully!");
	}
	else if (ZFPE_ERRORBASE < error) {
		switch (error) {
		case ZFPE_BADINPUTDATA:
			strcat(buf, "incorrect input data!");
			break;

		case ZFPE_TIMEOUT:
			strcat(buf, "timeout while waiting for fiscal printer response!");
			break;

		case ZFPE_NACKRECEIVED:
			strcat(buf, "fiscal printer returned negative (NACK) response!");
			break;

		case ZFPE_CRCERROR:
			strcat(buf, "CRC error!");
			break;

		case ZFPE_BADRECEIPTDATA:
			strcat(buf, "bad fiscal printer response / communication error!");
			break;

		case ZFPE_BADRESPONSEDATA:
			strcat(buf, "bad fiscal printer response data / communication error!");
			break;

		case ZFPE_RETRIED:
			strcat(buf, "fiscal printer cannot complete the operation / try again later!");
			break;

		case ZFPE_BADLOGOFILE:
			strcat(buf, "invalid logo file!");
			break;

		case ZFPE_NOFPRINTER:
			strcat(buf, "fiscal printer device cannot be found!");
			break;

		case ZFPE_FPRINTERBUSY:
			strcat(buf, "fiscal printer is busy / try again later!");
			break;

		case ZFPE_NBLNOTSAME:
			strcat(buf, "bad data block number / communication error!");
			break;

		case ZFPE_FILEIOERROR:
			strcat(buf, "file I/O error!");
			break;

		case ZFPE_FPBUSYTIMEOUT:
			strcat(buf, "fiscal printer is busy (timeout while waiting)!");
			break;

		case ZFPE_INVALIDDEVICE:
			strcat(buf, "invalid device found!");
			break;

		default:
			strcat(buf, "unknown error!");
			break;
		} // switch
	}
	else {
		int err = error >> 4;
		switch (err) {
		case 0:
			strcat(buf, "F.P.: OK");
			break;

		case 1:
			strcat(buf, "F.P.: paper out");
			break;

		case 2:
			strcat(buf, "F.P.: daily registers overflow");
			break;

		case 3:
			strcat(buf, "F.P.: not adjusted/wrong clock");
			break;

		case 4:
			strcat(buf, "F.P.: opened fiscal receipt");
			break;

		case 5:
			strcat(buf, "F.P.: account with remainder to be paid (opened receipt)");
			break;

		case 6:
			strcat(buf, "F.P.: opened non fiscal receipt");
			break;

		case 7:
			strcat(buf, "F.P.: account payment finished (opened receipt)");
			break;

		case 8:
			strcat(buf, "F.P.: fiscal memory is read-only");
			break;

		case 9:
			strcat(buf, "F.P.: bad password or command not allowed");
			break;

		case 0x0A:
			strcat(buf, "F.P.: missing display");
			break;

		case 0x0B:
			strcat(buf, "F.P.: 24 hours without daily report blocked");
			break;

		case 0x0C:
			strcat(buf, "F.P.: printer overheat");
			break;

		case 0x0D:
			strcat(buf, "F.P.: power down");
			break;

		case 0x0E:
			strcat(buf, "F.P.: electronic journal overflow");
			break;

		case 0x0F:
			strcat(buf, "F.P.: not enough conditions met");
			break;

		default:
			strcat(buf, "F.P.: unknown error");
			break;
		} // switch

		strcat(buf, " / ");
		err = error & 0x0F;
		switch (err) {
		case 0:
			strcat(buf, "command: OK!");
			break;

		case 1:
			strcat(buf, "command: invalid!");
			break;

		case 2:
			strcat(buf, "command: illegal!");
			break;

		case 3:
			strcat(buf, "command: denied because of uncommited report!");
			break;

		case 4:
			strcat(buf, "command: syntax error!");
			break;

		case 5:
			strcat(buf, "command: syntax error / input register overflow!");
			break;

		case 6:
			strcat(buf, "command: syntax error / input register is zero!");
			break;

		case 7:
			strcat(buf, "command: missing transaction for void!");
			break;

		case 8:
			strcat(buf, "command: insufficient subtotal!");
			break;

		case 9:
			strcat(buf, "command: tax groups conflict!");
			break;

		default:
			strcat(buf, "command: unknown error!");
			break;
		} // switch
	} // else
}
