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
string s;
set<string> ss;
string a[ms];

void solve() {
    ss.clear();
    cin >> n;
    For(i, 1, n) {
        cin >> s;
        a[i] = s;
        ss.insert(s);
    }
    For(i, 1, n) {
        int m = sz(a[i]);
        string e = a[i];
        bool found = false;
        For(l, 1, m - 1) {
            string sa = e.substr(0, l);
            string sb = e.substr(l);
            if (ss.count(sa) and ss.count(sb)) {
                found = true;
                break;
            }
        }
        if (found)
            cout << 1;
        else
            cout << 0;
    }
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