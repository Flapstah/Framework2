#include "common/stdafx.h"

#if USE_GLFW
//==============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <math.h>

#include <GL/glfw.h>
//#include "includes/glext.h"

#include "time/time.h"
#include "graphics/renderer.h"
#include "input/keyboard.h"

//==============================================================================

namespace engine
{
	//============================================================================

#define PI (3.141592654)
#define TWO_PI (PI*2.0)
#define HALF_PI (PI/2.0)
	double sinlerp(double weight)
	{
		if (weight < 0.0)
		{
			weight = 0.0;
		}

		if (weight > 1.0)
		{
			weight = 1.0;
		}

		weight = (weight*PI)-HALF_PI;
		return (sin(weight)+1.0)/2.0;
	}

	//============================================================================

	CRenderer::CRenderer(uint32 width, uint32 height, const char* title, float frameRate)
		: m_timer(CTime::CTimeValue(), 1.0f, 0.0, CRenderer::Callback, this)
		, m_width(width)
		, m_height(height)
		, m_consoleStartYPos(0)
		, m_consoleCurrentYPos(0)
		, m_consoleTargetYPos(0)
		, m_consoleVisibility(1.0f)
		, m_displayScale(1.0f)
		, m_title(title)
		, m_frameRate(frameRate)
	{
		m_pConsoleDisplay = new uint32[m_width*m_height];

		if ((m_pConsoleDisplay == NULL) || (!glfwOpenWindow(m_width, m_height, 0, 0, 0, 0, 0, 0, GLFW_WINDOW)))
		{
			if (m_pConsoleDisplay == NULL)
			{
				printf("[CRenderer]: unable to allocate memory for console display");
			}
			else
			{
				printf("[CRenderer]: failed to open GLFW window");
			}

			exit(EXIT_FAILURE);
		}

		engine::CKeyboard::Initialise();

		for (uint32 i = 0; i < (m_width*m_height); ++i)
		{
			m_pConsoleDisplay[i] = 0x00ff0000;
		}

		glfwSwapInterval(0);
		glfwSetWindowTitle(title);

		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		glShadeModel(GL_FLAT);

		// Do texture stuff (http://www.gamedev.net/page/resources/_/reference/programming/opengl/269/opengl-texture-mapping-an-introduction-r947)
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glBindTexture(GL_TEXTURE_2D, eTID_Console);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

		m_timer.SetMaxFrameTime(CTime::CTimeValue(0.1));
		m_timer.SetInterval(1.0/m_frameRate);
	}

	//============================================================================

	CRenderer::~CRenderer(void)
	{
		if (m_pConsoleDisplay != NULL)
		{
			delete[] m_pConsoleDisplay;
			m_pConsoleDisplay = NULL;
		}
	}
	
	//============================================================================

	bool CRenderer::Update(void)
	{
		m_timer.Tick();
		return m_timer.IsActive();
	}

	//============================================================================

	void CRenderer::UpdateConsole(bool visible)
	{
		int width, height;

		// Get window size (and protect against height being 0)
		glfwGetWindowSize(&width, &height);
		height = (height > 0) ? height : 1;

		// Set up view
		glViewport(0, 0, width, height);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(0.0, (GLdouble)width, (GLdouble)height, 0.0);

		// Clear back buffer
		glClear(GL_COLOR_BUFFER_BIT);

		// Select texture
		glEnable(GL_TEXTURE_2D);
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
		glBindTexture(GL_TEXTURE_2D, eTID_Console);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_pConsoleDisplay);

		int32 delta = m_consoleTargetYPos-m_consoleStartYPos;
		m_consoleCurrentYPos = m_consoleStartYPos+(sinlerp(m_consoleVisibility)*delta);

		if (m_consoleVisibility < 1.0f)
		{
			if (m_consoleVisibility < 1.0f)
			{
				m_consoleVisibility += 2.0/DEFAULT_FRAMERATE;
				if (m_consoleVisibility > 1.0f)
				{
					m_consoleVisibility = 1.0f;
				}
			}
		}

		int32 x = 0;
		int32 y = m_consoleCurrentYPos-height;

		// Render textured quad
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f);
		glVertex2i(x, y);
		glTexCoord2f(0.0f, 1.0f);
		glVertex2i(x, y + height);
		glTexCoord2f(1.0f, 1.0f);
		glVertex2i(x + width, y + height);
		glTexCoord2f(1.0f, 0.0f);
		glVertex2i(x + width, y);
		glEnd();

		glfwSwapBuffers();
		glDisable(GL_TEXTURE_2D);
	}
	
	//============================================================================

	uint32 CRenderer::Print(uint32 ypos, uint32 xpos, uint32 inkColour, uint32 paperColour, const char* text)
	{
		uint32 width = 0;
		uint8 height = m_debugFont.GetFontHeight();

		while (*text)
		{
			const engine::CDebugFont::SGlyph* pGlyph = m_debugFont.GetGlyph(*text);

			for (uint8 y = 0; y < height; ++y)
			{
				if ((ypos+y) < m_height)
				{
					uint32 pixel = ((ypos+y)*m_width)+xpos+width;;
					for (uint8 x = 0; x < pGlyph->m_width; ++x)
					{
						if ((xpos+width+x) < m_width)
						{
							bool bit = ((pGlyph->m_data[y] & (0x80>>x)) != 0);
							uint32 colour = (bit) ? inkColour : paperColour;
							// TODO: modify colour by alpha channel
							m_pConsoleDisplay[pixel] = colour;
						}
						else
						{
							break;
						}
						++pixel;
					}
				}
				else
				{
					break;
				}
			}

			width += pGlyph->m_width;
			++text;
		}

		return width;
	}

	//============================================================================

	void CRenderer::ActivateConsole(bool activate)
	{
		if (activate && (m_consoleTargetYPos == 0))
		{
			SetConsoleHeight(0.5f);
		}

		if (!activate && (m_consoleTargetYPos != 0))
		{
			SetConsoleHeight(0.0f);
		}
	}

	//============================================================================

	bool CRenderer::IsConsoleActive(void) const
	{
		return (m_consoleTargetYPos != 0);
	}

	//============================================================================

	void CRenderer::SetConsoleHeight(float ratio)
	{
		if (ratio < 0.0f)
		{
			ratio = 0.0f;
		}

		if (ratio > 1.0f)
		{
			ratio = 1.0f;
		}

		uint32 height = ratio*m_height;

		if (m_consoleTargetYPos != height)
		{
			m_consoleStartYPos = m_consoleCurrentYPos;
			m_consoleTargetYPos = height;
			m_consoleVisibility = 0.0f;
		}
	}

	//============================================================================

	bool CRenderer::Callback(engine::CCallbackTimer* pTimer, void* pUserData)
	{
		CRenderer* pThis = reinterpret_cast<CRenderer*>(pUserData);

		pThis->UpdateConsole(true);

		// return false if the window is closed
		return (glfwGetWindowParam(GLFW_OPENED) == GL_TRUE) ? true : false;
	}

	//============================================================================
} // End [namespace engine]

//==============================================================================

#endif // End [USING_GLFW]

//==============================================================================
// [EOF]

