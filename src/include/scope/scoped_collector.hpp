#pragma once
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <vector>
#include <optional>
#include "include/scope/scope.hpp"
#include "include/utils/unique_number.hpp"

namespace scope
{
template <typename T>
class ScopedCollector
{
    private:
    std::map<ScopeID, std::map<std::string, T>> elements;
    ScopeID current_scope_id;
    ScopeID top_scope_id;
    int _unique_number;

    public:
    ScopedCollector(std::string top_scope_name)
        : current_scope_id(Scope::create(top_scope_name)),
          top_scope_id(Scope::create(top_scope_name))
    {
    }

    void add(std::string name, T new_element)
    {
        add(name, new_element, current_scope_id);
    }

    void add(std::string name, T new_element, ScopeID scope_id)
    {
        elements[scope_id].insert(std::make_pair(name, new_element));
    }

    std::optional<T> get(const std::string& name, ScopeID scope_id)
    {
        auto accessible = ScopePool::get(scope_id).enumerate_accesible_scopes();
        for (const auto& accessible_scope : accessible)
        {
            if (elements[accessible_scope].count(name))
            {
                return elements[accessible_scope].at(name);
            }
        }
        return std::nullopt;
    }

    std::optional<T> get(const std::string& name)
    {
        return get(name, current_scope_id);
    }

    void into_named_scope(std::string name)
    {
        current_scope_id = ScopePool::get(current_scope_id).append(name);
    }

    void into_anonymous_scope()
    {
        int number = utils::UniqueNumber::get().get_unique_number();
        current_scope_id =
            ScopePool::get(current_scope_id)
                .append(std::string("anonymous#") + std::to_string(number));
    }

    void break_out_of_namespace()
    {
        auto& prev = ScopePool::get(current_scope_id);
        current_scope_id = ScopePool::get(current_scope_id).pop();
    }

    ScopeID& get_scope_id() { return current_scope_id; }

    void dump()
    {
        for (auto& pair : elements)
        {
            auto scope_id = pair.first;
            auto& element_map = pair.second;
            std::cout << "in scope " << ScopePool::get(scope_id).to_string()
                      << std::endl;
            for (auto& name_and_element : elements[scope_id])
            {
                std::cout << "    " << name_and_element.first << std::endl;
            }
        }
    }
};
}  // namespace scope