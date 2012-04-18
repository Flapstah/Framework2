#if !defined(__REALTIMECLOCK_H__)
#define __REALTIMECLOCK_H__

//==============================================================================

#include "time/time.h"

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

			const CTime::CTimeValue GetCurrentTime(void) const;
	}; // End [class CRealTimeClock]

	//============================================================================
} // End [namespace engine]

//==============================================================================
#endif // End [!defined(__REALTIMECLOCK_H__)]
// [EOF]

