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
int n, k;
int a[ms], h[ms];
int aa[ms];
vi cnt;

bool check(int val) {
    // cout << "val = " << val << "\n";
    for(int i = 1; i <= n - val + 1; i++) {
        // cout << i << " " << cnt[i] << endl;
        if(cnt[i] < val) continue;
        int sum = aa[i + val - 1] - aa[i - 1];
        if(sum <= k) {
            return true;
        }
    }
    return false;

}

void solve() {
    cin >> n >> k;
    For(i, 1, n) cin >> a[i];
    For(i, 1, n) cin >> h[i];

    For(i, 1, n) aa[i] = aa[i - 1] + a[i];
    // cnt.clear();
    cnt.assign(n + 5, 0);
    cnt[n] = 1;
    for(int i = n - 1; i >= 1; i--) {
        if(h[i] % h[i + 1] == 0) {
            cnt[i] = cnt[i + 1] + 1;
        } else {
            cnt[i] = 1;
        }
    }
    // For(i, 1, n) cout << cnt[i] << ' ';
    // cout << '\n';

    int ans = 0;
    int l = 0, r = n;
    while(l <= r) {
        int mid = (l + r) / 2;
        // cout << "mid = " << mid << endl;
        if(check(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << r << '\n';
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