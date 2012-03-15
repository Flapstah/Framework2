#include "common/stdafx.h"

#include "time/time.h"

//==============================================================================

namespace engine
{
	//============================================================================

	extern uint64 g_platformTicksPerSecond;

	//============================================================================

	void CTime::Platform_Init(void)
	{
		LARGE_INTEGER frequency;

		::QueryPerformanceFrequency(&frequency);
		g_platformTicksPerSecond = static_cast<uint64>(frequency.QuadPart);
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

	const CTimeValue& CRealTimeClock::Tick(void)
	{
		LARGE_INTEGER time;
		::QueryPerformanceCounter(&time);

		CTimeValue lastTick(m_elapsedTime);
		m_elapsedTime = static_cast<uint64>(time.QuadPart);
		m_frameTime = m_elapsedTime-lastTick;

		return m_frameTime;
	}

	//============================================================================
} // End [namespace engine]

//==============================================================================
// [EOF]
