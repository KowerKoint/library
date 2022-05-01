namespace internal_operator {
    template <typename T>
    T default_add(T a, T b) { return a + b; }
    template <typename T>
    T default_sub(T a, T b) { return a - b; }
    template <typename T>
    T zero() { return T(0); }
    template <typename T>
    T default_div(T a, T b) { return a / b; }
    template <typename T>
    T default_mult(T a, T b) { return a * b; }
    template <typename T>
    T one() { return T(1); }
    template <typename T>
    T default_xor(T a, T b) { return a ^ b; }
    template <typename T>
    T default_and(T a, T b) { return a & b; }
    template <typename T>
    T default_or(T a, T b) { return a | b; }
}
