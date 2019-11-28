#pragma once
#include <cstddef>
#include <istream>
#include "parser.tab.hh"
#include "scanner.hpp"

namespace Blawn {

class Driver {
public:
  std::shared_ptr<ASTGenerator> ast_generator;
  Driver(std::shared_ptr<ASTGenerator> ast_generator) : ast_generator(ast_generator){};
  virtual ~Driver();
  void parse(const char* const filename);
  void parse(std::istream& iss);
  Blawn::Scanner* scanner = nullptr;

private:
  void parse_helper(std::istream& stream);
  Blawn::Parser* parser = nullptr;
};

} // namespace Blawn
