#include "type.hpp"
#include <iostream>

#include "../module/module.hpp"
#include <map>
namespace mir {


}


struct V{
    template <typename T> std::string operator()(T& arg)
    {
        return typeid(arg).name();
    }
};
#include "../type_solver/type_solver.hpp"

void dbg(mir::TypeSolver& ts,struct V v)
{
    auto t = ts.get_all_types().get_parents();
    for (auto& pair:t)
    {
        if (pair.first != pair.second)
        std::cout << pair.first->accept(v) << " depends on " << pair.second->accept(v) << std::endl;
    }
}

int main()
{
    auto module = std::make_shared<mir::Module>();
    auto v = V();
    auto integer = mir::TypeVariable::create<mir::IntegerType>(module);
    auto& TS = module->get_type_solver();
    std::vector<std::shared_ptr<mir::TypeVariable>> tvs(1000000);
    for (int i=0; i<1000000; ++i)
    {
        if (i % 2) tvs[i] = mir::TypeVariable::create(module);
        else tvs[i] = mir::TypeVariable::create<mir::IntegerType>(module);
    }
    auto lazy1 = mir::TypeVariable::create<>(module);
    std::cout << "================================" << std::endl;
    for (int i=0; i<1000000; ++i)
    {
        auto lazy_i = tvs[i];
        if (i == 0) TS.bind(lazy_i,lazy1);
        else TS.bind(lazy_i,tvs[i-1]);
    }
    std::cout << "mid\n";
    TS.bind(lazy1,integer);
    std::cout << "================================" << std::endl;
    auto solved = TS.solve(tvs.back());
    std::cout << solved->accept(v) << std::endl;
    dbg(TS,v);
}

/*
clang++ -c ../module/module.cpp -std=c++2a;
clang++ -c ../type_solver/type_solver.cpp -std=c++2a;
clang++ type.cpp type_solver.o module.o -std=c++2a;
./a.out
*/