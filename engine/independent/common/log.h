#if !defined(__LOG_H__)
#define __LOG_H__

//==============================================================================

namespace engine
{
	//============================================================================
	// CLog
	//============================================================================
	class CLog
	{
		public:
			enum eLogFlags
			{
				// .... .... .... .... .... ASSS TTBB DDDD

				// Destination (4 bits, independent flags)
				// .... .... .... .... .... .... .... DDDD
				eLFD_FILE							= 1 << 0,
				eLFD_CONSOLE					= 1 << 1,
				eLFD_STDOUT						= 1 << 2,
				eLFD_STDERR						= 1 << 3,

				// Behaviour (2 bits, independent flags)
				// .... .... .... .... .... .... ..BB ....
				eLFB_ACTIVE						= 1 << 4,
				eLFB_TIMESTAMP				= 1 << 5,

				// Type (2 bits, enumeration)
				// .... .... .... .... .... .... TT.. ....
				eLFT_SHIFT						= 6,
				eLFT_MASK							= 0x03 << eLFT_SHIFT,

				eLFT_OPERATING_SYSTEM	= 0,
				eLFT_ENGINE,
				eLFT_APPLICATION,
				ELFT_USER,

				// Severity (3 bits, enumeration)
				// .... .... .... .... .... .SSS .... ....
				eLFS_SHIFT						= 8,
				eLFS_MASK							= 0x07 << eLFS_SHIFT,

				eLF_FATAL							= 0,
				eLF_ERROR,
				eLF_URGENT,
				eLF_WARN,
				eLF_INFO,
				eLF_DEBUG,

				// Area (? bits, enumeration)
				// .... .... .... .... .... A... .... ....
				eLFA_SHIFT						= 11,
				eLFA_MASK							= 0x07 << eLFX_SHIFT,

				eLFA_TIME							= 0
				// ...more systems here
			}; // End [enum eLogFlags]

			CLog(const char* fileName);
			~CLog(void);

			Print(uint32 flags, const char* format, ...);

			SetFlags(uint32 flags);
			uint32 GetFlags(void) const;

		protected:
			uint32 m_flags;
			const char* m_fileName;
			FILE* m_pFile;
	}; // End [class CLog]
	//============================================================================

} // End [namespace engine]

//==============================================================================
#endif // End [!defined(__LOG_H__)]
// [EOF]

