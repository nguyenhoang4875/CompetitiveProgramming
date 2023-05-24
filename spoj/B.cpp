#include <bits/stdc++.h>
#define int long long

using namespace std;

int tcs, n;

string findMultiple(int n) {
    if(n == 1) {
        return "1";
    }
    vector<string> dp(n);
    dp[1] = "1";
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int r = q.front();
        q.pop();
        if(r == 0) return dp[r];
        for (int digit : {0, 1}) {
            int newR = (10 * r + digit) % n;
            if(dp[newR].empty()) {
                q.push(newR);
                dp[newR] = dp[r] + char('0' + digit);
            }
        }
    }
   return "-1"; 
}

void solve() {
    cin >> n;
    cout << findMultiple(n) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}