//////////////////////////////////////////////////////////////////////
// Copyright (c) 2005-2008 Tremol Ltd.
// License: Mozilla Public License 1.1
// Contacts: software@tremol.bg
//////////////////////////////////////////////////////////////////////

#include <stdio.h>

#ifdef WIN32
#include <windows.h>
#include <shlwapi.h>
#include "../win32/SerialA.h"
#endif

#ifdef POSIX
#include <string.h>
#include <unistd.h>
#include <sys/times.h>
#include "../posix/SerialA.h"
#endif

#include "../../include/ZekaFPdefs.h"
#include "../../include/ZekaFP.h"
#include "../../include/ZekaFPver.h"

static const char g_szFrmChars[] = "\n\r\t\f\b\x07\x0B\0"; // needed for hex formatting
BYTE CZekaFP::m_lastNBL = 0;
BYTE CZekaFP::m_antiEcho = ZFP_ANTIECHO;
unsigned ZFP_TIMEOUT = 2000, ZFP_PINGTIMEOUT = 200;

//////////////////////////////////////////////////////////////////////
// Tools
//////////////////////////////////////////////////////////////////////
char* nstrcpy(char* dest, const char* src, int len)
{
	if (NULL == dest)
		return NULL;
	if (NULL == src) {
		memset(dest, ' ', len);
	}
	else {
		int srcLen = strlen(src);
		memcpy(dest, src, srcLen > len ? len : srcLen + 1);
	}
	dest[len] = 0;
	return dest;
}

int strreplace(char* str, char fromCh, char toCh)
{
	if (NULL == str)
		return 0;
	int replaced = 0;
	for (int i = 0; str[i] != 0; i++) {
		if (fromCh == str[i]) {
			str[i] = toCh;
			replaced++;
		}
	}
	return replaced;
}

BOOL mystrtrim(char* str, const char* trimChars)
{
	//return StrTrim(str, " \r\n\t"); // WARNING: win32 specific API calls !
	BOOL res = FALSE;
	static const char buf[] = " \r\n\t";
	const char* trim = trimChars ? trimChars : buf;
	int i, len = strlen(str);
	if (!len)
		return FALSE;

	// remove from the beginning
	for (i = 0; i < len; i++) {
		if (NULL == strchr(trim, str[i]))
			break;
	}
	
	if (i) {
		memcpy(str, &str[i], len - i + 1);
		len -= i;
		res = TRUE;
	}

	if (len) {
		for (i = len - 1; i >= 0; i--) {
			if (strchr(trim, str[i])) {
				str[i] = 0;
				res = TRUE;
			}
			else 
				break;
		}
	}

	return res;
}

char* getfloatformat(char* dest, double num, int count)
{
	if (NULL == dest)
		return NULL;
	double max_value;
	if (2 == count) {
		max_value = 9999999.99;
	}
	else {
		max_value = 999999.999;
	}

	char match[20];
	if (max_value < num) {
		strcpy(match, "%.0f"); // no limitations
	}
	else {
		sprintf(match, "%%010.%df", count);
	}
	sprintf(dest, match, num);
	if ('.' == dest[9])
		dest[9] = 0;

	return dest;
}

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CZekaFP::CZekaFP()
{
	Clear();

	m_wCom = 0;
	m_retries = 3;
	m_retryWait = 1000;
	m_zfpType = ZFPT_BG;
	m_autoBusyTimeout = ZFP_NOBUSYWAIT;
	m_pingType = -1;
	m_pingStatus = 0;
}

CZekaFP::CZekaFP(WORD wCom, DWORD baud, WORD retries, DWORD retryWait)
{
	Clear();

	Setup(wCom, baud, retries, retryWait);
	m_zfpType = ZFPT_BG;
	m_autoBusyTimeout = ZFP_NOBUSYWAIT;
}

CZekaFP::~CZekaFP()
{
	m_pingType = -1;
}

