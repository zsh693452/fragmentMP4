#ifndef _FMP4_STSZ_BOX_H_
#define _FMP4_STSZ_BOX_H_

#include "box.h"

class CStszBox: public CBox
{
public:
	CStszBox();
	~CStszBox();

	// sample size 32bit
	void SetSampleSize(Uint32 size);

	// sampe count 32 bit
	void SetSampleCount(Uint32 count);

	// if sample size is zero, this property is enable
	void SetEntrySize(Uint32 *entrySize, int size);
};
#endif
