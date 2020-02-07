#include <vector>
#include <memory>
#include <string>

namespace llvm {
class Value;
}

namespace mir {
class Type;
}
// forward declarations

namespace mir {

class MIR {
    private:
    std::unique_ptr<Type> type;
    long long line_number;

    public:
    MIR(std::unique_ptr<Type>&& type,long long line_number):type(std::move(type)),line_number(line_number){}
    std::string print();
    void fetch_type(std::shared_ptr<Type> new_type);
    void depend(std::shared_ptr<MIR>);
    void depend(std::vector<std::shared_ptr<Block>>);
};

class Integer : public MIR {};

class Float : public MIR {};

class String : public MIR {};

class BinaryExpression : public MIR {};

class Array : public MIR {};

class Store : public MIR {};

class Variable : public MIR {};

class GlobalVariable : public MIR {};

class AllocateHeap : public MIR {};

class FreeHeap : public MIR {};

class Block : public MIR {
    private:
    std::vector<std::shared_ptr<MIR>> body;
    std::vector<std::shared_ptr<Block>> from_blocks;
    std::vector<std::shared_ptr<Block>> to_blocks;
};

class Jump : public MIR {
    private:
    std::shared_ptr<Block> to;
    std::shared_ptr<Block> from;
};

class CallFunction : public MIR {
    private:
    std::shared_ptr<Block> function;
    std::vector<std::shared_ptr<MIR>> arguments;
};

class Argument : public MIR {};

class Cast : public MIR {};

}  // namespace mir