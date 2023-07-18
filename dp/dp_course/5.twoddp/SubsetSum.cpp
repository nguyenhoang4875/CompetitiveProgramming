#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: Give a SUM and an array of non negative numbers.
 * Determine if subset of array exist with sum equals SUM
 *
 * Solution: Forward
 * f(x, y) => whether sum y can be founded by using array [x....]
 * x -> index     y -> sum
 * f(x, y):   f(x + 1, y - a[x]) or f(x + 1, y) (take or not take a[i])
 *
 * f(x, y): (0 <= x <= n - 1) (0 <= y <= sum)
 *
 * Or: Backward
 * f(x, y) => whether sum y can be founded by using array [....x]
 * x -> index     y -> sum
 * f(x, y):   f(x - 1, y - a[x]) or f(x - 1, y) (take or not take a[i])
 *
 */

int a[1005];
vector<vector<int>> memo;

// whether sum is possible from subset of
// a[......idx]
int subsetSum(int idx, int sum) {
    // base case
    // no element left for sum
    if (idx == 0) return sum == 0;
    if(memo[idx][sum] != -1) return memo[idx][sum];
    bool ans = false;
    // include a[idx] in sum
    if (sum >= a[idx]) {
        ans |= subsetSum(idx - 1, sum - a[idx]);
    }

    // exclude a[idx]
    ans |= subsetSum(idx - 1, sum);
    return memo[idx][sum] = ans;
}

void solve() {
    int sum, n;
    cin >> sum >> n;
    memo.resize(n + 1, vector<int>(sum + 1, -1));

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cout << subsetSum(n, sum) << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}