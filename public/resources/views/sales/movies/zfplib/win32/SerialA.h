 
#ifndef _SERIALA_H_
#define _SERIALA_H_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CSerialA  
{
public:
	CSerialA();
	CSerialA(WORD wCom, DWORD dwBaudRate=9600, BYTE byByteSize=8, BYTE byParity=NOPARITY, BYTE byStopBits=ONESTOPBIT, DWORD dwInQueue=1024, DWORD dwOutQueue=1024);
	virtual ~CSerialA();

	void ClearInQueue();
	BOOL ReadFromComPort(void* lpBuf, DWORD dwBufSize, DWORD* lpdwBytesRead);
	BOOL WriteToComPort(void* lpBuf, DWORD szBufSize);
	void CloseComPort();
	BOOL SetupAndOpen(WORD wCom, DWORD dwBaudRate=9600, BYTE byByteSize=8, BYTE byParity=NOPARITY, BYTE byStopBits=ONESTOPBIT, DWORD dwInQueue=1024, DWORD dwOutQueue=1024);
	BOOL SetCommTimeouts(COMMTIMEOUTS * pcto);
	BOOL IsOpen();
	
	static void PortsToCombo(HWND combo);
	static int GetPorts(BYTE* portsavail, int size);

	BOOL fKeepOpen;

private:
    HANDLE  DriverHandle;
    DWORD   dwBaudRate;
    DCB     MyDCB;
	DWORD   dwInQueueSize;
	short   wCurrentCom;
};

#endif // _SERIALA_H_
