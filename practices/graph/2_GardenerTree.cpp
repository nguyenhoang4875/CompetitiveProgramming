#include <bits/stdc++.h>
#define int long long

/**
 * https://codeforces.com/problemset/problem/1593/E
 */

using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define all1(x) (x).begin() + 1, (x).end()
#define el '\n'
#define F first
#define S second
#define Rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
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
const int ms = 2e5 + 5;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> adj(n + 1);
    vi deg(n + 1, 0);

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }

    vi removal_round(n + 1, 0);
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (deg[i] <= 1) {
            removal_round[i] = 1;
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (removal_round[v] == 0) {
                deg[v]--;
                if (deg[v] == 1) {
                    removal_round[v] = removal_round[u] + 1;
                    q.push(v);
                }
            }
        }
    }

    int cnt_remaining = 0;
    for (int i = 1; i <= n; i++) {
        if (removal_round[i] == 0 || removal_round[i] > k) { cnt_remaining++; }
    }

    cout << cnt_remaining << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs = 1;
    cin >> tcs;
    while (tcs--) { solve(); }
    return 0;
}