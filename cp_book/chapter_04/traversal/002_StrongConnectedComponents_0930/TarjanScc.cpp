#include <bits/stdc++.h>

using namespace std;

/**
 * Tarjan Algorithm
 * tin: time to in that node when traversal using dfs
 * low: low-link time of the smallest (lowest) node reachable from that node
 *  when doing a Dfs(including itself)
 */

vector<vector<int>> adj;
vector<int> low, tin;
stack<int> st;
vector<bool> seen;  // seen[u]: node u is on the stack
int timer = 0, num_scc = 0;
int n, m;

void tarjan(int u) {
    tin[u] = low[u] = timer++;
    st.push(u);
    seen[u] = true;

    for (auto &v : adj[u]) {
        if (tin[v] == -1) tarjan(v);
        if (seen[v]) low[u] = min(low[u], low[v]);  // only update when u is on the stack
    }

    if (low[u] == tin[u]) {  // root start of an SCC
        ++num_scc;
        while (true) {
            int v = st.top();  // can print v for an SCC
            st.pop();
            seen[v] = false;  // remove v from the stack
            if (u == v) break;
        }
    }
}

void solve() {
    cin >> n >> m;
    adj.assign(n, vector<int>());

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;  // if based-index 1
        adj[u].push_back(v);
    }
    tin.assign(n, -1);
    low.assign(n, 0);
    seen.assign(n, false);

    num_scc = timer = 0;
    while (!st.empty()) st.pop();  // clear stack

    for (int u = 0; u < n; ++u) {
        if (tin[u] == -1) {
            tarjan(u);
        }
    }

    cout << num_scc << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}