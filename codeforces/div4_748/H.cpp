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

void solve() {
    cin >> n >> k;
    int ans = (1 << 31) - 1;
    For(i, 1, n) {
        cin >> a[i];
        ans &= a[i];
    }

    int tmp = 0;
    map<int, int> cnt;
    Ford(i, 30, 0) {
        tmp = 0;
        For(j, 1, n) {
            if ((a[j] >> i) & 1) tmp++;
        }
        cnt[i] = n - tmp;  // needed number of 1 to have all a[j] has 1 at bit i
    }

    Ford(i, 30, 0) {
        if (k >= cnt[i]) {
            k -= cnt[i];
            ans |= (1 << i);
        }
    }
    cout << ans << el;
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