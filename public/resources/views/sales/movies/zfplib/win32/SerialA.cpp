//////////////////////////////////////////////////////////////////////
// SerialA.cpp: works with serial ports in Win32 API environment
//////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <windows.h>
#include <tchar.h>
#include "SerialA.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

static HANDLE OpenHandle = 0;
static WORD OpenCom = 0;
static BOOL _keep_open = 1;

CSerialA::CSerialA()
{
    DriverHandle = 0;
	fKeepOpen = 0;
	wCurrentCom = 0;
}

CSerialA::CSerialA(WORD wCom, DWORD dwBaudRate, BYTE byByteSize, BYTE byParity,
            BYTE byStopBits, DWORD dwInQueue, DWORD dwOutQueue)
{
    DriverHandle = 0;
	wCurrentCom = 0;
	fKeepOpen = 0;
    SetupAndOpen(wCom, dwBaudRate, byByteSize, byParity,
        byStopBits, dwInQueue, dwOutQueue);
}

CSerialA::~CSerialA()
{
    CloseComPort();
}

BOOL CSerialA::SetupAndOpen(WORD wCom, DWORD dwBaud, BYTE byByteSize, BYTE byParity,
                            BYTE byStopBits, DWORD dwInQueue, DWORD dwOutQueue)
{
	wCurrentCom = (short)wCom;
	if (wCurrentCom < 0)
	{
		wCurrentCom = -wCurrentCom;
		if (fKeepOpen == 0)
			fKeepOpen = 1;
	}
	else
		if (wCurrentCom == OpenCom)
		{
			if (fKeepOpen == 0)
				fKeepOpen = _keep_open;
		}
		else fKeepOpen = 0;
    CloseComPort(); // close the com port if open
    TCHAR szComName[16];

    // Make a COMPORT name from a number
    _stprintf(szComName, _T("\\\\.\\COM%u"), wCurrentCom);

    // Convert the Baud Rate to the Com library define for the DCB
    switch (dwBaud)
	{
        case 110: dwBaudRate = 110; break;
        case 300: dwBaudRate = CBR_300; break;
        case 600: dwBaudRate = CBR_600; break;
        case 1200: dwBaudRate = CBR_1200; break;
        case 2400: dwBaudRate = CBR_2400; break;
        case 4800: dwBaudRate = CBR_4800; break;
        case 9600: dwBaudRate = CBR_9600; break;
        case 19200: dwBaudRate = CBR_19200; break;
        case 38400: dwBaudRate = CBR_38400; break;
        case 57600: dwBaudRate = CBR_57600; break;
        case 115200: dwBaudRate = CBR_115200; break;
        default: return FALSE;
    }

	if (wCurrentCom == OpenCom)
	{
		DriverHandle = OpenHandle;
		return TRUE;
	}
  // Open a channel to the Comport - This example DOES NOT use overlapped I/O
  // Since the benefits of overlapped I/O are few, we suggest not using it.
    DriverHandle = CreateFile(szComName, GENERIC_READ | GENERIC_WRITE,
                               0, NULL, OPEN_EXISTING, 0, NULL);

  // Do we have a valid handle? (If not, the driver probably isn't loaded)
    if (DriverHandle == INVALID_HANDLE_VALUE)
	{
        DriverHandle = 0;
        return (FALSE);
    }
    else
	{
     // The SetupComm() function establishes the Transmit and Receive
     // buffer sizes
        SetupComm(DriverHandle, dwInQueue, dwOutQueue);
        dwInQueueSize = dwInQueue;

     // Obtain the current DCB structure. this can be saved away for restore after
     // the application is done using the Comport
        GetCommState(DriverHandle, &MyDCB);

     // Fill in the DCB structure with our own settings.
        MyDCB.BaudRate = dwBaudRate;
        MyDCB.fParity = 0;
        MyDCB.fOutxCtsFlow = 0;
        MyDCB.fOutxDsrFlow = 0;
        MyDCB.fDtrControl = DTR_CONTROL_DISABLE;
        MyDCB.fDsrSensitivity = FALSE;
        MyDCB.fTXContinueOnXoff = 0;
        MyDCB.fOutX = 0;
        MyDCB.fInX = 0;
        MyDCB.fErrorChar = 0;
        MyDCB.fNull = 0;
        MyDCB.fRtsControl = RTS_CONTROL_DISABLE;
        MyDCB.fAbortOnError = 0;
        MyDCB.ByteSize = byByteSize;
        MyDCB.Parity = byParity;
        MyDCB.StopBits = byStopBits;

     // Configure the comport with our new DCB
        SetCommState(DriverHandle, &MyDCB);

     // Setup a mask that allows us to tell if the port is done transmitting
     // the current buffer of data
        SetCommMask(DriverHandle, EV_TXEMPTY);

		if (fKeepOpen)
		{
			OpenHandle = DriverHandle;
			OpenCom = wCurrentCom;
		}
    }

    Sleep(10);
    ClearInQueue();

    return TRUE;
}

