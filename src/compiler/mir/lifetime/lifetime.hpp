#include <vector>
#include <memory>


namespace mir
{
    class LifeTime:public std::enable_shared_from_this<LifeTime>
    {
        private:
        std::vector<std::shared_ptr<LifeTime>> followers;
        std::vector<std::shared_ptr<LifeTime>> following;
    };
}