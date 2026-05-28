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

int polyHash(const string& s) {
    const int p = 31, mod = 1000000007;
    int h = 0, pw = 1;

    for (int i = 0; i < (int)s.size(); i++) {
        int c = s[i] - 'a' + 1;  // lowercase only
        h = (h + c * pw) % mod;
        pw = pw * p % mod;
    }
    return h;
}

pair<int, int> doubleHash(const string& s) {
    const int p1 = 131, mod1 = 1000000007;
    const int p2 = 137, mod2 = 1000000009;
    int h1 = 0, h2 = 0;
    int pw1 = 1, pw2 = 1;

    for (int i = 0; i < (int)s.size(); i++) {
        int c = s[i] + 1;  // works for any ASCII character
        h1 = (h1 + c * pw1) % mod1;
        h2 = (h2 + c * pw2) % mod2;
        pw1 = pw1 * p1 % mod1;
        pw2 = pw2 * p2 % mod2;
    }
    return {h1, h2};
}

void solve() {
    string s = "poly hash";
    cout << polyHash(s) << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}