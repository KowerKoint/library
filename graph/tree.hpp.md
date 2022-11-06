---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: connectivity/union-find.hpp
    title: connectivity/union-find.hpp
  - icon: ':heavy_check_mark:'
    path: graph/graph.hpp
    title: graph/graph.hpp
  - icon: ':heavy_check_mark:'
    path: stl-wrapper/all.hpp
    title: stl-wrapper/all.hpp
  - icon: ':heavy_check_mark:'
    path: stl-wrapper/map.hpp
    title: stl-wrapper/map.hpp
  - icon: ':heavy_check_mark:'
    path: stl-wrapper/pair.hpp
    title: stl-wrapper/pair.hpp
  - icon: ':heavy_check_mark:'
    path: stl-wrapper/set.hpp
    title: stl-wrapper/set.hpp
  - icon: ':heavy_check_mark:'
    path: stl-wrapper/unordered_map.hpp
    title: stl-wrapper/unordered_map.hpp
  - icon: ':heavy_check_mark:'
    path: stl-wrapper/unordered_set.hpp
    title: stl-wrapper/unordered_set.hpp
  - icon: ':heavy_check_mark:'
    path: stl-wrapper/vector.hpp
    title: stl-wrapper/vector.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo-lowest-common-ancestor.test.cpp
    title: test/yosupo-lowest-common-ancestor.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"base.hpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n#line 4 \"stl-wrapper/pair.hpp\"\n\ntemplate <typename T1, typename\
    \ T2>\nstruct Pair : public std::pair<T1, T2> {\n    constexpr Pair() : std::pair<T1,\
    \ T2>() {}\n    constexpr Pair(const T1& first, const T2& second) : std::pair<T1,\
    \ T2>(first, second) {}\n    template <typename U1, typename U2>\n    constexpr\
    \ Pair(U1&& first, U2&& second) : std::pair<T1, T2>(std::forward<U1>(first), std::forward<U2>(second))\
    \ {}\n    template <typename U1, typename U2>\n    constexpr Pair(const std::pair<U1,\
    \ U2>& other) : std::pair<T1, T2>(other) {}\n    template <typename U1, typename\
    \ U2>\n    constexpr Pair(std::pair<U1, U2>&& other) : std::pair<T1, T2>(std::move(other))\
    \ {}\n    template <typename... Args1, typename... Args2>\n    Pair(std::piecewise_construct_t,\
    \ std::tuple<Args1...> first_args, std::tuple<Args2...> second_args) : std::pair<T1,\
    \ T2>(std::piecewise_construct, first_args, second_args) {}\n    friend std::istream&\
    \ operator>>(std::istream& is, Pair& p) {\n        return is >> p.first >> p.second;\n\
    \    }\n    friend std::ostream& operator<<(std::ostream& os, const Pair& p) {\n\
    \        return os << p.first << ' ' << p.second;\n    }\n};\nnamespace std {\n\
    \    template <typename T1, typename T2>\n    struct hash<Pair<T1, T2>> {\n  \
    \      size_t operator()(const Pair<T1, T2>& p) const {\n            size_t seed\
    \ = 0;\n            seed ^= hash<T1>()(p.first) + 0x9e3779b9 + (seed << 6) + (seed\
    \ >> 2);\n            seed ^= hash<T2>()(p.second) + 0x9e3779b9 + (seed << 6)\
    \ + (seed >> 2);\n            return seed;\n        }\n    };\n}\n#line 5 \"stl-wrapper/vector.hpp\"\
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
    }\n#line 3 \"connectivity/union-find.hpp\"\n\ntemplate <typename Value=nullptr_t,\
    \ Value (*merge_value)(Value, Value)=nullptr, typename Potential=int>\nstruct\
    \ UnionFind {\n    int n;\n    VI par; // size if value is negative\n    Vector<Value>\
    \ val;\n    Vector<Potential> pot;\n    UnionFind(int n=0) : n(n), par(n, -1),\
    \ val(n), pot(n) {\n        assert(n >= 0);\n    }\n    int root(int x) {\n  \
    \      assert(0 <= x && x < n);\n        if(par[x] < 0) return x;\n        int\
    \ rt = root(par[x]);\n        pot[x] += pot[par[x]];\n        return par[x] =\
    \ rt;\n    }\n    Value get_value(int x) {\n        assert(0 <= x && x < n);\n\
    \        return val[root(x)];\n    }\n    void set_value(int x, Value v) {\n \
    \       assert(0 <= x && x < n);\n        val[root(x)] = v;\n    }\n    Potential\
    \ potential(int x) {\n        assert(0 <= x && x < n);\n        root(x);\n   \
    \     return pot[x];\n    }\n    Potential diff(int x, int y) {\n        assert(0\
    \ <= x && x < n);\n        assert(0 <= y && y < n);\n        return potential(y)\
    \ - potential(x);\n    }\n    int size(int x) {\n        assert(0 <= x && x <\
    \ n);\n        return -par[root(x)];\n    }\n    bool merge(int x, int y, Potential\
    \ p=0) {\n        assert(0 <= x && x < n);\n        assert(0 <= y && y < n);\n\
    \        p += potential(x);\n        p -= potential(y);\n        x = root(x),\
    \ y = root(y);\n        if(x == y) return false;\n        if(par[x] > par[y])\
    \ {\n            swap(x, y);\n            p = -p;\n        }\n        par[x] +=\
    \ par[y];\n        par[y] = x;\n        if(merge_value != nullptr) val[x] = merge_value(val[x],\
    \ val[y]);\n        pot[y] = p;\n        return true;\n    }\n    bool same(int\
    \ x, int y) {\n        assert(0 <= x && x < n);\n        assert(0 <= y && y <\
    \ n);\n        return root(x) == root(y);\n    }\n    VVI groups() {\n       \
    \ VVI res(n);\n        REP(i, n) {\n            res[root(i)].push_back(i);\n \
    \       }\n        sort(ALL(res), [](VI& a, VI& b) {\n            return a.size()\
    \ > b.size();\n        });\n        while(!res.empty() && res.back().empty())\
    \ res.pop_back();\n        return res;\n    }\n};\n\ntemplate <typename Potential>\n\
    using WeightedUnionFind = UnionFind<nullptr_t, nullptr, Potential>;\n#line 4 \"\
    graph/graph.hpp\"\n\ntemplate <typename T=int>\nstruct Edge {\n    int from, to;\n\
    \    T cost;\n    int id;\n    Edge() = default;\n    Edge(int from, int to, T\
    \ cost=1, int id=-1) : from(from), to(to), cost(cost), id(id) {}\n    operator\
    \ int() const { return to; }\n};\n\ntemplate <typename T=int>\nstruct Graph {\n\
    \    int n;\n    int m;\n    Vector<Vector<Edge<T>>> g;\n    Graph(int n_=0) :\
    \ n(n_), m(0), g(n_) {\n        assert(n_ >= 0);\n    }\n    void add_edge(int\
    \ u, int v, T w=1) {\n        assert(0 <= u && u < n);\n        assert(0 <= v\
    \ && v < n);\n        g[u].push_back({u, v, w, m});\n        g[v].push_back({v,\
    \ u, w, m++});\n    }\n    void add_directed_edge(int u, int v, T w=1) {\n   \
    \     assert(0 <= u && u < n);\n        assert(0 <= v && v < n);\n        g[u].push_back({u,\
    \ v, w, m++});\n    }\n    void read(int m_, int padding=-1, bool weighted=false,\
    \ bool directed=false) {\n        assert(m_ >= 0);\n        REP(i, m_) {\n   \
    \         int u, v; cin >> u >> v; u += padding, v += padding;\n            T\
    \ c(1);\n            if(weighted) cin >> c;\n            if(directed) add_directed_edge(u,\
    \ v, c);\n            else add_edge(u, v, c);\n        }\n    }\n    Vector<Edge<T>>&\
    \ operator[](int u) {\n        assert(0 <= u && u < n);\n        return g[u];\n\
    \    }\n    const Vector<Edge<T>>& operator[](int u) const {\n        assert(0\
    \ <= u && u < n);\n        return g[u];\n    }\n    Pair<Vector<T>, Vector<Edge<T>>>\
    \ dijkstra(int st) const {\n        assert(0 <= st && st < n);\n        T inf\
    \ = numeric_limits<T>::max();\n        Vector<T> dist(n, inf);\n        Vector<Edge<T>>\
    \ pre(n);\n        GPQ<Pair<T, int>> pq;\n        dist[st] = 0;\n        pq.emplace(0,\
    \ st);\n        while(!pq.empty()) {\n            auto [d, from] = pq.top(); pq.pop();\n\
    \            if(dist[from] < d) continue;\n            for(auto& e : g[from])\
    \ {\n                if(chmin(dist[e.to], d + e.cost)) {\n                   \
    \ pre[e.to] = e;\n                    pq.emplace(dist[e.to], e.to);\n        \
    \        }\n            }\n        }\n        return {dist, pre};\n    }\n   \
    \ Pair<Vector<T>, Vector<Edge<T>>> bfs(int st) const {\n        assert(0 <= st\
    \ && st < n);\n        T inf = numeric_limits<T>::max();\n        Vector<T> dist(n,\
    \ inf);\n        Vector<Edge<T>> pre(n);\n        queue<int> que;\n        dist[st]\
    \ = 0;\n        que.emplace(st);\n        while(!que.empty()) {\n            int\
    \ from = que.front(); que.pop();\n            for(auto& e : g[from]) {\n     \
    \           if(chmin(dist[e.to], dist[e.from] + 1)) {\n                    pre[e.to]\
    \ = e;\n                    que.emplace(e.to);\n                }\n          \
    \  }\n        }\n        return {dist, pre};\n    }\n    Vector<Edge<T>> edges()\
    \ const {\n        Vector<Edge<T>> res;\n        REP(i, n) for(auto& e : g[i])\
    \ res.emplace_back(e);\n        sort(res.begin(), res.end(), [](const Edge<T>&\
    \ a, const Edge<T>& b) {\n            return a.id < b.id;\n        });\n     \
    \   res.erase(unique(ALL(res), [](const Edge<T>& a, const Edge<T>& b) {\n    \
    \        return a.id == b.id;\n        }), res.end());\n        return res;\n\
    \    }\n    Vector<Edge<T>> kruskal() const {\n        Vector<Edge<T>> res;\n\
    \        Vector<Edge<T>> es = edges();\n        UnionFind uf(n);\n        sort(ALL(es),\
    \ [](const Edge<T>& a, const Edge<T>& b) {\n            return a.cost < b.cost;\n\
    \        });\n        for(auto& e : edges()) {\n            if(uf.merge(e.from,\
    \ e.to)) res.emplace_back(e);\n        }\n        return res;\n    }\n};\n#line\
    \ 3 \"graph/tree.hpp\"\n\ntemplate <typename T=int>\nstruct Tree : Graph<T> {\n\
    \    int root = -1;\n    Vector<Edge<T>> par;\n    Vector<Vector<Edge<T>>> child;\n\
    \    Vector<T> depth;\n    Vector<int> sz;\n    Vector<int> preorder, postorder,\
    \ eulertour;\n    Vector<Vector<int>> doubling_par;\n    Tree(int n_=0) : Graph<T>(n_)\
    \ {}\n    Tree(const Graph<T>& g) : Graph<T>(g) {}\n    Tree(const vector<int>&\
    \ par_, int padding = -1) : Graph<T>(par_.size()+1) {\n        REP(i, par_.size())\
    \ {\n            this->add_edge(i+1, par_[i] + padding);\n        }\n    }\n \
    \   void read(int padding=-1, bool weighted=false) {\n        Graph<T>::read(this->n-1,\
    \ padding, weighted, false);\n    }\n    void build(int root_) {\n        assert(0\
    \ <= root_ && root_ < this->n);\n        root = root_;\n        int n = this->n;\n\
    \        par = Vector<Edge<T>>(n);\n        child = Vector<Vector<Edge<T>>>(n);\n\
    \        depth = Vector<T>(n);\n        sz = Vector<int>(n);\n        stack<int>\
    \ stk;\n        stk.push(~root);\n        stk.push(root);\n        par[root] =\
    \ {root, -1, 0, -1};\n        depth[root] = 0;\n        while(!stk.empty()) {\n\
    \            int from = stk.top(); stk.pop();\n            if(from >= 0) {\n \
    \               preorder.push_back(from);\n                eulertour.push_back(from);\n\
    \                for(auto& e : this->g[from]) {\n                    if(e.to ==\
    \ par[from]) continue;\n                    par[e.to] = {e.to, from, e.cost, e.id};\n\
    \                    child[from].push_back(e);\n                    depth[e.to]\
    \ = depth[from] + e.cost;\n                    stk.push(~e.to);\n            \
    \        stk.push(e.to);\n                }\n            } else {\n          \
    \      from = ~from;\n                postorder.push_back(from);\n           \
    \     eulertour.push_back(~from);\n                sz[from] = 1;\n           \
    \     for(auto& e : child[from]) {\n                    sz[from] += sz[e.to];\n\
    \                }\n            }\n        }\n    }\n    void lca_build() {\n\
    \        int n = this->n;\n        int height = 0;\n        while(1 << height\
    \ < n) height++;\n        doubling_par.assign(height, VI(n, -1));\n        REP(i,\
    \ n) doubling_par[0][i] = par[i];\n        REP(i, height-1) {\n            REP(j,\
    \ n) {\n                if(doubling_par[i][j] != -1) {\n                    doubling_par[i+1][j]\
    \ = doubling_par[i][doubling_par[i][j]];\n                }\n            }\n \
    \       }\n    }\n    int climb(int i, int k) {\n        assert(0 <= i && i <\
    \ this->n);\n        int height = doubling_par.size();\n        REP(j, height)\
    \ {\n            if(k >> j & 1) {\n                i = doubling_par[j][i];\n \
    \           }\n            if(i == -1) return -1;\n        }\n        return i;\n\
    \    }\n    int lca(int i, int j) {\n        assert(0 <= i && i < this->n);\n\
    \        assert(0 <= j && j < this->n);\n        if(depth[i] < depth[j]) j = climb(j,\
    \ depth[j] - depth[i]);\n        if(depth[i] > depth[j]) i = climb(i, depth[i]\
    \ - depth[j]);\n        if(i == j) return i;\n        int height = doubling_par.size();\n\
    \        for(int k = height-1; k >= 0; k--) {\n            if(depth[i] < 1 <<\
    \ k) continue;\n            if(doubling_par[k][i] != doubling_par[k][j]) {\n \
    \               i = doubling_par[k][i];\n                j = doubling_par[k][j];\n\
    \            }\n        }\n        return par[i];\n    }\n    int dist(int i,\
    \ int j) {\n        assert(0 <= i && i < this->n);\n        assert(0 <= j && j\
    \ < this->n);\n        return depth[i] + depth[j] - depth[lca(i, j)] * 2;\n  \
    \  }\n};\n"
  code: "#pragma once\n#include \"graph.hpp\"\n\ntemplate <typename T=int>\nstruct\
    \ Tree : Graph<T> {\n    int root = -1;\n    Vector<Edge<T>> par;\n    Vector<Vector<Edge<T>>>\
    \ child;\n    Vector<T> depth;\n    Vector<int> sz;\n    Vector<int> preorder,\
    \ postorder, eulertour;\n    Vector<Vector<int>> doubling_par;\n    Tree(int n_=0)\
    \ : Graph<T>(n_) {}\n    Tree(const Graph<T>& g) : Graph<T>(g) {}\n    Tree(const\
    \ vector<int>& par_, int padding = -1) : Graph<T>(par_.size()+1) {\n        REP(i,\
    \ par_.size()) {\n            this->add_edge(i+1, par_[i] + padding);\n      \
    \  }\n    }\n    void read(int padding=-1, bool weighted=false) {\n        Graph<T>::read(this->n-1,\
    \ padding, weighted, false);\n    }\n    void build(int root_) {\n        assert(0\
    \ <= root_ && root_ < this->n);\n        root = root_;\n        int n = this->n;\n\
    \        par = Vector<Edge<T>>(n);\n        child = Vector<Vector<Edge<T>>>(n);\n\
    \        depth = Vector<T>(n);\n        sz = Vector<int>(n);\n        stack<int>\
    \ stk;\n        stk.push(~root);\n        stk.push(root);\n        par[root] =\
    \ {root, -1, 0, -1};\n        depth[root] = 0;\n        while(!stk.empty()) {\n\
    \            int from = stk.top(); stk.pop();\n            if(from >= 0) {\n \
    \               preorder.push_back(from);\n                eulertour.push_back(from);\n\
    \                for(auto& e : this->g[from]) {\n                    if(e.to ==\
    \ par[from]) continue;\n                    par[e.to] = {e.to, from, e.cost, e.id};\n\
    \                    child[from].push_back(e);\n                    depth[e.to]\
    \ = depth[from] + e.cost;\n                    stk.push(~e.to);\n            \
    \        stk.push(e.to);\n                }\n            } else {\n          \
    \      from = ~from;\n                postorder.push_back(from);\n           \
    \     eulertour.push_back(~from);\n                sz[from] = 1;\n           \
    \     for(auto& e : child[from]) {\n                    sz[from] += sz[e.to];\n\
    \                }\n            }\n        }\n    }\n    void lca_build() {\n\
    \        int n = this->n;\n        int height = 0;\n        while(1 << height\
    \ < n) height++;\n        doubling_par.assign(height, VI(n, -1));\n        REP(i,\
    \ n) doubling_par[0][i] = par[i];\n        REP(i, height-1) {\n            REP(j,\
    \ n) {\n                if(doubling_par[i][j] != -1) {\n                    doubling_par[i+1][j]\
    \ = doubling_par[i][doubling_par[i][j]];\n                }\n            }\n \
    \       }\n    }\n    int climb(int i, int k) {\n        assert(0 <= i && i <\
    \ this->n);\n        int height = doubling_par.size();\n        REP(j, height)\
    \ {\n            if(k >> j & 1) {\n                i = doubling_par[j][i];\n \
    \           }\n            if(i == -1) return -1;\n        }\n        return i;\n\
    \    }\n    int lca(int i, int j) {\n        assert(0 <= i && i < this->n);\n\
    \        assert(0 <= j && j < this->n);\n        if(depth[i] < depth[j]) j = climb(j,\
    \ depth[j] - depth[i]);\n        if(depth[i] > depth[j]) i = climb(i, depth[i]\
    \ - depth[j]);\n        if(i == j) return i;\n        int height = doubling_par.size();\n\
    \        for(int k = height-1; k >= 0; k--) {\n            if(depth[i] < 1 <<\
    \ k) continue;\n            if(doubling_par[k][i] != doubling_par[k][j]) {\n \
    \               i = doubling_par[k][i];\n                j = doubling_par[k][j];\n\
    \            }\n        }\n        return par[i];\n    }\n    int dist(int i,\
    \ int j) {\n        assert(0 <= i && i < this->n);\n        assert(0 <= j && j\
    \ < this->n);\n        return depth[i] + depth[j] - depth[lca(i, j)] * 2;\n  \
    \  }\n};\n"
  dependsOn:
  - graph/graph.hpp
  - base.hpp
  - stl-wrapper/all.hpp
  - stl-wrapper/pair.hpp
  - stl-wrapper/vector.hpp
  - stl-wrapper/set.hpp
  - stl-wrapper/map.hpp
  - stl-wrapper/unordered_set.hpp
  - stl-wrapper/unordered_map.hpp
  - connectivity/union-find.hpp
  isVerificationFile: false
  path: graph/tree.hpp
  requiredBy: []
  timestamp: '2022-11-06 15:35:57+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo-lowest-common-ancestor.test.cpp
documentation_of: graph/tree.hpp
layout: document
redirect_from:
- /library/graph/tree.hpp
- /library/graph/tree.hpp.html
title: graph/tree.hpp
---
