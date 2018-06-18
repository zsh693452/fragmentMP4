#include "dref.h"
#include "../unit/unit.h"

static const char *szDrefBox = "dref";

CDrefBox::CDrefBox()
{
	Uint32 u32BoxSize = 8;
	SetBoxType((Uint8 *)szDrefBox);
	SetBoxSize(u32BoxSize);
}


CDrefBox::~CDrefBox()
{

}


void CDrefBox::SetEntryCount(Uint32 count)
{
	Uint32 v = CUnit::Uint32Reverse(count);
	AddProperty("entry_count", (char *)&v, GetBoxSize(), 4);
}


