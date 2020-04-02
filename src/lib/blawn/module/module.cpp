#include "include/utils/scoped_collector.hpp"
#include "include/ast/node.hpp"
#include "include/blawn/module/module.hpp"

namespace module {

Module::Module(std::string name)
    : name(name),
      ast_container(
          std::make_unique<utils::ScopedCollector<std::shared_ptr<ast::Node>>>(
              "[GLOBAL]")) {}

const std::string& Module::get_name() const { return name; }

utils::ScopedCollector<std::shared_ptr<ast::Node>>&
Module::get_ast_container() {
    return *ast_container;
}
}  // namespace module