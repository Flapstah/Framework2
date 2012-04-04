#include "common/stdafx.h"

#include <GL/glfw.h>

#include "time/time.h"
#include "time/realtimeclock.h"
#include "time/timer.h"
#include "time/callbacktimer.h"
#include "time/timevalue.h"

#include "graphics/display.h"
#include "input/keyboard.h"

#define WINDOW_WIDTH (640)
#define WINDOW_HEIGHT (400)

#define DESIRED_FRAMERATE (10.0)
#define FRAME_INTERVAL (1.0/DESIRED_FRAMERATE)
engine::CTimeValue g_FrameInterval; // cannot set before CTime::Initialise()

//==============================================================================

void DumpArgs(int argc, char* argv[])
{
	printf("*** Passed %d arguments:\n", argc);
	for (int i = 0; i < argc; ++i)
	{
		printf("[%d] [%s]\n", i, argv[i]);
	}
	printf("*** End argument list\n");
}

//==============================================================================

void DumpVariableSizes(void)
{
	printf("*** Variable sizes\n");
#define PRINT_SIZE(_type_) printf(#_type_ "\t: %u\n", static_cast<uint32>(sizeof(_type_)))
	PRINT_SIZE(int8);
	PRINT_SIZE(int16);
	PRINT_SIZE(int32);
	PRINT_SIZE(int64);
	PRINT_SIZE(uint8);
	PRINT_SIZE(uint16);
	PRINT_SIZE(uint32);
	PRINT_SIZE(uint64);
	PRINT_SIZE(bool);
	PRINT_SIZE(float);
	PRINT_SIZE(double);
#undef PRINT_SIZE
	printf("*** End variable sizes\n");
}

//==============================================================================

void TimeValueTest(double seconds)
{
	engine::CTimeValue tv(seconds);
	printf("Time %06.3fs\n", tv.GetSeconds());
	uint64 time = tv.GetTime();
	printf("%" PRIu64 " days, %02" PRIu64 ":%02" PRIu64 ":%06.3fs\n",
		 	(time & DAYS_MASK) >> DAYS_SHIFT,
		 	(time & HOURS_MASK) >> HOURS_SHIFT,
		 	(time & MINUTES_MASK) >> MINUTES_SHIFT,
		 	engine::CTimeValue::GetSeconds(time & SECONDS_MASK));
}

//==============================================================================

bool TimerCallback(engine::CCallbackTimer* pTimer, void* pUserData)
{
	IGNORE_PARAMETER(pUserData);

	double elapsedSeconds = (pTimer->GetElapsedTime()).GetSeconds();
	bool running = true;

	printf("%fs elapsed\n", elapsedSeconds);

	if (elapsedSeconds >= 5.0)
	{
		running = false;
	}

	return running;
}

//==============================================================================

class CRenderer
{
	public:
	CRenderer(void)
		: m_display(WINDOW_WIDTH, WINDOW_HEIGHT, "Framework test")
		, m_timer(engine::CTime::RealTimeClock(), g_FrameInterval, 1.0f, FRAME_INTERVAL, Callback, this)
	{
		for (uint32 i = 0; i < WINDOW_WIDTH*WINDOW_HEIGHT; ++i)
		{
			m_screen[i] = 0x00ff0000;
		}
	}

	~CRenderer(void)
	{
	}

	void Update(void)
	{
		m_timer.Tick();
	}

	protected:
	static bool Callback(engine::CCallbackTimer* pTimer, void* pUserData)
	{
		CRenderer* pThis = reinterpret_cast<CRenderer*>(pUserData);

		pThis->m_display.Update(&pThis->m_screen);

		return true;
	}

	protected:
	engine::CDisplay m_display;
	engine::CCallbackTimer m_timer;
	uint32 m_screen[WINDOW_WIDTH*WINDOW_HEIGHT];
};

//==============================================================================

int main(int argc, char* argv[])
{
	IGNORE_PARAMETER(argc);
	IGNORE_PARAMETER(argv);
//	DumpArgs(argc, argv);

	engine::CKeyboard::Initialise();
	engine::CTime::Initialise();

	g_FrameInterval = FRAME_INTERVAL;

	CRenderer renderer;

	printf("Starting 5 second test...\n");

	/*
	printf("sizeof(CTimeValue) is %d\n", sizeof(engine::CTimeValue));

	TimeValueTest(60.0);
	TimeValueTest(3600.0);
	TimeValueTest(86400.0);
	TimeValueTest(604800.0);

	engine::CTimeValue tv(0xffffffffffffffffull);
	printf("Time %06.3fs\n", tv.GetSeconds());
	uint64 time = tv.GetTime();
	printf("%" PRIu64 " days, %02" PRIu64 ":%02" PRIu64 ":%06.3fs\n",
		 	(time & DAYS_MASK) >> DAYS_SHIFT,
		 	(time & HOURS_MASK) >> HOURS_SHIFT,
		 	(time & MINUTES_MASK) >> MINUTES_SHIFT,
		 	engine::CTimeValue::GetSeconds(time & SECONDS_MASK));
	*/

	/*
	engine::CRealTimeClock& rtc = engine::CTime::RealTimeClock();
	engine::CTimer& gc = engine::CTime::GameClock();
	engine::CTimeValue elapsed(0.0);
	engine::CTimeValue target(5.0);
	engine::CTimeValue ticker(0.0);

	while (elapsed < target)
	{
		rtc.Tick();
		engine::CTimeValue tick = gc.Tick();
		ticker += tick;
		elapsed += tick;

		if (ticker >= 1.0)
		{
			printf("%fs elapsed\n", elapsed.GetSeconds());
			ticker -= 1.0;
		}
	}
	*/

	engine::CRealTimeClock& rtc = engine::CTime::RealTimeClock();
	engine::CTimeValue start = rtc.GetCurrentTime();
	engine::CTimeValue maxFrameTime(0.1);
	engine::CCallbackTimer ct(rtc, maxFrameTime, 1.0f, 1.0, TimerCallback, NULL);

	while (ct.IsActive())
	{
		ct.Tick();
		renderer.Update();
	}

	engine::CTimeValue finish = rtc.GetCurrentTime();
	printf("Total elapsed time %fs (start %f, end %f)\n", (finish-start).GetSeconds(), start.GetSeconds(), finish.GetSeconds());
	printf("All done.\n");
	return 0;
}

//==============================================================================

