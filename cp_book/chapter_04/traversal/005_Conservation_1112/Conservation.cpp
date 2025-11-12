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
    int n, m;
    cin >> n >> m;
    vi room(n + 1);
    For(i, 1, n) cin >> room[i];

    vvi adj(n + 1);
    vi deg(n + 1);
    Rep(i, m) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        deg[v]++;
    }

    auto getAns = [&](int s, vi deg) {
        vi v1, v2;
        For(i, 1, n) {
            if (deg[i] == 0) {
                if (room[i] == s) v1.pb(i);
                else v2.pb(i);
            }
        }
        if (v1.empty()) return oo;

        int cnt = 0;
        bool has_s = true;
        queue<int> q;
        for (auto& e : v1) q.push(e);
        v1.clear();

        while (q.size()) {
            int u = q.front();
            q.pop();

            for (auto& v : adj[u]) {
                --deg[v];
                if (deg[v] == 0) {
                    if (room[v] == s) {
                        v1.pb(v);
                    } else {
                        v2.pb(v);
                    }
                }
            }
            if (q.empty()) {
                if (v1.empty() and v2.empty()) break;
                bool tmp = has_s;
                if (has_s) {
                    if (v1.size()) {
                        for (auto e : v1) q.push(e);
                        v1.clear();
                    } else {
                        for (auto e : v2) q.push(e);
                        v2.clear();
                        has_s = !has_s;
                    }
                } else {
                    if (v2.size()) {
                        for (auto e : v2) q.push(e);
                        v2.clear();
                    } else {
                        for (auto e : v1) q.push(e);
                        v1.clear();
                        has_s = !has_s;
                    }
                }
                if (tmp != has_s) ++cnt;
            }
        }
        return cnt;
    };
    int ans = min(getAns(1, deg), getAns(2, deg));
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