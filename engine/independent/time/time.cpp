#include "common/stdafx.h"

#include "time/time.h"
#include "time/realtimeclock.h"
#include "time/timer.h"

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

	CRealTimeClock& CTime::RealTimeClock(void)
	{
		return s_realTimeClock;
	}

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

	CTimer& CTime::GameClock(void)
	{
		return s_gameTimer;
	}

	//============================================================================
} // End [namespace engine]

//==============================================================================
// [EOF]

