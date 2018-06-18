#include "tfhd.h"
#include "../unit/unit.h"

static const char *szTfhdBox = "tfhd";

CTfhdBox::CTfhdBox()
{
	Uint32 u32BoxSize = 8;
	SetBoxType((Uint8 *)szTfhdBox);
	SetBoxSize(u32BoxSize);
}

CTfhdBox::~CTfhdBox()
{
	
}

void CTfhdBox::SetTrackId(Uint32 id)
{
	Uint32 v = CUnit::Uint32Reverse(id);
	AddProperty("track_id", (char *)&v, GetBoxSize(), 4);
}

void CTfhdBox::SetBaseDataOffset(Uint64 offset)
{
	Uint64 v = CUnit::Uint64Reverse(offset);
	AddProperty("base_data_offset", (char *)&v, GetBoxSize(), 8);
}

void CTfhdBox::SetSampleDescriptionIndex(Uint32 index)
{
	Uint32 v = CUnit::Uint32Reverse(index);
	AddProperty("sample_description_index", (char *)&v, GetBoxSize(), 4);
}

void CTfhdBox::SetDefaultSampleDuration(Uint32 duration)
{
	Uint32 v = CUnit::Uint32Reverse(duration);
	AddProperty("default_sample_duration", (char *)&v, GetBoxSize(), 4);
}

void CTfhdBox::SetDefaultSampleSize(Uint32 size)
{
	Uint32 v = CUnit::Uint32Reverse(size);
	AddProperty("default_sample_size", (char *)&v, GetBoxSize(), 4);
}

void CTfhdBox::SetDefaultSampleFlag(Uint32 flag)
{
	Uint32 v = CUnit::Uint32Reverse(flag);
	AddProperty("default_sample_flag", (char *)&v, GetBoxSize(), 4);
}