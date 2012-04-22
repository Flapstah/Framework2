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
		: m_gameTimer(0.1f, 1.0f)
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
// TODO: Why does this cause infinite loop?
//		m_gameTimer.Reset();
	}

	//============================================================================
} // End [namespace engine]

//==============================================================================
// [EOF]