void CSerialA::CloseComPort()
{
	if (fKeepOpen == 0)
	{
		if (DriverHandle && (DriverHandle != INVALID_HANDLE_VALUE))
		    CloseHandle(DriverHandle);

	    DriverHandle = 0;
		if (wCurrentCom == OpenCom)
		{
			OpenCom = 0;
			OpenHandle = NULL;
			_keep_open = 1;
		}
	}
	else
	{
		_keep_open = fKeepOpen;
	}
}

BOOL CSerialA::WriteToComPort(void * lpBuf, DWORD dwBufSize)
{
DWORD /*dwEvtMask,*/ dwBytesWritten;
BOOL bStatus;

    if ((DriverHandle == 0) || (DriverHandle == INVALID_HANDLE_VALUE))
	{
        return FALSE;
    }

    // Some devices may require setting RTS or DTR to specific states prior to
    // transmission of data
    EscapeCommFunction(DriverHandle, SETRTS);

    // Output the data to the Comport
    bStatus = WriteFile(DriverHandle, lpBuf, dwBufSize, &dwBytesWritten, 0);
    if (!bStatus)
	{
//      TRACE("GetLastError(): %d\n",GetLastError());
        return FALSE;
    }

    // If you want, use the WaitCommEvent() function to wait for the
    // data Transmission to complete
    //WaitCommEvent(DriverHandle, &dwEvtMask, NULL);

	FlushFileBuffers(DriverHandle);

    // Some devices may require clearing RTS or DTR to after transmission of data
    EscapeCommFunction(DriverHandle, CLRRTS);

    return TRUE;
}

BOOL CSerialA::SetCommTimeouts(COMMTIMEOUTS * pcto)
{
	return ::SetCommTimeouts(DriverHandle, pcto);
}

BOOL CSerialA::ReadFromComPort(void * lpBuf, DWORD dwBufSize, DWORD * lpdwBytesRead)
{
COMSTAT OurComstat;
DWORD   dwComErrors, dwBytesToRead;

    // By far the most efficient way to input Comport data is the following:
    // ---------------------------------------------------------------------
    // A) See how much data is present
    // B) Read exactly that amount of data
    //
    // Note: It is possible to ask for more data than is present, but the ReadFile()
    //       function call will not return until that amount of data has been received.
    //       Some programs will request more data and establish a timeout using the
    //       SetCommTimeouts() function to return from the ReadFile() function when
    //       not enough data has been receive. Although this may work, it is inefficient
    //       and generally works like crap. For everyone's sake, use the technique above
    //       and handle your own timeout in applications code.
    //

    if ((DriverHandle == 0) || (DriverHandle == INVALID_HANDLE_VALUE)) {
        *lpdwBytesRead = 0;
        return FALSE;
    }


    ZeroMemory(&OurComstat, sizeof(OurComstat));
   // Check the Input buffer
    ClearCommError(DriverHandle, &dwComErrors, &OurComstat);

  // ReadFile() only if there is data.
    if (OurComstat.cbInQue > 0) {
      // Make sure we do not overrun the Buffer
        if (OurComstat.cbInQue > dwBufSize) {
            dwBytesToRead = dwBufSize;
        }
        else {
            dwBytesToRead = OurComstat.cbInQue;
        }
      // Read the data, no (NULL) Overlapped I/O
        if (ReadFile(DriverHandle, lpBuf, dwBytesToRead, lpdwBytesRead, NULL)) {
//            TRACE("Read OK\n");
        }
        else {
//            TRACE("Read FAIL!\n");
            *lpdwBytesRead = 0;
            return FALSE;
        }
    }
    else {
        *lpdwBytesRead = 0;
        return FALSE;
    }

    return TRUE;
}

