#include "common/stdafx.h"

#if INSTRUMENTED_CODE

#include "common/profiling.h"

//==============================================================================

namespace engine
{
	//============================================================================

	CProfiling::TProfilingDataMap CProfiling::s_profileDataMap;

	//============================================================================

	void CProfiling::AddCall(const char* name)
	{
		SProfilingData& data = s_profileDataMap[name];
		data.m_callCount += 1;
	}

	//============================================================================

	void CProfiling::AddTime(const char* name, const CTime::CTimeValue timeSpent)
	{
		SProfilingData& data = s_profileDataMap[name];
		data.m_timeSpentLastCall = timeSpent;
		data.m_timeSpentOverall += timeSpent;
	}

	//============================================================================

	void CProfiling::LogProfilingData(void)
	{
		for (TProfilingDataMap::iterator it = s_profileDataMap.begin(); it != s_profileDataMap.end(); ++it)
		{
			SProfilingData& data = (*it).second;

			if (data.m_timeSpentOverall.GetTicks() == 0)
			{
				printf("[%s] called %d times (no time logged)\n", (*it).first, data.m_callCount);
			}
			else
			{
				printf("[%s] called %d times, taking %.03f\n", (*it).first, data.m_callCount, data.m_timeSpentOverall.GetSeconds()*1000.0);
			}
		}
	}

	//============================================================================
} // End [namespace engine]

#endif // INSTRUMENTED_CODE

//==============================================================================
// [EOF]

