#include <llvm/ADT/APFloat.h>
#include <llvm/ADT/APInt.h>
#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/Constants.h>
#include <llvm/IR/DataLayout.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/GlobalVariable.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Instructions.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/Value.h>
#include <llvm/IR/Verifier.h>
#include <llvm/Support/raw_ostream.h>
#include <llvm/Transforms/Utils/Cloning.h>
#include <iostream>
#include <set>
#include "../ast/node.hpp"
#include "../blawn_context/blawn_context.hpp"
#include "../builtins/builtins.hpp"
#include "../errors/errors.hpp"
#include "../global_configuration/global_configuration.hpp"
#include "../utils/utils.hpp"
#include "ir_generator.hpp"

bool check_parameter(llvm::Function* func, std::vector<llvm::Type*> passed) {
    return func->arg_size() == passed.size();
}

void initialize(llvm::LLVMContext& context, llvm::Module& module,
                llvm::IRBuilder<>& ir_builder) {
    // declare malloc
    std::vector<llvm::Type*> malloc_types(1, ir_builder.getInt64Ty());
    auto malloc_declaration_type = llvm::FunctionType::get(
        ir_builder.getInt64Ty()->getPointerTo(), malloc_types, false);
    llvm::Function::Create(malloc_declaration_type,
                           llvm::Function::ExternalLinkage, "malloc", &module);
    // declare free
    std::vector<llvm::Type*> free_types(
        1, ir_builder.getInt64Ty()->getPointerTo());
    auto free_declaration_type =
        llvm::FunctionType::get(ir_builder.getVoidTy(), free_types, false);
    llvm::Function::Create(free_declaration_type,
                           llvm::Function::ExternalLinkage, "free", &module);
    // create builtin string type
    builtins::create_string_type(context, module, ir_builder);
    // load builtins
    builtins::load_builtin_functions(context,module, ir_builder);
    // builtins::load_builtins(context,module);
    // create main function
    std::vector<llvm::Type*> main_types;
    auto function_type = llvm::FunctionType::get(llvm::Type::getInt8Ty(context),
                                                 main_types, false);
    auto function = llvm::Function::Create(
        function_type, llvm::Function::ExternalLinkage, "main", &module);
    auto block = llvm::BasicBlock::Create(context, "entry", function);
    ir_builder.SetInsertPoint(block);
}

IRGenerator::IRGenerator(llvm::LLVMContext& context, llvm::Module& module,
                         llvm::IRBuilder<>& ir_builder)
    : context(context), module(module), ir_builder(ir_builder) {
    static bool initialized = false;
    if (!initialized) {
        initialize(context, module, ir_builder);
        initialized = true;
    }
}

llvm::Value* IRGenerator::generate(Node& node) {
    /*
    std::cout << "Warning: calling not implemented ir generator function" <<
    std::endl; std::cout << "For degug:\n line number: " << node.line_number <<
    std::endl; std::cout << "node name: " << node.name << std::endl; std::cout
    << "node object's address: " << &node << std::endl; std::cout << "...Done
    report"
    << std::endl;
    */
    return 0;
}

llvm::Value* SizeofGenerator::generate(Node& node_) {
    auto& node = *static_cast<SizeofNode*>(&node_);
    auto type = node.get_value()->generate()->getType();
    return ir_builder.getInt64(utils::get_sizeof(type, module));
}

llvm::Value* TypeIdGenerator::generate(Node& node_) {
    auto& node = *static_cast<TypeIdNode*>(&node_);
    auto type = node.get_value()->generate()->getType();
    auto id = get_blawn_context().get_typeid(context, type);
    node.set_id(id);
    return id;
}

llvm::Value* CastIRGenerator::generate(Node& node_) {
    auto& node = *static_cast<CastNode*>(&node_);
    BlawnLogger logger;
    logger.set_line_number(node.line_number);
    if (node.get_idnode()->is_typeid()) {
        node.get_idnode()->generate();
        auto id = node.get_idnode()->get_id();
        auto id_assigned_type = get_blawn_context().get_type_with_id(id);
        auto value = node.get_value()->generate();
        if (id_assigned_type == nullptr) {
            logger.invalid_cast_error("?", utils::to_string(value->getType()));
            return 0;
        }
        if (value->getType()->isPointerTy()) {
            if (value->getType() == ir_builder.getInt8PtrTy()) {
                auto p = ir_builder.CreateBitCast(
                    value, id_assigned_type->getPointerTo());
                return ir_builder.CreateLoad(p);
            }
            return ir_builder.CreateBitCast(value, id_assigned_type);
        }
        logger.invalid_cast_error(utils::to_string(value->getType()),
                                  utils::to_string(value->getType()));
        return 0;
    } else {
        logger.invalid_cast_error("<?>", "<?>");
        return 0;
    }
}

llvm::Type* _get_C_type();

