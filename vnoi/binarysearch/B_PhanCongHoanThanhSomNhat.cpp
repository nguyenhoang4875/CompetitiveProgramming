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
const int ms = 205;
int n;
int a[ms][ms];

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    vi v;
    int ans = -1;
    for(int i = 1; i <= n; i++) {
        int t = oo;
        for(int j = 1; j <= n; j++) {
            t = min(t, a[j][i]);
        }
        ans = max(ans, t);
        v.pb(t);
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}