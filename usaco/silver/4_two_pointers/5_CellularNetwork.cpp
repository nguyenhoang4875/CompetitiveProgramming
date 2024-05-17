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
int n, m;

void solve() {
    cin >> n >> m;
    vi a(n), b(m);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;

    vi can;
    for (auto val : a) {
        auto low = lower_bound(all(b), val);
        if (low != b.end() and *low == val) {
            can.push_back(0);
            continue;
        }
        if (low != b.begin()) low--;

        auto up = upper_bound(all(b), val);
        if (up == b.end()) up--;
        int ans = min(abs(val - *low), abs(val - *up));
        can.pb(ans);
    }
    int ans = *max_element(all(can));
    cout << ans << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}