llvm::Value* NullIRGenerator::generate(Node& node_) {
    auto& node = *static_cast<NullNode*>(&node_);
    BlawnLogger logger;
    logger.set_line_number(node.line_number);
    std::vector<std::string> real_num_types = {"__C_DOUBLE__", "__C_FLOAT__",
                                               "__C_LONGDOUBLE__"};
    std::vector<std::string> unsigned_types = {"__C_UCHAR__", "__C_UINT__",
                                               "__C_ULONG__", "__C_ULONGLONG__",
                                               "__C_USHORT__"};

    std::vector<std::string> builtin_C_types = {
        "__C_BOOL__",     "__C_CHAR__",   "__C_CHAR__",      "__C_DOUBLE__",
        "__C_FLOAT__",    "__C_INT__",    "__C_LONG__",      "__C_LONGDOUBLE__",
        "__C_LONGLONG__", "__C_SCHAR__",  "__C_SHORT__",     "__C_UCHAR__",
        "__C_UINT__",     "__C_ULONG__",  "__C_ULONGLONG__", "__C_USHORT__",
        "__C_WCHAR__",    "__C_UNKNOWN__"};
    std::vector<std::string> parsed;
    utils::split(node.type_name, "__PTR__ ", parsed);
    std::string type_name = parsed.back();
    utils::replace(type_name, " ", "");
    std::vector<std::string> res;
    utils::split(type_name, std::string("SIZE_"), res);
    if (type_name == "__C_VOID__") {
        return nullptr;
    }
    if ((res.back() == "" or res.size() <= 1) && node.class_node == nullptr) {
        logger.unknown_identifier_error("type name or variable",
                                        node.type_name);
    }
    parsed.pop_back();

    if (node.class_node == nullptr) {
        unsigned int type_size = std::stoi(res.back().c_str()) * 8;
        type_name = res.front();
        utils::replace(type_name, " ", "");
        bool is_real_num_type = utils::exist(real_num_types, type_name);
        bool is_unsigned = utils::exist(unsigned_types, type_name);
        if (utils::exist(builtin_C_types, type_name)) {
            if (parsed.size() == 0) {
                if (!is_real_num_type)
                    return llvm::ConstantInt::get(
                        context, llvm::APInt(type_size, 0, is_unsigned));
                return llvm::ConstantFP::get(context, llvm::APFloat(0.0));
            }
            llvm::Type* type = is_real_num_type
                                   ? ir_builder.getFloatTy()
                                   : ir_builder.getIntNTy(type_size);
            for (auto& _ : parsed) {
                type = type->getPointerTo();
            }
            auto ptype = llvm::dyn_cast<llvm::PointerType>(type);
            return llvm::ConstantPointerNull::get(ptype);
        } else {
            logger.unknown_identifier_error("type name or variable", type_name);
            return 0;
        }
    } else {
        auto type = utils::get_or_create_type(context, node.class_node,
                                              node.class_node->name);
        auto constructor_type =
            llvm::FunctionType::get(type->getPointerTo(), false);
        auto constructor = llvm::Function::Create(
            constructor_type, llvm::Function::ExternalLinkage,
            node.class_node->name, &module);
        auto constructor_entry =
            llvm::BasicBlock::Create(context, "entry", constructor);
        auto previous_block = ir_builder.GetInsertBlock();
        ir_builder.SetInsertPoint(constructor_entry);
        ir_builder.CreateRet(
            utils::malloc_value(type, context, module, ir_builder));
        ir_builder.SetInsertPoint(previous_block);
        node.class_node->register_constructor({}, constructor);
        if (parsed.size()) {
            for (auto& _ : parsed) {
                type = type->getPointerTo();
            }
            auto ptype = llvm::dyn_cast<llvm::PointerType>(type);
            return llvm::ConstantPointerNull::get(ptype);
        } else {
            return ir_builder.CreateLoad(ir_builder.CreateAlloca(type, 0, ""));
        }
    }
}

llvm::Value* IntegerIRGenerator::generate(Node& node) {
    return llvm::ConstantInt::get(context, llvm::APInt(64, node.int_num, true));
}

llvm::Value* FloatIRGenerator::generate(Node& node) {
    return llvm::ConstantFP::get(context, llvm::APFloat(node.float_num));
}

llvm::Value* StringIRGenerator::generate(Node& node) {
    std::string str = node.string;
    auto ptr = ir_builder.CreateGlobalStringPtr(str,str);
    auto length =
        llvm::ConstantInt::get(context, llvm::APInt(64, str.size()));
    std::vector<llvm::Value*> args;
    args.push_back(ptr);
    args.push_back(length);
    auto string = ir_builder.CreateCall(module.getFunction("string_constructor"),
                                 args);
    return string;
}

llvm::Value* VariableIRGenerator::generate(Node& node_) {
    auto& node = *static_cast<VariableNode*>(&node_);
    BlawnLogger logger;
    logger.set_line_number(node.line_number);
    if (!node.is_generated()) {
        llvm::Value* right;
        if (node.generated_right_values.count(node.right_node)) {
            right = node.generated_right_values[node.right_node];
        } else
            right = node.right_node->generate();
        if (right == nullptr) logger.invalid_right_value_error();
        if (node.is_global()) {
            auto gvalue = new llvm::GlobalVariable(
                module, right->getType(), false,
                llvm::GlobalVariable::ExternalLinkage,
                llvm::Constant::getNullValue(right->getType()), node.name);
            node.global_ptr = gvalue;
            ir_builder.CreateStore(right, gvalue);
            node.generated();
            return ir_builder.CreateLoad(node.global_ptr);
        }
        /*
        if (right->getType()->isPointerTy())
        {
            auto load = ir_builder.CreateLoad(right);
            node.alloca_inst =
        ir_builder.CreateAlloca(load->getType(),0,node.name); auto s =
        ir_builder.CreateStore(load,node.alloca_inst); node.generated();
            std::cout << utils::to_string(s) << std::endl;
        }
        else*/
        {
            node.alloca_inst =
                ir_builder.CreateAlloca(right->getType(), 0, node.name);
            ir_builder.CreateStore(right, node.alloca_inst);
            node.generated();
        }
        return ir_builder.CreateLoad(node.alloca_inst);

    } else {
        if (node.alloca_inst != nullptr)
            return ir_builder.CreateLoad(node.alloca_inst);
        if (node.global_ptr != nullptr)
            return ir_builder.CreateLoad(node.global_ptr);
    }
}

