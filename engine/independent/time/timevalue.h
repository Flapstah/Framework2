#if !defined(__TIMEVALUE_H__)
#define __TIMEVALUE_H__

//==============================================================================

#define SECONDS_MASK 0x00000000ffffffffull
#define MINUTES_MASK 0x0000003f00000000ull
#define HOURS_MASK   0x000007c000000000ull
#define DAYS_MASK    0xfffff80000000000ull

#define MINUTES_SHIFT 32
#define HOURS_SHIFT 38
#define DAYS_SHIFT 43

//==============================================================================

namespace engine
{
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

			explicit CTimeValue(uint64 ticks)
			: m_ticks(ticks)
			{
			}

			explicit CTimeValue(double seconds)
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
				m_ticks = static_cast<uint64>(seconds*TICKS_PER_SECOND);
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
				m_ticks += static_cast<uint64>(seconds*TICKS_PER_SECOND);
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
				m_ticks -= static_cast<uint64>(seconds*TICKS_PER_SECOND);
				return *this;
			}

			CTimeValue& operator-=(uint64 ticks)
			{
				m_ticks -= ticks;
				return *this;
			}

			const CTimeValue operator+(const CTimeValue& other) const
			{
				CTimeValue result(m_ticks+other.m_ticks);
				return result;
			}

			const CTimeValue operator+(double seconds) const
			{
				CTimeValue result(m_ticks+(seconds*TICKS_PER_SECOND));
				return result;
			}

			const CTimeValue operator+(uint64 ticks) const
			{
				CTimeValue result(m_ticks+ticks);
				return result;
			}

			const CTimeValue operator-(const CTimeValue& other) const
			{
				CTimeValue result(m_ticks-other.m_ticks);
				return result;
			}

			const CTimeValue operator-(double seconds) const
			{
				CTimeValue result(m_ticks-(seconds*TICKS_PER_SECOND));
				return result;
			}

			const CTimeValue operator-(uint64 ticks) const
			{
				CTimeValue result(m_ticks-ticks);
				return result;
			}

			bool operator==(const CTimeValue& other) const
			{
				return (m_ticks == other.m_ticks);
			}

			bool operator==(double seconds) const
			{
				return (m_ticks == seconds*TICKS_PER_SECOND);
			}

			bool operator==(uint64 ticks) const
			{
				return (m_ticks == ticks);
			}

			bool operator<(const CTimeValue& other) const
			{
				return (m_ticks < other.m_ticks);
			}

			bool operator<(double seconds) const
			{
				return (m_ticks < seconds*TICKS_PER_SECOND);
			}

			bool operator<(uint64 ticks) const
			{
				return (m_ticks < ticks);
			}

			bool operator<=(const CTimeValue& other) const
			{
				return (m_ticks <= other.m_ticks);
			}

			bool operator<=(double seconds) const
			{
				return (m_ticks <= seconds*TICKS_PER_SECOND);
			}

			bool operator<=(uint64 ticks) const
			{
				return (m_ticks <= ticks);
			}

			bool operator>(const CTimeValue& other) const
			{
				return (m_ticks > other.m_ticks);
			}

			bool operator>(double seconds) const
			{
				return (m_ticks > seconds*TICKS_PER_SECOND);
			}

			bool operator>(uint64 ticks) const
			{
				return (m_ticks > ticks);
			}

			bool operator>=(const CTimeValue& other) const
			{
				return (m_ticks >= other.m_ticks);
			}

			bool operator>=(double seconds) const
			{
				return (m_ticks >= seconds*TICKS_PER_SECOND);
			}

			bool operator>=(uint64 ticks) const
			{
				return (m_ticks >= ticks);
			}

			double GetSeconds(void) const
			{
				return static_cast<double>(m_ticks)/TICKS_PER_SECOND;
			}

			uint64 GetTicks(void) const
			{
				return m_ticks;
			}

			uint64 GetTime(void) const;

			static double GetSeconds(uint64 ticks)
			{
				return static_cast<double>(ticks)/TICKS_PER_SECOND;
			}

		protected:
			uint64 m_ticks;

		public:
			static const uint64& TICKS_PER_SECOND;
	}; // End [class CTimeValue]

	//============================================================================
} // End [namespace engine]

//==============================================================================
#endif // End [!defined(__TIMEVALUE_H__)]
// [EOF]

