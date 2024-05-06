#include <bits/stdc++.h>
#define int long long

using namespace std;
//*** debug(x) ***//
#define DEBUG 1

#if DEBUG
#define del cout << '\n'
#define debug(x)             \
    cout << "[" << #x << "]" \
         << " : " << (x) << endl
template <class Ch, class Tr, class Container>
basic_ostream<Ch, Tr>& operator<<(basic_ostream<Ch, Tr>& os, Container const& x) {
    os << "{ ";
    for (auto& y : x) os << y << ", ";
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

//*** START CODING ***//

const int oo = 2e18, mod = 1e9 + 7;
const int ms = 2500 + 5;
int n;
int pSum[ms][ms];
pii p[ms];

bool yCmp(pii p1, pii p2) { return p1.S < p2.S; }

int rSum(int x1, int y1, int x2, int y2) {
    return pSum[x2 + 1][y2 + 1] - pSum[x1][y2 + 1] - pSum[x2 + 1][y1] + pSum[x1][y1];
}

void solve() {
    cin >> n;
    int x, y;
    For(i, 0, n - 1) {
        cin >> x >> y;
        p[i] = {x, y};
    }

    sort(p, p + n);
    For(i, 0, n - 1) p[i].F = i + 1;

    sort(p, p + n, yCmp);
    For(i, 0, n - 1) p[i].S = i + 1;

    For(i, 0, n - 1) pSum[p[i].F][p[i].S] = 1;

    For(i, 1, n) {
        For(j, 1, n) { pSum[i][j] += pSum[i - 1][j] + pSum[i][j - 1] - pSum[i - 1][j - 1]; }
    }

    int ans = 0;
    For(i, 0, n - 1) {
        For(j, i, n - 1) {
            int x1 = min(p[i].F, p[j].F) - 1;
            int x2 = max(p[i].F, p[j].F) - 1;
            ans += rSum(0, i, x1, j) * rSum(x2, i, n - 1, j);
        }
    }
    ans += 1;
    cout << ans << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}