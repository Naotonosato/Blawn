#pragma once
#include <string>
#include <variant>

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
    VariantWrapper(T content) : content(content) {}

    template <typename ContentType>
    void assign(ContentType new_content) {
        content = new_content;
    }

    template <typename ContentType>
    void assign_mov(ContentType&& new_content) {
        content = new_content;
    }

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
    ContentType& get() {
        assert(std::holds_alternative<ContentType>(content));
        return std::get<ContentType>(content);
    }
};

}  // namespace utils