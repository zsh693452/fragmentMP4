#include "dinf.h"


static const char *szDinfBox = "dinf";

CDinfBox::CDinfBox()
{
	Uint32 u32BoxSize = 8;
	SetBoxType((Uint8 *)szDinfBox);
	SetBoxSize(u32BoxSize);
}

CDinfBox::~CDinfBox()
{

}