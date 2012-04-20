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

			CCallbackTimer(CTimer& parent, CTime::CTimeValue maxFrameTime, float scale, CTime::CTimeValue interval, Callback pCallback, void* const pUserData)
				: CTimer(parent, maxFrameTime, scale)
				, m_interval(interval)
				, m_pCallback(pCallback)
				, m_pUserData(pUserData)
				, m_active(true)
			{
			}

			CCallbackTimer(CTimer& parent, CTime::CTimeValue maxFrameTime, float scale, double intervalInSeconds, Callback pCallback, void* const pUserData)
				: CTimer(parent, maxFrameTime, scale)
				, m_interval(intervalInSeconds)
				, m_pCallback(pCallback)
				, m_pUserData(pUserData)
				, m_active(true)
			{
			}

			CCallbackTimer(CTimer& parent, CTime::CTimeValue maxFrameTime, float scale, uint64 intervalInTicks, Callback pCallback, void* const pUserData)
				: CTimer(parent, maxFrameTime, scale)
				, m_interval(intervalInTicks)
				, m_pCallback(pCallback)
				, m_pUserData(pUserData)
				, m_active(true)
			{
			}

			CCallbackTimer(CTime::CTimeValue maxFrameTime, float scale, CTime::CTimeValue interval, Callback pCallback, void* const pUserData)
				: CTimer(maxFrameTime, scale)
				, m_interval(interval)
				, m_pCallback(pCallback)
				, m_pUserData(pUserData)
				, m_active(true)
			{
			}

			CCallbackTimer(CTime::CTimeValue maxFrameTime, float scale, double intervalInSeconds, Callback pCallback, void* const pUserData)
				: CTimer(maxFrameTime, scale)
				, m_interval(intervalInSeconds)
				, m_pCallback(pCallback)
				, m_pUserData(pUserData)
				, m_active(true)
			{
			}

			CCallbackTimer(CTime::CTimeValue maxFrameTime, float scale, uint64 intervalInTicks, Callback pCallback, void* const pUserData)
				: CTimer(maxFrameTime, scale)
				, m_interval(intervalInTicks)
				, m_pCallback(pCallback)
				, m_pUserData(pUserData)
				, m_active(true)
			{
			}

			// ITimer
			virtual const CTime::CTimeValue& Tick(void);
			// ~ITimer

			void SetInterval(CTime::CTimeValue interval)
			{
				m_interval = interval;
			}

			void SetInterval(double intervalInSeconds)
			{
				m_interval = intervalInSeconds;
			}

			void SetInterval(uint64 intervalInTicks)
			{
				m_interval = intervalInTicks;
			}

			const CTime::CTimeValue& GetInterval(void)
			{
				return m_interval;
			}

			void SetActive(bool active)
			{
				m_active = active;
			}

			bool IsActive(void) const
			{
				return m_active;
			}

		protected:
			CTime::CTimeValue m_interval;
			CTime::CTimeValue m_ticker;
			Callback m_pCallback;
			void* const m_pUserData;
			bool m_active;
	}; // End [class CCallbakcTimer]

	//============================================================================
} // End [namespace engine]

//==============================================================================
#endif // End [!defined(__CALLBACKTIMER_H__)]
// [EOF]

