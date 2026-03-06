#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MAXN = 4e5 + 10;
int n, cnt, sum[MAXN], num[MAXN], ans = -1, id;

struct Node {
    int op, l, r, w;
} t[MAXN];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    num[++cnt] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> t[i].op;
        if (t[i].op == 1) {
            cin >> t[i].l >> t[i].r >> t[i].w;
            num[++cnt] = t[i].l;
            num[++cnt] = t[i].l - 1;
            num[++cnt] = t[i].r;
            num[++cnt] = t[i].r + 1;
        } else if (t[i].op == 2) {
            cin >> t[i].l >> t[i].w;
            num[++cnt] = t[i].l;
            num[++cnt] = t[i].l - 1;
            num[++cnt] = t[i].l + 1;
        } else if (t[i].op == 3) {
            cin >> t[i].l >> t[i].w;
            num[++cnt] = t[i].l;
            num[++cnt] = t[i].l - 1;
            num[++cnt] = t[i].l + 1;
        }
    }
    sort(num + 1, num + 1 + cnt);
    cnt = unique(num + 1, num + 1 + cnt) - num - 1;
    for (int i = 1; i <= n; i++) {
        auto [op, l, r, w] = t[i];
        int L = lower_bound(num + 1, num + 1 + cnt, l) - num;
        if (op == 1) {
            sum[L] ^= w;
            sum[lower_bound(num + 1, num + 1 + cnt, r) - num + 1] ^= w;
        } else if (op == 2) {
            sum[L] ^= w;
            sum[L + 1] ^= w;
        } else if (op == 3) {
            if (L ^ 1) sum[1] ^= w, sum[L] ^= w;
            sum[L + 1] ^= w;
        }
    }
    for (int i = 1; i <= cnt; i++) {
        sum[i] ^= sum[i - 1];
        if (sum[i] > ans)
            ans = sum[i], id = num[i];
        else if (sum[i] == ans) {
            if (abs(id) > abs(num[i]))
                id = num[i];
            else if (abs(id) == abs(num[i]) && num[i] > id)
                id = num[i];
        }
    }
    cout << ans << ' ' << id << '\n';

    return 0;
}