#include <bits/stdc++.h>
#define int long long

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MAXN = 2e6 + 10, mod = 20100403;
int n, m, frac[MAXN];

int qpow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) (res *= a) %= mod;
        (a *= a) %= mod, b >>= 1;
    }
    return res;
}

int inv(int x) { return qpow(x, mod - 2); }

int C(int n, int m) {
    if (m > n) return 0;
    return frac[n] * inv(frac[m]) % mod * inv(frac[n - m]) % mod;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    frac[0] = 1;
    for (int i = 1; i <= n + m; i++) frac[i] = frac[i - 1] * i % mod;
    cout << (C(n + m, n) - C(n + m, n + 1) + mod) % mod << '\n';

    return 0;
}