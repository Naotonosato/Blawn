#include <string>
#include <iostream>
#include "errors.hpp"


void BlawnLogger::invalid_dot_error()
{
    std::cerr << "Error: invalid use of '.'" << std::endl;
    exit(1);
}
void BlawnLogger::has_no_member_error(std::string type,std::string name)
{
    std::cerr << "Error: type " << type << " has no member " << name << std::endl;
    exit(1);
}
void BlawnLogger::unknown_identifier_error(std::string kind,std::string identifier)
{
    std::cerr << "Error: unknown " << kind << " " << identifier << std::endl;
    exit(1);
}