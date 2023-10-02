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
int n, m, q;
int a[ms], b[ms];
int cnt[ms];

void solve() {
    cin >> n >> m >> q;
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }
    for (int i = 1; i <= m; i++) {
        cnt[a[i]]++;
        cnt[b[i] + 1]--;
    }
    for (int i = 1; i <= n; i++) {
        cnt[i] += cnt[i - 1];
    }
    sort(cnt + 1, cnt + n + 1);
    cout << endl;
    while (q--) {
        int val;
        cin >> val;
        int pos = lower_bound(cnt + 1, cnt + n + 1, val) - cnt;
        int ans = n - pos + 1;
        cout << ans << "\n";
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}