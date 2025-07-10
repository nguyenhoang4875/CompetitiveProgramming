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
    vi p(n);
    Rep(i, n) cin >> p[i];
    vi d(n);
    Rep(i, n) cin >> d[i];

    auto check = [&](int pos) {
        if (pos > p[n - 1]) return true;

        int dir = 1, curTime = 0;
        set<pii> st;
        while (true) {
            auto low = lower_bound(all(p), pos);
            if (dir == 1) {
                curTime += (*low - pos);
            } else {
                if (pos != *low) {
                    --low;
                }
                curTime += (pos - *low);
            }
            pos = *low;
            curTime %= k;
            bool isRed = curTime == d[low - p.begin()];
            if (isRed) dir *= -1;
            pos += dir;
            ++curTime;
            if (pos > p[n - 1] and dir == 1) return true;
            if (pos < p[0] and dir == -1) return true;

            if (st.count({pos, curTime * dir})) return false;
            st.insert({pos, curTime * dir});
        }
        return false;
    };

    int q;
    cin >> q;
    while (q--) {
        int a;
        cin >> a;
        if (check(a)) cout << "YES" << el;
        else cout << "NO" << el;
    }
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