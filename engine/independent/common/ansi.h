#if !defined(__ANSI_H__)
#define __ANSI_H__

//==============================================================================
// Example printf statement using the ANSI_xxx macros:
//==============================================================================
/*
	printf(
			ANSI_1SEQUENCE(ANSI_FOREGROUND(ANSI_BLACK)) "R"
			ANSI_1SEQUENCE(ANSI_FOREGROUND(ANSI_RED)) "a"
			ANSI_1SEQUENCE(ANSI_FOREGROUND(ANSI_GREEN)) "i"
			ANSI_1SEQUENCE(ANSI_FOREGROUND(ANSI_YELLOW)) "n"
			ANSI_1SEQUENCE(ANSI_FOREGROUND(ANSI_BLUE)) "b"
			ANSI_1SEQUENCE(ANSI_FOREGROUND(ANSI_MAGENTA)) "o"
			ANSI_1SEQUENCE(ANSI_FOREGROUND(ANSI_CYAN)) "w"
			ANSI_1SEQUENCE(ANSI_RESET_ALL) "\n"
			ANSI_2SEQUENCE(ANSI_BRIGHT, ANSI_FOREGROUND(ANSI_BLACK)) "R"
			ANSI_1SEQUENCE(ANSI_FOREGROUND(ANSI_RED)) "a"
			ANSI_1SEQUENCE(ANSI_FOREGROUND(ANSI_GREEN)) "i"
			ANSI_1SEQUENCE(ANSI_FOREGROUND(ANSI_YELLOW)) "n"
			ANSI_1SEQUENCE(ANSI_FOREGROUND(ANSI_BLUE)) "b"
			ANSI_1SEQUENCE(ANSI_FOREGROUND(ANSI_MAGENTA)) "o"
			ANSI_1SEQUENCE(ANSI_FOREGROUND(ANSI_CYAN)) "w"
			ANSI_1SEQUENCE(ANSI_RESET_ALL) "\n"
			ANSI_1SEQUENCE(ANSI_COLOUR(ANSI_WHITE, ANSI_BLACK)) "R"
			ANSI_1SEQUENCE(ANSI_COLOUR(ANSI_WHITE, ANSI_RED)) "a"
			ANSI_1SEQUENCE(ANSI_COLOUR(ANSI_WHITE, ANSI_GREEN)) "i"
			ANSI_1SEQUENCE(ANSI_COLOUR(ANSI_WHITE, ANSI_YELLOW)) "n"
			ANSI_1SEQUENCE(ANSI_COLOUR(ANSI_WHITE, ANSI_BLUE)) "b"
			ANSI_1SEQUENCE(ANSI_COLOUR(ANSI_WHITE, ANSI_MAGENTA)) "o"
			ANSI_1SEQUENCE(ANSI_COLOUR(ANSI_WHITE, ANSI_CYAN)) "w"
			ANSI_1SEQUENCE(ANSI_RESET_ALL) "\n"
			ANSI_2SEQUENCE(ANSI_BRIGHT, ANSI_COLOUR(ANSI_WHITE, ANSI_BLACK)) "R"
			ANSI_1SEQUENCE(ANSI_COLOUR(ANSI_WHITE, ANSI_RED)) "a"
			ANSI_1SEQUENCE(ANSI_COLOUR(ANSI_WHITE, ANSI_GREEN)) "i"
			ANSI_1SEQUENCE(ANSI_COLOUR(ANSI_WHITE, ANSI_YELLOW)) "n"
			ANSI_1SEQUENCE(ANSI_COLOUR(ANSI_WHITE, ANSI_BLUE)) "b"
			ANSI_1SEQUENCE(ANSI_COLOUR(ANSI_WHITE, ANSI_MAGENTA)) "o"
			ANSI_1SEQUENCE(ANSI_COLOUR(ANSI_WHITE, ANSI_CYAN)) "w"
			ANSI_1SEQUENCE(ANSI_RESET_ALL) "\n"
			);
*/

//==============================================================================
// Nominal colours for ANSI compliant terminals
//==============================================================================
#define ANSI_BLACK "0"
#define ANSI_RED "1"
#define ANSI_GREEN "2"
#define ANSI_YELLOW "3"
#define ANSI_BLUE "4"
#define ANSI_MAGENTA "5"
#define ANSI_CYAN "6"
#define ANSI_WHITE "7"

//==============================================================================
// RGB values can be entered directly
//==============================================================================
#define ANSI_RGB(_red_, _green_, _blue_) "8;2;"#_red_";"#_green_";"#_blue_

//==============================================================================
// System defined default colour
//==============================================================================
#define ANSI_DEFAULT_COLOUR "9"

//==============================================================================
// Use colour arguments above for foreground/background
// e.g. ANSI_FOREGROUND(ANSI_GREEN)
//      ANSI_BACKGROUND(ANSI_RGB(64,128,255))
//==============================================================================
#define ANSI_FOREGROUND(_colour_string_) "3" _colour_string_
#define ANSI_BACKGROUND(_colour_string_) "4" _colour_string_

//==============================================================================
// Used to set 'bright' mode
//==============================================================================
#define ANSI_BRIGHT "1"

//==============================================================================
// Used to reset all styles/colours
//==============================================================================
#define ANSI_RESET_ALL "0"

//==============================================================================
// Helper macros to define the start, how to join sequences and the end of a
//sequence
//==============================================================================
#define ANSI_CSI "\x1b["
#define ANSI_WITH ";"
#define ANSI_TERMINATOR "m"

//==============================================================================
// Helper macro to define a foreground and background colour easily
// e.g. ANSI_COLOUR(ANSI_GREEN, ANSI_YELLOW) would be green text on a yellow
//																					 background
//==============================================================================
#define ANSI_COLOUR(_ansi_fgColour_, _ansi_bgColour_) ANSI_FOREGROUND(_ansi_fgColour_) ANSI_WITH ANSI_BACKGROUND(_ansi_bgColour_)

//==============================================================================
// Helper macros to define ANSI sequences
// e.g. ANSI_1SEQUENCE(ANSI_FOREGROUND(ANSI_RED))
//					 is a fully qualified sequence to set red text
//      ANSI_2SEQUENCE(ANSI_BRIGHT, ANSI_COLOUR(ANSI_CYAN, ANSI_RED))
//					 is a fully qualified sequence for bright red text on a bright
//					 yellow background
//==============================================================================
#define ANSI_1SEQUENCE(_sequence1_) ANSI_CSI _sequence1_ ANSI_TERMINATOR
#define ANSI_2SEQUENCE(_sequence1_, _sequence2_) ANSI_CSI _sequence1_ ANSI_WITH _sequence2_ ANSI_TERMINATOR

#endif // !defined(__ANSI_H__)
