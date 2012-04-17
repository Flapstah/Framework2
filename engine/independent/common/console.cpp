#include "common/stdafx.h"

#include "common/console.h"

//==============================================================================

namespace engine
{
	//============================================================================

	// The one instance of the console.
	static CConsole g_Console;
	CConsole* CConsole::s_this = &g_Console;

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
						printf("[Console]: %s = %" PRIu64 "\n", (*it).first, variable.GetUINT64());
						break;

					case eVT_SignedInteger:
						printf("[Console]: %s = %" PRId64 "\n", (*it).first, variable.GetINT64());
						break;

					case eVT_FloatingPoint:
						printf("[Console]: %s = %f\n", (*it).first, variable.GetFloatingPoint());
						break;

					case eVT_String:
						printf("[Console]: %s = \"%s\"\n", (*it).first, variable.GetString());
						break;
				}
				++count;
			}
			printf("[Console]: %d variables need unregistering\n", count);

			m_variableMap.clear();
		}
	}

	//============================================================================

	CConsole* CConsole::Get(void)
	{
		return s_this;
	}

	//============================================================================

	bool CConsole::RegisterCommand(const char* name, Callback pFunction, uint32 flags, const char* pUsage)
	{
		SCommand command(pFunction, flags, pUsage);
		std::pair<TCommandMap::iterator, bool> ret;

		ret = m_commandMap.insert(TCommandMapElement(name, command));
		if (ret.second == false)
		{
			printf("[Console]: unable to register command %s as it already exists\n", name);
		}

		return ret.second;
	}

	//============================================================================

	const CConsole::SCommand* CConsole::GetCommand(const char* name)
	{
		SCommand* pCommand = NULL;
		TCommandMap::iterator it = m_commandMap.find(name);

		if (it != m_commandMap.end())
		{
			pCommand = &((*it).second);
		}

		return pCommand;
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

	bool CConsole::RegisterVariable(const char* name, uint64& variable, uint32 flags, const char* pUsage)
	{
		SVariable consoleVariable(variable, flags, pUsage);
		std::pair<TVariableMap::iterator, bool> ret;

		ret = m_variableMap.insert(TVariableMapElement(name, consoleVariable));
		if (ret.second == false)
		{
			printf("[Console]: unable to register variable %s as it already exists\n", name);
		}

		return ret.second;
	}

	//============================================================================

	bool CConsole::RegisterVariable(const char* name, int64& variable, uint32 flags, const char* pUsage)
	{
		SVariable consoleVariable(variable, flags, pUsage);
		std::pair<TVariableMap::iterator, bool> ret;

		ret = m_variableMap.insert(TVariableMapElement(name, consoleVariable));
		if (ret.second == false)
		{
			printf("[Console]: unable to register variable %s as it already exists\n", name);
		}

		return ret.second;
	}

	//============================================================================

	bool CConsole::RegisterVariable(const char* name, double& variable, uint32 flags, const char* pUsage)
	{
		SVariable consoleVariable(variable, flags, pUsage);
		std::pair<TVariableMap::iterator, bool> ret;

		ret = m_variableMap.insert(TVariableMapElement(name, consoleVariable));
		if (ret.second == false)
		{
			printf("[Console]: unable to register variable %s as it already exists\n", name);
		}

		return ret.second;
	}

	//============================================================================

	bool CConsole::RegisterVariable(const char* name, std::string& variable, uint32 flags, const char* pUsage)
	{
		SVariable consoleVariable(variable, flags, pUsage);
		std::pair<TVariableMap::iterator, bool> ret;

		ret = m_variableMap.insert(TVariableMapElement(name, consoleVariable));
		if (ret.second == false)
		{
			printf("[Console]: unable to register variable %s as it already exists\n", name);
		}

		return ret.second;
	}

	//============================================================================

	CConsole::SVariable* CConsole::GetVariable(const char* name)
	{
		SVariable* pVariable = NULL;
		TVariableMap::iterator it = m_variableMap.find(name);

		if (it != m_variableMap.end())
		{
			pVariable = &((*it).second);
		}

		return pVariable;
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

