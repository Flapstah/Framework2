#include "common/stdafx.h"

#include <unistd.h>

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
		::timeval time;
		::gettimeofday(&time, NULL);
		
		CTimeValue lastTick(m_elapsedTime);
		m_elapsedTime = static_cast<double>(time.tv_sec);
		m_elapsedTime += static_cast<uint64>(time.tv_usec);
		m_frameTime = m_elapsedTime-lastTick;

		return m_frameTime;
	}

	//============================================================================
} // End [namespace engine]

//==============================================================================
// [EOF]
