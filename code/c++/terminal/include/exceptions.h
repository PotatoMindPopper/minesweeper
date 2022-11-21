#ifndef __EXCEPTIONS_H__
#define __EXCEPTIONS_H__

#include <stdexcept>
#include <string>

/**
 * @brief The Exception class for a CellError
 */
class CellError : public std::runtime_error {
    public:
        explicit CellError(const std::string &msg) : runtime_error("ERROR: " + msg) {}
};

/**
 * @brief The Exception class for a CellError
 */
class TableError : public std::runtime_error {
    public:
        explicit TableError(const std::string &msg) : runtime_error("ERROR: " + msg) {}
};

/**
 * @brief The Exception class for a CellError
 */
class MineError : public std::runtime_error {
    public:
        explicit MineError(const std::string &msg) : runtime_error("ERROR: " + msg) {}
};


#endif // __EXCEPTIONS_H__
