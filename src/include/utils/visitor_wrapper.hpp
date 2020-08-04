#pragma once
#include <memory>
#include <type_traits>

namespace utils
{
template <typename T>
class VisitorWrapper;

template <typename T>
class VisitorBase
{
    protected:
    VisitorWrapper<T>& visitor_ref;

    public:
    VisitorBase(VisitorWrapper<T>& visitor_ref) : visitor_ref(visitor_ref) {}
};

template <typename VisitorType>
class VisitorWrapper
{
    private:
    std::unique_ptr<VisitorType> visitor;

    protected:
    template <typename Base>
    struct CreateHelper : Base
    {
        template <typename... Args>
        CreateHelper(Args&&... args) : Base(std::forward<Args>(args)...)
        {
        }
    };
    VisitorWrapper() = default;
    void set_visitor(std::unique_ptr<VisitorType>&& visitor_)
    {
        visitor = std::move(visitor_);
    }

    public:
    template <typename... Args>
    static std::unique_ptr<VisitorWrapper<VisitorType>> create(Args&&... args)
    {
        static_assert(
            std::is_base_of<VisitorBase<VisitorType>, VisitorType>(),
            "Visitor Class must be derived from VisitorBase<`Visitor Class`>");
        auto visitor_wrapper = std::make_unique<CreateHelper<VisitorWrapper>>();
        visitor_wrapper->set_visitor(std::make_unique<VisitorType>(
            *visitor_wrapper, std::forward<Args>(args)...));
        return visitor_wrapper;
    }

    template <typename ArgType>
    auto operator()(ArgType& arg) const
    {
        return visitor->visit(arg);
    }
};

}  // namespace utils