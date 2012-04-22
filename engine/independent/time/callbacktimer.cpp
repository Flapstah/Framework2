#include "common/stdafx.h"

#include "time/callbacktimer.h"

//==============================================================================

namespace engine
{
	//============================================================================

	const CTime::CTimeValue CCallbackTimer::Update(void)
	{
		if (m_active)
		{
			m_ticker += PARENT::Update();

			if (m_ticker >= m_interval)
			{
				m_active = m_pCallback(this, m_pUserData);
				m_ticker -= m_interval;
			}
		}

		return PARENT::GetFrameTime();
	}

	//============================================================================
} // End [namespace engine]

//==============================================================================
// [EOF]

