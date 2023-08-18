#include <bits/stdc++.h>

using namespace std;

/**
 * Problem: https://codeforces.com/problemset/problem/264/B
 * Solution: DP
 *  - Find all prime divisor number for each ai
 *  - Count the max value for each ai
 *  - Accumulate the max value for each prime number
 *  - Give the max accumulate of prime numbers
 *
 * TC: O(n * sqrt(n))
 * MC: O(n)
 */

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
#define int long long
#define pb push_back
#define FOR(_i, _a, _b) for (int _i = (_a); _i < (_b); _i++)
#define FORI(_i, _a, _b) for (int _i = (_a); _i <= (_b); _i++)
#define FORE(it, x) for (auto it = x.begin(); it != x.end(); ++it)

//*** custom using ***//
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;

//*** START CODING ***//

const int MS = 1e5 + 5;  // max size

int n;
int a[MS];
int dpPrime[MS];

// O(n * n) => TLE
void dpBruteForce() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    vi dp(n + 1, 1);

    int ans = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (__gcd(a[i], a[j]) > 1) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << '\n';
}

// O(sqrt(n))
vector<int> givePrimeDivisor(int n) {
    vi div;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            div.pb(i);
            while (n % i == 0) n /= i;
        }
    }
    if (n > 1) div.pb(n);
    return div;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    if (n == 1) {
        cout << "1\n";
        return;
    }
    vi dp(n + 1, 1);

    for (int i = 1; i <= n; i++) {
        vi primeDiv = givePrimeDivisor(a[i]);
        int bestEnding = 0;

        for (auto x : primeDiv) {
            // find the best ending for all prime divisor of a[i]
            bestEnding = max(bestEnding, dpPrime[x]);
        }

        for (auto x : primeDiv) {
            // set all prime divisor of a[i] = bestEnding + 1 (added a[i])
            dpPrime[x] = bestEnding + 1;
        }
    }

    int ans = *max_element(dpPrime + 1, dpPrime + MS + 1);
    cout << ans << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}