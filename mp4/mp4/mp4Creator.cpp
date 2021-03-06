#include "mp4Creator.h"

#define VIDEO_WIDTH 1920
#define VIDEO_HEIGHT 1080

CFMP4Creator::CFMP4Creator()
{
	m_pContext = NULL;
}

CFMP4Creator::~CFMP4Creator()
{

}

void * CFMP4Creator::Create()
{
	m_root = new CRootBox();
	m_ftyp = ftyp_box();
	m_iFtypBoxSize = m_ftyp->GetBoxSize();
	m_root->AddChild(m_ftyp);

	return (void *)m_root;
}

char * CFMP4Creator::SetMetaData(char *SPS, int iSPSSize, char *PPS, int iPPSSize, char *VPS, int iVPSSize, int w, int h, int *iOutDataSize)
{
	m_moov = moov_box();
	CBox *mvhd = mvhd_box();
	m_moov->AddChild(mvhd);

	// moov.trak
	CBox *trak = trak_box();
	// moov.trak.tkhd
	CBox *tkhd = tkhd_box(1, false, w, h);
	trak->AddChild(tkhd);

	// moov.trak.mdia
	CBox *mdia = mdia_box();
	// moov.trak.mdia.mdhd
	CBox *mdhd = mdhd_box();
	mdia->AddChild(mdhd);
	// moov.trak.mdia.hdlr
	char szVideoHandlerName[128] = "Bento4 Video Handler";
	CBox *hdlr = hdlr_box("video", szVideoHandlerName, strlen(szVideoHandlerName) + 1);
	mdia->AddChild(hdlr);
	// moov.trak.mdia.minf
	CBox *minf = minf_box();
	// moov.trak.mdia.minf.vmhd
	CBox *vmhd = vmhd_box();
	minf->AddChild(vmhd);
	// moov.trak.mdia.minf.dinf
	CBox *dinf = dinf_box();
	// moov.trak.mdia.minf.dinf.dref
	CBox *dref = dref_box(1);
	// moov.trak.mdia.minf.dinf.dref.url
	CBox *url = url_box(NULL, 0);
	dref->AddChild(url);
	dinf->AddChild(dref);
	minf->AddChild(dinf);
	// moov.trak.mdia.minf.stbl
	CBox *stbl = stbl_box();
	// moov.trak.mdia.minf.stbl.stsd
	CBox *stsd = stsd_box(1);
	// moov.trak.mdia.minf.stbl.stsd.avc1
	CBox *avc1 = avc1_box(w, h);
	// moov.trak.mdia.minf.stbl.stsd.avc1.avcC
	CBox *avcC = avcC_box(SPS, iSPSSize, PPS, iPPSSize);
	avc1->AddChild(avcC);
	stsd->AddChild(avc1);
	stbl->AddChild(stsd);
	// moov.trak.mdia.minf.stbl.stts
	CBox *stts = stts_box();
	stbl->AddChild(stts);
	// moov.trak.mdia.minf.stbl.stsc
	CBox *stsc = stsc_box();
	stbl->AddChild(stsc);
	// moov.trak.mdia.minf.stbl.stsz
	CBox *stsz = stsz_box();
	stbl->AddChild(stsz);
	// moov.trak.mdia.minf.stbl.stco
	CBox *stco = stco_box();
	stbl->AddChild(stco);
	minf->AddChild(stbl);
	mdia->AddChild(minf);
	trak->AddChild(mdia);
	m_moov->AddChild(trak);	
	m_root->AddChild(m_moov);

	// Temp root box
	m_ftypmoovbox = new CRootBox();
	m_ftypmoovbox->AddChild(m_ftyp);
	m_ftypmoovbox->AddChild(m_moov);

	if (iOutDataSize != NULL)
		*iOutDataSize = m_ftypmoovbox->GetBoxSize();

	return m_ftypmoovbox->GetBuffer();
}

