#pragma once
#include <unordered_map>
#include <unordered_set>
#include <iostream>

namespace algorithm
{
template <typename NodeType, typename IntegerType = uint64_t>
class UnionFindTree
{
    /*
    This algorithm may be possible to improve. Becaouse container of root nodes
    and ranks are unordered_map not fast accessing. To replace unordered_map to
    vector is way to optimize speed. But for simplicity,not yet implemented.
    */
    private:
    std::unordered_map<NodeType, NodeType> parents;
    std::unordered_map<NodeType, IntegerType> ranks;

    public:
    void add_root(NodeType node)
    {
        parents[node] = node;
        ranks[node] = 0;
    }
    void add_node(NodeType node, NodeType parent_node)
    {
        parents[node] = parent_node;
        auto root_of_node = get_root(node);
        if (ranks.count(root_of_node))
            ranks[root_of_node] += 1;
        else
            ranks[root_of_node] = 0;
    }

    NodeType get_root(NodeType node)
    {
        if (parents[node] == node)
            return node;
        else
        {
            parents[node] = get_root(parents[node]);
            return parents[node];
        }
    }
    void unite(NodeType node1, NodeType node2)
    {
        auto root_of_node1 = get_root(node1);
        auto root_of_node2 = get_root(node2);
        if (root_of_node1 == root_of_node2) return;

        if (ranks[root_of_node1] > ranks[root_of_node2])
        {
            parents[root_of_node2] = root_of_node1;
            return;
        }
        else
        {
            parents[root_of_node1] = root_of_node2;
            if (ranks[root_of_node1] == ranks[root_of_node2])
            {
                ranks[root_of_node2] += 1;
            }
            return;
        }
    }

    bool has_parent(NodeType node) const
    {
        return parents.contains(node);
        // return static_cast<bool>(parents.count(node));
    }

    const std::unordered_map<NodeType, NodeType>& get_parents() const
    {
        return parents;
    }

    const std::unordered_map<NodeType, IntegerType>& get_ranks() const
    {
        return ranks;
    }
};
}  // namespace algorithm