#include "common/stdafx.h"

#include "time/time.h"

//==============================================================================

namespace engine
{
	//============================================================================

	static CRealTimeClock g_realTimeClock;
	// The max frame time gets set properly in CTime::Init()
	static CTimeValue g_oneTick(1ull);
	static CTimer g_gameClock(g_realTimeClock, g_oneTick, 1.0f);
	CRealTimeClock& CTime::s_realTimeClock = g_realTimeClock;
	CTimer& CTime::s_gameTimer = g_gameClock;

	// Gets set properly in CTime::Platform_Init()
	uint64 g_platformTicksPerSecond = 1;
	const uint64& CTimeValue::TICKS_PER_SECOND = g_platformTicksPerSecond;

	//============================================================================

	void CTime::Init(void)
	{
		Platform_Init();

		// Now that the OS ticks per second has been established, we can set the
		// default max frame time sensibly for the game clock
		CTimeValue oneTenthOfASecond(0.1);
		g_gameClock.SetMaxFrameTime(oneTenthOfASecond);
	}

	//============================================================================

	CRealTimeClock& CTime::RealTimeClock(void)
	{
		return s_realTimeClock;
	}

	//============================================================================

	CTimer& CTime::GameClock(void)
	{
		return s_gameTimer;
	}

	//============================================================================

	const CTimeValue& CTimer::Tick(void)
	{
		if (!IsPaused())
		{
			CTimeValue lastTick(m_elapsedTime);
			CTimeValue frameTime(m_scale*m_pParent->GetFrameTime().GetTicks());
			if (frameTime <= m_maxFrameTime)
			{
				m_elapsedTime += frameTime;
			}
			else
			{
				m_elapsedTime += m_maxFrameTime;
			}
		}
		else
		{
			m_frameTime = 0ull;
		}

		return m_frameTime;
	}

	//============================================================================
} // End [namespace engine]

//==============================================================================
// [EOF]
