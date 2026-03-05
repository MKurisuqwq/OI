#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MAXN = 1e5 + 10;
int n, k, X, Y, a[MAXN], b[MAXN], sum[MAXN], l[MAXN], r[MAXN];

void solve(int dx, int dy) {
    int pos = dx * X + dy * Y;
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + dx * a[i] + dy * b[i];
    if (!sum[n]) {
        ;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;
    while (T-- > 0) {
        cin >> n >> k >> X >> Y;
        for (int i = 1; i <= n; i++) cin >> a[i] >> b[i], r[i] = INT_MAX;
        if (!X && !Y) {
            cout << "0\n";
            continue;
        }
    }

    return 0;
}