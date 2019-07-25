#include <string>
#include <vector>
#include <memory>

namespace llvm
{
    class Type;
}

class Type
{
public:
    std::string type_name;
    std::shared_ptr<llvm::Type> type;
    Type(std::string type_name):type_name(type_name){}
};