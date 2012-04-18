#include "common/stdafx.h"

#include "time/realtimeclock.h"

namespace engine
{
	//============================================================================

	extern uint64 g_platformTicksPerSecond;

	//============================================================================

	CRealTimeClock::CRealTimeClock(void)
	{
		LARGE_INTEGER frequency;

		::QueryPerformanceFrequency(&frequency);
		g_platformTicksPerSecond = static_cast<uint64>(frequency.QuadPart);
	}

	//============================================================================

	const CTime::CTimeValue CRealTimeClock::GetCurrentTime() const
	{
		LARGE_INTEGER time;
		::QueryPerformanceCounter(&time);

		CTime::CTimeValue currentTime(static_cast<uint64>(time.QuadPart));

		return currentTime;
	}

	//============================================================================
} // End [namespace engine]

//==============================================================================
// [EOF]

