#include <include/debug/debug_info.hpp>

namespace debug
{
const size_t TokenInfo::get_line_number() const { return line_number; }
const size_t TokenInfo::get_index_in_line() const { return index_in_line; }
const std::string& TokenInfo::get_token_string() const { return token_string; }

const std::string& DebugInfo::get_filename() const { return filename; }

const TokenInfo& DebugInfo::get_token_info() const { return token_info; }

const scope::ScopeID DebugInfo::get_scope_id() const { return scope_id; }

}  // namespace debug