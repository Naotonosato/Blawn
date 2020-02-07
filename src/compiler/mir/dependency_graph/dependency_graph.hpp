#include <vector>
#include <memory>


namespace dependency_graph
{
class Node : public std::enable_shared_from_this<Node> {
    private:
    std::shared_ptr<Node> shared_this;
    std::vector<std::shared_ptr<Node>> dependencies;
    std::vector<std::shared_ptr<Node>> observers;//self instance has influence for observers;
    Node()=delete;

    template<typename Base>
    struct CreateHelper:Base
    {
        template<typename... Args>
        explicit CreateHelper(Args&&... args):Base(std::forward<Args>(args)...){}
    };

    public:
    Node(const Node&) = delete;
    static std::shared_ptr<Node> create();
    Node& operator=(const Node&) = delete;
    void depend(std::shared_ptr<Node> target);
    virtual void receive_notification(Node& from)=0;
    virtual void notify();
    std::vector<std::shared_ptr<Node>> get_dependencies() const;
    std::vector<std::shared_ptr<Node>> get_observers() const;
};
}