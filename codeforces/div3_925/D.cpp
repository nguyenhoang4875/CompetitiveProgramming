#include <bits/stdc++.h>
#define int long long

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(i, a, b) for (int i = a; i <= (int)b; i++)
#define Ford(i, a, b) for (int i = a; i >= (int)b; i--)
#define Fore(it, x) for (auto it = x.begin(); it != x.end(); ++it)

using vb = vector<bool>;
using vvb = vector<vb>;
using vc = vector<char>;
using vvc = vector<vc>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;

//*** debug(x) ***//
#if 1
#define debug(x)             \
    cout << "[" << #x << "]" \
         << " : " << (x) << endl

template <class Ch, class Tr, class Container>
basic_ostream<Ch, Tr>& operator<<(basic_ostream<Ch, Tr>& os,
                                  Container const& x) {
    os << "{ ";
    for (auto& y : x) os << y << ", ";
    return os << "}";
}

template <class X, class Y>
ostream& operator<<(ostream& os, pair<X, Y> const& p) {
    return os << "(" << p.first << ", " << p.second << ")";
}

template <typename T>
void check_here(T x) {
    cout << "------------- " << x << " -------------" << endl;
}
#endif

//*** START CODING ***//

const int oo = 1e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;
int n, x, y, tmp;
int mx[ms], my[ms];
map<int, vi> mp;

int nC2(int n) { return n * (n - 1) / 2; }

void solve() {
    cin >> n >> x >> y;
    mp.clear();

    For(i, 1, n) {
        cin >> tmp;
        int tx = tmp % x;
        int ty = tmp % y;
        mx[i] = tx;
        my[i] = ty;
        mp[ty].pb(i);
    }
    int cnt = 0;

    // For(i, 1, n) { cout << mx[i] << " "; }
    // cout << el;
    // For(i, 1, n) { cout << my[i] << " "; }
    // cout << el;

    for (auto e : mp) {
        if (e.S.size() == 1) continue;
        map<int, vi> mxx;
        for (auto i : e.S) {
            mxx[mx[i]].pb(i);
        }
        for (auto t : mxx) {
            if (t.F == 0) {
                // debug(sz(t.S));
                cnt += 2 * nC2(sz(t.S));
                continue;
            }
            int val = x - t.F;
            if (mxx.count(val)) {
                // debug(sz(mxx[val]));
                if (val == t.F)
                    cnt += 2 * nC2(sz(t.S));
                else
                    cnt += sz(t.S) * sz(mxx[val]);
            }
        }
    }
    cout << cnt / 2 << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}