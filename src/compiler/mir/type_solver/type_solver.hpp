#pragma once
#include "../../algorithm/union_find/union_find.hpp"
#include "../type/type.hpp"

namespace mir {
class TypeVariable;
}

namespace mir {
class TypeSolver {
    private:
    algorithm::UnionFindTree<std::shared_ptr<TypeVariable>> type_variables;

    public:
    void add_type_variable(std::shared_ptr<TypeVariable> type_variable);
    void bind(std::shared_ptr<TypeVariable> type_variable,
              std::shared_ptr<TypeVariable> depend_on);
    void fetch_type(std::shared_ptr<TypeVariable> type_variable,
                    std::shared_ptr<TypeVariable> to_fetch);
    std::shared_ptr<TypeVariable> solve(
        std::shared_ptr<TypeVariable> type_variable);
    const algorithm::UnionFindTree<std::shared_ptr<TypeVariable>>&
    get_all_types();
};
}  // namespace mir

/*
l = lazy l:lazy
l2 = l l2->l1
l = l2 l1->l2

*/