#include <string>
#include <memory>
#include <map>
#include <vector>
#include "../builtins/type.hpp"

class Node
{
public:  
    std::shared_ptr<Type> type;
    Node();
    Node(std::shared_ptr<Type> type):type(type){}
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