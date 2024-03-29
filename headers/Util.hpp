#ifndef __UTIL_HPP__
#define __UTIL_HPP__

#include <stdexcept>
#include <string>
#include <vector>

#define Expects(expression, message)                                           \
    if ((expression) == false) {                                               \
        throw std::invalid_argument(message);                                  \
    }

template <typename T>
inline std::string quote(const T &any) {
    return std::to_string(any);
}

inline std::string quote(const std::string &str) {
    return "'" + str + "'";
}

/*
 * This overlaod is needed only for compile time linking, it is never called
 * during execution.
 */
std::string build(const std::vector<std::string> & = {});

template <typename T, typename... Ts>
std::string build(T current, Ts... next) {
    return quote(current) + (sizeof...(next) == 0 ? "" : ", " + build(next...));
}

template <typename T, typename... Ts>
std::string build(const std::vector<std::string> &vec, T current, Ts... next) {
    return vec.at(vec.size() - sizeof...(next) - 1) + " = " + quote(current) +
           (sizeof...(next) == 0 ? "" : ", " + build(vec, next...));
}

#endif // __UTIL_HPP__
