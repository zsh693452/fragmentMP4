
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
	CFMP4Creator *creator = (CFMP4Creator *)hMP4;
	if (creator != NULL)
	{
		delete creator;
		creator = NULL;
	}
}

char * FMP4_SetMetaData(void *hMP4, 
						char *sps, int iSizeOfSps, 
						char *pps, int iSizeOfPps, 
						char *vps, int iSizeOfVps, 
						int w, int h,
						int *iMetaDataSize)
{
	CFMP4Creator *creator = (CFMP4Creator *)hMP4;
	return creator->SetMetaData(sps, iSizeOfSps, pps, iSizeOfPps, vps, iSizeOfVps, w, h, iMetaDataSize);
}

char * FMP4_SetVideoData(void *hMP4, char *mediaData, int iLen, int *iMediaDataSize)
{
	CFMP4Creator *creator = (CFMP4Creator *)hMP4;
	return creator->SetVideoData(mediaData, iLen, iMediaDataSize);
}


unsigned char *FMP4_GetData(void *hMP4, int *iOutSize)
{
	CFMP4Creator *inst = (CFMP4Creator *)hMP4;
	void *p = inst->GetContext(iOutSize);
	return (unsigned char *)p;
}