#include "moof.h"

static const char *szMoof = "moof";

CMoofBox::CMoofBox()
{
	Uint32 size = 8;
	SetBoxType((Uint8 *)szMoof);
	SetBoxSize(size);
}

CMoofBox::~CMoofBox()
{
	
}