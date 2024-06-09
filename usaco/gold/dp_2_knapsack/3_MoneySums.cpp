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
#define Rof(i, a, b) for (int i = a; i >= (int)b; i--)
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

const int oo = 2e18, mod = 1e9 + 7;
const int ms = 1e5;
int n;

void solve() {
    cin >> n;
    vi a(n);
    int total = 0;
    for (auto &x : a) {
        cin >> x;
        total += x;
    }

    vi f(ms + 5, 0);
    f[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = total; j >= 0; j--) {
            if (j >= a[i]) {
                f[j] |= f[j - a[i]];
            }
        }
    }
    vi ans;
    for (int i = 1; i <= total; i++) {
        if (f[i]) ans.pb(i);
    }
    cout << ans.size() << el;
    for (auto e : ans) {
        cout << e << " ";
    }
    cout << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}