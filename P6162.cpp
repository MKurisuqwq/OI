#include <bits/stdc++.h>
#define int long long

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MAXN = 1e6 + 10, mod = 998244353;
int n, k, m, ans, frac[MAXN];

int qpow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) (res *= a) %= mod;
        (a *= a) %= mod, b >>= 1;
    }
    return res;
}

int inv(int x) { return qpow(x, mod - 2); }

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> k;
    frac[0] = 1;
    for (int i = 1; i <= n; i++) frac[i] = i * frac[i - 1] % mod;
    m = n - k;
    for (int i = 0; i <= m; i++)
        (ans += (i & 1 ? -1 : 1) * qpow(m - i, n) * inv(frac[i]) % mod * inv(frac[m - i]) % mod) %= mod;
    cout << (ans + mod) % mod << '\n';

    return 0;
}