#if !defined(__MACROS_H__)
#define __MACROS_H__

//==============================================================================

//------------------------------------------------------------------------------
// Create environment independent 64 bit literals
//------------------------------------------------------------------------------
#if defined(ENVIRONMENT32)
#define DECLARE_64BIT(_val_) (_val_##ll)
#elif defined(ENVIRONMENT64)
#define DECLARE_64BIT(_val_) (_val_##l)
#else
#error Unable to determine compilation environment (neither ENVIRONMENT32 or ENVIRONMENT64 defined)
#endif // [defined(ENVIRONMENT32)]

//------------------------------------------------------------------------------
// Prevent copy constructor and assignment operator
//------------------------------------------------------------------------------
#define PREVENT_CLASS_COPY(_class_) _class_(const _class_&); _class_& operator = (const _class_&)

//------------------------------------------------------------------------------
// Prevent instancing this class
//------------------------------------------------------------------------------
#define PREVENT_CLASS_INSTANCE() virtual void YouCannotInstanceThisClass(void) = 0

//------------------------------------------------------------------------------
// Prevent compiler warnings for intentionally unreferenced parameters
//------------------------------------------------------------------------------
#define IGNORE_PARAMETER(_parameter_) (void)(_parameter_)

//------------------------------------------------------------------------------
// Size macros
//------------------------------------------------------------------------------
#define SIZE_IN_KB(_size_) ((_size_)*1024)
#define SIZE_IN_MB(_size_) ((_size_)*1024*1024)

//------------------------------------------------------------------------------
// Disambiguate specific bit manipulation
//------------------------------------------------------------------------------
#define BIT(_number_) (1<<_number_)

//==============================================================================

#endif // End [!defined(__MACROS_H__)]
// [EOF]
