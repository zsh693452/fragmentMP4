#ifndef _FMP4_BOX_H_
#define _FMP4_BOX_H_

#include <stdlib.h>
#include <map>
#include "../baseDef/baseType.h"
#include "../memory/memory.h"

enum
{
	propery_size = 0
};

class CBox;

typedef std::map<int, CBox*> BoxChilds;
typedef std::map<int , int> propertys;

class CBox
{
public:
	CBox();
	virtual ~CBox();

	// Set box type, 4bytes
	void SetBoxType(Uint8 *type);

	// Set Box size, 4 bytes
	void SetBoxSize(Uint32 uBoxSize);

	// Get box size
	int GetBoxSize();

	// Set Box size, 16 bytes
	void SetBoxSize(Uint64 uBoxSize);

	// Set full box version, 1 byte
	void SetVersion(Uint8 version);

	// Set full box flag, 3 bytes
	void SetFlag(Uint8 flag[3]);

	// Add a child, return box buffer include child box 
	char * AddChild(CBox *child);

	// Get all buffer data in box
	char* GetBuffer();

	// Get buffer size
	int GetBufferSize();

protected:

	// Write property to box buffer
	// szProteryName is unused
	void AddProperty(char *szProteryName, char *value, int iBufferOffset, int iValueLength);

	void ChangeProperty(char *szProteryName, char *value, int iBufferOffset, int iValueLength);

	// Get base box header size, only include size and type
	int GetBaseBoxHeadOffset();
	
	// Get used box size in buffer
	int GetUsedBoxSize();

	// Calc box size
	void BoxSizeIncrease(int size);

private:
	CMemory *m_boxBuffer;
	BoxChilds m_childs;
	int m_iCountOfChilds;
	int m_baseBoxHeadOffset; 
	int m_boxSize; // Used box size in buffer
	bool m_bRoot;
	propertys propertyList;
};


#endif
