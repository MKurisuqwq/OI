#include <bits/stdc++.h>
#define int long long

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int T;

int exgcd(int a, int b, int &x, int &y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    int res = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return res;
}

void solve() {
    int x, y, a, b, c;
    cin >> a >> b >> c;
    int res = exgcd(a, b, x, y);
    if (c % res) return cout << "-1\n", void();
    x *= c / res, y *= c / res;
    int dx = b / res, dy = a / res;
    int m = ceil(1.0 * (1 - x) / dx), n = floor(1.0 * (y - 1) / dy);
    if (m > n) {
        cout << x + m * dx << " " << y - n * dy << "\n";
    } else {
        int xmn = (x % dx + dx) % dx;
        xmn = xmn == 0 ? dx : xmn;
        int ymn = (y % dy + dy) % dy;
        ymn = ymn == 0 ? dy : ymn;
        int xmx = (c - ymn * b) / a, ymx = (c - xmn * a) / b, cnt = n - m + 1;
        cout << cnt << " " << xmn << " " << ymn << " " << xmx << " " << ymx << "\n";
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> T;
    while (T-- > 0) solve();

    return 0;
}