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
    int n, h;
    cin >> n >> h;
    vi a, b;
    a.reserve(n / 2 + 1);
    b.reserve(n / 2 + 1);
    Rep(i, n) {
        int x;
        cin >> x;
        if (i & 1) b.pb(x);
        else a.pb(x);
    }
    sort(all(a));
    sort(all(b));

    auto getVal = [&](vi& a, int l) {
        return a.end() - lower_bound(all(a), l);
    };

    vi best;
    int num = n;
    For(l, 1, h) {
        int ca = getVal(a, l);
        int cb = getVal(b, h - l + 1);
        if (ca + cb < num) {
            num = ca + cb;
            best.clear();
            best.pb(l);
        } else if (ca + cb == num) {
            best.pb(l);
        }
    }
    cout << num << " " << best.size() << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}