#if !defined(__CONSOLE_H__)
#define __CONSOLE_H__

//==============================================================================

#include <string>
#include <map>

//==============================================================================

namespace engine
{
	//============================================================================
	// CConsole
	//============================================================================
	class CConsole
	{
		public:
			CConsole(void);
			~CConsole(void);

			void Activate(bool activate);
			bool IsActive(void) const;

			enum eConsoleFlags
			{
				eCF_Visible = 1 << 0,				// Visible in the console (autocomplete and value)
				eCF_Development = 1 << 1,		// Modifiable in development only
				eCF_Synchronised = 1 << 2,	// Synchronised between all clients
				eCF_ServerOnly = 1 << 3			// Modifialbe by the server only
			}; // End [enum eConsoleFlags]

			//typedef bool (*Callback)(const SCommand& command, uint32 argc, const char* argv[]);
			typedef bool (*Callback)(void);
			struct SCommand
			{
				SCommand(Callback pFunction, uint32 flags)
					: m_pFunction(pFunction)
					, m_flags(flags)
				{
				}

				Callback m_pFunction;
				uint32 m_flags;
			}; // End [struct SCommand]

			enum eVariableType
			{
				eVT_UnsignedInteger,
				eVT_SignedInteger,
				eVT_FloatingPoint,
				eVT_String
			}; // End [enum eVariableType]

			struct SVariable
			{
				SVariable(uint64& variable, uint32 flags)
					: m_pUnsignedInteger(&variable)
					, m_type(eVT_UnsignedInteger)
					, m_flags(flags)
				{
				}

				SVariable(int64& variable, uint32 flags)
					: m_pSignedInteger(&variable)
					, m_type(eVT_SignedInteger)
					, m_flags(flags)
				{
				}

				SVariable(double& variable, uint32 flags)
					: m_pFloatingPoint(&variable)
					, m_type(eVT_FloatingPoint)
					, m_flags(flags)
				{
				}

				SVariable(std::string& variable, uint32 flags)
					: m_pString(&variable)
					, m_type(eVT_String)
					, m_flags(flags)
				{
				}

				union
				{
					uint64* m_pUnsignedInteger;
					int64* m_pSignedInteger;
					double* m_pFloatingPoint;
					std::string* m_pString;
				}; // End [union]
				eVariableType m_type;
				uint32 m_flags;
			}; // End [SVariable]

			bool RegisterCommand(const char* name, Callback pFunction, uint32 flags);
			void UnregisterCommand(const char* name);
			bool RegisterVariable(const char* name, uint64& variable, uint32 flags);
			bool RegisterVariable(const char* name, int64& variable, uint32 flags);
			bool RegisterVariable(const char* name, double& variable, uint32 flags);
			bool RegisterVariable(const char* name, std::string& variable, uint32 flags);
			void UnregisterVariable(const char* name);
			bool ExecuteString(const char* command);

		protected:
			typedef std::map<const char*, SCommand> TCommandMap;
			typedef std::pair<const char*, SCommand> TCommandMapElement;
			typedef std::map<const char*, SVariable> TVariableMap;
			typedef std::pair<const char*, SVariable> TVariableMapElement;

			TCommandMap m_commandMap;
			TVariableMap m_variableMap;
	}; // End [class CConsole]

	//============================================================================
} // End [namespace engine]

//==============================================================================
#endif // End [!defined(__CONSOLE_H__)]
// [EOF]

