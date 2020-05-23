#pragma once
#include <vector>
#include <unordered_map>
#include <string>
#include "include/utils/unique_number.hpp"
#include "include/utils/hash_table.hpp"

namespace scope
{
class Scope;
using ScopeID = utils::Hash<Scope>;

class Scope final : protected std::string
{
    private:
    char separator;
    std::vector<std::string> scope_names;
    Scope(char separator = '/') : std::string(), separator(separator) {}
    Scope(const std::string& name, char separator = '/');
    Scope(std::string&& name, char separator = '/')
        : std::string(std::move(name)), separator(separator)
    {
    }

    Scope(const Scope&, std::string new_scope_name, char separator = '/');

    public:
    Scope(const Scope&) = default;
    static ScopeID create(char separator = '/');
    static ScopeID create(const std::string& name, char separator = '/');
    static ScopeID create(std::string&& name, char separator = '/');
    static ScopeID create(const Scope&);
    static ScopeID create(const Scope&, std::string new_scope_name,
                          char separator = '/');

    Scope& operator=(const Scope&) = delete;
    Scope& operator=(Scope&&) = delete;

    ScopeID append(const std::string&) const;
    ScopeID pop() const;
    std::string to_string() const;
    std::string front() const;
    std::string back() const;
    const char get_separator() const;
    bool operator==(const Scope&) const;
    bool operator!=(const Scope&) const;
    bool operator<(const Scope&) const;
    bool is_deeper_than(const Scope& scope) const;
    bool is_shallower_than(const Scope& scope) const;
    const std::vector<ScopeID> enumerate_accesible_scopes();

    size_t hash() const;
};

using ScopePool = utils::HashTable<Scope>;

}  // namespace scope