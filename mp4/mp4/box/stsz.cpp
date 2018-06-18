#include "stsz.h"
#include "../unit/unit.h"

static const char *szStszBox = "stsz";

CStszBox::CStszBox()
{
	Uint32 u32BoxSize = 8;
	SetBoxType((Uint8 *)szStszBox);
	SetBoxSize(u32BoxSize);
}

CStszBox::~CStszBox()
{

}

void CStszBox::SetSampleSize(Uint32 size)
{
	Uint32 v = CUnit::Uint32Reverse(size);
	AddProperty("sample_size", (char *)&v, GetBoxSize(), 4);
}


void CStszBox::SetSampleCount(Uint32 count)
{
	Uint32 v = CUnit::Uint32Reverse(count);
	AddProperty("sample_count", (char *)&v, GetBoxSize(), 4);
}

void CStszBox::SetEntrySize(Uint32 *entrySize, int size)
{
	Uint32 *v = new Uint32[size];
	for (int i = 0; i < size; i++)
		v[i] = CUnit::Uint32Reverse(entrySize[i]);

	AddProperty("entry_size", (char *)&v, GetBoxSize(), 4 * size);
	delete v;
	v = NULL;
}