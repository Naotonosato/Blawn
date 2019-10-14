#pragma once
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <vector>

static unsigned int unique_number_ = 0;

class Scope : public std::vector<std::string> {
    public:
    using std::vector<std::string>::vector;
    bool is_longer(Scope s) {
        if (s.size() <= this->size()) return false;
        unsigned int index = 0;
        for (auto& e : *this) {
            if (s[index] != e) return false;
            index += 1;
        }
        return true;
    }
    bool is_equal(Scope s) {
        if (s.size() != this->size()) return false;
        unsigned int index = 0;
        for (auto& e : *this) {
            if (s[index] != e) return false;
            index += 1;
        }
        return true;
    }
    bool is_shorter_than(Scope s) {
        if (s.size() >= this->size()) return false;
        unsigned int index = 0;
        for (auto& e : s) {
            if ((*this)[index] != e) return false;
            index += 1;
        }
        return true;
    }
};

template <typename T>
class NodeCollector {
    private:
    std::map<Scope, std::pair<std::map<std::string, std::shared_ptr<T>>, Scope>>
        nodes;
    Scope current_namespace;
    Scope _top;

    public:
    NodeCollector(std::string top = "[TOP]")
        : current_namespace({top}), _top({top}) {}

    Scope top() { return _top; }

    std::shared_ptr<T> get(std::string name) {
        Scope upper_namespace;
        for (auto& n : current_namespace) {
            upper_namespace.push_back(n);
            if (nodes[upper_namespace].first.count(name)) {
                return nodes[upper_namespace].first[name];
            }
        }
        return nullptr;
    }

    std::shared_ptr<T> get(std::string name, Scope namespace_) {
        Scope upper_namespace;
        for (auto& n : namespace_) {
            upper_namespace.push_back(n);
            if (nodes[upper_namespace].first.count(name)) {
                return nodes[upper_namespace].first[name];
            }
        }
        return nullptr;
    }

    std::shared_ptr<T> get_previous() {
        auto name = nodes[current_namespace].second.back();
        return nodes[current_namespace].first[name];
    }

    std::vector<std::shared_ptr<T>> get_all() {
        std::vector<std::shared_ptr<T>> res;
        for (auto& map_iter : nodes) {
            for (auto& name : map_iter.second.second) {
                res.push_back(map_iter.second.first[name]);
            }
        }
        return res;
    }

    std::vector<std::shared_ptr<T>> get_all(Scope namespace_) {
        std::vector<std::shared_ptr<T>> res;
        for (auto& name : nodes[namespace_].second) {
            res.push_back(nodes[namespace_].first[name]);
        }
        return res;
    }

    void set(std::string name, std::shared_ptr<T> node) {
        nodes[current_namespace].first[name] = node;
        nodes[current_namespace].second.push_back(name);
    }

    void set(std::string name, std::shared_ptr<T> node, Scope namespace_) {
        nodes[namespace_].first[name] = node;
        nodes[namespace_].second.push_back(name);
    }

    void into_namespace(std::string namespace_) {
        current_namespace.push_back(namespace_);
        std::pair<std::map<std::string, std::shared_ptr<T>>, Scope> empty;
        nodes[current_namespace] = empty;
    }

    void break_out_of_namespace() {
        if (!current_namespace.empty()) {
            current_namespace.pop_back();
        }
    }

    Scope get_namespace() { return current_namespace; }

    bool exist(std::string name) {
        if (get(name) != nullptr) {
            return true;
        } else {
            return false;
        }
    }

    bool is_current_top() { return (current_namespace.size() == 1); }

    std::string get_unique_name() {
        unsigned int n = unique_number_;
        unique_number_ += 1;
        std::string unique_name = "#" + std::to_string(n);
        return unique_name;
    }
    std::string get_namespace_as_string() {
        std::string cur = ".";
        for (auto& i : current_namespace) {
            cur += "/" + i;
        }
        return cur;
    }

    std::string get_namespace_as_string(Scope s) {
        std::string cur = ".";
        for (auto& i : s) {
            cur += "/" + i;
        }
        return cur;
    }

    void dump() {
        for (auto& node_map : nodes) {
            std::cout << "in scope '" << get_namespace_as_string(node_map.first)
                      << "':" << std::endl;
            for (auto& name : nodes[node_map.first].second) {
                std::cout << "    " << name << std::endl;
                // nodes[node_map.first].first[name];
            }
        }
    }
};
