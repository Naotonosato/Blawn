#pragma once
#include <iostream>
#include <string>

class Error
{};


class NotImplementedException:public std::logic_error
{
    public:
    NotImplementedException(std::string name):std::logic_error("Not Implemented: "+name){}
};


class BlawnLogger
{
    private:
    void error();
    public:
    void different_type_error(std::string first,std::string second);
    void invalid_dot_error();
    void has_no_member_error(std::string type,std::string name);
    void unknown_identifier_error(std::string kind,std::string identifier);
};