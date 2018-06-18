#ifndef _FMP4_TFDT_BOX_H_
#define _FMP4_TFDT_BOX_H_

#include "box.h"

class CTfdtBox: public CBox
{
public:
	CTfdtBox();
	~CTfdtBox();

	void SetBaseMediaDecodeTime(Uint32 time);
	void SetBaseMediaDecodeTime(Uint64 time);
};
#endif
