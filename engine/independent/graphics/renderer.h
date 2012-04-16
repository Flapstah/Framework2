#if !defined(__RENDERER_H__)
#define __RENDERER_H__

//==============================================================================

#include "time/callbacktimer.h"
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
			void SetConsoleHeight(uint32 height);

		protected:
			static bool Callback(engine::CCallbackTimer* pTimer, void* pUserData);
			void UpdateConsole(bool visible);

		protected:
			enum eTextureID
			{
				eTID_Console = 1
			};

			engine::CDebugFont m_debugFont;
			engine::CCallbackTimer m_timer;
			uint32* m_pConsoleDisplay;
			uint32 m_width;
			uint32 m_height;
			uint32 m_consoleStartYPos;
			uint32 m_consoleCurrentYPos;
			uint32 m_consoleTargetYPos;
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