llvm::Value* AssigmentIRGenerator::generate(Node& node_) {
    auto& node = *static_cast<AssigmentNode*>(&node_);
    BlawnLogger logger;
    logger.set_line_number(node.line_number);
    llvm::Value* pointer;
    std::shared_ptr<Node> left_node;
    std::shared_ptr<Node> right_node = node.get_right_node();
    if (node.get_target_var() != nullptr) {
        node.get_target_var()->generate();
        left_node = node.get_target_var();
        pointer = node.get_target_var()->alloca_inst;
        if (pointer == nullptr) pointer = node.get_target_var()->global_ptr;
    }
    if (node.get_target_member() != nullptr) {
        node.get_target_member()->generate();
        pointer = node.get_target_member()->get_pointer();
        left_node = node.get_target_member();
    }
    if (node.target_arg != nullptr) {
        pointer = node.target_arg->alloca_inst;
        left_node = node.target_arg;
    }

    auto right_value = node.get_right_node()->generate();
    if (right_value == nullptr) logger.invalid_right_value_error();

    if (right_value->getType()->isPointerTy() &&
        left_node->self_scope.is_longer(right_node->self_scope)) {
        logger.assignment_different_scope_error(
            utils::to_string(left_node->self_scope),
            utils::to_string(right_node->self_scope));
    }

    auto to_store = right_value;
    if (pointer->getType()->getPointerElementType()->isIntegerTy() &&
        right_value->getType()->isDoubleTy()) {
        to_store =
            ir_builder.CreateFPToSI(right_value, ir_builder.getInt64Ty());
    }
    if (right_value->getType() == ir_builder.getInt8PtrTy()) {
        // auto to_store_ = ir_builder.CreateLoad(to_store);
        to_store = ir_builder.CreateBitCast(
            right_value, pointer->getType()->getPointerElementType());
    }
    if (pointer->getType()->getPointerElementType() != to_store->getType()) {
        BlawnLogger logger;
        logger.set_line_number(node.line_number);
        logger.different_type_error(
            utils::to_string(pointer->getType()->getPointerElementType()),
            utils::to_string(to_store->getType()));
    }
    ir_builder.CreateStore(to_store, pointer);
    return ir_builder.CreateLoad(pointer);
}

void walk(llvm::Type* type,
          std::vector<std::pair<llvm::Value*, llvm::Value*>>& res,
          StoreNode& node, llvm::LLVMContext& context, llvm::Module& module,
          llvm::IRBuilder<>& ir_builder, StoreIRGenerator& store_generator) {
    if (type->isPointerTy() && type->getPointerElementType()->isStructTy()) {
        std::string struct_name =
            type->getPointerElementType()->getStructName();
        auto field = get_blawn_context().get_elements(struct_name);

        auto gen = AccessIRGenerator(context, module, ir_builder);
        NodeCollector<FunctionNode> empty;
        std::shared_ptr<Node> p_node;
        std::shared_ptr<Node> o_node;

        for (auto& element : field) {
            auto element_name = element.first;
            utils::replace(element_name, "@", "");
            p_node = std::shared_ptr<Node>(
                new AccessNode(node.line_number, node.self_scope, gen,
                               node.pointer, element_name, empty));
            o_node = std::shared_ptr<Node>(
                new AccessNode(node.line_number, node.self_scope, gen,
                               node.object, element_name, empty));
            if (p_node->generate()->getType()->isPointerTy() &&
                p_node->generate()
                    ->getType()
                    ->getPointerElementType()
                    ->isStructTy()) {
                auto store_node = StoreNode(node.line_number, node.self_scope,
                                            store_generator, p_node, o_node);
                walk(p_node->generate()->getType(), res, store_node, context,
                     module, ir_builder, store_generator);
            } else {
                p_node->generate();
                auto element_object = o_node->generate();
                if (p_node->is_accessing()) {
                    llvm::Value* element_pointer =
                        static_cast<AccessNode*>(p_node.get())->get_pointer();
                    res.push_back(
                        std::make_pair(element_pointer, element_object));
                }
            }
        }
    }
}

void store(StoreNode& node, llvm::Value* pointer, llvm::Value* object,
           llvm::LLVMContext& context, llvm::Module& module,
           llvm::IRBuilder<>& ir_builder) {
    BlawnLogger logger;
    logger.set_line_number(node.line_number);
    /*if object-type is pointer,should load that ptr.
      but maybe object-type is ptr but that's not result of access(last
      element). in than case, pointer is ptr of ptr;
    */
    if (object->getType()->isPointerTy() &&
        !pointer->getType()->getPointerElementType()->isPointerTy())
        object = ir_builder.CreateLoad(object);
    if (!pointer->getType()->isPointerTy() ||
        pointer->getType()->getPointerElementType() != object->getType()) {
        // cannot store error
        logger.invalid_store_error(utils::to_string(pointer->getType()),
                                   utils::to_string(object->getType()));
    }
    ir_builder.CreateStore(object, pointer);
}

llvm::Value* StoreIRGenerator::generate(Node& node_) {
    auto& node = *static_cast<StoreNode*>(&node_);
    BlawnLogger logger;
    logger.set_line_number(node.line_number);
    auto pointer = node.pointer->generate();
    auto object = node.object->generate();
    if (object->getType()->isPointerTy())
        object = ir_builder.CreateLoad(object);
    if (node.pointer->is_accessing() && !pointer->getType()->isStructTy()) {
        pointer = (*static_cast<AccessNode*>(node.pointer.get())).get_pointer();
        bool is_break = false;
        if (pointer->getType()->getPointerElementType()->isPointerTy()) {
            pointer =
                node.pointer->generate();  // ir_builder.CreateLoad(pointer);
            is_break = true;
        }
        if (!pointer->getType()->getPointerElementType()->isPointerTy() &&
                !pointer->getType()->isPointerTy() ||
            pointer->getType()->getPointerElementType() != object->getType()) {
            logger.invalid_store_error(utils::to_string(pointer->getType()),
                                       utils::to_string(object->getType()));
        }
        if (!is_break) ir_builder.CreateStore(object, pointer);
    }
    std::vector<std::pair<llvm::Value*, llvm::Value*>> res;
    walk(pointer->getType(), res, node, context, module, ir_builder, *this);

    for (auto& pair : res) {
        auto ptr = pair.first;
        auto obj = pair.second;
        store(node, ptr, obj, context, module, ir_builder);
    }

    /*
    if (pointer->getType()->getPointerElementType()->isStructTy())
    {
        std::string struct_name =
    pointer->getType()->getPointerElementType()->getStructName(); auto field =
    get_blawn_context().get_elements(struct_name);

        auto gen = AccessIRGenerator(context,module,ir_builder);
        NodeCollector<FunctionNode> empty;
        std::shared_ptr<Node> p_node;
        std::shared_ptr<Node> o_node;

        for (auto& element:field)
        {
            auto element_name = element.first;
            utils::replace(element_name,"@","");
            std::cout << "store to " << struct_name << "." << element_name <<
    std::endl; p_node = std::shared_ptr<Node>( new
    AccessNode(node.line_number,node.self_scope,gen,node.pointer,element_name,empty)
                );
            o_node = std::shared_ptr<Node>(
                new
    AccessNode(node.line_number,node.self_scope,gen,node.object,element_name,empty)
                );
            if (p_node->generate()->getType()->isPointerTy())
            {auto re =
    StoreNode(node.line_number,node.self_scope,*this,p_node,o_node);
            generate(re);}


        }
    }
    //ir_builder.CreateStore(object,pointer);
    */
    return pointer;
}

