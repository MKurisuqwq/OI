#include <bits/stdc++.h>
#define int long long
#define y(i) t[i].y
#define x(i) t[i].x
#define v(i) t[i].v

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MAXN = 1010, INF = 0x3f3f3f3f;
int n, x0, f[MAXN][MAXN], g[MAXN][MAXN], sum[MAXN];
struct Node {
    int x, y, v;

    bool operator<(const Node &o) const { return x < o.x; }
} t[MAXN];

int calc(int l, int r) { return sum[n] - (sum[r] - sum[l - 1]); }

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    bool flag = false;
    cin >> n >> x0;
    for (int i = 1; i <= n; i++) cin >> t[i].x, (t[i].x == x0 ? flag = true : flag);
    for (int i = 1; i <= n; i++) cin >> t[i].y;
    for (int i = 1; i <= n; i++) cin >> t[i].v;
    (!flag ? t[++n] = {x0, 0, 0} : t[n]);
    sort(t + 1, t + 1 + n), memset(f, -0x3f, sizeof(f)), memset(g, -0x3f, sizeof(g));
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + t[i].v, (t[i].x == x0 ? f[i][i] = g[i][i] = y(i) : f[i][i]);
    for (int l = 2; l <= n; l++) {
        for (int i = 1, j = i + l - 1; j <= n; i++, j++) {
            f[i][j] = y(i) + max(f[i + 1][j] - (x(i + 1) - x(i)) * calc(i + 1, j),
                                 g[i + 1][j] - (x(j) - x(i)) * calc(i + 1, j));
            g[i][j] = y(j) + max(g[i][j - 1] - (x(j) - x(j - 1)) * calc(i, j - 1),
                                 f[i][j - 1] - (x(j) - x(i)) * calc(i, j - 1));
        }
    }
    printf("%.3f\n", max(f[1][n], g[1][n]) / 1000.0);

    return 0;
}