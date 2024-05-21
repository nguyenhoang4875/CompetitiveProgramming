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
const int ms = 2e5 + 5;
int n, m;

struct edge {
    int from, to , w;
};

struct aEdge {
    int idx, from, to, w;
};
vector<edge> ve;
vector<aEdge> vae;
vvi graph;

map<pii, int> me;

int cnt[ms];
int cnt2[ms];
int val0 = 0;
int valMin, valMax;

void addToMap(int u, int v, int w) {
    if(u > v) swap(u, v);
    me[{u, v}] = w;
}

int getFromMap(int u, int v) {
    if(u > v) swap(u, v);
    return me[{u, v}];
}

void dfs(int cur, int par) {
    for(auto x: graph[cur]) {
        if(x != par) {
            dfs(x, cur);
            cnt[cur] += cnt[x];
        }
    }
}

void dfs2(int cur, int par) {
    for(auto x: graph[cur]) {
        if(x != par) {
            dfs2(x, cur);
            cnt2[cur] += cnt2[x];
        }
    }
}

int sumAnEdge(edge e) {
    int t1 = min(cnt[e.from], cnt[e.to]);
    int t2 = n - t1;
    return t1 * t2 * getFromMap(e.from, e.to);
}

int getSum(int originVal, aEdge ae) {
    int newVal = originVal;
    cout << ae.idx << " " << ae.from << " " << ae.to << " " << ae.w << el;

    edge rmEdge = ve[ae.idx];
    int sumRmEdge = sumAnEdge(rmEdge);
    For(i, 1, n) cnt2[i] = 1;
    dfs(1, 0);

}


void solve() {
    cin >> n >> m;
    ve = vector<edge>(n + 1);
    vae = vector<aEdge>(m + 1);
    graph = vvi(n + 1);
    For(i, 1, n - 1) {
        int u, v, w;
        cin >> u >> v >> w;
        ve[i] = {u, v, w};

        graph[u].pb(v);
        graph[v].pb(u);
        addToMap(u, v, w);
    }

    For(i, 1, m) {
        int idx, u, v, w;
        cin >> idx >> u >> v >> w;
        vae[i] = {idx, u, v, w};
    }

    val0 = 0, valMin = oo, valMax = 0;
    For(i, 1, n) {
        cnt[i] = 1;
    }
    dfs(1, 0);

    // For(i, 1, n) {
    //     cout << "i = " << i << " cnt = " << cnt[i] << el;
    // }
    For(i, 1, n - 1) {
        // cout << ve[i].from << " " << ve[i].to << el;
        val0 += sumAnEdge(ve[i]);
    }
    cout << val0 << el;
    getSum(val0, vae[1]);
    // for(int i = 1; i <= m; i++) {
    //     int val = getSum(val0, vae[i]);
    // }
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