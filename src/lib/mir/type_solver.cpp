#include "include/mir/type.hpp"
#include "include/mir/type_solver.hpp"

namespace mir
{
void TypeSolver::add_type_variable(std::shared_ptr<Type> type_variable)
{
    type_variables.add_root(type_variable);
}

void TypeSolver::bind(std::shared_ptr<Type> type_variable,
                      std::shared_ptr<Type> depend_on)
{
    type_variables.unite(type_variable, depend_on);

    if (!type_variable->is_type<LazyType>())
    {
        auto root = type_variables.get_root(type_variable);
        *root = std::move(*type_variable);
    }
    if (!depend_on->is_type<LazyType>())
    {
        auto root = type_variables.get_root(type_variable);
        *root = std::move(*depend_on);
    }
}

void TypeSolver::fetch_type(std::shared_ptr<Type> type_variable,
                            std::shared_ptr<Type> to_fetch)
{
    auto root = type_variables.get_root(type_variable);
    *root = std::move(*to_fetch);
}

std::shared_ptr<Type> TypeSolver::solve(std::shared_ptr<Type> type)
{
    auto root = type_variables.get_root(type);
    return root;
}

const algorithm::UnionFindTree<std::shared_ptr<Type>>&
TypeSolver::get_all_types()
{
    return type_variables;
}
}  // namespace mir
