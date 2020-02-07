#include <vector>
#include <string>
#include <map>

namespace mir {
class Context;

class Type;
class FunctionType;
class StructType;

class Variable;
class GlobalVariable;
}  // namespace mir

namespace mir {
class Module {
    private:
    Context& context;
    std::string name;
    std::map<std::string, FunctionType&> functions;
    std::map<std::string, StructType&> types;
    std::map<std::string, GlobalVariable&> gloval_variables;

    public:
    Module(Context& context) : context(context) {}
};
}  // namespace mir
