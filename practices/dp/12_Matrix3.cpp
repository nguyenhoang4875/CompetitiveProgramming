#include <bits/stdc++.h>
#define int long long

using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(i, a, b) for (int i = (a); i <= (int)(b); i++)
#define Rof(i, a, b) for (int i = (a); i >= (int)(b); i--)
#define Fore(it, x) for (auto it = (x).begin(); it != (x).end(); ++it)

using vb = vector<bool>;
using vvb = vector<vb>;
using vc = vector<char>;
using vvc = vector<vc>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;

//*** START CODING ***//

const long long oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;

void solve() {
    int n, m;
    cin >> n >> m;
    vvi a(n + 1, vi(m + 1));
    For(i, 1, n) {
        For(j, 1, m) { cin >> a[i][j]; }
    }
    int f[n + 1][m + 1][5] = {};
    f[1][1][0] = a[1][1];
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            int maxLeft = max({f[i][j - 1][0], f[i][j - 1][1], f[i][j - 1][2]});
            if(maxLeft) f[i][j][0] = max(f[i][j][0], maxLeft + a[i][j]);
            if(f[i - 1][j][0]) f[i][j][1] = max(f[i][j][1], f[i - 1][j][0] + a[i][j]);
            if(f[i - 1][j][1]) f[i][j][2] = max(f[i][j][2], f[i - 1][j][1] + a[i][j]);
        }
    }

    int ans = max({ f[n][m][0], f[n][m][1], f[n][m][2] });
    cout << ans << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}