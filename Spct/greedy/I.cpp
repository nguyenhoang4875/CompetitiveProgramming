#include <bits/stdc++.h>

using namespace std;
/**
 * Problem: https://codeforces.com/contest/1738/problem/C
 * TC: O(n)
 * MC: O(1)
*/

//*** define ***//
#define int long long
#define pb push_back
#define FOR(_i, _a, _b) for (int _i = (_a); _i < (_b); _i++)
#define FORI(_i, _a, _b) for (int _i = (_a); _i <= (_b); _i++)
#define FORE(it, x) for (auto it = x.begin(); it != x.end(); ++it)

//*** custom using ***//
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;

//*** START CODING ***//

int tcs, n;

void solve() {
    cin >> n;
    int numOdd = 0;
    int numEven = 0;
    int x;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        if (x & 1) numOdd++;
        else numEven++;
    }

    if (n == 1) {
        if (numOdd == 1)
            cout << "Bob";
        else
            cout << "Alice";
        cout << '\n';
        return;
    }
    if (numOdd % 4 == 2) {
        cout << "Bob";
    } else if (numOdd % 4 == 3) {
        cout << "Alice";
    } else if (numOdd % 4 == 0) {
        cout << "Alice";
    } else if (numEven % 2 == 1) {
        cout << "Alice";
    } else {
        cout << "Bob";
    }
    cout << '\n';
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