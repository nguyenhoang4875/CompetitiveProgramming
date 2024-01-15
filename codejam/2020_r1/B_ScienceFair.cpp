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

const int oo = 1e9, mod = 1e9 + 7;
const int ms = 1e5 + 5;
int n, na, nb, nc;
const int SS = 0, TT = 11, A = 1, B = 2, C = 3, AB = 4, AC = 5, BC = 6, ABC = 7;
const int GA = 8, GB = 9, GC = 10;

vector<vector<int>> capacity;
vector<vector<int>> adj;
unordered_set<int> sa, sb, sc, sab, sac, sbc, sabc;

int bfs(int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);  // also use as visited array
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, oo});

    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == t) return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

int maxFlow(int s, int t) {
    int flow = 0;
    vector<int> parent(TT + 1);
    int new_flow;

    while (new_flow = bfs(s, t, parent)) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}
void addEdge(int u, int v, int w) {
    adj[u].pb(v);
    adj[v].pb(u);
    capacity[u][v] = w;
}

void initGraph() {
    adj = vector<vector<int>>(TT + 1);
    capacity = vector<vector<int>>(TT + 1, vector<int>(TT + 1, 0));
    // build graph
    addEdge(SS, A, sa.size());
    addEdge(SS, B, sb.size());
    addEdge(SS, C, sc.size());
    addEdge(SS, AB, sab.size());
    addEdge(SS, AC, sac.size());
    addEdge(SS, BC, sbc.size());
    addEdge(SS, ABC, sabc.size());

    addEdge(A, GA, oo);
    addEdge(AB, GA, oo);
    addEdge(AC, GA, oo);
    addEdge(ABC, GA, oo);

    addEdge(B, GB, oo);
    addEdge(AB, GB, oo);
    addEdge(BC, GB, oo);
    addEdge(ABC, GB, oo);

    addEdge(C, GC, oo);
    addEdge(AC, GC, oo);
    addEdge(BC, GC, oo);
    addEdge(ABC, GC, oo);

    addEdge(GA, TT, na);
    addEdge(GB, TT, nb);
    addEdge(GC, TT, nc);
}

void resetData() {
    sa.clear();
    sb.clear();
    sc.clear();
    sab.clear();
    sac.clear();
    sbc.clear();
    sabc.clear();
}

void getGym(unordered_set<int>& si, int sid) {
    for (int j = GA; j <= GC; j++) {
        int cnt = capacity[j][sid];
        for (int k = cnt; k--; k > 0) {
            cout << *si.begin() << " " << (char)(j - 8 + 'A') << "\n";
            si.erase(si.begin());
        }
    }
}

void solve() {
    resetData();
    cin >> n;
    cin >> na >> nb >> nc;
    int m;
    cin >> m;
    // for gym A
    For(j, 1, m) {
        int x;
        cin >> x;
        sa.insert(x);
    }
    cin >> m;
    // for gym B
    For(j, 1, m) {
        int x;
        cin >> x;
        if (sa.count(x)) {
            sa.erase(x);
            sab.insert(x);
        } else
            sb.insert(x);
    }
    cin >> m;
    // for gym C
    For(j, 1, m) {
        int x;
        cin >> x;
        if (sa.count(x)) {
            sa.erase(x);
            sac.insert(x);
            continue;
        }
        if (sb.count(x)) {
            sb.erase(x);
            sbc.insert(x);
            continue;
        }
        if (sab.count(x)) {
            sab.erase(x);
            sabc.insert(x);
            continue;
        }
        sc.insert(x);
    }
    initGraph();
    cout << maxFlow(SS, TT) << el;
    getGym(sa, A);
    getGym(sb, B);
    getGym(sc, C);
    getGym(sab, AB);
    getGym(sbc, BC);
    getGym(sac, AC);
    getGym(sabc, ABC);
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