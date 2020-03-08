#include <memory>
#include <type_traits>

namespace utils {
template <typename T> 
class SharedFromThis
{
    struct CreateHelper:T
    {
        template<typename... Args>
        CreateHelper(Args&&... args):T(std::forward<Args>(args)...){}
    };
    public:
    template<typename... Args>
    void* operator new(size_t,Args&&...)
    {
        //delay evaluation until instantiation
        constexpr bool operator_new_is_not_used = []{return false;}();
        static_assert(operator_new_is_not_used,"Class that inherits from SharedFromThis cannot be instantiated with operator new.");
    }

    template<typename... Args> static std::shared_ptr<T> create(Args&&... args)
    {
        constexpr bool is_constructor_is_callable = std::is_constructible<T,Args&&...>::value;
        static_assert(
            !is_constructor_is_callable,
            "If the class inherits from SharedFromThis,the class of constructor must be protected."
        );

        auto shared_this = std::make_shared<CreateHelper>(std::forward<Args>(args)...);
        return shared_this;
    }
};
}