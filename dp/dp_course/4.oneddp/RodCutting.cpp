#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Give a rod of length n and array prices length n
 * denoting the cost of pieces of rod of length 1 to n.
 * Find the maximum amount that can be made if the rod cut up optimally.
 * 
*/

int memo[100005];

int rodCutting(int n, int prices[]) {
    if(n == 0) return 0;

    if(memo[n] != -1) return memo[n];

    // O(n) extra work inside each state
    int ans = 0;
    for(int i = 1; i <= n ; i++) {
        ans = max(ans, prices[i] + rodCutting(n - i, prices));
    }

    return memo[n] = ans;

}

void solve() {
    int n;
    cin >> n;
    int prices[n + 5];
    memset(memo, -1, (n + 5) * sizeof(int));
    for(int i = 1; i <= n; i++) {
        cin >> prices[i];
    }
    cout << rodCutting(n, prices) << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}