#pragma once
#include <string>
#include <variant>

namespace utils
{
template <typename... ElementTypes>
class VariantWrapper
{
    public:
    using variant_type = std::variant<ElementTypes...>;

    protected:
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
    VariantWrapper(T&& content) : content(std::move(content))
    {
    }

    public:
    template <typename VisitorType>
    auto accept(VisitorType& visitor) const
    {
        return std::visit(visitor, content);
    }

    const variant_type& get_variant() const { return content; }

    template <typename ContentType>
    bool is_type()
    {
        return std::holds_alternative<ContentType>(content);
    }

    template <typename ContentType>
    ContentType& as()
    {
        assert(std::holds_alternative<ContentType>(content));
        return std::get<ContentType>(content);
    }
};

}  // namespace utils

/*
#include <string>
#include <variant>
#include <iostream>
#include <optional>


namespace utils {
template <typename... ElementTypes>
class VariantWrapper {
    public:
    using variant_type = std::variant<ElementTypes...>;

    protected:
    variant_type content;

    template <typename Base>
    struct CreateHelper : Base {
        template <typename... Args>
        CreateHelper(Args&&... args) : Base(std::forward<Args>(args)...) {}
    };

    template <class T>
    VariantWrapper(T&& content) : content(std::move(content)) {}

    public:
    template <typename VisitorType>
    auto accept(VisitorType& visitor) {
        return std::visit(visitor, content);
    }

    variant_type& get_variant() { return content; }

    template <typename ContentType>
    bool is_type() {
        return std::holds_alternative<ContentType>(content);
    }

    template <typename ContentType>
    ContentType& as() {
        assert(std::holds_alternative<ContentType>(content));
        return std::get<ContentType>(content);
    }
};

}  // namespace utils




class V:public utils::VariantWrapper<int,std::string>
{
    public:
    template<typename T> V(T&&
initial):utils::VariantWrapper<int,std::string>(std::move(initial)){}
};


template <typename... T>
class Match
{
    public:
    Match(T... ){}
};



template<typename T,typename VariantType,typename FunctionType>

auto Case(VariantType& variant,FunctionType
function)->std::optional<decltype(function(variant))>
{
    if (variant.template is_type<T>())
    {
        return function(variant);
    }
    return std::nullopt;
}


template<typename ReturnType>
class DefaultReturnType
{
    private:
    ReturnType result;
    public:
    DefaultReturnType()=delete;
    DefaultReturnType(ReturnType&& returns):result(std::move(returns)){}
    ReturnType get_result(){return result;}
};


template<typename VariantType,typename FunctionType>
auto Default(VariantType& variant,FunctionType
function)->DefaultReturnType<decltype(function(variant))>
{
    return DefaultReturnType(function(variant));
}

int main()
{
    auto v = V("aaa");

    Match
        (
        Case<std::string>(v,[](auto& v) {std::cout << "contains string" <<
std::endl; return 0; }), Case<int>(v,[](auto& v) {std::cout << "contains int" <<
std::endl; return 0;}), Default(v,(v,[](auto& v){std::cout << "didn't match" <<
std::endl; return 0;}))
        );

    return 0;
}
*/