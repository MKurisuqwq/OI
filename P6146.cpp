#include <bits/stdc++.h>
#define int long long
#define lc(p) p << 1
#define rc(p) p << 1 | 1
#define lson lc(p), l, mid
#define rson rc(p), mid + 1, r

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MAXN = 2e5 + 10, mod = 1e9 + 7;
int n, k, C[15][15];
struct Line {
    int l, r;
    bool operator<(const Line &o) const { return l < o.l; }
} a[MAXN];

int qpow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) (res *= a) %= mod;
        (a *= a) %= mod;
        b >>= 1;
    }
    return res;
}

struct Node {
    int a[15];

    Node() { memset(a, 0, sizeof(a)); }

    int operator[](const int &x) const { return a[x]; }
    int &operator[](const int &x) { return a[x]; }

    Node operator+(const Node &o) const {
        Node res;
        for (int i = 0; i <= k; i++) res[i] = (a[i] + o[i]) % mod;
        return res;
    }
} t[MAXN << 2];

int tag[MAXN << 2];

void pushup(int p) { t[p] = t[lc(p)] + t[rc(p)]; }

void pushdown(int p) {
    int tmp = qpow(2, tag[p]);
    for (int i = 0; i <= k; i++) (t[lc(p)][i] *= tmp) %= mod;
    for (int i = 0; i <= k; i++) (t[rc(p)][i] *= tmp) %= mod;
    tag[lc(p)] += tag[p], tag[rc(p)] += tag[p];
    tag[p] = 0;
}

void add(int p, int l, int r, int x, const Node &val) {
    if (l == r) return t[p] = t[p] + val, void();
    int mid = (l + r) >> 1;
    pushdown(p);
    x <= mid ? add(lson, x, val) : add(rson, x, val);
    pushup(p);
}

void modify(int p, int l, int r, int L, int R) {
    if (L > R) return;
    if (L <= l && r <= R) {
        for (int i = 0; i <= k; i++) (t[p][i] <<= 1) %= mod;
        return tag[p]++, void();
    }
    int mid = (l + r) >> 1;
    pushdown(p);
    if (L <= mid) modify(lson, L, R);
    if (R > mid) modify(rson, L, R);
    pushup(p);
}

Node query(int p, int l, int r, int L, int R) {
    if (L <= l && r <= R) return t[p];
    int mid = (l + r) >> 1;
    pushdown(p);
    if (R <= mid) return query(lson, L, R);
    if (L > mid) return query(rson, L, R);
    return query(lson, L, R) + query(rson, L, R);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> k;
    C[0][0] = 1;
    for (int i = 1; i <= k; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
    }
    for (int i = 1; i <= n; i++) cin >> a[i].l >> a[i].r;
    sort(a + 1, a + 1 + n);
    Node b;
    b[0] = 1;
    add(1, 0, n << 1, 0, b);
    for (int i = 1; i <= n; i++) {
        auto [l, r] = a[i];
        Node tmp = query(1, 0, n << 1, 0, l - 1), q = query(1, 0, n << 1, l, r - 1);
        for (int i = 0; i <= k; i++)
            for (int j = 0; j <= i; j++) (q[i] += tmp[j] * C[i][j] % mod) %= mod;
        add(1, 0, n << 1, r, q);
        modify(1, 0, n << 1, r + 1, n << 1);
    }
    cout << query(1, 0, n << 1, 0, n << 1)[k] << '\n';

    return 0;
}