#include <llvm/IR/Type.h>
#include "blawn_context.hpp"


static BlawnContext context;

void BlawnContext::register_element_name(std::string type,std::string name,unsigned int index)
{
    element_names[type][name] = index;
}

unsigned int BlawnContext::get_element_index(std::string type,std::string name)
{
    return element_names[type][name];
}

BlawnContext& get_blawn_context()
{
    return context;
}