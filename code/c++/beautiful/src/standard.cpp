#include "standard.hpp"

/**
 * @brief A function to remove the trailing zeros from a string
 * 
 * @param str The string to remove the trailing zeros from
 * @return std::string The string without the trailing zeros
 */
std::string remove_trailing_zeros(const std::string &str) {
    std::string new_str = str;
    new_str.erase(new_str.find_last_not_of('0') + 1, std::string::npos);
    if (new_str.back() == '.')
        new_str.pop_back();
    return new_str;
}

/**
 * @brief A function to transform a decimal number to a string representation
 * 
 * @param number The number to transform (of data types supporting decimal)
 * @return std::string The string representation of the number
 */
std::string to_string(const float &number) {
    std::string str = std::to_string(number);
    return remove_trailing_zeros(str);
}

std::string to_string(const double &number) {
    std::string str = std::to_string(number);
    return remove_trailing_zeros(str);
}

std::string to_string(const long double &number) {
    std::string str = std::to_string(number);
    return remove_trailing_zeros(str);
}
