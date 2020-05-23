#include <vector>
#include <memory>
#include <unordered_map>
#include <set>
#include <unordered_set>

namespace graph
{
class Observable
{
    std::vector<std::shared_ptr<Observable>> dependencies;
    std::vector<std::shared_ptr<Observable>> observers;
    virtual void send_notification(std::shared_ptr<Observable> to);
    virtual void receive_notification(std::shared_ptr<Observable> from);
};

template <typename VertexType>
using Edge = typename std::pair<VertexType, VertexType>;
template <typename VertexType>
using Edges =
    typename std::unordered_map<VertexType, std::vector<Edge<VertexType>>>;

namespace directed_pseuduoforest
{
template <typename VertexType>
class Edge
{
    public:
    std::optional<VertexType> from;
    std::optional<VertexType> to;
};

template <typename VertexType>
class DirectedPseudoForest
{
    private:
    std::vector<Edge<VertexType>> edges;
    std::unordered_set<VertexType> vertexes;

    public:
    void add_edge(Edge<VertexType> new_edge)
    {
        vertexes.emplace(*new_edge.from);
        vertexes.emplace(*new_edge.to);
        edges.push_back(new_edge);
    }
    std::vector<Edge<VertexType>> const& get_edges() const { return edges; }
    std::unordered_set<VertexType> const& get_vertexes() const
    {
        return vertexes;
    }
};
}  // namespace directed_pseuduoforest

template <typename VertexType>
class Graph
{
    private:
    // using Edge = std::pair<VertexType,VertexType>;
    // using Edges = std::unordered_map<VertexType,std::vector<Edge>>;
    Edges<VertexType> edges;
    std::set<VertexType> vertexes;

    public:
    void add_edge(VertexType vertex, Edge<VertexType> edge)
    {
        vertexes.emplace(edges.first);
        vertexes.emplace(edges.second);
        edges[vertex].push_back(edge);
    }
    void add_edge(VertexType from, VertexType to)
    {
        auto edge = std::make_pair(from, to);
        add_edge(from, edge);
    }
    Edges<VertexType> const& get_edges() { return edges; }
    std::set<VertexType> const& get_vertexes() { return vertexes; }
};

template <typename NodeType>
class Node : public std::enable_shared_from_this<NodeType>
{
    private:
    std::shared_ptr<NodeType> shared_this;
    std::vector<std::shared_ptr<NodeType>> dependencies;
    std::vector<std::shared_ptr<NodeType>>
        observers;  // self instance has influence for observers;
    // Node()=delete;
    // template<typename... Args> Node(Args...);
    struct CreateHelper : NodeType
    {
        template <typename... Args>
        explicit CreateHelper(std::string args) : NodeType(args)
        {
        }
    };

    public:
    Node(const Node&) = delete;

    Node& operator=(const Node&) = delete;
    void depend(std::shared_ptr<NodeType> target)
    {
        dependencies.push_back(target);
        target->observers.push_back(shared_this);
    }
    virtual void notify()
    {
        for (auto& node : observers)
        {
            auto& self = *static_cast<NodeType*>(this);
            node->receive_notification(self);
        }
    }
    virtual void receive_notification(NodeType& from) = 0;
    std::vector<std::shared_ptr<NodeType>> get_dependencies() const
    {
        return dependencies;
    }
    std::vector<std::shared_ptr<NodeType>> get_observers() const
    {
        return observers;
    }
};
};  // namespace graph

/*
class list
(
    @typeid = lazy
    ...
)

l = list() -- type(l) is lazy
l2 = list() -- type(l2) is lazy
l2.append(l) -- type(l2) depends type(l)
l.append(10) -- type(l) is int >>> type(l2) is int

*/