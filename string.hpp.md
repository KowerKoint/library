---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  - icon: ':question:'
    path: stl-wrapper/all.hpp
    title: stl-wrapper/all.hpp
  - icon: ':question:'
    path: stl-wrapper/map.hpp
    title: stl-wrapper/map.hpp
  - icon: ':question:'
    path: stl-wrapper/pair.hpp
    title: stl-wrapper/pair.hpp
  - icon: ':question:'
    path: stl-wrapper/set.hpp
    title: stl-wrapper/set.hpp
  - icon: ':question:'
    path: stl-wrapper/unordered_map.hpp
    title: stl-wrapper/unordered_map.hpp
  - icon: ':question:'
    path: stl-wrapper/unordered_set.hpp
    title: stl-wrapper/unordered_set.hpp
  - icon: ':question:'
    path: stl-wrapper/vector.hpp
    title: stl-wrapper/vector.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string.hpp\"\n\n#line 2 \"base.hpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 4 \"stl-wrapper/pair.hpp\"\n\ntemplate <typename\
    \ T1, typename T2>\nstruct Pair : public std::pair<T1, T2> {\n    constexpr Pair()\
    \ : std::pair<T1, T2>() {}\n    constexpr Pair(const T1& first, const T2& second)\
    \ : std::pair<T1, T2>(first, second) {}\n    template <typename U1, typename U2>\n\
    \    constexpr Pair(U1&& first, U2&& second) : std::pair<T1, T2>(std::forward<U1>(first),\
    \ std::forward<U2>(second)) {}\n    template <typename U1, typename U2>\n    constexpr\
    \ Pair(const std::pair<U1, U2>& other) : std::pair<T1, T2>(other) {}\n    template\
    \ <typename U1, typename U2>\n    constexpr Pair(std::pair<U1, U2>&& other) :\
    \ std::pair<T1, T2>(std::move(other)) {}\n    template <typename... Args1, typename...\
    \ Args2>\n    Pair(std::piecewise_construct_t, std::tuple<Args1...> first_args,\
    \ std::tuple<Args2...> second_args) : std::pair<T1, T2>(std::piecewise_construct,\
    \ first_args, second_args) {}\n    friend std::istream& operator>>(std::istream&\
    \ is, Pair& p) {\n        return is >> p.first >> p.second;\n    }\n    friend\
    \ std::ostream& operator<<(std::ostream& os, const Pair& p) {\n        return\
    \ os << p.first << ' ' << p.second;\n    }\n};\nnamespace std {\n    template\
    \ <typename T1, typename T2>\n    struct hash<Pair<T1, T2>> {\n        size_t\
    \ operator()(const Pair<T1, T2>& p) const {\n            size_t seed = 0;\n  \
    \          seed ^= hash<T1>()(p.first) + 0x9e3779b9 + (seed << 6) + (seed >> 2);\n\
    \            seed ^= hash<T2>()(p.second) + 0x9e3779b9 + (seed << 6) + (seed >>\
    \ 2);\n            return seed;\n        }\n    };\n}\n#line 5 \"stl-wrapper/vector.hpp\"\
    \n\ntemplate <typename T>\nstruct Vector : std::vector<T> {\n    Vector() noexcept\
    \ : std::vector<T>() {}\n    explicit Vector(size_t count) : std::vector<T>(count,\
    \ T()) {}\n    Vector(size_t count, const T& value) : std::vector<T>(count, value)\
    \ {}\n    template <typename InputIt>\n    Vector(InputIt first, InputIt last)\
    \ : std::vector<T>(first, last) {}\n    Vector(const std::vector<T>& other) :\
    \ std::vector<T>(other) {}\n    Vector(std::vector<T>&& other) noexcept : std::vector<T>(std::move(other))\
    \ {}\n    Vector(std::initializer_list<T> init) : std::vector<T>(init) {}\n  \
    \  const T& operator[](size_t i) const {\n        assert(i < this->size());\n\
    \        return std::vector<T>::operator[](i);\n    }\n    T& operator[](size_t\
    \ i) {\n        assert(i < this->size());\n        return std::vector<T>::operator[](i);\n\
    \    }\n    const T& front() const {\n        assert(!this->empty());\n      \
    \  return std::vector<T>::front();\n    }\n    T& front() {\n        assert(!this->empty());\n\
    \        return std::vector<T>::front();\n    }\n    const T& back() const {\n\
    \        assert(!this->empty());\n        return std::vector<T>::back();\n   \
    \ }\n    T& back() {\n        assert(!this->empty());\n        return std::vector<T>::back();\n\
    \    }\n    friend std::istream& operator>>(std::istream& is, Vector& v) {\n \
    \       for (auto& x : v) is >> x;\n        return is;\n    }\n    friend std::ostream&\
    \ operator<<(std::ostream& os, const Vector& v) {\n        for (size_t i = 0;\
    \ i < v.size(); ++i) {\n            if (i) os << ' ';\n            os << v[i];\n\
    \        }\n        return os;\n    }\n};\nnamespace std {\n    template <typename\
    \ T>\n    struct hash<Vector<T>> {\n        size_t operator()(const Vector<T>&\
    \ v) const {\n            size_t seed = 0;\n            for (const auto& x : v)\
    \ seed ^= hash<T>{}(x) + 0x9e3779b9 + (seed << 6) + (seed >> 2);\n           \
    \ return seed;\n        }\n    };\n};\n#line 4 \"stl-wrapper/set.hpp\"\n#include\
    \ <ext/pb_ds/assoc_container.hpp>\n#include <ext/pb_ds/tree_policy.hpp>\n#line\
    \ 7 \"stl-wrapper/set.hpp\"\n\n\ntemplate <typename T, typename Compare = std::less<T>>\n\
    using pbds_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, Compare, __gnu_pbds::rb_tree_tag,\
    \ __gnu_pbds::tree_order_statistics_node_update>;\n\ntemplate <typename T, typename\
    \ Compare = std::less<T>>\nstruct Set : public pbds_set<T, Compare> {\n    Set()\
    \ : pbds_set<T, Compare>() {}\n    explicit Set(const Compare& comp) : pbds_set<T,\
    \ Compare>(comp) {}\n    template <typename It>\n    Set(It first, It last, const\
    \ Compare& comp = Compare()) : pbds_set<T, Compare>(first, last, comp) {}\n  \
    \  Set(const pbds_set<T, Compare>& other) : pbds_set<T, Compare>(other) {}\n \
    \   Set(const std::set<T, Compare>& other) : pbds_set<T, Compare>(other.begin(),\
    \ other.end()) {}\n    Set(pbds_set<T, Compare>&& other) : pbds_set<T, Compare>(std::move(other))\
    \ {}\n    Set(std::initializer_list<T> init, const Compare& comp = Compare())\
    \ : pbds_set<T, Compare>(init, comp) {}\n    typename Set::const_iterator cbegin()\
    \ const { return this->begin(); }\n    typename Set::const_iterator cend() const\
    \ { return this->end(); }\n    typename Set::const_reverse_iterator crbegin()\
    \ const { return this->rbegin(); }\n    typename Set::const_reverse_iterator crend()\
    \ const { return this->rend(); }\n    template <typename K>\n    std::pair<typename\
    \ Set::iterator, typename Set::iterator> equal_range(const K& value) {\n     \
    \   return std::make_pair(lower_bound(value), upper_bound(value));\n    }\n  \
    \  template <typename K>\n    std::pair<typename Set::const_iterator, typename\
    \ Set::const_iterator> equal_range(const K& value) const {\n        return std::make_pair(lower_bound(value),\
    \ upper_bound(value));\n    }\n    template <typename K>\n    size_t count(const\
    \ K& x) const { return this->find(x) != this->end(); }\n    decltype(Compare())\
    \ key_comp() const { return Compare(); }\n    template <typename... Args>\n  \
    \  std::pair<typename Set::iterator, bool> emplace(Args&&... args) {\n       \
    \ return this->insert(T(std::forward<Args>(args)...));\n    }\n    template <typename...\
    \ Args>\n    typename Set::iterator emplace_hint(typename Set::const_iterator\
    \ hint, Args&&... args) {\n        return this->insert(hint, T(std::forward<Args>(args)...));\n\
    \    }\n    friend std::ostream& operator<<(std::ostream& os, const Set& set)\
    \ {\n        Vector<T> vector(set.begin(), set.end());\n        return os << vector;\n\
    \    }\n};\n\nnamespace _set_util {\n    template <typename T, typename Compare>\n\
    \    struct CompareEqual {\n        bool operator()(const T& lhs, const T& rhs)\
    \ const {\n            return !Compare()(rhs, lhs);\n        }\n    };\n}\ntemplate\
    \ <typename T, typename Compare = std::less<T>>\nusing pbds_multiset = __gnu_pbds::tree<T,\
    \ __gnu_pbds::null_type, _set_util::CompareEqual<T, Compare>, __gnu_pbds::rb_tree_tag,\
    \ __gnu_pbds::tree_order_statistics_node_update>;\n\ntemplate <typename T, typename\
    \ Compare = std::less<T>>\nstruct MultiSet : public pbds_multiset<T, Compare>\
    \ {\n    MultiSet() : pbds_multiset<T, Compare>() {}\n    explicit MultiSet(const\
    \ Compare& comp) : pbds_multiset<T, Compare>(comp) {}\n    template <typename\
    \ It>\n    MultiSet(It first, It last, const Compare& comp = Compare()) : pbds_multiset<T,\
    \ Compare>(first, last, comp) {}\n    MultiSet(const pbds_multiset<T, Compare>&\
    \ other) : pbds_multiset<T, Compare>(other) {}\n    MultiSet(const std::multiset<T,\
    \ Compare>& other) : pbds_multiset<T, Compare>(other.begin(), other.end()) {}\n\
    \    MultiSet(pbds_multiset<T, Compare>&& other) : pbds_multiset<T, Compare>(std::move(other))\
    \ {}\n    MultiSet(std::initializer_list<T> init, const Compare& comp = Compare())\
    \ : pbds_multiset<T, Compare>(init, comp) {}\n    typename MultiSet::const_iterator\
    \ cbegin() const { return this->begin(); }\n    typename MultiSet::const_iterator\
    \ cend() const { return this->end(); }\n    typename MultiSet::const_reverse_iterator\
    \ crbegin() const { return this->rbegin(); }\n    typename MultiSet::const_reverse_iterator\
    \ crend() const { return this->rend(); }\n    template <typename K>\n    std::pair<typename\
    \ MultiSet::iterator, typename MultiSet::iterator> equal_range(const K& value)\
    \ {\n        return std::make_pair(lower_bound(value), upper_bound(value));\n\
    \    }\n    template <typename K>\n    std::pair<typename MultiSet::const_iterator,\
    \ typename MultiSet::const_iterator> equal_range(const K& value) const {\n   \
    \     return std::make_pair(lower_bound(value), upper_bound(value));\n    }\n\
    \    template <typename K>\n    size_t count(const K& x) const {\n        auto\
    \ range = equal_range(x);\n        return std::distance(range.first, range.second);\n\
    \    }\n    decltype(Compare()) key_comp() const { return Compare(); }\n    template\
    \ <typename... Args>\n    typename MultiSet::iterator emplace(Args&&... args)\
    \ {\n        return this->insert(T(std::forward<Args>(args)...));\n    }\n   \
    \ template <typename... Args>\n    typename MultiSet::iterator emplace_hint(typename\
    \ MultiSet::const_iterator hint, Args&&... args) {\n        return this->insert(hint,\
    \ T(std::forward<Args>(args)...));\n    }\n    friend std::ostream& operator<<(std::ostream&\
    \ os, const MultiSet& set) {\n        Vector<T> vector(set.begin(), set.end());\n\
    \        return os << vector;\n    }\n};\nnamespace std {\n    template <typename\
    \ T, typename Compare>\n    struct hash<Set<T, Compare>> {\n        size_t operator()(const\
    \ Set<T, Compare>& set) const {\n            Vector<T> vec(set.begin(), set.end());\n\
    \            return hash<Vector<T>>()(vec);\n        }\n    };\n    template <typename\
    \ T, typename Compare>\n    struct hash<MultiSet<T, Compare>> {\n        size_t\
    \ operator()(const MultiSet<T, Compare>& set) const {\n            Vector<T> vec(set.begin(),\
    \ set.end());\n            return hash<Vector<T>>()(vec);\n        }\n    };\n\
    };\n#line 7 \"stl-wrapper/map.hpp\"\n\ntemplate <typename Key, typename Value,\
    \ typename Compare>\nusing pbds_map = __gnu_pbds::tree<Key, Value, Compare, __gnu_pbds::rb_tree_tag,\
    \ __gnu_pbds::tree_order_statistics_node_update>;\n\ntemplate <typename Key, typename\
    \ Value, typename Compare = std::less<Key>>\nstruct Map : pbds_map<Key, Value,\
    \ Compare> {\n    Map() : pbds_map<Key, Value, Compare>() {}\n    explicit Map(const\
    \ Compare& comp) : pbds_map<Key, Value, Compare>(comp) {}\n    template <typename\
    \ It>\n    Map(It first, It last, const Compare& comp = Compare()) : pbds_map<Key,\
    \ Value, Compare>(first, last, comp) {}\n    Map(const pbds_map<Key, Value, Compare>&\
    \ other) : pbds_map<Key, Value, Compare>(other) {}\n    Map(const std::map<Key,\
    \ Value, Compare>& other) : pbds_map<Key, Value, Compare>(other.begin(), other.end())\
    \ {}\n    Map(pbds_map<Key, Value, Compare>&& other) : pbds_map<Key, Value, Compare>(std::move(other))\
    \ {}\n    Map(std::initializer_list<std::pair<Key, Value>> init, const Compare&\
    \ comp = Compare()) : pbds_map<Key, Value, Compare>(init, comp) {}\n    typename\
    \ Map::const_iterator cbegin() const { return this->begin(); }\n    typename Map::const_iterator\
    \ cend() const { return this->end(); }\n    typename Map::const_reverse_iterator\
    \ crbegin() const { return this->rbegin(); }\n    typename Map::const_reverse_iterator\
    \ crend() const { return this->rend(); }\n    template <typename K>\n    std::pair<typename\
    \ Map::iterator, typename Map::iterator> equal_range(const K& value) {\n     \
    \   return std::make_pair(lower_bound(value), upper_bound(value));\n    }\n  \
    \  template <typename K>\n    std::pair<typename Map::const_iterator, typename\
    \ Map::const_iterator> equal_range(const K& value) const {\n        return std::make_pair(lower_bound(value),\
    \ upper_bound(value));\n    }\n    Value& at(const Key& key) {\n        auto it\
    \ = find(key);\n        assert(it != this->end());\n        return it->second;\n\
    \    }\n    const Value& at(const Key& key) const {\n        auto it = find(key);\n\
    \        assert(it != this->end());\n        return it->second;\n    }\n    template\
    \ <typename K>\n    size_t count(const K& x) const { return this->find(x) != this->end();\
    \ }\n    decltype(Compare()) key_comp() const { return Compare(); }\n    template\
    \ <typename... Args>\n    std::pair<typename Map::iterator, bool> emplace(Args&&...\
    \ args) {\n        return this->insert(std::make_pair(std::forward<Args>(args)...));\n\
    \    }\n    template <typename... Args>\n    typename Map::iterator emplace_hint(typename\
    \ Map::const_iterator hint, Args&&... args) {\n        return this->insert(hint,\
    \ std::make_pair(std::forward<Args>(args)...));\n    }\n    friend std::ostream&\
    \ operator<<(std::ostream& out, const Map& map) {\n        for (auto it = map.begin();\
    \ it != map.end(); ++it) {\n            out << it->first << ' ' << it->second\
    \ << '\\n';\n        }\n        return out;\n    }\n};\n\nnamespace _map_util\
    \ {\n    template <typename T, typename Compare>\n    struct CompareEqual {\n\
    \        bool operator()(const T& lhs, const T& rhs) const {\n            return\
    \ !Compare()(rhs, lhs);\n        }\n    };\n}\ntemplate <typename Key, typename\
    \ Value, typename Compare = std::less<Key>>\nusing pbds_multimap = __gnu_pbds::tree<Key,\
    \ Value, _map_util::CompareEqual<Key, Compare>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;\n\
    \ntemplate <typename Key, typename Value, typename Compare = std::less<Key>>\n\
    struct MultiMap : pbds_multimap<Key, Value, Compare> {\n    MultiMap() : pbds_multimap<Key,\
    \ Value, Compare>() {}\n    explicit MultiMap(const Compare& comp) : pbds_multimap<Key,\
    \ Value, Compare>(comp) {}\n    template <typename It>\n    MultiMap(It first,\
    \ It last, const Compare& comp = Compare()) : pbds_multimap<Key, Value, Compare>(first,\
    \ last, comp) {}\n    MultiMap(const pbds_multimap<Key, Value, Compare>& other)\
    \ : pbds_multimap<Key, Value, Compare>(other) {}\n    MultiMap(const std::multimap<Key,\
    \ Value, Compare>& other) : pbds_multimap<Key, Value, Compare>(other.begin(),\
    \ other.end()) {}\n    MultiMap(pbds_multimap<Key, Value, Compare>&& other) :\
    \ pbds_multimap<Key, Value, Compare>(std::move(other)) {}\n    MultiMap(std::initializer_list<std::pair<Key,\
    \ Value>> init, const Compare& comp = Compare()) : pbds_multimap<Key, Value, Compare>(init,\
    \ comp) {}\n    typename MultiMap::const_iterator cbegin() const { return this->begin();\
    \ }\n    typename MultiMap::const_iterator cend() const { return this->end();\
    \ }\n    typename MultiMap::const_reverse_iterator crbegin() const { return this->rbegin();\
    \ }\n    typename MultiMap::const_reverse_iterator crend() const { return this->rend();\
    \ }\n    template <typename K>\n    std::pair<typename MultiMap::iterator, typename\
    \ MultiMap::iterator> equal_range(const K& value) {\n        return std::make_pair(lower_bound(value),\
    \ upper_bound(value));\n    }\n    template <typename K>\n    std::pair<typename\
    \ MultiMap::const_iterator, typename MultiMap::const_iterator> equal_range(const\
    \ K& value) const {\n        return std::make_pair(lower_bound(value), upper_bound(value));\n\
    \    }\n    Value& at(const Key& key) {\n        auto it = find(key);\n      \
    \  assert(it != this->end());\n        return it->second;\n    }\n    const Value&\
    \ at(const Key& key) const {\n        auto it = find(key);\n        assert(it\
    \ != this->end());\n        return it->second;\n    }\n    template <typename\
    \ K>\n    size_t count(const K& x) const {\n        auto range = equal_range(x);\n\
    \        return std::distance(range.first, range.second);\n    }\n    decltype(Compare())key_comp()\
    \ const { return Compare(); }\n    template <typename... Args>\n    typename MultiMap::iterator\
    \ emplace(Args&&... args) {\n        return this->insert(std::make_pair(std::forward<Args>(args)...));\n\
    \    }\n    template <typename... Args>\n    typename MultiMap::iterator emplace_hint(typename\
    \ MultiMap::const_iterator hint, Args&&... args) {\n        return this->insert(hint,\
    \ std::make_pair(std::forward<Args>(args)...));\n    }\n    friend std::ostream&\
    \ operator<<(std::ostream& out, const MultiMap& map) {\n        for (auto it =\
    \ map.begin(); it != map.end(); ++it) {\n            out << it->first << ' ' <<\
    \ it->second << '\\n';\n        }\n        return out;\n    }\n};\n\nnamespace\
    \ std {\n    template <typename Key, typename Value, typename Compare>\n    struct\
    \ hash<Map<Key, Value, Compare>> {\n        size_t operator()(const Map<Key, Value,\
    \ Compare>& map) const {\n            Vector<pair<Key, Value>> v(map.begin(),\
    \ map.end());\n            return hash<Vector<pair<Key, Value>>>()(v);\n     \
    \   }\n    };\n    template <typename Key, typename Value, typename Compare>\n\
    \    struct hash<MultiMap<Key, Value, Compare>> {\n        size_t operator()(const\
    \ Map<Key, Value, Compare>& map) const {\n            Vector<pair<Key, Value>>\
    \ v(map.begin(), map.end());\n            return hash<Vector<pair<Key, Value>>>()(v);\n\
    \        }\n    };\n}\n#line 9 \"stl-wrapper/unordered_set.hpp\"\n\ntemplate <typename\
    \ T, typename Hash = std::hash<T>, typename KeyEqual = std::equal_to<T>>\nusing\
    \ pbds_unordered_set = __gnu_pbds::gp_hash_table<T, __gnu_pbds::null_type, Hash,\
    \ KeyEqual>;\n\ntemplate <typename T, typename Hash = std::hash<T>, typename KeyEqual\
    \ = std::equal_to<T>>\nstruct UnorderedSet : public pbds_unordered_set<T, Hash,\
    \ KeyEqual> {\n    UnorderedSet() : pbds_unordered_set<T, Hash, KeyEqual>() {}\n\
    \    explicit UnorderedSet(std::size_t bucket_count, const Hash& hash = Hash(),\
    \ const KeyEqual& equal = KeyEqual()) : pbds_unordered_set<T, Hash, KeyEqual>(bucket_count,\
    \ hash, equal) {}\n    template <typename InputIt>\n    UnorderedSet(InputIt first,\
    \ InputIt last, std::size_t bucket_count = 1, const Hash& hash = Hash(), const\
    \ KeyEqual& equal = KeyEqual()) : pbds_unordered_set<T, Hash, KeyEqual>(first,\
    \ last, bucket_count, hash, equal) {}\n    UnorderedSet(const pbds_unordered_set<T,\
    \ Hash, KeyEqual>& other) : pbds_unordered_set<T, Hash, KeyEqual>(other) {}\n\
    \    UnorderedSet(const std::unordered_set<T, Hash, KeyEqual>& other) : pbds_unordered_set<T,\
    \ Hash, KeyEqual>(other.begin(), other.end()) {}\n    UnorderedSet(pbds_unordered_set<T,\
    \ Hash, KeyEqual>&& other) : pbds_unordered_set<T, Hash, KeyEqual>(std::move(other))\
    \ {}\n    UnorderedSet(std::initializer_list<T> init, std::size_t bucket_count\
    \ = 1, const Hash& hash = Hash(), const KeyEqual& equal = KeyEqual()) : pbds_unordered_set<T,\
    \ Hash, KeyEqual>(init, bucket_count, hash, equal) {}\n    typename UnorderedSet::const_iterator\
    \ cbegin() const { return this->begin(); }\n    typename UnorderedSet::const_iterator\
    \ cend() const { return this->end(); }\n    KeyEqual key_eq() const { return KeyEqual();\
    \ }\n    std::size_t count(const T& value) const { return this->find(value) !=\
    \ this->end(); }\n    template <typename... Args>\n    std::pair<typename UnorderedSet::iterator,\
    \ bool> emplace(Args&&... args) { return this->insert(T(std::forward<Args>(args)...));\
    \ }\n    template <typename... Args>\n    typename UnorderedSet::iterator emplace_hint(typename\
    \ UnorderedSet::const_iterator hint, Args&&... args) { return this->insert(hint,\
    \ T(std::forward<Args>(args)...)); }\n    friend std::ostream& operator<<(std::ostream&\
    \ os, const UnorderedSet& set) {\n        for (auto it = set.begin(); it != set.end();\
    \ ++it) {\n            if(it != set.begin()) os << \" \";\n            os << *it;\n\
    \        }\n        return os;\n    }\n};\ntemplate <typename T, typename Hash\
    \ = std::hash<T>, typename KeyEqual = std::equal_to<T>>\nstruct UnorderedMultiSet\
    \ : std::unordered_multiset<T, Hash, KeyEqual> {\n    UnorderedMultiSet() : std::unordered_multiset<T,\
    \ Hash, KeyEqual>() {}\n    explicit UnorderedMultiSet(std::size_t bucket_count,\
    \ const Hash& hash = Hash(), const KeyEqual& equal = KeyEqual()) : std::unordered_multiset<T,\
    \ Hash, KeyEqual>(bucket_count, hash, equal) {}\n    template <typename InputIt>\n\
    \    UnorderedMultiSet(InputIt first, InputIt last, std::size_t bucket_count =\
    \ 1, const Hash& hash = Hash(), const KeyEqual& equal = KeyEqual()) : std::unordered_multiset<T,\
    \ Hash, KeyEqual>(first, last, bucket_count, hash, equal) {}\n    UnorderedMultiSet(const\
    \ std::unordered_set<T, Hash, KeyEqual>& other) : std::unordered_multiset<T, Hash,\
    \ KeyEqual>(other) {}\n    UnorderedMultiSet(std::unordered_set<T, Hash, KeyEqual>&&\
    \ other) : std::unordered_multiset<T, Hash, KeyEqual>(std::move(other)) {}\n \
    \   UnorderedMultiSet(std::initializer_list<T> init, std::size_t bucket_count\
    \ = 1, const Hash& hash = Hash(), const KeyEqual& equal = KeyEqual()) : std::unordered_multiset<T,\
    \ Hash, KeyEqual>(init, bucket_count, hash, equal) {}\n    friend std::ostream&\
    \ operator<<(std::ostream& os, const UnorderedMultiSet& set) {\n        for (auto\
    \ it = set.begin(); it != set.end(); ++it) {\n            if(it != set.begin())\
    \ os << \" \";\n            os << *it;\n        }\n        return os;\n    }\n\
    };\nnamespace std {\n    template<typename T, typename Hash, typename KeyEqual>\n\
    \    struct hash<UnorderedSet<T, Hash, KeyEqual>> {\n        size_t operator()(const\
    \ UnorderedSet<T, Hash, KeyEqual>& set) const {\n            Vector<T> vec(set.begin(),\
    \ set.end());\n            sort(vec.begin(), vec.end());\n            return hash<Vector<T>>()(vec);\n\
    \        }\n    };\n    template<typename T, typename Hash, typename KeyEqual>\n\
    \    struct hash<UnorderedMultiSet<T, Hash, KeyEqual>> {\n        size_t operator()(const\
    \ UnorderedMultiSet<T, Hash, KeyEqual>& set) const {\n            Vector<T> vec(set.begin(),\
    \ set.end());\n            sort(vec.begin(), vec.end());\n            return hash<Vector<T>>()(vec);\n\
    \        }\n    };\n}\n#line 9 \"stl-wrapper/unordered_map.hpp\"\n\ntemplate <typename\
    \ Key, typename Value, typename Hash = std::hash<Key>, typename KeyEqual = std::equal_to<Key>>\n\
    using pbds_unordered_map = __gnu_pbds::gp_hash_table<Key, Value, Hash, KeyEqual>;\n\
    \ntemplate <typename Key, typename Value, typename Hash = std::hash<Key>, typename\
    \ KeyEqual = std::equal_to<Key>>\nstruct UnorderedMap : public pbds_unordered_map<Key,\
    \ Value, Hash, KeyEqual> {\n    UnorderedMap() : pbds_unordered_map<Key, Value,\
    \ Hash, KeyEqual>() {}\n    explicit UnorderedMap(std::size_t bucket_count, const\
    \ Hash& hash = Hash(), const KeyEqual& equal = KeyEqual()) : pbds_unordered_map<Key,\
    \ Value, Hash, KeyEqual>(bucket_count, hash, equal) {}\n    template <typename\
    \ InputIt>\n    UnorderedMap(InputIt first, InputIt last, std::size_t bucket_count\
    \ = 1, const Hash& hash = Hash(), const KeyEqual& equal = KeyEqual()) : pbds_unordered_map<Key,\
    \ Value, Hash, KeyEqual>(first, last, bucket_count, hash, equal) {}\n    UnorderedMap(const\
    \ pbds_unordered_map<Key, Value, Hash, KeyEqual>& other) : pbds_unordered_map<Key,\
    \ Value, Hash, KeyEqual>(other) {}\n    UnorderedMap(const std::unordered_map<Key,\
    \ Value, Hash, KeyEqual>& other) : pbds_unordered_map<Key, Value, Hash, KeyEqual>(other.begin(),\
    \ other.end()) {}\n    UnorderedMap(pbds_unordered_map<Key, Value, Hash, KeyEqual>&&\
    \ other) noexcept : pbds_unordered_map<Key, Value, Hash, KeyEqual>(std::move(other))\
    \ {}\n    UnorderedMap(std::initializer_list<std::pair<Key, Value>> init, std::size_t\
    \ bucket_count = 1, const Hash& hash = Hash(), const KeyEqual& equal = KeyEqual())\
    \ : pbds_unordered_map<Key, Value, Hash, KeyEqual>(init, bucket_count, hash, equal)\
    \ {}\n    friend std::ostream& operator<<(std::ostream& os, const UnorderedMap&\
    \ set) {\n        for (auto it = set.begin(); it != set.end(); ++it) {\n     \
    \       os << it->first << ' ' << it->second << '\\n';\n        }\n        return\
    \ os;\n    }\n};\n\ntemplate <typename Key, typename Value, typename Hash = std::hash<Key>,\
    \ typename KeyEqual = std::equal_to<Key>>\nstruct UnorderedMultiMap : std::unordered_multimap<Key,\
    \ Value, Hash, KeyEqual> {\n    UnorderedMultiMap() : std::unordered_multimap<Key,\
    \ Value, Hash, KeyEqual>() {}\n    explicit UnorderedMultiMap(std::size_t bucket_count,\
    \ const Hash& hash = Hash(), const KeyEqual& equal = KeyEqual()) : std::unordered_multimap<Key,\
    \ Value, Hash, KeyEqual>(bucket_count, hash, equal) {}\n    template <typename\
    \ InputIt>\n    UnorderedMultiMap(InputIt first, InputIt last, std::size_t bucket_count\
    \ = 1, const Hash& hash = Hash(), const KeyEqual& equal = KeyEqual()) : std::unordered_multimap<Key,\
    \ Value, Hash, KeyEqual>(first, last, bucket_count, hash, equal) {}\n    UnorderedMultiMap(const\
    \ std::unordered_map<Key, Value, Hash, KeyEqual>& other) : std::unordered_multimap<Key,\
    \ Value, Hash, KeyEqual>(other) {}\n    UnorderedMultiMap(std::unordered_map<Key,\
    \ Value, Hash, KeyEqual>&& other) noexcept : std::unordered_multimap<Key, Value,\
    \ Hash, KeyEqual>(std::move(other)) {}\n    UnorderedMultiMap(std::initializer_list<std::pair<Key,\
    \ Value>> init, std::size_t bucket_count = 1, const Hash& hash = Hash(), const\
    \ KeyEqual& equal = KeyEqual()) : std::unordered_multimap<Key, Value, Hash, KeyEqual>(init,\
    \ bucket_count, hash, equal) {}\n    friend std::ostream& operator<<(std::ostream&\
    \ os, const UnorderedMultiMap& map) {\n        for (auto it = map.begin(); it\
    \ != map.end(); ++it) {\n            os << it->first << ' ' << it->second << '\\\
    n';\n        }\n        return os;\n    }\n};\nnamespace std {\n    template<typename\
    \ T, typename Hash, typename KeyEqual>\n    struct hash<UnorderedMap<T, Hash,\
    \ KeyEqual>> {\n        size_t operator()(const UnorderedMap<T, Hash, KeyEqual>&\
    \ map) const {\n            Vector<T> vec(map.begin(), map.end());\n         \
    \   sort(vec.begin(), vec.end());\n            return hash<Vector<T>>()(vec);\n\
    \        }\n    };\n    template<typename T, typename Hash, typename KeyEqual>\n\
    \    struct hash<UnorderedMultiMap<T, Hash, KeyEqual>> {\n        size_t operator()(const\
    \ UnorderedMultiMap<T, Hash, KeyEqual>& map) const {\n            Vector<T> vec(map.begin(),\
    \ map.end());\n            sort(vec.begin(), vec.end());\n            return hash<Vector<T>>()(vec);\n\
    \        }\n    };\n}\n#line 7 \"base.hpp\"\n\n#define REP(i, n) for(int i = 0;\
    \ i < (int)(n); i++)\n#define FOR(i, a, b) for(ll i = a; i < (ll)(b); i++)\n#define\
    \ ALL(a) (a).begin(),(a).end()\n#define RALL(a) (a).rbegin(),(a).rend()\n#define\
    \ END(...) { print(__VA_ARGS__); return; }\n\nusing VI = Vector<int>;\nusing VVI\
    \ = Vector<VI>;\nusing VVVI = Vector<VVI>;\nusing ll = long long;\nusing VL =\
    \ Vector<ll>;\nusing VVL = Vector<VL>;\nusing VVVL = Vector<VVL>;\nusing ull =\
    \ unsigned long long;\nusing VUL = Vector<ull>;\nusing VVUL = Vector<VUL>;\nusing\
    \ VVVUL = Vector<VVUL>;\nusing VD = Vector<double>;\nusing VVD = Vector<VD>;\n\
    using VVVD = Vector<VVD>;\nusing VS = Vector<string>;\nusing VVS = Vector<VS>;\n\
    using VVVS = Vector<VVS>;\nusing VC = Vector<char>;\nusing VVC = Vector<VC>;\n\
    using VVVC = Vector<VVC>;\nusing P = Pair<int, int>;\nusing VP = Vector<P>;\n\
    using VVP = Vector<VP>;\nusing VVVP = Vector<VVP>;\nusing LP = Pair<ll, ll>;\n\
    using VLP = Vector<LP>;\nusing VVLP = Vector<VLP>;\nusing VVVLP = Vector<VVLP>;\n\
    \ntemplate <typename T>\nusing PQ = priority_queue<T>;\ntemplate <typename T>\n\
    using GPQ = priority_queue<T, vector<T>, greater<T>>;\n\nconstexpr int INF = 1001001001;\n\
    constexpr ll LINF = 1001001001001001001ll;\nconstexpr int DX[] = {1, 0, -1, 0};\n\
    constexpr int DY[] = {0, 1, 0, -1};\n\nvoid print() { cout << '\\n'; }\ntemplate<typename\
    \ T>\nvoid print(const T &t) { cout << t << '\\n'; }\ntemplate<typename Head,\
    \ typename... Tail>\nvoid print(const Head &head, const Tail &... tail) {\n  \
    \  cout << head << ' ';\n    print(tail...);\n}\n\n#ifdef DEBUG\nvoid dbg() {\
    \ cerr << '\\n'; }\ntemplate<typename T>\nvoid dbg(const T &t) { cerr << t <<\
    \ '\\n'; }\ntemplate<typename Head, typename... Tail>\nvoid dbg(const Head &head,\
    \ const Tail &... tail) {\n    cerr << head << ' ';\n    dbg(tail...);\n}\n#else\n\
    template<typename... Args>\nvoid dbg(const Args &... args) {}\n#endif\n\ntemplate<typename\
    \ T>\nVector<Vector<T>> split(typename vector<T>::const_iterator begin, typename\
    \ vector<T>::const_iterator end, T val) {\n    Vector<Vector<T>> res;\n    Vector<T>\
    \ cur;\n    for(auto it = begin; it != end; it++) {\n        if(*it == val) {\n\
    \            res.push_back(cur);\n            cur.clear();\n        } else cur.push_back(*it);\n\
    \    }\n    res.push_back(cur);\n    return res;\n}\n\nVector<string> split(typename\
    \ string::const_iterator begin, typename string::const_iterator end, char val)\
    \ {\n    Vector<string> res;\n    string cur = \"\";\n    for(auto it = begin;\
    \ it != end; it++) {\n        if(*it == val) {\n            res.push_back(cur);\n\
    \            cur.clear();\n        } else cur.push_back(*it);\n    }\n    res.push_back(cur);\n\
    \    return res;\n}\n\ntemplate< typename T1, typename T2 >\ninline bool chmax(T1\
    \ &a, T2 b) { return a < b && (a = b, true); }\n\ntemplate< typename T1, typename\
    \ T2 >\ninline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }\n\n\
    template <typename T>\npair<VI, Vector<T>> compress(const vector<T> &a) {\n  \
    \  int n = a.size();\n    Vector<T> x;\n    REP(i, n) x.push_back(a[i]);\n   \
    \ sort(ALL(x)); x.erase(unique(ALL(x)), x.end());\n    VI res(n);\n    REP(i,\
    \ n) res[i] = lower_bound(ALL(x), a[i]) - x.begin();\n    return make_pair(res,\
    \ x);\n}\n\ntemplate <typename It>\nauto rle(It begin, It end) {\n    Vector<pair<typename\
    \ It::value_type, int>> res;\n    if(begin == end) return res;\n    auto pre =\
    \ *begin;\n    int num = 1;\n    for(auto it = begin + 1; it != end; it++) {\n\
    \        if(pre != *it) {\n            res.emplace_back(pre, num);\n         \
    \   pre = *it;\n            num = 1;\n        } else num++;\n    }\n    res.emplace_back(pre,\
    \ num);\n    return res;\n}\n\ntemplate <typename It>\nVector<pair<typename It::value_type,\
    \ int>> rle_sort(It begin, It end) {\n    Vector<typename It::value_type> cloned(begin,\
    \ end);\n    sort(ALL(cloned));\n    auto e = rle(ALL(cloned));\n    sort(ALL(e),\
    \ [](const auto& l, const auto& r) { return l.second < r.second; });\n    return\
    \ e;\n}\n\ntemplate <typename T>\nPair<Vector<T>, Vector<T>> factorial(int n)\
    \ {\n    Vector<T> res(n+1), rev(n+1);\n    res[0] = 1;\n    REP(i, n) res[i+1]\
    \ = res[i] * (i+1);\n    rev[n] = 1 / res[n];\n    for(int i = n; i > 0; i--)\
    \ {\n        rev[i-1] = rev[i] * i;\n    }\n    return make_pair(res, rev);\n\
    }\n#line 4 \"string.hpp\"\n\ntemplate <typename It>\nVector<int> kmp_table(It\
    \ begin, It end) {\n    int m = end - begin;\n    Vector<int> table(m);\n    int\
    \ j = 0;\n    FOR(i, 1, m) {\n        while(j > 0 && *(begin+i) != *(begin+j))\
    \ j = table[j-1];\n        if(*(begin+i) == *(begin+j)) table[i] = ++j;\n    }\n\
    \    return table;\n}\n\nVector<int> kmp_table(string& t) {\n    return kmp_table(ALL(t));\n\
    }\n\ntemplate <typename It>\nVector<int> kmp_find(It s_begin, It s_end, It t_begin,\
    \ It t_end, Vector<int>& table) {\n    int n = s_end - s_begin;\n    int m = t_end\
    \ - t_begin;\n    Vector<int> res;\n    int j = 0;\n    REP(i, n) {\n        while(j\
    \ > 0 && *(s_begin+i) != *(t_begin+j)) j = table[j-1];\n        if(*(s_begin+i)\
    \ == *(t_begin+j)) {\n            if(++j == m) {\n                res.push_back(i\
    \ - (m-1));\n                j = table[m-1];\n            }\n        }\n    }\n\
    \    return res;\n}\n\nVector<int> kmp_find(string& s, string& t, Vector<int>&\
    \ table) {\n    return kmp_find(ALL(s), ALL(t), table);\n}\n\ntemplate <typename\
    \ T=char, T begin_char='a', int char_sz=26>\nstruct Trie {\n    struct Node {\n\
    \        T c;\n        int sz = 0;\n        int depth;\n        Vector<Node*>\
    \ nxt;\n        Node* failure;\n        Vector<int> fullmatch_keyword_id;\n  \
    \      Vector<int> suffixmatch_keyword_id;\n\n        Node(T _c, int _d): c(_c),\
    \ depth(_d) {\n            nxt.resize(char_sz);\n            fill(ALL(nxt), nullptr);\n\
    \        }\n        ~Node() {\n            for(auto& p: nxt) if(p) delete p;\n\
    \        }\n    };\n\n    Node* root;\n    int keyword_id = 0;\n\n    Trie() {\n\
    \        root = new Node(begin_char-1, 0);\n    }\n    ~Trie() {\n        delete\
    \ root;\n    }\n\n    template <typename It>\n    void add(It begin, It end, int\
    \ keyword_id_=-1) {\n        if(keyword_id_ == -1) keyword_id_ = keyword_id++;\n\
    \        Node* cursor = root;\n        cursor->sz++;\n        for(It it = begin;\
    \ it != end; it++) {\n            if(!cursor->nxt[*it-begin_char]) cursor->nxt[*it-begin_char]\
    \ = new Node(*it, cursor->depth+1);\n            cursor = cursor->nxt[*it-begin_char];\n\
    \            cursor->sz++;\n        }\n        cursor->fullmatch_keyword_id.push_back(keyword_id_);\n\
    \    }\n\n    void add(const string& str, int keyword_id_=-1) {\n        add(ALL(str),\
    \ keyword_id_ == -1? keyword_id++ : keyword_id_);\n    }\n\n    void build_failure()\
    \ {\n        queue<Node*> que;\n        REP(i, char_sz) {\n            Node* to\
    \ = root->nxt[i];\n            if(!to) continue;\n            to->failure = root;\n\
    \            for(int x : to->fullmatch_keyword_id) {\n                to->suffixmatch_keyword_id.push_back(x);\n\
    \            }\n            que.push(to);\n        }\n        while(!que.empty())\
    \ {\n            Node* from = que.front(); que.pop();\n            REP(i, char_sz)\
    \ {\n                Node* to = from->nxt[i];\n                if(!to) continue;\n\
    \                Node* cursor = from->failure;\n                while(cursor !=\
    \ root && !cursor->nxt[i]) cursor = cursor->failure;\n                if(cursor->nxt[i])\
    \ to->failure = cursor->nxt[i];\n                else to->failure = root;\n  \
    \              for(int x : to->fullmatch_keyword_id) {\n                    to->suffixmatch_keyword_id.push_back(x);\n\
    \                }\n                for(int x : to->failure->suffixmatch_keyword_id)\
    \ {\n                    to->suffixmatch_keyword_id.push_back(x);\n          \
    \      }\n                que.push(to);\n            }\n        }\n    }\n\n \
    \   template <typename It>\n    void aho_corasick(It begin, It end, function<void(Vector<int>&)>&\
    \ f) {\n        Node* cursor = root;\n        for(It it = begin; it != end; it++)\
    \ {\n            while(cursor != root && !cursor->nxt[*it-begin_char]) cursor\
    \ = cursor->failure;\n            if(cursor->nxt[*it-begin_char]) {\n        \
    \        cursor = cursor->nxt[*it-begin_char];\n                f(cursor->suffixmatch_keyword_id);\n\
    \            }\n        }\n    }\n\n    template <typename It>\n    ll aho_corasick(It\
    \ begin, It end) {\n        ll res = 0;\n        function<void(Vector<int>&)>\
    \ f = [&](Vector<int>& v) {\n            res += v.size();\n        };\n      \
    \  aho_corasick(begin, end, f);\n        return res;\n    }\n\n    void aho_corasick(string\
    \ &s, function<void(Vector<int>&)>& f) {\n        aho_corasick(ALL(s), f);\n \
    \   }\n\n    ll aho_corasick(string &s) {\n        return aho_corasick(ALL(s));\n\
    \    }\n};\n\ntemplate <typename T>\nstruct RollingHash {\n    int num;\n    Vector<T>\
    \ base;\n    Vector<Vector<T>> power;\n\n    RollingHash(const vector<T>& base_)\
    \ : num(base_.size()), base(base_) {\n        power = Vector<Vector<T>>(num, Vector<T>(1,\
    \ 1));\n    }\n\n    RollingHash(int num_=3) : num(num_) {\n        assert(num_\
    \ > 0);\n        power = Vector<Vector<T>>(num, Vector<T>(1, 1));\n        mt19937\
    \ engine((random_device){}());\n        REP(i, num) base.push_back(engine());\n\
    \    }\n\n    void expand(int n) {\n        int m = power[0].size();\n       \
    \ if(m > n) return;\n        REP(i, num) {\n            power[i].resize(n+1);\n\
    \            FOR(j, m, n+1) power[i][j] = power[i][j-1] * base[i];\n        }\n\
    \    }\n\n    template<typename It>\n    Vector<Vector<T>> build(It begin, It\
    \ end) {\n        int n = end - begin;\n        Vector<Vector<T>> res(num, Vector<T>(n+1));\n\
    \        REP(i, num) REP(j, n) {\n            res[i][j+1] = res[i][j] * base[i]\
    \ + *(begin+j);\n        }\n        return res;\n    }\n\n    Vector<Vector<T>>\
    \ build(const string& s) {\n        return build(ALL(s));\n    }\n\n    Vector<T>\
    \ query(const Vector<Vector<T>>& hash, int l, int r) {\n        assert(hash.size()\
    \ == num);\n        assert(0 <= l && l <= r && r < hash[0].size());\n        expand(r\
    \ - l);\n        Vector<T> res(num);\n        REP(i, num) res[i] = hash[i][r]\
    \ - hash[i][l] * power[i][r-l];\n        return res;\n    }\n};\n"
  code: "#pragma once\n\n#include \"base.hpp\"\n\ntemplate <typename It>\nVector<int>\
    \ kmp_table(It begin, It end) {\n    int m = end - begin;\n    Vector<int> table(m);\n\
    \    int j = 0;\n    FOR(i, 1, m) {\n        while(j > 0 && *(begin+i) != *(begin+j))\
    \ j = table[j-1];\n        if(*(begin+i) == *(begin+j)) table[i] = ++j;\n    }\n\
    \    return table;\n}\n\nVector<int> kmp_table(string& t) {\n    return kmp_table(ALL(t));\n\
    }\n\ntemplate <typename It>\nVector<int> kmp_find(It s_begin, It s_end, It t_begin,\
    \ It t_end, Vector<int>& table) {\n    int n = s_end - s_begin;\n    int m = t_end\
    \ - t_begin;\n    Vector<int> res;\n    int j = 0;\n    REP(i, n) {\n        while(j\
    \ > 0 && *(s_begin+i) != *(t_begin+j)) j = table[j-1];\n        if(*(s_begin+i)\
    \ == *(t_begin+j)) {\n            if(++j == m) {\n                res.push_back(i\
    \ - (m-1));\n                j = table[m-1];\n            }\n        }\n    }\n\
    \    return res;\n}\n\nVector<int> kmp_find(string& s, string& t, Vector<int>&\
    \ table) {\n    return kmp_find(ALL(s), ALL(t), table);\n}\n\ntemplate <typename\
    \ T=char, T begin_char='a', int char_sz=26>\nstruct Trie {\n    struct Node {\n\
    \        T c;\n        int sz = 0;\n        int depth;\n        Vector<Node*>\
    \ nxt;\n        Node* failure;\n        Vector<int> fullmatch_keyword_id;\n  \
    \      Vector<int> suffixmatch_keyword_id;\n\n        Node(T _c, int _d): c(_c),\
    \ depth(_d) {\n            nxt.resize(char_sz);\n            fill(ALL(nxt), nullptr);\n\
    \        }\n        ~Node() {\n            for(auto& p: nxt) if(p) delete p;\n\
    \        }\n    };\n\n    Node* root;\n    int keyword_id = 0;\n\n    Trie() {\n\
    \        root = new Node(begin_char-1, 0);\n    }\n    ~Trie() {\n        delete\
    \ root;\n    }\n\n    template <typename It>\n    void add(It begin, It end, int\
    \ keyword_id_=-1) {\n        if(keyword_id_ == -1) keyword_id_ = keyword_id++;\n\
    \        Node* cursor = root;\n        cursor->sz++;\n        for(It it = begin;\
    \ it != end; it++) {\n            if(!cursor->nxt[*it-begin_char]) cursor->nxt[*it-begin_char]\
    \ = new Node(*it, cursor->depth+1);\n            cursor = cursor->nxt[*it-begin_char];\n\
    \            cursor->sz++;\n        }\n        cursor->fullmatch_keyword_id.push_back(keyword_id_);\n\
    \    }\n\n    void add(const string& str, int keyword_id_=-1) {\n        add(ALL(str),\
    \ keyword_id_ == -1? keyword_id++ : keyword_id_);\n    }\n\n    void build_failure()\
    \ {\n        queue<Node*> que;\n        REP(i, char_sz) {\n            Node* to\
    \ = root->nxt[i];\n            if(!to) continue;\n            to->failure = root;\n\
    \            for(int x : to->fullmatch_keyword_id) {\n                to->suffixmatch_keyword_id.push_back(x);\n\
    \            }\n            que.push(to);\n        }\n        while(!que.empty())\
    \ {\n            Node* from = que.front(); que.pop();\n            REP(i, char_sz)\
    \ {\n                Node* to = from->nxt[i];\n                if(!to) continue;\n\
    \                Node* cursor = from->failure;\n                while(cursor !=\
    \ root && !cursor->nxt[i]) cursor = cursor->failure;\n                if(cursor->nxt[i])\
    \ to->failure = cursor->nxt[i];\n                else to->failure = root;\n  \
    \              for(int x : to->fullmatch_keyword_id) {\n                    to->suffixmatch_keyword_id.push_back(x);\n\
    \                }\n                for(int x : to->failure->suffixmatch_keyword_id)\
    \ {\n                    to->suffixmatch_keyword_id.push_back(x);\n          \
    \      }\n                que.push(to);\n            }\n        }\n    }\n\n \
    \   template <typename It>\n    void aho_corasick(It begin, It end, function<void(Vector<int>&)>&\
    \ f) {\n        Node* cursor = root;\n        for(It it = begin; it != end; it++)\
    \ {\n            while(cursor != root && !cursor->nxt[*it-begin_char]) cursor\
    \ = cursor->failure;\n            if(cursor->nxt[*it-begin_char]) {\n        \
    \        cursor = cursor->nxt[*it-begin_char];\n                f(cursor->suffixmatch_keyword_id);\n\
    \            }\n        }\n    }\n\n    template <typename It>\n    ll aho_corasick(It\
    \ begin, It end) {\n        ll res = 0;\n        function<void(Vector<int>&)>\
    \ f = [&](Vector<int>& v) {\n            res += v.size();\n        };\n      \
    \  aho_corasick(begin, end, f);\n        return res;\n    }\n\n    void aho_corasick(string\
    \ &s, function<void(Vector<int>&)>& f) {\n        aho_corasick(ALL(s), f);\n \
    \   }\n\n    ll aho_corasick(string &s) {\n        return aho_corasick(ALL(s));\n\
    \    }\n};\n\ntemplate <typename T>\nstruct RollingHash {\n    int num;\n    Vector<T>\
    \ base;\n    Vector<Vector<T>> power;\n\n    RollingHash(const vector<T>& base_)\
    \ : num(base_.size()), base(base_) {\n        power = Vector<Vector<T>>(num, Vector<T>(1,\
    \ 1));\n    }\n\n    RollingHash(int num_=3) : num(num_) {\n        assert(num_\
    \ > 0);\n        power = Vector<Vector<T>>(num, Vector<T>(1, 1));\n        mt19937\
    \ engine((random_device){}());\n        REP(i, num) base.push_back(engine());\n\
    \    }\n\n    void expand(int n) {\n        int m = power[0].size();\n       \
    \ if(m > n) return;\n        REP(i, num) {\n            power[i].resize(n+1);\n\
    \            FOR(j, m, n+1) power[i][j] = power[i][j-1] * base[i];\n        }\n\
    \    }\n\n    template<typename It>\n    Vector<Vector<T>> build(It begin, It\
    \ end) {\n        int n = end - begin;\n        Vector<Vector<T>> res(num, Vector<T>(n+1));\n\
    \        REP(i, num) REP(j, n) {\n            res[i][j+1] = res[i][j] * base[i]\
    \ + *(begin+j);\n        }\n        return res;\n    }\n\n    Vector<Vector<T>>\
    \ build(const string& s) {\n        return build(ALL(s));\n    }\n\n    Vector<T>\
    \ query(const Vector<Vector<T>>& hash, int l, int r) {\n        assert(hash.size()\
    \ == num);\n        assert(0 <= l && l <= r && r < hash[0].size());\n        expand(r\
    \ - l);\n        Vector<T> res(num);\n        REP(i, num) res[i] = hash[i][r]\
    \ - hash[i][l] * power[i][r-l];\n        return res;\n    }\n};\n"
  dependsOn:
  - base.hpp
  - stl-wrapper/all.hpp
  - stl-wrapper/pair.hpp
  - stl-wrapper/vector.hpp
  - stl-wrapper/set.hpp
  - stl-wrapper/map.hpp
  - stl-wrapper/unordered_set.hpp
  - stl-wrapper/unordered_map.hpp
  isVerificationFile: false
  path: string.hpp
  requiredBy: []
  timestamp: '2022-11-03 00:55:39+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string.hpp
layout: document
redirect_from:
- /library/string.hpp
- /library/string.hpp.html
title: string.hpp
---
