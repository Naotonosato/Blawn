#include <string>
#include <utility>
#include "include/scope/scope.hpp"
#include "include/scope/mangler.hpp"

namespace scope
{
std::string mangle(const std::string& name, ScopeID scope_id)
{
    auto separator = ScopePool::get(scope_id).get_separator();
    auto mangled_name = ScopePool::get(scope_id).to_string() + separator + name;
    return mangled_name;
}

std::pair<std::string, ScopeID> demangle(const std::string& mangled_name)
{
    auto scope_id = Scope::create(mangled_name);
    auto name = ScopePool::get(scope_id).back();
    return std::make_pair(name, ScopePool::get(scope_id).pop());
}
}  // namespace scope