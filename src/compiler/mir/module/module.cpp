#include "../type/type.hpp"
#include "../type_solver/type_solver.hpp"
#include "module.hpp"


namespace mir
{
    TypeSolver& Module::get_type_solver()
    {
        return type_solver;
    }
}
