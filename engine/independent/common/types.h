#if !defined(__PLATFORM_TYPES_H__)
#define __PLATFORM_TYPES_H__

//==============================================================================

#include <stdint.h> // for intX_t
#include <cstring>	// for size_t
#if !defined(_WIN32)
// Need this macro for C++ (ISO C99 standard)
#define __STDC_FORMAT_MACROS
#include <inttypes.h> // for PRIu64 for printf(), etc. 
#else
#define PRIX64 "I64X"
#define PRIx64 "I64x"
#define PRId64 "I64d"
#define PRIu64 "I64u"
#endif // !defined(_WIN32)

//==============================================================================

typedef int8_t	  int8;
typedef int16_t	  int16;
typedef int32_t	  int32;
typedef int64_t	  int64;

typedef uint8_t   uint8;
typedef uint16_t  uint16;
typedef uint32_t  uint32;
typedef uint64_t  uint64;

template <size_t _size>
union mchar_t
{
	wchar_t	m_UTF16[_size];
	char		m_UTF8[_size * sizeof(wchar_t)];
};

//==============================================================================

#endif // End [!defined(__PLATFORM_TYPES_H__)]
// [EOF]

