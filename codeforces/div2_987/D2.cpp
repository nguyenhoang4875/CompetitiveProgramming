#include <bits/stdc++.h>
#define int long long

using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(i, a, b) for (int i = (a); i <= (int)(b); i++)
#define Rof(i, a, b) for (int i = (a); i >= (int)(b); i--)
#define Fore(it, x) for (auto it = (x).begin(); it != (x).end(); ++it)

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
const int ms = 5e5 + 5;
int n;
int a[ms], preMax[ms], sufMin[ms];

void solve() {
    cin >> n;
    For(i, 1, n) cin >> a[i];

    For(i, 1, n) preMax[i] = max(preMax[i - 1], a[i]);
    sufMin[n + 1] = n + 1;
    Rof(i, n, 1) sufMin[i] = min(sufMin[i + 1], a[i]);

    vi ans(n + 1, 0);
    For(i, 1, n) ans[i] = preMax[i];

    Rof(i, n - 1, 1) {
        auto low = lower_bound(sufMin + i, sufMin + n + 1, preMax[i]) - sufMin;
        low--;
        ans[i] = max(ans[low], ans[i]);
    }
    For(i, 1, n) cout << ans[i] << " ";
    cout << endl;
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