#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MAXN = 4e7 + 10, mod = 998244353;
int ans, n, k, frac[MAXN], invf[MAXN];

ll qpow(ll a, int b) {
    ll res = 1;
    while (b) {
        if (b & 1) (res *= a) %= mod;
        (a *= a) %= mod, b >>= 1;
    }
    return res;
}

ll C(int a, int b) { return a < b || a < 0 || b < 0 ? 0 : ll(frac[a]) * invf[b] % mod * invf[a - b] % mod; }

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> k;
    invf[0] = frac[0] = 1;
    for (int i = 1; i < MAXN; i++) frac[i] = (ll)frac[i - 1] * i % mod;
    invf[MAXN - 1] = qpow(frac[MAXN - 1], mod - 2);
    for (int i = MAXN - 2; i; i--) invf[i] = (ll)invf[i + 1] * (i + 1) % mod;

    ans = (n == k);
    for (int i = 1; i <= k; i++)
        for (int j = 0; j <= k; j++)
            ans = ((ll)ans + C(2 * n - 2 * j - 2 * i, k - j - 2 * i) * C(j + 1, i) % mod * C(n - j - 1, i - 1) % mod) %
                  mod;
    cout << ans << '\n';

    return 0;
}