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
using pis = pair<int, string>;

//*** START CODING ***//

const long long oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;

void solve() {
    int n, m;
    int tc = 0;
    while (cin >> n) {
        vector<string> v(n);
        Rep(i, n) cin >> v[i];
        map<string, vector<string>> adj;
        map<string, int> in_deg, pos;
        Rep(i, n) {
            pos[v[i]] = i;
            in_deg[v[i]] = 0;
        }

        cin >> m;
        Rep(i, m) {
            string s, t;
            cin >> s >> t;
            adj[s].pb(t);
            in_deg[t]++;
        }

        priority_queue<pis, vector<pis>, greater<pis>> q;
        for (auto& [s, cnt] : in_deg) {
            if (cnt == 0) q.push({pos[s], s});
        }

        vector<string> order;
        while (q.size()) {
            auto [_, t] = q.top();
            q.pop();
            order.pb(t);

            for (auto u : adj[t]) {
                --in_deg[u];
                if (in_deg[u] == 0) q.push({pos[u], u});
            }
        }
        cout << "Case #" << ++tc << ": Dilbert should drink beverages in this order: ";
        int on = order.size();
        for (int i = 0; i < on; ++i) {
            cout << order[i] << " ."[i == n - 1];
        }
        cout << el;
        cout << el;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}