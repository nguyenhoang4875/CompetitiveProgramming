#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * https://codeforces.com/gym/605682/problem/A
 */

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define all1(x) (x).begin() + 1, (x).end()
#define el '\n'
#define F first
#define S second
#define Rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
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
    int n, m, k;
    cin >> n >> m >> k;
    string ans = "";
    For(i, 1, n - 1) ans.pb('U');
    For(i, 1, m - 1) ans.pb('L');
    For(i, 1, n) {
        if (i > 1) { ans.pb('D'); }
        if (i & 1) For(i, 1, m - 1) ans.pb('R');
        else For(i, 1, m - 1) ans.pb('L');
    }
    cout << ans.size() << el;
    for (auto& e : ans) cout << e;
    cout << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs = 1;
    while (tcs--) { solve(); }
    return 0;
}