#include "ast_generator.hpp"
#include <iostream>
#include <vector>
#include <map>


void ASTGenerator::generate()
{/*
    for (int i=0;i<nodes.size();i++)
    {
        //nodes[i]->generate();
    }
*/
}

void ASTGenerator::add_variable(std::string name,std::shared_ptr<Node> value)
{
    std::cout << "name is: " << name;
    variables.emplace(name,std::move(value));
}

std::shared_ptr<Node> ASTGenerator::attach_operator(std::shared_ptr<Node> node,std::shared_ptr<Node> other,const std::string operator_type)
{
    /*try
    {
        auto special_method = node->special_methods.at(operator_type);
        std::vector<std::shared_ptr<Node>> arg;
        arg.push_back(other);   
        auto res = std::shared_ptr<Node>(new CallFunctionNode(special_method,arg));
        return res;
    }
    catch (std::out_of_range)
    {
        return node; 
    }*/
    return node;
}
