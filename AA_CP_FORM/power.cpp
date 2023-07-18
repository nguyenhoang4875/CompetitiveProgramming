#include <bits/stdc++.h>
#define int long long

using namespace std;

int a, n;

// faster than recursion(fastest way!!!)
int fastPower(int a, int n) {
    int ans = 1;
    while (n > 0) {
        if (n & 1) ans *= a;
        n >>=  1; // n = n / 2
        a *= a;
    }
    return ans;
}

int power(int a, int n) {
    if(n == 0) return 1; // base case
    return a * power(a, n-1); // rec case
}

// slower than iterator 
vector<int> memo;
int fastPowerRec(int a, int n) {
    if(n == 0) return 1; // base case
    // rec case
    if(memo[n] != -1) return memo[n];
    int ans = fastPowerRec(a, n/2) * fastPowerRec(a, n/2);
    if(n & 1) ans *= a;
    return memo[n] = ans;
}

void solve() {
    cin >> a >> n;
    cout << fastPower(a, n) << endl;
    cout << power(a, n) << endl;
    memo.resize(n + 1, -1);
    cout << fastPowerRec(a, n) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}