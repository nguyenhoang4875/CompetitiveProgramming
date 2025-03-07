#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * https://codeforces.com/contest/478/problem/D
 */

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(i, a, b) for (int i = (a); i <= (int)(b); i++)
#define Rof(i, a, b) for (int i = (a); i >= (int)(b); i--)
#define Fore(it, x) for (auto it = (x).begin(); it != (x).end(); ++it)

using vb = vector<bool>;
using vvb = vector<vb>;
using vc = vector<char>;
using vvc = vector<vc>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;
//*** START CODING ***//

const long long oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5;

void solve() {
    int r, g;
    cin >> r >> g;
    int h = sqrtl(2 * (r + g) + 5);
    while (h * (h + 1) > 2 * (r + g)) h--;
    vi f(r + 1);  // f[i]: number of ways to use exactly i red blocks for the current level
    f[0] = 1;
    For(i, 1, h) {
        for (int j = r; j >= i; j--) {
            f[j] = f[j] + f[j - i];
            f[j] %= mod;
        }
    }
    int ans = 0;
    For(i, 0, r) {
        if (h * (h + 1) / 2 - i <= g) {
            ans += f[i];
            ans %= mod;
        }
    }
    cout << ans << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}