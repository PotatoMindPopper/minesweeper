#ifndef __CONSTANTS_WITH_INCLUDES_H__
#define __CONSTANTS_WITH_INCLUDES_H__

// Try to not get these includes perse in the rest of the code
#if !defined(_STRING_) || !defined(_CHRONO_) || !defined(_CSTDDEF_)
#include <string>
#include <chrono>
#include <cstddef>
#endif

// typedef for std::chrono::time_point
typedef std::chrono::time_point<std::chrono::system_clock> TimePoint;
// typedef for std::chrono::duration
typedef std::chrono::duration<float> Duration;

// Constants
const std::string UNDEFINED_STRING{""};
const std::nullptr_t UNDEFINED_PTR{nullptr};
const Duration UNDEFINED_DURATION{std::chrono::duration<float>::min()};
const TimePoint UNDEFINED_TIME{std::chrono::system_clock::time_point::min()};

#endif // __CONSTANTS_WITH_INCLUDES_H__