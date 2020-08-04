#pragma once
#include <string>
#include <include/utils/hash_table.hpp>
#include <include/scope/scope.hpp>

namespace debug
{
class TokenInfo
{
    private:
    size_t line_number;
    size_t index_in_line;
    const std::string token_string;

    public:
    TokenInfo() = delete;
    TokenInfo(size_t line_number, size_t index_in_line,
              std::string token_string)
        : line_number(line_number),
          index_in_line(index_in_line),
          token_string(token_string)
    {
    }
    const size_t get_line_number() const;
    const size_t get_index_in_line() const;
    const std::string& get_token_string() const;
};

class DebugInfo
{
    private:
    const std::string filename;
    const TokenInfo token_info;
    const scope::ScopeID scope_id;

    public:
    DebugInfo() = delete;
    DebugInfo(const DebugInfo&) = default;
    DebugInfo(const std::string& filename, TokenInfo&& token_info,
              scope::ScopeID scope_id)
        : filename(filename),
          token_info(std::move(token_info)),
          scope_id(scope_id)
    {
    }

    const std::string& get_filename() const;
    const TokenInfo& get_token_info() const;
    const scope::ScopeID get_scope_id() const;
    size_t hash() const;
};

}  // namespace debug