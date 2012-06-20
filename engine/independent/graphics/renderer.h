#if !defined(__RENDERER_H__)
#define __RENDERER_H__

//==============================================================================

#include "graphics/debugfont.h"

//==============================================================================

namespace engine
{
	//============================================================================
	// CRenderer
	//============================================================================
	class CRenderer
	{
		public:
			CRenderer(uint32 width, uint32 height, const char* title, float frameRate);
			~CRenderer(void);

			bool Update(void);

			uint32 Print(uint32 ypos, uint32 xpos, uint32 inkColour, uint32 paperColour, const char* text);
			void ActivateConsole(bool activate);
			bool IsConsoleActive(void) const;

		protected:
			static bool Callback(engine::CTime::CCallbackTimer* pTimer, void* pUserData);
			void UpdateConsole(bool visible);
			void SetConsoleHeight(float ratio);

		protected:
			enum eTextureID
			{
				eTID_Console = 1
			};

			engine::CDebugFont m_debugFont;
			uint32* m_pConsoleDisplay;
			uint32 m_width;
			uint32 m_height;
			uint32 m_consoleStartYPos;
			uint32 m_consoleCurrentYPos;
			uint32 m_consoleTargetYPos;
			uint32 m_timerID;
			float m_consoleVisibility;
			float m_displayScale;
			const char* m_title;
			float m_frameRate;
	}; // End [class CRenderer]

	//============================================================================
} // End [namespace engine]

//==============================================================================
#endif // !defined(__RENDERER_H__)
// [EOF]

