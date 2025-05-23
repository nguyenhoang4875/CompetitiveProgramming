#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * https://codeforces.com/problemset/problem/1096/D
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
    long long p, n, i;
    string s;
    cin >> n >> s;
    int a, b, c, d;
    a = b = c = d = 0;
    for (i = 0; i < n; i++) {
        cin >> p;
        if (s[i] == 'h') a += p;
        if (s[i] == 'a') b = min(a, b + p);
        if (s[i] == 'r') c = min(b, c + p);
        if (s[i] == 'd') d = min(c, d + p);
    }
    cout << d << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}