#include <bits/stdc++.h>

using namespace std;
/**
 * Problem: https://codeforces.com/problemset/problem/977/F
 * Solution: DP
 *  f(i) ->  best ending for number i
 *  f(i) = f(i - 1) + 1
 *
 *  - find max of f(i)
 *
 * TC: O(n)
 * MC: O(n)
 *
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

const int MS = 2e5 + 5;
int n;
int a[MS];
unordered_map<int, int> dp;  // a[i] max = 1e9 => use unordered map

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        dp[a[i]] = dp[a[i] - 1] + 1;
    }
    int cnt = 0, start, end;
    for (auto x : dp) {
        if (cnt < x.second) {
            end = x.first;
            cnt = x.second;
        }
    }
    cout << cnt << '\n';
    start = end - cnt + 1;
    for (int i = 1; i <= n; i++) {
        if (start > end) break;
        if (a[i] == start) {
            cout << i << ' ';
            start++;
        }
    }
    cout << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}