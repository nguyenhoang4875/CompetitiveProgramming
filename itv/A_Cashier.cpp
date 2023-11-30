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
const int ms = 1e5 + 5;
int n, l, a;

void solve() {
    vii v;
    cin >> n >> l >> a;
    For(i, 1, n) {
        int tt, ll;
        cin >> tt >> ll;
        v.pb({tt, ll});
    }
    int cur_time = 0;
    int cnt = 0;
    for (auto [tt, ll] : v) {
        if (tt - cur_time >= a) {
            cnt += (tt - cur_time) / a;
        }
        cur_time = tt + ll;
    }
    if (l - cur_time >= a) {
        cnt += (l - cur_time) / a;
    }
    cout << cnt << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}