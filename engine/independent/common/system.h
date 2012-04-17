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
			static bool Initialise(void);
			static void Uninitialise(void);

			static CSystem* Get(void);

		protected:
			CSystem(void);
			~CSystem(void);

		protected:
#if USE_GLFW
			CGLFW m_glfw;
#endif // USE_GLFW

			static CSystem* s_this;

	}; // End [class CSystem]

	//============================================================================
} // End [namespace engine]

//==============================================================================
#endif // End [!defined(__SYSTEM_H__)]
// [EOF]

