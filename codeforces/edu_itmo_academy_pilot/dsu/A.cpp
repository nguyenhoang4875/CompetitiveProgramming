#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, m;

struct Dsu {
   vector<int> parent, sz;
   Dsu(int n): parent(n), sz(n) {}; 
   
   void makeSet(int v) {
       parent[v] = v;
       sz[v] = 1;
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
        cin >> s >> a >> b;
        if(s == "union") {
            dsu.unionSet(a, b);
        } else {
            if(dsu.findSet(a) == dsu.findSet(b)) {
                cout << "YES\n";
            } else cout << "NO\n";
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}