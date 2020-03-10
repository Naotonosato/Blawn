namespace utils {
class UniqueNumber {
    private:
    UniqueNumber() = default;
    ~UniqueNumber() = default;
    int unique_number;

    public:
    UniqueNumber(const UniqueNumber&) = delete;
    UniqueNumber& operator=(const UniqueNumber&) = delete;
    UniqueNumber(UniqueNumber&&) = delete;
    UniqueNumber& operator=(UniqueNumber&&) = delete;
    int get_unique_number();
    static UniqueNumber& get();
};
}  // namespace utils