#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MAXN = 5e5 + 10;
int n, a[MAXN], cnt[MAXN];
ll ans;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], cnt[a[i]]++;
    for (int i = 1; i <= n; i++) ans += cnt[a[i]] - 1;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 1) continue;
        for (int j = 1; j * j <= a[i]; j++) {
            if (a[i] % j) continue;
            ans += cnt[j];
            if (((j * j) ^ a[i]) && (j ^ 1)) ans += cnt[a[i] / j];
        }
    }
    cout << ans << '\n';

    return 0;
}