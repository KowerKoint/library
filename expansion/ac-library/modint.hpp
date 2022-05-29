ostream &operator<<(ostream &os, const modint &x) {
    os << x.val();
    return os;
}

ostream &operator<<(ostream &os, const modint998244353 &x) {
    os << x.val();
    return os;
}

ostream &operator<<(ostream &os, const modint1000000007 &x) {
    os << x.val();
    return os;
}

istream &operator>>(istream &is, modint &x) {
    int y; is >> y;
    x = y;
    return is;
}

istream &operator>>(istream &is, modint998244353 &x) {
    int y; is >> y;
    x = y;
    return is;
}

istream &operator>>(istream &is, modint1000000007 &x) {
    int y; is >> y;
    x = y;
    return is;
}
