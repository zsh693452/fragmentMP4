// testmp4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <windows.h>

#include "../mp4/mp4.h"
#pragma comment(lib, "../lib/mp4.lib")


void WriteFileTest(char *data, int len)
{
	char szPath[MAX_PATH] = {0};
	GetModuleFileNameA(NULL, (LPSTR)szPath, MAX_PATH);
	char *p = (char *)strrchr((const char *)szPath, '\\');
	*p = 0;
	strcat(szPath, "\\test.mp4");

	/*
	FILE *pf = fopen(szPath, "w+");
	if (pf == NULL)
		return;

	int lenOfWrite = fwrite(data, len, 1, pf);
	fclose(pf);
	*/


	HANDLE hFile = CreateFileA(szPath, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE,
								NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	if (hFile == INVALID_HANDLE_VALUE)
		return;

	DWORD dwLenOfWrite = 0;
	WriteFile(hFile, data, len, &dwLenOfWrite, NULL);
	CloseHandle(hFile);
}



int GetSPS(char *sps)
{
	FILE *pf = fopen("E:\\mp4libGithub\\testdata\\data_key_0", "r");
	if (pf == NULL)
		return -1;

	fseek(pf, 0, SEEK_END);
	int len = ftell(pf);
	fseek(pf, 0, SEEK_SET);

	char *buffer = new char[len];
	fread(buffer, len, 1, pf);
	fclose(pf);

	int iOffset = 0;
	int spsOffset = 0;
}

int _tmain(int argc, _TCHAR* argv[])
{
	char sps[] = {	0x00, 0x00, 0x00, 0x01, 0x67, 0x64, 0x00, 0x29, 0xAC, 0x34, 0xCC, 0x07, 0x80, 0x22, 0x7E, 0x5C,
					0x05, 0xA8, 0x08, 0x08, 0x0D, 0x0A, 0x00, 0x00, 0x07, 0xD0, 0x00, 0x01, 0x86, 0xA1, 0xD0, 0xC0,
					0x00, 0x85, 0x2C, 0x00, 0x00, 0x85, 0x2C, 0x17, 0x79, 0x71, 0xA1, 0x80, 0x01, 0x0D, 0x0A, 0x58,
					0x00, 0x01, 0x0D, 0x0A, 0x58, 0x2E, 0xF2, 0xE1, 0x40 };

	char pps[] = {0x00, 0x00, 0x00, 0x01, 0x68, 0xEE, 0x3C, 0x30};

	int len = 0;
	void *hmp4 = FMP4_Create();
	FMP4_SetMetaData(hmp4, sps + 4, sizeof(sps) - 4, pps + 4, sizeof(pps) - 4, NULL, 0, 1920, 1080);
	FMP4_SetVideoData(hmp4, "1234567890abcdefg", 17);
	char *data = (char *)FMP4_GetData(hmp4, &len);
	WriteFileTest(data, len);
	FMP4_Release(hmp4);

	return 0;
}

