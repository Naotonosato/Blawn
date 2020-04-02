#include "graph.hpp"

namespace graph {
namespace algorithm {
template <typename VertexType>
using Edge = std::pair<VertexType, VertexType>;
template <typename VertexType>
void detect_cycle(Graph<VertexType> graph, VertexType vertex) {
    /*
    time: O(|E|) #E is num of edges
    memory: O(|V|) #V is num of vertexes
    algorithm: "DFS(depth-first search)"
    */
    std::vector<Edge<VertexType>> route;
    auto edges =
}
template <typename VertexType>
void _depth_first_search(Edges<VertexType>& edges, VertexType start,
                         VertexType goal, std::vector<Edge<VertexType>> stack) {
    for (auto& edge : edges[start]) {
        auto to = edge.second;
        if (to == goal) return stack;
        _depth_first_search(edges, to, goal, stack)
    }
    return stack;
}

template <typename VertexType>
void depth_first_search(Graph<VertexType> graph, VertexType start,
                        VertexType goal) {
    std::vector<VertexType> visited;
    std::vector<Edge<VertexType>> stack;
    auto edges = graph.get_edges();
    auto edges_from_start_vertex = edges[start];
    for (auto& edge : edges_from_start_vertex) {
        stack.push_back(edge);
        auto to = edge.second;
        if (to == goal) return stack;
        _depth_first_search(edges, to, goal, stack);
    }
    return stack;
}

}  // namespace algorithm
}  // namespace graph