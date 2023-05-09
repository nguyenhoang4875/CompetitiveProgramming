#include <bits/stdc++.h>
#define int long long

using namespace std;


struct edge {
    int s, e;
};

int tcs, n, m;

void solve() {
    cin >> n >> m;

    vector<edge> v[n+1];
    for (int i = 1; i <= m; i++) {
        int s, e;
        cin >> s >> e;
        edge ed = {s, e};
        v[s].push_back(ed);
        v[e].push_back(ed);
    }
    map<int, int> mi;
    for (int i = 1; i <= n; i++) {
        mi[v[i].size()]++;
    }

    int x, y;
    for (auto e: mi) {
        // cout << e.first << " " << e.second << endl;
        if(e.second == 1) {
            x = e.first;
            break;
        }
    }
    y = m / x - 1;
    cout << x << " " <<  y << endl; 

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}