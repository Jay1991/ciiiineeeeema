
#ifndef _SERIALA_H_
#define _SERIALA_H_

#ifdef POSIX
typedef int                 BOOL;
typedef unsigned char       BYTE;
typedef unsigned short      WORD;
//typedef unsigned int        DWORD;
#define DWORD               unsigned int
#endif

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#include <termios.h> /* POSIX terminal control definitions */

class CSerialA
{
public:
    CSerialA();
    CSerialA(WORD wCom, DWORD dwBaudRate=9600);
    virtual ~CSerialA();

    void ClearInQueue();
    BOOL ReadFromComPort(void* lpBuf, size_t dwBufSize, DWORD* lpdwBytesRead);
    BOOL WriteToComPort(void* lpBuf, size_t szBufSize);
    void CloseComPort();
    BOOL SetupAndOpen(WORD wCom, DWORD dwBaudRate=9600);
    BOOL IsOpen();

    static int GetPorts(BYTE* portsavail, int size);

private:
    int     DriverHandle;
    struct termios termios_save;
};

#endif // _SERIALA_H_
