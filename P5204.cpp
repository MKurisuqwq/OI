#include <bits/stdc++.h>
#define int long long

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MAXN = 1e5 + 10, mod = 1e9 + 7;
int n, k, c[MAXN], dp[MAXN], ans = 1;

int qpow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) (res *= a) %= mod;
        (a *= a) %= mod;
        b >>= 1;
    }
    return res;
}

int calc(int v, int len) {
    int x = 1e9 - v;
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= len + 1; i++) {
        (dp[i] = (x + 1) * dp[i - 1] % mod) %= mod;
        if (i - k - 1 >= 0) (dp[i] -= qpow(x, k) * dp[i - k - 1] % mod) %= mod;
    }
    return dp[len + 1];
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n - k + 1; i++) cin >> c[i];
    for (int i = 1, j; i <= n - k + 1; i = j + 1) {
        j = i;
        while (j <= n - k + 1 && c[j + 1] == c[i]) j++;
        int len = j - i + k;
        if ((i ^ 1) && c[i - 1] > c[i]) len -= k;
        if ((j ^ (n - k + 1)) && c[j + 1] > c[j]) len -= k;
        if (len > 0) (ans *= calc(c[i], len)) %= mod;
    }
    cout << (ans + mod) % mod << '\n';

    return 0;
}