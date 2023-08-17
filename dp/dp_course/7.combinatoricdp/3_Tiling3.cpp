#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;
/**
 * Problem: Given a '2 x n' board and tiles size of '2 x 1' and 'L-shape', count
 * the number of ways to tile the given board using '2 x 1' tiles. A tile can be
 * placed horizontally or vertically.
 *
 * Solution: same with fibonacci
 *  f(n) number of way to tile 2 x n boards with 2 x 1 tiles
 *  g(n) number of way to tile 2 x n boards with one additional square (1st or 2nd row)
 *
 *  f(n) = f(n - 1) + f(n - 2) + 2 * g(n - 2)
 *  g(n) = g(n - 1) + f(n - 1)
 *
 * Base case:
 * f(0) = 0, f(1) = 1, f(2) = 2, g(0) = 0, g(1) = 1, g(2) = 2
 *
 * TC: O(n)
 * MC: O(n)
 *
 */

using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;

//*** START CODING ***//

int tcs, n;

void solve() {
    int n;
    cin >> n;
    vector<int> f(n + 1, 0);
    vector<int> g(n + 1, 0);
    for (int i = 0; i <= 2; i++) {
        f[i] = g[i] = i;
    }
    for (int i = 3; i <= n; i++) {
        f[i] = f[i - 1] + f[i - 2] + 2 * g[i - 2];
        g[i] = g[i - 1] + f[i - 1];
    }
    cout << f[n];
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}