void CZekaFP::Setup(WORD wCom, DWORD baud, WORD retries, DWORD retryWait)
{
#ifndef POSIX
	DWORD rs, type = REG_DWORD;

	if (SHGetValue(HKEY_LOCAL_MACHINE, "Software\\Tremol\\ZFPLib", "ReadTimeout", &type, &ZFP_TIMEOUT, &rs) != ERROR_SUCCESS)
#endif
	{
		ZFP_TIMEOUT = 2000;
	}
#ifndef POSIX
	if (SHGetValue(HKEY_LOCAL_MACHINE, "Software\\Tremol\\ZFPLib", "PingTimeout", &type, &ZFP_PINGTIMEOUT, &rs) != ERROR_SUCCESS)
#endif
	{
		ZFP_PINGTIMEOUT = 200;
	}
	m_wCom = wCom;
	m_retries = retries;
	m_retryWait = retryWait;
	m_baudRate = baud;
	m_pingType = -1;
	m_pingStatus = 0;
}

//////////////////////////////////////////////////////////////////////
// Communications
//////////////////////////////////////////////////////////////////////

#ifdef POSIX
void Sleep(unsigned long msec)
{
	usleep( msec * 1000 );
}

DWORD GetTickCount()
{
	static double ms_per_tick = 1000 / sysconf(_SC_CLK_TCK);
	struct tms t;
	DWORD res = (DWORD)(times(&t) * ms_per_tick);
	return res;
}

#endif

int CZekaFP::GetReceipt(CSerialA *serial, DWORD ptr)
{
	// get the data
	DWORD dwPtr = ptr, dwRead = 0;
	DWORD dwTicks = GetTickCount();
	do {
		serial->ReadFromComPort(&m_responseBuf[dwPtr], ZFP_RECEIPTLEN - dwPtr, &dwRead);
		dwPtr += dwRead;
		if ((1 == dwPtr) && (ZFP_NACK == m_responseBuf[0])) {
			m_responseLen = (BYTE)dwPtr;
			return ZFPE_NACKRECEIVED;
		}
		if ((GetTickCount() - dwTicks) > ZFP_TIMEOUT * 120 ) {
			m_responseLen = (BYTE)dwPtr;
			return ZFPE_TIMEOUT;
		}
		Sleep(20);
	}
	while (dwPtr < ZFP_RECEIPTLEN);

	m_responseLen = (BYTE)dwPtr;
	// data check
	if ((ZFP_ACK != m_responseBuf[0]) || (ZFP_ETX != m_responseBuf[ZFP_RECEIPTLEN - 1]))
		return ZFPE_BADRECEIPTDATA;

	BYTE crc1, crc2;
	MakeCRC(&m_responseBuf[1], (BYTE)dwPtr - ZFP_ENDLEN - 1, &crc1, &crc2);
	if ((crc1 != m_responseBuf[ZFP_RECEIPTLEN - ZFP_ENDLEN]) ||
		(crc2 != m_responseBuf[ZFP_RECEIPTLEN - ZFP_ENDLEN + 1]))
		return ZFPE_CRCERROR;

//	if (m_lastNBL != m_responseBuf[2])
//		return ZFPE_NBLNOTSAME;

	BYTE error;
	if (m_responseBuf[ZFP_RECEIPTLEN - ZFP_ENDLEN - 2] < 'A')
		error = (BYTE)m_responseBuf[ZFP_RECEIPTLEN - ZFP_ENDLEN - 2] << 4;
	else
		error = ((BYTE)m_responseBuf[ZFP_RECEIPTLEN - ZFP_ENDLEN - 2] - 'A' + 0x0A) << 4;

	error |= (BYTE)m_responseBuf[ZFP_RECEIPTLEN - ZFP_ENDLEN - 1] & 0x0F;
	if (error)
		return (int)error;

	return ZFPE_SUCCESS;
}

