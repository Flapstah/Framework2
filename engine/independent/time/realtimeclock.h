#if !defined(__REALTIMECLOCK_H__)
#define __REALTIMECLOCK_H__

//==============================================================================

#include "time/timevalue.h"

//==============================================================================

namespace engine
{
	//============================================================================
	// CRealTimeClock
	//============================================================================
	class CRealTimeClock
	{
		public:
			CRealTimeClock(void);
			~CRealTimeClock(void)
			{
			}

			const CTimeValue GetCurrentTime(void) const;

			const CTimeValue GetElapsedTime(void)
			{
				CTimeValue now(GetCurrentTime());
				CTimeValue elapsed(now-m_cachedLastTime);
				m_cachedLastTime = now;

				return elapsed;
			}

		protected:
			CTimeValue m_cachedLastTime;
	};

	//============================================================================
} // End [namespace engine]

//==============================================================================
#endif // End [!defined(__REALTIMECLOCK_H__)]
// [EOF]

