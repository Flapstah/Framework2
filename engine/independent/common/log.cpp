#include "common/stdafx.h"

#include "common/log.h"

//==============================================================================

namespace engine
{
	CLog::CLog(const char* fileName)
		: m_flags(LOG_DEFAULT_FLAGS)
		,	m_fileName(fileName)
		, m_pFile(NULL)
	{
		if (CFileSystem::Exists(m_fileName))
		{
			CFileSystem::Rename(m_fileName, newFileName);
		}

		m_pFile = fopen(m_fileName, "w");
	}

	CLog::~CLog(void)
	{
		if (m_pFile != NULL)
		{
			fclose(m_pFile);
		}
	}

	Print(uint32 flags, const char* format, ...);

	SetFlags(uint32 flags);
	uint32 GetFlags(void) const;

	//============================================================================
} // End [namespace engine]

//==============================================================================
// [EOF]

