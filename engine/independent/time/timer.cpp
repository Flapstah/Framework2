#include "common/stdafx.h"

#include "time/time.h"
#include "time/realtimeclock.h"
#include "time/timer.h"

//==============================================================================

namespace engine
{
	//============================================================================

	const CTimeValue& CTimer::Tick(void)
	{
		if (!IsPaused())
		{
			if (m_pParent != NULL)
			{
				m_frameTime = static_cast<uint64>(m_scale*m_pParent->GetFrameTime().GetTicks());
			}
			else
			{
				m_frameTime = static_cast<uint64>(m_scale*CTime::RealTimeClock().GetElapsedTime().GetTicks());
			}

			if (m_frameTime > m_maxFrameTime)
			{
				m_frameTime = m_maxFrameTime;
			}

			m_elapsedTime += m_frameTime;
		}
		else
		{
			m_frameTime = uint64(0);
		}

		return m_frameTime;
	}

	//============================================================================
} // End [namespace engine]

//==============================================================================
// [EOF]

