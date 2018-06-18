#include "traf.h"

static const char *szTrafBox = "traf";

CTrafBox::CTrafBox()
{
	Uint32 u32BoxSize = 0;
	SetBoxType((Uint8 *)szTrafBox);
	SetBoxSize(u32BoxSize);
}

CTrafBox::~CTrafBox()
{

}


