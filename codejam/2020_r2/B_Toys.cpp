#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: https://codejam.lge.com/problem/19240
 * Solution: Using Bipartite graph
 */

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
int n, m;

bool isBipartite(int N, vii& unfriendlyPairs) {
    vector<vector<int>> graph(N + 1);

    // Group assignment for each toy (-1: unassigned, 0: Group 1, 1: Group 2)
    vector<int> group(N + 1, -1);

    // Build adjacency list representation of the graph
    for (const auto& pair : unfriendlyPairs) {
        int toy1 = pair.first;
        int toy2 = pair.second;
        graph[toy1].push_back(toy2);
        graph[toy2].push_back(toy1);
    }

    // Perform BFS traversal
    for (int start = 1; start <= N; start++) {
        if (group[start] != -1) {
            // Toy already assigned to a group
            continue;
        }

        queue<int> q;
        q.push(start);
        group[start] = 0;

        while (!q.empty()) {
            int currToy = q.front();
            q.pop();

            for (int neighbor : graph[currToy]) {
                if (group[neighbor] == -1) {
                    // Neighbor toy not assigned to a group
                    group[neighbor] = 1 - group[currToy];
                    q.push(neighbor);
                } else if (group[neighbor] == group[currToy]) {
                    // Neighbor toy assigned to the same group
                    return false;
                }
            }
        }
    }
    return true;
}

void solve() {
    cin >> n >> m;
    vii unPair;
    For(i, 1, m) {
        int a, b;
        cin >> a >> b;
        unPair.pb({a, b});
    }
    if (isBipartite(n, unPair)) {
        cout << "YES" << el;
    } else
        cout << "NO" << el;
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