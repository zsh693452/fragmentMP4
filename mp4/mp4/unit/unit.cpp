#include "unit.h"

unsigned int CUnit::Uint32Reverse(unsigned int v)
{
	unsigned int v1 = 0;
	char *pDst = (char *)&v1;
	char *pSrc = (char *)&v;

	pDst[0] = pSrc[3];
	pDst[1] = pSrc[2];
	pDst[2] = pSrc[1];
	pDst[3] = pSrc[0];

	return v1;
}

unsigned short CUnit::Uint16Reverse(unsigned short v)
{
	unsigned short v1 = 0;
	char *pDst = (char *)&v1;
	char *pSrc = (char *)&v;

	pDst[0] = pSrc[1];
	pDst[1] = pSrc[0];

	return v1;
}

unsigned long long CUnit::Uint64Reverse(unsigned long long v)
{
	unsigned long long v1 = 0;
	char *pDst = (char *)&v1;
	char *pSrc = (char *)&v;

	pDst[0] = pSrc[7];
	pDst[1] = pSrc[6];
	pDst[2] = pSrc[5];
	pDst[3] = pSrc[4];
	pDst[4] = pSrc[3];
	pDst[5] = pSrc[2];
	pDst[6] = pSrc[1];
	pDst[7] = pSrc[0];

	return v1;
}