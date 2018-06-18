#ifndef _FMP4_STCO_BOX_H_
#define _FMP4_STCO_BOX_H_

#include "box.h"

class CStcoBox: public CBox
{
public:
	CStcoBox();
	~CStcoBox();

	// entry count 32bit
	void SetEntryCount(Uint32 entryCount);

	// chunk offset, a array of uint64
	void SetChunkOffset(Uint64 *offsets, int size);
};
#endif

