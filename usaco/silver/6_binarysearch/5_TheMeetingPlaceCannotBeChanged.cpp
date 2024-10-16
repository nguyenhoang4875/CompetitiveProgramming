#include <bits/stdc++.h>
#define int long long

using namespace std;

//*** define ***//
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(i, a, b) for (int i = (a); i <= (int)(b); i++)
#define Rof(i, a, b) for (int i = (a); i >= (int)(b); i--)
#define Fore(it, x) for (auto it = (x).begin(); it != (x).end(); ++it)

//*** custom using ***//
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
const int ms = 6e4 + 5;
int n;
int x[ms], v[ms];
double e = 1e-7;

void solve() {
    cin >> n;
    For(i, 1, n) cin >> x[i];
    For(i, 1, n) cin >> v[i];

    auto check = [&](double t) {
        double l = 0, r = 1e9;
        For(i, 1, n) {
            double tl = x[i] - v[i] * t;
            double tr = x[i] + v[i] * t;
            if (tl > r) return false;
            if (tr < l) return false;
            l = max(tl, l);
            r = min(tr, r);
        }
        return l <= r;
    };

    double l = 0, r = 1e9;
    double ans = 1e9;
    while (r - l > e) {
        double mid = (l + r) / 2;
        if (check(mid)) {
            ans = mid;
            r = mid - e;
        } else
            l = mid + e;
    }
    cout << fixed << setprecision(6);
    cout << ans << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}