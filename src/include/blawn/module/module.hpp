#include <string>
#include <memory>

namespace ast
{
class Node;
}

namespace module
{
class Module
{
    private:
    std::string name;

    public:
    Module() = delete;
    Module(std::string name);
    Module(const Module&) = delete;
    Module& operator=(const Module&) = delete;
    const std::string& get_name() const;
};
}  // namespace module