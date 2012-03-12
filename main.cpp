#include "common/stdafx.h"

#include <GL/glfw.h>

#include "time/time.h"

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

int main(int argc, char* argv[])
{
//	IGNORE_PARAMETER(argc);
//	IGNORE_PARAMETER(argv);
	DumpArgs(argc, argv);

	engine::CTime::Init();

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
	return 0;
}

//==============================================================================

