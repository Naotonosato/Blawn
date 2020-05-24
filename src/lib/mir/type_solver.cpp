#include "include/mir/type.hpp"
#include "include/mir/type_solver.hpp"

namespace mir
{
void TypeSolver::add_type_variable(std::shared_ptr<Type> new_type)
{
    type_tree.add_root(new_type);
}

void TypeSolver::bind(std::shared_ptr<Type> type,
                      std::shared_ptr<Type> depend_on)
{
    type_tree.unite(type, depend_on);

    if (!type->is_type<LazyType>())
    {
        auto root = type_tree.get_root(type);
        //*root = std::move(*type_variable);
        root.swap(type);
    }
    if (!depend_on->is_type<LazyType>())
    {
        auto root = type_tree.get_root(type);
        //*root = std::move(*depend_on);
        root.swap(depend_on);
    }
}

void TypeSolver::fetch_type(std::shared_ptr<Type> type_variable,
                            std::shared_ptr<Type> to_fetch)
{
    auto root = type_tree.get_root(type_variable);
    //*root = std::move(*to_fetch);
    root.swap(to_fetch);
}

std::shared_ptr<Type> TypeSolver::solve(std::shared_ptr<Type> type)
{
    auto root = type_tree.get_root(type);
    return root;
}

const algorithm::UnionFindTree<std::shared_ptr<Type>>&
TypeSolver::get_all_types()
{
    return type_tree;
}
}  // namespace mir
