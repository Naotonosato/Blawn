#include "include/mir/type.hpp"
#include "include/mir/type_solver.hpp"
#include "include/mir/module.hpp"

namespace mir {
TypeSolver& Module::get_type_solver() { return type_solver; }
}  // namespace mir
