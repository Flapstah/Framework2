#include "common/stdafx.h"

#include <sys/time.h>		// gettimeofday

#include "time/realtimeclock.h"

namespace engine
{
	//============================================================================

	extern uint64 g_platformTicksPerSecond;

	//============================================================================
	
	CRealTimeClock::CRealTimeClock(void)
	{
		g_platformTicksPerSecond = 1000000;
	}

	//============================================================================

	const CTime::CTimeValue CRealTimeClock::GetCurrentTime() const
	{
		::timeval time;
		::gettimeofday(&time, NULL);
		
		CTime::CTimeValue currentTime(static_cast<double>(time.tv_sec));
		currentTime += static_cast<uint64>(time.tv_usec);

		return currentTime;
	}

	//============================================================================
} // End [namespace engine]

//==============================================================================
// [EOF]

