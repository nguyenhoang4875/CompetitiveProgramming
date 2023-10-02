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
int n, k;

int cal(vi& a) {
    if (a.empty()) return 0;
    int sz = a.size();
    int sum = 0;
    for (int i = sz - 1; i >= 0; i--) {
        sum += 2 * a[i];
        i -= k - 1;
    }
    return sum;
}

void solve() {
    cin >> n >> k;
    vi a, b;
    int x;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        if (x == 0) continue;
        if (x > 0)
            a.pb(x);
        else
            b.pb(-x);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int ans = cal(a) + cal(b);
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}