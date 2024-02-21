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
int n;
map<int, vi> graph;
vb used;

int go(int i) {
    used[i] = true;
    for (auto now : graph[i]) {
        if (!used[now]) {
            return go(now) + 1;
        }
    }
    return 1;
}

void solve() {
    cin >> n;
    used.clear();
    used.resize(n + 1, false);
    graph.clear();

    bool fault = false;

    For(i, 1, n) {
        int u, v;
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
        if (u == v || graph[u].size() > 2 || graph[v].size() > 2) fault = true;
    }
    if (fault) {
        cout << "NO" << el;
        return;
    }
    For(i, 1, n) {
        if (!used[i]) {
            if (go(i) & 1) {
                cout << "NO" << el;
                return;
            }
        }
    }
    cout << "YES" << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}