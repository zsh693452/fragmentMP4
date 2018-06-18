#include "tkhd.h"
#include "../unit/unit.h"

static const char *szTkhdBox = "tkhd";
CTkhdBox::CTkhdBox()
{
	Uint32 u32Size = 8;
	SetBoxType((Uint8 *)szTkhdBox);
	SetBoxSize(u32Size);
}

CTkhdBox::~CTkhdBox()
{

}

void CTkhdBox::SetCreationTime(Uint64 time)
{
	AddProperty("creation_time", (char *)&time, GetBoxSize(), 8);
}

void CTkhdBox::SetCreationTime(Uint32 time)
{
	Uint32 v = CUnit::Uint32Reverse(time);
	AddProperty("creation_time", (char *)&v, GetBoxSize(), 4);
}


void CTkhdBox::SetModificationTime(Uint64 time)
{
	AddProperty("modification_time", (char *)&time, GetBoxSize(), 8);
}

void CTkhdBox::SetModificationTime(Uint32 time)
{
	Uint32 v = CUnit::Uint32Reverse(time);
	AddProperty("modification_time", (char *)&v, GetBoxSize(), 4);
}

void CTkhdBox::SetTrackId(Uint32 id)
{
	Uint32 v = CUnit::Uint32Reverse(id);
	AddProperty("trak_id", (char *)&v, GetBoxSize(), 4);
}

void CTkhdBox::SetReserved(Uint32 reserved)
{
	Uint32 v = CUnit::Uint32Reverse(reserved);
	AddProperty("reserved", (char *)&v, GetBoxSize(), 4);
}

void CTkhdBox::SetDuration(Uint64 duration)
{
	AddProperty("duration", (char *)&duration, GetBoxSize(), 8);
}

void CTkhdBox::SetDuration(Uint32 duration)
{
	Uint32 v = CUnit::Uint32Reverse(duration);
	AddProperty("duration", (char *)&v, GetBoxSize(), 4);
}

void CTkhdBox::SetReserved2(Uint8 reserved[8])
{
	AddProperty("reserved2", (char *)reserved, GetBoxSize(), 8);
}

void CTkhdBox::SetLayer(Uint16 layer /* = 0 */)
{
	Uint16 v = CUnit::Uint16Reverse(layer);
	AddProperty("layer", (char *)&v, GetBoxSize(), 2);
}

void CTkhdBox::SetAlternateGroup(Uint16 ang /* = 0 */)
{
	Uint16 v = CUnit::Uint16Reverse(ang);
	AddProperty("alternate_group", (char *)&v, GetBoxSize(), 2);
}

void CTkhdBox::SetVolume(Uint16 vol /* = 0 */)
{
	Uint16 v = CUnit::Uint16Reverse(vol);
	AddProperty("volume", (char *)&v, GetBoxSize(), 2);
}

void CTkhdBox::SetReserved3(Uint16 reserved)
{
	AddProperty("reserved3", (char *)&reserved, GetBoxSize(), 2);
}

void CTkhdBox::SetMatrix(Uint32 matrix[9])
{
	Uint32 v[9] = {0};
	for (int i = 0; i < 9; i++)
		v[i] = CUnit::Uint32Reverse(matrix[i]);

	AddProperty("matrix", (char *)v, GetBoxSize(), 36);
}

void CTkhdBox::SetWidth(Uint32 w)
{
	Uint32 v = CUnit::Uint32Reverse(w);
	AddProperty("width", (char *)&v, GetBoxSize(), 4);
}

void CTkhdBox::SetHeight(Uint32 h)
{
	Uint32 v = CUnit::Uint32Reverse(h);
	AddProperty("height", (char *)&v, GetBoxSize(), 4);
}