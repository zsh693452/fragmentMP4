#include "mvhd.h"
#include "../unit/unit.h"

static const char *szMvhdBox = "mvhd";

CMvhdBox::CMvhdBox()
{
	Uint32 u32BoxSize = 8;
	Uint8 flag[3] = {0x00, 0x00, 0x00};

	SetBoxType((Uint8 *)szMvhdBox);
	SetBoxSize(u32BoxSize);
	SetVersion(0);
	SetFlag(flag);
}

CMvhdBox::~CMvhdBox()
{
	
}

void CMvhdBox::SetCreationTime(Uint64 time)
{
	AddProperty("creation_time", (char *)&time, GetBoxSize(), 8);
}

void CMvhdBox::SetCreationTime(Uint32 time)
{
	AddProperty("creation_time", (char *)&time, GetBoxSize(), 4);
}

void CMvhdBox::SetModificationTime(Uint64 time)
{
	AddProperty("modification_time", (char *)&time, GetBoxSize(), 8);
}

void CMvhdBox::SetModificationTime(Uint32 time)
{
	AddProperty("modification_time", (char *)&time, GetBoxSize(), 4);
}

void CMvhdBox::SetTimeScale(Uint32 scale)
{
	Uint32 v = CUnit::Uint32Reverse(scale);
	AddProperty("time_scale", (char *)&v, GetBoxSize(), 4);
}

void CMvhdBox::SetDuration(Uint32 duration)
{
	Uint32 v = CUnit::Uint32Reverse(duration);
	AddProperty("duration", (char *)&v, GetBoxSize(), 4);
}

void CMvhdBox::SetDuration(Uint64 duration)
{
	Uint64 v = CUnit::Uint64Reverse(duration);
	AddProperty("duration", (char *)&v, GetBoxSize(), 8);
}

void CMvhdBox::SetRate(Uint32 rate)
{
	Uint32 v = CUnit::Uint32Reverse(rate);
	AddProperty("rate", (char *)&v, GetBoxSize(), 4);
}

void CMvhdBox::SetVolume(Uint16 vol)
{
	Uint16 v = CUnit::Uint16Reverse(vol);
	AddProperty("volume", (char *)&v, GetBoxSize(), 2);
}

void CMvhdBox::SetReserved(Uint16 reserved)
{
	Uint16 v = CUnit::Uint16Reverse(reserved);
	AddProperty("reserved", (char *)&v, GetBoxSize(), 2);
}

void CMvhdBox::SetReserved2(Uint8 reserved[8])
{
	AddProperty("reserved", (char *)reserved, GetBoxSize(), 8);
}

void CMvhdBox::SetMatrix(Uint32 matrix[9])
{
	Uint32 v[9] = {0};
	for (int i = 0; i < 9; i++)
		v[i] = CUnit::Uint32Reverse(matrix[i]);

	AddProperty("matrix", (char *)v, GetBoxSize(), 36);
}

void CMvhdBox::SetPreDefined(Uint32 defined[6])
{
	Uint32 v[6] = {0};
	for (int i = 0; i < 6; i++)
		v[i] = CUnit::Uint32Reverse(defined[i]);

	AddProperty("pre_defined", (char *)v, GetBoxSize(), 24);
}

void CMvhdBox::SetNextTrackId(Uint32 id)
{
	Uint32 v = CUnit::Uint32Reverse(id);
	AddProperty("next_track_id", (char *)&v, GetBoxSize(), 4);
}