#ifndef _FMP4_STSC_BOX_H_
#define _FMP4_STSC_BOX_H_

// Mandatory

#include "box.h"

class CStscBox: public CBox
{
public:
	CStscBox();
	~CStscBox();

	// entry count 32bit
	void SetEntryCount(Uint32 entryCount);

	// first chunk 32bit
	void SetFirstChunk(Uint32 firstChunk);

	// samples per chunk 32bit
	void SetSamplesPerChunk(Uint32 samples);

	// sample description index 32bit
	void SetSampleDescriptionIndex(Uint32 index);
};
#endif
