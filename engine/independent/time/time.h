#if !defined(__TIME_H__)
#define __TIME_H__

//==============================================================================

namespace engine
{
	class CRealTimeClock;
	class CTimer;

	//============================================================================
	// CTime
	//============================================================================
	class CTime
	{
		public:
		static void Init(void);
		static void Sleep(uint32 microseconds);
		static CRealTimeClock& RealTimeClock(void);
		static CTimer& GameClock(void);

	protected:
		static CRealTimeClock& s_realTimeClock;
		static CTimer& s_gameTimer;
	}; // End [class CTime]

	//============================================================================
} // End [namespace engine]

//==============================================================================
#endif // End [!defined(__TIME_H__)]
// [EOF]

