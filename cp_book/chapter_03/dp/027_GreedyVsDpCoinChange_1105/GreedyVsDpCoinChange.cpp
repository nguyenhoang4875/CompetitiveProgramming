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

const long long oo = 2e18;
const int ms = 2e5 + 5;

void solve() {
    int n;
    cin >> n;
    vi a(n);
    Rep(i, n) cin >> a[i];
    int g = a[1];
    bool ok = true;

    auto gCount = [&](int x) {
        int cnt = 0;
        Rof(i, n - 1, 0) {
            if (x >= a[i]) {
                cnt += x / a[i];
                x %= a[i];
            }
        }
        return cnt;
    };

    int mx = a[n - 1] + a[n - 2] - 1;
    vi f(mx + 1, oo);
    f[0] = 0;
    Rep(i, n) {
        For(j, a[i], mx) { f[j] = min(f[j], f[j - a[i]] + 1); }
    }
    For(i, 2, mx) {
        if (f[i] < gCount(i)) {
            cout << "non-canonical" << el;
            return;
        }
    }
    cout << "canonical" << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}