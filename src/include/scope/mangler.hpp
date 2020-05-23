#include <string>
#include <utility>

namespace scope
{
class Scope;

std::string mangle(const std::string& name, const ScopeID scope);
std::pair<std::string, ScopeID> demangle(const std::string& mangled_name);
}  // namespace scope