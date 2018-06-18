#include "avcC.h"
#include "../unit/unit.h"

static const char *szAvcCBox = "avcC";
CAvcCBox::CAvcCBox()
{
	Uint32 u32BoxSize = 8;
	SetBoxType((Uint8 *)szAvcCBox);
	SetBoxSize(u32BoxSize);
}

CAvcCBox::~CAvcCBox()
{

}

void CAvcCBox::SetConfigurationVersion(Uint8 ver /* = 1 */)
{
	AddProperty("configurationVersion", (char *)&ver, GetBoxSize(), 1);
}

void CAvcCBox::SetAVCProfileIndication(Uint8 avcPi)
{
	AddProperty("AVCProfileIndication", (char *)&avcPi, GetBoxSize(), 1);
}

void CAvcCBox::SetProfileCompatibility(Uint8 pc)
{
	AddProperty("profile_compatibility", (char *)&pc, GetBoxSize(), 1);
}

void CAvcCBox::SetAVCLevelIndication(Uint8 avcLv)
{
	AddProperty("AVCLevelIndication", (char *)&avcLv, GetBoxSize(), 1);
}

void CAvcCBox::SetReservedAndLengthSizeMinusOne(Uint8 mixValue)
{
	AddProperty("reserved_lengthSizeMinusOne", (char *)&mixValue, GetBoxSize(), 1);
}

void CAvcCBox::SetRessevedAndNumOfSPS(Uint8 mixValue)
{
	AddProperty("reserved_NumOfSPS", (char *)&mixValue, GetBoxSize(), 1);
}

void CAvcCBox::SetSizeOfSPS(Uint16 size)
{
	Uint16 v = CUnit::Uint16Reverse(size);
	AddProperty("spsLength", (char *)&v, GetBoxSize(), 2);
}

void CAvcCBox::SetSPS(Uint8 *sps, Uint32 size)
{
	AddProperty("SPS", (char *)sps, GetBoxSize(), size);
}

void CAvcCBox::SetNumOfPPS(Uint8 num)
{
	AddProperty("NumOfPPS", (char *)&num, GetBoxSize(), 1);
}

void CAvcCBox::SetSizeOfPPS(Uint16 size)
{
	Uint16 v = CUnit::Uint16Reverse(size);
	AddProperty("ppsLength", (char *)&v, GetBoxSize(), 2);
}

void CAvcCBox::SetPPS(Uint8 *pps, Uint32 size)
{
	AddProperty("pps", (char *)pps, GetBoxSize(), size);
}