#include "common/stdafx.h"

#include "time/time.h"

//==============================================================================

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

	const CTimeValue CRealTimeClock::GetCurrentTime() const
	{
		LARGE_INTEGER time;
		::QueryPerformanceCounter(&time);

		CTimeValue currentTime(static_cast<uint64>(time.QuadPart));

		return currentTime;
	}

	//============================================================================

	void CTime::Sleep(uint32 microseconds)
	{
		// round up to the nearest 1/2 millisecond
		uint32 milliseconds = (microseconds+500)/1000;
		if ((milliseconds == 0) && (microseconds > 0))
		{
			milliseconds = 0;
		}

		::Sleep(milliseconds);
	}

	//============================================================================
} // End [namespace engine]

//==============================================================================
// [EOF]

