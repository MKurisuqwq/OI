#include <bits/stdc++.h>
#define int long long

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MAXN = 1e4 + 10, mod = 998244353;
int n, m, ans, a[MAXN], C[MAXN][MAXN], pw[MAXN];

void init() {
    pw[0] = C[0][0] = 1;
    for (int i = 1; i < MAXN; i++) {
        pw[i] = (pw[i - 1] << 1) % mod;
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) (C[i][j] += C[i - 1][j - 1] + C[i - 1][j]) %= mod;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int c, t;
    cin >> c >> t;
    init();
    while (t-- > 0) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) cin >> a[i];
        sort(a + 1, a + 1 + n);
        ans = pw[n];
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1, k = 0; j <= n; j++) {
                if (a[i] == a[j] || (m - 2 - (n - j)) < 0) continue;
                if (a[j] >= (a[i] << 1)) break;
                while (k < n && a[k + 1] + a[i] <= a[j]) k++;
                (ans -= C[n - i - 1][m - 2 + n - j] * pw[k] % mod) %= mod;
            }
        }
        cout << (ans + mod) % mod << '\n';
    }

    return 0;
}