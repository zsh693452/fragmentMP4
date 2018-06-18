#include "stco.h"
#include "../unit/unit.h"

static const char *szStcoBox = "stco";

CStcoBox::CStcoBox()
{
	Uint32 u32BoxSize = 8;
	SetBoxType((Uint8 *)szStcoBox);
	SetBoxSize(u32BoxSize);
}

CStcoBox::~CStcoBox()
{

}


void CStcoBox::SetEntryCount(Uint32 entryCount)
{
	Uint32 v = CUnit::Uint32Reverse(entryCount);
	AddProperty("entry_count", (char *)&v, GetBoxSize(), 4);
}

void CStcoBox::SetChunkOffset(Uint64 *offsets, int size)
{
	Uint64 *v = new Uint64[size];
	for (int i = 0; i < size; i++)
		v[i] = CUnit::Uint64Reverse(offsets[i]);

	AddProperty("chunk_offset", (char *)v, GetBoxSize(), 8 * size);
	delete v;
	v = NULL;
}