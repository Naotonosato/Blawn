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