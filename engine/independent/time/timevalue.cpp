#include "common/stdafx.h"

#include "time/timevalue.h"

namespace engine
{
	//============================================================================

	uint64 CTimeValue::GetTime(void) const
	{
		uint64 time = m_ticks;

		uint64 unit = TICKS_PER_SECOND*60*60*24; // ticks per day
		uint64 days = time/unit;
		time -= days*unit;

		unit /= 24; // ticks per hour
		uint64 hours = time/unit;
		time -= hours*unit;

		unit /= 60; // ticks per minute
		uint64 minutes = time/unit;
		time -= minutes*unit;

		time |= (days<<DAYS_SHIFT) | (hours<<HOURS_SHIFT) | (minutes<<MINUTES_SHIFT);
		return time;
	}

	//============================================================================
} // End [namespace engine]

//==============================================================================
// [EOF]

