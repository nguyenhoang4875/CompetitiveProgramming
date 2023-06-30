#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, m;

struct Dsu {
   vector<int> parent, sz, mn, mx, sum ;
   Dsu(int n): parent(n), sz(n), mn(n), mx(n), sum(n) {}; 
   
   void makeSet(int v) {
       parent[v] = v;
       sz[v] = 1;
       mn[v] = v;
       mx[v] = v;
   }

   int findSet(int v) {
    return parent[v] = (v == parent[v] ? v : findSet(parent[v]));
   }
   
   void unionSet(int a, int b) {
        a = findSet(a);
        b = findSet(b);
        if(a != b) {
            if(a < b) swap(a, b);
            parent[b] = a;
            sz[a] += sz[b];
            mn[a] = min(mn[a], mn[b]);
            mx[a] = max(mx[a], mx[b]);
            sum[a] += sum[b];
        }
   }
};

void solve() {
    cin >> n >> m;

    Dsu dsu(n + 1);
    for (int i = 1; i <= n; i++) dsu.makeSet(i);
    string s;
    int a, b;
    for (int i = 1; i <= m; i++) {
        cin >> s >> a;
        if(s == "union") {
            cin >> b;
            dsu.unionSet(a, b);
        } else {
            a = dsu.findSet(a);
            cout << dsu.mn[a] << ' ' << dsu.mx[a] << ' ' << dsu.sz[a] << '\n';
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}