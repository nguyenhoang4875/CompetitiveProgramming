#include <bits/stdc++.h>
#define int long long

using namespace std;
int a, b;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
void solve() {
    cin >> a >> b;
    cout << a / gcd(a, b)  * b;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}