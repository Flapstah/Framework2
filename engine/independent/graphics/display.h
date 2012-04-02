#if !defined(__DISPLAY_H__)
#define __DISPLAY_H__

//==============================================================================

namespace engine
{
	//============================================================================
	// CDisplay
	//============================================================================
	class CDisplay
	{
		public:
			CDisplay(uint32 width, uint32 height, const char* title);
			~CDisplay(void);

			bool Update(const void* pData);
			void SetDisplayScale(float scale);
			float GetDisplayScale(void) const;

		protected:

			enum eTextureID
			{
				eTID_Main = 1
			};

			float m_displayScale;
			uint32 m_width;
			uint32 m_height;
	}; // End [class CDisplay]

//============================================================================
} // End [namespace engine]

//==============================================================================
#endif // !defined(__DISPLAY_H__)
// [EOF]

