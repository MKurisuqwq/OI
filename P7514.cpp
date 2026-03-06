#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MAXN = 1e6 + 10;
int n, m, ans = INT_MAX;
pii t[MAXN];
mt19937 rnd(chrono::system_clock().now().time_since_epoch().count());

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> t[i].first >> t[i].second;
    for (int _ = 1; _ <= 500; _++) {
        shuffle(t + 1, t + 1 + n, rnd);
        int mn = t[1].first, mx = t[1].second, cnt = 0;
        for (int i = 2; i <= n; i++) {
            if (cnt < m && max(mx, t[i].second) - min(mn, t[i].second) < max(mx, t[i].first) - min(mn, t[i].first))
                cnt++, mx = max(mx, t[i].second), mn = min(mn, t[i].second);
            else
                mx = max(mx, t[i].first), mn = min(mn, t[i].first);
        }
        ans = min(ans, mx - mn);
    }
    cout << ans << '\n';

    return 0;
}