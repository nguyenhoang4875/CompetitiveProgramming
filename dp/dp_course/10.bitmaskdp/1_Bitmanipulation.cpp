#include <bits/stdc++.h>
#define int long long
#define pb push
#define el '\n'

using namespace std;
/**
 * Bit Manipulations
 */

int setBit(int n, int pos) { return n |= (1 << pos); }
int clearBit(int n, int pos) { return n &= ~(1 << pos); }
int getBit(int n, int pos) { return (n >> pos) & 1; }
int toggleBit(int n, int pos) { return n ^= (1 << pos); }

string getBin(int n) {
    string ans = "";
    while (n) {
        if (n & 1) ans.push_back('1');
        else ans.push_back('0');
        n >>= 1;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

vector<int> getSubSetMask(int mask) {
    vector<int> ans;
    int subMask = mask;
    while(subMask) {
        ans.push_back(subMask);
        subMask = (subMask - 1) & mask;
    }
    ans.push_back(0);
    return ans;
}

void solve() {
    int n = 9;                        // 1001
    cout << getBit(n, 3) << '\n';     // 1
    cout << setBit(n, 2) << '\n';     // 1101: 13
    cout << setBit(n, 1) << '\n';     // 1011: 11
    cout << clearBit(n, 3) << '\n';   // 0001: 1
    cout << toggleBit(n, 2) << '\n';  // 1101: 13

    cout << getBin(n) << '\n';

    vector<int> subMasks = getSubSetMask(n);
    for(auto e: subMasks) cout << e << " ";
    cout << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}