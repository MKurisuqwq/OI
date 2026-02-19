#include <bits/stdc++.h>
#define int long long

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MAXN = 1e6 + 10, MAXM = 70, mod = 1e9 + 7;
int n, m, k, t;

struct Matrix {
    int a[MAXM][MAXM];

    Matrix() { memset(a, 0, sizeof(a)); }

    constexpr auto operator[](const int &x) { return a[x]; }

    Matrix operator*(const Matrix &o) {
        Matrix res;
        for (int i = 0; i < t; i++)
            for (int k = 0; k < t; k++)
                for (int j = 0; j < t; j++) (res[i][j] += a[i][k] * o.a[k][j] % mod) %= mod;
        return res;
    }
};

Matrix qpow(Matrix a, int b) {
    auto res = a;
    b--;
    while (b) {
        if (b & 1) res = res * a;
        a = a * a, b >>= 1;
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m >> k;
    t = 1 << m;
    Matrix a;
    for (int i = 0, j; i < t; ++i) {
        if (__builtin_popcount(i) > k) continue;
        j = i >> 1;
        a[j][i] = 1;
        j = (i >> 1) | (1 << (m - 1));
        if (__builtin_popcount(j) <= k) a[j][i] = 1;
    }
    auto b = qpow(a, n);
    int ans = 0;
    for (int i = 0; i < t; ++i) (ans += b[i][i]) %= mod;
    cout << ans << '\n';

    return 0;
}