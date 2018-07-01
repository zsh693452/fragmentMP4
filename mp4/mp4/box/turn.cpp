#include "turn.h"
#include "../unit/unit.h"

static const char *szTrunBox = "trun";

CTrunBox::CTrunBox()
{
	Uint32 u32BoxSize = 8;
	SetBoxType((Uint8 *)szTrunBox);
	SetBoxSize(u32BoxSize);
}

CTrunBox::~CTrunBox()
{

}

void CTrunBox::SetSampleCount(Uint32 count)
{
	Uint32 v = CUnit::Uint32Reverse(count);
	AddProperty("sample_count", (char *)&v, GetBoxSize(), 4);
}

void CTrunBox::SetDataOffset(Uint32 offset)
{
	Uint32 v = CUnit::Uint32Reverse(offset);
	AddProperty("data_offset", (char *)&v, GetBoxSize(), 4);
}

void CTrunBox::SetFirstSampleFlags(Uint32 flags)
{
	Uint32 v = CUnit::Uint32Reverse(flags);
	AddProperty("first_sample_flag", (char *)&v, GetBoxSize(), 4);
}

void CTrunBox::SetSampleDuration(Uint32 duration)
{
	Uint32 v = CUnit::Uint32Reverse(duration);
	AddProperty("sample_duration", (char *)&v, GetBoxSize(), 4);
}

void CTrunBox::SetSampleSize(Uint32 size)
{
	Uint32 v = CUnit::Uint32Reverse(size);
	AddProperty("sample_size", (char *)&v, GetBoxSize(), 4);
}

void CTrunBox::SetSampleFlags(Uint32 flags)
{
	Uint32 v = CUnit::Uint32Reverse(flags);
	AddProperty("sample_flags", (char *)&v, GetBoxSize(), 4);
}

void CTrunBox::SetSampleCompositionTimeOffset(Uint32 offset)
{
	Uint32 v = CUnit::Uint32Reverse(offset);
	AddProperty("sample_composition_time_offset", (char *)&v, GetBoxSize(), 4);
}

void CTrunBox::ChangeDataOffset(int iBufferOffset, Uint32 offset)
{
	Uint32 v = CUnit::Uint32Reverse(offset);
	ChangeProperty("data_offset", (char *)&v, iBufferOffset, 4);
}