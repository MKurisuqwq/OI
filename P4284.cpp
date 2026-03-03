#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

const int MAXN = 5e5 + 10;
const ld eps = 1e-8;
int n;
vector<pair<int, ld>> g[MAXN];
ld ans, dp[MAXN];

bool eq(ld a, ld b) { return fabs(a - b) < eps; }

void dfs1(int u, int fa) {
    for (auto [v, w] : g[u]) {
        if (v == fa) continue;
        dfs1(v, u);
        dp[u] = dp[u] + dp[v] * w - dp[u] * dp[v] * w;
    }
}

void dfs2(int u, int fa) {
    ans += dp[u];
    for (auto [v, w] : g[u]) {
        if (v == fa) continue;
        if (eq(dp[v] * w, 1)) {
            dfs2(v, u);
            continue;
        }
        ld tmp = (dp[u] - dp[v] * w) / (1 - dp[v] * w);
        dp[v] = dp[v] + tmp * w - dp[v] * tmp * w;
        dfs2(v, u);
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for (int i = 1, u, v, w; i < n; i++) {
        cin >> u >> v >> w;
        g[u].emplace_back(v, w / 100.0);
        g[v].emplace_back(u, w / 100.0);
    }
    for (int i = 1; i <= n; i++) cin >> dp[i], dp[i] /= 100;
    dfs1(1, 0);
    dfs2(1, 0);
    printf("%.6Lf\n", ans);

    return 0;
}