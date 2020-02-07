#include <string>
#include <vector>
#include <map>

namespace mir {
class Type;
class FunctionType;
}  // namespace mir
// forward declarations

namespace mir {
class Context {
    private:
    std::vector<std::shared_ptr<FunctionType>> functions;
    std::map<std::string, std::shared_ptr<Type>> types;
};
}  // namespace mir