#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: Given an array of boxes. Each box has hight, width, depth.
 * Our goad is stack up the boxes and maximize the total height of the stack.
 * The boxes can not rotate and the box mus have strictly smaller width, depth
 * and height than any other box below it.
 *
 * Solution: Dp (like LIS problem)
 *
 * TC: O(n)
 * MC: O(n)
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
int n;

struct box {
    int d, w, h;
};

box a[ms];

void solve() {
    cin >> n;
    For(i, 1, n) { cin >> a[i].d >> a[i].w >> a[i].h; }
    sort(a + 1, a + n + 1, [&](box n1, box n2) { return n1.h < n2.h; });

    vi dp(n + 1);
    // init value for dp
    For(i, 1, n) dp[i] = a[i].h;

    int ans = 0;
    For(i, 1, n) {
        For(j, 1, i - 1) {
            // condition to push box i-th to the top of box i-th
            if (a[j].d < a[i].d and a[j].w < a[i].w and a[j].h < a[i].h) {
                dp[i] = max(dp[i], a[i].h + dp[j]);
                ans = max(ans, dp[i]);
            }
        }
    }
    cout << ans << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}