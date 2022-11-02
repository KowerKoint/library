---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: stl-wrapper/set.hpp
    title: stl-wrapper/set.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/set_xor_min
    links:
    - https://judge.yosupo.jp/problem/set_xor_min
  bundledCode: "#line 1 \"test/yosupo-set-xor-min.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/set_xor_min\"\
    \n\n#include <bits/stdc++.h>\n#line 4 \"stl-wrapper/set.hpp\"\n#include <ext/pb_ds/assoc_container.hpp>\n\
    #include <ext/pb_ds/tree_policy.hpp>\n#line 5 \"stl-wrapper/vector.hpp\"\n\ntemplate\
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
    \ return seed;\n        }\n    };\n};\n#line 7 \"stl-wrapper/set.hpp\"\n\n\ntemplate\
    \ <typename T, typename Compare = std::less<T>>\nusing pbds_set = __gnu_pbds::tree<T,\
    \ __gnu_pbds::null_type, Compare, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;\n\
    \ntemplate <typename T, typename Compare = std::less<T>>\nstruct Set : public\
    \ pbds_set<T, Compare> {\n    Set() : pbds_set<T, Compare>() {}\n    explicit\
    \ Set(const Compare& comp) : pbds_set<T, Compare>(comp) {}\n    template <typename\
    \ It>\n    Set(It first, It last, const Compare& comp = Compare()) : pbds_set<T,\
    \ Compare>(first, last, comp) {}\n    Set(const pbds_set<T, Compare>& other) :\
    \ pbds_set<T, Compare>(other) {}\n    Set(const std::set<T, Compare>& other) :\
    \ pbds_set<T, Compare>(other.begin(), other.end()) {}\n    Set(pbds_set<T, Compare>&&\
    \ other) : pbds_set<T, Compare>(std::move(other)) {}\n    Set(std::initializer_list<T>\
    \ init, const Compare& comp = Compare()) : pbds_set<T, Compare>(init, comp) {}\n\
    \    typename Set::const_iterator cbegin() const { return this->begin(); }\n \
    \   typename Set::const_iterator cend() const { return this->end(); }\n    typename\
    \ Set::const_reverse_iterator crbegin() const { return this->rbegin(); }\n   \
    \ typename Set::const_reverse_iterator crend() const { return this->rend(); }\n\
    \    template <typename K>\n    std::pair<typename Set::iterator, typename Set::iterator>\
    \ equal_range(const K& value) {\n        return std::make_pair(lower_bound(value),\
    \ upper_bound(value));\n    }\n    template <typename K>\n    std::pair<typename\
    \ Set::const_iterator, typename Set::const_iterator> equal_range(const K& value)\
    \ const {\n        return std::make_pair(lower_bound(value), upper_bound(value));\n\
    \    }\n    template <typename K>\n    size_t count(const K& x) const { return\
    \ this->find(x) != this->end(); }\n    decltype(Compare()) key_comp() const {\
    \ return Compare(); }\n    template <typename... Args>\n    std::pair<typename\
    \ Set::iterator, bool> emplace(Args&&... args) {\n        return this->insert(T(std::forward<Args>(args)...));\n\
    \    }\n    template <typename... Args>\n    typename Set::iterator emplace_hint(typename\
    \ Set::const_iterator hint, Args&&... args) {\n        return this->insert(hint,\
    \ T(std::forward<Args>(args)...));\n    }\n    friend std::ostream& operator<<(std::ostream&\
    \ os, const Set& set) {\n        Vector<T> vector(set.begin(), set.end());\n \
    \       return os << vector;\n    }\n};\n\nnamespace _set_util {\n    template\
    \ <typename T, typename Compare>\n    struct CompareEqual {\n        bool operator()(const\
    \ T& lhs, const T& rhs) const {\n            return !Compare()(rhs, lhs);\n  \
    \      }\n    };\n}\ntemplate <typename T, typename Compare = std::less<T>>\n\
    using pbds_multiset = __gnu_pbds::tree<T, __gnu_pbds::null_type, _set_util::CompareEqual<T,\
    \ Compare>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;\n\
    \ntemplate <typename T, typename Compare = std::less<T>>\nstruct MultiSet : public\
    \ pbds_multiset<T, Compare> {\n    MultiSet() : pbds_multiset<T, Compare>() {}\n\
    \    explicit MultiSet(const Compare& comp) : pbds_multiset<T, Compare>(comp)\
    \ {}\n    template <typename It>\n    MultiSet(It first, It last, const Compare&\
    \ comp = Compare()) : pbds_multiset<T, Compare>(first, last, comp) {}\n    MultiSet(const\
    \ pbds_multiset<T, Compare>& other) : pbds_multiset<T, Compare>(other) {}\n  \
    \  MultiSet(const std::multiset<T, Compare>& other) : pbds_multiset<T, Compare>(other.begin(),\
    \ other.end()) {}\n    MultiSet(pbds_multiset<T, Compare>&& other) : pbds_multiset<T,\
    \ Compare>(std::move(other)) {}\n    MultiSet(std::initializer_list<T> init, const\
    \ Compare& comp = Compare()) : pbds_multiset<T, Compare>(init, comp) {}\n    typename\
    \ MultiSet::const_iterator cbegin() const { return this->begin(); }\n    typename\
    \ MultiSet::const_iterator cend() const { return this->end(); }\n    typename\
    \ MultiSet::const_reverse_iterator crbegin() const { return this->rbegin(); }\n\
    \    typename MultiSet::const_reverse_iterator crend() const { return this->rend();\
    \ }\n    template <typename K>\n    std::pair<typename MultiSet::iterator, typename\
    \ MultiSet::iterator> equal_range(const K& value) {\n        return std::make_pair(lower_bound(value),\
    \ upper_bound(value));\n    }\n    template <typename K>\n    std::pair<typename\
    \ MultiSet::const_iterator, typename MultiSet::const_iterator> equal_range(const\
    \ K& value) const {\n        return std::make_pair(lower_bound(value), upper_bound(value));\n\
    \    }\n    template <typename K>\n    size_t count(const K& x) const {\n    \
    \    auto range = equal_range(x);\n        return std::distance(range.first, range.second);\n\
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
    };\n#line 5 \"test/yosupo-set-xor-min.test.cpp\"\nusing namespace std;\nint main()\
    \ {\n    int q; cin >> q;\n    Set<int> s;\n    while(q--) {\n        int t, x;\
    \ cin >> t >> x;\n        if(t == 0) {\n            s.insert(x);\n        } else\
    \ if(t == 1) {\n            s.erase(x);\n        } else {\n            auto l\
    \ = s.begin();\n            auto r = s.end();\n            int v = 0;\n      \
    \      for(int i = 29; i >= 0; i--) {\n                int v2 = v | (1 << i);\n\
    \                auto it = s.lower_bound(v2);\n                if(l == it || (it\
    \ != r && x >> i & 1)) {\n                    v = v2;\n                    l =\
    \ it;\n                } else {\n                    r = it;\n               \
    \ }\n            }\n            cout << (x^v) << endl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/set_xor_min\"\n\n#include\
    \ <bits/stdc++.h>\n#include \"stl-wrapper/set.hpp\"\nusing namespace std;\nint\
    \ main() {\n    int q; cin >> q;\n    Set<int> s;\n    while(q--) {\n        int\
    \ t, x; cin >> t >> x;\n        if(t == 0) {\n            s.insert(x);\n     \
    \   } else if(t == 1) {\n            s.erase(x);\n        } else {\n         \
    \   auto l = s.begin();\n            auto r = s.end();\n            int v = 0;\n\
    \            for(int i = 29; i >= 0; i--) {\n                int v2 = v | (1 <<\
    \ i);\n                auto it = s.lower_bound(v2);\n                if(l == it\
    \ || (it != r && x >> i & 1)) {\n                    v = v2;\n               \
    \     l = it;\n                } else {\n                    r = it;\n       \
    \         }\n            }\n            cout << (x^v) << endl;\n        }\n  \
    \  }\n}\n"
  dependsOn:
  - stl-wrapper/set.hpp
  - stl-wrapper/vector.hpp
  isVerificationFile: true
  path: test/yosupo-set-xor-min.test.cpp
  requiredBy: []
  timestamp: '2022-11-03 02:21:27+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo-set-xor-min.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-set-xor-min.test.cpp
- /verify/test/yosupo-set-xor-min.test.cpp.html
title: test/yosupo-set-xor-min.test.cpp
---
