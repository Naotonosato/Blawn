#pragma once
#include <string>
#include <vector>
#include <map>
#include <set>
#include "include/mir/type_solver.hpp"

namespace mir {
class Type;
}  // namespace mir
// forward declarations

namespace mir {
class Module {
    private:
    TypeSolver type_solver;

    public:
    TypeSolver& get_type_solver();
};
}  // namespace mir