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

int max1dRangeProduct(vector<int>& a) {
    int n = a.size();
    int cur_min = a[0], cur_max = a[0];  // min, max end at i-th
    int ans = a[0];

    for (int i = 1; i < n; i++) {
        int x = a[i];
        if (x < 0) swap(cur_min, cur_max);
        cur_max = max(x, cur_max * x);
        cur_min = min(x, cur_min * x);
        ans = max(ans, cur_max);
    }
    return ans;
}

void solve() {
    int x;
    vi a;
    while (cin >> x) {
        if (x == -999999) {
            cout << max1dRangeProduct(a) << el;
            a.clear();
        } else {
            a.pb(x);
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}