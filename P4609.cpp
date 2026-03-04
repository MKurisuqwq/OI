#include <bits/stdc++.h>
#define int long long

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MAXN = 5e4 + 10, MAXA = 210, mod = 1e9 + 7;
int T, n, a, b, C[MAXA][MAXA], S[MAXN][MAXA];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> T;
    C[0][0] = S[0][0] = 1;
    for (int i = 1; i < MAXA; i++) {
        C[i][0] = 1;
        for (int j = 1; j < MAXA; j++) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
    }
    for (int i = 1; i < MAXN; i++)
        for (int j = 1; j < MAXA; j++) S[i][j] = (S[i - 1][j - 1] + (i - 1) * S[i - 1][j] % mod) % mod;
    while (T-- > 0) {
        cin >> n >> a >> b;
        cout << S[n - 1][a + b - 2] * C[a + b - 2][a - 1] % mod << '\n';
    }

    return 0;
}