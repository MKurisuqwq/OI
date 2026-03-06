#include <bits/stdc++.h>
#define int long long

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MAXN = 2e5 + 10;
int n, a[MAXN], ans;
set<int> st;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int j = n; j; j--) {
        if (ans > a[j] - 1) break;
        if (a[j - 1] == a[j]) continue;
        st.clear();
        for (int i = 1; i <= n; i++) {
            if (i == j) continue;
            if (!st.empty()) {
                ans = max(ans, (a[i] + *st.rbegin()) % a[j]);
                auto it = st.lower_bound(a[j] - a[i] % a[j]);
                if (it != st.begin()) ans = max(ans, (a[i] + *prev(it)) % a[j]);
            }
            st.emplace(a[i] % a[j]);
        }
    }
    cout << ans << '\n';

    return 0;
}