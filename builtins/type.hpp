#include <string>
#include <vector>
#include <memory>
#include <llvm/ADT/APInt.h>
#include <llvm/ADT/APFloat.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/Value.h>

class Type
{
public:
    std::string type_name;
    std::shared_ptr<llvm::Type> type;
    Type(std::string type_name):type_name(type_name){}
};