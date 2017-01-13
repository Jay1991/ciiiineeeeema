//////////////////////////////////////////////////////////////////////
// SerialA.cpp: works with serial ports in POSIX environment
//
// Notes: This is only a port of the Windows class.
// Serial manipulations in POSIX are quite different.
// A better implementation would be to use select() or
// other system call, but since serial implementation
// for the older Windows versions made problems with
// Windows handling timeouts, the timeout code is in
// the library
//////////////////////////////////////////////////////////////////////

#include <stdio.h> /* Standard input/output definitions */
#include <string.h> /* String function definitions */
#include <unistd.h> /* UNIX standard function definitions */
#include <fcntl.h> /* File control definitions */
#include <errno.h> /* Error number definitions */
//#include <unistd.h>
#include "SerialA.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSerialA::CSerialA()
{
    DriverHandle = -1;
}

CSerialA::CSerialA(WORD wCom, DWORD dwBaudRate)
{
    DriverHandle = -1;
    SetupAndOpen(wCom, dwBaudRate);
}

CSerialA::~CSerialA()
{
    CloseComPort();
}

BOOL CSerialA::SetupAndOpen(WORD wCom, DWORD dwBaud)
{
    CloseComPort(); // close the com port if open
    char szComName[20];

    // Make a COMPORT name from a number
    sprintf(szComName, "/dev/ttyS%u", wCom - 1);

    DriverHandle = open(szComName, O_RDWR | O_NOCTTY | O_NDELAY);

    // Do we have a valid handle? (If not, the driver probably isn't loaded)
    if (-1 == DriverHandle) {
        return FALSE;
    }

    // return immediately if no data available (no blocking)
    fcntl(DriverHandle, F_SETFL, FNDELAY);

    // Setting the baud rate.
    struct termios options;

    // Get the current options for the port...
    tcgetattr(DriverHandle, &options);
    memcpy(&termios_save, &options, sizeof(struct termios));

    // Set the baud rate
    speed_t baud;

    switch (dwBaud) {
        case 1200: baud = B1200; break;
        case 2400: baud = B2400; break;
        case 4800: baud = B4800; break;
        case 9600: baud = B9600; break;
        case 19200: baud = B19200; break;
        case 38400: baud = B38400; break;
        case 57600: baud = B57600; break;
        case 115200: baud = B115200; break;
        default: return FALSE;
    }

    cfsetispeed(&options, baud);
    cfsetospeed(&options, baud);

    // Enable the receiver and set local mode...
    options.c_cflag = CLOCAL | CREAD | IGNPAR | IGNBRK | CS8/* | HUPCL */| baud;

    options.c_oflag = 0;
    options.c_lflag = 0;

    // Set the new options for the port...
    tcsetattr(DriverHandle, TCSANOW, &options);

    tcflush(DriverHandle, TCOFLUSH);
    tcflush(DriverHandle, TCIFLUSH);

    return TRUE;
}

void CSerialA::CloseComPort()
{
    if (DriverHandle && (-1 != DriverHandle))
    {
        tcsetattr(DriverHandle, TCSANOW, &termios_save);
        tcflush(DriverHandle, TCOFLUSH);
        tcflush(DriverHandle, TCIFLUSH);
        close(DriverHandle);
    }
    DriverHandle = -1;
}

BOOL CSerialA::WriteToComPort(void * lpBuf, size_t dwBufSize)
{
size_t dwBytesWritten;

    if (-1 == DriverHandle) {
        return FALSE;
    }

    // Output the data to the Comport
    dwBytesWritten = write(DriverHandle, lpBuf, dwBufSize);
    if (dwBytesWritten != dwBufSize) {
        return FALSE;
    }

    return TRUE;
}

BOOL CSerialA::ReadFromComPort(void * lpBuf, size_t dwBufSize, DWORD* lpdwBytesRead)
{
    if (-1 == DriverHandle) {
        *lpdwBytesRead = 0;
        return FALSE;
    }

    ssize_t rd = read(DriverHandle, lpBuf, dwBufSize);
    *lpdwBytesRead = (DWORD)rd;
    if (0 >= rd) {
        *lpdwBytesRead = 0;
        return FALSE;
    }

    return TRUE;
}

void CSerialA::ClearInQueue()
{
    tcflush(DriverHandle, TCIFLUSH);
}

int CSerialA::GetPorts(BYTE* portsavail, int size)
{
    memset(portsavail, 0, size);
    int fd, ports = 0;
    int last = 255 >= size ? size : 255;
    char szComName[20];

    for (int i = 1; i <= last; i++) {
        // Make a COMPORT name from a number
        sprintf(szComName, "/dev/ttyS%u", i);
        fd = open(szComName, O_RDWR | O_NOCTTY | O_NDELAY);
        if (-1 != fd) {
            portsavail[i] = 1;
            ports++;
            close(fd);
        }
    }

    return ports;
}

BOOL CSerialA::IsOpen()
{
    return (0 < DriverHandle) ? TRUE : FALSE;
}