int CZekaFP::GetResponse(CSerialA *serial, BYTE* data, BYTE* len)
{
	// sync by the first byte
READ_AGAIN:

	DWORD dwPtr = 0, dwRead = 0;
	DWORD dwTicks = GetTickCount();
	m_responseBuf[0] = 0;
	do {
		serial->ReadFromComPort(&m_responseBuf[0], 1, &dwRead);
		dwPtr += dwRead;
		if ((GetTickCount() - dwTicks) > ZFP_TIMEOUT) {
			m_responseLen = (BYTE)dwPtr;
			return ZFPE_TIMEOUT;
		}
		Sleep(0);
	}
	while ((ZFP_NACK != m_responseBuf[0]) && (ZFP_STX != m_responseBuf[0]) && 
			(ZFP_ACK != m_responseBuf[0]) && (ZFP_RETRY != m_responseBuf[0]) &&
			(ZFP_ANTIECHO != m_responseBuf[0]));

	if (m_responseBuf[0] == ZFP_NACK && m_curRetry > 0) ///
	{
		// do retry
		Sleep(m_retryWait);
		m_curRetry--;
		serial->WriteToComPort(m_inputBuf, m_inputLen);
		goto READ_AGAIN;
	}

	if (ZFP_NACK == m_responseBuf[0])
		return ZFPE_NACKRECEIVED;

	if (ZFP_ANTIECHO == m_responseBuf[0])
		return ZFPE_INVALIDDEVICE;

	if (ZFP_ACK == m_responseBuf[0])
		return GetReceipt(serial, 1);

	if (ZFP_RETRY == m_responseBuf[0])
	{
		if (0 == m_curRetry)
			return ZFPE_RETRIED;
		
		// do retry
		Sleep(m_retryWait);
		m_curRetry--;
		serial->WriteToComPort(m_inputBuf, m_inputLen);
		goto READ_AGAIN;
	}

	// read the data
	dwPtr = 1;
	dwRead = 0;

	do {
		serial->ReadFromComPort(&m_responseBuf[dwPtr], ZFP_MAXBUFLEN, &dwRead);
		dwPtr += dwRead;
		if ((GetTickCount() - dwTicks) > ZFP_TIMEOUT) {
			m_responseLen = (BYTE)dwPtr;
			return ZFPE_TIMEOUT;
		}
		Sleep(20);
	}
	while (ZFP_ETX != m_responseBuf[dwPtr - 1]);

	m_responseLen = (BYTE)dwPtr;

	if (ZFP_MAXBUFLEN < dwPtr)
		return ZFPE_BADRESPONSEDATA;

	// data check
	BYTE crc1, crc2;
	MakeCRC(&m_responseBuf[1], (BYTE)dwPtr - ZFP_ENDLEN - 1, &crc1, &crc2);
	if ((crc1 != m_responseBuf[dwPtr - ZFP_ENDLEN]) ||
		(crc2 != m_responseBuf[dwPtr - ZFP_ENDLEN + 1]))
		return ZFPE_CRCERROR;

	if (m_lastNBL != m_responseBuf[2])
		return ZFPE_NBLNOTSAME;

	// data get
	if (NULL != data)
		memcpy(data, &m_responseBuf[4], dwPtr - ZFP_FULLPRIVATELEN);
	if (NULL != len)
		*len = (BYTE)(dwPtr - ZFP_FULLPRIVATELEN);

	return ZFPE_SUCCESS;
}

// New PING:
// PC sends single 09 byte
// FP/ECR replies with one byte: 01xxxxxx
// Bit 0 = 1 - device is busy
// Bit 1 = 1 - paper out
// Bit 2 = 1 - printer is overheated
// Bits 3..5 are reserved (0)
// Bits 6 and 7 are always 1,0
int CZekaFP::Ping2( CSerialA *serial, int retries )
{
	serial->ClearInQueue();
	for (int i = 0; i < retries; i++)
	{
		BYTE pong = ZFP_PING2;

		serial->WriteToComPort(&pong, 1);

		DWORD dwRead, dwTicks = GetTickCount();
		do
		{
			pong = 0;
			serial->ReadFromComPort( &pong, 1, &dwRead );
			if ( dwRead == 0 ) Sleep(10);
		}
		while ( ( pong & 0xC0 ) != 0x40 && pong != ZFP_PING2 && (GetTickCount() - dwTicks) < ZFP_PINGTIMEOUT * 3 );

		if (pong == ZFP_PING2)
			return ZFPE_INVALIDDEVICE;

		if ( ( pong & 0xC0 ) == 0x40 )
		{
			m_pingStatus = pong;
			if ( ( pong & 1 ) != 0 )
			{
				if ( i == retries - 1 )
					return ZFPE_FPRINTERBUSY;

				Sleep( ZFP_PINGTIMEOUT );
				continue;
			}

			return ZFPE_SUCCESS;
		}
	}
	return ZFPE_NOFPRINTER;
}

