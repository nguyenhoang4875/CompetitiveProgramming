#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;
/**
 * Problem: https://codejam.lge.com/problem/15738
 * Solution: Math
 * 
 * TC: O(n)
 * MC: O(n)
*/

using vb = vector<bool>;
using vvb = vector<vb>;
using vc = vector<char>;
using vvc = vector<vc>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;

//*** START CODING ***//

const int oo = 1e18, mod = 1e9 + 7;
const int ms = 1e5 + 5;
int n, k, m;
int a[ms];
int i;

void solve() {
    cin >> n >> k >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];

    while (m--) {
        cin >> i;
        if (i > 0) {
            if (i < k) continue;
            k = i + 1 - k;
        } else {
            // i < 0
            i = abs(i);
            int pos = n - i + 1;
            if (k < pos) continue;
            k = n + pos - k;
        }
    }
    cout << k << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}