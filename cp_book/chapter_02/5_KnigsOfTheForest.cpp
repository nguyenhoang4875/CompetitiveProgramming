#include <bits/stdc++.h>
#define int long long

using namespace std;

#define pb push_back
#define LSOne(x) ((x) & -(x))
#define all(x) (x).begin(), (x).end()
#define all1(x) (x).begin() + 1, (x).end()
#define sz(x) static_cast<int>((x).size())
#define el '\n'
#define F first
#define S second
#define Rep(i, n) for (int i = 0; i < (int)n; ++i)
#define For(i, a, b) for (int i = (a); i <= (int)b; ++i)
#define Rof(i, b, a) for (int i = (b); i >= (int)a; --i)
#define Fore(i, v) for (auto i = (v).begin(); i != (v).end(); ++i)

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
    int k, n;
    cin >> k >> n;
    pii ka;
    cin >> ka.F >> ka.S;

    vii a;
    a.pb(ka);
    For(i, 1, n + k - 2) {
        int y, p;
        cin >> y >> p;
        a.pb({y, p});
    }
    sort(all(a));
    int m = sz(a);
    priority_queue<int> q;  // strength
    Rep(i, k) q.push(a[i].S);
    int idx = k;
    int cur_year = a[0].F;
    while (q.size() >= k) {
        int cur = q.top();
        q.pop();
        if (cur == ka.S) {
            cout << cur_year << el;
            return;
        }
        if (idx == m) break;
        cur_year = a[idx].F;
        while (idx < m and cur_year == a[idx].F) {
            q.push(a[idx].S);
            ++idx;
        }
    }
    cout << "unknown" << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}