#include "Memory.h"
#pragma unmanaged

//DEFAULT_CONSTRUCTOR
Memory::Memory() {

};

//DESTRUCTOR
Memory::~Memory() {

};

//FUNCTIONAL
int _stdcall Memory::WriteMemory(void* pvAddress, void* pvWriteBuffer, size_t Size) {
	DWORD dwAddress, dwOldProtectionFlags, dwSize;

	int iReturnCode;

	iReturnCode = 0;

	dwAddress = ROUND_DOWN(pvAddress, 0x1000); // assume 4096 bytes of granularity for pages, otherwise use void* and GetSystemInfo to get page size for x64
	dwSize = ROUND_UP(Size, 0x1000);

	if (VirtualProtect((LPVOID)dwAddress, dwSize, PAGE_EXECUTE_READWRITE, &dwOldProtectionFlags))
	{
		memcpy(pvAddress, pvWriteBuffer, Size);

		if (VirtualProtect((LPVOID)dwAddress, dwSize, dwOldProtectionFlags, &dwOldProtectionFlags))
		{
			if (FlushInstructionCache(GetCurrentProcess(), (LPCVOID)dwAddress, dwSize))
			{
				iReturnCode = 0;
			}
			else
			{
				iReturnCode = GetLastError();
			}
		}
		else
		{
			iReturnCode = GetLastError();
		}
	}
	else
	{
		iReturnCode = GetLastError();
	}

	return iReturnCode;
};

ULONG_PTR Memory::ReadPtr(DWORD dwBase, INT iOffset) {
	ULONG_PTR* ulBase = (ULONG_PTR *)dwBase;
	if (!IsBadReadPtr((VOID*)ulBase, sizeof(ULONG_PTR)))
		if (!IsBadReadPtr((VOID*)((*(ULONG_PTR*)ulBase) + iOffset), sizeof(ULONG_PTR)))
			return *(ULONG_PTR*)((*(ULONG_PTR*)ulBase) + iOffset);
	return 0;
};

std::string Memory::ReadStr(DWORD dwBase, INT iOffset) {
	ULONG_PTR* ulBase = (ULONG_PTR *)dwBase;
	if (!IsBadReadPtr((VOID*)ulBase, sizeof(ULONG_PTR)))
		if (!IsBadReadPtr((VOID*)((*(ULONG_PTR*)ulBase) + iOffset), sizeof(ULONG_PTR)))
			return *(std::string*)((*(int*)ulBase) + iOffset);
	return 0;
};

BOOL Memory::WritePtr(unsigned long ulBase, INT iOffset, int iValue)
{
	__try { *(int*)(*(unsigned long*)ulBase + iOffset) = iValue; return TRUE; }
	__except (EXCEPTION_EXECUTE_HANDLER) { }

	return FALSE;
};

BOOL Memory::WriteStr(unsigned long ulBase, INT iOffset, std::string sValue)
{
	try { *(std::string*)(*(unsigned long*)ulBase + iOffset) = sValue; return TRUE; }
	catch (...) {}

	return FALSE;
};