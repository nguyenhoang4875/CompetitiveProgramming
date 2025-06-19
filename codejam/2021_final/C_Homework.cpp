#include <bits/stdc++.h>
#define int long long

using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define all1(x) (x).begin() + 1, (x).end()
#define el '\n'
#define F first
#define S second
#define Rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define For(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define Rof(i, a, b) for (int i = (a), _b = (b); i >= _b; i--)
#define Fore(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)

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
const int ms = 2e5 + 5;

void solve() {
    int n, cur;
    cin >> n >> cur;
    vii a(n);
    Rep(i, n) cin >> a[i].F;
    Rep(i, n) cin >> a[i].S;

    sort(all(a)); // sort asc time release

    priority_queue<pii> q;
    int idx = 0;
    Rep(i, n) {
        if(cur < a[i].F) break;
        q.push({a[i].S, a[i].F});
        idx++;
    }

    int ans = 0;
    Rep(i, n) {
        if(idx < n and q.empty()) {
            q.push({a[idx].S, a[idx].F});
            cur = max(cur, a[idx].F);
            idx++;
        }
        
        // add same cur time
        while(idx < n and cur == a[idx].F) {
            q.push({a[idx].S, a[idx].F});
            idx++;
        }

        auto [v, t] = q.top();
        q.pop();
        ans += (cur - t) * v;
        cur += 1;
    }
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