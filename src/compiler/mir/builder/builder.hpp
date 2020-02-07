#include <memory>

namespace mir {
class Context;
class MIR;
class Integer;
class Float;
}  // namespace mir
// forward declarations;

namespace mir {
class MIRBuilder {
    private:
    Context& context;

    public:
    MIRBuilder(Context& context) : context(context) {}
    std::shared_ptr<Integer> constant_integer(long long num);
    std::shared_ptr<Integer> integer(long long num);
    std::shared_ptr<Float> constant_float(double num);
    std::shared_ptr<Float> real_number(double num);
};
}  // namespace mir