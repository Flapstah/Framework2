#include "common/stdafx.h"

#include "time/time.h"

//==============================================================================

namespace engine
{
	//============================================================================

	static CRealTimeClock g_realTimeClock;
	// The max frame time gets set properly in CTime::Init()
	static CTimeValue g_oneTick(uint64(1));
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
		// we can seed the real time clock by calling GetElapsedTime() twice...
		g_realTimeClock.GetElapsedTime();
		g_realTimeClock.GetElapsedTime();

		// ...then set the default maximum frame time of the game clock sensibly.
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
			if (m_pParent != NULL)
			{
				m_frameTime = static_cast<uint64>(m_scale*m_pParent->GetFrameTime().GetTicks());
			}
			else
			{
				m_frameTime = static_cast<uint64>(m_scale*g_realTimeClock.GetElapsedTime().GetTicks());
			}

			if (m_frameTime > m_maxFrameTime)
			{
				m_frameTime = m_maxFrameTime;
			}

			m_elapsedTime += m_frameTime;
		}
		else
		{
			m_frameTime = uint64(0);
		}

		return m_frameTime;
	}

	//============================================================================

	const CTimeValue& CCallbackTimer::Tick(void)
	{
		if (m_active)
		{
			m_ticker += PARENT::Tick();

			if (m_ticker >= m_interval)
			{
				m_active = m_pCallback(this, m_pUserData);
				m_ticker -= m_interval;
			}
		}

		return m_frameTime;
	}

	//============================================================================
} // End [namespace engine]

//==============================================================================
// [EOF]

