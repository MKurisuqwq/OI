#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAXN = 300, mod = 998244353;
int n, a, b, dp[MAXN * MAXN][MAXN];
int frac[MAXN * MAXN], invf[MAXN * MAXN];

int qpow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) (res *= a) %= mod;
        (a *= a) %= mod, b >>= 1;
    }
    return res;
}

int inv(int x) { return qpow(x, mod - 2); }

int C(int n, int m) { return frac[n] * invf[m] % mod * invf[n - m] % mod; }

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> a >> b;
    frac[0] = 1;
    for (int i = 1; i <= (n - 1) * b + a; i++) frac[i] = frac[i - 1] * i % mod;
    invf[(n - 1) * b + a] = inv(frac[(n - 1) * b + a]);
    for (int i = (n - 1) * b + a - 1; ~i; i--) invf[i] = invf[i + 1] * (i + 1) % mod;
    dp[0][0] = 1;
    for (int i = 0; i <= (n - 1) * b + a; i++) {
        for (int j = 0; j <= min(n - 1, i / b); j++) {
            int tmp = dp[i][j] * inv(n - j) % mod;
            (dp[i + 1][j] += tmp) %= mod;
            (dp[i + 1][j + 1] += tmp * C(i - j * b, b - 1) % mod) %= mod;
        }
    }
    int ans = n * (1 - frac[n - 1] * dp[(n - 1) * b + a - 1][n - 1] % mod) % mod;
    cout << (ans + mod) % mod << '\n';

    return 0;
}
