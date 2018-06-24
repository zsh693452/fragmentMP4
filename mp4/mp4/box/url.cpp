#include "url.h"

static const char *szUrlBox = "url ";

CUrlBox::CUrlBox()
{
	Uint32 u32BoxSize = 8;
	SetBoxType((Uint8 *)szUrlBox);
	SetBoxSize(u32BoxSize);
}

CUrlBox::~CUrlBox()
{

}

void CUrlBox::SetLocation(Uint8 *location, Uint32 size)
{
	if (location == NULL || size == 0)
		return;

	AddProperty("location", (char *)location, GetBoxSize(), size);
}