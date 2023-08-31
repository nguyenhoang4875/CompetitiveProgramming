#include <bits/stdc++.h>
using namespace std;
/**
 * Problem: https://codeforces.com/problemset/problem/1807/F
 * Solution: Brute force
 *  - number state = 4 * m * n // 4: number direction
 *
 * TC: O(4 * m * n) max(4* 2500 * 2500) = O(2.5 * 10^7) => AC
 * MC: O(4 * m * n)
 */

void solve() {
    int n, m, x1, y1, x2, y2;
    string d_string;
    cin >> n >> m >> x1 >> y1 >> x2 >> y2;
    cin >> d_string;
    // DL = 0, UL = 1, DR = 2, UR = 3
    int d = (d_string[0] == 'U' ? 1 : 0) + (d_string[1] == 'R' ? 2 : 0);
    bool vis[n + 1][m + 1][4];
    memset(vis, false, sizeof(vis));
    int i = x1, j = y1;
    int bounces = 0;
    while (!vis[i][j][d]) {
        if (i == x2 && j == y2) {
            cout << bounces << '\n';
            return;
        }
        int touchSide = 0;
        // has UP need to go Down
        if (d % 2 == 1 && i == 1) {
            d -= 1;
            touchSide++;
        }
        // has Down need to go Up
        if (d % 2 == 0 && i == n) {
            d += 1;
            touchSide++;
        }
        // has Right need to go Left
        if (d >= 2 && j == m) {
            d -= 2;
            touchSide++;
        }
        // has Left need to go Right
        if (d < 2 && j == 1) {
            d += 2;
            touchSide++;
        }
        bounces += min(1, touchSide);
        if (vis[i][j][d]) break;  // repeat visited

        vis[i][j][d] = true;

        if (d % 2 == 1)  // has Up need to go Down
            i--;
        else  // has Down need to go Up
            i++;

        if (d >= 2)  // has Right need to go Left
            j++;
        else  // has Left need to go Right
            j--;
    }
    cout << -1 << endl;
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}