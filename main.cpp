#include "common/stdafx.h"

#include <GL/glfw.h>

#include "time/time.h"

#include "graphics/renderer.h"
#include "input/keyboard.h"

#include "common/console.h"
#include "common/system.h"
#include "common/log.h"
#include "common/profiling.h"

//==============================================================================

#define TEST_LENGTH (5.0)

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
#if defined(ENVIRONMENT32)
	printf("\n32 bit environment\n\n");
#endif // [defined(ENVIRONMENT32)]
#if defined(ENVIRONMENT64)
	printf("\n64 bit environment\n");
#endif // [defined(ENVIRONMENT64)]
	printf("*** Variable sizes:\n");
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
	PRINT_SIZE(size_t);
#undef PRINT_SIZE
	printf("*** End variable sizes\n\n");
}

//==============================================================================

void TimeValueTest(engine::CTime::CTimeValue value)
{
	printf("Time %06.3fs\n", value.GetSeconds());

	int32 days, hours, minutes;
	float seconds;
	value.GetTime(days, hours, minutes, seconds);

	printf("%s%d days, %02u:%02u:%06.3fs\n", (value.GetTicks() < 0) ? "-" : "",  days, hours, minutes, seconds);
}

//==============================================================================

bool TimerCallback(engine::CTime::CCallbackTimer* pTimer, void* pUserData)
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
//	DumpVariableSizes();

	// This will create and initialise the CSystem singleton
	engine::CSystem::Get();

	/*
	/////////////////////////////////////////////////////////////////////////////
	// CLog tests
	{
		engine::CLog log("Game.log");
		log.Print(engine::CLog::eLFD_FILE | engine::CLog::eLFT_APPLICATION | engine::CLog::eLFS_MESSAGE | engine::CLog::eLFB_TIMESTAMP, "This is a message with a timestamp\n");
		log.Print(engine::CLog::eLFD_FILE | engine::CLog::eLFT_APPLICATION | engine::CLog::eLFS_INFO, "This is an information message\n");
		log.Print(engine::CLog::eLFD_FILE | engine::CLog::eLFT_APPLICATION | engine::CLog::eLFS_WARN, "This is a warning message\n");
		log.Print(engine::CLog::eLFD_FILE | engine::CLog::eLFT_APPLICATION | engine::CLog::eLFS_URGENT, "This is an urgent message\n");
		log.Print(engine::CLog::eLFD_FILE | engine::CLog::eLFT_APPLICATION | engine::CLog::eLFS_ERROR, "This is an error message\n");
		log.Print(engine::CLog::eLFD_FILE | engine::CLog::eLFT_APPLICATION | engine::CLog::eLFS_FATAL, "This is a fatal message\n");
	}
	*/

	/*
	/////////////////////////////////////////////////////////////////////////////
	// CTimeValue tests
	printf("sizeof(CTime::CTimeValue) is %u bytes\n", static_cast<uint32>(sizeof(engine::CTime::CTimeValue)));
	printf("%" PRIu64 " ticks per second\n", engine::CTime::CTimeValue::TICKS_PER_SECOND);

	engine::CTime::CTimeValue value(60.0);
	TimeValueTest(value);
	value = 3600.0;
	TimeValueTest(value);
	value = 86400.0;
	TimeValueTest(value);
	value = 604800.0;
	TimeValueTest(value);
	value = -1.0;
	TimeValueTest(value);
	value = int64(DECLARE_64BIT(0x7fffffffffffffff));
	TimeValueTest(value);
	/////////////////////////////////////////////////////////////////////////////
	*/

	/*
	/////////////////////////////////////////////////////////////////////////////
	// CRealTimeClock test
	engine::CTime::CTimer& gt = engine::CTime::Get().GameTimer();
	engine::CTime::CTimeValue target(TEST_LENGTH);
	engine::CTime::CTimeValue ticker(0.0);

	while (gt.GetElapsedTime() < target)
	{
		engine::CTime::CTimeValue tick = engine::CTime::Get().Update();
		ticker += tick;

		if (ticker >= 1.0)
		{
			printf("%fs elapsed\n", gt.GetElapsedTime().GetSeconds());
			ticker -= 1.0;
		}
	}
	/////////////////////////////////////////////////////////////////////////////
	*/

	/////////////////////////////////////////////////////////////////////////////
	// callback timer and renderer test
	engine::CRenderer renderer(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT, DEFAULT_WINDOW_TITLE, DEFAULT_FRAMERATE);

	printf("Starting %.02f second test...\n", TEST_LENGTH);

	engine::CTime::CTimeValue start = engine::CTime::Get().GetCurrentTime();
	uint32 callbackTimerID = engine::CTime::Get().CreateCallbackTimer(0.1f, 1.0f, 1.0, TimerCallback, NULL);
	engine::CTime::CCallbackTimer* pCallbackTimer = engine::CTime::Get().GetCallbackTimer(callbackTimerID);

	uint32 xpos = 100;
	xpos += renderer.Print(250, xpos, 0x00ffffff, 0, "Andrew");
	xpos += renderer.Print(250, xpos, 0x00ffffff, 0, " Catlender");

	renderer.Print(300, 100, 0x00ffffff, 0, "THE QUICK BROWN FOX JUMPED OVER THE LAZY DOG");
	renderer.Print(310, 100, 0x00ffffff, 0, "the quick brown fox jumped over the lazy dog");
	renderer.Print(320, 100, 0x00ffffff, 0, "0123456789");
	renderer.Print(330, 100, 0x00ffffff, 0, " !\"#$%&\'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz");

	while (pCallbackTimer->IsActive() && !engine::CKeyboard::IsKeyPressed(GLFW_KEY_ESC))
	{
		PROFILE("main");

		engine::CTime::CTimeValue tick = engine::CTime::Get().Update();
		pCallbackTimer->Update();

		if (engine::CKeyboard::IsKeyPressed('`'))
		{
			renderer.ActivateConsole(!renderer.IsConsoleActive());
		}

		renderer.Update();
	}

	engine::CTime::CTimeValue finish = engine::CTime::Get().GetCurrentTime();
	printf("Total elapsed time %fs\n", (finish-start).GetSeconds());
	engine::CTime::Get().DestroyTimer(callbackTimerID);
	/////////////////////////////////////////////////////////////////////////////

	/*
	/////////////////////////////////////////////////////////////////////////////
	// console variables test
	uint64 test_uint64 = 0;
	REGISTER_CONSOLE_VARIABLE(test_uint64, 123, 0, "An unsigned int console variable");
	int64 test_int64 = 0;
	REGISTER_CONSOLE_VARIABLE(test_int64, -123, 0, "A signed int console variable");
	double test_floatingpoint = 0.0;
	REGISTER_CONSOLE_VARIABLE(test_floatingpoint, 123.456, 0, "A floating point console variable");

	printf("console variable: unsigned int\n");
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
		pVar->Set(uint64(789));
		printf("  value: %" PRIu64 "\n", pVar->GetUINT64());
	}

	printf("console variable: signed int\n");
	pVar = engine::CConsole::Get()->GetVariable("test_int64");
	if (pVar != NULL)
	{
		printf("Found console variable:\n");
		printf("  usage: %s\n", pVar->GetUsage());
		printf("  value: %" PRId64 "\n", pVar->GetINT64());
		printf("Setting in code to -99\n");
		test_int64 = -99;
		printf("  value: %" PRId64 "\n", pVar->GetINT64());
		printf("Setting via console variable to 789\n");
		pVar->Set(int64(789));
		printf("  value: %" PRId64 "\n", pVar->GetINT64());
	}

	printf("console variable: floating point\n");
	pVar = engine::CConsole::Get()->GetVariable("test_floatingpoint");
	if (pVar != NULL)
	{
		printf("Found console variable:\n");
		printf("  usage: %s\n", pVar->GetUsage());
		printf("  value: %f\n", pVar->GetFloatingPoint());
		printf("Setting in code to -3.14159\n");
		test_floatingpoint = -3.14159;
		printf("  value: %f\n", pVar->GetFloatingPoint());
		printf("Setting via console variable to 0.789\n");
		pVar->Set(0.789);
		printf("  value: %f\n", pVar->GetFloatingPoint());
	}


	UNREGISTER_CONSOLE_VARIABLE(test_floatingpoint);
	UNREGISTER_CONSOLE_VARIABLE(test_int64);
	UNREGISTER_CONSOLE_VARIABLE(test_uint64);
	/////////////////////////////////////////////////////////////////////////////
	*/

	LOG_PROFILING;

	printf("All done.\n");

	return 0;
}

//==============================================================================

