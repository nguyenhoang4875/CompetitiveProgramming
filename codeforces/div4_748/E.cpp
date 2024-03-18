#include <bits/stdc++.h>
#define int long long

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

const int oo = 1e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;
int n;

vector<string> getDiffs(string s) {
    vector<string> ans;
    string tmp = "  ";
    for (char c = 'a'; c <= 'k'; c++) {
        tmp[0] = s[0];
        tmp[1] = c;
        if (tmp != s) {
            ans.pb(tmp);
        }
    }
    for (char c = 'a'; c <= 'k'; c++) {
        tmp[0] = c;
        tmp[1] = s[1];
        if (tmp != s) {
            ans.pb(tmp);
        }
    }
    return ans;
}

void solve() {
    cin >> n;
    string s;
    map<string, int> m;
    For(i, 1, n) {
        cin >> s;
        m[s]++;
    }
    int ans = 0;
    for (auto e : m) {
        for (auto x : getDiffs(e.F)) {
            if (m.count(x)) {
                ans += e.S * m[x];
            }
        }
    }
    ans /= 2;
    cout << ans << el;
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