#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Hamiltonian Path is a path in directed or undirected graph
 * that visit each vertex exactly once.
 * Solution: backtracking
*/

int n, m;
vector<int> g[100005]; // graph
bool isHamiltonPath; // check have Hamiltonian path
bool visited[100005]; // check visited or not
vector<string> vp; // vector of Hamiltonian path
int totalPath; // count total Hamiltonian path


// bool path: return bool to check have Hamiltonian path or not
bool path(int cur, int cnt, string s) {
    // base case
    if(cnt == n) {
        isHamiltonPath = true;
        vp.push_back(s);
        totalPath++;
        return true;
    }

    visited[cur] = true; // mark visited
    //rec case
    for(int v: g[cur]) {
        if(!visited[v]) {
            path(v, cnt + 1, s + char(v + '0'));
            // return true;// if want to find only one Hamiltonian path (1)
        }
    }
    // backtracking
    visited[cur] = false;
    // return false; // if want to find only one Hamiltonian path(2)
}

void solve() {
    cin >> n >> m;
    int u, v;
    for(int i = 1; i <= n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    isHamiltonPath = false;
    totalPath  = 0;
    vp.clear();
    for(int i = 1; i <= n; i++) {
        path(i, 1, to_string(i));
    }
    cout << isHamiltonPath << endl;
    cout << "totalPath = " << totalPath << endl;
    for(auto s: vp) {
        cout << "path = " << s << '\n';
    }

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}