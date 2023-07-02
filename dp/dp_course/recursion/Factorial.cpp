#include <bits/stdc++.h>
#define int long long

using namespace std;

int n;

int fact(int n) {
    if(n == 0) return 1; // base case
    return n * fact(n -1); // recursion case
}

void solve() {
    cin >> n;
    cout << fact(n) << endl;

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}