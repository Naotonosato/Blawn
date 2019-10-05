#pragma once
#include <vector>
#include <map>
#include <string>
#include <memory>
#include <iostream>

static unsigned int unique_number_ = 0;
typedef std::vector<std::string> scope;

template <typename T>
class NodeCollector
{
    private:
    std::map<
            scope,
            std::pair<
            std::map<std::string,std::shared_ptr<T>>,
            scope>
            > 
            nodes;
    scope current_namespace;
    scope _top;
    public:
    NodeCollector(std::string top="[TOP]"):current_namespace({top}),
    _top({top}){}
    
    scope top()
    {
        return _top;
    }

    std::shared_ptr<T> get(std::string name)
    {
        scope upper_namespace;
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

    std::shared_ptr<T> get(std::string name,scope namespace_)
    {
        scope upper_namespace;
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

    std::vector<std::shared_ptr<T>> get_all(scope namespace_)
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
    
    void set(std::string name,std::shared_ptr<T> node,scope namespace_)
    {
        nodes[namespace_].first[name] = node;
        nodes[namespace_].second.push_back(name);
    }

    void into_namespace(std::string namespace_)
    {
        current_namespace.push_back(namespace_);
        std::pair<std::map<std::string,std::shared_ptr<T>>,scope> empty;
        nodes[current_namespace] = empty;
    }

    void break_out_of_namespace()
    {
        if (!current_namespace.empty())
            {
            current_namespace.pop_back();
            }
    }

    scope get_namespace()
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
        unsigned int n = unique_number_;
        unique_number_ += 1;
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
