#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: https://codeforces.com/problemset/problem/977/F
 * Solution: DP
 *  f(i) ->  best ending for number i
 *  f(i) = f(i - 1) + 1
 *
 *  - find max of f(i)
 *
 * TC: O(n)
 * MC: O(2 * n)
 *
 *
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
const int ms = 2e5 + 5;

void solve() {
    int n;
    cin >> n;
    map<int, int> f;
    vi a(n + 1);
    For(i, 1, n) cin >> a[i];
    For(i, 1, n) { f[a[i]] = f[a[i] - 1] + 1; }
    int mx = 0;
    int end = 0;
    for (auto &[f, s] : f) {
        if (s > mx) {
            mx = s;
            end = f;
        }
    }
    cout << mx << el;
    int start = end - mx + 1;
    For(i, 1, n) {
        if (start > end) break;
        if (a[i] == start) {
            cout << i << " ";
            start++;
        }
    }
    cout << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}