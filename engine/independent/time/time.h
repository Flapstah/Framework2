#if !defined(__TIME_H__)
#define __TIME_H__

//==============================================================================

#include <list>
#include <vector>

//==============================================================================

namespace engine
{
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
						INVALID_TIME	 = DECLARE_64BIT(0xf000000000000000),
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

					explicit CTimeValue(int64 ticks)
						: m_ticks(ticks)
					{
					}

					explicit CTimeValue(double seconds)
						: m_ticks(static_cast<int64>(seconds*TICKS_PER_SECOND))
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
						m_ticks = static_cast<int64>(seconds*TICKS_PER_SECOND);
						return *this;
					}

					CTimeValue& operator=(int64 ticks)
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
						m_ticks += static_cast<int64>(seconds*TICKS_PER_SECOND);
						return *this;
					}

					CTimeValue& operator+=(int64 ticks)
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
						m_ticks -= static_cast<int64>(seconds*TICKS_PER_SECOND);
						return *this;
					}

					CTimeValue& operator-=(int64 ticks)
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

					const CTimeValue operator+(int64 ticks) const
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

					const CTimeValue operator-(int64 ticks) const
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
						return (m_ticks == static_cast<int64>(seconds*TICKS_PER_SECOND));
					}

					bool operator==(int64 ticks) const
					{
						return (m_ticks == ticks);
					}

					bool operator!=(const CTimeValue& other) const
					{
						return (m_ticks != other.m_ticks);
					}

					bool operator!=(double seconds) const
					{
						return (m_ticks != static_cast<int64>(seconds*TICKS_PER_SECOND));
					}

					bool operator!=(int64 ticks) const
					{
						return (m_ticks != ticks);
					}

					bool operator<(const CTimeValue& other) const
					{
						return (m_ticks < other.m_ticks);
					}

					bool operator<(double seconds) const
					{
						return (m_ticks < seconds*TICKS_PER_SECOND);
					}

					bool operator<(int64 ticks) const
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

					bool operator<=(int64 ticks) const
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

					bool operator>(int64 ticks) const
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

					bool operator>=(int64 ticks) const
					{
						return (m_ticks >= ticks);
					}

					double GetSeconds(void) const
					{
						return static_cast<double>(m_ticks)/TICKS_PER_SECOND;
					}

					int64 GetTicks(void) const
					{
						return m_ticks;
					}

					int64 GetTime(void) const
					{
						int64 time = m_ticks;

						int64 unit = TICKS_PER_SECOND*60*60*24; // ticks per day
						int64 days = time/unit;
						time -= days*unit;

						unit /= 24; // ticks per hour
						int64 hours = time/unit;
						time -= hours*unit;

						unit /= 60; // ticks per minute
						int64 minutes = time/unit;
						time -= minutes*unit;

						time |= (days<<DAYS_SHIFT) | (hours<<HOURS_SHIFT) | (minutes<<MINUTES_SHIFT);
						return time;
					}

					void GetTime(int32& days, int32& hours, int32& minutes, float& seconds)
					{
						// To prevent the user from having to test the signs of the parameters
						// upon return, time is made absolute by two's complement.  The sign
						// can always be tested by GetTicks()
						int64 time = m_ticks;
						int64 mask = m_ticks >> 63;
						time = (time ^ mask) - mask;

						int64 unit = TICKS_PER_SECOND*60*60*24; // ticks per day
						days = time/unit;
						time -= unit*days;

						unit /= 24; // ticks per hour
						hours = time/unit;
						time -= unit*hours;

						unit /= 60; // ticks per minute
						minutes = time/unit;
						seconds = static_cast<float>(time-(unit*minutes))/TICKS_PER_SECOND;
					}

					static double GetSeconds(int64 ticks)
					{
						return static_cast<double>(ticks)/TICKS_PER_SECOND;
					}

				protected:
					int64 m_ticks;

				public:
					static const int64& TICKS_PER_SECOND;
			}; // End [class CTimeValue]
			//========================================================================

			//========================================================================
			// CTimer
			//========================================================================
			class CTimer
			{
				friend class CTime;

				public:
					enum eDefaultValues
					{
						eDV_SCALE = 1,
						eDV_RECIPROCALMAXFRAMETIME = 10
					}; // End [enum eDefaultValues]

				protected:
					CTimer(void)
						: m_pParent(NULL)
						, m_maxFrameTime(1.0f/eDV_RECIPROCALMAXFRAMETIME)
						, m_scale(eDV_SCALE)
					{
					}

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

				public:
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

					float GetMaxFrameTime(void) const
					{
						return m_maxFrameTime;
					}

					void SetMaxFrameTime(float maxFrameTime)
					{
						m_maxFrameTime = maxFrameTime;
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
						Reset((m_pParent == NULL) ? CTime::Get().GetCurrentTime() : m_pParent->GetCurrentTime());
					}

					void Reset(const CTimeValue& when)
					{
						m_timeNow = when;
						m_timeLast = m_timeNow;
						m_timeElapsed = DECLARE_64BIT(0);
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
			//========================================================================

			//========================================================================
			// CCallbackTimer
			//========================================================================
			class CCallbackTimer : public CTimer
			{
				friend class CTime;
				typedef CTime::CTimer PARENT;

				public:
				typedef bool (*Callback)(CCallbackTimer*, void*);

				protected:
				CCallbackTimer(void)
					: m_interval(0.0)
						, m_pCallback(NULL)
					, m_pUserData(NULL)
					, m_active(false)
				{
				}

				CCallbackTimer(float maxFrameTime, float scale, double intervalInSeconds, Callback pCallback, void* const pUserData)
					: CTimer(maxFrameTime, scale)
						, m_interval(intervalInSeconds)
						 , m_pCallback(pCallback)
						 , m_pUserData(pUserData)
						 , m_active(true)
				{
					Reset();
				}

				CCallbackTimer(CTime::CTimer& parent, float maxFrameTime, float scale, double intervalInSeconds, Callback pCallback, void* const pUserData)
					: CTimer(parent, maxFrameTime, scale)
						, m_interval(intervalInSeconds)
						 , m_pCallback(pCallback)
						 , m_pUserData(pUserData)
						 , m_active(true)
				{
					Reset();
				}

				~CCallbackTimer(void)
				{
				}

				public:
				// CTimer
				virtual const CTime::CTimeValue Update(void)
				{
					if (m_active)
					{
						m_ticker += PARENT::Update();

						if (m_ticker >= m_interval)
						{
							m_active = m_pCallback(this, m_pUserData);
							m_ticker -= m_interval;
						}
					}

					return PARENT::GetFrameTime();
				}
				// ~CTimer

				void SetInterval(CTime::CTimeValue interval)
				{
					m_interval = interval;
				}

				void SetInterval(double intervalInSeconds)
				{
					m_interval = intervalInSeconds;
				}

				const CTime::CTimeValue& GetInterval(void)
				{
					return m_interval;
				}

				bool IsActive(void) const
				{
					return m_active;
				}

				protected:
				CTimeValue m_interval;
				CTimeValue m_ticker;
				Callback m_pCallback;
				// TODO: really want m_pUserData to be void* const but default copy
				// constructor can't cope
				void* m_pUserData;
				bool m_active;
			}; // End [class CCallbackTimer]
			//========================================================================

		public:
			SINGLETON(CTime);
			~CTime(void);

			static void Sleep(uint32 microseconds);

			const CTimeValue Update(void)
			{
				CTimeValue gameFrameTime = GameTimer().Update();

				return gameFrameTime;
			}
			
			// Callback stuff
			enum eConstants
			{
				GAME_TIMER = 0,
				INVALID_TIMER_ID = 0xffffffff
			};

			uint32 CreateTimer(float maxFrameTime, float scale);
			uint32 CreateTimer(CTime::CTimer& parent, float maxFrameTime, float scale);
			uint32 CreateCallbackTimer(float maxFrameTime, float scale, double intervalInSeconds, CTime::CCallbackTimer::Callback pCallback, void* const pUserData);
			uint32 CreateCallbackTimer(CTime::CTimer& parent, float maxFrameTime, float scale, double intervalInSeconds, CTime::CCallbackTimer::Callback pCallback, void* const pUserData);
			CTimer* GetTimer(uint32 timerID);
			CCallbackTimer* GetCallbackTimer(uint32 timerID);
			bool DestroyTimer(uint32 timerID);

			CTimer& GameTimer(void)
			{
				return *GetTimer(GAME_TIMER);
			}

			const CTimeValue GetCurrentTime(void) const
			{
				return Platform_GetCurrentTime();
			}

		protected:
			void Initialise(void);
			void Platform_Initialise(void);
			const CTimeValue Platform_GetCurrentTime(void) const;

			struct STimerContainer
			{
				STimerContainer(void) : m_type(eT_None) {}
				~STimerContainer(void)
				{
					switch (m_type)
					{
						case eT_Timer:
							reinterpret_cast<CTimer*>(&m_timer)->~CTimer();
							break;
						case eT_CallbackTimer:
							reinterpret_cast<CCallbackTimer*>(&m_callbackTimer)->~CCallbackTimer();
							break;
						default:
							// Nothing to do here
							break;
					}
					m_type = eT_None;
				}

				enum eType
				{
					eT_None,
					eT_Timer,
					eT_CallbackTimer,

					eT_MAX
				};

				union
				{
					uint8 m_timer[sizeof(CTimer)];
					uint8 m_callbackTimer[sizeof(CCallbackTimer)];
				};

				eType m_type;
			};

			typedef std::vector<STimerContainer> TTimerVector;
			TTimerVector m_timers;
			typedef std::list<uint32> TTimerUpdateOrder;
			TTimerUpdateOrder m_timerUpdateOrder;
			uint32 GetFreeTimerID(void);
	}; // End [class CTime]

	//============================================================================
} // End [namespace engine]

//==============================================================================
#endif // End [!defined(__TIME_H__)]
// [EOF]

