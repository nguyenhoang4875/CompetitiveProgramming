#include <bits/stdc++.h>
#define int long long

using namespace std;

int cnt;
vector<int> memo;
int fib(int n) {
    cnt++;
    if(n <= 2) return 1;
    // memoisation part
    if(memo[n] != -1) return memo[n];
    // recursion relation
    return memo[n] = fib(n - 1) + fib(n - 2);
}

int fibTab(int n) {
    int memo[n + 1] = {0};
    memo[1] = memo[2] = 1;
    for(int i = 3; i <= n; i++) {
        memo[i] = memo[i -1] + memo[i - 2];
    }
    return memo[n];
}

void solve() {
    int n;
    cin >> n;
    memo.resize(n + 1, -1);
    cout << fib(n) << endl;
    cout << "cnt = " << cnt << endl;
    cout << fibTab(n) << endl;


}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}