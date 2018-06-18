#include "minf.h"

static const char *szMinfBox = "minf";

CMinfBox::CMinfBox()
{
	Uint32 u32BoxSize = 8;
	SetBoxType((Uint8 *)szMinfBox);
	SetBoxSize(u32BoxSize);
}

CMinfBox::~CMinfBox()
{
	
}