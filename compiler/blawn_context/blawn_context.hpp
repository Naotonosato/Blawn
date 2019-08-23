#pragma once
#include <string>
#include <map>
#include <vector>


namespace llvm
{
    class Type;
    class StructType;
}


class BlawnContext
{
    private:
    std::map<std::string,std::map<std::string,unsigned int>> element_names;
    public:
    void register_element_name(std::string,std::string name,unsigned int index);
    int get_element_index(std::string,std::string name);
};


BlawnContext& get_blawn_context();