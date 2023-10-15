#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;
/**
 * Problem:https://www.hackerrank.com/challenges/a-chessboard-game-1
 * Solution: DP
 * if dp(x, y) can not move to any state first player win
 * dp(x, y) = !(dp(x-1, y+1) && dp(x-2, y-1) && dp(x+1, y-2) && (dp(x-1, y-2)))
 *
 */

using vb = vector<bool>;
using vvb = vector<vb>;
using vc = vector<char>;
using vvc = vector<vc>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;

//*** START CODING ***//

const int oo = 1e18, mod = 1e9 + 7;

int memo[20][20];
bool dp(int x, int y) {
    if (x < 1 || x > 15 || y < 1 || y > 15) return true;  // out of bound
    if (memo[x][y] != -1) return memo[x][y];

    bool ans = true;
    ans &= dp(x - 2, y + 1);
    ans &= dp(x - 2, y - 1);
    ans &= dp(x + 1, y - 2);
    ans &= dp(x - 1, y - 2);
    ans = !ans;
    return memo[x][y] = ans;
}

void solve() {
    int x, y;
    cin >> x >> y;
    memset(memo, -1, sizeof(memo));
    if (dp(x, y)) {
        cout << "First\n";
    } else {
        cout << "Second\n";
    }

    for (int i = 1; i <= 15; i++) {
        for (int j = 1; j <= 15; j++) {
            cout << memo[i][j] << " ";
        }
        cout << '\n';
    }
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