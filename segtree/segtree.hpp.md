---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: operator.hpp
    title: operator.hpp
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
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj-dsl-2-a.test.cpp
    title: test/aoj-dsl-2-a.test.cpp
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
    }\n#line 3 \"operator.hpp\"\n\ntemplate <typename T>\nT add_op(T a, T b) { return\
    \ a + b; }\ntemplate <typename T>\nT sub_op(T a, T b) { return a - b; }\ntemplate\
    \ <typename T>\nT zero_e() { return T(0); }\ntemplate <typename T>\nT div_op(T\
    \ a, T b) { return a / b; }\ntemplate <typename T>\nT mult_op(T a, T b) { return\
    \ a * b; }\ntemplate <typename T>\nT one_e() { return T(1); }\ntemplate <typename\
    \ T>\nT xor_op(T a, T b) { return a ^ b; }\ntemplate <typename T>\nT and_op(T\
    \ a, T b) { return a & b; }\ntemplate <typename T>\nT or_op(T a, T b) { return\
    \ a | b; }\nll mod3() { return 998244353LL; }\nll mod7() { return 1000000007LL;\
    \ }\nll mod9() { return 1000000009LL; }\ntemplate <typename T>\nT max_op(T a,\
    \ T b) { return max(a, b); }\ntemplate <typename T>\nT min_op(T a, T b) { return\
    \ min(a, b); }\n\ntemplate <typename T>\nT max_e() { return numeric_limits<T>::max();\
    \ }\ntemplate <typename T>\nT min_e() { return numeric_limits<T>::min(); }\n#line\
    \ 3 \"segtree/segtree.hpp\"\n\ntemplate <typename S, S (*op)(const S, const S),\
    \ S (*e)()>\nstruct SegTree {\nprotected:\n    int n, sz, height;\n    Vector<S>\
    \ state;\n    void update(int k) {\n        assert(0 <= k && k < sz);\n      \
    \  state[k] = op(state[k*2], state[k*2+1]);\n    }\npublic:\n    SegTree(int n_\
    \ = 0): n(n_) {\n        assert(n_ >= 0);\n        sz = 1;\n        height = 0;\n\
    \        while(sz < n) {\n            height++;\n            sz <<= 1;\n     \
    \   }\n        state.assign(sz*2, e());\n    }\n    SegTree(const vector<S>& v):\
    \ n(v.size()) {\n        sz = 1;\n        height = 0;\n        while(sz < n) {\n\
    \            height++;\n            sz <<= 1;\n        }\n        state.assign(sz*2,\
    \ e());\n        REP(i, v.size()) state[sz+i] = v[i];\n        for(int i = sz-1;\
    \ i > 0; i--) update(i);\n    }\n    S get(int i) const {\n        assert(0 <=\
    \ i && i < n);\n        return state[sz+i];\n    }\n    S operator[](int i) const\
    \ {\n        assert(0 <= i && i < n);\n        return get(i);\n    }\n    void\
    \ set(int i, const S &x) {\n        assert(0 <= i && i < n);\n        i += sz;\n\
    \        state[i] = x;\n        while(i >>= 1) update(i);\n    }\n    void ch_op(int\
    \ i, const S &x) {\n        set(i, op(get(i), x));\n    }\n    S prod(int l, int\
    \ r) const {\n        assert(0 <= l && l <= r && r <= n);\n        S left_prod\
    \ = e(), right_prod = e();\n        l += sz, r += sz;\n        while(l < r) {\n\
    \            if(l & 1) left_prod = op(left_prod, state[l++]);\n            if(r\
    \ & 1) right_prod = op(state[--r], right_prod);\n            l >>= 1;\n      \
    \      r >>= 1;\n        }\n        return op(left_prod, right_prod);\n    }\n\
    \    S all_prod() const {\n        return state[1];\n    }\n    template <typename\
    \ F>\n    int max_right(int l, F f) const {\n        assert(0 <= l && l <= n);\n\
    \        assert(f(e()));\n        if(l == n) return n;\n        l += sz;\n   \
    \     while(l % 2 == 0) l >>= 1;\n        S sum = e();\n        while(f(op(sum,\
    \ state[l]))) {\n            if(__builtin_clz(l) != __builtin_clz(l+1)) return\
    \ n;\n            sum = op(sum, state[l]);\n            l++;\n            while(l\
    \ % 2 == 0) l >>= 1;\n        }\n        while(l < sz) {\n            if(!f(op(sum,\
    \ state[l*2]))) l *= 2;\n            else {\n                sum = op(sum, state[l*2]);\n\
    \                l = l*2 + 1;\n            }\n        }\n        return l - sz;\n\
    \    }\n    template <typename F>\n    int min_left(int r, F f) const {\n    \
    \    assert(0 <= r && r <= n);\n        assert(f(e()));\n        if(r == 0) return\
    \ 0;\n        r += sz-1;\n        while(r % 2 == 1) r >>= 1;\n        S sum =\
    \ e();\n        while(f(op(state[r], sum))) {\n            if(__builtin_clz(r)\
    \ != __builtin_clz(r-1)) return 0;\n            sum = op(state[r], sum);\n   \
    \         r--;\n            while(r % 2 == 1) r >>= 1;\n        }\n        while(r\
    \ < sz) {\n            if(!f(op(state[r*2+1], sum))) r = r*2 + 1;\n          \
    \  else {\n                sum = op(state[r*2+1], sum);\n                r = r*2;\n\
    \            }\n        }\n        return r - sz + 1;\n    }\n};\n\ntemplate <typename\
    \ S>\nusing RMaxQ = SegTree<S, max_op<S>, min_e<S>>;\ntemplate <typename S>\n\
    using RMinQ = SegTree<S, min_op<S>, max_e<S>>;\ntemplate <typename S>\nusing RSumQ\
    \ = SegTree<S, add_op<S>, zero_e<S>>;\n"
  code: "#pragma once\n#include \"../operator.hpp\"\n\ntemplate <typename S, S (*op)(const\
    \ S, const S), S (*e)()>\nstruct SegTree {\nprotected:\n    int n, sz, height;\n\
    \    Vector<S> state;\n    void update(int k) {\n        assert(0 <= k && k <\
    \ sz);\n        state[k] = op(state[k*2], state[k*2+1]);\n    }\npublic:\n   \
    \ SegTree(int n_ = 0): n(n_) {\n        assert(n_ >= 0);\n        sz = 1;\n  \
    \      height = 0;\n        while(sz < n) {\n            height++;\n         \
    \   sz <<= 1;\n        }\n        state.assign(sz*2, e());\n    }\n    SegTree(const\
    \ vector<S>& v): n(v.size()) {\n        sz = 1;\n        height = 0;\n       \
    \ while(sz < n) {\n            height++;\n            sz <<= 1;\n        }\n \
    \       state.assign(sz*2, e());\n        REP(i, v.size()) state[sz+i] = v[i];\n\
    \        for(int i = sz-1; i > 0; i--) update(i);\n    }\n    S get(int i) const\
    \ {\n        assert(0 <= i && i < n);\n        return state[sz+i];\n    }\n  \
    \  S operator[](int i) const {\n        assert(0 <= i && i < n);\n        return\
    \ get(i);\n    }\n    void set(int i, const S &x) {\n        assert(0 <= i &&\
    \ i < n);\n        i += sz;\n        state[i] = x;\n        while(i >>= 1) update(i);\n\
    \    }\n    void ch_op(int i, const S &x) {\n        set(i, op(get(i), x));\n\
    \    }\n    S prod(int l, int r) const {\n        assert(0 <= l && l <= r && r\
    \ <= n);\n        S left_prod = e(), right_prod = e();\n        l += sz, r +=\
    \ sz;\n        while(l < r) {\n            if(l & 1) left_prod = op(left_prod,\
    \ state[l++]);\n            if(r & 1) right_prod = op(state[--r], right_prod);\n\
    \            l >>= 1;\n            r >>= 1;\n        }\n        return op(left_prod,\
    \ right_prod);\n    }\n    S all_prod() const {\n        return state[1];\n  \
    \  }\n    template <typename F>\n    int max_right(int l, F f) const {\n     \
    \   assert(0 <= l && l <= n);\n        assert(f(e()));\n        if(l == n) return\
    \ n;\n        l += sz;\n        while(l % 2 == 0) l >>= 1;\n        S sum = e();\n\
    \        while(f(op(sum, state[l]))) {\n            if(__builtin_clz(l) != __builtin_clz(l+1))\
    \ return n;\n            sum = op(sum, state[l]);\n            l++;\n        \
    \    while(l % 2 == 0) l >>= 1;\n        }\n        while(l < sz) {\n        \
    \    if(!f(op(sum, state[l*2]))) l *= 2;\n            else {\n               \
    \ sum = op(sum, state[l*2]);\n                l = l*2 + 1;\n            }\n  \
    \      }\n        return l - sz;\n    }\n    template <typename F>\n    int min_left(int\
    \ r, F f) const {\n        assert(0 <= r && r <= n);\n        assert(f(e()));\n\
    \        if(r == 0) return 0;\n        r += sz-1;\n        while(r % 2 == 1) r\
    \ >>= 1;\n        S sum = e();\n        while(f(op(state[r], sum))) {\n      \
    \      if(__builtin_clz(r) != __builtin_clz(r-1)) return 0;\n            sum =\
    \ op(state[r], sum);\n            r--;\n            while(r % 2 == 1) r >>= 1;\n\
    \        }\n        while(r < sz) {\n            if(!f(op(state[r*2+1], sum)))\
    \ r = r*2 + 1;\n            else {\n                sum = op(state[r*2+1], sum);\n\
    \                r = r*2;\n            }\n        }\n        return r - sz + 1;\n\
    \    }\n};\n\ntemplate <typename S>\nusing RMaxQ = SegTree<S, max_op<S>, min_e<S>>;\n\
    template <typename S>\nusing RMinQ = SegTree<S, min_op<S>, max_e<S>>;\ntemplate\
    \ <typename S>\nusing RSumQ = SegTree<S, add_op<S>, zero_e<S>>;\n"
  dependsOn:
  - operator.hpp
  - base.hpp
  - stl-wrapper/all.hpp
  - stl-wrapper/pair.hpp
  - stl-wrapper/vector.hpp
  - stl-wrapper/set.hpp
  - stl-wrapper/map.hpp
  - stl-wrapper/unordered_set.hpp
  - stl-wrapper/unordered_map.hpp
  isVerificationFile: false
  path: segtree/segtree.hpp
  requiredBy: []
  timestamp: '2022-11-06 10:00:21+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj-dsl-2-a.test.cpp
documentation_of: segtree/segtree.hpp
layout: document
redirect_from:
- /library/segtree/segtree.hpp
- /library/segtree/segtree.hpp.html
title: segtree/segtree.hpp
---
