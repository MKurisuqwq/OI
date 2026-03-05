#include <bits/stdc++.h>
#define int long long

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MAXN = 1e5 + 10;
int n, k, X, Y, a[MAXN], b[MAXN], sum[MAXN], l[MAXN], r[MAXN];

void solve(int dx, int dy) {
    int tmp = dx * X + dy * Y;
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + dx * a[i] + dy * b[i] + k;
    if (!sum[n]) {
        for (int i = 1; i <= n; i++)
            if (sum[i] < tmp) r[i] = -1;
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (sum[n] > 0) {
            if (sum[i] < tmp) l[i] = max(l[i], (tmp - sum[i] + sum[n] - 1) / sum[n]);
        } else {
            if (sum[i] < tmp)
                r[i] = -1;
            else
                r[i] = min(r[i], (tmp - sum[i]) / sum[n]);
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;
    while (T-- > 0) {
        cin >> n >> k >> X >> Y;
        for (int i = 1; i <= n; i++) cin >> a[i] >> b[i], l[i] = 0, r[i] = LLONG_MAX;
        if (!X && !Y) {
            cout << "0\n";
            continue;
        }
        solve(1, 1), solve(1, -1), solve(-1, 1), solve(-1, -1);
        int ans = LLONG_MAX;
        for (int i = 1; i <= n; i++)
            if (l[i] <= r[i]) ans = min(ans, l[i] * n + i);
        cout << (ans == LLONG_MAX ? -1 : ans) << '\n';
    }

    return 0;
}