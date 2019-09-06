#include <string>
#include <iostream>
#include "errors.hpp"


void BlawnLogger::set_line_number(int line_number_)
{
    line_number = line_number_;
}

void BlawnLogger::different_type_error(std::string first,std::string second)
{
    std::cerr << "Error: types are not same. " << first << " and " << second << " at line " << line_number << std::endl;
    exit(1);
}

void BlawnLogger::invalid_dot_error()
{
    std::cerr << "Error: invalid use of '.'" << " at line " << line_number <<  std::endl;
    exit(1);
}
void BlawnLogger::has_no_member_error(std::string type,std::string name)
{
    std::cerr << "Error: type " << type << " has no member " << name << " at line " << line_number <<  std::endl;
    exit(1);
}
void BlawnLogger::unknown_identifier_error(std::string kind,std::string identifier)
{
    std::cerr << "Error: unknown " << kind << " " << identifier << " at line " << line_number <<  std::endl;
    exit(1);
}

void BlawnLogger::invalid_cast_error(std::string type,std::string to)
{
    std::cerr << "Error: invalid cast " << type << " to " << to << " at line " << line_number <<  std::endl;
    exit(1);
}

void BlawnLogger::invalid_right_value_error()
{
    std::cerr << "Error: invalid right hand side value" << " at line " << line_number <<  std::endl;
    exit(1);
}

void BlawnLogger::invalid_paramater_error(std::string func_name)
{
    std::cerr << "Error: invalid parameter passed " << func_name  << " at line " << line_number <<  std::endl;
    exit(1);
}