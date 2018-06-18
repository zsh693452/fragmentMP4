#ifndef _FMP4_TKHD_BOX_H_
#define _FMP4_TKHD_BOX_H_

// Mandatory

#include "box.h"

class CTkhdBox: public CBox
{
public:
	CTkhdBox();
	~CTkhdBox();

	// creation time, 64 bit
	void SetCreationTime(Uint64 time);

	// creation time, 32 bit
	void SetCreationTime(Uint32 time);

	// modifiation time, 64 bit
	void SetModificationTime(Uint64 time);

	// modification time, 32 bit
	void SetModificationTime(Uint32 time);

	// trak id
	void SetTrackId(Uint32 id);

	// reserved, defalut value is 0
	void SetReserved(Uint32 reserved = 0);

	// duration, 32 bit
	void SetDuration(Uint32 duration);

	// duration 64 bit
	void SetDuration(Uint64 duration);

	// reserved, default value is 0
	void SetReserved2(Uint8 reserved[8]);

	// layer, default value is 0
	void SetLayer(Uint16 layer = 0);

	// alter nate groupp, default value is 0
	void SetAlternateGroup(Uint16 ang = 0);

	// volume, if trak id is a audio trak, value shoud be 0x0100
	// else value is 0
	void SetVolume(Uint16 vol = 0);

	// reserved 2bytes
	void SetReserved3(Uint16 reserved = 0);

	// matrix, default value is 0x00010000,0,0,0,0x00010000,0,0,0,0x40000000
	void SetMatrix(Uint32 matrix[9]);

	// width
	void SetWidth(Uint32 w);

	// height
	void SetHeight(Uint32 h);
};

#endif
