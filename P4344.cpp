#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;
int n, m;

namespace sgt {
#define lc(p) p << 1
#define rc(p) p << 1 | 1
#define lson lc(p), l, mid
#define rson rc(p), mid + 1, r

    int tag[MAXN << 2];
    struct Node {
        int lmx, rmx, res, cnt, len;
    } t[MAXN << 2];

    Node merge(const Node &a, const Node &b) {
        Node res;
        res.lmx = max(a.lmx, a.lmx == a.len ? a.len + b.lmx : 0);
        res.rmx = max(b.rmx, b.rmx == b.len ? b.len + a.rmx : 0);
        res.res = max({a.res, b.res, a.rmx + b.lmx});
        res.cnt = a.cnt + b.cnt;
        res.len = a.len + b.len;
        return res;
    }

    void build(int p, int l, int r) {
        t[p].cnt = t[p].len = r - l + 1;
        if (l == r) return;
        int mid = (l + r) >> 1;
        build(lson), build(rson);
    }

    void pushup(int p) { t[p] = merge(t[lc(p)], t[rc(p)]); }

    void pushdown(int p) {
        auto &L = t[lc(p)], &R = t[rc(p)];
        if (!~tag[p]) {
            L = {L.len, L.len, L.len, 0, L.len};
            R = {R.len, R.len, R.len, 0, R.len};
            tag[lc(p)] = tag[rc(p)] = -1;
        } else if (tag[p]) {
            L = {0, 0, 0, L.len, L.len};
            R = {0, 0, 0, R.len, R.len};
            tag[lc(p)] = tag[rc(p)] = 1;
        }
        tag[p] = 0;
    }

    void del(int p, int l, int r, int x, int y) {
        if (x <= l && r <= y) {
            t[p] = {t[p].len, t[p].len, t[p].len, 0, t[p].len};
            tag[p] = -1;
            return;
        }
        pushdown(p);
        int mid = (l + r) >> 1;
        if (x <= mid) del(lson, x, y);
        if (y > mid) del(rson, x, y);
        pushup(p);
    }

    void add(int p, int l, int r, int x, int y) {
        if (x <= l && r <= y) {
            t[p] = {0, 0, 0, t[p].len, t[p].len};
            tag[p] = 1;
            return;
        }
        pushdown(p);
        int mid = (l + r) >> 1;
        if (x <= mid) add(lson, x, y);
        if (y > mid) add(rson, x, y);
        pushup(p);
    }

    Node query(int p, int l, int r, int x, int y) {
        if (x <= l && r <= y) return t[p];
        pushdown(p);
        int mid = (l + r) >> 1;
        if (y <= mid) return query(lson, x, y);
        if (x > mid) return query(rson, x, y);
        return merge(query(lson, x, y), query(rson, x, y));
    }

    void remove(int l, int r) { del(1, 1, n, l, r); }
    void insert(int l, int r) { add(1, 1, n, l, r); }
    Node query(int l, int r) { return query(1, 1, n, l, r); }
} // namespace sgt

using sgt::build;
using sgt::insert;
using sgt::query;
using sgt::remove;

void solve(int a, int b, int x, int y) {
    int tmp = query(a, b).cnt;
    if (!tmp) return;
    remove(a, b);
    int l = x, r = y, res = y;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (mid - x + 1 - query(x, mid).cnt <= tmp)
            res = mid, l = mid + 1;
        else
            r = mid - 1;
    }
    insert(x, res);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    build(1, 1, n);
    while (m-- > 0) {
        int op, l, r, x, y;
        cin >> op >> l >> r;
        if (op == 0) {
            remove(l, r);
        } else if (op == 1) {
            cin >> x >> y;
            solve(l, r, x, y);
        } else if (op == 2) {
            cout << query(l, r).res << '\n';
        }
    }

    return 0;
}