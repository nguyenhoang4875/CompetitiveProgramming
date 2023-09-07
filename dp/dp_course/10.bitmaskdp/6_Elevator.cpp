#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;
/**
 * Problem: There is an elevator with maximum weight x, and n people
 * with know weights who want to get from the ground floor to the top floor.
 * What is the minimum number of rides needed if the people enter elevator
 * in an optimal order?
 * Example: n = 5, x = 10;
 * person: 0 1 2 3 4 
 * weight: 2 3 3 5 6
 * 
 * Output: 2
 * 
 * Solution: Bit Mask DP
 * f(x) -> min rides needed to used the top with x.
 * g(x) -> min weight of the last ride that took place.
 * 
 * => ans = dp[(1 << n) - 1].first
 * TC: O(2^n * n)
*/

using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;

//*** START CODING ***//

int x, n;

void solve() {
    cin >> n >> x;
    int weight[n];

    for(int i = 0; i < n; i++) {
        cin >> weight[i];
    }

    pair<int, int> dp[1 << n];
    // dp[mask].first = f[mask] = rides
    // dp[mask].second = g[mask] = weight

    dp[0] = {1, 0};

    for(int mask = 1; mask < (1 << n); mask++) {
        dp[mask] = {n, 0}; // max values, n rides with 0 person

        for(int y = 0; y < n; y++) {
            if((mask >> y) & 1) {
                int newMask = mask ^ (1 << y);
                pair<int, int> option = dp[newMask];

                // include y-th person
                // re-use current ride
                if(option.second + weight[y] <= x) {
                    option.first = option.first;
                    option.second += weight[y];
                } else {
                    // exclude the y-th person
                    // use new ride with y-th person 
                    option.first++;
                    option.second = weight[y];
                }
                dp[mask] = min(dp[mask], option);
            }
        }
    }

    cout << dp[(1 << n) - 1].first  << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}