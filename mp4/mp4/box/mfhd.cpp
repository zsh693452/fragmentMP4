#include "mfhd.h"
#include "../unit/unit.h"

static const char *szMfhdBox = "mfhd";

CMfhdBox::CMfhdBox()
{
	Uint32 u32BoxSize = 8;
	SetBoxType((Uint8 *)szMfhdBox);
	SetBoxSize(u32BoxSize);
}

CMfhdBox::~CMfhdBox()
{

}

void CMfhdBox::SetSequenceNumber(Uint32 number)
{
	Uint32 v = CUnit::Uint32Reverse(number);
	AddProperty("sequence_number", (char *)&v, GetBoxSize(), 4);
}