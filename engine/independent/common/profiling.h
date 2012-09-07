#if !defined(__PROFILING_H__)
#define __PROFILING_H__

//==============================================================================

#if INSTRUMENTED_CODE

#include "time/time.h"

#include <map>
#include <vector>

//==============================================================================

namespace engine
{
	//============================================================================
	// CProfiling
	//============================================================================
	class CProfiling
	{
		PREVENT_CLASS_INSTANCE;

		public:
			class CData
			{
				CData(void)
			 	{
				}

				void AddSample(CTime::CTimeValue timeSlice)
				{
					uint32 frameID = CTime::Get().GetCurrentFrameID();
					if (frameID == m_frameID)
					{
						m_timeSpentThisFrame += timeSlice;
						m_callCountThisFrame += 1;
					}
					else
					{
						m_frameID = frameID;
						m_timeSpentThisFrame = timeSlice;
						m_callCountThisFrame = 1;
					}

					m_timeSpentLastCall = timeSlice;
					m_timeSpentOverall += timeSlice;
					++m_callCountOverall;
				}

				uint64						m_callCountOverall;
				CTime::CTimeValue	m_timeSpentLastCall;	// no need to reset in initialiser list
				CTime::CTimeValue	m_timeSpentThisFrame;	// no need to reset in initialiser list
				CTime::CTimeValue	m_timeSpentOverall;		// no need to reset in initialiser list
				SProfilingData*		m_pParent;
				uint32						m_callCountThisFrame;
				uint32						m_frameID;
			};

			static void AddCall(const char* name);
			static void AddTime(const char* name, const CTime::CTimeValue timeSpent);

			static void LogProfilingData(void);

			typedef std::map<const char*, SProfilingData> TProfilingDataMap;
			static TProfilingDataMap s_profileDataMap;
	}; // End [class CProfiling]

	//============================================================================

	class CProfileCallCount
	{
		public:
			CProfileCallCount(const char* name)
		 	{
			 	CProfiling::AddCall(name);
		 	}

			~CProfileCallCount(void)
		 	{
			}
	}; // End [class CProfileCallCount]

	//============================================================================

	class CProfileElapsedTime
	{
		public:
			CProfileElapsedTime(const char* name)
			 	: m_name(name)
		 	{
			 	CProfiling::AddCall(name);
			 	m_timeElapsed -= CTime::Get().GetCurrentTime();
		 	}

			~CProfileElapsedTime(void)
		 	{
			 	m_timeElapsed += CTime::Get().GetCurrentTime();
			 	CProfiling::AddTime(m_name, m_timeElapsed);
		 	}

		protected:
			const char*				m_name;
			CTime::CTimeValue	m_timeElapsed;
	}; // End [class CProfileElapsedTime]

	//============================================================================
} // End [namespace engine]

#endif // INSTRUMENTED_CODE

//==============================================================================
#endif // !defined(__PROFILING_H__)
// [EOF]

