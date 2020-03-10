#include "unique_number.hpp"

namespace utils {
int UniqueNumber::get_unique_number() {
    unique_number += 1;
    return unique_number;
}

UniqueNumber& UniqueNumber::get() {
    static UniqueNumber instance;
    return instance;
}
}  // namespace utils