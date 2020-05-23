#include "include/mir/type.hpp"
#include <iostream>

#include <map>
#include "include/mir/type_solver.hpp"
#include "include/mir/module.hpp"

struct V {
    template <typename T>
    std::string operator()(T& arg) {
        return typeid(arg).name();
    }
};

void dbg(mir::TypeSolver& ts, struct V v) {
    auto t = ts.get_all_types().get_parents();
    for (auto& pair : t) {
        if (pair.first != pair.second)
            std::cout << pair.first->accept(v) << " depends on "
                      << pair.second->accept(v) << std::endl;
    }
}

int main() {
    auto module = std::make_shared<mir::Module>();
    auto v = V();
    auto integer = mir::Type::create<mir::FunctionType>(module);
    auto& TS = module->get_type_solver();
    std::vector<std::shared_ptr<mir::Type>> tvs(1000000);
    for (int i = 0; i < 1000000; ++i) {
        if (i % 2)
            tvs[i] = mir::Type::create(module);
        else
            tvs[i] = mir::Type::create<mir::FunctionType>(module);
    }
    auto lazy1 = mir::Type::create<>(module);
    std::cout << "================================" << std::endl;
    for (int i = 0; i < 1000000; ++i) {
        auto lazy_i = tvs[i];
        if (i == 0)
            TS.bind(lazy_i, lazy1);
        else
            TS.bind(lazy_i, tvs[i - 1]);
    }
    std::cout << "mid\n";
    TS.bind(lazy1, integer);
    std::cout << "================================" << std::endl;
    auto solved = TS.solve(tvs.back());
    std::cout << solved->accept(v) << std::endl;
    dbg(TS, v);
}



/*
clang++ -c ../src/lib/mir/module.cpp -std=c++17 -I../src;
clang++ -c ../src/lib/mir/type_solver.cpp -std=c++17 -I../src;
clang++ ../src/lib/mir/type.cpp type_solver.o module.o -std=c++17 -I../src;
./a.out
*/
