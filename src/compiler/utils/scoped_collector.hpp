#pragma once
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <vector>
#include <optional>
#include "scope/scope.hpp"
#include "unique_number/unique_number.hpp"

namespace utils {

template <typename T>
class ScopedCollector {
    private:
    std::map<Scope, std::map<std::string, T>> elements;
    Scope current_scope;
    Scope top_scope;
    int _unique_number;

    public:
    ScopedCollector(std::string top_scope_name)
        : current_scope(top_scope_name), top_scope(top_scope_name) {}

    void add(std::string name, T new_element) {
        elements[current_scope][name] = new_element;
    }

    void add(std::string name, T new_element, Scope scope) {
        elements[scope][name] = new_element;
    }

    std::optional<T> get(std::string name, Scope scope) const {
        auto accessible = scope.enumerate_accesible_scopes();
        for (const auto& accessible_scope : accessible) {
            if (elements[accessible_scope].count(name)) {
                return elements[accessible_scope][name];
            }
        }
        return std::nullopt;
    }

    std::optional<T> get(std::string name) const {
        return get(name, current_scope);
    }

    void into_named_scope(std::string name) { current_scope.append(name); }

    void into_anonymous_scope() {
        int number = UniqueNumber::get().get_unique_number();
        current_scope.append(std::string("anonymous#") +
                             std::to_string(number));
    }

    void break_out_of_namespace() { current_scope.pop(); }

    Scope& get_scope() { return current_scope; }

    /*
    void dump() {
        for (auto& node_map : nodes) {
            std::cout << "in scope '" << get_namespace_as_string(node_map.first)
                      << "':" << std::endl;
            for (auto& name : nodes[node_map.first].second) {
                std::cout << "    " << name << std::endl;
                // nodes[node_map.first].first[name];
            }
        }
    }
    */
};
}  // namespace utils