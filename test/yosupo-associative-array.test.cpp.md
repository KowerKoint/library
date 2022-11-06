---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: stl-wrapper/map.hpp
    title: stl-wrapper/map.hpp
  - icon: ':heavy_check_mark:'
    path: stl-wrapper/vector.hpp
    title: stl-wrapper/vector.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/associative_array
    links:
    - https://judge.yosupo.jp/problem/associative_array
  bundledCode: "#line 1 \"test/yosupo-associative-array.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/associative_array\"\n\n#include <bits/stdc++.h>\n\
    #line 4 \"stl-wrapper/map.hpp\"\n#include <ext/pb_ds/assoc_container.hpp>\n#include\
    \ <ext/pb_ds/tree_policy.hpp>\n#line 5 \"stl-wrapper/vector.hpp\"\n\ntemplate\
    \ <typename T>\nstruct Vector : std::vector<T> {\n    Vector() noexcept : std::vector<T>()\
    \ {}\n    explicit Vector(size_t count) : std::vector<T>(count, T()) {}\n    Vector(size_t\
    \ count, const T& value) : std::vector<T>(count, value) {}\n    template <typename\
    \ InputIt>\n    Vector(InputIt first, InputIt last) : std::vector<T>(first, last)\
    \ {}\n    Vector(const std::vector<T>& other) : std::vector<T>(other) {}\n   \
    \ Vector(std::vector<T>&& other) noexcept : std::vector<T>(std::move(other)) {}\n\
    \    Vector(std::initializer_list<T> init) : std::vector<T>(init) {}\n    const\
    \ T& operator[](size_t i) const {\n        assert(i < this->size());\n       \
    \ return std::vector<T>::operator[](i);\n    }\n    T& operator[](size_t i) {\n\
    \        assert(i < this->size());\n        return std::vector<T>::operator[](i);\n\
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
    \ return seed;\n        }\n    };\n};\n#line 7 \"stl-wrapper/map.hpp\"\n\ntemplate\
    \ <typename Key, typename Value, typename Compare>\nusing pbds_map = __gnu_pbds::tree<Key,\
    \ Value, Compare, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;\n\
    \ntemplate <typename Key, typename Value, typename Compare = std::less<Key>>\n\
    struct Map : pbds_map<Key, Value, Compare> {\n    Map() : pbds_map<Key, Value,\
    \ Compare>() {}\n    explicit Map(const Compare& comp) : pbds_map<Key, Value,\
    \ Compare>(comp) {}\n    template <typename It>\n    Map(It first, It last, const\
    \ Compare& comp = Compare()) : pbds_map<Key, Value, Compare>(first, last, comp)\
    \ {}\n    Map(const pbds_map<Key, Value, Compare>& other) : pbds_map<Key, Value,\
    \ Compare>(other) {}\n    Map(const std::map<Key, Value, Compare>& other) : pbds_map<Key,\
    \ Value, Compare>(other.begin(), other.end()) {}\n    Map(pbds_map<Key, Value,\
    \ Compare>&& other) : pbds_map<Key, Value, Compare>(std::move(other)) {}\n   \
    \ Map(std::initializer_list<std::pair<Key, Value>> init, const Compare& comp =\
    \ Compare()) : pbds_map<Key, Value, Compare>(init, comp) {}\n    typename Map::const_iterator\
    \ cbegin() const { return this->begin(); }\n    typename Map::const_iterator cend()\
    \ const { return this->end(); }\n    typename Map::const_reverse_iterator crbegin()\
    \ const { return this->rbegin(); }\n    typename Map::const_reverse_iterator crend()\
    \ const { return this->rend(); }\n    template <typename K>\n    std::pair<typename\
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
    \        }\n    };\n}\n#line 5 \"test/yosupo-associative-array.test.cpp\"\nusing\
    \ namespace std;\nusing ll = long long;\n\nint main() {\n    int q; cin >> q;\n\
    \    Map<ll, ll> mp;\n    while(q--) {\n        int op; cin >> op;\n        if(op\
    \ == 0) {\n            ll k, v; cin >> k >> v;\n            mp[k] = v;\n     \
    \   } else {\n            ll k; cin >> k;\n            cout << mp[k] << endl;\n\
    \        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/associative_array\"\n\n\
    #include <bits/stdc++.h>\n#include \"stl-wrapper/map.hpp\"\nusing namespace std;\n\
    using ll = long long;\n\nint main() {\n    int q; cin >> q;\n    Map<ll, ll> mp;\n\
    \    while(q--) {\n        int op; cin >> op;\n        if(op == 0) {\n       \
    \     ll k, v; cin >> k >> v;\n            mp[k] = v;\n        } else {\n    \
    \        ll k; cin >> k;\n            cout << mp[k] << endl;\n        }\n    }\n\
    }\n"
  dependsOn:
  - stl-wrapper/map.hpp
  - stl-wrapper/vector.hpp
  isVerificationFile: true
  path: test/yosupo-associative-array.test.cpp
  requiredBy: []
  timestamp: '2022-11-06 15:35:57+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo-associative-array.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-associative-array.test.cpp
- /verify/test/yosupo-associative-array.test.cpp.html
title: test/yosupo-associative-array.test.cpp
---
