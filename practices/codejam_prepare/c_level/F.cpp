#include <bits/stdc++.h>
#define int long long

using namespace std;

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
    int n;
    cin >> n;
    string s;
    cin >> s;

    int l = 0, r = n - 1;
    while (l < r and s[l] == s[r]) { l++, r--; }
    if (l >= r) {
        cout << 0 << el;
        return;
    }

    auto getAns = [&](int l, int r, int c) {
        int ret = 0;
        while (l < r) {
            if (s[l] == s[r]) {
                l++, r--;
            } else if (s[l] == c) {
                ret++;
                l++;
            } else if (s[r] == c) {
                ret++;
                r--;
            } else {
                return oo;
            }
        }
        return ret;
    };
    int ans = min(getAns(l, r, s[l]), getAns(l, r, s[r]));
    if (ans == oo) ans = -1;
    cout << ans << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs = 1;
    cin >> tcs;
    while (tcs--) { solve(); }
    return 0;
}