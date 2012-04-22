#if !defined(__CALLBACKTIMER_H__)
#define __CALLBACKTIMER_H__

//==============================================================================

#include "time/time.h"

//==============================================================================

namespace engine
{
	//============================================================================
	// CCallbackTimer
	//============================================================================
	class CCallbackTimer : public CTime::CTimer
	{
		typedef CTime::CTimer PARENT;

		public:
			typedef bool (*Callback)(CCallbackTimer*, void*);

			CCallbackTimer(CTime::CTimer& parent, float maxFrameTime, float scale, CTime::CTimeValue interval, Callback pCallback, void* const pUserData)
				: CTimer(parent, maxFrameTime, scale)
				, m_interval(interval)
				, m_pCallback(pCallback)
				, m_pUserData(pUserData)
				, m_active(true)
			{
				Reset();
			}

			CCallbackTimer(CTime::CTimer& parent, float maxFrameTime, float scale, double intervalInSeconds, Callback pCallback, void* const pUserData)
				: CTimer(parent, maxFrameTime, scale)
				, m_interval(intervalInSeconds)
				, m_pCallback(pCallback)
				, m_pUserData(pUserData)
				, m_active(true)
			{
				Reset();
			}

			CCallbackTimer(float maxFrameTime, float scale, CTime::CTimeValue interval, Callback pCallback, void* const pUserData)
				: CTimer(maxFrameTime, scale)
				, m_interval(interval)
				, m_pCallback(pCallback)
				, m_pUserData(pUserData)
				, m_active(true)
			{
				Reset();
			}

			CCallbackTimer(float maxFrameTime, float scale, double intervalInSeconds, Callback pCallback, void* const pUserData)
				: CTimer(maxFrameTime, scale)
				, m_interval(intervalInSeconds)
				, m_pCallback(pCallback)
				, m_pUserData(pUserData)
				, m_active(true)
			{
				Reset();
			}

			// ITimer
			virtual const CTime::CTimeValue Update(void);
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

