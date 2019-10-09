#pragma once
#include <iostream>
#include <string>

class Error {};

class NotImplementedException : public std::logic_error {
public:
    NotImplementedException(std::string name)
        : std::logic_error("Not Implemented: " + name) {}
};

class BlawnLogger {
private:
    void error();
    int line_number;

public:
    void set_line_number(int line_number);
    void different_type_error(std::string first, std::string second);
    void invalid_dot_error();
    void invalid_right_value_error();
    void invalid_paramater_error(std::string func_name);
    void has_no_member_error(std::string type, std::string name);
    void unknown_identifier_error(std::string kind, std::string identifier);
    void invalid_cast_error(std::string type, std::string to);
};