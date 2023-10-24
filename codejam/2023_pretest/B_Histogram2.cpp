#include <bits/stdc++.h>
#define int long long

using namespace std;

//*** debug(x) ***//
#define debug(x)             \
    cout << "[" << #x << "]" \
         << " : " << (x) << endl

#if 1
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

void setBit(int n, int pos) { n | (1 << pos); }

void clearBit(int n, int pos) { n &= ~(1 << pos); }

int getBit(int n, int pos) { return (n >> pos) & 1; }

int32_t main() {
    int n;
    while (true) {
        cin >> n;
        if (n == 0) return 0;

        int arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];

        vvi dp(1 << n, vi(n, 0));
        vvi count(1 << n, vi(n, 0));

        for (int i = 0; i < n; i++) {
            dp[0][i] = 0;
            count[0][i] = 0;
        }
        const int max_mask = (1 << n) - 1;
        for (int mask = 1; mask <= max_mask; mask++) {
            for (int cur = 0; cur < n; cur++) {
                if (mask == (1 << cur))
                    dp[mask][cur] = 2 * arr[cur] + 2;
                else
                    dp[mask][cur] = 0;
                count[mask][cur] = 1;
                if (mask & (1 << cur)) {
                    for (int from = 0; from < n; from++) {
                        if (getBit(mask, from) && (from != cur)) {
                            int pre_mask = mask ^ (1 << cur);
                            int temp = dp[pre_mask][from] +
                                       abs(arr[cur] - arr[from]) + arr[cur] -
                                       arr[from] + 2;
                            if (dp[mask][cur] < temp) {
                                dp[mask][cur] = temp;
                                count[mask][cur] = count[pre_mask][from];
                            } else if (dp[mask][cur] == temp) {
                                count[mask][cur] += count[pre_mask][from];
                            }
                        }
                    }
                }
            }
        }

        int ans = 0;
        int count_ans = 1;
        for (int i = 0; i < n; i++) {
            if (ans < dp[max_mask][i]) {
                ans = dp[max_mask][i];
                count_ans = count[max_mask][i];
            } else if (ans == dp[max_mask][i]) {
                count_ans += count[max_mask][i];
            }
        }
        cout << ans << " " << count_ans << endl;
    }
    return 0;
}