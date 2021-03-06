#include "common/stdafx.h"

#if USE_GLFW

#include "common/glfw.h"

#include <GL/glfw.h>

//==============================================================================

namespace engine
{
	//============================================================================
	
	// GLFW lifetime managed by this object
	static CGLFW g_GLFW;

	//============================================================================

	CGLFW::CGLFW(void)
	{
		if (!glfwInit())
		{
			printf("[CGLFW] Failed to initialise GLFW\n");
			exit(EXIT_FAILURE);
		}
	}

	//============================================================================

	CGLFW::~CGLFW(void)
	{
		glfwTerminate();
	}

	//============================================================================
} // End [namespace engine]

//==============================================================================

#endif // End [USE_GLFW]

//==============================================================================
// [EOF]

