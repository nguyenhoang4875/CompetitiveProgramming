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
    while (true) {
        int n;
        if (!(cin >> n)) return;
        vi a(n);
        Rep(i, n) cin >> a[i];

        auto getLis = [&]() {
            vii l(n);
            vi lis = {a[0]};
            l[0] = {1, a[0]};

            for (int i = 1; i < n; i++) {
                int x = a[i];
                if (lis.back() < x) {
                    lis.pb(x);
                    l[i] = {lis.size(), a[i]};
                } else {
                    int pos = lower_bound(all(lis), x) - lis.begin();
                    lis[pos] = x;
                    if (pos == sz(lis) - 1) l[i] = {sz(lis), a[i]};
                }
            }
            return l;
        };
        vii l = getLis();
        reverse(all(a));

        vii r = getLis();
        reverse(all(r));
        int ans = 0;
        Rep(i, n) {
            if (l[i].S == l[i].S) {
                int mn = min(l[i].F, r[i].F);
                int val = 2 * mn - 1;
                ans = max(ans, val);
            }
        }
        cout << ans << el;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}