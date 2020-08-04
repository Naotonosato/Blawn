#pragma once
#include <memory>
#include "include/blawn/visitors/visitor.hpp"

namespace ast
{
class IntegerNode;
class FloatNode;
class ArrayNode;
class StringNode;
class VariableNode;
class BinaryExpressionNode;
class VariableNode;
class GlobalVariableNode;
class ArgumentNode;
class AssignmentNode;
class GenericFunctionNode;
class CallFunctionNode;
class AccessElementNode;
class DeepCopyNode;
class BlockNode;
class IfNode;
class ForNode;
class GenericFunctionDeclarationNode;
class GenericFunctionNode;
class GenericClassNode;
class TypeIdNode;
class CastNode;
}  // namespace ast

namespace mir
{
class MIR;
}

namespace blawn
{
namespace visitors
{
template class ASTVisitor<std::unique_ptr<mir::MIR>>;
using Converter = class ASTVisitor<std::unique_ptr<mir::MIR>>;
}  // namespace visitors
}  // namespace blawn