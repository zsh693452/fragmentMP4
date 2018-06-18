#include "mdia.h"

static const char *szMdiaBox = "mdia";
CMdiaBox::CMdiaBox()
{
	Uint32 u32BoxSize = 8;
	SetBoxType((Uint8 *)szMdiaBox);
	SetBoxSize(u32BoxSize);
}

CMdiaBox::~CMdiaBox()
{

}