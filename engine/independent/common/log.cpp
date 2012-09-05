#include "common/stdafx.h"
#include <stdarg.h>

#include "common/log.h"
#include "common/filesystem.h"
#include "time/time.h"

//==============================================================================

#if defined(ERROR)
// Needed because Win32 defines ERROR in wingdi.h, included through windows.h
#undef ERROR
#endif // defined(ERROR)

#define FATAL		ANSI_1SEQUENCE(ANSI_COLOUR(ANSI_YELLOW, ANSI_RED))
#define ERROR		ANSI_1SEQUENCE(ANSI_FOREGROUND(ANSI_RED))
#define URGENT	ANSI_1SEQUENCE(ANSI_FOREGROUND(ANSI_MAGENTA))
#define WARN		ANSI_1SEQUENCE(ANSI_FOREGROUND(ANSI_YELLOW))
#define INFO		ANSI_1SEQUENCE(ANSI_FOREGROUND(ANSI_GREEN))
#define MESSAGE ANSI_1SEQUENCE(ANSI_FOREGROUND(ANSI_DEFAULT_COLOUR))
#define FIXME		ANSI_1SEQUENCE(ANSI_COLOUR(ANSI_YELLOW, ANSI_BLACK))
#define RESET		ANSI_1SEQUENCE(ANSI_RESET_ALL)

//==============================================================================

namespace engine
{
	//============================================================================

	CLog::CLog(const char* fileName, uint32 flags)
		: m_flags(flags)
		,	m_fileName(fileName)
		, m_fileHandle(CFileSystem::eC_INVALID_FILE_HANDLE)
	{
		if (m_flags & eLFD_FILE)
		{
			m_fileHandle = CFileSystem::Get().Open(m_fileName, "w");
		}
	}

	//============================================================================

	CLog::~CLog(void)
	{
		Print(eLFD_RELEASE | eLFT_ALL | eLFS_MESSAGE | eLFB_TIMESTAMP, "[EOF]\n");

		if (m_fileHandle != CFileSystem::eC_INVALID_FILE_HANDLE)
		{
			CFileSystem::Get().Close(m_fileHandle);
			m_fileHandle = CFileSystem::eC_INVALID_FILE_HANDLE;
		}
	}

	//============================================================================

	void CLog::Print(uint32 flags, const char* format, ...)
	{
		if ( (((m_flags & eLFB_ACTIVE) == 0) || (m_flags & flags & eLFD_ALL) == 0) || ((m_flags & flags & eLFT_ALL) == 0) || ((m_flags & flags & eLFS_ALL) == 0) || false /* check systems flags here */)
		{
			return;
		}

		// N.B. Need a mutex here

		static char buffer[LOG_BUFFER_SIZE];
		int32 index = 0;
		int32 charsWritten = 0;

		switch (m_flags & flags & eLFS_ALL)
		{
			case eLFS_FATAL:
				index += sprintf(&buffer[index], RESET FATAL);
				break;
			case eLFS_ERROR:
				index += sprintf(&buffer[index], RESET ERROR);
				break;
			case eLFS_URGENT:
				index += sprintf(&buffer[index], RESET URGENT);
				break;
			case eLFS_WARN:
				index += sprintf(&buffer[index], RESET WARN);
				break;
			case eLFS_INFO:
				index += sprintf(&buffer[index], RESET INFO);
				break;
			case eLFS_MESSAGE:
				index += sprintf(&buffer[index], RESET MESSAGE);
				break;
			default:
				index += sprintf(&buffer[index], RESET FIXME);
				break;
		}

		if (m_flags & flags & eLFB_TIMESTAMP)
		{
			CTime::CTimeValue now = CTime::Get().GetCurrentTime();
			int32 days, hours, minutes;
			float seconds;

			now.GetTime(days, hours, minutes, seconds);
			index += sprintf(&buffer[index], "[%02u:%02u:%06.3f] : ", hours, minutes, seconds);
		}

		va_list args;
		va_start(args, format);
		charsWritten = vsprintf(&buffer[index], format, args);
		va_end(args);

		index += charsWritten;
		if ((charsWritten < 0) || (index >= LOG_BUFFER_SIZE))
		{
			FATAL_ERROR(FATAL "CLog::Print() : buffer over-run!" RESET "\n");
		}

		if (m_flags & flags & eLFD_FILE)
		{
			CFileSystem::Get().Write(m_fileHandle, buffer, index);
		}

		if (m_flags & flags & eLFD_CONSOLE)
		{
			// TODO: write to the console
		}

		if (m_flags & flags & eLFD_STDOUT)
		{
			fwrite(buffer, index, 1, stdout);
		}

		if (m_flags & flags & eLFD_STDERR)
		{
			fwrite(buffer, index, 1, stderr);
		}
	}

	//============================================================================

	uint32 CLog::SetFlags(uint32 flags)
	{
		uint32 originalFlags = m_flags;
		m_flags |= flags;
		return originalFlags;
	}

	//============================================================================

	uint32 CLog::ResetFlags(uint32 flags)
	{
		uint32 originalFlags = m_flags;
		m_flags &= ~flags;
		return originalFlags;
	}

	//============================================================================

	uint32 CLog::GetFlags(void) const
	{
		return m_flags;
	}

	//============================================================================
} // End [namespace engine]

//==============================================================================
// [EOF]

