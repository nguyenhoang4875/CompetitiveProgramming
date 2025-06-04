#include <bits/stdc++.h>
#define int long long

using namespace std;

//*** define ***//
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(i, a, b) for (int i = (a); i <= (int)(b); i++)
#define Rof(i, a, b) for (int i = (a); i >= (int)(b); i--)
#define Fore(it, x) for (auto it = (x).begin(); it != (x).end(); ++it)

//*** custom using ***//
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
int n, m, v;
int a[ms];

void solve() {
    cin >> n >> m >> v;
    For(i, 1, n) cin >> a[i];
    vi b(n + 1, 0), rb(n + 1, 0);

    int sum = 0;
    int cnt = 0;
    int mx = 0;
    int tot = 0;
    For(i, 1, n) {
        sum += a[i];
        tot += a[i];
        if (sum >= v) {
            b[cnt + 1] = b[cnt] + sum;
            sum = 0;
            cnt++;
        }
    }
    mx = max(mx, cnt);

    cnt = 0;
    sum = 0;
    Rof(i, n, 1) {
        sum += a[i];
        if (sum >= v) {
            rb[cnt + 1] = rb[cnt] + sum;
            sum = 0;
            cnt++;
        }
    }
    mx = max(mx, cnt);
    if (mx < m) {
        cout << -1 << el;
        return;
    }
    int ans = 0;
    for (int k = 0; k <= m; k++) {
        ans = max(ans, tot - b[k] - rb[m - k]);
    }
    cout << ans << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs = 1;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}