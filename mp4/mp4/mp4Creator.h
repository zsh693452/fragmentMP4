#ifndef _MP4_CREATOR_H_
#define _MP4_CREATOR_H_

#include "baseDef/baseType.h"
#include "box/root.h"
#include "box/ftyp.h"
#include "box/moov.h"
#include "box/moof.h"
#include "box/mdat.h"
#include "box/mvhd.h"
#include "box/trak.h"
#include "box/tkhd.h"
#include "box/mdia.h"
#include "box/mdhd.h"
#include "box/hdlr.h"
#include "box/minf.h"
#include "box/vmhd.h"
#include "box/dinf.h"
#include "box/dref.h"
#include "box/url.h"
#include "box/stbl.h"
#include "box/stsd.h"
#include "box/avc1.h"
#include "box/avcC.h"
#include "box/stts.h"
#include "box/stsc.h"
#include "box/stsz.h"
#include "box/stco.h"
#include "box/mfhd.h"
#include "box/traf.h"
#include "box/tfhd.h"
#include "box/tfdt.h"
#include "box/turn.h"

class CFMP4Creator
{
public:
	CFMP4Creator();
	~CFMP4Creator();

	void * Create();
	void SetMetaData(char *SPS, int iSPSSize, char *PPS, int iPPSSize, char *VPS, int iVPSSize, int w, int h);
	void SetVideoData(char *data, int iDataSize);
	void * GetContext(int *iOutSize);
	int GetContextSize();

protected:
	CBox * ftyp_box();
	CBox * moov_box();
	CBox * moof_box();
	CBox * mdat_box(char *data, int iSize);
	CBox * mvhd_box();
	CBox * trak_box();
	CBox * tkhd_box(int trakId, bool audioTrak, int w, int h);
	CBox * mdia_box();
	CBox * mdhd_box();
	CBox * hdlr_box(char handleType[4], char *szName, int iNameSize);
	CBox * minf_box();
	CBox * vmhd_box();
	CBox * dinf_box();
	CBox * dref_box(int entryCount);
	CBox * url_box(char *szLocation, int iSize);
	CBox * stbl_box();
	CBox * stsd_box(int entryCount);
	CBox * avc1_box(short w, short h);
	CBox * avcC_box(char *sps, int sizeOfSPS, char *pps, int sizeOfPPS);
	CBox * stts_box();
	CBox * stsc_box();
	CBox * stsz_box();
	CBox * stco_box();
	CBox * mfhd_box();
	CBox * traf_box();
	CBox * tfhd_box(Uint32 trackId, Uint64 baseDataOffset, Uint32 desIndex, Uint32 sampleDuration, Uint32 sampleSize, Uint32 sampleFlag);
	CBox * tfdt_box(Uint64 time);
	CBox * trun_box(int iSampleSize);

private:
	CBox *m_root;
	CBox *m_moov;
	CBox *m_moof;

	unsigned char *m_pContext;
	int m_iContextSize;
};


#endif
