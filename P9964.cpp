#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

const int MAXN = 5010;
int n, p[MAXN], s[MAXN][MAXN], t[MAXN][MAXN];
pii dp[MAXN][MAXN];
string st;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> st;
    st = ' ' + st;
    for (int i = 1; i <= n; i++) {
        for (p[i] = 1; i - p[i] && i + p[i] <= n; p[i]++)
            if (st[i - p[i]] == st[i + p[i]]) break;
        p[i]--;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++, s[i][j] = s[i][j - 1])
            if (j - p[j] <= i) s[i][j] = j;
        for (int j = n; j; j--, t[i][j] = t[i][j + 1])
            if (j + p[j] >= i) t[i][j] = j;
        dp[i][i] = {1, 0};
    }
    for (int len = 2; len <= n; len++) {
        for (int i = 1, j = len; j <= n; i++, j++) {
            dp[i][j] = {n + 1, 0};
            int k = (i + j) >> 1, u;
            if ((u = s[i][k]) && u >= i)
                dp[i][j] = min(dp[i][j], {dp[u + 1][j].first + 1, dp[u + 1][j].second + i + j - u - u});
            if ((u = t[j][k + 1]) && u <= j)
                dp[i][j] = min(dp[i][j], {dp[i][u - 1].first + 1, dp[i][u - 1].second + u + u - i - j});
        }
    }
    cout << dp[1][n].first << ' ' << dp[1][n].second << '\n';

    return 0;
}