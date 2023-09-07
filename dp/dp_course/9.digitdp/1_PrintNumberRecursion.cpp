#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;

using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;

//*** START CODING ***//
/**
 * Problem: Print all number from 0...n using recursion
 * Solution: Using recursion
 *
 * TC: O(n);
 * MC: O(n);
 */

int n;
string s;

void gen(string ans, int idx, bool last) {
    // base case
    if (idx == n) {
        cout << ans << '\n';
        return;
    }

    // recursion case
    int till = (last ? (s[idx] - '0') : 9);
    for (int i = 0; i <= till; i++) {
        // next last is both before last and current last
        gen(ans + to_string(i), idx + 1, (last && (i == till)));
    }
}

void solve() {
    cin >> s;
    n = s.size();
    gen("", 0, true);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}