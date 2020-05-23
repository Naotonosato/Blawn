#pragma once
#include <vector>
#include <string>
#include <unordered_map>
#include <memory>
#include <variant>
#include "include/algorithm/union_find/union_find.hpp"
#include "include/mir/type_solver.hpp"
#include "include/mir/module.hpp"

namespace mir
{
class Module;
class Type;
// forward declarations

class TypeBase
{
    private:
    bool is_constant;
    const std::string name;

    public:
    TypeBase(const std::string& name)
        : name(name)
    {
    }
    TypeBase(const TypeBase&) = delete;
    TypeBase(TypeBase&&) noexcept = default;
    TypeBase& operator=(const TypeBase&) = delete;
    TypeBase& operator=(TypeBase&&) noexcept = default;
    const std::string& get_name() const;
};

class IntegerType : public TypeBase
{
    public:
    IntegerType(const std::string& name="int"):TypeBase(name){}
};

class FloatType : public TypeBase
{
    public:
    FloatType(const std::string& name="float"):TypeBase(name){}
};

class PointerType : public TypeBase
{
    private:
    std::shared_ptr<Type> pointer_to;
    public:
    PointerType(const std::string& name,std::shared_ptr<Type> pointer_to):TypeBase(name),pointer_to(pointer_to){}
};

class ArrayType : public TypeBase
{
    private:
    std::shared_ptr<Type> element_type;
    public:
    ArrayType(const std::string& name="array"):TypeBase(name){}
};

class StringType : public TypeBase
{
    public:
    StringType(const std::string& name="string"):TypeBase(name){}
};

class StructType : public TypeBase
{
    private:
    std::vector<std::shared_ptr<Type>> member_types;

    public:
    StructType(const std::string& name,std::vector<std::shared_ptr<Type>>&& member_types)
    :TypeBase(name),member_types(std::move(member_types)){}
};

class FunctionType : public TypeBase
{
    private:
    std::vector<std::shared_ptr<Type>> argument_types;
    std::shared_ptr<Type> return_type;
    public:
    FunctionType(const std::string& name,std::vector<std::shared_ptr<Type>>&& argument_types,std::shared_ptr<Type> return_type)
    :TypeBase(name),argument_types(std::move(argument_types)),return_type(return_type){}
};

class LazyType : public TypeBase
{
    public:
    LazyType(const std::string& name="lazy"):TypeBase(name){}
};

class Type
{
    public:
    using variant_type =
        std::variant<IntegerType, FloatType, StringType, ArrayType, StructType,
                     FunctionType, LazyType>;

    private:
    variant_type content;

    template <typename Base>
    struct CreateHelper : Base
    {
        template <typename... Args>
        CreateHelper(Args&&... args) : Base(std::forward<Args>(args)...)
        {
        }
    };

    template <class T>
    Type(T&& content)
        :content(std::move(content))
    {
    }

    public:

    template <class T = LazyType, typename... Args>
    static std::shared_ptr<Type> create(std::shared_ptr<Module> module,
                                        Args&&... args)
    {
        auto type_variable = std::make_shared<CreateHelper<Type>>(
            module, std::move(T(std::forward<Args>(args)...)));
        module->get_type_solver().add_type_variable(type_variable);
        return type_variable;
    }

    template <typename VisitorType>
    auto accept(VisitorType& visitor)
    {
        return std::visit(visitor, content);
    }

    template <typename Type>
    bool is_type()
    {
        return std::holds_alternative<Type>(content);
    }
};

}  // namespace mir