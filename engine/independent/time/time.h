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
#define HOURS_SHIFT 39
#define DAYS_SHIFT 50

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

			CTimeValue& operator+=(const CTimeValue& other)
			{
				m_ticks += other.m_ticks;
				return *this;
			}

			CTimeValue& operator-=(const CTimeValue& other)
			{
				m_ticks -= other.m_ticks;
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

			double GetSeconds(void) const
			{
				return static_cast<double>(m_ticks)/TICKS_PER_SECOND;
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

			uint64 GetTicks(void) const
			{
				return m_ticks;
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
} // End [namespace engine]

//==============================================================================
#endif // End [!defined(__TIME_H__)]
// [EOF]
