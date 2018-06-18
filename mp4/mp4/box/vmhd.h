#ifndef _FMP4_VMHD_H_
#define _FMP4_VMHD_H_

// Mandatory

#include "box.h"

class CVmhdBox: public CBox
{
public:
	CVmhdBox();
	~CVmhdBox();

	// graphicsmode 
	void SetGraphicsMode(Uint16 mode = 0);

	// opcolor
	void SetOpColor(Uint16 opClr[3]);
};
#endif
