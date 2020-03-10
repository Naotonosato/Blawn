#include <vector>
#include <string>

namespace utils {

class Scope final : protected std::string {
    private:
    char separator;
    std::vector<std::string> scope_names;

    public:
    Scope(char separator = '/') : std::string(), separator(separator) {}
    Scope(const std::string& name, char separator = '/');
    Scope(std::string&& name, char separator = '/')
        : std::string(std::move(name)), separator(separator) {}
    Scope(const Scope&) = default;
    Scope(Scope&&) = default;
    Scope(const Scope&, std::string new_scope_name, char separator = '/');
    Scope& operator=(const Scope&) = delete;
    Scope& operator=(Scope&&) = delete;
    void append(const std::string&);
    void pop();
    std::string to_string() const;
    bool operator==(const Scope&) const;
    bool operator!=(const Scope&) const;
    bool is_deeper_than(const Scope& scope) const;
    bool is_shallower_than(const Scope& scope) const;
    std::vector<Scope> enumerate_accesible_scopes();
};

}  // namespace utils