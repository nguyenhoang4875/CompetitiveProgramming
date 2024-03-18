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

void solve() {
    cin >> n;
    string s;
    cin >> s;
    vector<string> vs;
    For(i, 0, n - 1) {
        if (s[i] == 'W') continue;
        string tmp = "";
        while (i < n and s[i] != 'W') {
            tmp += s[i];
            i++;
        }
        sort(all(tmp));
        vs.pb(tmp);
    }
    sort(all(vs), [&](string s1, string s2) { return s1.size() < s2.size(); });
    for (auto e : vs) {
        if (sz(e) == 1) {
            cout << "NO" << el;
            return;
        }
        if (e.front() == e.back()) {
            cout << "NO" << el;
            return;
        }
    }
    cout << "YES" << el;
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