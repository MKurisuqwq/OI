#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MAXN = 210;
int n, k, dp[MAXN][10];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> k;
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= k && j <= i; j++) dp[i][j] = dp[i - 1][j - 1] + dp[i - j][j];
    cout << dp[n][k] << '\n';

    return 0;
}