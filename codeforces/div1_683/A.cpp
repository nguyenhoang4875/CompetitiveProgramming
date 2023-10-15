#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;
/**
 * https://codeforces.com/contest/1446/problem/A
 */

using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;

//*** START CODING ***//

const int ms = 2e5 + 5;
int n, w;

void solve() {
    cin >> n >> w;
    vi ans;
    int sum = 0;
    int x;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        if (sum + x <= w) {
            sum += x;
            ans.pb(i);
        }
        if (x >= (w + 1) / 2 && x <= w) {
            sum = x;
            ans = {i};
        }
    }
    if (sum >= (w + 1) / 2 && sum <= w) {
        cout << ans.size() << '\n';
        for (int e : ans) cout << e << " ";
        cout << '\n';
    } else {
        cout << "-1\n";
    }
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