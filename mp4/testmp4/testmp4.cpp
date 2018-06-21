// testmp4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <windows.h>

#include "../mp4/mp4.h"
#pragma comment(lib, "../lib/mp4.lib")


void WriteFile(char *data, int len)
{
	char szPath[MAX_PATH] = {0};
	GetModuleFileNameA(NULL, (LPSTR)szPath, MAX_PATH);
	char *p = (char *)strrchr((const char *)szPath, '\\');
	*p = 0;
	strcat(szPath, "\\test.mp4");

	FILE *pf = fopen(szPath, "w+");
	if (pf == NULL)
		return;

	fwrite(data, len, 1, pf);
	fclose(pf);
}

int _tmain(int argc, _TCHAR* argv[])
{
	int len = 0;
	void *hmp4 = FMP4_Create();
	FMP4_SetMetaData(hmp4, "123", 3, "123", 3, NULL, 0, 1920, 1080);
	FMP4_SetVideoData(hmp4, "1234567890abcdefg", 17);
	char *data = (char *)FMP4_GetData(hmp4, &len);
	WriteFile(data, len);
	FMP4_Release(hmp4);

	return 0;
}

