#include <memory>

namespace mir {
class Module;

class StructType;
class FunctionType;

class MIR;
class Integer;
class Float;
class Array;
class String;
class Struct;
class Function;
}  // namespace mir
// forward declarations;

namespace mir {
class Builder {
    private:
    std::shared_ptr<Module> module;

    public:
    Builder(std::shared_ptr<Module> module) : module(module) {}
    std::unique_ptr<Integer> create_integer();
    std::unique_ptr<Integer> create_constant_integer(long long num);
    std::unique_ptr<Float> create_float();
    std::unique_ptr<Float> create_constant_float(double num);
    std::unique_ptr<String> create_string();
    std::unique_ptr<String> create_constant_string(const std::string& str);
    std::unique_ptr<Array> create_array();
    std::unique_ptr<StructType> declare_struct();
    std::unique_ptr<FunctionType> declare_function();
};
}  // namespace mir