#include <vector>
#include <memory>
#include <string>

namespace llvm {
class Value;
}

namespace mir {
class TypeVariable;
}
// forward declarations

namespace mir {

class MIR {
    private:
    std::shared_ptr<TypeVariable> type;
    uint64_t line_number;

    public:
    MIR(std::shared_ptr<TypeVariable>&& type, uint64_t line_number)
        : type(std::move(type)), line_number(line_number) {}
    std::string print();
};

class Integer {};

class Float {};

class String {};

class BinaryExpression {};

class Array {};

class Store {};

class Variable {};

class GlobalVariable {};

class AllocateHeap {};

class FreeHeap {};

class Block {
    private:
    std::vector<std::shared_ptr<MIR>> body;
    std::vector<std::shared_ptr<Block>> from_blocks;
    std::vector<std::shared_ptr<Block>> to_blocks;
};

class Jump {
    private:
    std::shared_ptr<Block> to;
    std::shared_ptr<Block> from;
};

class CallFunction {
    private:
    std::shared_ptr<Block> function;
    std::vector<std::shared_ptr<MIR>> arguments;
};

class Argument {};

class Cast {};

}  // namespace mir

/*
AST->MIR->solve type
MIR->LLVM IR
*/