char * CFMP4Creator::SetVideoData(char *data, int iDataSize, int *iOutDataSize)
{
	// moof
	m_moof = moof_box();
	// moof.mfhd
	CBox *mfhd = mfhd_box();
	m_moof->AddChild(mfhd);
	// moof.traf
	CBox *traf = traf_box();
	// moof.traf.tfhd
	CBox *tfhd = tfhd_box(1, 0, 0, 3000, 0, 0x01010000); // fake data
	traf->AddChild(tfhd);
	// moof.traf.tfdt
	CBox *tfdt = tfdt_box(0); // fake data
	traf->AddChild(tfdt);
	// moof.traf.trun
	CBox *trun = trun_box(iDataSize);
	// 
	int iToMoovSize = m_ftyp->GetBoxSize() + m_moov->GetBoxSize();
	int iDataOffset = m_moof->GetBoxSize() + traf->GetBoxSize() + trun->GetBoxSize() + 8;
	CTrunBox *trunBox = (CTrunBox *)trun;
	trunBox->ChangeDataOffset(16, iDataOffset);

	traf->AddChild(trun);
	m_moof->AddChild(traf);
	m_root->AddChild(m_moof);

	// mdat
	m_mdat = mdat_box(data, iDataSize);
	m_root->AddChild(m_mdat);

	// tmp box that include moof and mdat box
	m_moofmdatbox = new CRootBox();
	m_moofmdatbox->AddChild(m_moof);
	m_moofmdatbox->AddChild(m_mdat);

	if (iOutDataSize != NULL)
	{
		*iOutDataSize = m_moofmdatbox->GetBoxSize();
		printf("size = %d %d %d", *iOutDataSize, m_moof->GetBoxSize(), m_mdat->GetBoxSize());
	}
	return m_moofmdatbox->GetBuffer();
}

void *CFMP4Creator::GetContext(int *outSize)
{
	m_pContext = (unsigned char *)m_root->GetBuffer();
	*outSize = GetContextSize();
	return m_pContext;
}

int CFMP4Creator::GetContextSize()
{
	m_iContextSize = m_root->GetBoxSize();
	return m_iContextSize;
}

CBox * CFMP4Creator::ftyp_box()
{
	CFtypBox *ftyp = new CFtypBox();
	Uint8 brand[4] = {'m', 'p', '4', '2'};
	Uint8 version[4] = {0x00, 0x00, 0x00, 0x01};
	ftyp->SetMajorBrand(brand);
	ftyp->SetMinorVersion(version);
	Uint8 *brands = (Uint8 *)"mp42avc1iso5";
	ftyp->SetCompatibleBrands(brands, strlen((const char *)brands));

	return ftyp;
}

CBox * CFMP4Creator::moov_box()
{
	CMoovBox *moov = new CMoovBox();
	return moov;
}

CBox *CFMP4Creator::moof_box()
{
	CMoofBox *moof = new CMoofBox();
	return moof;
}

CBox * CFMP4Creator::mdat_box(char *data, int iSize)
{
	CMdatBox *mdat = new CMdatBox();
	mdat->SetData((unsigned char *)data, iSize);
	return mdat;
}

CBox * CFMP4Creator::mvhd_box()
{
	CMvhdBox *mvhd = new CMvhdBox();
	mvhd->SetCreationTime((Uint32)0);
	mvhd->SetModificationTime((Uint32)0);
	mvhd->SetTimeScale((Uint32)1000);
	mvhd->SetDuration((Uint32)50000);
	mvhd->SetRate();
	mvhd->SetVolume();
	mvhd->SetReserved();

	Uint8 resvered[8] = {0};
	mvhd->SetReserved2(resvered);
	Uint32 matrix[9] = {0x00010000,0,0,0,0x00010000,0,0,0,0x40000000};
	mvhd->SetMatrix(matrix);
	Uint32 pre_defined[6] = {0};
	mvhd->SetPreDefined(pre_defined);
	mvhd->SetNextTrackId();

	return mvhd;
}

CBox * CFMP4Creator::trak_box()
{
	CTrakBox *trak = new CTrakBox();
	return trak;
}

CBox * CFMP4Creator::tkhd_box(int trakId, bool audioTrak, int w, int h)
{
	Uint8 flag[3] = {0x00, 0x00, 0x07};
	Uint8 reserved[8] = {0};
	Uint32 matrix[9] = {0x00010000,0,0,0,0x00010000,0,0,0,0x40000000};

	CTkhdBox *tkhd = new CTkhdBox();
	tkhd->SetVersion(0);
	tkhd->SetFlag(flag);
	tkhd->SetCreationTime((Uint32)0);
	tkhd->SetModificationTime((Uint32)0);
	tkhd->SetTrackId(trakId);
	tkhd->SetReserved();
	tkhd->SetDuration((Uint32)0);
	tkhd->SetReserved2(reserved);
	tkhd->SetLayer();
	tkhd->SetAlternateGroup();
	tkhd->SetVolume(audioTrak ? 0x0100 : 0);
	tkhd->SetReserved3();
	tkhd->SetMatrix(matrix);
	tkhd->SetWidth(w);
	tkhd->SetHeight(h);

	return tkhd;
}

