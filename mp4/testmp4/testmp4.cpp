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

	HANDLE hFile = CreateFileA(szPath, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE,
								NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	if (hFile == INVALID_HANDLE_VALUE)
		return;

	DWORD dwLenOfWrite = 0;
	WriteFile(hFile, data, len, &dwLenOfWrite, NULL);
	CloseHandle(hFile);
}


class CH264Parser
{

#define NALU_IDR 5
#define NALU_SPS 7
#define NALU_PPS 8

public:
	CH264Parser();
	CH264Parser(char *frame, int frameLen);
	~CH264Parser();

	void ParseKeyFrame(char *sps, int &spsSize, char *pps, int &ppsSize, char *idr, int &idrSize);
	int NaluType(char cNALHeader);

private:
	char *m_data;
	int m_dataLen;
};

int GetMetadata(char *sps, int &spsLen, char *pps, int &ppsLen, char *idr, int &idrLen)
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
	
	CH264Parser parser(buffer, len);
	parser.ParseKeyFrame(sps, spsLen, pps, ppsLen, idr, idrLen);
	
	delete[] buffer;
	buffer = NULL;
}



CH264Parser::CH264Parser()
{

}


CH264Parser::CH264Parser(char *frame, int frameLen)
{
	m_data = frame;
	m_dataLen = frameLen;
}

CH264Parser::~CH264Parser()
{
	
}

int CH264Parser::NaluType(char cNALHeader)
{
	return cNALHeader & 0x1f;
}

void CH264Parser::ParseKeyFrame(char *sps, int &spsSize, char *pps, int &ppsSize, char *idr, int &idrSize)
{
	int offset = 0;
	bool bIDR = false;
	bool bSPS = false;
	bool bPPS = false;
	bool bOtherNalu = false;

	int iIDROffset = 0;
	int iSPSOffset = 0;
	int iPPSOffset = 0;
	int iOtherOffset = 0;

	while(offset + 4 <= m_dataLen)
	{
		if (m_data[offset] == 0x00 && m_data[offset + 1] == 0x00 && m_data[offset + 2] == 0x00 && m_data[offset + 3] == 0x01)
		{
			int naluType = NaluType(m_data[offset + 4]);

			if (naluType == NALU_IDR)
			{
				bIDR = true;
				iIDROffset = offset;
			}
			else if (naluType == NALU_SPS)
			{
				bSPS = true;
				iSPSOffset = offset;
			}
			else if (naluType == NALU_PPS)
			{
				bPPS = true;
				iPPSOffset = offset;
			}
			else 
			{
				bOtherNalu = true;
				iOtherOffset = 0;
			}

			offset += 4;
		}
		else
		{
			offset++;
		}

		if (bIDR && bSPS && bPPS)
		{
			memcpy(sps, m_data + iSPSOffset, iPPSOffset - iSPSOffset);
			spsSize = iPPSOffset - iSPSOffset;

			memcpy(pps, m_data + iPPSOffset, iIDROffset - iPPSOffset);
			ppsSize = iIDROffset - iPPSOffset;

			memcpy(idr, m_data + iIDROffset, m_dataLen - iIDROffset);
			idrSize = m_dataLen - iIDROffset;
			break;
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	/*
	char sps[] = {	0x00, 0x00, 0x00, 0x01, 0x67, 0x64, 0x00, 0x29, 0xAC, 0x34, 0xCC, 0x07, 0x80, 0x22, 0x7E, 0x5C,
					0x05, 0xA8, 0x08, 0x08, 0x0D, 0x0A, 0x00, 0x00, 0x07, 0xD0, 0x00, 0x01, 0x86, 0xA1, 0xD0, 0xC0,
					0x00, 0x85, 0x2C, 0x00, 0x00, 0x85, 0x2C, 0x17, 0x79, 0x71, 0xA1, 0x80, 0x01, 0x0D, 0x0A, 0x58,
					0x00, 0x01, 0x0D, 0x0A, 0x58, 0x2E, 0xF2, 0xE1, 0x40 };

	char pps[] = {0x00, 0x00, 0x00, 0x01, 0x68, 0xEE, 0x3C, 0x30};
	*/

	int spsLen = 512;
	int ppsLen = 512;
	int idrLen = 1024 * 1024;
	char *sps = new char[512];
	char *pps = new char[512];
	char *idr = new char[1024 * 1024];
	GetMetadata(sps, spsLen, pps, ppsLen, idr, idrLen);

	int len = 0;
	void *hmp4 = FMP4_Create();
	FMP4_SetMetaData(hmp4, sps + 4, spsLen - 4, pps + 4, ppsLen - 4, NULL, 0, 1920, 1080);
	FMP4_SetVideoData(hmp4, idr, idrLen);
	char *data = (char *)FMP4_GetData(hmp4, &len);
	WriteFileTest(data, len);
	FMP4_Release(hmp4);

	delete[] sps;
	delete[] pps;
	delete[] idr;

	return 0;
}

