#include "common/stdafx.h"

#include "time/time.h"

//==============================================================================

namespace engine
{
	//============================================================================

	// Gets set properly in CRealTimeClock constructor
	int64 g_platformTicksPerSecond = 1;
	const int64& CTime::CTimeValue::TICKS_PER_SECOND = g_platformTicksPerSecond;

	//============================================================================

	CTime::CTime(void)
	{
		Initialise();
	}

	//============================================================================

	CTime::~CTime(void)
	{
	}

	//============================================================================

	void CTime::Initialise(void)
	{
		Platform_Initialise();

		// Make sure the game timer is reset to "now".  N.B. Can't do Reset() here
		// because CTimer::Reset() for the game timer will call CTime::Get()...and
		// we're currently in the constructor flow for the original CTime::Get()...
		// which causes a segmentation fault when compiled with GCC (but not Visual
		// Studio oddly).
		m_gameTimer.Reset(GetCurrentTime());

		m_callbackTimers.reserve(CALLBACK_TIMER_POOL_SIZE);
	}

	//============================================================================

	uint32 CTime::CreateCallbackTimer(float maxFrameTime, float scale, double intervalInSeconds, CTime::CCallbackTimer::Callback pCallback, void* const pUserData)
	{
		CCallbackTimer timer(maxFrameTime, scale, intervalInSeconds, pCallback, pUserData);
		return CreateCallbackTimer(timer);
	}

	//============================================================================

	uint32 CTime::CreateCallbackTimer(CTime::CTimer& parent, float maxFrameTime, float scale, double intervalInSeconds, CTime::CCallbackTimer::Callback pCallback, void* const pUserData)
	{
		CCallbackTimer timer(parent, maxFrameTime, scale, intervalInSeconds, pCallback, pUserData);
		return CreateCallbackTimer(timer);
	}

	//============================================================================

	uint32 CTime::CreateCallbackTimer(CTime::CCallbackTimer& timer)
	{
		uint32 timerID = INVALID_TIMER_ID;
		bool addTimer = true;

		if (m_callbackTimers.size() == CALLBACK_TIMER_POOL_SIZE)
		{
#if USE_DYNAMIC_CALLBACK_TIMER_POOL
			printf("CTime::CreateCallbackTimer() : exeeded initial callback timer pool size (%d); consider increasing\n", CALLBACK_TIMER_POOL_SIZE);
#else
			printf("CTime::CreateCallbackTimer() : maximum number of callback timers reached (%d); unable to create more\n", CALLBACK_TIMER_POOL_SIZE);
			addTimer = false;
#endif // USE_DYNAMIC_CALLBACK_TIMER_POOL
		}

		if (addTimer == true)
		{
			timerID = 0;
			for (TCallbackTimerVector::iterator it = m_callbackTimers.begin(); it != m_callbackTimers.end(); ++it)
			{
				CCallbackTimer& timerSlot = *it;
				if (timerSlot.IsActive() == false)
				{
					timerSlot = timer;
					break;
				}
				++timerID;
			}

			if (timerID == CALLBACK_TIMER_POOL_SIZE)
			{
				m_callbackTimers.push_back(timer);
			}
		}

		return timerID;
	}

	//============================================================================
} // End [namespace engine]

//==============================================================================
// [EOF]

