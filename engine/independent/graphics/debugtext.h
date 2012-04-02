#if !defined(__DEBUGTEXT_H__)
#define __DEBUGTEXT_H__

//==============================================================================

namespace engine
{
	//============================================================================
	// CDebugText
	//============================================================================
	class CDebugText
	{
		public:
			CDebugText(void);
			~CDebugText(void);

			uint32 Print(void* pData, uint32 width, uint32 height, uint32 xpos, uint32 ypos, const char* text);
			uint32 Width(const char* text);

		protected:
			void InitFontData(void);

			struct SChar
			{
				SChar(void)
					: m_width(0)
				{
					memset(m_data, 0, sizeof(m_data));
				}

				SChar(uint8 data0, uint8 data1, uint8 data2, uint8 data3, uint8 data4, uint8 data5, uint8 data6, uint8 width)
					: m_width(width)
				{
					m_data[0] = data0;
					m_data[1] = data1;
					m_data[2] = data2;
					m_data[3] = data3;
					m_data[4] = data4;
					m_data[5] = data5;
					m_data[6] = data6;
				}

				uint8 m_data[7];
				uint8 m_width;
			}; // End [struct SChar]

			SChar m_font[95]; // Basic ASCII ' ' (32) to '~' (126), with DEL (127) representing unprintable characters 

	}; // End [class CDebugText]

//============================================================================
} // End [namespace engine]

//==============================================================================
#endif // !defined(__DEBUGTEXT_H__)
// [EOF]

