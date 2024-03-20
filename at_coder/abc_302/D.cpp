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
int n, m, d;

void solve() {
    cin >> n >> m >> d;
    vi a(n), b(m);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;

    sort(all(a));
    sort(all(b));

    int ans = -1;
    for (auto x : a) {
        auto pos = lower_bound(all(b), x + d);
        if (pos == b.end()) pos--;
        if (abs(*pos - x) <= d) ans = max(ans, x + *pos);
        pos = lower_bound(all(b), x - d);
        if (pos == b.end()) pos--;
        if (abs(*pos - x) <= d) ans = max(ans, x + *pos);
    }
    cout << ans << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}