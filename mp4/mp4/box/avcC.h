#ifndef _FMP4_AVCC_BOX_H_
#define _FMP4_AVCC_BOX_H_

#include "box.h"

// AVCDecoderConfigurationRecord 
// Define at ISOIEC 14496-15

class CAvcCBox: public CBox
{
public:
	CAvcCBox();
	~CAvcCBox();

	// configureation version 8bit
	void SetConfigurationVersion(Uint8 ver = 1);

	// AVC Profile indication 8 bit
	void SetAVCProfileIndication(Uint8 avcPi);

	// Profile compatibility 8bit
	void SetProfileCompatibility(Uint8 pc);

	// AVC Level indicaion 8bit
	void SetAVCLevelIndication(Uint8 avcLv);

	// reserved 6bit and lengthSizeMinusOne 2bit
	// reserved value is 111111b
	void SetReservedAndLengthSizeMinusOne(Uint8 mixValue);

	// reserved 3bit and num of sps 5bit
	void SetRessevedAndNumOfSPS(Uint8 mixValue);

	// sps size 16 bit
	void SetSizeOfSPS(Uint16 size);

	// SPS data
	void SetSPS(Uint8 *sps, Uint32 size);

	// Num of PPS 8bit
	void SetNumOfPPS(Uint8 num);

	// pps size
	void SetSizeOfPPS(Uint16 size);

	// PPS data
	void SetPPS(Uint8 *pps, Uint32 size);

};
#endif



