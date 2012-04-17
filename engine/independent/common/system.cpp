#include "common/stdafx.h"

#include <new>

#include "common/system.h"
#include "time/time.h"

//==============================================================================

namespace engine
{
	//============================================================================

	static uint8 g_CSystemInstanceMemory[sizeof(CSystem)];
	CSystem* CSystem::s_this = NULL;

	//============================================================================

	CSystem::CSystem(void)
	{
		CTime::Initialise();
	}

	//============================================================================

	CSystem::~CSystem(void)
	{
	}

	//============================================================================

	bool CSystem::Initialise(void)
	{
		bool initialised = (Get() != NULL);

		return initialised;
	}

	//============================================================================

	void CSystem::Uninitialise(void)
	{
		if (s_this != NULL)
		{
			s_this->~CSystem();
			s_this = NULL;
		}
	}

	//============================================================================

	CSystem* CSystem::Get(void)
	{
		if (s_this == NULL)
		{
			s_this = new(static_cast<void*>(g_CSystemInstanceMemory)) CSystem();
		}

		return s_this;
	}

	//============================================================================
} // End [namespace engine]

//==============================================================================
// [EOF]

