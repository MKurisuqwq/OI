#include <bits/stdc++.h>
#define int long long

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MAXN = 1e5 + 10;
int x, y, ans;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> x >> y;
    for (int i = 1; i * i <= x * y; i++) {
        if (x * y % i) continue;
        int j = x * y / i;
        if (__gcd(i, j) == x) {
            ans += 2;
            if (i == j) ans--;
        }
    }
    cout << ans << '\n';

    return 0;
}