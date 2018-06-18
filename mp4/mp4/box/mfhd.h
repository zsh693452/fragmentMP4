#ifndef _FMP4_MFHD_BOX_H_
#define _FMP4_MFHD_BOX_H_

#include "box.h"

class CMfhdBox: public CBox
{
public:
	CMfhdBox();
	~CMfhdBox();

	void SetSequenceNumber(Uint32 number);
};

#endif
