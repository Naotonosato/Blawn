#include "include/utils/unique_number.hpp"

namespace utils
{
unsigned long UniqueNumber::get_unique_number()
{
    unique_number += 1;
    return unique_number;
}

UniqueNumber& UniqueNumber::get()
{
    static UniqueNumber instance;
    return instance;
}

unsigned long get_unique_number()
{
    return UniqueNumber::get().get_unique_number();
}
}  // namespace utils