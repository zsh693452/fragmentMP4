#ifndef _FMP4_STSD_BOX_H_
#define _FMP4_STSD_BOX_H_

#include "box.h"

class CStsdBox: public CBox
{
public:
	CStsdBox();
	~CStsdBox();
	
	// entry count
	void SetEntryCount(Uint32 count);

	// i
	void SetIndex(Uint32 i);
};

#endif

