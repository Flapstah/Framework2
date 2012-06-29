#include "common/stdafx.h"

#include "common/filesystem.h"

//==============================================================================

namespace engine
{
	//============================================================================

	CFileSystem::CFileSystem(void)
	{
		for (uint32 index = 0; index < FILESYSTEM_MAX_HANDLES; ++index)
		{
			m_fileHandle[index].m_handle = NULL;
		}
	}

	//============================================================================

	CFileSystem::~CFileSystem(void)
	{
		// Flush all open files
		fflush(NULL);

		for (uint32 index = 0; index < FILESYSTEM_MAX_HANDLES; ++index)
		{
			if (m_fileHandle[index].m_handle != NULL)
			{
#if defined(_DEBUG)
				printf("[CFileSystem] file [%s] (handle %d) still open at exit\n", m_fileHandle[index].m_name, index);
#else
				printf("[CFileSystem] file handle %d still open at exit\n", index);
#endif // defined(_DEBUG)
			}
		}
	}

	//============================================================================

	CFileSystem& CFileSystem::Get(void)
	{
		static CFileSystem instance;
		return instance;
	}

	//============================================================================

	bool CFileSystem::Exists(const char* fileName)
	{
		bool exists = false;

		FILE* pFile = fopen(fileName, "rb");
		if (pFile != NULL)
		{
			fclose(pFile);
			exists = true;
		}

		return exists;
	}

	//============================================================================

	bool CFileSystem::Remove(const char* fileName)
	{
		bool removed = (remove(fileName) == 0);
		return removed;
	}

	//============================================================================

	bool CFileSystem::Rename(const char* oldFileName, const char* newFileName)
	{
		bool renamed = (rename(oldFileName, newFileName) == 0);
		return renamed;
	}

	//============================================================================

	uint32 CFileSystem::Open(const char* fileSpec, const char* mode)
	{
		uint32 handle = eC_INVALID_FILE_HANDLE;

		for (uint32 index = 0; index < FILESYSTEM_MAX_HANDLES; ++index)
		{
			if (m_fileHandle[index].m_handle == NULL)
			{
				m_fileHandle[index].m_handle = fopen(fileSpec, mode);
				if (m_fileHandle[index].m_handle != NULL)
				{
#if defined(_DEBUG)
					strncpy(m_fileHandle[index].m_name, fileSpec, FILESYSTEM_MAX_STORED_NAME_LENGTH);
					m_fileHandle[index].m_name[FILESYSTEM_MAX_STORED_NAME_LENGTH-1] = 0;
#endif // defined(_DEBUG)
					handle = index;
				}
				break;
			}
		}

		return handle;
	}

	//============================================================================

	bool CFileSystem::Write(uint32 handle, const void* pData, uint32 length)
	{
		bool written = false;

		if (handle < FILESYSTEM_MAX_HANDLES)
		{
			if (m_fileHandle[handle].m_handle != NULL)
			{
				written = (fwrite(pData, length, 1, m_fileHandle[handle].m_handle) == 1);
			}
		}

		return written;
	}

	//============================================================================

	bool CFileSystem::Read(uint32 handle, void* pData, uint32 length)
	{
		bool read = false;

		if (handle < FILESYSTEM_MAX_HANDLES)
		{
			if (m_fileHandle[handle].m_handle != NULL)
			{
				read = (fread(pData, length, 1, m_fileHandle[handle].m_handle) == 1);
			}
		}

		return read;
	}

	//============================================================================

	bool CFileSystem::Flush(uint32 handle)
	{
		bool flushed = false;

		if (handle < FILESYSTEM_MAX_HANDLES)
		{
			if (m_fileHandle[handle].m_handle != NULL)
			{
				flushed = (fflush(m_fileHandle[handle].m_handle) == 0);
			}
		}

		return flushed;
	}

	//============================================================================

	bool CFileSystem::Close(uint32 handle)
	{
		bool closed = false;

		if (handle < FILESYSTEM_MAX_HANDLES)
		{
			if (m_fileHandle[handle].m_handle != NULL)
			{
				fflush(m_fileHandle[handle].m_handle);
				closed = (fclose(m_fileHandle[handle].m_handle) == 0);
				if (closed)
				{
					m_fileHandle[handle].m_handle = NULL;
				}
			}
		}

		return closed;
	}

	//============================================================================
} // End [namespace engine]

//==============================================================================
// [EOF]