llvm::Value* ArgumentIRGenerator::generate(Node& node_) {
    auto& node = *static_cast<ArgumentNode*>(&node_);
    return ir_builder.CreateLoad(node.alloca_inst);
}

llvm::Value* BinaryExpressionIRGenerator::generate(Node& node_) {
    auto& node = *static_cast<BinaryExpressionNode*>(&node_);

    auto operator_kind = node.operator_kind;
    auto left = node.left_node->generate();
    auto right = node.right_node->generate();
    bool both_int =
        (left->getType()->isIntegerTy() && right->getType()->isIntegerTy());
    auto f_cast = llvm::CastInst::SIToFP;

    std::set<llvm::Value*> false_values;
    false_values.insert(
        llvm::ConstantInt::get(context, llvm::APInt(64, 0, true)));
    false_values.insert(
        llvm::ConstantFP::get(context, llvm::APFloat(double(0.0))));
    false_values.insert(ir_builder.getInt1(false));

    if (operator_kind == "+") {
        if (both_int)
            return ir_builder.CreateAdd(left, right);
        else
            return ir_builder.CreateFAdd(
                ir_builder.CreateCast(f_cast, left, ir_builder.getDoubleTy()),
                ir_builder.CreateCast(f_cast, right, ir_builder.getDoubleTy()));
    }
    if (operator_kind == "-") {
        if (both_int)
            return ir_builder.CreateSub(left, right);
        else
            return ir_builder.CreateFSub(
                ir_builder.CreateCast(f_cast, left, ir_builder.getDoubleTy()),
                ir_builder.CreateCast(f_cast, right, ir_builder.getDoubleTy()));
    }
    if (operator_kind == "*") {
        if (both_int)
            return ir_builder.CreateMul(left, right);
        else
            return ir_builder.CreateFMul(
                ir_builder.CreateCast(f_cast, left, ir_builder.getDoubleTy()),
                ir_builder.CreateCast(f_cast, right, ir_builder.getDoubleTy()));
    }
    if (operator_kind == "/") {
        return ir_builder.CreateFDiv(
            ir_builder.CreateCast(f_cast, left, ir_builder.getDoubleTy()),
            ir_builder.CreateCast(f_cast, right, ir_builder.getDoubleTy()));
    }
    if (operator_kind == "==") {
        if (left->getType() != right->getType())
            return ir_builder.getInt1(false);
        else
            return ir_builder.CreateICmpEQ(left, right);
    }
    if (operator_kind == "!=") {
        if (left->getType() != right->getType())
            return ir_builder.getInt1(true);
        else
            return ir_builder.CreateICmpNE(left, right);
    }
    if (operator_kind == ">=") {
        if (both_int) {
            return ir_builder.CreateICmpSGE(left, right);
        } else {
            return ir_builder.CreateFCmpOGE(left, right);
        }
    }
    if (operator_kind == "<=") {
        if (both_int) {
            return ir_builder.CreateICmpSLE(left, right);
        } else {
            return ir_builder.CreateFCmpOLE(left, right);
        }
    }
    if (operator_kind == ">") {
        if (both_int) {
            return ir_builder.CreateICmpSGT(left, right);
        } else {
            return ir_builder.CreateFCmpOGT(left, right);
        }
    }
    if (operator_kind == "<") {
        if (both_int) {
            return ir_builder.CreateICmpSLT(left, right);
        } else {
            return ir_builder.CreateFCmpOLT(left, right);
        }
    }
    if (operator_kind == "and") {
        if ((false_values.find(left) == false_values.end()) &&
            (false_values.find(right) == false_values.end())) {
            return ir_builder.getInt1(true);
        } else
            return ir_builder.getInt1(false);
    }
    if (operator_kind == "or") {
        if ((false_values.find(left) == false_values.end()) ||
            (false_values.find(right) == false_values.end())) {
            return ir_builder.getInt1(true);
        } else
            return ir_builder.getInt1(false);
    }
    std::cout << "Error: invalid operator " << operator_kind << std::endl;
    exit(1);
    return 0;
}

llvm::Function* FunctionIRGenerator::generate(Node& node_) {
    auto& node = *static_cast<FunctionNode*>(&node_);
    std::vector<llvm::Type*> types;
    auto func_type =
        llvm::FunctionType::get(llvm::Type::getVoidTy(context), types, false);
    auto function = llvm::Function::Create(
        func_type, llvm::Function::ExternalLinkage, node.name, &module);
    node.set_temporary_function(function);
    return function;
}

