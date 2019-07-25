#pragma once
#include <vector>
#include <string>
#include <map>
#include <memory>
#include <iostream>


class Node;
class IntergerIRGenerator;
class FloatIRGenerator;
namespace llvm
{
    class Module;
    template<typename T,typename Inserter>
    class IRBuilder;
}

 
class ASTGenerator
{
public:
    ~ASTGenerator();
private:
    llvm::Module const& module;
    llvm::IRBuilder<> const& ir_builder;
    std::vector<std::string> current_namespace;
    std::map<
        std::vector<std::string>,
        std::map<std::string,std::shared_ptr<Node>>
            > 
        variables;
public:
    std::shared_ptr<IRGenerator> ir_generator;
    std::shared_ptr<IRGenerator> int_ir_generator;
    std::shared_ptr<IRGenerator> float_ir_generator;
    std::shared_ptr<Node> attach_operator(std::shared_ptr<Node> node,std::shared_ptr<Node> other,const std::string operator_type);
    ASTGenerator(llvm::Module const& module,llvm::IRBuilder<> const& ir_builder);
    void into_namespace(std::string name);
    void break_out_of_namespace();
    std::shared_ptr<Node> add_variable(std::string name,std::shared_ptr<Node> node);
    std::shared_ptr<Node> get_variable(std::string name);
    void generate();
};