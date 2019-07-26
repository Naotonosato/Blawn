#include <string>
#include <memory>
#include <map>
#include <vector>

//------forward declaration------
class Type;
class IRGenerator;
namespace llvm
{
    class Value;
}
//------forward declaration------


class Node
{
public:  
    std::shared_ptr<Type> type;
    std::shared_ptr<Node> left_node;
    std::shared_ptr<Node> right_node;
    int int_num;
    double float_num;
    std::string string;
    std::shared_ptr<IRGenerator> ir_generator;
    Node(std::shared_ptr<Type> type,std::shared_ptr<IRGenerator> ir_generator)
    :type(type),ir_generator(ir_generator){}
    llvm::Value* generate();

};


class BinaryExpressionNode: public Node
{
public:
    std::string operator_kind;
};


class FunctionNode: public Node
{
    public:
        std::multimap<std::string,std::string> args_type;
};


class CallFunctionNode: public Node
{
    public:
        std::shared_ptr<Node> function;
        std::vector<std::shared_ptr<Node>> argments;
};