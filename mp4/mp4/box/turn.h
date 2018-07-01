#ifndef _FMP4_TRUN_BOX_H_
#define _FMP4_TRUN_BOX_H_

#include "box.h"

class CTrunBox: public CBox
{
public:
	CTrunBox();
	~CTrunBox();

	// sample count 32bit
	void SetSampleCount(Uint32 count);

	// data offset 32bit
	void SetDataOffset(Uint32 offset);

	// first sample flags 32bit
	void SetFirstSampleFlags(Uint32 flags);

	// (optional) sample duration 32bit
	void SetSampleDuration(Uint32 duration);

	// (optional) sample size 32bit
	void SetSampleSize(Uint32 size);

	// (optional) sample flags 32bit
	void SetSampleFlags(Uint32 flags);

	// (optional) sample_composition_time_offset 32bit
	void SetSampleCompositionTimeOffset(Uint32 offset);

	// change data offset 
	// this function will not increase box size
	// iBufferOffset: box memory index for trun data offset field
	// offset: value
	void ChangeDataOffset(int iBufferOffset, Uint32 offset);

};
#endif