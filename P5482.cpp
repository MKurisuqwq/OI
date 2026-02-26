#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MAXN = 2e6 + 10;
int q, cnt, a[MAXN], b[MAXN], c[MAXN];
bitset<MAXN> vis;

namespace fenwick {
    int t[MAXN];
    constexpr int lowbit(const int &x) { return x & -x; }

    void add(int x, int val) {
        for (; x < MAXN; x += lowbit(x)) t[x] += val;
    }

    void add(int l, int r, int val) { add(l, val), add(r + 1, -val); }

    int query(int x) {
        int res = 0;
        for (; x; x -= lowbit(x)) res += t[x];
        return res;
    }
} // namespace fenwick

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> q;
    while (q-- > 0) {
        string s;
        int x, y, z;
        cin >> s >> x;
        if (s == "Add") {
            cin >> y >> z;
            cnt++;
            a[cnt] = x, b[cnt] = y, c[cnt] = z;
            vis[cnt] = 1;
            if (x > 0) {
                int tmp = floor(1.0 * (z - y) / x) + 1 + 1e6 + 1;
                if (tmp <= 0) tmp = 1;
                fenwick::add(tmp, 1);
            } else if (x == 0) {
                if (y > z) fenwick::add(1, 1);
            } else {
                int tmp = ceil(1.0 * (z - y) / x) - 1 + 1e6 + 1;
                if (tmp <= 0) continue;
                fenwick::add(1, tmp, 1);
            }
        } else if (s == "Del") {
            if (vis[x]) {
                vis[x] = 0;
                if (a[x] > 0) {
                    int tmp = floor(1.0 * (c[x] - b[x]) / a[x]) + 1 + 1e6 + 1;
                    if (tmp <= 0) tmp = 1;
                    fenwick::add(tmp, -1);
                } else if (a[x] == 0) {
                    if (b[x] > c[x]) fenwick::add(1, -1);
                } else {
                    int tmp = ceil(1.0 * (c[x] - b[x]) / a[x]) - 1 + 1e6 + 1;
                    if (tmp <= 0) continue;
                    fenwick::add(1, tmp, -1);
                }
            }
        } else {
            cout << fenwick::query(x + 1e6 + 1) << '\n';
        }
    }

    return 0;
}