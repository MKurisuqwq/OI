#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int ans = 1, n, cnt;

int calc(int x) {
    while (!(x & 1)) {
        x >>= 1;
        cnt++;
    }
    while (!(x % 5)) {
        x /= 5;
        cnt--;
    }
    return x;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) (ans *= calc(i)) %= 10;
    for (int i = 1; i <= cnt; i++) (ans <<= 1) %= 10;
    cout << ans << '\n';

    return 0;
}