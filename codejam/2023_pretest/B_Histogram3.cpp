#include <bits/stdc++.h>
#define int long long

using namespace std;

//*** debug(x) ***//
#define debug(x)             \
    cout << "[" << #x << "]" \
         << " : " << (x) << endl

#if 1
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
#endif

template <typename T>
void check_here(T x) {
    cout << "------------- " << x << " -------------" << endl;
}

//*** define ***//
#define pb push_back
#define all(x) x.begin(), x.end()
#define F first
#define S second
#define For(_i, _a, _b) for (int _i = (_a); _i <= (_b); _i++)
#define Ford(_i, _a, _b) for (int _i = (_a); _i >= (_b); _i--)
#define Fore(it, x) for (auto it = x.begin(); it != x.end(); ++it)

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

const int oo = 1e18, mod = 1e9 + 7;
const int ms = 1e5 + 5;
int n;
vi a;

int getBit(int mask, int pos) { return (mask >> pos) & 1; }

int setBit(int mask, int pos) { return mask |= (1 << pos); }

int clearBit(int mask, int pos) { return mask &= ~(1 << pos); }

void solve() {
    cin >> n;
    a.clear();
    a.resize(n + 1);
    For(i, 0, n - 1) cin >> a[i];

    // dp[i][j] perimeter at mask = i and last visited j
    int max_mask = (1 << n) - 1;
    vvi dp((1 << n) + 1, vi(n + 1, 0));
    vvi count((1 << n) + 1, vi(n + 1, 0));
    For(i, 0, n - 1) { dp[1 << i][i] = a[i]; }
    for (int mask = 1; mask <= max_mask; mask++) {
        for (int cur = 0; cur <= n - 1; cur++) {
            count[mask][cur] = 1;
            if (getBit(mask, cur)) {
                for (int from = 0; from <= n - 1; from++) {
                    if (getBit(mask, from) && from != cur) {
                        int pre_mask = clearBit(mask, cur);
                        int temp = dp[pre_mask][from] + abs(a[from] - a[cur]);
                        if (temp > dp[mask][cur]) {
                            dp[mask][cur] = temp;
                            count[mask][cur] = count[pre_mask][from];
                        } else if (temp == dp[mask][cur]) {
                            count[mask][cur] += count[pre_mask][from];
                        }
                    }
                }
            }
        }
    }

    int ans = 0;
    int cnt = 0;
    For(i, 0, n - 1) {
        int temp = dp[max_mask][i] + 2 * n + a[i];
        if (temp > ans) {
            ans = temp;
            cnt = count[max_mask][i];
        } else if (temp == ans) {
            cnt += count[max_mask][i];
        }
    }

    cout << ans << ' ' << cnt << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}