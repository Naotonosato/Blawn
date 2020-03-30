#include <vector>
#include <type_traits>

namespace utils {
template <typename To, typename From>
std::vector<To> transforme_variant_vector(const std::vector<From>& vector) {
    std::vector<To> res(vector.size());
    for (auto& v : vector) {
    }
}
}  // namespace utils