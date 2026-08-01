#include <bits/stdc++.h>
#define int long long

using namespace std;

#define pb push_back
#define LSOne(x) ((x) & -(x))
#define all(x) (x).begin(), (x).end()
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
    int n, k;
    cin >> n >> k;
    vi a(n);
    Rep(i, n) cin >> a[i];
    vi rm(n);

    int ans = oo;
    Rep(t, k) {
        vi b = a;
        int need_rm = t;

        Rep(x, k) {
            if ((b[0] + x) % k == need_rm) {
                b[0] += x;
                break;
            }
        }

        For(i, 1, n - 1) {
            need_rm = (need_rm + 1) % k;
            if (b[i] <= b[i - 1]) {
                b[i] = b[i - 1] + 1;
                continue;
            }
            Rep(x, k) {
                if ((b[i] + x) % k == need_rm) {
                    b[i] += x;
                    break;
                }
            }
        }
        int sum = 0;
        Rep(i, n) sum += b[i] - a[i];
        ans = min(ans, sum);
    }
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