llvm::Value* DeclareCIRGenerator::generate(Node& node_) {
    auto& node = *static_cast<DeclareCNode*>(&node_);
    BlawnLogger logger;
    logger.set_line_number(node.line_number);
    std::vector<llvm::Type*> arguments_type;
    for (auto& v : node.arguments_type()) {
        auto value = v->generate();
        if (value == nullptr) {
            logger.invalid_paramater_error(
                node.name + "(invalide declaration of argument)");
        }
        arguments_type.push_back(value->getType());
    }
    auto return_value = node.return_type()->generate();
    llvm::Type* return_type;
    if (return_value == nullptr) {
        return_type = ir_builder.getVoidTy();
    } else {
        return_type = return_value->getType();
    }
    llvm::FunctionType* ft = nullptr;
    if (arguments_type.size() == 0)
        ft = llvm::FunctionType::get(return_type, false);
    else
        ft = llvm::FunctionType::get(return_type, arguments_type, false);
    auto C_function = llvm::Function::Create(
        ft, llvm::Function::ExternalLinkage, node.name, &module);
    get_blawn_context().add_C_function(node.name, C_function);
    return 0;
}

llvm::Value* CallFunctionIRGenerator::generate(Node& node_) {
    auto& node = *static_cast<CallFunctionNode*>(&node_);
    BlawnLogger logger;
    logger.set_line_number(node.line_number);
    if (node.is_builtin) {
        for (auto& arg : node.passed_arguments) {
            if (arg->is_argument()) {
                if (static_cast<ArgumentNode*>(arg.get())->get_right_value() ==
                    nullptr) {
                    std::vector<llvm::Value*> empty_arg;
                    return ir_builder.CreateCall(node.builtin_function,
                                                 empty_arg);
                }
            }
        }
        std::vector<llvm::Value*> args;
        if (node.builtin_function->arg_size() != node.passed_arguments.size()) {
            logger.invalid_paramater_error("function");
        }

        int count = 0;
        for (auto& b_arg : node.builtin_function->args()) {
            auto& arg = node.passed_arguments[count];
            auto value = arg->generate();
            if (b_arg.getType() == ir_builder.getInt8PtrTy()) {
                auto casted =
                    ir_builder.CreateBitCast(value, ir_builder.getInt8PtrTy());
                args.push_back(casted);
            } else {
                if (value->getType() != b_arg.getType()) {
                    logger.invalid_paramater_error("function");
                }
                args.push_back(value);
            }
            count += 1;
        }
        return ir_builder.CreateCall(node.builtin_function, args);
    }

    // call C function
    if (node.is_C) {
        if (!get_blawn_context().exist_C_function(node.name)) {
            logger.unknown_identifier_error("function", node.name);
        }
        auto cfunc = get_blawn_context().get_C_function(node.name);
        for (auto& arg : node.passed_arguments) {
            if (arg->is_argument()) {
                if (static_cast<ArgumentNode*>(arg.get())->get_right_value() ==
                    nullptr) {
                    std::vector<llvm::Value*> empty_arg;
                    return ir_builder.CreateCall(cfunc, empty_arg);
                }
            }
        }
        std::vector<llvm::Value*> args;
        if (cfunc->arg_size() != node.passed_arguments.size()) {
            logger.invalid_paramater_error(node.name);
        }

        int count = 0;
        for (auto& c_arg : cfunc->args()) {
            auto& arg = node.passed_arguments[count];
            auto value = arg->generate();
            if (value->getType() != c_arg.getType()) {
                logger.invalid_paramater_error(node.name);
            }
            args.push_back(value);
            count += 1;
        }
        return ir_builder.CreateCall(cfunc, args);
    }
    //
    for (auto& arg : node.passed_arguments) {
        if (arg->is_argument()) {
            if (static_cast<ArgumentNode*>(arg.get())->get_right_value() ==
                nullptr) {
                std::vector<llvm::Value*> empty_arg;
                return ir_builder.CreateCall(
                    node.function->get_temporary_function(), empty_arg);
            }
        }
    }
    if (node.passed_arguments.size() != node.function->arguments_names.size()) {
        logger.invalid_paramater_error("function");
    }
    auto callee_block = ir_builder.GetInsertBlock();
    std::vector<llvm::Type*> types;
    std::vector<llvm::Value*> argument_values;
    for (auto& arg : node.passed_arguments) {
        auto v = arg->generate();
        types.push_back(v->getType());
        argument_values.push_back(v);
    }
    auto f = node.function->get_function(types);
    if (f != nullptr)
    // function is already generated
    {
        return ir_builder.CreateCall(f, argument_values);
    }
    auto base_function_type =
        llvm::FunctionType::get(ir_builder.getVoidTy(), types, false);
    auto base_function = llvm::Function::Create(base_function_type,
                                                llvm::Function::ExternalLinkage,
                                                node.function->name, &module);
    node.function->set_base_function(base_function);

    auto block = llvm::BasicBlock::Create(context, "entry", base_function);
    ir_builder.SetInsertPoint(block);

    if (node.function->arguments_names.size()) {
        int count = 0;
        for (auto& tmp_func_arg : base_function->args()) {
            std::string name = node.function->arguments_names[count];
            tmp_func_arg.setName(name);
            auto local = node.function->get_self_namespace();
            auto empty_node = node.argument_collector.get(name, local);
            empty_node->alloca_inst =
                ir_builder.CreateAlloca(tmp_func_arg.getType(), 0, 0);
            ir_builder.CreateStore(&tmp_func_arg, empty_node->alloca_inst);

            /*
            empty_node->alloca_inst =
                ir_builder.CreateAlloca(tmp_func_arg.getType(), 0, 0);
            ir_builder.CreateStore(&tmp_func_arg, empty_node->alloca_inst);
            empty_node->set_right_value(
                ir_builder.CreateLoad(empty_node->alloca_inst));
            empty_node->alloca_inst;
            */
            empty_node->set_right_value(&tmp_func_arg);
            count += 1;
        }
    }
    // auto destruction_block = llvm::BasicBlock::Create(context,"destruction");
    // auto merge = llvm::BasicBlock::Create(context,"merge");
    for (auto& line : node.function->body) {
        line->initialize();
        line->generate();
    }

    // auto ds = get_blawn_context().get_destructors(block);
    // std::string n = block->getParent()->getName(); // print(llvm::outs());
    // std::cout << "function name: " << n << " num of heap pointer: "<<
    // ds.size()
    // << std::endl;

    /*
    for (auto& d:ds)
    {
        ir_builder.CreateCall(d.first,d.second);
        std::string n = d.first->getName();
        std::cout << "call: " << n << std::endl;
        //f->print(llvm::outs());
    }
    */

    llvm::Value* return_value;
    llvm::Type* return_type;
    if (node.function->return_value != nullptr) {
        return_value = node.function->return_value->generate();
        ir_builder.CreateRet(return_value);
        return_type = return_value->getType();
    } else {
        ir_builder.CreateRetVoid();
        return_type = ir_builder.getVoidTy();
    }

    auto new_function_type = llvm::FunctionType::get(return_type, types, false);
    auto new_function = llvm::Function::Create(new_function_type,
                                               llvm::Function::ExternalLinkage,
                                               node.function->name, &module);

    llvm::ValueToValueMapTy vmap;

    auto new_arg = new_function->arg_begin();
    for (auto& tmp_arg : base_function->args()) {
        new_arg->setName(tmp_arg.getName());
        vmap[&tmp_arg] = new_arg;
        new_arg++;
    }

    llvm::SmallVector<llvm::ReturnInst*, 0> returns;
    llvm::CloneFunctionInto(new_function, base_function, vmap, false, returns);

    node.function->register_function(types, new_function);
    // node.function->get_temporary_function()->replaceAllUsesWith(new_function);

    ir_builder.SetInsertPoint(callee_block);
    return ir_builder.CreateCall(new_function, argument_values);
}

