#include <memory>
#include "../mir/mir.hpp"
#include "builder.hpp"


namespace mir {

std::unique_ptr<Integer> Builder::create_integer() {
    return std::make_unique<Integer>(module);
}

std::unique_ptr<Integer> Builder::create_constant_integer(long long num) {
    return std::make_unique<Integer>(module,num);
}

std::unique_ptr<Float> Builder::create_float() {
    return std::make_unique<Float>(module);
}

std::unique_ptr<Float> Builder::create_constant_float(double num) {
    return std::make_unique<Float>(module,num);
}

std::unique_ptr<String> Builder::create_string() {
    return std::make_unique<String>(module);
}

std::unique_ptr<String> Builder::create_constant_string(const std::string& str) {
    return std::make_unique<String>(module,str);
}

std::unique_ptr<Array> Builder::create_array() {
    return std::make_unique<Array>(module);
}

std::unique_ptr<StructType> Builder::declare_struct() {
    
}

std::unique_ptr<FunctionType> Builder::declare_function() {
    
}

}