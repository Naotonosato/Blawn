#include <llvm/IR/DataLayout.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Type.h>
#include <llvm/Support/raw_ostream.h>
#include "../ast/node.hpp"
#include "../blawn_context/blawn_context.hpp"
#include "utils.hpp"

std::string utils::to_string(llvm::Type* type) {
    std::string str;
    llvm::raw_string_ostream rso(str);
    type->print(rso);
    return rso.str();
}

std::string utils::to_string(llvm::Value* value) {
    std::string str;
    llvm::raw_string_ostream rso(str);
    value->print(rso);
    return rso.str();
}

void utils::split(std::string text, std::string splitter,
                  std::vector<std::string>& res) {
    std::string::size_type index = 0;
    while (index != std::string::npos) {
        std::string::size_type found_index = text.find(splitter, index);
        if (found_index == std::string::npos) {
            res.push_back(text.substr(index));
            break;
        } else {
            res.push_back(text.substr(index, found_index - index));
        }
        index = found_index + splitter.size();
    }
}

void utils::replace(std::string& text, std::string from, std::string to,
                    unsigned int from_index) {
    std::string::size_type index = text.find(from, from_index);
    if (index != std::string::npos && !from.empty()) {
        if (text.find(from, index + from.length()) != std::string::npos) {
            replace(text, from, to, index + from.length());
        }
        text = text.replace(index, from.length(), to);
    }
}

bool utils::exist(std::string text, std::string to_find) {
    return text.find(to_find) != std::string::npos;
}

uint64_t utils::get_sizeof(llvm::Type* type, llvm::Module& module) {
    auto layout = llvm::DataLayout(&module);
    return layout.getTypeAllocSize(type);
}

llvm::Value* utils::malloc_value(llvm::Type* type, llvm::LLVMContext& context,
                                 llvm::Module& module,
                                 llvm::IRBuilder<>& ir_builder) {
    auto malloc_func = module.getFunction("malloc");
    uint64_t size = get_sizeof(type, module);
    auto size_ir = llvm::ConstantInt::get(context, llvm::APInt(64, size));
    std::vector<llvm::Value*> arg(1, size_ir);
    auto pointer = ir_builder.CreateCall(malloc_func, arg);
    return ir_builder.CreateBitCast(pointer, type->getPointerTo());
}

llvm::Value* utils::free_value(llvm::Value* to_delete_ptr, llvm::Module& module,
                               llvm::IRBuilder<>& ir_builder) {
    auto free_func = module.getFunction("free");
    auto cast_inst = ir_builder.CreateBitCast(
        to_delete_ptr, ir_builder.getInt64Ty()->getPointerTo());
    std::vector<llvm::Value*> arg(1, cast_inst);
    return ir_builder.CreateCall(free_func, arg);
}

llvm::Type* utils::get_or_create_type(llvm::LLVMContext& context,
                                      std::shared_ptr<ClassNode> class_node,
                                      std::string name) {
    auto type = get_blawn_context().get_user_type(class_node->name);
    if (type == nullptr) {
        auto members_definition = class_node->get_members_definition();
        std::vector<llvm::Type*> fields;
        std::vector<llvm::Value*> initial_values;
        std::vector<std::string> names;
        for (auto& line : members_definition) {
            auto val = line->generate();
            fields.push_back(val->getType());
            names.push_back(line->name);
        }
        type = llvm::StructType::create(context, fields, class_node->name);
        unsigned int index = 0;
        
        for (auto& name:names)
        {
            get_blawn_context().register_element_name(type->getStructName(),
                                                      name, index);
            index += 1;
        }
        get_blawn_context().add_user_type(class_node->name, type);
    }
    return type;
}