int CZekaFP::DoPing(CSerialA *serial, BYTE ping, int result, int retries)
{
	BYTE p[2];

	p[0] = m_antiEcho;
	p[1] = ping;
	if ( m_pingType == -1 )
		p[0] = ZFP_PING2;

	serial->ClearInQueue();
	for (int i = 0; i < retries; i++)
	{
		serial->WriteToComPort( p, 2 );

		// read pong
		DWORD dwRead, dwTicks = GetTickCount();
		BYTE pong;
		do
		{
			pong = 0;
			serial->ReadFromComPort(&pong, 1, &dwRead);
			if ( dwRead == 0 ) Sleep(10);
			else
			{
				if ( m_pingType == -1 )
				{
					if ( ( pong & 0xC0 ) == 0x40 )
					{
						m_pingType = 1;
						m_pingStatus = pong;
						if ( ping == ZFP_PING && ( pong & 1 ) == 1 ) // online but busy
						{
							Sleep( ZFP_PINGTIMEOUT );
						}
						return ZFPE_SUCCESS;
					}
					else
					{
						m_pingType = 0;
					}
				}
			}
		}
		while ( pong != ping && pong != ZFP_OUTOFPAPER && pong != p[0] && ((GetTickCount() - dwTicks) < ZFP_PINGTIMEOUT) );

		if ( pong == ping || pong == ZFP_OUTOFPAPER )
			return ZFPE_SUCCESS;

		if ( pong == p[0] )
			return ZFPE_INVALIDDEVICE;
	}
	return result;
}

int CZekaFP::CheckForFPrinter(CSerialA *serial, int retries)
{
	if ( m_pingType == 1 )
	{
		m_pingStatus = 0;
		return ZFPE_SUCCESS;
	}
	return DoPing(serial, ZFP_PING, ZFPE_NOFPRINTER, retries);
}

int CZekaFP::CheckForBusy(CSerialA *serial, int retries)
{
	if ( m_pingType == 1 )
	{
		return Ping2( serial, retries );
	}
	return DoPing(serial, ZFP_BUSY, ZFPE_FPRINTERBUSY, retries);
}

int CZekaFP::SendCommand(CSerialA *serial, BYTE cmd, BOOL getReceipt, BYTE* data, BYTE len)
{
	if (CheckForFPrinter(serial))
		return ZFPE_NOFPRINTER;

	if ( ( m_pingType != 1 || m_pingStatus == 0 || ( m_pingStatus & 0xC1 ) == 0x41 ) && CheckForBusy(serial) )
		return ZFPE_FPRINTERBUSY;
	
	Clear();
	serial->ClearInQueue();

	if (ZFP_MAXDATALEN < len)
		return ZFPE_BADINPUTDATA;

	// compose the command
	m_inputBuf[0] = ZFP_STX;				// start marker
	m_inputBuf[1] = (BYTE)(len + ZFP_BASEDATA + ZFP_PRIVATELEN);		// length
	m_lastNBL = (m_lastNBL + 1) % ZFP_MAXDATALEN + ZFP_BASEDATA;
	m_inputBuf[2] = m_lastNBL;
	m_inputBuf[3] = cmd;
	if (data)
		memcpy(&m_inputBuf[4], data, len);
	int csOffs = 4 + len;
	MakeCRC(&m_inputBuf[1], ZFP_PRIVATELEN + len, 
		&m_inputBuf[csOffs], &m_inputBuf[csOffs + 1]);
	m_inputBuf[csOffs + 2] = ZFP_ETX; // add the end marker
	m_inputLen = ZFP_FULLPRIVATELEN + len;

	// send the command
	serial->WriteToComPort(&m_inputBuf, m_inputLen);

	return getReceipt ? GetResponse(serial) : ZFPE_SUCCESS;
}

void CZekaFP::MakeCRC(BYTE* data, BYTE len, BYTE* crc1, BYTE* crc2)
{
	// calculate the CRC
	BYTE crc = 0;
	for (int i = 0; i < len; i++)
		crc ^= data[i];

	// add the CRC
	*crc1 = (crc >> 4) | 0x30;
	*crc2 = (crc & 0x0F) | 0x30;
}

void CZekaFP::Clear()
{
	// buffers
	m_inputLen = m_responseLen = 0;
	memset(&m_inputBuf, 0, ZFP_MAXBUFLEN);
	memset(&m_responseBuf, 0, ZFP_MAXBUFLEN);

	// other
	m_curRetry = m_retries;
}

