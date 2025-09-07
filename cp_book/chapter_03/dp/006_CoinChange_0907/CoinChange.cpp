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

int cntWay(vector<int> &a, int t) {
    int n = a.size();
    vector<int> f(t + 1, 0);
    f[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = a[i]; j <= t; j++) {
            f[j] += f[j - a[i]];
        }
    }
    return f[t];
}

int minCoin(vector<int> &a, int t) {
    int n = a.size();
    vector<int> f(t + 1, oo);
    f[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = a[i]; j <= t; j++) {
            if (f[j - a[i]] != oo) f[j] = min(f[j], f[j - a[i]] + 1);
        }
    }
    return f[t];
}

void solve() {
    int n, t;
    cin >> n >> t;
    vi a(n);
    Rep(i, n) cin >> a[i];
    cout << cntWay(a, t) << el;
    cout << minCoin(a, t) << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}