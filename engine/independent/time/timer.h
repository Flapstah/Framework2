#if !defined(__TIMER_H__)
#define __TIMER_H__

//==============================================================================

#include "time/timevalue.h"

//==============================================================================

namespace engine
{
	//============================================================================
	// Forward declarations
	//============================================================================
	class CRealTimeClock;

	//============================================================================
	// CTimer
	//============================================================================
	class CTimer
	{
		public:
			CTimer(CTimer& parent, CTimeValue& maxFrameTime, float scale)
				: m_maxFrameTime(maxFrameTime)
				, m_pParent(&parent)
				,	m_referenceCount(0)
				, m_scale(scale)
				, m_paused(false)
			{
				m_pParent->AddReference();
			}

			CTimer(CRealTimeClock& parent, CTimeValue& maxFrameTime, float scale)
				: m_maxFrameTime(maxFrameTime)
				, m_pParent(NULL)
				,	m_referenceCount(0)
				, m_scale(scale)
				, m_paused(false)
			{
				IGNORE_PARAMETER(parent);
			}

			virtual ~CTimer(void)
			{
				if (m_pParent)
				{
					m_pParent->Release();
				}

				if (m_referenceCount != 0)
				{
					fprintf(stderr, "[CTimer] trying to destroy a timer which is still being referenced\n");
				}
			}

			virtual const CTimeValue& Tick(void);

			const CTimeValue& GetElapsedTime(void) const
			{
				return m_elapsedTime;
			}

			const CTimeValue& GetFrameTime(void) const
			{
				return m_frameTime;
			}

			const uint32 GetFrameCount(void) const
			{
				return m_frameCount;
			}

			void Reset(void)
			{
				m_elapsedTime = uint64(0);
				m_frameTime = uint64(0);
				m_frameCount = 0;
			}

			uint32 AddReference(void)
			{
				return ++m_referenceCount;
			}

			uint32 Release(void)
			{
				return --m_referenceCount;
			}

			void SetScale(float scale)
			{
				m_scale = scale;
			}

			float GetScale(void) const
			{
				return m_scale;
			}

			void Pause(bool pause)
			{
				m_paused = pause;
			}

			bool IsPaused(void) const
			{
				bool paused = (m_pParent != NULL) ? reinterpret_cast<CTimer*>(m_pParent)->IsPaused() : m_paused;
				return paused;
			}

			void SetMaxFrameTime(CTimeValue& maxFrameTime)
			{
				m_maxFrameTime = maxFrameTime;
			}

			const CTimeValue& GetMaxFrameTime(void) const
			{
				return m_maxFrameTime;
			}

		protected:
			CTimeValue m_maxFrameTime;
			CTimeValue m_frameTime;
			CTimeValue m_elapsedTime;
			CTimer* m_pParent;
			uint32 m_referenceCount;
			uint32 m_frameCount;
			float m_scale;
			bool m_paused;
	}; // End [class CTimer]

	//============================================================================
} // End [namespace engine]

//==============================================================================
#endif // End [!defined(__TIMER_H__)]
// [EOF]

