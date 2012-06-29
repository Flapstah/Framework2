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
				// Destination
				// .... .... .... .... .... .... .... DDDD
				eLFD_FILE							= 1 << 0,
				eLFD_CONSOLE					= 1 << 1,
				eLFD_STDOUT						= 1 << 2,
				eLFD_STDERR						= 1 << 3,

				eLFD_RELEASE					= eLFD_FILE | eLFD_CONSOLE,
				eLFD_DEBUG						= eLFD_FILE | eLFD_CONSOLE | eLFD_STDERR,
				eLFD_ALL							= eLFD_FILE | eLFD_CONSOLE | eLFD_STDOUT | eLFD_STDERR,

				// Type
				// .... .... .... .... .... .... TTTT ....
				eLFT_OPERATING_SYSTEM	= 1 << 4,
				eLFT_ENGINE						= 1 << 5,
				eLFT_APPLICATION			= 1 << 6,
				eLFT_USER							= 1 << 7,

				eLFT_RELEASE					= eLFT_OPERATING_SYSTEM | eLFT_ENGINE | eLFT_APPLICATION,
				eLFT_DEBUG						= eLFT_OPERATING_SYSTEM | eLFT_ENGINE | eLFT_APPLICATION | eLFT_USER,
				eLFT_ALL							= eLFT_OPERATING_SYSTEM | eLFT_ENGINE | eLFT_APPLICATION | eLFT_USER,

				// Severity
				// .... .... .... .... ..SS SSSS .... ....
				eLFS_FATAL						= 1 << 8,
				eLFS_ERROR						= 1 << 9,
				eLFS_URGENT						= 1 << 10,
				eLFS_WARN							= 1 << 11,
				eLFS_INFO							= 1 << 12,
				eLFS_MESSAGE					= 1 << 13,

				eLFS_RELEASE					= eLFS_FATAL | eLFS_ERROR,
				eLFS_DEBUG						= eLFS_FATAL | eLFS_ERROR | eLFS_URGENT | eLFS_WARN | eLFS_INFO | eLFS_MESSAGE,
				eLFS_ALL							= eLFS_FATAL | eLFS_ERROR | eLFS_URGENT | eLFS_WARN | eLFS_INFO | eLFS_MESSAGE,

				// Behaviour
				// .... .... .... .... BB.. .... .... ....
				eLFB_ACTIVE						= 1 << 14,
				eLFB_TIMESTAMP				= 1 << 15,

				eLFB_DEBUG						= eLFB_ACTIVE | eLFB_TIMESTAMP,
				eLFB_RELEASE					= eLFB_ACTIVE | eLFB_TIMESTAMP,
				eLFB_ALL							= eLFB_ACTIVE | eLFB_TIMESTAMP,

				// System
				// .... .... .... ...A .... .... .... ....
				eLFX_TIME							= 1 << 16,
				// ...more systems here

				eLF_DEFAULT =
#if !defined (_RELEASE)
					eLFD_DEBUG | eLFT_DEBUG | eLFS_DEBUG | eLFB_ALL
#else
					eLFD_RELEASE | eLFT_RELEASE | eLFS_DEBUG | eLFB_ALL
#endif // !defined (_RELEASE)
			}; // End [enum eLogFlags]

			CLog(const char* fileName, uint32 flags = eLF_DEFAULT);
			~CLog(void);

			void Print(uint32 flags, const char* format, ...);

			uint32 SetFlags(uint32 flags);
			uint32 ResetFlags(uint32 flags);
			uint32 GetFlags(void) const;

		protected:
			uint32 m_flags;
			const char* m_fileName;
			uint32 m_fileHandle;
	}; // End [class CLog]
	//============================================================================

} // End [namespace engine]

//==============================================================================
#endif // End [!defined(__LOG_H__)]
// [EOF]

