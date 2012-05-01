#include "common/stdafx.h"

#include "common/system.h"
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

	void CSystem::Initialise(void)
	{
		// This will create and initialise the CTime singleton
		CTime::Get();
	}

	//============================================================================

	void CSystem::Uninitialise(void)
	{
	}

	//============================================================================

	void CSystem::LogCallstack(uint32 maxDepth)
	{
		Platform_LogCallstack(maxDepth);
	}

	//============================================================================
} // End [namespace engine]

//==============================================================================
// [EOF]

