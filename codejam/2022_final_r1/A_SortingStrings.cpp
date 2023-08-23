#include <bits/stdc++.h>

using namespace std;
/**
 * Problem: https://codejam.lge.com/problem/25204
 * Solution:
 *  - Custom string sort by the conditions
 *
 * TC: O(n log n) n: number of string (max = 15000)
 * MC: O(n)
 */

int tcs, n;
vector<string> v;

bool cmp(string s1, string s2) {
    int minSize = min(s1.size(), s2.size());
    bool found = false;
    int idx = 0;
    for (int i = 0; i < minSize; i++) {
        if (s1[i] != s2[i]) {
            found = true;
            idx = i;
            break;
        }
    }
    if (found) {
        if (s1[idx] == '-') return false;
        if (s2[idx] == '-') return true;
        char c1i = tolower(s1[idx]);
        char c2i = tolower(s2[idx]);
        if (c1i == c2i) {
            return s1[idx] < s2[idx];
        }
        return c1i < c2i;
    } else {
        return s1.size() < s2.size();
    }
}

void solve() {
    cin >> n;
    v.clear();
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        v.push_back(s);
    }
    sort(v.begin(), v.end(), cmp);
    for (auto e : v) cout << e << "\n";
    // cout << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}