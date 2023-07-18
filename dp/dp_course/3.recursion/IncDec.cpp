#include <bits/stdc++.h>
#define int long long

using namespace std;

void dec(int n) {
    if(n == 0) return; // base case
    // rec case
    cout << n << " ";
    dec(n -1);
}

void inc(int n) {
    if(n == 0) return; // base case
    // rec case
    inc(n -1);
    cout << n << " ";
}

void solve() {
    int n;
    cin >> n;
    dec(n);
    cout << endl;
    inc(n);
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}