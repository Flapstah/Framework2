#if !defined(__TIME_H__)
#define __TIME_H__

//==============================================================================

namespace engine
{
	//============================================================================

	class CRealTimeClock;
	class CTimer;

	//============================================================================
	// CTime
	//============================================================================
	class CTime
	{
		public:

			//========================================================================

			//========================================================================
			// CTimeValue
			//========================================================================
			class CTimeValue
			{
				public:
					enum eConstants
					{
						SECONDS_MASK	 = uint64(0x00000000ffffffffu),
						MINUTES_MASK	 = uint64(0x0000003f00000000u),
						HOURS_MASK		 = uint64(0x000007c000000000u),
						DAYS_MASK			 = uint64(0xfffff80000000000u),

						MINUTES_SHIFT	 = 32,
						HOURS_SHIFT		 = 38,
						DAYS_SHIFT		 = 43
					}; // End [enum eTimeValueConstants]

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

					void GetTime(uint32& days, uint32& hours, uint32& minutes, float& seconds)
					{
						uint64 time = m_ticks;

						uint64 unit = TICKS_PER_SECOND*60*60*24; // ticks per day
						days = time/unit;
						time -= unit*days;

						unit /= 24; // ticks per hour
						hours = time/unit;
						time -= unit*hours;

						unit /= 60; // ticks per minute
						minutes = time/unit;
						seconds = static_cast<float>(time-(unit*minutes))/TICKS_PER_SECOND;
					}

					static double GetSeconds(uint64 ticks)
					{
						return static_cast<double>(ticks)/TICKS_PER_SECOND;
					}

				protected:
					uint64 m_ticks;

				public:
					static const uint64& TICKS_PER_SECOND;
			}; // End [class CTimeValue]

		public:
			// Get the singleton instance
//			static CTime* Get(void);
			static void Sleep(uint32 microseconds);

			static void Initialise(void);
			static CRealTimeClock& RealTimeClock(void);
			static CTimer& GameClock(void);

		protected:
//			CTime(void);
//			~CTime(void);










		protected:
			static CRealTimeClock& s_realTimeClock;
			static CTimer& s_gameTimer;
	}; // End [class CTime]

	//============================================================================
} // End [namespace engine]

//==============================================================================
#endif // End [!defined(__TIME_H__)]
// [EOF]

