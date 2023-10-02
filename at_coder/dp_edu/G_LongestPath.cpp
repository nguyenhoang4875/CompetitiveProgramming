#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;

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
int n, m;
vi v[ms];
vb visited;
int cnt = 0;
vi ts;

void dfs(int i) {
    visited[i] = true;
    cnt++;
    for(auto to: v[i]) {
        if(!visited[to]) dfs(to);
    }
    ts.pb(i);
}

void solve() {
    cin >> n >> m;
    visited.clear();
    visited.resize(n + 5, false);
    while(m--) {
        int x, y;
        cin >> x >> y;
        v[x].pb(y);
    }
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            dfs(i);
        }
    }


    reverse(ts.begin(), ts.end());
    cout << '\n';
    int ans = 0;
    vi dp(n + 1, 0);
    for(auto i: ts) {
        for(auto j : v[i]) {
            dp[j] = max(dp[j], dp[i] + 1);
            ans =  max(ans, dp[j]);
        }
    }
    cout << ans << "\n";

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}