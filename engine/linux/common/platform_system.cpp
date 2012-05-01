#include "common/stdafx.h"

#include <execinfo.h>

#include "common/system.h"

namespace engine
{
	//============================================================================

	void CSystem::Platform_LogCallstack(uint32 maxDepth)
	{
		void* pCallstack = malloc(maxDepth*sizeof(void*));
		int32 depth = backtrace(pCallstack, maxDepth);
		char** pSymbols = backtrace_symbols(pCallstack, depth);

		printf("Callstack:\n");
		for (uint32 index = 0; index < depth; ++index)
		{
			printf("  %d) %s\n", index, pSymbols[index]);
		}
		printf("End callstack\n");

		free(pSymbols);
		free(pCallstack);
	}

	//============================================================================
} // End [namespace engine]

//==============================================================================
// [EOF]

