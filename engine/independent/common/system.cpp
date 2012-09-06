#include "common/stdafx.h"

#include "common/system.h"
#include "common/filesystem.h"
#include "common/log.h"
#include "time/time.h"

//==============================================================================

namespace engine
{
	//============================================================================

	CSystem::CSystem(void)
	{
		Initialise();
	}

	//============================================================================

	CSystem::~CSystem(void)
	{
		Uninitialise();
	}

	//============================================================================

	void CSystem::LogCallstack(uint32 maxDepth)
	{
		Platform_LogCallstack(maxDepth);
	}

	//============================================================================

	void CSystem::Initialise(void)
	{
		// This will create and initialise the CTime singleton
		CTime::Get();
		// This will create and initialise the CFileSystem singleton
		CFileSystem::Get();
	}

	//============================================================================

	void CSystem::Uninitialise(void)
	{
	}

	//============================================================================
} // End [namespace engine]

//==============================================================================
// [EOF]

