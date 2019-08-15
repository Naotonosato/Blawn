#pragma once
#include <vector>
#include <map>
#include <string>
#include <memory>


template <typename T>
class NodeCollector
{
private:
std::map<
        std::vector<std::string>,
        std::map<std::string,std::shared_ptr<T>>
            > 
        nodes;
std::vector<std::string> current_namespace;
public:
    NodeCollector(std::string top="TOP");
    std::shared_ptr<T> get(std::string);
    std::shared_ptr<T> get(std::string name,std::vector<std::string> namespace_);
    void set(std::string,std::shared_ptr<T>);
    void set(std::string,std::shared_ptr<T>,std::vector<std::string>);
    void into_namespace(std::string);
    void break_out_of_namespace();
    std::vector<std::string> get_namespace();
    bool exist(std::string);
    bool is_current_top();
    std::string get_namespace_as_string();
};











template<typename T>
NodeCollector<T>::NodeCollector(std::string top):current_namespace({top})
{}

template<typename T>
std::shared_ptr<T> 
NodeCollector<T>::get(std::string name)
{
    std::vector<std::string> upper_namespace;
    for (auto &n:current_namespace)
    {
        upper_namespace.push_back(n);
        if (nodes[upper_namespace].count(name))
        {
            return nodes[upper_namespace][name];
        }
    }
    return nullptr;
}

template<typename T>
std::shared_ptr<T> 
NodeCollector<T>::get(std::string name,std::vector<std::string> namespace_)
{
    std::vector<std::string> upper_namespace;
    for (auto &n:namespace_)
    {
        upper_namespace.push_back(n);
        if (nodes[upper_namespace].count(name))
        {
            return nodes[upper_namespace][name];
        }
    }
    return nullptr;
}

template<typename T>
void NodeCollector<T>::set(std::string name,std::shared_ptr<T> node)
{
    nodes[current_namespace][name] = node;
}

template<typename T>
void NodeCollector<T>::set(std::string name,std::shared_ptr<T> node,std::vector<std::string> namespace_)
{
    nodes[namespace_][name] = node;
}

template<typename T>
void NodeCollector<T>::into_namespace(std::string namespace_)
{
    current_namespace.push_back(namespace_);
    std::map<std::string,std::shared_ptr<T>> empty;
    nodes[current_namespace] = empty;
}

template<typename T>
void NodeCollector<T>::break_out_of_namespace()
{
    if (!current_namespace.empty())
        {
        current_namespace.pop_back();
        }
}

template<typename T> 
std::vector<std::string> NodeCollector<T>::get_namespace()
{
    return current_namespace;
}

template<typename T>
bool NodeCollector<T>::exist(std::string name)
{
    if (get(name) != nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template<typename T>
bool NodeCollector<T>::is_current_top()
{
    return (current_namespace.size() == 1);
}

template<typename T>
std::string NodeCollector<T>::get_namespace_as_string()
{
    std::string cur = ".";
    for (auto &i:current_namespace)
    {
        cur += "/" + i;
    }
    return cur;
}