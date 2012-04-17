#include "common/stdafx.h"

#include <GL/glfw.h>

#include "time/time.h"
#include "time/realtimeclock.h"
#include "time/timer.h"
#include "time/callbacktimer.h"
#include "time/timevalue.h"

#include "graphics/renderer.h"
#include "input/keyboard.h"

#include "common/console.h"

//==============================================================================

#define TEST_LENGTH (10.0)

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

	if (elapsedSeconds >= TEST_LENGTH)
	{
		running = false;
	}

	return running;
}

//==============================================================================

int main(int argc, char* argv[])
{
	IGNORE_PARAMETER(argc);
	IGNORE_PARAMETER(argv);
//	DumpArgs(argc, argv);

	engine::CTime::Initialise();
	engine::CRenderer renderer(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT, DEFAULT_WINDOW_TITLE, DEFAULT_FRAMERATE);
	engine::CKeyboard::Initialise();

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

	uint32 xpos = 100;
	xpos += renderer.Print(100, xpos, 0x00ffffff, 0, "Andrew");
	xpos += renderer.Print(100, xpos, 0x00ffffff, 0, " Catlender");

	renderer.Print(200, 100, 0x00ffffff, 0, "THE QUICK BROWN FOX JUMPED OVER THE LAZY DOG");
	renderer.Print(210, 100, 0x00ffffff, 0, "the quick brown fox jumped over the lazy dog");
	renderer.Print(220, 100, 0x00ffffff, 0, "0123456789");
	renderer.Print(230, 100, 0x00ffffff, 0, " !\"#$%&\'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz");

	uint64 test_uint64 = 0;
	REGISTER_CONSOLE_VARIABLE("test_uint64", test_uint64, 123, 0, "An unsigned int console variable");

	engine::CConsole::SVariable* pVar = engine::CConsole::Get()->GetVariable("test_uint64");
	if (pVar != NULL)
	{
		printf("Found console variable:\n");
		printf("  usage: %s\n", pVar->GetUsage());
		printf("  value: %" PRIu64 "\n", pVar->GetUINT64());
		printf("Setting in code to 99\n");
		test_uint64 = 99;
		printf("  value: %" PRIu64 "\n", pVar->GetUINT64());
		printf("Setting via console variable to 789\n");
		pVar->Set(789ull);
		printf("  value: %" PRIu64 "\n", pVar->GetUINT64());
	}

	while (ct.IsActive() && !engine::CKeyboard::IsKeyPressed(GLFW_KEY_ESC))
	{
		ct.Tick();
		if (engine::CKeyboard::IsKeyPressed('`')) renderer.ActivateConsole(!renderer.IsConsoleActive());
		renderer.Update();
	}

	UNREGISTER_CONSOLE_VARIABLE("test_uint64");

	engine::CTimeValue finish = rtc.GetCurrentTime();
	printf("Total elapsed time %fs\n", (finish-start).GetSeconds());
	printf("All done.\n");

	return 0;
}

//==============================================================================

