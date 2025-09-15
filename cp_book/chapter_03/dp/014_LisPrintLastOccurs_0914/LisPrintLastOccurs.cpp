#include <bits/stdc++.h>
#define int long long

using namespace std;

#define pb push_back
#define LSOne(x) ((x) & -(x))
#define all(x) (x).begin(), (x).end()
#define all1(x) (x).begin() + 1, (x).end()
#define sz(x) static_cast<int>((x).size())
#define el '\n'
#define F first
#define S second
#define Rep(i, n) for (int i = 0; i < (int)n; ++i)
#define For(i, a, b) for (int i = (a); i <= (int)b; ++i)
#define Rof(i, b, a) for (int i = (b); i >= (int)a; --i)
#define Fore(i, v) for (auto i = (v).begin(); i != (v).end(); ++i)

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
    vi a;
    int x;
    while (cin >> x) a.pb(x);

    int n = a.size();
    vi f(n, oo);
    vi pos(n, -1), pre_pos(n, -1);
    int len = 0;

    for (int i = 0; i < n; i++) {
        int e = a[i];
        int idx = lower_bound(all(f), e) - f.begin();
        f[idx] = e;
        pos[idx] = i;
        if (idx > 0) pre_pos[i] = pos[idx - 1];
        if (idx + 1 > len) len = idx + 1;
    }

    vi ans;
    int last_idx = pos[len - 1];
    while (last_idx != -1) {
        ans.push_back(a[last_idx]);
        last_idx = pre_pos[last_idx];
    }
    reverse(all(ans));

    cout << len << el;
    cout << "-" << el;
    for (auto &e : ans) cout << e << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}