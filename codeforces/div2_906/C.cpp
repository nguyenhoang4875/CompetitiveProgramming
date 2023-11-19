#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: https://codeforces.com/contest/1890/problem/C
 * Solution: Brute force
 *  - if s[0] != s[n - 1] remove s[0] and s[n - 1]
 *  - else :
 *      - if s[0] == s[n - 1] and s[0] == '0' add "01" in the end of s
 *      - if s[0] == s[n - 1] and s[0] == '1' add "01" in the begin of s
 * 
 * TC: O(n)
 * MC: O(n)
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
const int ms = 1e5 + 5;
int n;
string s;

void solve() {
    cin >> n;
    cin >> s;
    if(n & 1) {
        cout << "-1\n";
        return;
    }

    int idx = 0;
    vi vPos;
    while(sz(s)) {
        if(s.front() == s.back()) {
            if(s.front() == '0') {
                vPos.pb(idx + sz(s));
                s += "01";
            } else {
                vPos.pb(idx);
                s.insert(0, "01");
            }
        }
        s = s.substr(1, sz(s) - 2);
        if(sz(vPos) > 300) {
            cout << "-1\n";
            return;
        }
        idx++;
    }
    cout << sz(vPos) << el;
    for(auto e: vPos) cout << e << " ";
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