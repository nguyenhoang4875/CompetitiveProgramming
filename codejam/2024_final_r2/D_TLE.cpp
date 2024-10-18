#include <bits/stdc++.h>
#define int long long

using namespace std;

//*** debug(x) ***//
#define DEBUG 0

#if DEBUG
#define del cout << '\n'
#define debug(x) cout << "[" << #x << "]" << " : " << (x) << endl
template <class Ch, class Tr, class Container>
basic_ostream<Ch, Tr>& operator<<(basic_ostream<Ch, Tr>& os, Container const& x) {
    os << "{ ";
    for (const auto& y : x) os << y << ", ";
    return os << "}";
}
template <class X, class Y>
ostream& operator<<(ostream& os, pair<X, Y> const& p) {
    return os << "(" << p.first << ", " << p.second << ")";
}
#else
#define del
#define debug(x)
#endif

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
const int ms = 2e5 + 5;
const int ms2 = 1e4 + 5;
int n, m;

vi D(ms), SS(ms);
vvi VC;
map<int, vi> MD;
map<int, vi> MS;
vi X(ms2), A(ms2), B(ms2), C(ms2);

pair<int, int> getDivisors(int& n) {
    pii ans = {0, 0};
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ans.F += i;
            // debug(i);
            ans.S++;
            if (i * i != n) {
                ans.F += n / i;
                // debug(n / i);
                ans.S++;
            };
        }
    }
    return ans;
}
void init() {
    for (int val = 0; val < ms; val++) {
        pii ret = getDivisors(val);
        int sum = ret.F, cnt = ret.S;

        D[val] = cnt;
        MD[cnt].pb(val);
        // VC.push_back({val, })
        SS[val] = sum;
        MS[sum].push_back(val);
    }
}

void solve() {
    cin >> n >> m;
    while (m--) {
        int x, a, b, c;
        cin >> x >> a >> b >> c;
        // cout << x << " " << a << " " << b << " " << c << el;
        int cnt = D[x];
        debug(D[x]);
        debug(SS[x]);

        int ret = 0;
        int minCnt = max(1LL, cnt - b);
        int maxCnt = cnt + b;
        debug(minCnt);
        debug(maxCnt);
        for (int i = minCnt; i <= maxCnt; i++) {
            for (auto y : MD[i]) {
                if (y > n) continue;
                if (abs(x - y) > a) continue;
                if (abs(SS[x] - SS[y]) > c) continue;
                debug(y);
                debug(D[y]);
                debug(SS[y]);
                ret++;
            }
        }
        del;
        cout << ret << " ";
    }
    cout << el;
    del;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init();

    int tcs = 1;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}