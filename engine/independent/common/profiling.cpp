#include "common/stdafx.h"

#if ENABLE_PROFILING

#include "common/profiling.h"

//==============================================================================

namespace engine
{
	//============================================================================

	CProfiling::TProfilingDataMap CProfiling::s_profileDataMap;

	//============================================================================

	void CProfiling::AddSample(const char* name, const CTime::CTimeValue timeElapsed)
	{
		CData& data = s_profileDataMap[name];
		data.AddSample(timeElapsed);
	}

	//============================================================================

	void CProfiling::LogProfilingData(void)
	{
		printf("This frame   | Overall      | Name\n");

		for (TProfilingDataMap::iterator it = s_profileDataMap.begin(); it != s_profileDataMap.end(); ++it)
		{
			CData& data = (*it).second;

			printf("%.03fms (%d) | %.03fms (%" PRIu64 ") | [%s]\n",
				 	data.m_timeElapsedThisFrame.GetSeconds()*1000.0f, data.m_callCountThisFrame,
					data.m_timeElapsedOverall.GetSeconds()*1000.0f, data.m_callCountOverall,
					(*it).first);
		}
	}

	//============================================================================
} // End [namespace engine]

#endif // ENABLE_PROFILING

//==============================================================================
// [EOF]

