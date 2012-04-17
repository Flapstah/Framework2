#if !defined(__CONSOLE_H__)
#define __CONSOLE_H__

//==============================================================================

#include <string>
#include <map>

//==============================================================================

namespace engine
{
	//============================================================================
	// Helper macros
	//============================================================================
#define REGISTER_CONSOLE_VARIABLE(_name_, _variable_, _default_value_, _flags_, _usage_) \
	_variable_ = _default_value_; \
	engine::CConsole::Get()->RegisterVariable(_name_, _variable_, _flags_, _usage_);
#define UNREGISTER_CONSOLE_VARIABLE(_name_) \
	engine::CConsole::Get()->UnregisterVariable(_name_);

	//============================================================================
	// CConsole
	//============================================================================
	class CConsole
	{
		public:
			CConsole(void);
			~CConsole(void);

			static CConsole* Get(void);
			
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
				SCommand(Callback pFunction, uint32 flags, const char* pUsage)
					: m_pFunction(pFunction)
					, m_pUsage(pUsage)
					, m_flags(flags)
				{
				}

				Callback m_pFunction;
				const char* m_pUsage;
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
				SVariable(uint64& variable, uint32 flags, const char* pUsage)
					: m_pUnsignedInteger(&variable)
					, m_pUsage(pUsage)
					, m_type(eVT_UnsignedInteger)
					, m_flags(flags)
				{
				}

				SVariable(int64& variable, uint32 flags, const char* pUsage)
					: m_pSignedInteger(&variable)
					, m_pUsage(pUsage)
					, m_type(eVT_SignedInteger)
					, m_flags(flags)
				{
				}

				SVariable(double& variable, uint32 flags, const char* pUsage)
					: m_pFloatingPoint(&variable)
					, m_pUsage(pUsage)
					, m_type(eVT_FloatingPoint)
					, m_flags(flags)
				{
				}

				SVariable(std::string& variable, uint32 flags, const char* pUsage)
					: m_pString(&variable)
					, m_pUsage(pUsage)
					, m_type(eVT_String)
					, m_flags(flags)
				{
				}

				uint64 GetUINT64(void) const
				{
					uint64 value = 0;
					if (m_type == eVT_UnsignedInteger)
					{
						value = *m_pUnsignedInteger;
					}

					return value;
				}

				void Set(uint64 value)
				{
					if (m_type == eVT_UnsignedInteger)
					{
						*m_pUnsignedInteger = value;
					}
				}

				int64 GetINT64(void) const
				{
					int64 value = 0;
					if (m_type == eVT_SignedInteger)
					{
						value = *m_pSignedInteger;
					}

					return value;
				}

				void Set(int64 value)
				{
					if (m_type == eVT_SignedInteger)
					{
						*m_pSignedInteger = value;
					}
				}

				double GetFloatingPoint(void) const
				{
					double value = 0.0;
					if (m_type == eVT_FloatingPoint)
					{
						value = *m_pFloatingPoint;
					}

					return value;
				}

				void Set(double value)
				{
					if (m_type == eVT_FloatingPoint)
					{
						*m_pFloatingPoint = value;
					}
				}

				const char* GetString(void) const
				{
					const char* pValue = "";
					if (m_type == eVT_String)
					{
						pValue = m_pString->c_str();
					}

					return pValue;
				}

				void Set(const char* value)
				{
					if (m_type == eVT_String)
					{
						*m_pString = value;
					}
				}

				const char* GetUsage(void) const
				{
					return m_pUsage;
				}

				eVariableType GetType(void) const
				{
					return m_type;
				}

				union
				{
					uint64* m_pUnsignedInteger;
					int64* m_pSignedInteger;
					double* m_pFloatingPoint;
					std::string* m_pString;
				}; // End [union]
				const char* m_pUsage;
				eVariableType m_type;
				uint32 m_flags;
			}; // End [SVariable]

			bool RegisterCommand(const char* name, Callback pFunction, uint32 flags, const char* pUsage);
			const SCommand* GetCommand(const char* name);
			void UnregisterCommand(const char* name);
			bool RegisterVariable(const char* name, uint64& variable, uint32 flags, const char* pUsage);
			bool RegisterVariable(const char* name, int64& variable, uint32 flags, const char* pUsage);
			bool RegisterVariable(const char* name, double& variable, uint32 flags, const char* pUsage);
			bool RegisterVariable(const char* name, std::string& variable, uint32 flags, const char* pUsage);
			SVariable* GetVariable(const char* name);
			void UnregisterVariable(const char* name);
			bool ExecuteString(const char* command);

		protected:
			static CConsole* s_this;

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