void CSerialA::ClearInQueue()
{
    if ((DriverHandle == 0) || (DriverHandle == INVALID_HANDLE_VALUE))
        return;

    PurgeComm(DriverHandle, PURGE_TXCLEAR | PURGE_RXCLEAR);
}

void CSerialA::PortsToCombo(HWND combo)
{
    //Make sure we clear out any elements which may already be in the combo
    SendMessage(combo, CB_RESETCONTENT, 0, 0);

    BYTE ports[256];
    if (GetPorts(ports, 256)) {
        TCHAR szPort[10];
        for (int i = 0; i < 256; i++) {
            if (ports[i]) {
                _stprintf(szPort, _T("COM%d"), i);
                int index = SendMessage(combo, CB_ADDSTRING, 0, (LPARAM)szPort);
                SendMessage(combo, CB_SETITEMDATA, (WPARAM)index, (LPARAM)i);
            }
        }
    }
}

int CSerialA::GetPorts(BYTE* portsavail, int size)
{
    memset(portsavail, 0, size);
    int ports = 0;

    //Determine what OS we are running on
    OSVERSIONINFO osvi;
    osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
    BOOL bGetVer = GetVersionEx(&osvi);

    //On NT use the QueryDosDevice API
    if (bGetVer && (osvi.dwPlatformId == VER_PLATFORM_WIN32_NT))  {
        //Use QueryDosDevice to look for all devices of the form COMx. This is a better
        //solution as it means that no ports have to be opened at all.
        TCHAR szDevices[65535];
        DWORD dwChars = QueryDosDevice(NULL, szDevices, 65535);

        if (dwChars) {
            int i = 0;
            for (;;) {
                //Get the current device name
                TCHAR* pszCurrentDevice = &szDevices[i];

                //If it looks like "COMX" then
                //add it to the array which will be returned
                int nLen = _tcslen(pszCurrentDevice);
                if (nLen > 3 && _tcsnicmp(pszCurrentDevice, _T("COM"), 3) == 0)
				{
                    //Work out the port number
                    int nPort = _ttoi(&pszCurrentDevice[3]);
                    ports++;
                    if (size > nPort)
                        portsavail[nPort] = 1;
                }

                // Go to next NULL character
                while(szDevices[i] != _T('\0'))
                    i++;

                // Bump pointer to the next string
                i++;

                // The list is double-NULL terminated, so if the character is
                // now NULL, we're at the end
                if (szDevices[i] == _T('\0'))
                    break;
            }
        }
        //else
        //  TRACE(_T("Failed in call to QueryDosDevice, GetLastError:%d\n"), GetLastError());
    }
    else {
        //On 95/98 open up each port to determine their existence

        //Up to 255 COM ports are supported so we iterate through all of them seeing
        //if we can open them or if we fail to open them, get an access denied error.
        //Both of these cases indicate that there is a COM port at that number.
        for (UINT i = 1; i < 256; i++) {
            //Form the Raw device name
            TCHAR szPort[10];
            _stprintf(szPort, _T("\\\\.\\COM%d"), i);

            //Try to open the port
            BOOL bSuccess = FALSE;
            HANDLE hPort = ::CreateFile(szPort, GENERIC_READ | GENERIC_WRITE, 0, 0, OPEN_EXISTING, 0, 0);
            if (hPort == INVALID_HANDLE_VALUE) {
                DWORD dwError = GetLastError();

                //Check to see if the error was because some other app had the port open
                if (dwError == ERROR_ACCESS_DENIED)
                    bSuccess = TRUE;
            }
            else {
                //The port was opened successfully
                bSuccess = TRUE;

                //Don't forget to close the port, since we are going to do nothing with it anyway
                CloseHandle(hPort);
            }

            //Add the port number to the array which will be returned
            if (bSuccess) {
                ports++;
                if (size > (int)i)
                    portsavail[i] = 1;
            }
        }
    }

    return ports;
}

BOOL CSerialA::IsOpen()
{
    return (DriverHandle != 0);
}
