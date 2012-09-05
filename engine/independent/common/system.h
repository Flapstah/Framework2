#if !defined(__SYSTEM_H__)
#define __SYSTEM_H__

//==============================================================================

#if USE_GLFW
#include "common/glfw.h"
#endif // USE_GLFW

#if INSTRUMENTED_CODE
#include <map>
#include <vector>
#endif // INSTRUMENTED_CODE

//==============================================================================

namespace engine
{
	//============================================================================
	// CSystem
	//============================================================================
	class CSystem
	{
		public:
			SINGLETON(CSystem)
			~CSystem(void);

			void LogCallstack(uint32 maxDepth);

		protected:
			void Initialise(void);
			void Uninitialise(void);

			void Platform_LogCallstack(uint32 maxDepth);

#if INSTRUMENTED_CODE
			static void Instrument(const char* name);
			static void LogInstrumentation(void);
#endif // INSTRUMENTED_CODE

		protected:
#if USE_GLFW
			CGLFW m_glfw;
#endif // USE_GLFW

#if INSTRUMENTED_CODE
			struct SInstrumentedData
			{
				SInstrumentedData(void) : m_callCount(0) {}

				uint64 m_callCount;
			};

			typedef std::map<const char*, SInstrumentedData> TInstrumentedCodeMap;
			static TInstrumentedCodeMap s_instrumentedCode;
#endif // INSTRUMENTED_CODE

	//============================================================================
	}; // End [class CSystem]

	//============================================================================
} // End [namespace engine]

//==============================================================================
#endif // End [!defined(__SYSTEM_H__)]
// [EOF]

