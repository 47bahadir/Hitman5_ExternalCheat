#pragma once
#include <windows.h>
#include <vector>
#include <TlHelp32.h>


namespace mem
{

	//get process ID
	DWORD getProcId(const wchar_t* procName);

	//get Modula Base Address
	uintptr_t getModuleBase(const wchar_t* procName, DWORD procID);

	//Unlock the pointer chain
	uintptr_t findDMAAddy(HANDLE hProc, uintptr_t ptr, std::vector<unsigned int> offsets);

	//Patch the memory Address
	void patchEx(HANDLE hProc, BYTE* dst, BYTE* src, unsigned int size);

	//PatchNop the memory Address
	void nopEx(HANDLE hProc, BYTE* dst, unsigned int size);


}

