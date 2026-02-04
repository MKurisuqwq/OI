#include <bits/stdc++.h>
#define int long long

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MAXN = 1010;
int n, x, mod, m, ans;
int a[MAXN], b[MAXN], s[MAXN][MAXN], t[MAXN];

int qpow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) (res *= a) %= mod;
        (a *= a) %= mod, b >>= 1;
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> x >> mod >> m;
    for (int i = 0; i <= m; i++) cin >> a[i];
    s[0][0] = 1;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= m; j++) s[i][j] = (s[i - 1][j - 1] + j * s[i - 1][j] % mod) % mod;
    for (int i = 0; i <= m; i++) t[i] = 1;
    for (int i = 0; i <= m; i++)
        for (int j = i; j <= m; j++) (b[i] += s[j][i] * a[j] % mod) %= mod, (t[j + 1] *= n - i) %= mod;
    for (int i = 0; i <= m; i++) (ans += b[i] * t[i] % mod * qpow(x, i) % mod * qpow(x + 1, n - i) % mod) %= mod;
    cout << ans << '\n';

    return 0;
}