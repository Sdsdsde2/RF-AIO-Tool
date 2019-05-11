#include <Windows.h>
#include "MyForm.h"
#pragma unmanaged

extern void ShowForm(void);
::BOOL WINAPI DllWork(__in::HMODULE hModule)
{
	ShowForm();
	return true;// done pretty eeasy
}

extern HINSTANCE hAppInstance;

HINSTANCE HThisModule;

::BOOL WINAPI DllMain(__in::HMODULE hModule, __in::DWORD dwReason, __in __reserved::LPVOID lpvReserved)
{
	::HANDLE hThread = NULL;

		if (dwReason == DLL_PROCESS_ATTACH)
		{
			if ((hThread = ::CreateThread(NULL, 0, (::LPTHREAD_START_ROUTINE)&DllWork, (::HMODULE)hModule, 0, NULL)) == NULL)
			{
				return FALSE;
			}
			if (::CloseHandle(hThread) == FALSE)
			{
			}
		}
	return TRUE;
}