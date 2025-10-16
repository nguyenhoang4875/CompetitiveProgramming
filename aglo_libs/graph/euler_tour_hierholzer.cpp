#include <bits/stdc++.h>

using namespace std;

/**
 * Eulerian path: is a path which traverses each edge in the graph exactly once
 * Eulerian tour is above path and staring and ending at the same vertex

 * An undirected graph is Eulerian if and only if:
 *  (1) it is connected, and (2) all the vertices have an even degree

 * If all the vertices except exactly two vertices have an even degree,
 * then the graph has an Eulerian path which starts at one of the two odd-degree
 * vertices and ends at the other.
 *
 * TC: O(E)
 */

using vi = vector<int>;

int n;
vector<vi> adj;  // directed graph

vi hierholzer(int s) {
    vi ans, idx(n, 0), st;
    st.push_back(s);

    while (!st.empty()) {
        int u = st.back();
        if (idx[u] < adj[u].size()) {  // still has neighbor
            st.push_back(adj[u][idx[u]]);
            ++idx[u];
        } else {
            ans.push_back(u);
            st.pop_back();
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

void solve() {
    n = 7;
    adj.assign(n, vi());

    adj[0] = {1, 6};  // A -> [B, G]
    adj[1] = {2};     // B -> C
    adj[2] = {3, 4};  // C -> [D, E]
    adj[3] = {0};     // D -> A
    adj[4] = {5};     // E -> F
    adj[5] = {0, 2};  // F -> [A, C]
    adj[6] = {5};     // G -> F
    // Expected euler tour: A B C D A G F C E F A

    vi ans = hierholzer(0);
    for (auto &u : ans) {
        cout << (char)('A' + u) << " ";
    }
    cout << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}