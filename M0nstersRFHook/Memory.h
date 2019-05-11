#pragma once
#include <Windows.h>
#include <iostream>
#include <string>
#include <vector>

#define ROUND_UP(p, align)   (((DWORD)(p) + (align)-1) & ~((align)-1))
#define ROUND_DOWN(p, align) ((DWORD)(p) & ~((align)-1))

class Memory {
public:
	Memory();
	~Memory();
public:
	int _stdcall WriteMemory(void* pvAddress, void* pvWriteBuffer, size_t Size);
	ULONG_PTR ReadPtr(DWORD dwBase, INT iOffset);
	std::string ReadStr(DWORD dwBase, INT iOffset);
	BOOL WritePtr(unsigned long ulBase, INT iOffset, int iValue);
	BOOL WriteStr(unsigned long ulBase, INT iOffset, std::string sValue);
public:
	class Pointer {
	private:
		ULONG_PTR* mBase;
		std::vector< INT > mvOffsets;
	public:
		//CONSTRUCTORS
		Pointer();
		Pointer(DWORD Base, INT Offset);
		Pointer(DWORD Base, UINT Level, ...);
		//DESTRUCTOR
		~Pointer();
	private:
		DWORD GetPointedAddress(ULONG_PTR* ulBase, INT OFF_1) {
			__try {
				return *(DWORD*)ulBase + OFF_1;
			}
			__except (EXCEPTION_EXECUTE_HANDLER) {
				return NULL;
			}
		}
	public:
		//READ_PTR
		template< typename T > T Read() {
			if (this->mBase == NULL) {
				return 0;
			}
			else if (this->mvOffsets.size() == 0) {
				return 0;
			}
			else if (IsBadReadPtr((LPVOID)this->mBase, sizeof(ULONG_PTR))) {
				return 0;
			}

			ULONG_PTR Ret = *(ULONG_PTR*)((*(ULONG_PTR*)this->mBase) + this->mvOffsets[0]);

			if (mvOffsets.size() > 1) {
				for (UINT I = 1; I != mvOffsets.size(); ++I) {
					Ret = *(ULONG_PTR*)(Ret + mvOffsets[I]);
					if (IsBadReadPtr((LPVOID)(this->mBase + mvOffsets[I]), sizeof(ULONG_PTR)))
					{
						return 0;
					}
				}
			}
			return (T)Ret;
		};


		//WRITE_PTR
		template< typename T > BOOL Write(T Val) {
			if (this->mBase == NULL) {
				return FALSE;
			}
			else if (this->mvOffsets.size() == 0) {
				return FALSE;
			}
			else if (IsBadReadPtr((LPVOID)this->mBase, sizeof(ULONG_PTR))) {
				return FALSE;
			}

			if (mvOffsets.size() > 1) {
				DWORD O = GetPointedAddress(this->mBase, this->mvOffsets[0]);
				for (UINT I = 1; I != mvOffsets.size() - 1; ++I) {
					O = GetPointedAddress((LPDWORD)O, this->mvOffsets[I]);
				}
				*(LPDWORD)(*(LPDWORD(O)) + this->mvOffsets[this->mvOffsets.size() - 1]) = Val;
			}
			else {
				//SINGLE_PTR
			}
			return TRUE;
		};
	};
};