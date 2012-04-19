#if !defined(__PLATFORM_STDAFX_H__)
#define __PLATFORM_STDAFX_H__

//==============================================================================

#include "common/targetver.h"
#include <windows.h>

//==============================================================================

#if defined(GetCurrentTime)
#undef GetCurrentTime
#endif

#define DEBUG_BREAK DebugBreak()

// Check for 32 or 64 bit environment
#if defined(_WIN32) || defined(_WIN64)
#if defined(_WIN64)
#define ENVIRONMENT64
#else
#define ENVIRONMENT32
#endif // [defined(_WIN64)]
#endif // [defined(_WIN32) || defined(_WIN64)]

//==============================================================================

#endif // End [!defined(__PLATFORM_STDAFX_H__)]
// [EOF]

