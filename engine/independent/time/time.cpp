#include "common/stdafx.h"

#include "time/time.h"

//==============================================================================

namespace engine
{
	//============================================================================

	// Gets set properly in CTime::Init()
	uint64 g_platformTicksPerSecond = 1;
	const uint64& CTimeValue::TICKS_PER_SECOND = g_platformTicksPerSecond;

	//============================================================================
} // End [namespace engine]

//==============================================================================
// [EOF]
