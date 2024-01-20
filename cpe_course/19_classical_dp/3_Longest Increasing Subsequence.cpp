#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: Longest Increasing Subsequence
 *
 * TC: O(n log n) or O(n ^ 2) if use dp
 * MC: O(n)
 *
 */

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

const int oo = 1e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;
int n;

// O(n log n)
int fastLis(vector<int>& a, int n) {
    vector<int> ans;
    ans.push_back(a[0]);
    for (int i = 1; i < n; i++) {
        if (a[i] > ans.back()) {
            ans.push_back(a[i]);
        } else {
            int low = lower_bound(ans.begin(), ans.end(), a[i]) - ans.begin();
            ans[low] = a[i];
        }
    }
    return ans.size();
}

// O(n ^ 2)
int lisBottomUp(vector<int>& a, int n) {
    vector<int> dp(n + 1, 1);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (a[i] > a[j]) dp[i] = max(dp[i], 1 + dp[j]);
            ans = max(ans, dp[i]);
        }
    }
    return ans;
}

void solve() {
    cin >> n;
    vector<int> a(n);
    For(i, 0, n - 1) cin >> a[i];
    // cout << lisBottomUp(a, n) << el;
    cout << fastLis(a, n) << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}