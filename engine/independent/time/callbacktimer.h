#if !defined(__CALLBACKTIMER_H__)
#define __CALLBACKTIMER_H__

//==============================================================================

#include "time/timer.h"

//==============================================================================

namespace engine
{
	//============================================================================
	// CCallbackTimer
	//============================================================================
	class CCallbackTimer : public CTimer
	{
		typedef CTimer PARENT;

		public:
			typedef bool (*Callback)(CCallbackTimer*, void*);

			CCallbackTimer(CTimer& parent, CTimeValue& maxFrameTime, float scale, CTimeValue& interval, Callback pCallback, void* pUserData)
				: CTimer(parent, maxFrameTime, scale)
				, m_interval(interval)
				, m_pCallback(pCallback)
				, m_pUserData(pUserData)
				, m_active(true)
			{
			}

			CCallbackTimer(CTimer& parent, CTimeValue& maxFrameTime, float scale, double intervalInSeconds, Callback pCallback, void* pUserData)
				: CTimer(parent, maxFrameTime, scale)
				, m_interval(intervalInSeconds)
				, m_pCallback(pCallback)
				, m_pUserData(pUserData)
				, m_active(true)
			{
			}

			CCallbackTimer(CTimer& parent, CTimeValue& maxFrameTime, float scale, uint64 intervalInTicks, Callback pCallback, void* pUserData)
				: CTimer(parent, maxFrameTime, scale)
				, m_interval(intervalInTicks)
				, m_pCallback(pCallback)
				, m_pUserData(pUserData)
				, m_active(true)
			{
			}

			CCallbackTimer(CRealTimeClock& parent, CTimeValue& maxFrameTime, float scale, CTimeValue& interval, Callback pCallback, void* pUserData)
				: CTimer(parent, maxFrameTime, scale)
				, m_interval(interval)
				, m_pCallback(pCallback)
				, m_pUserData(pUserData)
				, m_active(true)
			{
			}

			CCallbackTimer(CRealTimeClock& parent, CTimeValue& maxFrameTime, float scale, double intervalInSeconds, Callback pCallback, void* pUserData)
				: CTimer(parent, maxFrameTime, scale)
				, m_interval(intervalInSeconds)
				, m_pCallback(pCallback)
				, m_pUserData(pUserData)
				, m_active(true)
			{
			}

			CCallbackTimer(CRealTimeClock& parent, CTimeValue& maxFrameTime, float scale, uint64 intervalInTicks, Callback pCallback, void* pUserData)
				: CTimer(parent, maxFrameTime, scale)
				, m_interval(intervalInTicks)
				, m_pCallback(pCallback)
				, m_pUserData(pUserData)
				, m_active(true)
			{
			}

			// ITimer
			virtual const CTimeValue& Tick(void);
			// ~ITimer

			void SetActive(bool active)
			{
				m_active = active;
			}

			bool IsActive(void) const
			{
				return m_active;
			}

		protected:
			CTimeValue m_interval;
			CTimeValue m_ticker;
			Callback m_pCallback;
			void* m_pUserData;
			bool m_active;
	};

	//============================================================================
} // End [namespace engine]

//==============================================================================
#endif // End [!defined(__CALLBACKTIMER_H__)]
// [EOF]

