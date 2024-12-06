#include <bits/stdc++.h>
#define int long long

using namespace std;

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
int n;

void solve() {
    cin >> n;
    map<char, vi> m;
    string s;
    char t;
    cin >> t;
    For(i, 1, 2 * n) {
        cin >> s;
        m[s[1]].pb(s[0] - '0');
    }
    for (auto& [f, s] : m) sort(all(s));
    int cnt = 0;
    for (auto& [f, s] : m) {
        if (f == t) continue;
        cnt += s.size() & 1;
    }
    if (cnt > m[t].size()) {
        cout << "IMPOSSIBLE" << el;
        return;
    }
    for (auto& [f, s] : m) {
        if (f == t) continue;
        if (s.size() & 1) {
            cout << s.back() << f << " " << m[t].back() << "" << t << el;
            s.pop_back();
            m[t].pop_back();
        }
    }

    for (auto& [f, s] : m) {
        for (int i = 0; i < s.size(); i += 2) {
            cout << s[i] << f << " " << s[i + 1] << "" << f << el;
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs = 1;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}