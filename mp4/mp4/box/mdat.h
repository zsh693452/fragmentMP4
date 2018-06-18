#ifndef _FMP4_MDAT_BOX_H_
#define _FMP4_MDAT_BOX_H_

#include "box.h"

class CMdatBox: public CBox
{
public:
	CMdatBox();
	~CMdatBox();

	void SetData(unsigned char *data, int iLen);
};

#endif

