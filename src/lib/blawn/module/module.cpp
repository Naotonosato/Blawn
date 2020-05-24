#include "include/scope/scoped_collector.hpp"
#include "include/ast/node.hpp"
#include "include/blawn/module/module.hpp"

namespace module
{
Module::Module(std::string name) : name(name) {}

const std::string& Module::get_name() const { return name; }

}  // namespace module