#ifndef _MP4_H_
#define _MP4_H_

void * FMP4_Create();
unsigned char *FMP4_GetData(void *hMP4, int *iOutSize);
void FMP4_Release(void *hMP4);

#endif
