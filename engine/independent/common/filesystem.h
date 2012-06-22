
namespace engine
{
	class CFileSystem
	{
		static bool Exists(const char* filename)
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

		static bool Remove(const char* fileName)
		{
			bool removed = (remove(fileName) == 0);
			return removed;
		}

		static bool Rename(const char* oldFileName, const char* newFileName)
		{
			bool renamed = (rename(oldFileName, newFileName) == 0);
			return renamed;
		}
	};
}

