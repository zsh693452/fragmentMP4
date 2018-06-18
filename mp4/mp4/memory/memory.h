#ifndef _FMP4_MEMORY_H_
#define _FMP4_MEMORY_H_

#include <stdlib.h>
#include <string.h>

#define MEMORY_SIZE 512 * 1024

enum
{
	REALLOC_FAILED = -1,
	REALLOC_MEMORY_ENOUGH = 0,
	REALLOC_SUCCESS = 1,
};

class CMemory
{
public:
	CMemory();
	~CMemory();

	int Write(char *data, int offset, int len);
	int Read(char *data, int offset, int len);
	char *GetMemory();
	int GetMemorySize();

protected:
	int MemoryCheck(int offset, int len);

private:

	char *m_pBuffer;
	int m_bufferLen;
};


#endif


