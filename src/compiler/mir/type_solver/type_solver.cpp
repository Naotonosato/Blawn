#include "../type/type.hpp"
#include "type_solver.hpp"


namespace mir{

    void TypeSolver::add_type_variable(std::shared_ptr<TypeVariable> type_variable)
    {
        type_variables.add_root(type_variable);
    }

    void TypeSolver::bind(
        std::shared_ptr<TypeVariable> type_variable,
        std::shared_ptr<TypeVariable> depend_on
        )
    {
        type_variables.unite(type_variable,depend_on);
        
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
    
    void TypeSolver::fetch_type(std::shared_ptr<TypeVariable> type_variable,std::shared_ptr<TypeVariable> to_fetch)
    {
        auto root = type_variables.get_root(type_variable);
        *root = std::move(*to_fetch);
    }
    
    std::shared_ptr<TypeVariable> TypeSolver::solve(std::shared_ptr<TypeVariable> type)
    {
        auto root = type_variables.get_root(type);
        return root;
    }

    const algorithm::UnionFindTree<std::shared_ptr<TypeVariable>>& TypeSolver::get_all_types()
    {
        return type_variables;
    }
}
