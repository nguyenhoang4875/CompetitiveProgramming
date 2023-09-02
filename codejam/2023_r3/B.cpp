#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;
/**
 * Problem: https://codejam.lge.com/contest/problem/1113/2
 * Solution: Bitmask DP
 *
 * TC: O(2^n * n^2)
 * MC: O(2^n * n)
 *
 */

using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;

//*** START CODING ***//
const int oo = 1e18;
int f, w, l, n;

struct Point {
    int x, y, z;
};
vector<Point> v;

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

    // position of escalator
    int edgeX[4] = {1, 1, w, w};
    int edgeY[4] = {1, l, 1, l};

    int ret = oo;
    // brute force to choose the minDist form a, b to escalator
    for (int i = 0; i < 4; i++) {
        int aToEdge = abs(a.x - edgeX[i]) + abs(a.y - edgeY[i]);
        int bToEdge = abs(b.x - edgeX[i]) + abs(b.y - edgeY[i]);
        ret = min(ret, aToEdge + crossFloor(a.z, b.z) + bToEdge);
    }
    return ret;
}

void solve() {
    cin >> f >> w >> l >> n;

    n++;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        int z, x, y;
        cin >> z >> x >> y;
        v[i] = {x, y, z};
    }

    vvi dp((1 << n), vi(n, oo));

    // dp[i][j] // i: mark of state visited, j: last point visited;
    dp[1][0] = 0;  // mark store is visited and

    // check all state get cur come from: from -> cur
    for (int mask = 2; mask < (1 << n); ++mask) {
        if ((mask & 1) == 0) continue;

        for (int cur = 1; cur < n; cur++) {
            // check point cur is visited
            if ((mask >> cur) & 1) {
                for (int from = 0; from < n; ++from) {
                    if ((mask >> from) & 1 && from != cur &&
                        dp[mask ^ (1 << cur)][from] != oo) {
                        dp[mask][cur] =
                            min(dp[mask][cur], dp[mask ^ (1 << cur)][from] +
                                                   getTime(v[from], v[cur]));
                    }
                }
            }
        }
    }

    int ret = oo;
    for (int i = 1; i < n; i++) {
        ret = min(ret, dp[(1 << n) - 1][i]);
    }
    cout << ret << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}