#include "common/stdafx.h"

#include "time/time.h"

//==============================================================================

namespace engine
{
	//============================================================================

	// Gets set properly in CRealTimeClock constructor
	uint64 g_platformTicksPerSecond = 1;
	const uint64& CTime::CTimeValue::TICKS_PER_SECOND = g_platformTicksPerSecond;

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
	}

	//============================================================================
} // End [namespace engine]

//==============================================================================
// [EOF]

