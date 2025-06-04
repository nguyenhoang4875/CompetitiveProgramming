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

const int oo = 1e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;
int n, k;
int a[ms];

bool check(int l, int r, bool pre, int& idx) {
    if (pre) {
        // check last position
        if (a[r - 1] >= 2 * a[r]) return false;
        return true;
    }
    int cur = a[l];
    int i = l + 1;
    while (i <= r) {
        if (cur >= 2 * a[i]) {
            idx = i - 1;  // ignore previous part
            return false;
        }
        cur = a[i];
        i++;
    }
    return true;
}

void solve() {
    cin >> n >> k;
    For(i, 1, n) cin >> a[i];
    int ans = 0;
    bool pre = false;
    For(i, 1, n - k) {
        if (check(i, i + k, pre, i)) {
            ans++;
            pre = true;
        } else
            pre = false;
    }
    cout << ans << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs;
    cin >> tcs;
    while (tcs--) solve();
    return 0;
}