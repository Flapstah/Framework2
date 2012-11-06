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
#define TIME_FIELD_WIDTH (16)	// width for floating point number
#define TIME_FIELD_MS (2) // width for 'ms'
#define TIME_FIELDS_TOTAL_WIDTH (TIME_FIELD_WIDTH+TIME_FIELD_MS)
#define TIME_FIELDS_LEFT_PAD ((TIME_FIELDS_TOTAL_WIDTH+1-sizeof("Elapsed time"))/2)
#define TIME_FIELDS_RIGHT_PAD (TIME_FIELDS_TOTAL_WIDTH-TIME_FIELDS_LEFT_PAD)
#define CALL_COUNT_THIS_FRAME_FIELD_WIDTH (10)
#define CALL_COUNT_THIS_FRAME_LEFT_PAD ((CALL_COUNT_THIS_FRAME_FIELD_WIDTH+1-sizeof("# calls"))/2)
#define CALL_COUNT_THIS_FRAME_RIGHT_PAD (CALL_COUNT_THIS_FRAME_FIELD_WIDTH-CALL_COUNT_THIS_FRAME_LEFT_PAD)
#define CALL_COUNT_OVERALL_FIELD_WIDTH (19)
#define CALL_COUNT_OVERALL_LEFT_PAD ((CALL_COUNT_OVERALL_FIELD_WIDTH+1-sizeof("# calls"))/2)
#define CALL_COUNT_OVERALL_RIGHT_PAD (CALL_COUNT_OVERALL_FIELD_WIDTH-CALL_COUNT_OVERALL_LEFT_PAD)
#define PER_FRAME_COLUMN_WIDTH (TIME_FIELDS_TOTAL_WIDTH+CALL_COUNT_THIS_FRAME_FIELD_WIDTH+3)
#define PER_FRAME_LEFT_PAD ((PER_FRAME_COLUMN_WIDTH+1-sizeof("This frame"))/2)
#define PER_FRAME_RIGHT_PAD (PER_FRAME_COLUMN_WIDTH-PER_FRAME_LEFT_PAD)
#define OVERALL_COLUMN_WIDTH (TIME_FIELDS_TOTAL_WIDTH+CALL_COUNT_OVERALL_FIELD_WIDTH+3)
#define OVERALL_LEFT_PAD ((OVERALL_COLUMN_WIDTH+1-sizeof("Overall"))/2)
#define OVERALL_RIGHT_PAD (OVERALL_COLUMN_WIDTH-OVERALL_LEFT_PAD)

		printf("\n+-------------------------------------------------------------------------------\n");
		printf("| %*s%-*s | %*s%-*s |\n", PER_FRAME_LEFT_PAD, "", PER_FRAME_RIGHT_PAD, "This frame", OVERALL_LEFT_PAD, "", OVERALL_RIGHT_PAD, "Overall");
		printf("+-------------------------------------------------------------------------------\n");
		printf("| %*s%-*s | %*s%-*s | %*s%-*s | %*s%-*s |\n",
			 TIME_FIELDS_LEFT_PAD,						"", TIME_FIELDS_RIGHT_PAD,						"Elapsed time",
			 CALL_COUNT_THIS_FRAME_LEFT_PAD,	"", CALL_COUNT_THIS_FRAME_RIGHT_PAD,	"# calls",
			 TIME_FIELDS_LEFT_PAD,						"", TIME_FIELDS_RIGHT_PAD,						"Elapsed time",
			 CALL_COUNT_OVERALL_LEFT_PAD,			"", CALL_COUNT_OVERALL_RIGHT_PAD,			"# calls"
			 );
		printf("+-------------------------------------------------------------------------------\n");

		for (TProfilingDataMap::iterator it = s_profileDataMap.begin(); it != s_profileDataMap.end(); ++it)
		{
			CData& data = (*it).second;

			printf("| %*.03fms | %*d | %*.03fms | %*" PRIu64 " | [%s]\n",
				 	TIME_FIELD_WIDTH, data.m_timeElapsedThisFrame.GetSeconds()*1000.0f, CALL_COUNT_THIS_FRAME_FIELD_WIDTH, data.m_callCountThisFrame,
					TIME_FIELD_WIDTH, data.m_timeElapsedOverall.GetSeconds()*1000.0f, CALL_COUNT_OVERALL_FIELD_WIDTH, data.m_callCountOverall,
					(*it).first);
		}

		printf("+-------------------------------------------------------------------------------\n\n");
	}

	//============================================================================
} // End [namespace engine]

#endif // ENABLE_PROFILING

//==============================================================================
// [EOF]

