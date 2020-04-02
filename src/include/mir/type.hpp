#pragma once
#include <vector>
#include <string>
#include <unordered_map>
#include <memory>
#include <variant>
#include "include/algorithm/union_find/union_find.hpp"
#include "include/mir/type_solver.hpp"
#include "include/mir/module.hpp"

namespace mir {

class Module;
class Type;
// forward declarations

class TypeBase {
    private:
    bool is_constant;
    std::string name;

    public:
    TypeBase(std::string name, bool is_constant = false)
        : name(name), is_constant(is_constant) {}
    TypeBase(const TypeBase&) = delete;
    TypeBase(TypeBase&&) noexcept = default;
    TypeBase& operator=(const TypeBase&) = delete;
    TypeBase& operator=(TypeBase&&) noexcept = default;
};

class IntegerType : public TypeBase {
    public:
};

class FloatType : public TypeBase {};

class DoubleType : public TypeBase {};

class ArrayType : public TypeBase {
    private:
    std::shared_ptr<Type> element_type;
};

class StringType : public TypeBase {};

class StructType : public TypeBase {
    private:
    std::string name;
    std::vector<std::shared_ptr<Type>> member_types;

    public:
    StructType(std::shared_ptr<Module> module,
               std::vector<std::shared_ptr<Type>> member_types);
};

class FunctionType : public TypeBase {
    private:
    std::vector<std::shared_ptr<Type>> argument_type;
    std::shared_ptr<TypeBase> return_type;
};

class LazyType : public TypeBase {
    private:
    std::shared_ptr<Type> dependency;

    public:
    void depend_on(std::shared_ptr<TypeBase> type);
};

class Type {
    public:
    using variant_type =
        std::variant<IntegerType, FloatType, StringType, ArrayType, StructType,
                     FunctionType, LazyType>;

    private:
    std::shared_ptr<Module> module;
    variant_type content;

    template <typename Base>
    struct CreateHelper : Base {
        template <typename... Args>
        CreateHelper(Args&&... args) : Base(std::forward<Args>(args)...) {}
    };

    template <class T>
    Type(std::shared_ptr<Module> module, T&& content)
        : module(module), content(std::move(content)) {}

    public:
    template <class T = LazyType, typename... Args>
    static std::shared_ptr<Type> create(std::shared_ptr<Module> module,
                                        Args&&... args) {
        auto type_variable = std::make_shared<CreateHelper<Type>>(
            module, std::move(T(std::forward<Args>(args)...)));
        module->get_type_solver().add_type_variable(type_variable);
        return type_variable;
    }

    template <typename VisitorType>
    auto accept(VisitorType& visitor) {
        return std::visit(visitor, content);
    }

    template <typename Type>
    bool is_type() {
        return std::holds_alternative<Type>(content);
    }
};

}  // namespace mir