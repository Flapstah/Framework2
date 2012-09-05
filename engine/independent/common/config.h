#if !defined(__CONFIG_H__)
#define __CONFIG_H__

//==============================================================================

// Use GLFW for the UI framework
#define USE_GLFW 1

#define LOG_KEYBOARD_INPUT 0

#define DEFAULT_WINDOW_WIDTH (640)
#define DEFAULT_WINDOW_HEIGHT (400)
#define DEFAULT_WINDOW_TITLE "Framework Test"
#define DEFAULT_FRAMERATE (60.0)

#define TIMER_POOL_SIZE (16)
#define USE_DYNAMIC_TIMER_POOL 0

#define FILESYSTEM_MAX_HANDLES (16)
#if defined(_DEBUG)
#define FILESYSTEM_MAX_STORED_NAME_LENGTH (64)
#endif // defined(_DEBUG)

#define LOG_BUFFER_SIZE (1024)

#define INSTRUMENTED_CODE 1

//==============================================================================
#endif // End [!defined(__CONFIG_H__)]
// [EOF]

