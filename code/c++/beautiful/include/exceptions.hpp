#ifndef __EXCEPTIONS_HPP__
#define __EXCEPTIONS_HPP__

#include "standard.hpp"
#include <stdexcept>
#include <string>

/**
 * @brief An exception thrown when the height is invalid
 *
 */
class Invalid_Height : public std::invalid_argument {
    public:
        Invalid_Height(const std::string &what_arg)
            : std::invalid_argument("Invalid height; " + what_arg) {}
};

class Out_Of_Height_Range : public Invalid_Height {
    public:
        Out_Of_Height_Range(const double &min_height, const double &max_height)
            : Invalid_Height("must be between " + to_string(min_height) +
                             " and " + to_string(max_height)) {}
};

/**
 * @brief An exception thrown when the width is invalid
 *
 */
class Invalid_Width : public std::invalid_argument {
    public:
        Invalid_Width(const std::string &what_arg)
            : std::invalid_argument("Invalid width; " + what_arg) {}
};

class Out_Of_Width_Range : public Invalid_Width {
    public:
        Out_Of_Width_Range(const double &min_width, const double &max_width)
            : Invalid_Width("must be between " + to_string(min_width) +
                            " and " + to_string(max_width)) {}
};

/**
 * @brief An exception thrown when the bounds are invalid
 *
 */
class Invalid_Bounds : public std::invalid_argument {
    public:
        Invalid_Bounds(const std::string &what_arg)
            : std::invalid_argument(what_arg) {}
};

/**
 * @brief An exception thrown when the percentage is invalid
 *
 */
class Invalid_Percentage : public std::invalid_argument {
    public:
        Invalid_Percentage(const std::string &what_arg)
            : std::invalid_argument("Invalid percentage; " + what_arg) {}
};

class Out_Of_Percentage_Range : public Invalid_Percentage {
    public:
        Out_Of_Percentage_Range(const double &min_percentage,
                                const double &max_percentage)
            : Invalid_Percentage("must be between " +
                                 to_string(min_percentage) + " and " +
                                 to_string(max_percentage)) {}
};

#endif // __EXCEPTIONS_HPP__