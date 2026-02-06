#include <bits/stdc++.h>
#define int long long

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MAXN = 110;
int n, m, dp[MAXN][MAXN];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    while (cin >> n >> m) {
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m && j <= i; j++) dp[i][j] = j * dp[i - 1][j] + dp[i - 1][j - 1];
        cout << dp[n][m] << '\n';
    }

    return 0;
}