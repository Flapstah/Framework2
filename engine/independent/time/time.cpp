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

		m_timers.reserve(TIMER_POOL_SIZE);
	}

	//============================================================================

	uint32 CTime::CreateTimer(float maxFrameTime, float scale)
	{
		uint32 id = GetFreeTimerID();

		if (id != INVALID_TIMER_ID)
		{
			STimerContainer& timerContainer = m_timers[id];
			timerContainer.m_type = STimerContainer::eT_Timer;
			new(timerContainer.m_timer) CTimer(maxFrameTime, scale);
		}

		return id;
	}

	//============================================================================

	uint32 CTime::CreateTimer(CTime::CTimer& parent, float maxFrameTime, float scale)
	{
		uint32 id = GetFreeTimerID();

		if (id != INVALID_TIMER_ID)
		{
			STimerContainer& timerContainer = m_timers[id];
			timerContainer.m_type = STimerContainer::eT_Timer;
			new(timerContainer.m_timer) CTimer(parent, maxFrameTime, scale);
		}

		return id;
	}

	//============================================================================

	uint32 CTime::CreateCallbackTimer(float maxFrameTime, float scale, double intervalInSeconds, CTime::CCallbackTimer::Callback pCallback, void* const pUserData)
	{
		uint32 id = GetFreeTimerID();

		if (id != INVALID_TIMER_ID)
		{
			STimerContainer& timerContainer = m_timers[id];
			timerContainer.m_type = STimerContainer::eT_CallbackTimer;
			new(timerContainer.m_callbackTimer) CCallbackTimer(maxFrameTime, scale, intervalInSeconds, pCallback, pUserData);
		}

		return id;
	}

	//============================================================================

	uint32 CTime::CreateCallbackTimer(CTime::CTimer& parent, float maxFrameTime, float scale, double intervalInSeconds, CTime::CCallbackTimer::Callback pCallback, void* const pUserData)
	{
		uint32 id = GetFreeTimerID();

		if (id != INVALID_TIMER_ID)
		{
			STimerContainer& timerContainer = m_timers[id];
			timerContainer.m_type = STimerContainer::eT_CallbackTimer;
			new(timerContainer.m_callbackTimer) CCallbackTimer(parent, maxFrameTime, scale, intervalInSeconds, pCallback, pUserData);
		}

		return id;
	}

	//============================================================================

	CTime::CTimer* CTime::GetTimer(uint32 timerID)
	{
		CTimer* pTimer = NULL;

		if (timerID < m_timers.size())
		{
			STimerContainer& timerContainer = m_timers[timerID];
			if (timerContainer.m_type = STimerContainer::eT_Timer)
			{
				pTimer = reinterpret_cast<CTimer*>(&timerContainer.m_timer);
			}
		}

		return pTimer;
	}

	//============================================================================

	CTime::CCallbackTimer* CTime::GetCallbackTimer(uint32 timerID)
	{
		CCallbackTimer* pTimer = NULL;

		if (timerID < m_timers.size())
		{
			STimerContainer& timerContainer = m_timers[timerID];
			if (timerContainer.m_type = STimerContainer::eT_CallbackTimer)
			{
				pTimer = reinterpret_cast<CCallbackTimer*>(&timerContainer.m_callbackTimer);
			}
		}

		return pTimer;
	}

	//============================================================================

	bool CTime::DestroyTimer(uint32 id)
	{
		bool destroyed = false;

		if (id < m_timers.size())
		{
			STimerContainer& timerContainer = m_timers[id];
			timerContainer.~STimerContainer();
			destroyed = true;
		}

		return destroyed;
	}

	//============================================================================

	uint32 CTime::GetFreeTimerID(void)
	{
		uint32 timerID = INVALID_TIMER_ID;
		bool addTimer = true;
		bool indexFound = false;

		if (m_timers.size() == TIMER_POOL_SIZE)
		{
#if USE_DYNAMIC_TIMER_POOL
			printf("CTime::GetNextTimerIndex() : exeeded initial timer pool size (%d); consider increasing\n", TIMER_POOL_SIZE);
			m_timers.reserve(m_timers.size()+1);
#else
			printf("CTime::GetNextTimerIndex() : maximum number of timers reached (%d); unable to create more\n", TIMER_POOL_SIZE);
			addTimer = false;
#endif // USE_DYNAMIC_CALLBACK_TIMER_POOL
		}

		if (addTimer == true)
		{
			timerID = 0;
			for (TTimerVector::iterator it = m_timers.begin(); it != m_timers.end(); ++it)
			{
				STimerContainer& timerContainer = *it;
				if (timerContainer.m_type == STimerContainer::eT_None)
				{
					indexFound = true;
					break;
				}
				++timerID;
			}
		}

		return (indexFound == true) ? timerID : INVALID_TIMER_ID;
	}

	//============================================================================
} // End [namespace engine]

//==============================================================================
// [EOF]