llvm::Value* ClassIRGenerator::generate(Node& node_) {
    auto& node = *static_cast<ClassNode*>(&node_);
    std::vector<llvm::Type*> types;
    auto type =
        llvm::FunctionType::get(llvm::Type::getVoidTy(context), types, false);
    auto constructor = llvm::Function::Create(
        type, llvm::Function::ExternalLinkage, node.name, &module);
    node.set_temporary_constructor(constructor);
    return constructor;
}

llvm::Value* CallConstructorIRGenerator::generate(Node& node_) {
    auto& node = *static_cast<CallConstructorNode*>(&node_);
    BlawnLogger logger;
    logger.set_line_number(node.line_number);
    for (auto& arg : node.get_passed_arguments()) {
        if (arg->is_argument()) {
            if (static_cast<ArgumentNode*>(arg.get())->get_right_value() ==
                nullptr) {
                std::vector<llvm::Value*> empty_arg;
                return ir_builder.CreateCall(
                    node.get_class()->get_temporary_constructor(), empty_arg);
            }
        }
    }

    auto callee_block = ir_builder.GetInsertBlock();
    std::vector<llvm::Type*> types;
    std::vector<llvm::Value*> argument_values;
    for (auto& arg : node.get_passed_arguments()) {
        auto v = arg->generate();
        types.push_back(v->getType());
        argument_values.push_back(v);
    }
    auto f = node.get_class()->get_constructor(types);
    llvm::Value* instance = nullptr;
    if (f != nullptr)
    // constructor is already generated
    {
        if (argument_values.size() != f->arg_size()) {
            logger.invalid_paramater_error("function");
        }
        instance = ir_builder.CreateCall(f, argument_values);
        get_blawn_context().add_heap_user(node.belong_to, instance);
        return instance;
    }
    auto base_constructor_type =
        llvm::FunctionType::get(ir_builder.getVoidTy(), types, false);
    auto base_constructor = llvm::Function::Create(
        base_constructor_type, llvm::Function::ExternalLinkage,
        node.get_class()->name, &module);
    node.get_class()->set_base_constructor(base_constructor);

    auto block = llvm::BasicBlock::Create(context, "entry", base_constructor);
    ir_builder.SetInsertPoint(block);

    int count = 0;
    for (auto& tmp_constructor_arg : base_constructor->args()) {
        std::string name = node.get_class()->get_arguments_names()[count];
        tmp_constructor_arg.setName(name);
        auto local = node.get_class()->get_self_namespace();
        auto empty_node = node.argument_collector.get(name, local);
        empty_node->alloca_inst =
                ir_builder.CreateAlloca(tmp_constructor_arg.getType(), 0, 0);
        ir_builder.CreateStore(&tmp_constructor_arg, empty_node->alloca_inst);
        /*
        empty_node->alloca_inst =
            ir_builder.CreateAlloca(tmp_func_arg.getType(), 0, 0);
        ir_builder.CreateStore(&tmp_func_arg, empty_node->alloca_inst);
        empty_node->set_right_value(
            ir_builder.CreateLoad(empty_node->alloca_inst));
        empty_node->alloca_inst;
        */
        empty_node->set_right_value(&tmp_constructor_arg);

        /*empty_node->alloca_inst =
            ir_builder.CreateAlloca(tmp_constructor_arg.getType(), 0, 0);
        ir_builder.CreateStore(&tmp_constructor_arg, empty_node->alloca_inst);
        empty_node->set_right_value(&tmp_constructor_arg);
        */
        count += 1;
    }

    std::vector<llvm::Type*> fields;
    std::vector<llvm::Value*> initial_values;
    std::vector<std::string> names;
    for (auto& line : node.get_class()->get_members_definition()) {
        line->initialize();
        auto value = line->generate();
        fields.push_back(value->getType());
        initial_values.push_back(value);
        names.push_back(line->name);
    }

    auto instance_type /*class*/ =
        llvm::StructType::create(context, fields, node.get_class()->name);
    auto instance_alloca /*pointer of the instance*/ =
        utils::malloc_value(instance_type, context, module, ir_builder);
    std::string type_name = instance_type->getStructName();
    get_blawn_context().add_class(type_name, node.get_class());
    get_blawn_context().add_user_type(node.get_class()->name, instance_type);

    for (unsigned int idx = 0; idx <= fields.size() - 1; idx++) {
        // initialize member variables
        get_blawn_context().register_element_name(type_name, names[idx], idx);
        ir_builder.CreateStore(
            initial_values[idx],
            ir_builder.CreateStructGEP(instance_type, instance_alloca, idx));
    }
    ir_builder.CreateRet(instance_alloca);

    auto new_constructor_type =
        llvm::FunctionType::get(instance_type->getPointerTo(), types, false);
    auto new_constructor = llvm::Function::Create(
        new_constructor_type, llvm::Function::ExternalLinkage,
        node.get_class()->name, &module);

    llvm::ValueToValueMapTy vmap;

    auto new_arg = new_constructor->arg_begin();
    for (auto& tmp_arg : base_constructor->args()) {
        new_arg->setName(tmp_arg.getName());
        vmap[&tmp_arg] = new_arg;
        new_arg++;
    }

    llvm::SmallVector<llvm::ReturnInst*, 0> returns;
    llvm::CloneFunctionInto(new_constructor, base_constructor, vmap, true,
                            returns);
    node.get_class()->register_constructor(types, new_constructor);
    node.get_class()->get_temporary_constructor()->replaceAllUsesWith(
        new_constructor);
    llvm::verifyFunction(*new_constructor, &llvm::outs());

    std::vector<llvm::Type*> destructor_args(1, instance_type->getPointerTo());
    auto destructor = node.get_class()->get_destructor(destructor_args);
    if (destructor == nullptr) {
        auto destructor_type = llvm::FunctionType::get(ir_builder.getVoidTy(),
                                                       destructor_args, false);
        destructor = llvm::Function::Create(
            destructor_type, llvm::Function::ExternalLinkage,
            "destructor<" + node.get_class()->name + ">", &module);
        auto destructor_entry =
            llvm::BasicBlock::Create(context, "entry", destructor);
        ir_builder.SetInsertPoint(destructor_entry);
        utils::free_value(destructor->arg_begin(), module, ir_builder);
        ir_builder.CreateRetVoid();
        node.get_class()->register_destructor(destructor_args, destructor);
    }
    node.set_destructor(destructor, instance_alloca);
    get_blawn_context().set_destructor(
        callee_block, std::make_pair(destructor, instance_alloca));
    ir_builder.SetInsertPoint(callee_block);
    instance = ir_builder.CreateCall(new_constructor, argument_values);
    get_blawn_context().add_heap_user(node.belong_to, instance);
    return instance;
}

