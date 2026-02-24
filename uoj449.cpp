#include <bits/stdc++.h>
#define int long long

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MAXN = 60, MAXM = 5e4 + 10, mod = 998244353;
int n, m, k, f[MAXM][MAXN], g[MAXM][MAXN], frac[MAXM], invf[MAXM];

int qpow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) (res *= a) %= mod;
        (a *= a) %= mod, b >>= 1;
    }
    return res;
}

int inv(int x) { return qpow(x, mod - 2); }

int C(int n, int m) { return n < m ? 0 : frac[n] * invf[m] % mod * invf[n - m] % mod; }

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> k;
    m = n * k;
    frac[0] = 1;
    for (int i = 1; i < MAXM; i++) frac[i] = frac[i - 1] * i % mod;
    invf[MAXM - 1] = inv(frac[MAXM - 1]);
    for (int i = MAXM - 2; ~i; i--) invf[i] = invf[i + 1] * (i + 1) % mod;
    f[0][0] = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int x = inv(n - j);
            (f[i + 1][j] += f[i][j] * x % mod) %= mod;
            (g[i + 1][j] += (f[i][j] * x % mod * n % mod + g[i][j]) * x % mod) %= mod;
            (f[i + 1][j + 1] += f[i][j] * x % mod * C(i - j * k, k - 1) % mod) %= mod;
            (g[i + 1][j + 1] += (f[i][j] * x % mod * n % mod + g[i][j]) * x % mod * C(i - j * k, k - 1) % mod) %= mod;
        }
    }
    cout << g[m][n] * frac[n] % mod << '\n';

    return 0;
}