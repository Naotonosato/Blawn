#include <variant>


namespace behaviors
{

template <typename... Types>
class HasVariantBehavior
{
    public:
    using variant_type = std::variant<Types...>;

    protected:
    variant_type content;
    template <typename T>
    HasVariantBehavior(T&& content): content(std::move(content)){}
    public:
    template <typename VisitorType> auto accept(VisitorType& visitor)
    {
        return std::visit(visitor,content);
    }
    template <typename Type> bool is_type()
    {
        return std::holds_alternative<Type>(content);
    }
};

}