llvm::Value* IfIRGenerator::generate(Node& node_) {
    auto& node = *static_cast<IfNode*>(&node_);
    std::set<llvm::Value*> false_values;
    false_values.insert(
        llvm::ConstantInt::get(context, llvm::APInt(64, 0, true)));
    false_values.insert(
        llvm::ConstantFP::get(context, llvm::APFloat(double(0.0))));
    false_values.insert(ir_builder.getInt1(false));

    auto cond_value = node.get_conditions()->generate();
    if (cond_value->getType() != ir_builder.getInt1Ty()) {
        if (cond_value->getType()->isIntegerTy())
            cond_value =
                ir_builder.CreateICmpNE(cond_value, ir_builder.getInt64(0));
        if (cond_value->getType()->isFloatTy())
            cond_value = ir_builder.CreateICmpNE(
                cond_value,
                llvm::ConstantFP::get(context, llvm::APFloat((0.0))));
        if (!cond_value->getType()->isIntegerTy() &&
            !cond_value->getType()->isFloatTy())
            cond_value = ir_builder.getInt1(true);
    }
    /*
    llvm::Value* cond_value = ir_builder.getInt1(false);
    if (false_values.find(cond) == false_values.end())// condition is true.
    {
        cond_value = ir_builder.getInt1(true);
    }
    */
    auto parent = ir_builder.GetInsertBlock()->getParent();
    auto then_block =
        llvm::BasicBlock::Create(context, "then of if expr", parent);
    auto else_block = llvm::BasicBlock::Create(context, "else of if_expr");
    auto merge_block = llvm::BasicBlock::Create(context, "merge of if_expr");

    ir_builder.CreateCondBr(cond_value, then_block, else_block);
    ir_builder.SetInsertPoint(then_block);
    for (auto& line : node.get_if_body()) {
        line->initialize();
        line->generate();
    }
    ir_builder.CreateBr(merge_block);
    then_block = ir_builder.GetInsertBlock();
    parent->getBasicBlockList().push_back(else_block);
    ir_builder.SetInsertPoint(else_block);
    for (auto& line : node.get_else_body()) {
        line->initialize();
        line->generate();
    }
    ir_builder.CreateBr(merge_block);
    else_block = ir_builder.GetInsertBlock();
    parent->getBasicBlockList().push_back(merge_block);
    ir_builder.SetInsertPoint(merge_block);
    return 0;
}

llvm::Value* ForIRGenerator::generate(Node& node_) {
    auto& node = *static_cast<ForNode*>(&node_);
    auto to_insert = ir_builder.GetInsertBlock()->getParent();
    auto body_block = llvm::BasicBlock::Create(context, "for", to_insert);
    auto merge_block = llvm::BasicBlock::Create(context, "merge of for");

    node.get_left_expression()->generate();  // left
    ir_builder.CreateBr(body_block);
    ir_builder.SetInsertPoint(body_block);
    for (auto& line : node.get_body()) {
        line->initialize();
        line->generate();
    }
    auto cond = node.get_center_expression()->generate();
    auto is_break = ir_builder.CreateICmpEQ(ir_builder.getInt1(false), cond);
    node.get_right_expression()->generate();  // proc
    body_block = ir_builder.GetInsertBlock();
    to_insert->getBasicBlockList().push_back(merge_block);
    ir_builder.CreateCondBr(is_break, merge_block, body_block);
    ir_builder.SetInsertPoint(merge_block);

    return 0;
}