CBox * CFMP4Creator::mdia_box()
{
	CMdiaBox *mdia = new CMdiaBox();
	return mdia;
}

CBox *CFMP4Creator::mdhd_box()
{
	Uint8 flag[3] = {0x00, 0x00, 0x00};
	Uint8 pad_language[2] = {0};

	CMdhdBox *mdhd = new CMdhdBox();
	mdhd->SetVersion(0);
	mdhd->SetFlag(flag);
	mdhd->SetCreationTime((Uint32)0);
	mdhd->SetModificationTime((Uint32)0);
	mdhd->SetTimeScale(1000);
	mdhd->SetDuration((Uint32)0);
	mdhd->SetPadLanguage(pad_language);
	mdhd->SetPredefined();

	return mdhd;
}

CBox * CFMP4Creator::hdlr_box(char handleType[4], char *szName, int iNameSize)
{
	Uint8 flag[3] = {0};
	Uint32 reserved[3] = {0};

	CHdlrBox *hdlr = new CHdlrBox();
	hdlr->SetVersion(0);
	hdlr->SetFlag(flag);
	hdlr->SetPredefined();
	hdlr->SetHandleType((Uint8 *)handleType);
	hdlr->SetReserved(reserved);
	hdlr->SetName((Uint8 *)szName, iNameSize);

	return hdlr;
}

CBox * CFMP4Creator::minf_box()
{
	CMinfBox * minf = new CMinfBox();
	return minf;
}

CBox * CFMP4Creator::vmhd_box()
{
	Uint8 flag[3] = {0x00, 0x00, 0x01};
	Uint16 opColor[3] = {0x00, 0x00, 0x00};

	CVmhdBox *vmhd = new CVmhdBox();
	vmhd->SetVersion(0);
	vmhd->SetFlag(flag);
	vmhd->SetGraphicsMode();
	vmhd->SetOpColor(opColor);

	return vmhd;
}

CBox * CFMP4Creator::dinf_box()
{
	CDinfBox *dinf = new CDinfBox();
	return dinf;
}

CBox * CFMP4Creator::dref_box(int entryCount)
{
	Uint8 flag[3] = {0};

	CDrefBox * dref = new CDrefBox();
	dref->SetVersion(0);
	dref->SetFlag(flag);
	dref->SetEntryCount(entryCount);
	return dref;
}

CBox * CFMP4Creator::url_box(char *szLocation, int iSize)
{
	Uint8 flag[3] = {0x00, 0x00, 0x01};
	CUrlBox *url = new CUrlBox();

	url->SetVersion(0);
	url->SetFlag(flag);
	url->SetLocation((Uint8 *)szLocation, iSize);

	return url;
}

CBox * CFMP4Creator::stbl_box()
{
	CStblBox *stbl = new CStblBox();
	return stbl;
}

CBox * CFMP4Creator::stsd_box(int entryCount)
{
	Uint8 flag[3] = {0};

	CStsdBox *stsd = new CStsdBox();
	stsd->SetVersion(0);
	stsd->SetFlag(flag);
	stsd->SetEntryCount(entryCount);

	return stsd;
}

CBox * CFMP4Creator::avc1_box(short w, short h)
{
	Uint32 predefined[3] = {0};
	Uint8 szCompressorName[32] = {0};
	Uint8 reserved[6] = {0};

	CAVC1Box *avc1 = new CAVC1Box();
	avc1->SetReserved(reserved);
	avc1->SetDataReferenceIndex(0x01);
	avc1->SetPredefined();
	avc1->SetReserved2();
	avc1->SetPredefined2(predefined);
	avc1->SetWidth(w);
	avc1->SetHeight(h);
	avc1->SetHorizResolution();
	avc1->SetVertResolution();
	avc1->SetReserved3();
	avc1->SetFrameCount();
	avc1->SetCompressorName(szCompressorName);
	avc1->SetDepth();
	avc1->SetPredefined3();

	return avc1;
}


