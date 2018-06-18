#include "hdlr.h"
#include "../unit/unit.h"

static const char *szDdlrBox = "hdlr";

CHdlrBox::CHdlrBox()
{
	Uint32 u32BoxSize = 8;
	SetBoxType((Uint8 *)szDdlrBox);
	SetBoxSize(u32BoxSize);
}

CHdlrBox::~CHdlrBox()
{

}


void CHdlrBox::SetPredefined(Uint32 predefined /* = 0 */)
{
	Uint32 v = CUnit::Uint32Reverse(predefined);
	AddProperty("pre_defined", (char *)&v, GetBoxSize(), 4);
}

void CHdlrBox::SetHandleType(Uint8 handleType[4])
{
	AddProperty("handle_type", (char *)handleType, GetBoxSize(), 4);
}

void CHdlrBox::SetReserved(Uint32 reserved[3])
{
	Uint32 v[3] = {0};
	for (int i = 0; i < 3; i++)
		v[i] = CUnit::Uint32Reverse(reserved[i]);

	AddProperty("reserved", (char *)v, GetBoxSize(), 12);
}

void CHdlrBox::SetName(Uint8 *name, int len)
{
	AddProperty("name", (char *)name, GetBoxSize(), len);
}

