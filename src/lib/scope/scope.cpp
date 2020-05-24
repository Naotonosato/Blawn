#include <string>
#include <functional>
#include "include/scope/scope.hpp"

namespace scope
{
Scope::Scope(const std::string& name, char separator)
    : std::string(name), separator(separator)
{
    std::string scope_name;
    for (const auto& letter : name)
    {
        if (letter == separator)
        {
            scope_names.push_back(scope_name);
            scope_name = "";
        }
        else
        {
            scope_name += letter;
        }
    }
    scope_names.push_back(scope_name);
}

Scope::Scope(const Scope& old_scope, std::string new_scope_name, char separator)
    : std::string(old_scope.to_string() + separator + new_scope_name),
      separator(separator)
{
    std::string scope_name;
    for (const auto& letter : to_string())
    {
        if (letter == separator)
        {
            scope_names.push_back(scope_name);
            scope_name = "";
        }
        else
        {
            scope_name += letter;
        }
    }
    scope_names.push_back(scope_name);
}

ScopeID Scope::create(char separator)
{
    return ScopePool::add(Scope(separator));
}
ScopeID Scope::create(const std::string& name, char separator)
{
    return ScopePool::add(Scope(name, separator));
}
ScopeID Scope::create(std::string&& name, char separator)
{
    return ScopePool::add(Scope(separator));
}
ScopeID Scope::create(const Scope& scope_)
{
    return ScopePool::add(Scope(scope_));
}
ScopeID Scope::create(const Scope& scope_, std::string new_scope_name,
                      char separator)
{
    return ScopePool::add(Scope(scope_, new_scope_name, separator));
}

ScopeID Scope::append(const std::string& new_scope_name) const
{
    return create(*this, new_scope_name, separator);
}

ScopeID Scope::pop() const
{
    std::string scope_name = to_string();
    int separator_length = 1;
    auto poped = to_string().substr(
        0, to_string().size() - separator_length - scope_names.back().size());
    return create(poped);
}

bool Scope::operator==(const Scope& scope) const
{
    return to_string() == scope.to_string();
}

bool Scope::operator!=(const Scope& scope) const { return !(*this == scope); }

bool Scope::operator<(const Scope& scope) const
{
    return to_string() < scope.to_string();
}

bool Scope::is_deeper_than(const Scope& scope) const
{
    if (scope_names.size() < scope.scope_names.size()) return false;
    int idx = 0;
    for (const auto& scope_name : scope_names)
    {
        if (scope_name != scope.scope_names[idx]) return false;
        idx += 1;
    }
    return true;
}

bool Scope::is_shallower_than(const Scope& scope) const
{
    return scope.is_deeper_than(*this);
}

std::string Scope::to_string() const { return std::string(c_str()); }

std::string Scope::front() const { return scope_names.front(); }
std::string Scope::back() const { return scope_names.back(); }

const char Scope::get_separator() const { return separator; }

const std::vector<ScopeID> Scope::enumerate_accesible_scopes()
{
    std::vector<ScopeID> enumerated;
    std::string previous_scope_name;
    for (const auto& scope_name : scope_names)
    {
        enumerated.push_back(create(previous_scope_name + scope_name));
        previous_scope_name += scope_name + separator;
    }
    return enumerated;
}

size_t Scope::hash() const { return std::hash<std::string>()(to_string()); }

}  // namespace scope

/*
#include <iostream>
int main()
{
    scope::Scope a = std::string("one/two/three");
    scope::Scope b(a,std::string("bbb"));
    scope::Scope c(b,std::string("ccc"));
    c.pop();
    c.append("ddd");
    std::cout << c.to_string() << std::endl;
    for (auto i:c.enumerate_accesible_scopes())
    {
        std::cout << i.to_string() << std::endl;
    }
}
*/