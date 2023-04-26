#include <bits/stdc++.h>
#define int long long

using namespace std;

int tcs, n;

string decToBaseK(int n, int  k)  {
    string ans = "";
    if(n == 0) {
        ans = "0";
    } else {
        while (n != 0) {
            int digit = n % k;
            ans = to_string(digit) + ans;
            n /= k;
        }
    }
    return ans;
}

void solve() {
    cin >> n;
    string s = decToBaseK(n, 9);
    for (char c: s) {
        if(c > '3') {
            int k = c - '0';
            cout << k + 1; 
        } else {
            cout << c;
        }
    }
    cout << endl;
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