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
int n;
int a[ms], preMax[ms], sufMax[ms];

void solve() {
    cin >> n;
    For(i, 1, n) cin >> a[i];
    // (a1 + a2 + a3) - (r - l): max <=> (a1 + l) + a2 + (a3 - r) max

    preMax[1] = a[1] + 1;
    For(i, 2, n) preMax[i] = max(preMax[i - 1], a[i] + i);
    sufMax[n] = a[n] - n;
    Ford(i, n - 1, 1) sufMax[i] = max(sufMax[i + 1], a[i] - i);

    int ans = 0LL;
    For(i, 2, n - 1) { ans = max(ans, preMax[i - 1] + a[i] + sufMax[i + 1]); }
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