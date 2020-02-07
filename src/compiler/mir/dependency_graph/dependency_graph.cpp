#include "dependency_graph.hpp"


namespace dependency_graph
{

std::shared_ptr<Node> Node::create()
{
    auto shared_this = std::make_shared<CreateHelper<Node>>();
    shared_this->shared_this = shared_this->shared_from_this();
    return shared_this;
}

void Node::depend(std::shared_ptr<Node> target) {
    dependencies.push_back(target);
    target->observers.push_back(shared_this);
}

void Node::notify()  {
    for (auto& node:observers)
    {
        node->receive_notification(*this);
    }    
}

std::vector<std::shared_ptr<Node>> Node::get_dependencies() const {
    return dependencies;
}

std::vector<std::shared_ptr<Node>> Node::get_observers() const {
    return observers;   
}
}