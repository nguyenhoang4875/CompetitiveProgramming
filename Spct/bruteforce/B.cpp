#include <bits/stdc++.h>
#define int long long

using namespace std;

int tcs, n;
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int sumDigit(int n) {
    int sum = 0;
    while(n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

bool isValid(int n) {
    int sum = sumDigit(n);
    return gcd(n, sum) > 1;
}

void solve() {
    cin >> n;
    while(!isValid(n))n++;
    cout << n << '\n';

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