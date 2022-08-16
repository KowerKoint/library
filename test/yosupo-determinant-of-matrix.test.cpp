#include "../matrix/matrix.hpp"
#include "../integer/modint.hpp"

int main() {
    int n; cin >> n;
    Matrix<MI3> a(n, n); cin >> a;
    cout << a.gaussian_elimination().second << endl;
}
