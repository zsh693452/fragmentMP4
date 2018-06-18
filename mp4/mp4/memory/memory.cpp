#include "memory.h"

CMemory::CMemory() :m_pBuffer(NULL), m_bufferLen(MEMORY_SIZE)
{
	m_pBuffer = new char[MEMORY_SIZE];
}

CMemory::~CMemory()
{
	if (m_pBuffer != NULL)
	{
		free(m_pBuffer);
		m_pBuffer = NULL;
	}
}

int CMemory::MemoryCheck(int offset, int len)
{
	if (m_pBuffer == NULL)
		return REALLOC_FAILED;

	int iAppendLen = offset + len - m_bufferLen;
	if (iAppendLen <= 0)
		return REALLOC_MEMORY_ENOUGH;

	char *p = (char *)realloc(m_pBuffer, iAppendLen + m_bufferLen);
	if (p = NULL)
		return REALLOC_FAILED;

	m_pBuffer = p;
	m_bufferLen = iAppendLen + m_bufferLen;

	return REALLOC_SUCCESS;
}

int CMemory::Write(char *data, int offset, int len)
{
	if (m_pBuffer == NULL)
		return REALLOC_FAILED;

	if (MemoryCheck(offset, len) == REALLOC_FAILED)
		return -1;

	memcpy(m_pBuffer + offset, data, len);

	return 0;
}


int CMemory::Read(char *data, int offset, int len)
{
	if (m_pBuffer == NULL)
		return -1;

	memcpy(data, m_pBuffer + offset, len);

	return 0;
}

char *CMemory::GetMemory()
{
	if (m_pBuffer == NULL)
		return NULL;

	return m_pBuffer;
}

int CMemory::GetMemorySize()
{
	return m_bufferLen;
}