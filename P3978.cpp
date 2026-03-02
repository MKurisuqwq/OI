#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

ld n;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    printf("%.10Lf", n * (n + 1) / (2 * (2 * n - 1)));

    return 0;
}