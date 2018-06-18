#include "mdat.h"

static const char *szMdat = "mdat";

CMdatBox::CMdatBox()
{
	Uint32 size = 8;
	SetBoxType((Uint8 *)szMdat);
	SetBoxSize(size);
}

CMdatBox::~CMdatBox()
{
	
}

void CMdatBox::SetData(unsigned char *data, int iLen)
{
	AddProperty("data", (char *)data, GetBaseBoxHeadOffset(), iLen);
}