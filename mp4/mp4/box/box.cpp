#include "box.h"
#include "../unit/unit.h"

CBox::CBox(): m_iCountOfChilds(0)
	,m_baseBoxHeadOffset(8) // 4 bytes size and 4 bytes type
	,m_boxSize(0)
	,m_bRoot(false)
{
	m_boxBuffer = new CMemory();
}


CBox::~CBox()
{
	if (m_boxBuffer != NULL)
	{
		delete m_boxBuffer;
		m_boxBuffer = NULL;
	}

	for (BoxChilds::iterator i = m_childs.begin(); i != m_childs.end(); i++)  
		m_childs.erase(i);
}


void CBox::SetBoxSize(Uint32 uBoxSize)
{
	Uint32 _size = CUnit::Uint32Reverse(uBoxSize);
	AddProperty("size", (char *)&_size, 0, 4);
}

void CBox::SetBoxSize(Uint64 uBoxSize)
{
	Uint32 _size_1 = 1;
	Uint32 _size = CUnit::Uint32Reverse(_size_1);
	AddProperty("size", (char *)&_size_1, 0, 4);
	AddProperty("largeSize", (char *)&uBoxSize, 8, 8);
}

void CBox::SetBoxType(Uint8 *type)
{
	if (type[0] == 'r' && type[1] == 'o' && type[2] == 'o' && type[3] == 't')
	{
		m_bRoot = true;
		return;
	}

	AddProperty("type", (char *)type, 4, 4);
}


void CBox::SetFlag(Uint8 flag[3])
{
	AddProperty("flag", (char *)flag, m_baseBoxHeadOffset + 1, 3);
}


void CBox::SetVersion(Uint8 version)
{
	AddProperty("version", (char *)&version, m_baseBoxHeadOffset, 1);
}

void CBox::BoxSizeIncrease(int size)
{
	m_boxSize += size;

	Uint32 v = CUnit::Uint32Reverse(m_boxSize);
	if (m_boxBuffer->Write((char *)&v, 0, 4) != 0)
		return;
}


void CBox::ChangeProperty(char *szProteryName, char *value, int iBufferOffset, int iValueLength)
{
	if (m_boxBuffer->Write(value, iBufferOffset, iValueLength) != 0)
		return;
}

void CBox::AddProperty(char *szProteryName, char *value, int iBufferOffset, int iValueLength)
{
	if (m_boxBuffer->Write(value, iBufferOffset, iValueLength) != 0)
		return;

	// If size property is exist, do not increase box size, only change size property value 
	bool bIsSizeProperty = memcmp(szProteryName, "size", 4) == 0 ? true : false;
	if (propertyList.find(propery_size) != propertyList.end() && bIsSizeProperty)
		return;

	BoxSizeIncrease(iValueLength);

	if (bIsSizeProperty)
		propertyList[propery_size] = 1;
}

char * CBox::AddChild(CBox *child)
{
	if (m_boxBuffer->Write(child->GetBuffer(), GetBoxSize(), child->GetBoxSize()) != 0)
		return NULL;

	m_boxSize += child->GetBoxSize();

	if (!m_bRoot)
	{
		SetBoxSize((Uint32)m_boxSize);
	}

	return GetBuffer();
}

char* CBox::GetBuffer()
{
	return m_boxBuffer->GetMemory();
}

int CBox::GetBaseBoxHeadOffset()
{
	return m_baseBoxHeadOffset;
}

int CBox::GetUsedBoxSize()
{
	return m_boxSize;
}

int CBox::GetBufferSize()
{
	return m_boxBuffer->GetMemorySize();
}

int CBox::GetBoxSize()
{
	return m_boxSize;
}