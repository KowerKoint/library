using MI7 = modint1000000007;
using V7 = vector<MI7>;
using VV7 = vector<V7>;
using VVV7 = vector<VV7>;
using MI3 = modint998244353;
using V3 = vector<MI3>;
using VV3 = vector<V3>;
using VVV3 = vector<VV3>;

ostream &operator<<(ostream &os, const modint &x) {
    os << x.val();
    return os;
}

ostream &operator<<(ostream &os, const MI3 &x) {
    os << x.val();
    return os;
}

ostream &operator<<(ostream &os, const MI7 &x) {
    os << x.val();
    return os;
}

istream &operator>>(istream &is, modint &x) {
    int y; is >> y;
    x = y;
    return is;
}

istream &operator>>(istream &is, MI3 &x) {
    int y; is >> y;
    x = y;
    return is;
}

istream &operator>>(istream &is, MI7 &x) {
    int y; is >> y;
    x = y;
    return is;
}
