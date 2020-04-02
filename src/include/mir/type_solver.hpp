#pragma once
#include "include/algorithm/union_find/union_find.hpp"
#include "include/mir/type.hpp"

namespace mir {
class Type;
}

namespace mir {
class TypeSolver {
    private:
    algorithm::UnionFindTree<std::shared_ptr<Type>> type_variables;

    public:
    void add_type_variable(std::shared_ptr<Type> type_variable);
    void bind(std::shared_ptr<Type> type_variable,
              std::shared_ptr<Type> depend_on);
    void fetch_type(std::shared_ptr<Type> type_variable,
                    std::shared_ptr<Type> to_fetch);
    std::shared_ptr<Type> solve(std::shared_ptr<Type> type_variable);
    const algorithm::UnionFindTree<std::shared_ptr<Type>>& get_all_types();
};
}  // namespace mir

/*
l = lazy l:lazy
l2 = l l2->l1
l = l2 l1->l2

*/