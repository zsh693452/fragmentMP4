
#include "mp4.h"
#include "mp4Creator.h"

void *FMP4_Create()
{
	CFMP4Creator *creator = new CFMP4Creator();
	creator->Create();
	return creator;
}

void FMP4_Release(void *hMP4)
{
	if (hMP4 != NULL)
	{
		delete hMP4;
		hMP4 = NULL;
	}
}

unsigned char *FMP4_GetData(void *hMP4, int *iOutSize)
{
	CFMP4Creator *inst = (CFMP4Creator *)hMP4;
	void *p = inst->GetContext(iOutSize);
	return (unsigned char *)p;
}