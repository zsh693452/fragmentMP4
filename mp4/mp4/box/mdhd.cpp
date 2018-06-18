#include "mdhd.h"
#include "../unit/unit.h"

static const char *szMdhdBox = "mdhd";


CMdhdBox::CMdhdBox()
{
	Uint32 u32BoxSize = 8;
	SetBoxType((Uint8 *)szMdhdBox);
	SetBoxSize(u32BoxSize);
}

CMdhdBox::~CMdhdBox()
{

}

void CMdhdBox::SetCreationTime(Uint64 time)
{
	AddProperty("creation_time", (char *)&time, GetBoxSize(), 8);
}

void CMdhdBox::SetCreationTime(Uint32 time)
{
	AddProperty("creation_time", (char *)&time, GetBoxSize(), 4);
}

void CMdhdBox::SetModificationTime(Uint64 time)
{
	AddProperty("modification_time", (char *)&time, GetBoxSize(), 8);
}

void CMdhdBox::SetModificationTime(Uint32 time)
{
	AddProperty("modification_time", (char *)&time, GetBoxSize(), 4);
}

void CMdhdBox::SetTimeScale(Uint32 scale)
{
	Uint32 v = CUnit::Uint32Reverse(scale);
	AddProperty("time_scale", (char *)&v, GetBoxSize(), 4);
}

void CMdhdBox::SetDuration(Uint32 duration)
{
	AddProperty("duration", (char *)&duration, GetBoxSize(), 4);
}

void CMdhdBox::SetDuration(Uint64 duration)
{
	AddProperty("duration", (char *)&duration, GetBoxSize(), 8);
}

void CMdhdBox::SetPadLanguage(Uint8 pl[2])
{
	AddProperty("pad_language", (char *)pl, GetBoxSize(), 2);
}

void CMdhdBox::SetPredefined(Uint16 predefined)
{
	Uint16 v = CUnit::Uint16Reverse(predefined);
	AddProperty("pre_defined", (char *)&v, GetBoxSize(), 2);
}