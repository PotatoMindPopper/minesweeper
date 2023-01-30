#ifndef __STANDARD_HPP__
#define __STANDARD_HPP__

#include <string>

/**
 * @brief A function to remove the trailing zeros from a string
 * 
 * @param str The string to remove the trailing zeros from
 * @return std::string The string without the trailing zeros
 */
std::string remove_trailing_zeros(const std::string &str);

/**
 * @brief A function to transform a decimal number to a string representation
 * 
 * @param number The number to transform (of data types supporting decimal)
 * @return std::string The string representation of the number
 */
std::string to_string(const float &number);
std::string to_string(const double &number);
std::string to_string(const long double &number);

#endif // __STANDARD_HPP__