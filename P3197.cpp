#include <bits/stdc++.h>
#define int long long

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int mod = 1e5 + 3;
int n, m;

int qpow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) (res *= a) %= mod;
        b >>= 1, (a *= a) %= mod;
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> m >> n;
    int ans = qpow(m, n) - m * qpow(m - 1, n - 1) % mod;
    cout << ((ans % mod) + mod) % mod << '\n';

    return 0;
}