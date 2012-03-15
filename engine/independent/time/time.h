#if !defined(__TIME_H__)
#define __TIME_H__

//==============================================================================

namespace engine
{
	//============================================================================
	// CTime
	//============================================================================
	class CTime
	{
		public:
		static void Init(void);
		static void Sleep(uint32 microseconds);

	protected:
		static void Platform_Init(void);
	};

#define SECONDS_MASK 0x00000000ffffffffull
#define MINUTES_MASK 0x0000003f00000000ull
#define HOURS_MASK   0x000007c000000000ull
#define DAYS_MASK    0xfffff80000000000ull

#define MINUTES_SHIFT 32
#define HOURS_SHIFT 38
#define DAYS_SHIFT 43

	//============================================================================
	// CTimeValue
	//============================================================================
	class CTimeValue
	{
		public:
			CTimeValue(void)
			: m_ticks(0)
			{
			}

			CTimeValue(uint64 ticks)
			: m_ticks(ticks)
			{
			}

			CTimeValue(double seconds)
			: m_ticks(static_cast<uint64>(seconds*TICKS_PER_SECOND))
			{
			}

			CTimeValue(const CTimeValue& other)
			: m_ticks(other.m_ticks)
			{
			}

			CTimeValue& operator=(const CTimeValue& other)
			{
				m_ticks = other.m_ticks;
				return *this;
			}

			CTimeValue& operator=(double seconds)
			{
				m_ticks = seconds*TICKS_PER_SECOND;
				return *this;
			}

			CTimeValue& operator=(uint64 ticks)
			{
				m_ticks = ticks;
				return *this;
			}

			CTimeValue& operator+=(const CTimeValue& other)
			{
				m_ticks += other.m_ticks;
				return *this;
			}

			CTimeValue& operator+=(double seconds)
			{
				m_ticks += seconds*TICKS_PER_SECOND;
				return *this;
			}

			CTimeValue& operator+=(uint64 ticks)
			{
				m_ticks += ticks;
				return *this;
			}

			CTimeValue& operator-=(const CTimeValue& other)
			{
				m_ticks -= other.m_ticks;
				return *this;
			}

			CTimeValue& operator-=(double seconds)
			{
				m_ticks -= seconds*TICKS_PER_SECOND;
				return *this;
			}

			CTimeValue& operator-=(uint64 ticks)
			{
				m_ticks -= ticks;
				return *this;
			}

			const CTimeValue operator+(const CTimeValue& other)
			{
				CTimeValue result(m_ticks+other.m_ticks);
				return result;
			}

			const CTimeValue operator-(const CTimeValue& other)
			{
				CTimeValue result(m_ticks-other.m_ticks);
				return result;
			}

			bool operator==(const CTimeValue& other)
			{
				return (m_ticks == other.m_ticks);
			}

			bool operator<(const CTimeValue& other)
			{
				return (m_ticks < other.m_ticks);
			}

			bool operator<=(const CTimeValue& other)
			{
				return (m_ticks <= other.m_ticks);
			}

			bool operator>(const CTimeValue& other)
			{
				return (m_ticks > other.m_ticks);
			}

			bool operator>=(const CTimeValue& other)
			{
				return (m_ticks >= other.m_ticks);
			}

			double GetSeconds(void) const
			{
				return static_cast<double>(m_ticks)/TICKS_PER_SECOND;
			}

			uint64 GetTicks(void) const
			{
				return m_ticks;
			}

			uint64 GetTime(void) const
			{
				uint64 time = m_ticks;

				uint64 unit = TICKS_PER_SECOND*60*60*24; // ticks per day
				uint64 days = time/unit;
				time -= days*unit;

				unit /= 24; // ticks per hour
				uint64 hours = time/unit;
				time -= hours*unit;
				
				unit /= 60; // ticks per minute
				uint64 minutes = time/unit;
				time -= minutes*unit;

				time |= (days<<DAYS_SHIFT) | (hours<<HOURS_SHIFT) | (minutes<<MINUTES_SHIFT);
				return time;
			}

			static double GetSeconds(uint64 ticks)
			{
				return static_cast<double>(ticks)/TICKS_PER_SECOND;
			}

		protected:
			uint64 m_ticks;

		public:
			static const uint64& TICKS_PER_SECOND;
	};

	//============================================================================
	// ITimer
	//============================================================================
	class ITimer
	{
		public:
			ITimer(void)
				:	m_referenceCount(0)
			{
				Reset();
			}

			~ITimer(void)
			{
				if (m_referenceCount != 0)
				{
					fprintf(stderr, "[ITimer] trying to destroy a timer which is still being referenced\n");
				}
			}
		
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
				m_elapsedTime = 0ull;
				m_frameTime = 0ull;
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

			virtual const CTimeValue& Tick(void) = 0;

		protected:
			CTimeValue m_elapsedTime;
			CTimeValue m_frameTime;
			uint32 m_frameCount;
			uint32 m_referenceCount;
	};
	
	//============================================================================
	// CRealTimeClock
	//============================================================================
	class CRealTimeClock : public ITimer
	{
		public:
			CRealTimeClock(void)
			{
			}

			~CRealTimeClock(void)
			{
			}

			// ITimer
			virtual const CTimeValue& Tick(void);
			// ~ITimer
	};

	//============================================================================
	// CTimer
	//============================================================================
	class CTimer : public ITimer
	{
		public:
			CTimer(CTimer& parent, CTimeValue& maxFrameTime, float scale)
				: m_pParent(&parent)
				, m_maxFrameTime(m_maxFrameTime)
				, m_scale(scale)
				, m_parentIsRealTimeClock(false)
			{
				m_pParent->AddReference();
			}

			CTimer(CRealTimeClock& parent, CTimeValue& maxFrameTime, float scale)
				: m_pParent(&parent)
				, m_maxFrameTime(m_maxFrameTime)
				, m_scale(scale)
				, m_parentIsRealTimeClock(true)
			{
				m_pParent->AddReference();
			}

			~CTimer(void)
			{
				m_pParent->Release();
			}

			// ITimer
			virtual const CTimeValue& Tick(void);
			// ~ITimer

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
				bool paused = false;
				if (!m_parentIsRealTimeClock)
				{
					paused = (m_pParent != NULL) ? reinterpret_cast<CTimer*>(m_pParent)->IsPaused() : m_paused;
				}

				return paused;
			}

		protected:
			ITimer* m_pParent;
			CTimeValue m_maxFrameTime;
			float m_scale;
			bool m_paused;
			bool m_parentIsRealTimeClock;
	};


	//============================================================================
} // End [namespace engine]

//==============================================================================
#endif // End [!defined(__TIME_H__)]
// [EOF]
