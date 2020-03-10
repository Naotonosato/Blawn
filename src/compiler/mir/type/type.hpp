#pragma once
#include <vector>
#include <unordered_map>
#include <memory>
#include <variant>
#include "../algorithm/union_find/union_find.hpp"
#include "../type_solver/type_solver.hpp"
#include "../module/module.hpp"
#include "../../behaviors/has_variant_behavior.hpp"

namespace mir {

class TypeVariable;
// forward declarations

class TypeBase {
    private:
    bool is_constant;

    public:
    TypeBase() : is_constant(false) {}
    TypeBase(const TypeBase&) = delete;
    TypeBase(TypeBase&&) noexcept = default;
    TypeBase& operator=(const TypeBase&) = delete;
    TypeBase& operator=(TypeBase&&) noexcept = default;
};

class IntegerType : public TypeBase {
    public:
};

class FloatType : public TypeBase {};

class ArrayType : public TypeBase {
    private:
    std::shared_ptr<TypeBase> element_type;
};

class StringType : public TypeBase {};

class StructType : public TypeBase {
    private:
    std::string name;
    std::vector<std::shared_ptr<TypeVariable>> members;

    public:
    StructType(std::shared_ptr<Module> module,
               std::vector<std::shared_ptr<TypeVariable>> members);
};

class FunctionType : public TypeBase {
    private:
    std::vector<std::shared_ptr<mir::TypeBase>> argument_type;
    std::shared_ptr<TypeBase> return_type;
};

class LazyType : public TypeBase {
    private:
    std::shared_ptr<TypeBase> dependency;

    public:
    void depend_on(std::shared_ptr<TypeBase> type);
};

class TypeVariable {
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
    TypeVariable(std::shared_ptr<Module> module, T&& content)
        : module(module), content(std::move(content)) {}

    public:
    template <class T = LazyType, typename... Args>
    static std::shared_ptr<TypeVariable> create(std::shared_ptr<Module> module,
                                                Args&&... args) {
        auto type_variable = std::make_shared<CreateHelper<TypeVariable>>(
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