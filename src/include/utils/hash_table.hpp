#pragma once
#include <type_traits>
#include <experimental/type_traits>
#include <unordered_map>

namespace utils
{
template <typename T>
using hash_function = decltype(std::declval<T>().hash());

template <typename T>
using has_hash_function = std::experimental::is_detected<hash_function, T>;

template <typename T>
class Hash
{
    private:
    size_t hash;

    public:
    Hash(const T& object)
    {
        static_assert(
            has_hash_function<T>::value,
            "Type argument of 'class Hash' must have hash() function");
        hash = object.hash();
    }
    struct HashForMap
    {
        size_t operator()(const Hash<T>& key) const { return key.hash; }
    };
    bool operator==(const Hash& rhs) const { return hash == rhs.hash; }
    bool operator!=(const Hash& rhs) const { return hash != rhs.hash; }
    bool operator<(const Hash& rhs) const { return hash < rhs.hash; }
    bool operator>(const Hash& rhs) const { return hash > rhs.hash; }
};

template <typename T>
class HashTable
{
    private:
    using table_type =
        std::unordered_map<Hash<T>, T, typename Hash<T>::HashForMap>;
    table_type table;
    HashTable() = default;
    static HashTable<T>& get_instance()
    {
        static HashTable<T> instance;
        return instance;
    }
    table_type& get_table() { return table; }

    public:
    static Hash<T> add(T&& object)
    {
        auto hash = Hash(object);
        if (!exists(hash))
        {
            get_instance().get_table().insert({hash, std::move(object)});
        }
        return hash;
    }
    static T& get(const Hash<T> hash)
    {
        return get_instance().get_table().at(hash);
    }
    static bool exists(const Hash<T> hash)
    {
        return static_cast<bool>(get_instance().get_table().count(hash));
    }
};
}  // namespace utils