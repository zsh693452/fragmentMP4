#ifndef _FMP4_URL_BOX_H_
#define _FMP4_URL_BOX_H_

#include "box.h"

class CUrlBox: public CBox
{
public:
	CUrlBox();
	~CUrlBox();
	void SetLocation(Uint8 *location, Uint32 size);
};

#endif
