#include "common/stdafx.h"

#include "common/system.h"
#include "common/filesystem.h"
#include "common/log.h"
#include "time/time.h"

//==============================================================================

namespace engine
{
	//============================================================================

#if INSTRUMENTED_CODE
	CSystem::TInstrumentedCodeMap CSystem::s_instrumentedCode;
#endif // INSTRUMENTED_CODE

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

#if INSTRUMENTED_CODE
	void CSystem::Instrument(const char* name)
	{
		SInstrumentedData& data = s_instrumentedCode[name];
		data.m_callCount += 1;
	}

	//============================================================================

	void CSystem::LogInstrumentation(void)
	{
		for (TInstrumentedCodeMap::iterator it = s_instrumentedCode.begin(); it != s_instrumentedCode.end(); ++it)
		{
			SInstrumentedData& data = (*it).second;

			printf("[%s] called %d times\n", (*it).first, data.m_callCount);
		}
	}
#endif // INSTRUMENTED_CODE

	//============================================================================
} // End [namespace engine]

//==============================================================================
// [EOF]

