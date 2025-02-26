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
#define Rof(i, a, b) for (int i = a; i >= (int)b; i--)
#define Fore(it, x) for (auto it = x.begin(); it != x.end(); ++it)

using vb = vector<bool>;
using vvb = vector<vb>;
using vc = vector<char>;
using vvc = vector<vc>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;

random_device rd;
mt19937 gen(rd());
int random(int l, int r) {
    uniform_int_distribution<int> dis(l, r);
    return dis(gen);
}

// !!! change shuffle for BETTER TREE
vector<pair<int, int>> genEdgeTree(int n) {
    bool shuffle = 1;

    int type = random(1, 4);  // 1: Random, 2: Start, 3: Line, 4: Binary tree
    vector<pair<int, int>> edges;
    for (int v = 2; v <= n; v++) {
        int u;
        switch (type) {
            case 1: u = random(1, v - 1); break;
            case 2: u = 1; break;
            case 3: u = v - 1; break;
            case 4: u = v / 2; break;
        }
        edges.push_back({u, v});
    }

    if (!shuffle) return edges;

    // rename vertices and random order of edges
    vector<int> perm(n + 1);
    for (int i = 1; i <= n; i++) perm[i] = i;
    random_shuffle(edges.begin(), edges.end());
    vector<pair<int, int>> shuffleEdges;
    for (auto e : edges) {
        int u = e.first, v = e.second;
        if (random(0, 1)) {
            swap(u, v);
        }
        shuffleEdges.push_back({perm[u], perm[v]});
    }
    return shuffleEdges;
}

void genTest() {

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    genTest();
    return 0;
}