#include "common/stdafx.h"

#include <unistd.h>			// usleep
#include <sys/time.h>		// gettimeofday

#include "time/time.h"

//==============================================================================

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

	const CTimeValue CRealTimeClock::GetCurrentTime() const
	{
		::timeval time;
		::gettimeofday(&time, NULL);
		
		CTimeValue currentTime(static_cast<double>(time.tv_sec));
		currentTime += static_cast<uint64>(time.tv_usec);

		return currentTime;
	}

	//============================================================================

	void CTime::Sleep(uint32 microseconds)
	{
		::usleep(microseconds);
	}

	//============================================================================
} // End [namespace engine]

//==============================================================================
// [EOF]
