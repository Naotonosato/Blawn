#pragma once
#include <vector>
#include <memory>
#include <string>
#include "include/utils/variant_wrapper.hpp"
#include "include/debug/debug_info.hpp"

namespace llvm
{
class Value;
}

namespace mir
{
class Type;
}
// forward declarations

namespace mir
{
class MIRBase
{
    private:
    std::shared_ptr<Type> type;
    std::unique_ptr<debug::DebugInfo> debug_info;

    public:
    MIRBase(std::shared_ptr<Type> type,
            std::unique_ptr<debug::DebugInfo>&& debug_info)
        : type(std::move(type)), debug_info(std::move(debug_info))
    {
    }
};

class Integer
{
};

class Float
{
};

class String
{
};

class BinaryExpression
{
};

class Array
{
};

class Store
{
};

class Variable
{
};

class GlobalVariable
{
};

class AllocateHeap
{
};

class FreeHeap
{
};

class Block
{
    private:
    std::vector<std::shared_ptr<MIRBase>> body;
    std::vector<std::shared_ptr<Block>> from_blocks;
    std::vector<std::shared_ptr<Block>> to_blocks;
};

class Jump
{
    private:
    std::shared_ptr<Block> to;
    std::shared_ptr<Block> from;
};

class CallFunction
{
    private:
    std::shared_ptr<Block> function;
    std::vector<std::shared_ptr<MIRBase>> arguments;
};

class Argument
{
};

class Cast
{
};

class MIR
    : public utils::VariantWrapper<Integer, Float, String, BinaryExpression,
                                   Array, Store, Variable, GlobalVariable,
                                   AllocateHeap, FreeHeap, Block, Jump,
                                   CallFunction, Argument, Cast>
{
    protected:
    template <class T>
    MIR(T&& initial_content)
        : utils::VariantWrapper<Integer, Float, String, BinaryExpression, Array,
                                Store, Variable, GlobalVariable, AllocateHeap,
                                FreeHeap, Block, Jump, CallFunction, Argument,
                                Cast>(std::move(initial_content))
    {
    }

    public:
    template <typename MIRType, typename... Args>
    static std::unique_ptr<MIR> create(Args&&... args)
    {
        auto mir = std::make_unique<CreateHelper<MIR>>(
            std::move(MIRType(std::forward<Args>(args)...)));
        return mir;
    }
};
}  // namespace mir

/*
AST->MIR->solve type
MIR->LLVM IR
*/