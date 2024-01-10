#include <bits/stdc++.h>
#define int long long
/**
 * Problem: apptask-lset-2020-fundamentals-01
 * https://www.hackerrank.com/contests/apptask-lset-2020-fundamentals-01/challenges
 */

using namespace std;

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

const int oo = 1e18, mod = 1e5;
const int ms = 1e5 + 5;
int n;

int powerRecMod(int a, int n, int p) {
    if (n == 0) return 1;  // base case
    int ans = powerRecMod(a, n / 2, p);
    ans = (ans * ans) % p;
    if (n & 1) ans = (ans * a) % p;
    return ans;
}

void solve() {
    cin >> n;
    cout << powerRecMod(2, n, mod) - 1 << el;
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