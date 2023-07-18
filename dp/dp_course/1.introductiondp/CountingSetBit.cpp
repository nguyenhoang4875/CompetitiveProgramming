#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Print number of set bits for each number from 1 to n?
 * 
 * Time: O(n)
 * Space: O(n)
 * 
*/
vector<int> memo;
int fun(int n) {
    if(n == 1) return 1;
    if(memo[n] != -1) return memo[n];
    return memo[n] = fun(n / 2) + (n & 1); // n & 1 same with n % 2

}

void solve() {
    int n;
    cin >> n;
    memo.resize(n + 1, -1);
    memo[0] = 0;

    for(int i = 1; i <= n; i++) {
        memo[i] = memo[i / 2] + (i % 2);
        cout << memo[i] << endl;
    }

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}