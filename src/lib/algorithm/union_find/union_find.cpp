#include <string>
#include <memory>
#include <iostream>
#include "union_find.hpp"

class Type
{
    public:
    std::string name;
    Type() : name("LAZY") {}
    Type(std::string name) : name(name) {}
};

void dump(algorithm::UnionFindTree<std::shared_ptr<Type>> t)
{
    for (auto& node_pair : t.get_parents())
    {
        auto child = node_pair.first;
        auto parent = t.get_root(child);
        std::cout << child->name << " 's root is " << parent->name << std::endl;
    }
}

int main()
{
    auto it = std::make_shared<Type>("INT");
    auto lt = std::make_shared<Type>("LAZY");
    auto t1 = std::make_shared<Type>("1");
    auto t2 = std::make_shared<Type>("2");
    auto t3 = std::make_shared<Type>("3");
    algorithm::UnionFindTree<std::shared_ptr<Type>> uft;
    uft.add_root(it);
    uft.add_node(t1, it);
    if (!uft.has_parent(it)) uft.add_node(it, t1);
    uft.add_root(lt);
    uft.add_node(t3, lt);
    dump(uft);
    uft.unite(t1, t3);
    std::cout << "\nfind" << std::endl;
    auto root = uft.get_root(t3);
    std::cout << root->name << std::endl;
    std::shared_ptr<int> ip(new int(10));
    *ip = 200;
    // dump(uft);
    std::cout << "\nnum" << *ip << std::endl;
}