#if !defined(__PROFILING_H__)
#define __PROFILING_H__

//==============================================================================

#if ENABLE_PROFILING

#include "time/time.h"

#include <map>
#include <vector>

//==============================================================================

#define PROFILE(_name_) engine::CScopedProfile scopedProfile(_name_)
#define LOG_PROFILING engine::CProfiling::LogProfilingData()

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
				public:
					CData(void)
						: m_callCountOverall(0)
						, m_callCountThisFrame(0)
						, m_pParent(NULL)
						, m_frameID(0)
					{
					}

					void AddSample(const CTime::CTimeValue& timeElapsed)
					{
						uint32 frameID = CTime::Get().GetCurrentFrameID();

						if (frameID == m_frameID)
						{
							m_timeElapsedThisFrame += timeElapsed;
							m_callCountThisFrame += 1;
						}
						else
						{
							m_frameID = frameID;
							m_timeElapsedThisFrame = timeElapsed;
							m_callCountThisFrame = 1;
						}

						m_timeElapsedLastCall = timeElapsed;
						m_timeElapsedOverall += timeElapsed;
						++m_callCountOverall;
					}

					uint64						m_callCountOverall;
					CTime::CTimeValue	m_timeElapsedLastCall;	// no need to reset in initialiser list
					CTime::CTimeValue	m_timeElapsedThisFrame;	// no need to reset in initialiser list
					CTime::CTimeValue	m_timeElapsedOverall;		// no need to reset in initialiser list
					CData*						m_pParent;
					uint32						m_callCountThisFrame;
					uint32						m_frameID;
			};

			static void AddSample(const char* name, const CTime::CTimeValue timeElapsed);
			static void LogProfilingData(void);

			typedef std::map<const char*, CData> TProfilingDataMap;
			static TProfilingDataMap s_profileDataMap;
	}; // End [class CProfiling]

	//============================================================================

	class CScopedProfile
	{
		public:
			CScopedProfile(const char* name)
			 	: m_name(name)
		 	{
			 	m_timeElapsed -= CTime::Get().GetCurrentTime();
		 	}

			~CScopedProfile(void)
		 	{
			 	m_timeElapsed += CTime::Get().GetCurrentTime();
				CProfiling::AddSample(m_name, m_timeElapsed);
		 	}

		protected:
			const char*				m_name;
			CTime::CTimeValue	m_timeElapsed;
	}; // End [class CScopedProfile]

	//============================================================================
} // End [namespace engine]

#else

#define PROFILE(_name_) /* elide */
#define LOG_PROFILING /* elide */

#endif // ENABLE_PROFILING

//==============================================================================
#endif // !defined(__PROFILING_H__)
// [EOF]

