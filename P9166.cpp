#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MAXN = 2e5 + 10;
int n, m, x;

namespace sgt {
#define lc(p) p << 1
#define rc(p) p << 1 | 1
#define lson lc(p), l, mid
#define rson rc(p), mid + 1, r
    int tag[MAXN << 2];
    struct Node {
        int len, sum;
    } t[MAXN << 2];

    void pushup(int p) { t[p].sum = t[lc(p)].sum + t[rc(p)].sum; }

    void pushdown(int p) {
        if (tag[p]) {
            t[lc(p)].sum = t[lc(p)].len;
            t[rc(p)].sum = t[rc(p)].len;
            tag[lc(p)] = tag[rc(p)] = 1;
        }
        tag[p] = 0;
    }

    void build(int p, int l, int r) {
        t[p].len = r - l + 1;
        if (l == r) return;
        int mid = (l + r) >> 1;
        build(lson), build(rson);
    }

    void modify(int p, int l, int r, int x, int y) {
        if (x <= l && r <= y) {
            t[p].sum = t[p].len;
            tag[p] = 1;
            return;
        }
        pushdown(p);
        int mid = (l + r) >> 1;
        if (x <= mid) modify(lson, x, y);
        if (y > mid) modify(rson, x, y);
        pushup(p);
    }

    int query(int p, int l, int r, int x, int y) {
        if (x <= l && r <= y) return t[p].sum;
        pushdown(p);
        int mid = (l + r) >> 1;
        if (y <= mid) return query(lson, x, y);
        if (x > mid) return query(rson, x, y);
        return query(lson, x, y) + query(rson, x, y);
    }

    void build() { build(1, 1, n); }
    void modify(int x, int y) { modify(1, 1, n, x, y); }
    int query(int x, int y) { return query(1, 1, n, x, y); }
} // namespace sgt
using sgt::build, sgt::modify, sgt::query;

int l[MAXN], r[MAXN];
bitset<MAXN> vis;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m >> x;
    build();
    for (int i = 1; i <= m; i++) {
        cin >> l[i] >> r[i];
        modify(l[i], r[i]);
        if (l[i] < x) vis[l[i]] = 1;
        if (r[i] > x) vis[r[i]] = 1;
    }
    for (int i = 1; i < x; i++)
        if (vis[i] && query(i, x) == x - i + 1) cout << i << ' ';
    for (int i = x + 1; i <= n; i++)
        if (vis[i] && query(x, i) == i - x + 1) cout << i << ' ';

    return 0;
}