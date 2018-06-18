#include "vmhd.h"
#include "../unit/unit.h"

static const char *szVmhdBox = "vmhd";

CVmhdBox::CVmhdBox()
{
	Uint32 u32BoxSize = 8;
	SetBoxType((Uint8 *)szVmhdBox);
	SetBoxSize(u32BoxSize);
}

CVmhdBox::~CVmhdBox()
{

}

void CVmhdBox::SetGraphicsMode(Uint16 mode /* = 0 */)
{
	Uint16 v = CUnit::Uint16Reverse(mode);
	AddProperty("graphicsmode", (char *)&v, GetBoxSize(), 2);
}


void CVmhdBox::SetOpColor(Uint16 opClr[3])
{
	Uint16 v[3] = {0};
	for (int i = 0; i < 3; i++)
		v[i] = CUnit::Uint16Reverse(v[i]);

	AddProperty("opcolor", (char *)v, GetBoxSize(), 6);
}