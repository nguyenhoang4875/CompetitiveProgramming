#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: https://codejam.lge.com/problem/17123
 * Solution: calculate for rows and columns
 * 
 * TC: O(n * n)
 * MC: O(n * n)
*/

#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(i, a, b) for (int i = a; i <= (int)b; i++)
#define Ford(i, a, b) for (int i = a; i >= (int)b; i--)
#define Fore(it, x) for (auto it = x.begin(); it != x.end(); ++it)

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
const int ms = 1e3 + 5;
int n, m;
int r[ms], c[ms];

void solve() {
    cin >> n >> m;
    memset(r, 0, sizeof(r));
    memset(c, 0, sizeof(c));
    For(i, 1, n) {
        For(j, 1, n) {
            int x;
            cin >> x;
            r[i] += x; // sum of row
            c[j] += x; // of of column
        }
    }

    int x, v;
    int r1, r2, c1, c2;
    For(i, 1, m) {
        cin >> r1 >> c1 >> r2 >> c2 >> v;

        x = (r2 - r1 + 1) * v;
        For(j, c1, c2) c[j] += x;
        x = (c2 - c1 + 1) * v;
        For(j, r1, r2) r[j] += x;
    }
    For(i, 1, n) cout << r[i] << " ";
    cout << el;

    For(i, 1, n) cout << c[i] << " ";
    cout << el;

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