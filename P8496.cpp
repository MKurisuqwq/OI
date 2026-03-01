#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MAXN = 1e6 + 10;
int n, q, l[MAXN], a[MAXN], hd[MAXN], ed[MAXN];
set<pii> st[MAXN];
map<int, int> mp[MAXN];

namespace List {
    struct Node {
        int pre, nxt, val;
        Node() { pre = nxt = val = -1; }
    } t[MAXN];
    int cnt;

    int newnode(int val) {
        t[++cnt].val = val;
        return cnt;
    }

    void merge(int a, int b) {
        t[a].nxt = b;
        t[b].pre = a;
    }

    int del(int p) {
        int tmp = t[p].pre;
        merge(t[p].pre, t[p].nxt);
        t[p] = Node();
        return tmp;
    }

    void append(int x, int val) {
        if (!ed[x]) return hd[x] = ed[x] = newnode(val), void();
        merge(ed[x], newnode(val));
        ed[x] = t[ed[x]].nxt;
    }

    void mergelist(int a, int b, int c) {
        merge(ed[a], hd[b]);
        hd[c] = hd[a], ed[c] = ed[b];
        hd[a] = hd[b] = ed[a] = ed[b] = 0;
    }
} // namespace List

struct Node {
    int cnt, res;
} t[MAXN];

Node merge(const Node &a, const Node &b) {
    if (a.res == b.res) return {a.cnt + b.cnt, a.res};
    if (a.cnt > b.cnt) return {a.cnt - b.cnt, a.res};
    return {b.cnt - a.cnt, b.res};
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> l[i];
        for (int j = 1, x; j <= l[i]; j++) {
            cin >> x, List::append(i, x), mp[i][x]++;
        }
        for (auto [x, y] : mp[i]) st[i].emplace(y, x);
        t[i] = {st[i].rbegin()->first, st[i].rbegin()->second};
    }
    while (q-- > 0) {
        int op, x, y, z;
        cin >> op;
        if (op == 1) {
            cin >> x >> y;
            st[x].erase({mp[x][y], y});
            mp[x][y]++;
            st[x].emplace(mp[x][y], y);
            t[x] = {st[x].rbegin()->first, st[x].rbegin()->second};
        } else if (op == 2) {
            cin >> x;
            y = List::t[ed[x]].val;
            st[x].erase({mp[x][y], y});
            mp[x][y]--;
            st[x].emplace(mp[x][y], y);
            t[x] = {st[x].rbegin()->first, st[x].rbegin()->second};
            ed[x] = List::del(ed[x]);
            if (!ed[x]) hd[x] = 0;
        } else if (op == 3) {
            cin >> x >> y;
            auto res = t[y];
            auto tmp = st[y];
            for (int i = 2; i <= n; i++) {
            }
        } else if (op == 4) {
            cin >> x >> y >> z;
            List::mergelist(x, y, z);
        }
    }

    return 0;
}