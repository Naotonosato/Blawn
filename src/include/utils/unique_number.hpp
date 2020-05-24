#pragma once

namespace utils
{
class UniqueNumber
{
    private:
    UniqueNumber() = default;
    ~UniqueNumber() = default;
    unsigned long unique_number;

    public:
    UniqueNumber(const UniqueNumber&) = delete;
    UniqueNumber& operator=(const UniqueNumber&) = delete;
    UniqueNumber(UniqueNumber&&) = delete;
    UniqueNumber& operator=(UniqueNumber&&) = delete;
    unsigned long get_unique_number();
    static UniqueNumber& get();
};

unsigned long get_unique_number();
}  // namespace utils