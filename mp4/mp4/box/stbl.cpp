#include "stbl.h"

static const char *szStblBox = "stbl";

CStblBox::CStblBox()
{
	Uint32 u32BoxSize = 8;
	SetBoxType((Uint8 *)szStblBox);
	SetBoxSize(u32BoxSize);
}

CStblBox::~CStblBox()
{

}
