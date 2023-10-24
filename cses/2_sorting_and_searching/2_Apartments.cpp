#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define F first
#define S second
#define For(_i, _a, _b) for (int _i = (_a); _i <= (_b); _i++)
#define Ford(_i, _a, _b) for (int _i = (_a); _i >= (_b); _i--)
#define Fore(it, x) for (auto it = x.begin(); it != x.end(); ++it)

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
const int ms = 2e5 + 5;
int n, m, k;
int a[ms];
int b[ms];

void solve() {
    cin >> n >> m >> k;
    For(i, 1, n) cin >> a[i];
    For(i, 1, m) cin >> b[i];

    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);

    int ia = 1, ib = 1;
    int cnt = 0;
    while (ia <= n && ib <= m) {
        if (a[ia] > b[ib] + k) {
            ib++;
            continue;
        }
        if (a[ia] < b[ib] - k) {
            ia++;
            continue;
        }
        cnt++;
        ia++;
        ib++;
    }
    cout << cnt << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}