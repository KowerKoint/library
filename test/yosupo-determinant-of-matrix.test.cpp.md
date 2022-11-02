---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: algebra/field.hpp
    title: algebra/field.hpp
  - icon: ':x:'
    path: algebra/modint.hpp
    title: algebra/modint.hpp
  - icon: ':question:'
    path: algebra/ordinal_operator.hpp
    title: algebra/ordinal_operator.hpp
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  - icon: ':question:'
    path: integer/extgcd.hpp
    title: integer/extgcd.hpp
  - icon: ':x:'
    path: integer/pow-mod.hpp
    title: integer/pow-mod.hpp
  - icon: ':x:'
    path: matrix/matrix.hpp
    title: matrix/matrix.hpp
  - icon: ':question:'
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
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/matrix_det
    links:
    - https://judge.yosupo.jp/problem/matrix_det
  bundledCode: "#line 1 \"test/yosupo-determinant-of-matrix.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/matrix_det\"\n#line 2 \"base.hpp\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#line 4 \"stl-wrapper/pair.hpp\"\n\n\
    template <typename T1, typename T2>\nstruct Pair : public std::pair<T1, T2> {\n\
    \    constexpr Pair() : std::pair<T1, T2>() {}\n    constexpr Pair(const T1& first,\
    \ const T2& second) : std::pair<T1, T2>(first, second) {}\n    template <typename\
    \ U1, typename U2>\n    constexpr Pair(U1&& first, U2&& second) : std::pair<T1,\
    \ T2>(std::forward<U1>(first), std::forward<U2>(second)) {}\n    template <typename\
    \ U1, typename U2>\n    constexpr Pair(const std::pair<U1, U2>& other) : std::pair<T1,\
    \ T2>(other) {}\n    template <typename U1, typename U2>\n    constexpr Pair(std::pair<U1,\
    \ U2>&& other) : std::pair<T1, T2>(std::move(other)) {}\n    template <typename...\
    \ Args1, typename... Args2>\n    Pair(std::piecewise_construct_t, std::tuple<Args1...>\
    \ first_args, std::tuple<Args2...> second_args) : std::pair<T1, T2>(std::piecewise_construct,\
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
    \ 4 \"matrix/matrix.hpp\"\n\ntemplate <\n    typename T,\n    T (*add)(const T,\
    \ const T)=add_op,\n    T (*zero)()=zero_e,\n    T (*mult)(const T, const T)=mult_op,\n\
    \    T (*one)()=one_e,\n    T (*sub)(const T, const T)=sub_op,\n    T (*div)(const\
    \ T, const T)=div_op\n>\nstruct Matrix {\n    int n, m;\n    Vector<Vector<T>>\
    \ A;\n\n    Matrix() : n(0), m(0), A(Vector<Vector<T>>(0)) {}\n    Matrix(size_t\
    \ _n, size_t _m) : n(_n), m(_m), A(_n, Vector<T>(_m, zero())) {}\n    Matrix(const\
    \ vector<vector<T>>& _A) : n(_A.size()), m(_A[0].size()), A(_A) {}\n\n    Vector<T>\
    \ &operator[](int i) {\n        assert(0 <= i && i < n);\n        return A.at(i);\n\
    \    }\n    const Vector<T> &operator[](int i) const {\n        assert(0 <= i\
    \ && i < n);\n        return A.at(i);\n    }\n\n    static Matrix I(size_t n)\
    \ {\n        assert(n >= 0);\n        Matrix ret(n, n);\n        REP(i, n) ret[i][i]\
    \ = one();\n        return ret;\n    }\n\n    Matrix &operator+=(const Matrix\
    \ &B) {\n        assert(n == B.n && m == B.m);\n        REP(i, n) REP(j, m) A[i][j]\
    \ = add(A[i][j], B[i][j]);\n        return *this;\n    }\n    Matrix operator+(const\
    \ Matrix &B) const {\n        assert(n == B.n && m == B.m);\n        return (Matrix(*this)\
    \ += B);\n    }\n\n    Matrix &operator-=(const Matrix &B) {\n        assert(n\
    \ == B.n && m == B.m);\n        REP(i, n) REP(j, m) A[i][j] = sub(A[i][j], B[i][j]);\n\
    \        return *this;\n    }\n    Matrix operator-(const Matrix &B) const {\n\
    \        assert(n == B.n && m == B.m);\n        return (Matrix(*this) -= B);\n\
    \    }\n\n    Matrix &operator*=(const Matrix &B) {\n        assert(m == B.n);\n\
    \        Vector<Vector<T>> res(n, Vector<T>(B.m, zero()));\n        REP(i, n)\
    \ REP(j, m) REP(k, B.m) res[i][k] = add(res[i][k], mult(A[i][j], B[j][k]));\n\
    \        A.swap(res);\n        m = B.m;\n        return (*this);\n    }\n    Matrix\
    \ operator*(const Matrix &B) const {\n        assert(m == B.n);\n        return\
    \ (Matrix(*this) *= B);\n    }\n\n    Matrix &operator|=(const Matrix &B) {\n\
    \        assert(B.n == n);\n        REP(i, n) {\n            A[i].resize(m+B.m);\n\
    \            REP(j, B.m) A[i][m+j] = B[i][j];\n        }\n        m += B.m;\n\
    \        return (*this);\n    }\n    Matrix operator|(const Matrix &B) const {\n\
    \        assert(B.n == n);\n        return (Matrix(*this) |= B);\n    }\n\n  \
    \  Matrix &operator|=(const vector<T> &B) {\n        assert(B.size() == n);\n\
    \        REP(i, n) {\n            A[i].push_back(B[i]);\n        }\n        m++;\n\
    \        return (*this);\n    }\n    Matrix operator|(const vector<T> &B) const\
    \ {\n        assert(B.size() == n);\n        return (Matrix(*this) |= B);\n  \
    \  }\n\n    Matrix &operator&=(const Matrix &B) {\n        assert(B.m == m);\n\
    \        A.resize(n+B.n);\n        REP(i, B.n) {\n            A[n+i] = B[i];\n\
    \        }\n        n += B.n;\n        return (*this);\n    }\n    Matrix operator&(const\
    \ Matrix &B) const {\n        assert(B.m == m);\n        return (Matrix(*this)\
    \ &= B);\n    }\n\n    Matrix &operator&=(const vector<T> &B) {\n        assert(B.size()\
    \ == m);\n        A.push_back(B);\n        n++;\n        return (*this);\n   \
    \ }\n    Matrix operator&(const vector<T> &B) const {\n        assert(B.size()\
    \ == m);\n        return (Matrix(*this) &= B);\n    }\n\n    friend istream &operator>>(istream\
    \ &is, Matrix &mat) {\n        REP(i, mat.n) REP(j, mat.m) is >> mat[i][j];\n\
    \        return is;\n    }\n\n    friend ostream &operator<<(ostream &os, const\
    \ Matrix &mat) {\n        REP(i, mat.n) {\n            REP(j, mat.m) os << mat[i][j]\
    \ << (j==mat.m-1? '\\n' : ' ');\n        }\n        return os;\n    }\n\n    Pair<Matrix,\
    \ T> gaussian_elimination() const {\n        Matrix mat(*this);\n        T det\
    \ = one();\n        VI columns;\n        int i = 0;\n        int j = 0;\n    \
    \    while(i < n && j < m) {\n            int idx = -1;\n            FOR(k, i,\
    \ n) if(mat[k][j] != zero()) idx = k;\n            if(idx == -1) {\n         \
    \       det = zero();\n                j++;\n                continue;\n     \
    \       }\n            if(i != idx) {\n                det *= sub(zero(), one());\n\
    \                swap(mat[i], mat[idx]);\n            }\n            det *= mat[i][j];\n\
    \            T scale = mat[i][j];\n            REP(l, m) mat[i][l] = div(mat[i][l],\
    \ scale);\n            FOR(k, i+1, n) {\n                T scale = mat[k][j];\n\
    \                REP(l, m) mat[k][l] = sub(mat[k][l], mult(mat[i][l], scale));\n\
    \            }\n            columns.push_back(j);\n            i++;\n        \
    \    j++;\n        }\n        REP(i, columns.size()) {\n            int j = columns[i];\n\
    \            REP(k, i) {\n                T scale = mat[k][j];\n             \
    \   FOR(l, j, m) {\n                    mat[k][l] = sub(mat[k][l], mult(mat[i][l],\
    \ scale));\n                }\n            }\n        }\n        return {mat,\
    \ det};\n    }\n\n    void make_basis() {\n        *this = gaussian_elimination().first;\n\
    \        while(n && get_bra(n-1) == Vector<T>(m, zero())) pop_bra();\n    }\n\n\
    \    Matrix inv() const {\n        Matrix and_i = (*this) | I(n);\n        auto\
    \ [i_and, det] = and_i.gaussian_elimination();\n        assert(det != zero());\n\
    \        Matrix res(n, n);\n        REP(i, n) REP(j, n) res[i][j] = i_and[i][n+j];\n\
    \        return res;\n    }\n\n    Vector<T> get_bra(int i) const {\n        assert(0\
    \ <= i && i < n);\n        return A[i];\n    }\n\n    Vector<T> get_ket(int i)\
    \ const {\n        assert(0 <= i && i < m);\n        Vector<T> res(n);\n     \
    \   REP(i, n) res[i] = A[i][i];\n        return res;\n    }\n\n    void pop_bra()\
    \ {\n        assert(n > 0);\n        A.pop_back();\n        n--;\n    }\n\n  \
    \  void pop_ket() {\n        assert(m > 0);\n        REP(i, n) A[i].pop_back();\n\
    \        m--;\n    }\n\n    Matrix transpose() const {\n        Matrix res(m,\
    \ n);\n        REP(i, n) REP(j, m) res[j][i] = A[i][j];\n        return res;\n\
    \    }\n\n    Matrix operator^=(ll k) {\n        if(k < 0) {\n            *this\
    \ = this->inv();\n            k = -k;\n        }\n        Matrix res = Matrix::I(n);\n\
    \        while(k) {\n            if(k & 1) res *= *this;\n            *this *=\
    \ *this;\n            k >>= 1LL;\n        }\n        A.swap(res.A);\n        return\
    \ (*this);\n    }\n    Matrix operator^(const ll k) const {\n        return (Matrix(*this)\
    \ ^= k);\n    }\n};\n\nusing XorMatrix = Matrix<\n    int,\n    xor_op<int>,\n\
    \    zero_e<int>,\n    and_op<int>,\n    one_e<int>,\n    xor_op<int>,\n    and_op<int>\n\
    >;\n#line 3 \"integer/extgcd.hpp\"\n\nll extgcd(ll a, ll b, ll& x, ll& y) {\n\
    \    x = 1, y = 0;\n    ll nx = 0, ny = 1;\n    while(b) {\n        ll q = a /\
    \ b;\n        tie(a, b) = LP(b, a % b);\n        tie(x, nx) = LP(nx, x - nx*q);\n\
    \        tie(y, ny) = LP(ny, y - ny*q);\n    }\n    return a;\n}\n#line 2 \"integer/pow-mod.hpp\"\
    \n\nll inv_mod(ll n, ll m) {\n    n %= m;\n    if (n < 0) n += m;\n    ll x, y;\n\
    \    assert(extgcd(n, m, x, y) == 1);\n    x %= m;\n    if(x < 0) x += m;\n  \
    \  return x;\n}\n\nll pow_mod(ll a, ll n, ll m) {\n    if(n == 0) return 1LL;\n\
    \    if(n < 0) return inv_mod(pow_mod(a, -n, m), m);\n    a %= m;\n    if (a <\
    \ 0) n += m;\n    ll res = 1;\n    while(n) {\n        if(n & 1) {\n         \
    \   res *= a;\n            res %= m;\n        }\n        n >>= 1;\n        a *=\
    \ a;\n        a %= m;\n    }\n    return res;\n}\n#line 2 \"algebra/ordinal_operator.hpp\"\
    \n\ntemplate <typename T>\nT ordinal_identity(const T& x) {\n    return x;\n}\n\
    template <typename T>\nT ordinal_plus(const T& a, const T& b) {\n    return a\
    \ + b;\n}\ntemplate <typename T>\nT ordinal_zero() {\n    return T(0);\n}\ntemplate\
    \ <typename T>\nT ordinal_mult(const T& a, const T& b) {\n    return a * b;\n\
    }\ntemplate <typename T>\nT ordinal_one() {\n    return T(1);\n}\ntemplate <typename\
    \ T>\nT ordinal_plusinv(const T& a) {\n    return -a;\n}\ntemplate <typename T>\n\
    T ordinal_multinv(const T& a) {\n    return T(1) / a;\n}\ntemplate <typename T>\n\
    T ordinal_xor(const T& a, const T& b) {\n    return a ^ b;\n}\ntemplate <typename\
    \ T>\nT ordinal_and(const T& a, const T& b) {\n    return a & b;\n}\ntemplate\
    \ <typename T>\nT ordinal_or(const T& a, const T& b) {\n    return a | b;\n}\n\
    #line 4 \"algebra/field.hpp\"\n\ntemplate <\n    typename T,\n    T (*mult)(const\
    \ T&, const T&),\n    T (*one)(),\n    T (*multinv)(const T&),\n    T (*plus)(const\
    \ T&, const T&),\n    T (*zero)(),\n    T (*plusinv)(const T&),\n    typename\
    \ R = T,\n    T (*rtot)(const R&) = ordinal_identity<R>,\n    R (*ttor)(const\
    \ T&) = ordinal_identity<T>\n>\nstruct Field {\n    T val;\n    Field() : val(zero())\
    \ {}\n    Field(const R& r) : val(rtot(r)) {}\n    operator R() const { return\
    \ ttor(val); }\n    Field& operator*=(const Field& other) {\n        val = mult(val,\
    \ other.val);\n        return *this;\n    }\n    Field operator*(const Field&\
    \ other) const {\n        return Field(*this) *= other;\n    }\n    Field inv()\
    \ const {\n        return Field(multinv(val));\n    }\n    Field& operator/= (const\
    \ Field& other) {\n        return *this *= other.inv();\n    }\n    Field operator/\
    \ (const Field& other) const {\n        return Field(*this) /= other;\n    }\n\
    \    Field& operator+=(const Field& other) {\n        val = plus(val, other.val);\n\
    \        return *this;\n    }\n    Field operator+(const Field& other) const {\n\
    \        return Field(*this) += other;\n    }\n    Field operator-() const {\n\
    \        return Field(plusinv(val));\n    }\n    Field& operator-=(const Field&\
    \ other) {\n        return *this += -other;\n    }\n    Field operator-(const\
    \ Field& other) const {\n        return Field(*this) -= other;\n    }\n    Field\
    \ pow(ll n) const {\n        if(n < 0) {\n            return inv().pow(-n);\n\
    \        }\n        Field res = one();\n        Field a = *this;\n        while(n\
    \ > 0) {\n            if(n & 1) res *= a;\n            a *= a;\n            n\
    \ >>= 1;\n        }\n        return res;\n    }\n    friend istream& operator>>(istream&\
    \ is, Field& f) {\n        R r; is >> r;\n        f = Field(r);\n        return\
    \ is;\n    }\n    friend ostream& operator<<(ostream& os, const Field& f) {\n\
    \        return os << (R)f.val;\n    }\n};\nnamespace std {\n    template <\n\
    \        typename T,\n        T (*mult)(const T, const T),\n        T (*one)(),\n\
    \        T (*multinv)(const T),\n        T (*plus)(const T, const T),\n      \
    \  T (*zero)(),\n        T (*plusinv)(const T),\n        typename R,\n       \
    \ T (*rtot)(const R),\n        R (*ttor)(const T)\n    >\n    struct hash<Field<T,\
    \ mult, one, multinv, plus, zero, plusinv, R, rtot, ttor>> {\n        size_t operator()(const\
    \ Field<T, mult, one, multinv, plus, zero, plusinv, R, rtot, ttor>& f) const {\n\
    \            return hash<T>()((R)f.val);\n        }\n    };\n}\n#line 5 \"algebra/modint.hpp\"\
    \n\ntemplate <ll (*mod)()>\nll mod_plus(const ll& a, const ll& b) {\n    ll res;\n\
    \    if(__builtin_add_overflow(a, b, &res)) {\n        return a % mod() + b %\
    \ mod();\n    }\n    return res;\n}\ntemplate <ll (*mod)()>\nll mod_mult(const\
    \ ll& a, const ll& b) {\n    ll res;\n    if(__builtin_mul_overflow(a, b, &res))\
    \ {\n        return (a % mod()) * (b % mod());\n    }\n    return res;\n}\ntemplate\
    \ <ll (*mod)()>\nll mod_inv(const ll& a) {\n    return inv_mod(a, mod());\n}\n\
    ll mod998244353() { return 998244353; }\nll mod1000000007() { return 1000000007;\
    \ }\ntemplate <ll (*mod)()>\nll make_representative(const ll& a) {\n    ll b =\
    \ a % mod();\n    if(b < 0) b += mod();\n    return b;\n}\n\ntemplate <ll (*mod)()>\n\
    using Modint = Field<ll, mod_mult<mod>, ordinal_one<ll>, mod_inv<mod>, mod_plus<mod>,\
    \ ordinal_zero<ll>, ordinal_plusinv<ll>, ll, ordinal_identity<ll>, make_representative<mod>>;\n\
    \nusing MI3 = Modint<mod998244353>;\nusing V3 = Vector<MI3>;\nusing VV3 = Vector<V3>;\n\
    using VVV3 = Vector<VV3>;\nusing MI7 = Modint<mod1000000007>;\nusing V7 = Vector<MI7>;\n\
    using VV7 = Vector<V7>;\nusing VVV7 = Vector<VV7>;\n#line 4 \"test/yosupo-determinant-of-matrix.test.cpp\"\
    \n\nint main() {\n    int n; cin >> n;\n    Matrix<MI3> a(n, n); cin >> a;\n \
    \   cout << a.gaussian_elimination().second << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_det\"\n#include\
    \ \"../matrix/matrix.hpp\"\n#include \"../algebra/modint.hpp\"\n\nint main() {\n\
    \    int n; cin >> n;\n    Matrix<MI3> a(n, n); cin >> a;\n    cout << a.gaussian_elimination().second\
    \ << endl;\n}\n"
  dependsOn:
  - matrix/matrix.hpp
  - base.hpp
  - stl-wrapper/all.hpp
  - stl-wrapper/pair.hpp
  - stl-wrapper/vector.hpp
  - stl-wrapper/set.hpp
  - stl-wrapper/map.hpp
  - stl-wrapper/unordered_set.hpp
  - stl-wrapper/unordered_map.hpp
  - operator.hpp
  - algebra/modint.hpp
  - integer/pow-mod.hpp
  - integer/extgcd.hpp
  - algebra/ordinal_operator.hpp
  - algebra/field.hpp
  isVerificationFile: true
  path: test/yosupo-determinant-of-matrix.test.cpp
  requiredBy: []
  timestamp: '2022-11-03 00:18:24+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo-determinant-of-matrix.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-determinant-of-matrix.test.cpp
- /verify/test/yosupo-determinant-of-matrix.test.cpp.html
title: test/yosupo-determinant-of-matrix.test.cpp
---
