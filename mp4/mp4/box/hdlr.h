#ifndef _FMP4_HDLR_BOX_H_
#define _FMP4_HDLR_BOX_H_

// Mandatory

#include "box.h"

class CHdlrBox: public CBox
{
public:
	CHdlrBox();
	~CHdlrBox();

	// pre_defined, defalut value is 0
	void SetPredefined(Uint32 predefined = 0);

	// handle type, 32bit
	void SetHandleType(Uint8 handleType[4]);

	// reserved, default value is 0
	void SetReserved(Uint32 reserved[3]);

	// name, utf8 string with null-terminated
	void SetName(Uint8 *name, int len);
};


#endif
