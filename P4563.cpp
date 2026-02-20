#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MAXN = 5010;
int n, ans, h[MAXN], sum, dp[MAXN][MAXN];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> h[i];
    for (int r = 1; r <= n; r++) {
        ans ^= (dp[r][r] = 1);
        int p = 0;
        for (int l = r - 1; l; l--) {
            if (!p || (ll)(h[r] - h[l]) * (r - p) < (ll)(h[r] - h[p]) * (r - l)) p = l;
            ans ^= (dp[l][r] = min(dp[l][p - 1], dp[l][p]) + dp[p + 1][r]);
        }
    }
    cout << ans << '\n';

    return 0;
}