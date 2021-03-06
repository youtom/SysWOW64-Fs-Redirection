// fsRedirect.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "windows.h"


int main(int argc,char ** argv)
{
	char path[] = "C:\\Windows\\System32\\Kernel32.dll";
	PVOID oldValue = NULL;
	//Wow64DisableWow64FsRedirection(&oldValue);
	printf("path wanted = %s\n",path);
	int offset = 0x30;
	DWORD teb = __readfsdword(0x18);
	printf("gs[%x]=%lx\n", offset, teb);
	_asm
	{
		xor eax, eax;			// clear eax
		mov eax, fs:[0x18];		// Reference start of the TEB
		add eax, 0xffffe000;    // get 64bit TEB from 32bit TEB
		mov [eax + 0x14c0],1;	// Disable it, TEB+0x14c0 points to WOW64_SYSREDIRECT, and 1 is to disable. 0 is enable
	}
	CreateFileA(path, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	system("pause");
    return 0;
}

