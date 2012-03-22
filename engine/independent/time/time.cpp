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

	// Gets set properly in CRealTimeClock constructor
	uint64 g_platformTicksPerSecond = 1;
	const uint64& CTimeValue::TICKS_PER_SECOND = g_platformTicksPerSecond;

	//============================================================================

	void CTime::Init(void)
	{
		// The OS ticks per second are set in CRealTimeClock's constructor, so now
		// we can seed the real time clock by ticking it...
		g_realTimeClock.Tick();

		// ...and set the default maximum frame time sensibly for the game clock
		CTimeValue oneTenthOfASecond(0.1);
		g_gameClock.SetMaxFrameTime(oneTenthOfASecond);

		// ...and then seed the game clock by ticking it
		g_gameClock.Tick();
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
			CTimeValue frameTime(static_cast<uint64>(m_scale*m_pParent->GetFrameTime().GetTicks()));
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
