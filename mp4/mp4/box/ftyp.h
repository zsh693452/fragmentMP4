#ifndef _FMP4_FTYP_BOX_H_
#define _FMP4_FTYP_BOX_H_

#include <stdlib.h>
#include "box.h"

class CFtypBox: public CBox
{
public:
	CFtypBox();
	virtual ~CFtypBox();
	
	void SetMajorBrand(Uint8 major[4]);
	void SetMinorVersion(Uint8 version[4]);
	void SetCompatibleBrands(Uint8 *brands, int len);

};

#endif

