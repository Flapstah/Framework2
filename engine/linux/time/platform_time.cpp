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

	void CTime::Sleep(uint32 microseconds)
	{
		::usleep(microseconds);
	}

	//============================================================================

	const CTimeValue& CRealTimeClock::Tick(void)
	{
		CTimeValue lastTick(m_elapsedTime);
		m_elapsedTime = GetTime();
		m_frameTime = m_elapsedTime-lastTick;

		return m_frameTime;
	}

	//============================================================================

	const CTimeValue CRealTimeClock::GetTime() const
	{
		::timeval time;
		::gettimeofday(&time, NULL);
		
		CTimeValue currentTime(static_cast<double>(time.tv_sec));
		currentTime += static_cast<uint64>(time.tv_usec);

		return currentTime;
	}

	//============================================================================
} // End [namespace engine]

//==============================================================================
// [EOF]
