#ifndef _FMP4_STTS_BOX_H_
#define _FMP4_STTS_BOX_H_

// Mandatory

#include "box.h"

class CSttsBox: public CBox
{
public:
	CSttsBox();
	~CSttsBox();
	
	// entry count 32bit
	void SetEntryCount(Uint32 entryCount);

	// sample count 32bit
	void SetSampleCount(Uint32 sampleCount);

	// sample delta 32bit
	void SetSampleDelta(Uint32 sampleDelta);
};

#endif
