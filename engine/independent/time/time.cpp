#include "common/stdafx.h"

#include "time/time.h"

//==============================================================================

namespace engine
{
	//============================================================================

	// Gets set properly in CTime::Init()
	uint64 g_platformTicksPerSecond = 1;
	const uint64& CTimeValue::TICKS_PER_SECOND = g_platformTicksPerSecond;

	//============================================================================

	void CTime::Init(void)
	{
		Platform_Init();
	}

	//============================================================================

	const CTimeValue& CTimer::Tick(void)
	{
		if (!IsPaused())
		{
			CTimeValue lastTick(m_elapsedTime);
			CTimeValue frameTime(m_scale*m_pParent->GetFrameTime().GetTicks());
			if (frameTime <= m_maxFrameTime)
			{
				m_elapsedTime += frameTime;
			}
			else
			{
				m_elapsedTime += m_maxFrameTime;
			}
		}
		else
		{
			m_frameTime = 0ull;
		}

		return m_frameTime;
	}

	//============================================================================
} // End [namespace engine]

//==============================================================================
// [EOF]
