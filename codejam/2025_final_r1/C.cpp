#include <bits/stdc++.h>
#define int long long

using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define all1(x) (x).begin() + 1, (x).end()
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
    int n, k;
    cin >> n >> k;
    vi a(n + 1);
    For(i, 1, n) cin >> a[i];

    vi ps(n + 1);
    For(i, 1, n) ps[i] = ps[i - 1] + a[i] * a[i];

    vi ps1(n + 1);
    For(i, 1, n) ps1[i] = ps1[i - 1] + a[i];

    auto check = [&](double v) {
        set<double> st;
        double mn = 0;
        ;
        For(i, k, n) {
            double tmp = ps[i] - v * ps1[i] - mn;
            if (tmp >= 0) return true;
            mn = min(mn, (ps[i - k + 1] - v * ps1[i - k + 1]));
        }
        return false;
    };

    double eps = 1e-6;
    double l = 1, r = 1e7;
    double ans = 1;
    while (l + eps < r) {
        double mid = (l + r) / 2;
        if (check(mid)) {
            ans = mid;
            l = mid + eps;
        } else {
            r = mid - eps;
        }
    }

    cout << fixed << setprecision(8);
    cout << ans << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}