#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MAXN = 2e6 + 10;
int n, l1[MAXN], r1[MAXN], l2[MAXN], r2[MAXN];
namespace solve {
    int cnt, a[MAXN], b[MAXN], c[MAXN], d[MAXN], e[MAXN], f[MAXN], num[MAXN];
    void solve() {
        cnt = 0;
        for (int i = 1; i <= n; i++)
            num[++cnt] = l2[i], num[++cnt] = r2[i] + 1, a[i] = b[i] = c[i] = d[i] = e[i] = f[i] = 0;
        sort(num + 1, num + 1 + cnt), cnt = unique(num + 1, num + 1 + cnt) - num - 1;
        for (int i = 1; i <= n; i++) {
            int L = lower_bound(num + 1, num + 1 + cnt, l2[i]) - num,
                R = lower_bound(num + 1, num + 1 + cnt, r2[i] + 1) - num;
            a[L] += r1[i], a[R] -= r1[i], b[R] += l1[i], c[R] += r1[i], d[1] += l1[i], d[L] -= l1[i], e[1] += r1[i],
                e[L] -= r1[i], f[L]++, f[R]--;
        }
        int ans = 0;
        for (int i = 1; i <= cnt; i++) {
            a[i] += a[i - 1], b[i] += b[i - 1], c[i] += c[i - 1], d[i] += d[i - 1], e[i] += e[i - 1], f[i] += f[i - 1];
            if (f[i] && max(b[i] - a[i] + 1, d[i]) <= min(c[i] + a[i], e[i])) ans += num[i + 1] - num[i];
        }
        cout << ans << '\n';
    }
} // namespace solve

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int c, T;
    cin >> c >> T;
    while (T-- > 0) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> l1[i] >> r1[i] >> l2[i] >> r2[i];
        solve::solve();
    }

    return 0;
}