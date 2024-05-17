#include <bits/stdc++.h>
#define int long long

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(i, a, b) for (int i = a; i <= (int)b; i++)
#define Ford(i, a, b) for (int i = a; i >= (int)b; i--)
#define Fore(it, x) for (auto it = x.begin(); it != x.end(); ++it)

using vb = vector<bool>;
using vvb = vector<vb>;
using vc = vector<char>;
using vvc = vector<vc>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;

//*** START CODING ***//

const int oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;
int n, m, total;

void solve() {
    cin >> n >> m;
    vi a(n), ps(n);
    vi p(m);
    for (auto& x : a) cin >> x;
    for (int i = 0; i < m; i++) {
        cin >> p[i];
    }
    if (n == 1) {
        for (int i = 0; i < m; i++) {
            cout << 0 << el;
        }
        return;
    }
    sort(all(a));
    ps[0] = a[0];
    for (int i = 1; i < n; i++) {
        ps[i] = ps[i - 1] + a[i];
    }

    auto binarySearch = [&](int val) {
        int ret = -1;
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if ((mid + 1) * a[mid] <= val + ps[mid]) {
                ret = mid;
                l = mid + 1;
            } else
                r = mid - 1;
        }
        return ret;
    };
    int idx = -1;
    int needToFill = 0;
    for (auto val : p) {
        // binary search to find index
        idx = binarySearch(val);
        int ans = a[n - 1] - a[idx];
        needToFill = idx == 0 ? 0 : a[idx] * idx - ps[idx - 1];
        if (val > needToFill) {
            int remain = val - needToFill;
            if (idx == n - 1) {
                ans += (remain % n) ? 1 : 0;
            } else {
                ans -= remain / (idx + 1);
            }
        }
        cout << ans << el;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}