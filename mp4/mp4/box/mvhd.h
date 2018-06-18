#ifndef _FMP4_MVHD_BOX_H_
#define _FMP4_MVHD_BOX_H_

// Mandatory

#include "box.h"

class CMvhdBox: public CBox
{
public:
	CMvhdBox();
	~CMvhdBox();

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

	// rate default value is 0x00010000
	void SetRate(Uint32 rate = 0x00010000);

	// volue default value is 0x0100
	void SetVolume(Uint16 vol = 0x0100);

	// reserved default value is 0x0000
	void SetReserved(Uint16 reserved = 0x0000);

	// reserved2 8 bytes, default val is 0
	void SetReserved2(Uint8 reserved[8]);

	// matrix uint32 array, size is 9, default value is 0x00010000, 0, 0, 0, 0x00010000, 0, 0, 0, 0x40000000
	void SetMatrix(Uint32 matrix[9]);
	
	// pre_defined, uini32 arary, size is 6, value is 0, 0, 0, 0, 0, 0
	void SetPreDefined(Uint32 defined[6]);

	// next_track_id, default value is 0xffffffff
	void SetNextTrackId(Uint32 id = 0xffffffff);
};
#endif
