#include <memory>
#include <variant>
#include "../ast/node.hpp"
namespace ast {
NodeBase;
}

namespace mir {
class Module;
class Module;
class Builder;

class MIR;
}  // namespace mir

namespace mir {

class ExpressionGenerator {
    private:
    Module &context;
    Module &module;

    public:
    ExpressionGenerator(Module &context, Module &module)
        : context(context), module(module) {}

    std::unique_ptr<MIR> operator()(std::nullptr_t &node);
    std::unique_ptr<MIR> operator()(ast::IntegerNode &node);
    std::unique_ptr<MIR> operator()(ast::FloatNode &node);
    std::unique_ptr<MIR> operator()(ast::ArrayNode &node);
    std::unique_ptr<MIR> operator()(ast::StringNode &node);
    std::unique_ptr<MIR> operator()(ast::ArgumentNode &node);
    std::unique_ptr<MIR> operator()(ast::AssignmentNode &node);
    std::unique_ptr<MIR> operator()(ast::DeepCopyNode &node);
};
}  // namespace mir
   // namespace mir
   /*
   namespace mir {
   class MIRGenerator {
       public:
       Context &context;
       Module &module;
       Builder &builder;
       MIRGenerator(Context &context, Module &module, Builder &ir_builder)
           : context(context), module(module), builder(builder) {}
       MIRGenerator &operator=(const MIRGenerator &) = default;
   
       std::shared_ptr<Value> operator()(Node &node);
       std::shared_ptr<Value> operator()(IntegerNode &node);
   };
   
   class IntegerMIRGenerator : public MIRGenerator {
       public:
       IntegerMIRGenerator(Context &context, Module &module, Builder &ir_builder)
           : MIRGenerator(context, module, builder) {}
       std::shared_ptr<Value> generate(Node &node) override;
   };
   
   class FloatMIRGenerator : public MIRGenerator {
       public:
       FloatMIRGenerator(Context &context, Module &module, Builder &ir_builder)
           : MIRGenerator(context, module, builder) {}
   };
   
   class StringMIRGenerator : public MIRGenerator {
       public:
       StringMIRGenerator(Context &context, Module &module, Builder &ir_builder)
           : MIRGenerator(context, module, builder) {}
   };
   
   class ArrayMIRGenerator : public MIRGenerator {
       public:
       ArrayMIRGenerator(Context &context, Module &module, Builder &ir_builder)
           : MIRGenerator(context, module, builder) {}
   };
   
   class ArgumentMIRGenerator : public MIRGenerator {};
   
   class AssigmentMIRGenerator : public MIRGenerator {};
   
   class DeepCopyMIRGenerator : public MIRGenerator {};
   
   class BinaryExpressionMIRGenerator : public MIRGenerator {};
   
   class FunctionMIRGenerator : public MIRGenerator {};
   
   class DeclareCIRGenerator : public MIRGenerator {};
   
   class SizeofGenerator : public MIRGenerator {};
   
   class TypeIdGenerator : public MIRGenerator {};
   
   class CastIRGenerator : public MIRGenerator {};
   
   class NullIRGenerator : public MIRGenerator {};
   
   class CallFunctionIRGenerator : public MIRGenerator {};
   
   class ClassIRGenerator : public MIRGenerator {};
   
   class CallConstructorIRGenerator : public MIRGenerator {};
   
   class IfIRGenerator : public MIRGenerator {};
   
   class AccessIRGenerator : public MIRGenerator {};
   
   class ForIRGenerator : public MIRGenerator {};
   
   class ListIRGenerator : public MIRGenerator {};
   
   class BlockEndIRGenerator : public MIRGenerator {};
   
   }  // namespace mir
   */