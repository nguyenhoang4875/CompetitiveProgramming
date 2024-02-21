#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: https://codejam.lge.com/problem/19594
 * Solution: Greedy + optimize
 *  - Sort by desc deadline
 *  - Find position of high priority by use preMax
 *  - Calculate the answer
 */

#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(i, a, b) for (int i = a; i <= (int)b; i++)
#define Ford(i, a, b) for (int i = a; i >= (int)b; i--)
#define Fore(it, x) for (auto it = x.begin(); it != x.end(); ++it)

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
const int ms = 2e5 + 5;
int n, tmp;

void solve() {
    cin >> n;
    vii v(n);
    For(i, 0, n - 1) {
        cin >> tmp;
        v[i].F = tmp;
    }
    For(i, 0, n - 1) {
        cin >> tmp;
        v[i].S = tmp;
    }

    sort(all(v), [&](pii p1, pii p2) {
        return p1.S < p2.S; // sort desc deadline
    });

    vi late(n, 0);
    late[0] = max(0LL, v[0].F - v[0].S);
    int curEnd = v[0].F, idxMax = 0, curMax = late[0];
    For(i, 1, n - 1) {
        curEnd += v[i].F;
        late[i] = max(0LL, curEnd - v[i].S);
        if (curMax < late[i]) {
            curMax = late[i];
            idxMax = i;
        }
        late[i] = max(late[i], late[i - 1]);  // preMax late
    }

    int ans = min(oo, max(0LL, curMax - v[0].F + 1));  // high priority at 0
    For(i, 1, idxMax) {
        ans = min(ans, max(late[i - 1], curMax - v[i].F + 1));  // high priority at i
    }
    cout << ans << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}