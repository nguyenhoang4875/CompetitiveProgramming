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
int n, k;
int a[ms];

void solve() {
    cin >> n >> k;
    For(i, 1, n) {
        char x;
        cin >> x;
        a[i] = x - '0';
    }

    int c = 0;
    vi v;
    Rof(i, n, 2) {
        if (a[i] == 1)
            c++;
        else
            c--;
        if (c > 0) v.pb(c);
    }
    sort(all(v));
    int ans = 1;
    while (k > 0 and !v.empty()) {
        k -= v.back();
        v.pop_back();
        ans++;
    }
    if (k > 0) ans = -1;
    cout << ans << el;
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