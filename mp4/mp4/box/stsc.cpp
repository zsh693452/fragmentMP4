#include "stsc.h"
#include "../unit/unit.h"

static const char *szStscBox = "stsc";

CStscBox::CStscBox()
{
	Uint32 u32BoxSize = 8;
	SetBoxType((Uint8 *)szStscBox);
	SetBoxSize(u32BoxSize);
}

CStscBox::~CStscBox()
{

}

void CStscBox::SetEntryCount(Uint32 entryCount)
{
	Uint32 v = CUnit::Uint32Reverse(entryCount);
	AddProperty("entry_count", (char *)&v, GetBoxSize(), 4);
}

void CStscBox::SetSamplesPerChunk(Uint32 samples)
{
	Uint32 v = CUnit::Uint32Reverse(samples);
	AddProperty("samples_per_chunk", (char *)&v, GetBoxSize(), 4);
}

void CStscBox::SetSampleDescriptionIndex(Uint32 index)
{
	Uint32 v = CUnit::Uint32Reverse(index);
	AddProperty("samples_description_index", (char *)&v, GetBoxSize(), 4);
}