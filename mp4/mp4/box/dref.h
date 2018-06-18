#ifndef _FMP4_DREF_BOX_H_
#define _FMP4_DREF_BOX_H_

// Mandatory

#include "box.h"

class CDrefBox: public CBox
{
public:
	CDrefBox();
	~CDrefBox();

	void SetEntryCount(Uint32 count);
};
#endif
