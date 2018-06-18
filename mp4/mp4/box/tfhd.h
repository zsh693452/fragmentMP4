#ifndef _FMP4_TFHD_BOX_H_
#define _FMP4_TFHD_BOX_H_

#include "box.h"

class CTfhdBox: public CBox
{
public:
	CTfhdBox();
	~CTfhdBox();

	// track id 32bit
	void SetTrackId(Uint32 id);

	// base data offset 64bit
	void SetBaseDataOffset(Uint64 offset);

	// sample description index 32bit
	void SetSampleDescriptionIndex(Uint32 index);

	// default sample duration 32bit
	void SetDefaultSampleDuration(Uint32 duration);

	// default sample size
	void SetDefaultSampleSize(Uint32 size);

	// default sample flag
	void SetDefaultSampleFlag(Uint32 flag);
};
#endif

