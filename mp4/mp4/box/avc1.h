#ifndef _FMP4_AVC1_BOX_H_
#define _FMP4_AVC1_BOX_H_

#include "box.h"

// define at IOSIEC 14496-12
// avc1 box is a SampleEntry
// class VisualSampleEntry(codingname) extends SampleEntry (codingname)

class CAVC1Box: public CBox
{
public:
	CAVC1Box();
	~CAVC1Box();

	// ------- part of SampleEntry -------

	// reserved 6bytes
	void SetReserved(Uint8 reserved[6]);

	// data_reference_idex
	void SetDataReferenceIndex(Uint16 index);

	// ------- part of VisualSampleEntry -------

	// pre_defined 16bit;
	void SetPredefined(Uint16 predefined = 0);

	// reserved 16bit;
	void SetReserved2(Uint16 reserved = 0);

	// pre_defined array of uint32, size is 3
	void SetPredefined2(Uint32 predefined[3]);

	// width 16bit
	void SetWidth(Uint16 w);

	// height 16bit
	void SetHeight(Uint16 h);

	// horizresolution 32bit
	void SetHorizResolution(Uint32 horizRsln = 0x00480000);

	// vertresolution  32bit
	void SetVertResolution(Uint32 vertRsln = 0x00480000);

	// reserved 32bit
	void SetReserved3(Uint32 reserved = 0);

	// frame count 16bit
	void SetFrameCount(Uint16 frameCount = 1);

	// compressor name array of uint8, size is 32
	void SetCompressorName(Uint8 name[32]);

	// depth 16bit
	void SetDepth(Uint16 depth = 0x0018);

	// pre_defined
	void SetPredefined3(Uint16 predefined = 0xffff);


};

#endif
