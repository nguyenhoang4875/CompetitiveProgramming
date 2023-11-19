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
const int ms = 1e5 + 5;
int n, m;
string s, t;

bool isGood(string s) {
    int n = sz(s);
    For(i, 0, n - 2) {
        if(s[i] == s[i+ 1]) return false;
    }
    return true;
}

void solve() {
    cin >> n >> m;
    cin >> s >> t;
    if(isGood(s)) {
        cout << "Yes\n";
        return;
    }
    if(!isGood(t)) {
        cout << "No\n";
        return;
    }
    int sSize = sz(s);
    int tSize = sz(t);
    string sGood = "";
    for(int i = 0; i <= sSize - 2; i++) {
        if(s[i] == s[i+1]) {
            if(s[i] == t[0] or s[i + 1] == t[tSize - 1]) {
                cout << "No\n";
                return;
            } else {
                s.insert(i + 1, t);
                sSize = sz(s);
                i += tSize;
                i -= 2;
            }
        }
    }
    cout << "Yes\n";

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