#include <string>
#include <memory>

namespace utils {
template <typename T>
class ScopedCollector;
}

namespace ast {
class Node;
}

namespace module {
class Module {
    private:
    std::string name;
    std::unique_ptr<utils::ScopedCollector<std::shared_ptr<ast::Node>>>
        ast_container;

    public:
    Module() = delete;
    Module(std::string name);
    Module(const Module&) = delete;
    Module& operator=(const Module&) = delete;
    const std::string& get_name() const;
    utils::ScopedCollector<std::shared_ptr<ast::Node>>& get_ast_container();
};
}  // namespace module