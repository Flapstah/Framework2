#include "common/stdafx.h"

#include "common/console.h"

//==============================================================================

namespace engine
{
	//============================================================================

	CConsole::CConsole(void)
	{
	}

	//============================================================================

	CConsole::~CConsole(void)
	{
		if (!m_commandMap.empty())
		{
			printf("[Console]: still have commands registered:\n");
			uint32 count = 0;
			for (TCommandMap::const_iterator it = m_commandMap.begin(); it != m_commandMap.end(); ++it)
			{
				printf("[Console]: %s\n", (*it).first);
				++count;
			}
			printf("[Console]: %d commands need unregistering\n", count);

			m_commandMap.clear();
		}
		if (!m_variableMap.empty())
		{
			printf("[Console]: still have variables registered:\n");
			uint32 count = 0;
			for (TVariableMap::const_iterator it = m_variableMap.begin(); it != m_variableMap.end(); ++it)
			{
				const SVariable& variable = (*it).second;
				switch (variable.m_type)
				{
					case eVT_UnsignedInteger:
						printf("[Console]: %s = %" PRIu64 "\n", (*it).first, *variable.m_pUnsignedInteger);
						break;

					case eVT_SignedInteger:
						printf("[Console]: %s = %" PRId64 "\n", (*it).first, *variable.m_pSignedInteger);
						break;

					case eVT_FloatingPoint:
						printf("[Console]: %s = %f\n", (*it).first, *variable.m_pFloatingPoint);
						break;

					case eVT_String:
						printf("[Console]: %s = \"%s\"\n", (*it).first, variable.m_pString->c_str());
						break;
				}
				++count;
			}
			printf("[Console]: %d variables need unregistering\n", count);

			m_variableMap.clear();
		}
	}
	//============================================================================

	bool CConsole::RegisterCommand(const char* name, Callback pFunction, uint32 flags)
	{
		SCommand command(pFunction, flags);
		std::pair<TCommandMap::iterator, bool> ret;

		ret = m_commandMap.insert(TCommandMapElement(name, command));
		if (ret.second == false)
		{
			printf("[Console]: unable to register command %s as it already exists\n", name);
		}

		return ret.second;
	}

	//============================================================================

	void CConsole::UnregisterCommand(const char* name)
	{
		if (m_commandMap.erase(name) == 0)
		{
			printf("[Console]: error unregistering: command %s does not exist\n", name);
		}
	}

	//============================================================================

	bool CConsole::RegisterVariable(const char* name, uint64& variable, uint32 flags)
	{
		SVariable consoleVariable(variable, flags);
		std::pair<TVariableMap::iterator, bool> ret;

		ret = m_variableMap.insert(TVariableMapElement(name, consoleVariable));
		if (ret.second == false)
		{
			printf("[Console]: unable to register variable %s as it already exists\n", name);
		}

		return ret.second;
	}

	//============================================================================

	bool CConsole::RegisterVariable(const char* name, int64& variable, uint32 flags)
	{
		SVariable consoleVariable(variable, flags);
		std::pair<TVariableMap::iterator, bool> ret;

		ret = m_variableMap.insert(TVariableMapElement(name, consoleVariable));
		if (ret.second == false)
		{
			printf("[Console]: unable to register variable %s as it already exists\n", name);
		}

		return ret.second;
	}

	//============================================================================

	bool CConsole::RegisterVariable(const char* name, double& variable, uint32 flags)
	{
		SVariable consoleVariable(variable, flags);
		std::pair<TVariableMap::iterator, bool> ret;

		ret = m_variableMap.insert(TVariableMapElement(name, consoleVariable));
		if (ret.second == false)
		{
			printf("[Console]: unable to register variable %s as it already exists\n", name);
		}

		return ret.second;
	}

	//============================================================================

	bool CConsole::RegisterVariable(const char* name, std::string& variable, uint32 flags)
	{
		SVariable consoleVariable(variable, flags);
		std::pair<TVariableMap::iterator, bool> ret;

		ret = m_variableMap.insert(TVariableMapElement(name, consoleVariable));
		if (ret.second == false)
		{
			printf("[Console]: unable to register variable %s as it already exists\n", name);
		}

		return ret.second;
	}

	//============================================================================

	void CConsole::UnregisterVariable(const char* name)
	{
		if (m_variableMap.erase(name) == 0)
		{
			printf("[Console]: error unregistering: variable %s does not exist\n", name);
		}
	}

	//============================================================================

	bool CConsole::ExecuteString(const char* command)
	{
		// TODO: implement
		return false;
	}

	//============================================================================
} // End [namespace engine]

//==============================================================================
// [EOF]

