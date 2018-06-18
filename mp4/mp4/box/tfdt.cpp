#include "tfdt.h"
#include "../unit/unit.h"

static const char *szTfdtBox = "tfdt";

CTfdtBox::CTfdtBox()
{
	Uint32 u32BoxSize = 8;
	SetBoxType((Uint8 *)szTfdtBox);
	SetBoxSize(u32BoxSize);
}

CTfdtBox::~CTfdtBox()
{

}

void CTfdtBox::SetBaseMediaDecodeTime(Uint64 time)
{
	Uint64 v = CUnit::Uint64Reverse(time);
	AddProperty("baseMediaDdecodeTime", (char *)&v, GetBoxSize(), 8);
}

void CTfdtBox::SetBaseMediaDecodeTime(Uint32 time)
{
	Uint32 v = CUnit::Uint32Reverse(time);
	AddProperty("baseMediaDdecodeTime", (char *)&v, GetBoxSize(), 4);
}