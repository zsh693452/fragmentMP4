#include "trak.h"

static const char *szTrakBox = "trak";
CTrakBox::CTrakBox()
{
	Uint32 u32Size = 8;
	SetBoxType((Uint8 *)szTrakBox);
	SetBoxSize(u32Size);
}

CTrakBox::~CTrakBox()
{

}


