#if !defined(__TIME_H__)
#define __TIME_H__

//==============================================================================

namespace engine
{
	//============================================================================

	class CTimer;

	//============================================================================
	// CTime
	//============================================================================
	class CTime
	{
		public:
			//========================================================================
			// CTimeValue
			//========================================================================
			class CTimeValue
			{
				public:
					enum eConstants
					{
						SECONDS_MASK	 = DECLARE_64BIT(0x00000000ffffffffu),
						MINUTES_MASK	 = DECLARE_64BIT(0x0000003f00000000u),
						HOURS_MASK		 = DECLARE_64BIT(0x000007c000000000u),
						DAYS_MASK			 = DECLARE_64BIT(0xfffff80000000000u),

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

			//========================================================================
			// CTimer
			//========================================================================
			class CTimer
			{
				public:
					CTimer(float maxFrameTime, float scale)
						: m_pParent(NULL)
						, m_maxFrameTime(maxFrameTime)
						, m_scale(scale)
					{
					}

					CTimer(CTimer& parent, float maxFrameTime, float scale)
						: m_pParent(&parent)
						, m_maxFrameTime(maxFrameTime)
						, m_scale(scale)
					{
					}

					~CTimer(void)
					{
					}

					CTimeValue GetCurrentTime(void) const
					{
						return m_timeNow;
					}

					CTimeValue GetElapsedTime(void) const
					{
						return m_timeElapsed;
					}

					CTimeValue GetFrameTime(void) const
					{
						return (m_timeNow-m_timeLast);
					}

					void SetScale(float scale)
					{
						m_scale = scale;
					}

					float GetScale(void) const
					{
						return m_scale;
					}

					// TODO: deal with pausing

					const CTimeValue Update(void)
					{
						m_timeLast = m_timeNow;
						m_timeNow = (m_pParent == NULL) ? CTime::Get().GetCurrentTime() : m_pParent->GetCurrentTime();

						CTimeValue frameTime = GetFrameTime();
						if (frameTime.GetSeconds() > m_maxFrameTime)
						{
							m_timeLast = m_timeNow-CTimeValue(m_maxFrameTime);
						}

						m_timeElapsed += frameTime;
						return frameTime;
					}

					void Reset(void)
					{
						m_timeNow = (m_pParent == NULL) ? CTime::Get().GetCurrentTime() : m_pParent->GetCurrentTime();
						m_timeLast = m_timeNow;
						m_timeElapsed = uint64(DECLARE_64BIT(0));
					}

				protected:
					CTimer* m_pParent;
					CTimeValue m_timeNow;
					CTimeValue m_timeLast;
					CTimeValue m_timeElapsed;
					float m_maxFrameTime;
					float m_scale;
					bool m_paused;
			}; // End [class CTimer]

		public:
			// Get the singleton instance
//			static CTime* Get(void);
			static void Sleep(uint32 microseconds);

			static CTime& Get(void)
			{
				static CTime instance;
				return instance;
			}
			~CTime(void);

			CTimer& GameClock(void)
			{
				return m_gameTimer;
			}

			const CTimeValue GetCurrentTime(void) const
			{
				return Platform_GetCurrentTime();
			}

		protected:
			CTime(void);

			void Initialise(void);
			void Platform_Initialise(void);
			const CTimeValue Platform_GetCurrentTime(void) const;

		protected:
			CTimer m_gameTimer;
	}; // End [class CTime]

	//============================================================================
} // End [namespace engine]

//==============================================================================
#endif // End [!defined(__TIME_H__)]
// [EOF]

