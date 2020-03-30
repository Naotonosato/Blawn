#include "to_string.hpp"

namespace utils {
std::string to_string(std::vector<std::string> vector) {
    std::string res;
    for (auto& v : vector) {
        res += v;
    }
    return res;
}
}  // namespace utils