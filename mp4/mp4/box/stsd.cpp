#include "stsd.h"
#include "../unit/unit.h"

static const char *szStsdBox = "stsd";

CStsdBox::CStsdBox()
{
	Uint32 u32BoxSize = 8;
	SetBoxType((Uint8 *)szStsdBox);
	SetBoxSize(u32BoxSize);
}


CStsdBox::~CStsdBox()
{

}

void CStsdBox::SetEntryCount(Uint32 count)
{
	Uint32 v = CUnit::Uint32Reverse(count);
	AddProperty("entry_count", (char *)&v, GetBoxSize(), 4);
}