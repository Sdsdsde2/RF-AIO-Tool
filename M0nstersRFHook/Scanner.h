#pragma once
#include <Windows.h>

class Scanner {

private:

	VOID CodeSectionInfo(IMAGE_DOS_HEADER* THIS_IMAGE_DOS_HEADER, DWORD* outCodeSectionStart, DWORD* outCodeSectionSize)
	{
		IMAGE_NT_HEADERS* e_lfanewPtr = (IMAGE_NT_HEADERS*)((DWORD)THIS_IMAGE_DOS_HEADER + THIS_IMAGE_DOS_HEADER->e_lfanew);
		*outCodeSectionStart = (DWORD)THIS_IMAGE_DOS_HEADER + e_lfanewPtr->OptionalHeader.BaseOfCode;
		*outCodeSectionSize = e_lfanewPtr->OptionalHeader.SizeOfCode;
	}

	BOOL CHECK(const BYTE* pData, const BYTE* bMask, const char* szMask)
	{
		for (; *szMask; ++szMask, ++pData, ++bMask)
			if (*szMask != '?' && *pData != *bMask)
				return false;

		return (*szMask) == NULL;
	}

public:

	DWORD findPattern(DWORD dwBegin, DWORD dwEnd, BYTE *bMask, char* szMask, BOOL dwSpecial = FALSE, INT iResult = 0)
	{
		DWORD dwAddress, dwLen;
		INT curResult = 0;
		if (!dwSpecial) {

			dwAddress = dwBegin;
			dwLen = dwEnd;
		}
		else
			CodeSectionInfo((IMAGE_DOS_HEADER*)GetModuleHandleA(NULL), &dwAddress, &dwLen);

		for (DWORD i = 0; i < dwLen; i++) {
			_try{


				if (CHECK((BYTE*)(dwAddress + i), bMask, szMask)) {
					if (iResult != 0) {
						if (curResult != iResult)
							curResult++;
						else
							return (DWORD)(dwAddress + i);
					}
					else
						return (DWORD)(dwAddress + i);
				}
			}
				__except (EXCEPTION_EXECUTE_HANDLER)
			{

			}
		}

		return dwBegin;
	}

	DWORD search(DWORD dwBegin, DWORD dwEnd, BYTE *bMask, char* szMask, INT iResult = 0) {

	Initialize:

		DWORD dwAddress, dwLen;
		dwAddress = dwBegin; dwLen = dwEnd;
		MEMORY_BASIC_INFORMATION meminfo;
		INT curResult = 0;
	Loop:
		if (dwLen > dwAddress) {
			_try{
				if (!VirtualQuery((LPVOID)dwAddress, &meminfo, sizeof(meminfo))) return 0;
				if (!(meminfo.Protect &(PAGE_READWRITE | PAGE_WRITECOPY | PAGE_EXECUTE_READWRITE | PAGE_EXECUTE_WRITECOPY | PAGE_EXECUTE_READ)) || !(meminfo.State &MEM_COMMIT)) {

					dwAddress += meminfo.RegionSize;
					goto Loop;
				}
				if (CHECK((BYTE*)(dwAddress), bMask, szMask)) {
					if (iResult != 0) {
						if (curResult != iResult) {
							curResult += 1;
							goto Increment;
						}
						else
							goto Complete;
					}
					else
						goto Complete;
				}
			} _except(EXCEPTION_EXECUTE_HANDLER) {

				dwAddress++;
				goto Loop;
			}
		}
		else
			return 0;

	Increment:

		dwAddress++;
		goto Loop;

	Complete:

		return (dwAddress);
	}

	DWORD findBase(DWORD dwAddy) {

		if (dwAddy >= 0x01000000 && dwAddy < 0x02000000)
			return 0x01000000;
		if (dwAddy >= 0x02000000 && dwAddy < 0x03000000)
			return 0x02000000;
		if (dwAddy >= 0x03000000 && dwAddy < 0x04000000)
			return 0x03000000;
		if (dwAddy >= 0x04000000 && dwAddy < 0x05000000)
			return 0x04000000;
		if (dwAddy >= 0x05000000 && dwAddy < 0x06000000)
			return 0x05000000;
		if (dwAddy >= 0x06000000 && dwAddy < 0x07000000)
			return 0x06000000;
		if (dwAddy >= 0x07000000 && dwAddy < 0x08000000)
			return 0x07000000;
		if (dwAddy >= 0x08000000 && dwAddy < 0x09000000)
			return 0x08000000;
		if (dwAddy >= 0x09000000 && dwAddy < 0x0A000000)
			return 0x09000000;
		if (dwAddy >= 0x0A000000 && dwAddy < 0x0B000000)
			return 0x0A000000;
		if (dwAddy >= 0x0B000000 && dwAddy < 0x0C000000)
			return 0x0B000000;
		if (dwAddy >= 0x0C000000 && dwAddy < 0x0D000000)
			return 0x0C000000;
		if (dwAddy >= 0x0D000000 && dwAddy < 0x0E000000)
			return 0x0D000000;
		if (dwAddy >= 0x0E000000 && dwAddy < 0x0F000000)
			return 0x0E000000;
		if (dwAddy >= 0x0F000000 && dwAddy < 0x10000000)
			return 0x0F000000;

		return NULL;
	}
};