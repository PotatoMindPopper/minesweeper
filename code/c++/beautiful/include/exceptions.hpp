#ifndef __EXCEPTIONS_HPP__
#define __EXCEPTIONS_HPP__

#include <stdexcept>
#include <string>

/**
 * @brief An exception thrown when the height is invalid
 * 
 */
class Invalid_Height : public std::invalid_argument {
    public:
        Invalid_Height(const std::string& what_arg) : std::invalid_argument(what_arg) {}
};

/**
 * @brief An exception thrown when the width is invalid
 * 
 */
class Invalid_Width : public std::invalid_argument {
    public:
        Invalid_Width(const std::string& what_arg) : std::invalid_argument(what_arg) {}
};

/**
 * @brief An exception thrown when the bounds are invalid
 * 
 */
class Invalid_Bounds : public std::invalid_argument {
    public:
        Invalid_Bounds(const std::string& what_arg) : std::invalid_argument(what_arg) {}
};

#endif // __EXCEPTIONS_HPP__