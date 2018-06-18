#include "avc1.h"
#include "../unit/unit.h"

static const char *szAvc1Box = "avc1";

CAVC1Box::CAVC1Box()
{
	Uint32 u32BoxSize = 8;
	SetBoxType((Uint8 *)szAvc1Box);
	SetBoxSize(u32BoxSize);
}

CAVC1Box::~CAVC1Box()
{

}

void CAVC1Box::SetPredefined(Uint16 predefined /* = 0 */)
{
	Uint16 v = CUnit::Uint16Reverse(predefined);
	AddProperty("pre_defined", (char *)&v, GetBoxSize(), 2);
}

void CAVC1Box::SetReserved(Uint16 reserved /* = 0 */)
{
	Uint16 v = CUnit::Uint16Reverse(reserved);
	AddProperty("reserved", (char *)&v, GetBoxSize(), 2);
}

void CAVC1Box::SetPredefined2(Uint32 predefined[3])
{
	Uint32 v[3] = {0};
	for (int i = 0; i < 3; i++)
		v[i] = CUnit::Uint32Reverse(predefined[i]);

	AddProperty("pre_defined2", (char *)&v, GetBoxSize(), 4);
}

void CAVC1Box::SetWidth(Uint16 w)
{
	Uint16 v = CUnit::Uint16Reverse(w);
	AddProperty("width", (char *)&v, GetBoxSize(), 2);
}

void CAVC1Box::SetHeight(Uint16 h)
{
	Uint16 v = CUnit::Uint16Reverse(h);
	AddProperty("height", (char *)&v, GetBoxSize(), 2);
}

void CAVC1Box::SetHorizResolution(Uint32 horizRsln /* = 0x00480000 */)
{
	Uint32 v = CUnit::Uint32Reverse(horizRsln);
	AddProperty("horizresolution", (char *)&v, GetBoxSize(), 4);
}

void CAVC1Box::SetVertResolution(Uint32 vertRsln /* = 0x00480000 */)
{
	Uint32 v = CUnit::Uint32Reverse(vertRsln);
	AddProperty("vertresolution", (char *)&v, GetBoxSize(), 4);
}

void CAVC1Box::SetReserved2(Uint32 reserved /* = 0 */)
{
	Uint32 v = CUnit::Uint32Reverse(reserved);
	AddProperty("reserved2", (char *)&reserved, GetBoxSize(), 4);
}

void CAVC1Box::SetFrameCount(Uint16 frameCount /* = 1 */)
{
	Uint32 v = CUnit::Uint16Reverse(frameCount);
	AddProperty("frame_count", (char *)&frameCount, GetBoxSize(), 2);
}

void CAVC1Box::SetCompressorName(Uint8 name[32])
{
	AddProperty("compressorname", (char *)name, GetBoxSize(), 32);
}

void CAVC1Box::SetDepth(Uint16 depth /* = 0x0018 */)
{
	Uint16 v = CUnit::Uint16Reverse(depth);
	AddProperty("depth", (char *)&v, GetBoxSize(), 2);
}

void CAVC1Box::SetPredefined3(Uint16 predefined /* = 0xffff */)
{
	Uint16 v = CUnit::Uint16Reverse(predefined);
	AddProperty("pre_defined3", (char *)&predefined, GetBoxSize(), 2);
}