#include "ftyp.h"


static const char *szFtyp = "ftyp";

CFtypBox::CFtypBox()
{
	SetBoxType((Uint8 *)szFtyp);
}

CFtypBox::~CFtypBox()
{

}

void CFtypBox::SetMajorBrand(Uint8 major[4])
{
	AddProperty("major_brand", (char *)major, GetBaseBoxHeadOffset(), 4);
}


void CFtypBox::SetMinorVersion(Uint8 version[4])
{
	AddProperty("minor_version", (char *)version, GetBaseBoxHeadOffset() + 4, 4);
}

void CFtypBox::SetCompatibleBrands(Uint8 *brands, int len)
{
	AddProperty("compatible_brands", (char *)brands, GetBaseBoxHeadOffset() + 8, len);

	Uint32 uBoxSize = 8 + 8 + len;
	SetBoxSize(uBoxSize);
}