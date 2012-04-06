#if !defined(__DEBUGFONT_H__)
#define __DEBUGFONT_H__

//==============================================================================

namespace engine
{
	//============================================================================
	// CDebugFont
	//============================================================================
	class CDebugFont
	{
		public:
			struct SGlyph
			{
				SGlyph(void)
					: m_width(0)
				{
					memset(m_data, 0, sizeof(m_data));
				}

				SGlyph(uint8 data0, uint8 data1, uint8 data2, uint8 data3, uint8 data4, uint8 data5, uint8 data6, uint8 width)
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
			}; // End [struct SGlyph]

		public:
			CDebugFont(void);
			~CDebugFont(void);

			const SGlyph* GetGlyph(char glyph);

		protected:
			void InitFontData(void);

			SGlyph m_font[95]; // Basic ASCII ' ' (32) to '~' (126), with DEL (127) representing unprintable characters 

	}; // End [class CDebugFont]

//============================================================================
} // End [namespace engine]

//==============================================================================
#endif // !defined(__DEBUGFONT_H__)
// [EOF]

