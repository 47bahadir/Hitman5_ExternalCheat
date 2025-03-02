#include "mem.h"

//get process ID
DWORD mem::getProcId(const wchar_t* procName)
{
	DWORD retProcID = 0;

	HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

	if (hSnap != INVALID_HANDLE_VALUE)
	{
		PROCESSENTRY32 procEntry;
		procEntry.dwSize = sizeof(PROCESSENTRY32);

		if (Process32First(hSnap, &procEntry))
		{

			do
			{
				if (!_wcsicmp(procName, procEntry.szExeFile))
				{
					retProcID = procEntry.th32ProcessID;
					break;
				}
			} while (Process32Next(hSnap, &procEntry));
		}
		else
		{
			return 0;
		}
	}
	CloseHandle(hSnap);
	return retProcID;
}



//get Modula Base Address
uintptr_t mem::getModuleBase(const wchar_t* procName, DWORD procID)
{
	uintptr_t retAddress = 0;

	HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, procID);

	if (hSnap != INVALID_HANDLE_VALUE)
	{
		MODULEENTRY32 modEntry;
		modEntry.dwSize = sizeof(MODULEENTRY32);

		if (Module32First(hSnap, &modEntry))
		{
			do
			{
				if (!_wcsicmp(procName, modEntry.szModule))
				{
					retAddress = (uintptr_t)modEntry.modBaseAddr;
					break;
				}
			} while (Module32Next(hSnap, &modEntry));
		}
	}
	CloseHandle(hSnap);
	return retAddress;
}

//Unlock the pointer chain
uintptr_t mem::findDMAAddy(HANDLE hProc, uintptr_t ptr, std::vector<unsigned int> offsets)
{
	uintptr_t retPtr = ptr;

	for (int i = 0; i < offsets.size(); i++)
	{
		ReadProcessMemory(hProc, (BYTE*)retPtr, &retPtr, sizeof(retPtr), 0);
		retPtr += offsets[i];
	}

	return retPtr;
}

//Patch the memory Address
void mem::patchEx(HANDLE hProc, BYTE* dst, BYTE* src, unsigned int size)
{
	DWORD oldProtect;
	VirtualProtectEx(hProc, dst, size, PAGE_EXECUTE_READWRITE, &oldProtect);

	WriteProcessMemory(hProc, dst, src, size, 0);

	VirtualProtectEx(hProc, dst, size, oldProtect, &oldProtect);
}

//PatchNop the memory Address
void mem::nopEx(HANDLE hProc, BYTE* dst, unsigned int size)
{
	BYTE* nopAddy = new BYTE[size];
	memset(nopAddy, 0x90, size);
	patchEx(hProc, dst, nopAddy, size);
	delete[] nopAddy;
}
