#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;
/**
 * Bit Manipulations
 */

int n;

int setBit(int n, int pos) { return n |= (1 << pos); }
int clearBit(int n, int pos) { return n &= ~(1 << pos); }
int getBit(int n, int pos) { return (n >> pos) & 1; }
int toggleBit(int n, int pos) { return n ^= (1 << pos); }

void solve() {
    int n = 9;                        // 1001
    cout << getBit(n, 3) << '\n';     // 1
    cout << setBit(n, 2) << '\n';     // 1101: 13
    cout << setBit(n, 1) << '\n';     // 1011: 11
    cout << clearBit(n, 3) << '\n';   // 0001: 1
    cout << toggleBit(n, 2) << '\n';  // 1101: 13
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}