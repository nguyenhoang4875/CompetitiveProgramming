#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;
/**
 * Bit Manipulations
 */

int n;

void setBit(int n, int pos) { n | (1 << pos); }

void clearBit(int n, int pos) { n &= ~(1 << pos); }

int getBit(int n, int pos) { return (n >> pos) & 1; }

void toggleBit() { n ^= 1 << n; }

void solve() {
    string s = "abc";
    int n = s.size();

    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            if ((i >> j) & 1) {
                cout << s[j];
            }
        }
        cout << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}