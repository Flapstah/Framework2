#include "common/stdafx.h"

#include "time/time.h"
#include "time/timer.h"

//==============================================================================

namespace engine
{
	//============================================================================

	const CTime::CTimeValue& CTimer::Tick(void)
	{
		if (!IsPaused())
		{
			CTime::CTimeValue now = (m_pParent == NULL) ? CTime::Get().GetCurrentTime() : m_pParent->GetElapsedTime();
			m_frameTime = static_cast<uint64>(m_scale*(now-m_lastTickTime).GetTicks());
			m_lastTickTime = now;

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

	void CTimer::Reset(void)
	{
		m_frameTime = uint64(0);
		m_elapsedTime = uint64(0);
		m_lastTickTime = (m_pParent == NULL) ? CTime::Get().GetCurrentTime() : m_pParent->GetElapsedTime();
		m_frameCount = 0;
	}

	//============================================================================
} // End [namespace engine]

//==============================================================================
// [EOF]

