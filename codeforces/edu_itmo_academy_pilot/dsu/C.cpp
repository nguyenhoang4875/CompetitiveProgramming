#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * https://codeforces.com/edu/course/2/lesson/7/1/practice?#comment-1031459
*/
int n, m;

struct Dsu {
   vector<int> parent, exp, add ;
   Dsu(int n): parent(n), exp(n), add(n) {}; 
   
   void makeSet(int v) {
       parent[v] = v;
       exp[v] = 0;
       add[v] = 0;
   }

   int findSet(int v) {
    int p = parent[v];
    vector<int> val, nodes;
    while(v != p) {
        val.push_back(add[p]);
        nodes.push_back(v);
        v = p;
        p = parent[v];
    }
    int sum = 0;
    for(int i = val.size() - 2; i >= 0; i--) {
        sum += val[i];
        exp[nodes[i]] += sum;
        add[nodes[i]] += sum;
        parent[nodes[i]] = p;
    }
    return p;
   }
   
   void unionSet(int a, int b) {
        a = findSet(a);
        b = findSet(b);
        if(a != b) {
            parent[a] = b;
            exp[a] -= add[b];
            add[a] -= add[b];
        }
   }

   int getExp(int v) {
        int p = findSet(v);
        return exp[v] + ((p != v) ? add[p] : 0);
   }
   
   void addSet(int v, int val) {
        v = findSet(v);
        exp[v] += val;
        add[v] += val;
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
        if(s == "add") {
            cin >> b;
            dsu.addSet(a, b);
        } else if (s == "join") {
            cin >> b;
            dsu.unionSet(a, b);
        } else {
            cout << dsu.getExp(a) << '\n';
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}