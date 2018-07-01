#ifndef _MP4_H_
#define _MP4_H_

void * FMP4_Create();
char * FMP4_SetMetaData(void *hMP4, 
					char *sps, int iSizeOfSps, 
					char *pps, int iSizeOfPps, 
					char *vps, int iSizeOfVps, 
					int w, int h,
					int *iMetaDataSize);

char * FMP4_SetVideoData(void *hMP4, char *mediaData, int iLen, int *iMediaDataSize);

unsigned char *FMP4_GetData(void *hMP4, int *iOutSize);
void FMP4_Release(void *hMP4);

#endif
