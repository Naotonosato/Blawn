#pragma once
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
    llvm::Type* type;
    Type(std::string type_name,llvm::Type* llvm_type=nullptr)
    :type_name(type_name),type(llvm_type){}
};