llvm::Value* AccessIRGenerator::generate(Node& node_) {
    auto& node = *static_cast<AccessNode*>(&node_);
    BlawnLogger logger;
    logger.set_line_number(node.line_number);

    auto left = node.get_left_node()->generate();
    auto left_type = left->getType();
    if (!left_type->isPointerTy()) {
        logger.has_no_member_error(utils::to_string(left_type),
                                   node.get_right_name());
        return 0;
    }
    if (left_type->isPointerTy() &&
        !left_type->getPointerElementType()->isStructTy()) {
        logger.has_no_member_error(utils::to_string(left_type),
                                   node.get_right_name());
        return 0;
    }
    llvm::StructType* struct_type;
    if (left_type->isPointerTy()) {
        struct_type = llvm::dyn_cast<llvm::StructType>(
            left_type->getPointerElementType());

    } else {
        struct_type = llvm::dyn_cast<llvm::StructType>(left_type);
    }
    std::string type_name = struct_type->getStructName();
    int index = get_blawn_context().get_element_index(
        type_name, "@" + node.get_right_name());
    if (index != -1) {
        auto pointer = ir_builder.CreateStructGEP(struct_type, left, index);
        node.set_pointer(pointer);
        auto value = ir_builder.CreateLoad(pointer);
        node.set_generated(value);
        return value;
    } else {
        auto bm = get_blawn_context().get_builtin_method(type_name,
                                                         node.get_right_name());
        if (bm != nullptr) {
            auto call_node = node.get_call_node();
            CallFunctionIRGenerator gen(context, module, ir_builder);
            auto method_call = CallFunctionNode(
                node.line_number, node.self_scope, gen,
                call_node->passed_arguments, call_node->argument_collector, bm);
            if (node.get_generated() != nullptr) {
                return node.get_generated();
            }
            auto value = method_call.generate();
            node.set_generated(value);
            return value;
        }

        auto class_node = get_blawn_context().get_class(type_name);
        if (class_node == nullptr) {
            logger.has_no_member_error(type_name, node.get_right_name());
            return 0;
        }

        for (auto& m : class_node->get_methods()) {
            if (m->name == node.get_right_name()) {
                if (node.get_generated() != nullptr) {
                    return node.get_generated();
                }

                node.get_call_node()->function = m;
                auto value = node.get_call_node()->generate();
                node.set_generated(value);
                return value;
            }
        }
        logger.has_no_member_error(type_name, node.get_right_name());
        return 0;
    }
}

llvm::Value* ListIRGenerator::generate(Node& node_) {
    auto& node = *static_cast<ListNode*>(&node_);
    if (node.is_null()) {
        return llvm::ConstantPointerNull::get(ir_builder.getInt8PtrTy());
    }
    std::vector<llvm::Value*> elements;
    llvm::Type* previous_element_type;

    for (auto& n : node.get_elements()) {
        auto v = n->generate();
        if (previous_element_type != v->getType()) {
            // err proc;
        }
        previous_element_type = v->getType();
        elements.push_back(v);
    }

    auto array_type = llvm::ArrayType::get(previous_element_type, 0);
    auto array = ir_builder.CreateAlloca(array_type);
    auto first_element_ptr =
        ir_builder.CreateBitCast(array, previous_element_type->getPointerTo());

    return first_element_ptr;
}

llvm::Value* BlockEndIRGenerator::generate(Node& node_) {
    auto& node = *static_cast<BlockEndNode*>(&node_);
    auto heap_users = get_blawn_context().get_heap_users(node.block_scope);
    for (int i = heap_users.size() - 1; i != -1; i -= 1) {
        utils::free_value(heap_users[i], module, ir_builder);
    }
    return nullptr;
}

IRGenerators::IRGenerators(llvm::LLVMContext& context, llvm::Module& module,
                           llvm::IRBuilder<>& ir_builder)
    : ir_generator(context, module, ir_builder),
      sizeof_generator(context, module, ir_builder),
      typeid_generator(context, module, ir_builder),
      cast_generator(context, module, ir_builder),
      null_generator(context, module, ir_builder),
      int_ir_generator(context, module, ir_builder),
      float_ir_generator(context, module, ir_builder),
      string_generator(context, module, ir_builder),
      variable_generator(context, module, ir_builder),
      argument_generator(context, module, ir_builder),
      assigment_generator(context, module, ir_builder),
      store_generator(context, module, ir_builder),
      binary_expression_generator(context, module, ir_builder),
      function_generator(context, module, ir_builder),
      declare_C_generator(context, module, ir_builder),
      calling_generator(context, module, ir_builder),
      class_generator(context, module, ir_builder),
      call_constructor_generator(context, module, ir_builder),
      if_generator(context, module, ir_builder),
      for_generator(context, module, ir_builder),
      access_generator(context, module, ir_builder),
      list_generator(context, module, ir_builder),
      block_end_generator(context, module, ir_builder) {}
/*
llvm::Value* access(llvm::Value* left,llvm::StructType* struct_type,std::string
right_name,llvm::IRBuilder<> ir_builder)
{
    BlawnLogger logger;logger.set_line_number(node.line_number);
    std::string type_name = struct_type->getStructName();
    int index = get_blawn_context().get_element_index(type_name,"@"+right_name);
    if (index != -1)
    {
        auto pointer = ir_builder.CreateStructGEP(nullptr,left,index);
        node.set_pointer(pointer);
        auto value = ir_builder.CreateLoad(pointer);
        node.set_generated(value);
        return value;
    }
    else
    {
        auto class_node = get_blawn_context().get_class(type_name);
        if (class_node == nullptr)
        {
            logger.has_no_member_error(type_name,node.get_right_name());
            return 0;
        }
        for (auto& m:class_node->get_methods())
        {
            if (m->name == node.get_right_name())
            {

                if (node.get_generated() != nullptr)
                {
                    return node.get_generated();
                }

                node.get_call_node()->function = m;
                auto value = node.get_call_node()->generate();
                node.set_generated(value);
                return value;
            }
        }
        logger.has_no_member_error(type_name,node.get_right_name());
        return 0;
    }
}
*/