int CZekaFP::GetInputBuffer(BYTE* buf)
{
	if (ZFP_MAXBUFLEN < m_inputLen)
		return 0;
	memcpy(buf, m_inputBuf, m_inputLen);
	return m_inputLen;
}

int CZekaFP::GetResponseBuffer(BYTE* buf)
{
	if (ZFP_MAXBUFLEN < (int)m_responseLen)
		return 0;
	memcpy(buf, m_responseBuf, m_responseLen);
	return m_responseLen;
}

void CZekaFP::GetBufferHex(const BYTE *pBuf, DWORD dwLen, char* buffer)
{
DWORD dwCounter, dwCnt;
char fh[200];

	buffer[0] = 0;
	for (dwCounter = 0; dwCounter < dwLen / 16; dwCounter++) {
		sprintf(fh, "%08x   %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x   ",
			dwCounter * 16, pBuf[dwCounter * 16], pBuf[dwCounter * 16 + 1],
			pBuf[dwCounter * 16 + 2], pBuf[dwCounter * 16 + 3], pBuf[dwCounter * 16 + 4],
			pBuf[dwCounter * 16 + 5], pBuf[dwCounter * 16 + 6], pBuf[dwCounter * 16 + 7],
			pBuf[dwCounter * 16 + 8], pBuf[dwCounter * 16 + 9], pBuf[dwCounter * 16 + 10],
			pBuf[dwCounter * 16 + 11], pBuf[dwCounter * 16 + 12], pBuf[dwCounter * 16 + 13],
			pBuf[dwCounter * 16 + 14], pBuf[dwCounter * 16 + 15]);

		strcat(buffer, fh);

		for (dwCnt = 0; dwCnt < 16; dwCnt++)
			if (strchr(g_szFrmChars, pBuf[dwCounter * 16 + dwCnt]))
				strcat(buffer, " ");
			else {
				fh[0] = pBuf[dwCounter * 16 + dwCnt];
				fh[1] = 0;
				strcat(buffer, fh);
			}

		strcat(buffer, "\r\n");
	}
	if (dwLen % 16 != 0) {
		sprintf(fh, "%08x   ", dwCounter * 16);
		strcat(buffer, fh);
		for (dwCnt = 0; dwCnt < dwLen % 16; dwCnt++) {
			sprintf(fh, "%02x ", pBuf[dwCounter * 16 + dwCnt]);
			strcat(buffer, fh);
		}
		strcat(buffer, "  ");
		for (;dwCnt < 16; dwCnt++) 
			strcat(buffer, "   ");

		for (dwCnt = 0; dwCnt < dwLen % 16; dwCnt++) {
			if (strchr(g_szFrmChars, pBuf[dwCounter * 16 + dwCnt])) 
				strcat(buffer, " ");
			else {
				fh[0] = pBuf[dwCounter * 16 + dwCnt];
				fh[1] = 0;
				strcat(buffer, fh);
			}
		}
		strcat(buffer, "\r\n");
	}
}

void CZekaFP::GetInputHexFormated(char* buf)
{
	GetBufferHex(m_inputBuf, m_inputLen, buf);
}

void CZekaFP::GetResponseHexFormated(char* buf)
{
	GetBufferHex(m_responseBuf, m_responseLen, buf);
}

// For compatibility with earlier versions of the library. Use FindFirstFPCOMEx()
DWORD CZekaFP::FindFirstFPCOM()
{
	BYTE ports[256];
	if (CSerialA::GetPorts(ports, 256))
	{
		int i;
		// check at baud rate 9600
		for (i = 0; i < 256; i++)
		{
			if (ports[i])
			{
				CSerialA serial(i, ZBR_9600);
				CZekaFP zt;

				if ( serial.IsOpen() && zt.CheckForFPrinter(&serial, 2) == ZFPE_SUCCESS )
					return (i | (ZBR_9600 << 16));
			}
		}

		// check at baud rate 19200
		for (i = 0; i < 256; i++)
		{
			if (ports[i])
			{
				CZekaFP zt;
				CSerialA serial(i, ZBR_19200);
				if ((serial.IsOpen()) && (ZFPE_SUCCESS == zt.CheckForFPrinter(&serial, 2)))
					return (i | (ZBR_19200 << 16));
			}
		}
	}
	return 0;
}

