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

using node = array<int, 4>;

void solve() {
    int e, n;
    cin >> e >> n;
    vector<vii> a(n + 1);

    auto add = [&](vii& v, int min_ps, int ps) {
        if (ps <= 0) return false;
        if (v.empty()) {
            v.push_back({min_ps, ps});
            return true;
        }
        if (ps <= v.back().S) return false;
        if (min_ps == v.back().F) v.pop_back();
        v.push_back({min_ps, ps});
        return true;
    };

    Rep(i, n) {
        int m;
        cin >> m;
        vi b(m);
        Rep(j, m) cin >> b[j];
        int ps = 0;
        int min_ps = b[0];
        int mps = 0;
        Rep(j, m) {
            ps += b[j];
            mps += b[j];
            min_ps = min(min_ps, mps);
            if (add(a[i], min_ps, ps)) {
                mps = 0;
                min_ps = oo;
            }
        }
        add(a[i], min_ps, ps);
    }

    priority_queue<node> q;  // min_ps, ps, row, id
    Rep(i, n) {
        if (sz(a[i])) q.push({{a[i][0].F, a[i][0].S, i, 0}});
    }

    vii last(n, {-1, 0});
    int cur = e;
    while (!q.empty()) {
        auto [min_ps, ps, row, id] = q.top();
        q.pop();
        if (cur + min_ps < 0) break;
        cur += ps;
        cur -= last[row].S;
        last[row] = {id, ps};
        if (id < sz(a[row]) - 1) {
            ++id;
            q.push({a[row][id].F, a[row][id].S, row, id});
        }
    }
    cout << cur << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}