#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;
/**
 * Problem: https://codejam.lge.com/problem/15703
 * Solution: Brute forces
 * - Find dices have min number first
 * - Check can construct dices with 
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
int n;
int cnt[1005];
void solve() {
    cin >> n;
    int x;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        cnt[x]++;
    }
    int ans = 0;
    int acc = 0;
    for (int i = 0; i <= 1000; i++) {
        if (cnt[i] == 0) continue;
        int num = 0;
        acc += cnt[i];
        num = cnt[i] / (i + 1);
        if (cnt[i] % (i + 1) != 0) num++;
        if (num * (i + 1) < acc) {
            num = acc / (i + 1);
            if (acc % (i + 1) != 0) num++;
        }
        ans = max(ans, num);
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}