#if !defined(__SYSTEM_H__)
#define __SYSTEM_H__

//==============================================================================

#if USE_GLFW
#include "common/glfw.h"
#endif // USE_GLFW

//==============================================================================

namespace engine
{
	//============================================================================
	// CSystem
	//============================================================================
	class CSystem
	{
		public:
			static CSystem& Get(void)
			{
				static CSystem instance;
				return instance;
			}
			~CSystem(void);

			void LogCallstack(uint32 maxDepth);

		protected:
			CSystem(void);
			void Initialise(void);
			void Uninitialise(void);

			void Platform_LogCallstack(uint32 maxDepth);

		protected:
#if USE_GLFW
			CGLFW m_glfw;
#endif // USE_GLFW

	//============================================================================
	}; // End [class CSystem]

	//============================================================================
} // End [namespace engine]

//==============================================================================
#endif // End [!defined(__SYSTEM_H__)]
// [EOF]

