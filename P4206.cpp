#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

const int MAXN = 1010;
int n, m, dis[MAXN][MAXN], nxt[MAXN][MAXN];
vector<int> g[MAXN];

namespace dijskra {
    bitset<MAXN> vis;
    priority_queue<pii, vector<pii>, greater<>> q;

    void work(int s, int *dis) {
        vis.reset();
        q.emplace(dis[s] = 0, s);
        while (!q.empty()) {
            auto [d, u] = q.top();
            q.pop();

            if (vis[u]) continue;
            vis[u] = 1;

            for (auto v : g[u])
                if (dis[v] > d + 1) q.emplace(dis[v] = d + 1, v);
        }
    }
} // namespace dijskra

namespace solve {
    ld dp[MAXN][MAXN];
    bitset<MAXN> vis[MAXN];
    ld dfs(int s, int t) {
        if (vis[s][t]) return dp[s][t];
        vis[s][t] = 1;
        int tmp1 = nxt[t][s];
        int tmp2 = nxt[t][tmp1];
        if (s == t) return dp[s][t] = 0;
        if (tmp1 == t || tmp2 == t) return dp[s][t] = 1;
        for (auto v : g[t]) dp[s][t] += dfs(tmp2, v) / (g[t].size() + 1);
        dp[s][t] += dfs(tmp2, t) / (g[t].size() + 1);
        dp[s][t] += 1;
        return dp[s][t];
    }
} // namespace solve

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int s, t;
    cin >> n >> m >> s >> t;
    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    memset(dis, 0x3f, sizeof(dis));
    memset(nxt, 0x3f, sizeof(nxt));
    for (int i = 1; i <= n; i++) dijskra::work(i, dis[i]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (auto k : g[j])
                if (dis[i][k] == dis[i][j] - 1) nxt[i][j] = min(nxt[i][j], k);
    printf("%.3Lf\n", solve::dfs(s, t));

    return 0;
}