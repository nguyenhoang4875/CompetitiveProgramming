#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define F first
#define S second
#define For(_i, _a, _b) for (int _i = (_a); _i <= (_b); _i++)
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

void solve() {
    cin >> n >> k;
    For(i, 1, n) cin >> a[i];
    For(i, 1, n) cin >> h[i];

    For(i, 1, n) aa[i] = aa[i - 1] + a[i];
    // For(i, 1, n) cout << aa[i] << ' ';
    // cout << '\n';

    int ans = 0;
    For(i, 1, n) {
        if(a[i] <= k) {
            ans = 1;
            break;
        }
    }
    int l = 2, r = 2;
    while (r <= n) {
        l = r - 1;
        if (h[r - 1] % h[r] == 0) {
            l = r - 1;
            int sum = 0;
            while (r <= n && h[r - 1] % h[r] == 0) {
                // cout << h[r - 1] << " h " << h[r] << '\n';
                sum = aa[r] - aa[l - 1];
                if (sum <= k) {
                    // cout << "sum1 = " << sum << '\n';
                    // cout << l << " s1 " << r << '\n';
                    ans = max(ans, r - l + 1);
                    r++;
                } else {
                    break;
                }
            }
        }
        l += 2;
        r = l;
    }
    
    cout << ans << '\n';
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