CBox * CFMP4Creator::avcC_box(char *sps, int sizeOfSPS, char *pps, int sizeOfPPS)
{
	CAvcCBox *avcC = new CAvcCBox();
	avcC->SetConfigurationVersion();
	avcC->SetAVCProfileIndication(0x42);
	avcC->SetProfileCompatibility(0xe0);
	avcC->SetAVCLevelIndication(0x1e);
	avcC->SetReservedAndLengthSizeMinusOne(0xff);
	avcC->SetRessevedAndNumOfSPS(0x01);
	avcC->SetSizeOfSPS(sizeOfSPS);
	avcC->SetSPS((Uint8 *)sps, sizeOfSPS);
	avcC->SetNumOfPPS(0x01);
	avcC->SetSizeOfPPS(sizeOfPPS);
	avcC->SetPPS((Uint8 *)pps, sizeOfPPS);

	return avcC;
}

CBox * CFMP4Creator::stts_box()
{
	Uint8 flag[3] = {0};

	CSttsBox *stts = new CSttsBox();
	stts->SetVersion(0);
	stts->SetFlag(flag);
	stts->SetEntryCount(0);

	return stts;
}

CBox * CFMP4Creator::stsc_box()
{
	Uint8 flag[3] = {0};

	CStscBox *stsc = new CStscBox();
	stsc->SetVersion(0);
	stsc->SetFlag(flag);
	stsc->SetEntryCount(0);

	return stsc;
}

CBox * CFMP4Creator::stsz_box()
{
	Uint8 flag[3] = {0};

	CStszBox *stsz = new CStszBox();
	stsz->SetVersion(0);
	stsz->SetFlag(flag);
	stsz->SetSampleSize(0);
	stsz->SetSampleCount(0);

	return stsz;
}

CBox * CFMP4Creator::stco_box()
{
	Uint8 flag[3] = {0};

	CStcoBox *stco = new CStcoBox();
	stco->SetVersion(0);
	stco->SetFlag(flag);
	stco->SetEntryCount(0);

	return stco;
}

CBox * CFMP4Creator::mfhd_box()
{
	Uint8 flag[3] = {0};

	CMfhdBox *mfhd = new CMfhdBox();
	mfhd->SetVersion(0);
	mfhd->SetFlag(flag);
	mfhd->SetSequenceNumber(1);

	return mfhd;
}

CBox * CFMP4Creator::traf_box()
{
	CTrafBox *traf = new CTrafBox();
	return traf;
}

CBox * CFMP4Creator::tfhd_box(Uint32 trackId, Uint64 baseDataOffset, Uint32 desIndex, Uint32 sampleDuration, Uint32 sampleSize, Uint32 sampleFlag)
{
	Uint8 flag[3] = {0x02, 0x00, 0x28};

	CTfhdBox *tfhd = new CTfhdBox();
	tfhd->SetVersion(0);
	tfhd->SetFlag(flag);
	tfhd->SetTrackId(trackId);
	//tfhd->SetBaseDataOffset(baseDataOffset);
	
	// optional
	//tfhd->SetSampleDescriptionIndex(desIndex);
	tfhd->SetDefaultSampleDuration(sampleDuration);
	//tfhd->SetDefaultSampleSize(sampleSize);
	tfhd->SetDefaultSampleFlag(sampleFlag);

	return tfhd;
}

CBox * CFMP4Creator::tfdt_box(Uint64 time)
{
	Uint8 flag[3] = {0x00};

	CTfdtBox *tfdt = new CTfdtBox();
	tfdt->SetVersion(1);
	tfdt->SetFlag(flag);
	tfdt->SetBaseMediaDecodeTime(time);

	return tfdt;
}


CBox * CFMP4Creator::trun_box(int iSampleSize)
{
	Uint8 flag[3] = {0x00, 0x02, 0x05};

	CTrunBox *trun = new CTrunBox();
	trun->SetVersion(0);
	trun->SetFlag(flag);

	// fake data
	trun->SetSampleCount(1);

	trun->SetDataOffset(0);
	trun->SetFirstSampleFlags(0x02000000);
	//trun->SetSampleDuration(0);
	trun->SetSampleSize((Uint32)iSampleSize);
	//trun->SetSampleFlags(0);
	//trun->SetSampleCompositionTimeOffset(0);

	return trun;
}