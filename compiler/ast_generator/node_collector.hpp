#pragma once
#include <vector>
#include <map>
#include <string>
#include <memory>
#include <iostream>

static unsigned int unique_number = 0;

template <typename T>
class NodeCollector
{
    private:
    std::map<
            std::vector<std::string>,
            std::pair<
            std::map<std::string,std::shared_ptr<T>>,
            std::vector<std::string>>
            > 
            nodes;
    std::vector<std::string> current_namespace;
    public:
    NodeCollector(std::string top="[TOP]"):current_namespace({top}){}
    
    std::shared_ptr<T> get(std::string name)
    {
        std::vector<std::string> upper_namespace;
        for (auto &n:current_namespace)
        {
            upper_namespace.push_back(n);
            if (nodes[upper_namespace].first.count(name))
            {
                return nodes[upper_namespace].first[name];
            }
        }
        return nullptr;
    }

    std::shared_ptr<T> get(std::string name,std::vector<std::string> namespace_)
    {
        std::vector<std::string> upper_namespace;
        for (auto &n:namespace_)
        {
            upper_namespace.push_back(n);
            if (nodes[upper_namespace].first.count(name))
            {
                return nodes[upper_namespace].first[name];
            }
        }
        return nullptr;
    }

    std::shared_ptr<T> get_previous()
    {
        auto name = nodes[current_namespace].second.back();
        return nodes[current_namespace].first[name];
    }

    std::vector<std::shared_ptr<T>> get_all()
    {
        std::vector<std::shared_ptr<T>> res;
        for (auto& map_iter:nodes)
        {
            for (auto& name:map_iter.second.second)
                {
                    res.push_back(map_iter.second.first[name]);
                }
        }
        return res;
    }

    std::vector<std::shared_ptr<T>> get_all(std::vector<std::string> namespace_)
    {
        std::vector<std::shared_ptr<T>> res;
        for (auto& name:nodes[namespace_].second)
        {
            res.push_back(nodes[namespace_].first[name]);
        }
        return res;
    }

    void set(std::string name,std::shared_ptr<T> node)
    {
        nodes[current_namespace].first[name] = node;
        nodes[current_namespace].second.push_back(name);
    }
    
    void set(std::string name,std::shared_ptr<T> node,std::vector<std::string> namespace_)
    {
        nodes[namespace_].first[name] = node;
        nodes[namespace_].second.push_back(name);
    }

    void into_namespace(std::string namespace_)
    {
        current_namespace.push_back(namespace_);
        std::pair<std::map<std::string,std::shared_ptr<T>>,std::vector<std::string>> empty;
        nodes[current_namespace] = empty;
    }

    void break_out_of_namespace()
    {
        if (!current_namespace.empty())
            {
            current_namespace.pop_back();
            }
    }

    std::vector<std::string> get_namespace()
    {
        return current_namespace;
    }

    bool exist(std::string name)
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

    bool is_current_top()
    {
        return (current_namespace.size() == 1);
    }
    std::string get_unique_name()
    {
        unsigned int n = unique_number;
        unique_number += 1;
        std::string unique_name = "#" + std::to_string(n);
        return unique_name;
    }
    std::string get_namespace_as_string()
    {
        std::string cur = ".";
        for (auto &i:current_namespace)
        {
            cur += "/" + i;
        }
        return cur;
    }
};
