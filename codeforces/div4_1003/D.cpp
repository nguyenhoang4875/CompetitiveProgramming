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
int n, m;

void solve() {
    cin >> n >> m;
    vvi a(n, vi(m));
    vector<pair<int, vi>> f;
    For(i, 0, n - 1) {
        int sum = 0;
        For(j, 0, m - 1) {
            cin >> a[i][j];
            sum += a[i][j];
        }
        f.push_back({sum, a[i]});
    }
    sort(all(f), greater<pair<int, vi>>());
    int cnt = n * m;
    int ans = 0;
    int acc = 0;
    for (int i = 0; i < n; i++) {
        for (auto e : f[i].S) {
            ans += e * cnt;
            cnt--;
        }
    }

    cout << ans << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs = 1;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}