// return value: 32-bits - PPPPPPPP.ssssssss.ssssssss.ssssssss - P - port#, S - port speed
DWORD CZekaFP::FindFirstFPCOMEx()
{
	DWORD ab[] = { ZBR_9600, ZBR_19200, ZBR_38400, ZBR_57600, ZBR_115200 };
	BYTE ports[256];

	if (CSerialA::GetPorts(ports, 256))
	{
		for (int i = 0; i < 256; i++)
		{
			
			for (int s = sizeof ab / sizeof *ab - 1; s >= 0; s--)
			{
				if (ports[i])
				{
					CZekaFP zt;
					CSerialA serial(i, ab[s]);
					if ((serial.IsOpen()) && (ZFPE_SUCCESS == zt.CheckForFPrinter(&serial, 2)))
						return ab[s] | ((DWORD)i << 24);
				}
			}
		}
	}
	return 0;
}

DWORD CZekaFP::FindBaudByCOM(WORD wCom)
{
	DWORD ab[] = { ZBR_9600, ZBR_19200, ZBR_38400, ZBR_57600, ZBR_115200 };

	for (int i = sizeof ab / sizeof *ab - 1; i >= 0; i--)
	{
		CZekaFP zt;
		CSerialA serial(wCom, ab[i]);
		if ((serial.IsOpen()) && (ZFPE_SUCCESS == zt.CheckForFPrinter(&serial, 2)))
			return ab[i];
	}
	return 0;
}

WORD CZekaFP::FindFirstFPCOMbyBaud(DWORD baud)
{
	BYTE ports[256];
	if (CSerialA::GetPorts(ports, 256))
	{
		int i;

		for (i = 0; i < 256; i++)
		{
			if (ports[i]) 
			{
				CZekaFP zt;
				CSerialA serial(i, baud);
				if ((serial.IsOpen()) && (ZFPE_SUCCESS == zt.CheckForFPrinter(&serial, 2)))
					return i;
			}
		}
	}
	return 0;
}

int CZekaFP::SetZFPType(int type)
{
	if ((ZFPT_BG != type) && (ZFPT_RO != type))
		return ZFPE_BADINPUTDATA;
	m_zfpType = type;
	return ZFPE_SUCCESS;
}

int CZekaFP::GetZFPType()
{
	return m_zfpType;
}

WORD CZekaFP::GetCOM()
{
	return m_wCom;
}

DWORD CZekaFP::GetBaudRate()
{
	return m_baudRate;
}

int CZekaFP::BusyWait(DWORD timeout)
{
	Sleep(50);
	CSerialA serial(m_wCom, m_baudRate);
	return DoBusyWait(&serial, timeout);
}

void CZekaFP::SetAutoBusyWait(DWORD timeout)
{
	m_autoBusyTimeout = timeout;
}

int CZekaFP::DoBusyWait(CSerialA *serial, DWORD timeout)
{
	DWORD ticks = GetTickCount();
	while (1)
	{
		if (CheckForFPrinter(serial))
			return ZFPE_NOFPRINTER;
		if (!CheckForBusy(serial))
			return ZFPE_SUCCESS;
		Sleep(ZFP_PINGTIMEOUT);
		serial->ClearInQueue();
		if ((timeout != ZFP_INFINITE) && (GetTickCount() - ticks > timeout))
			return ZFPE_FPBUSYTIMEOUT;
	}
}

int CZekaFP::SendCommandDirect(const char* cmd, char* data, BYTE* len)
{
	if (!cmd || (!strlen(cmd)))
		return ZFPE_BADINPUTDATA;
	CSerialA serial(m_wCom, m_baudRate);
	int res = SendCommand(&serial, cmd[0], FALSE, (BYTE *)&cmd[1], (BYTE)strlen(&cmd[1]));
	if (ZFPE_SUCCESS == res) {
		res = GetResponse(&serial, (BYTE *)data, len);
	}
	return res;
}

int CZekaFP::GetLibraryVersion()
{
	return MAKELONG(MAKEWORD(VER_BUILD, VER_MINOR), VER_MAJOR);
}
