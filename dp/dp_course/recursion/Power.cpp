#include <bits/stdc++.h>
#define int long long

using namespace std;

int a, n;

int power(int a, int n) {
    if(n == 0) return 1; // base case
    return a * power(a, n-1); // rec case
}

int fastPower(int a, int n) {
    if(n == 0) return 1; // base case
    // rec case
    int ans = fastPower(a, n/2) * fastPower(a, n/2);
    if(n & 1) ans *= a;
    return ans;
}

void solve() {
    cin >> a >> n;
    cout << power(a, n) << endl;
    cout << fastPower(a, n) << endl;
    

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}