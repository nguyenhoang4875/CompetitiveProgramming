#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: https://www.spoj.com/problems/M3TILE/
 * Solution:
 *  Using dp:
 *   f(i) number of ways 3xn board
 *   g(i) number of ways 3xn board with 2 extra squares on top
 *   f[0] = g[0] = 1;
 *   f[1] = g[1] = 0;
 *
 *    f[i] = f[i - 2] + 2 * g[i - 2];
 *    g[i] = f[i] + g[i - 2];
 *
 *  TC: O(n)
 *  MC: O(n)
 */

int tcs, n;

void solve() {
    while (true) {
        cin >> n;
        if (n == -1) return;
        vector<int> f(n + 1, 0);
        vector<int> g(n + 1, 0);
        f[0] = g[0] = 1;
        f[1] = g[1] = 0;
        for (int i = 2; i <= n; i++) {
            f[i] = f[i - 2] + 2 * g[i - 2];
            g[i] = f[i] + g[i - 2];
        }
        cout << f[n] << endl;
    }
}
void solve2() {
    while (true) {
        cin >> n;
        if (n == -1) return;
        vector<int> f(n + 1, 0);
        f[0] = 1;
        f[1] = 0;
        f[2] = 3;
        f[3] = 0;

        for (int i = 4; i <= n; i++) {
            f[i] = 4 * f[i - 2] - f[i - 4];
        }
        // for(int i = 1; i <= n; i++) cout << f[i] << " ";
        cout << f[n] << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}