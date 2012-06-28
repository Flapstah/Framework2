#if !defined(__FILESYSTEM_H__)
#define __FILESYSTEM_H__

//==============================================================================

namespace engine
{
	//============================================================================
	// CFileSystem
	//============================================================================
	class CFileSystem
	{
		protected:
			CFileSystem(void);
			CFileSystem(const CFileSystem& original);
			CFileSystem& operator=(const CFileSystem& rhs);

		public:
			~CFileSystem(void);

			static CFileSystem& Get(void);

			static bool Exists(const char* filename);
			static bool Remove(const char* fileName);
			static bool Rename(const char* oldFileName, const char* newFileName);

			uint32 Open(const char* fileSpec, const char* mode);
			bool Flush(uint32 handle);
			bool Close(uint32 handle);

			enum EConstants
			{
				eC_INVALID_FILE_HANDLE = FILESYSTEM_MAX_HANDLES
			}; // End [EConstants]

		protected:
			struct SFileHandle
			{
				FILE* m_handle;
#if defined(_DEBUG)
				char m_nameBuffer[FILESYSTEM_MAX_STORED_NAME_LENGTH];
#endif // defined(_DEBUG)
			} m_fileHandle[FILESYSTEM_MAX_HANDLES];

	}; // End [class CFileSystem]
	//============================================================================

} // End [namespace engine]

//==============================================================================
#endif // End [!defined(__FILESYSTEM_H__)]
// [EOF]


