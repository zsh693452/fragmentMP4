#ifndef _FMP4_MDHD_BOX_H_
#define _FMP4_MDHD_BOX_H_

// Mandatory

#include "box.h"

class CMdhdBox: public CBox
{
public:
	CMdhdBox();
	~CMdhdBox();

	// 64 bit creation time
	void SetCreationTime(Uint64 time);

	// 32 bit creation time
	void SetCreationTime(Uint32 time);

	// 64 bit modification time
	void SetModificationTime(Uint64 time);

	// 32 bit modificatin time
	void SetModificationTime(Uint32 time);

	// time scale
	void SetTimeScale(Uint32 scale);

	// 32 bit duration
	void SetDuration(Uint32 duration);

	// 64 bit duration
	void SetDuration(Uint64 duration);

	// pad and language ,pad bit 1, language 15 bit
	void SetPadLanguage(Uint8 pl[2]);

	// pre_defined, 16bit, default value = 0
	void SetPredefined(Uint16 predefined = 0);
};

#endif
