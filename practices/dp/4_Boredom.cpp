#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * https://codeforces.com/contest/455/problem/A
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
const int ms = 1e5;

void solve() {
    int n;
    cin >> n;
    vi cnt(ms + 1);
    For(i, 1, n) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    vi f(ms + 1, 0);
    f[0] = cnt[0];
    f[1] = cnt[1];
    For(i, 2, ms) { f[i] = max(f[i - 1], f[i - 2] + cnt[i] * i); }
    cout << f[ms] << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}