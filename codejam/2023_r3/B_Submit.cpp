#include <bits/stdc++.h>
#define int long long

using namespace std;

const int INF = 1000000000 + 5;
const int N = 2e5 + 5;
const int M = 1e6 + 5;
const int oo = 1ll << 60;
const int mod = 998244353;

int f, w, l, n;

struct Point {
    int x, y, z;
};

vector<Point> a;

int crossFloor(int a, int b) {
    if (a < b)
        return 2 * (b - a);
    else
        return a - b;
}

int getTime(Point a, Point b) {
    if (a.z == b.z) {
        return abs(a.x - b.x) + abs(a.y - b.y);
    }
    int edgeX[] = {1, 1, w, w};
    int edgeY[] = {1, l, 1, l};

    int ret = INF;

    for (int i = 0; i < 4; ++i) {
        int aToEdge = abs(a.x - edgeX[i]) + abs(a.y - edgeY[i]);
        int bToEdge = abs(b.x - edgeX[i]) + abs(b.y - edgeY[i]);
        ret = min(ret, aToEdge + crossFloor(a.z, b.z) + bToEdge);
    }
    return ret;
}

void solve() {
    cin >> f >> w >> l >> n;
    ++n;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].z >> a[i].x >> a[i].y;
    }
    vector<vector<int>> dp((1 << n), vector<int>(n, INF));
    dp[1][0] = 0;
    for (int mask = 2; mask < (1 << n); ++mask) {
        if((mask & 1) == 0) continue;
        for (int cur = 1; cur < n; ++cur) {
            if ((mask >> cur) & 1) {
                for (int from = 0; from < n; ++from) {
                    if ((mask >> from) & 1 && from != cur && dp[mask ^ (1 << cur)][from] != INF) {
                        dp[mask][cur] =
                            min(dp[mask][cur], dp[mask ^ (1 << cur)][from] +
                                                   getTime(a[from], a[cur]));
                    }
                }
            }
        }
    }
    int ret = INF;
    for (int i = 1; i < n; ++i) {
        ret = min(ret, dp[(1 << n) - 1][i]);
    }
    cout << ret << endl;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}