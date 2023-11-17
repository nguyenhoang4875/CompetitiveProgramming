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

struct Dsu {
    Dsu(){};
    Dsu(int n) : parent(n), rank(n), deg(n) {};

    vector<int> parent, rank, deg;
    void makeSet(int v) {
        parent[v] = v;
    }

    int findSet(int v) {
        return v == parent[v] ? v : parent[v] = findSet(parent[v]);
    }

    void unionSet(int a, int b) {
        deg[a]++;
        deg[b]++;
        a = findSet(a);
        b = findSet(b);
        if (a != b) {
            if(rank[a] > rank[b]) {
                parent[b] = a;
            } else {
                parent[a] = b;
                if(rank[a] == rank[b]) rank[b]++;
            }
        }
    }

    void reset() {
        for(int i = 0; i < parent.size(); i++) {
            parent[i] = i;
        }
        fill(all(rank), 0);
        fill(all(deg), 0);
    }
};

struct Edge {
    int u, v, w;
};
struct EdgeCmp {
    bool operator()(Edge const & lhs, Edge const & rhs) {
        return lhs.w > rhs.w;
    }
};

int n, m, k;
void solve() {
    cin >> n >> m >> k;
    Dsu dsu(n + 1);
    For(i, 1, n) dsu.makeSet(i);

    vector<Edge> ve(m + 1);
    int u, v;
    For(i, 0, m - 1) {
        cin >> u >> v;
        Edge e;
        e.u = --u;
        e.v = --v;
        e.w = i + 1;
        ve[i] = e;
    }

    vi ans(k , 0);
    if(n <= 1) return;

    int p, sum = 0;
    priority_queue<Edge, vector<Edge>, EdgeCmp> edges; 
    vb visited(m, false);
    For(i, 0, k - 1) {
        dsu.reset();
        queue<Edge> q;
        while(!edges.empty()) {
            q.push(edges.top());
            edges.pop();
        }
        while(!q.empty()) {
            Edge t = q.front();
            q.pop();

            dsu.unionSet(t.u, t.v);
            edges.push(t);
        }
        p = 0;
        while(edges.size() < n - 1 && p < m) {
            if(!visited[p]) {
                Edge e = ve[p];
                if(!dsu.deg[e.u] || !dsu.deg[e.v] || dsu.findSet(e.u) != dsu.findSet(e.v)) {
                    visited[p] = true;
                    dsu.unionSet(e.u, e.v);
                    edges.push(e);
                    sum += e.w;
                }
            }
            p++;
        }

        if(edges.size() < n - 1) {
            break;
        }
        ans[i] = sum;
        Edge e = edges.top();
        edges.pop();
        sum -= e.w;
    }
    For(i, 0, k - 1) cout << ans[i] << " ";
    cout << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}