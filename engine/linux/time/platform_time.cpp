#include "common/stdafx.h"

#include <unistd.h>			// usleep
#include <sys/time.h>		// gettimeofday

#include "time/time.h"

//==============================================================================

namespace engine
{
	//============================================================================

	void CTime::Sleep(uint32 microseconds)
	{
		::usleep(microseconds);
	}

	//============================================================================
} // End [namespace engine]

//==============================================================================
// [EOF]
