#include "stts.h"
#include "../unit/unit.h"

static const char *szSttsBox = "stts";

CSttsBox::CSttsBox()
{
	Uint32 u32BoxSize = 8;
	SetBoxType((Uint8 *)szSttsBox);
	SetBoxSize(u32BoxSize);
}

CSttsBox::~CSttsBox()
{

}

void CSttsBox::SetEntryCount(Uint32 entryCount)
{
	Uint32 v = CUnit::Uint32Reverse(entryCount);
	AddProperty("entry_count", (char *)&v, GetBoxSize(), 4);
}

void CSttsBox::SetSampleCount(Uint32 sampleCount)
{
	Uint32 v = CUnit::Uint32Reverse(sampleCount);
	AddProperty("sample_count", (char *)&v, GetBoxSize(), 4);
}

void CSttsBox::SetSampleDelta(Uint32 sampleDelta)
{
	Uint32 v = CUnit::Uint32Reverse(sampleDelta);
	AddProperty("sample_delta", (char *)&v, GetBoxSize(), 4);
}