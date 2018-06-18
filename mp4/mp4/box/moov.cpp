#include "moov.h"

static const char *szMoov = "moov";

CMoovBox::CMoovBox()
{
	Uint32 size = 8;
	SetBoxType((Uint8 *)szMoov);
	SetBoxSize(size);
}

CMoovBox::~CMoovBox()
{
	
}