#include "common/stdafx.h"

#include "time/callbacktimer.h"

//==============================================================================

namespace engine
{
	//============================================================================

	const CTime::CTimeValue& CCallbackTimer::Tick(void)
	{
		if (m_active)
		{
			m_ticker += PARENT::Tick();

			if (m_ticker >= m_interval)
			{
				m_active = m_pCallback(this, m_pUserData);
				m_ticker -= m_interval;
			}
		}

		return m_frameTime;
	}

	//============================================================================
} // End [namespace engine]

//==============================================================================
// [EOF]

