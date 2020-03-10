#include <string>
#include "scope.hpp"

namespace utils {
Scope::Scope(const std::string& name, char separator)
    : std::string(name), separator(separator) {
    std::string scope_name;
    for (const auto& letter : name) {
        if (letter == separator) {
            scope_names.push_back(scope_name);
            scope_name = "";
        } else {
            scope_name += letter;
        }
    }
    scope_names.push_back(scope_name);
}

Scope::Scope(const Scope& old_scope, std::string new_scope_name, char separator)
    : std::string(old_scope.to_string() + separator + new_scope_name),
      separator(separator) {
    std::string scope_name;
    for (const auto& letter : to_string()) {
        if (letter == separator) {
            scope_names.push_back(scope_name);
            scope_name = "";
        } else {
            scope_name += letter;
        }
    }
    scope_names.push_back(scope_name);
}

void Scope::append(const std::string& new_scope_name) {
    operator+=(separator + new_scope_name);
    scope_names.push_back(new_scope_name);
}

void Scope::pop() {
    std::string scope_name = to_string();
    int separator_length = 1;
    auto poped = to_string().substr(
        0, to_string().size() - separator_length - scope_names.back().size());
    std::string::operator=(poped);
    scope_names.pop_back();
}

bool Scope::operator==(const Scope& scope) const {
    return to_string() == scope.to_string();
}

bool Scope::operator!=(const Scope& scope) const { return !(*this == scope); }

bool Scope::is_deeper_than(const Scope& scope) const {
    if (scope_names.size() < scope.scope_names.size()) return false;
    int idx = 0;
    for (const auto& scope_name : scope_names) {
        if (scope_name != scope.scope_names[idx]) return false;
        idx += 1;
    }
    return true;
}

bool Scope::is_shallower_than(const Scope& scope) const {
    return scope.is_deeper_than(*this);
}

std::string Scope::to_string() const { return std::string(c_str()); }

std::vector<Scope> Scope::enumerate_accesible_scopes() {
    std::vector<Scope> enumerated;
    std::string previous_scope_name;
    for (const auto& scope_name : scope_names) {
        enumerated.push_back(Scope(previous_scope_name + scope_name));
        previous_scope_name += scope_name + separator;
    }
    return enumerated;
}
}  // namespace utils

/*
#include <iostream>
int main()
{
    utils::Scope a = std::string("one/two/three");
    utils::Scope b(a,std::string("bbb"));
    utils::Scope c(b,std::string("ccc"));
    c.pop();
    c.append("ddd");
    std::cout << c.to_string() << std::endl;
    for (auto i:c.enumerate_accesible_scopes())
    {
        std::cout << i.to_string() << std::endl;
    }
}
*/