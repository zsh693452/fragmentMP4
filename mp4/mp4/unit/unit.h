#ifndef _FMP4_UNIT_H_
#define _FMP4_UINT_H_

#include <stdlib.h>

class CUnit
{
public:
	static unsigned int Uint32Reverse(unsigned int v);
	static unsigned short Uint16Reverse(unsigned short v);
	static unsigned long long Uint64Reverse(unsigned long long v);
};

#endif
