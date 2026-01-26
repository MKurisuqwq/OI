#include <bits/stdc++.h>
#define int long long

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n;

int calc(int val) {
    int res = 0;
    for (int i = 2; i * i * i <= val; i++) res += val / (i * i * i);
    return res;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    int l = 1, r = 5e15, res = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (calc(mid) < n)
            res = mid, l = mid + 1;
        else
            r = mid - 1;
    }
    cout << (calc(res + 1) == n ? res + 1 : -1) << '\n';

    return 0;
}