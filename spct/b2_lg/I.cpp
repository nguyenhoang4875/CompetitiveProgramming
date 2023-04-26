#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, m, k;
int g[10];
bool used[10];

struct item {
    int id, b, s, r; // planet name, id, cost buy, cost sell, remain items
};

int cnt  = 0;
void outputGen() {
    cout << g[0] << " " << g[1] << endl;
    cnt++;

}

void gen(int start,int n) {
    if(start == 2) {
        outputGen();
        return;
    } else {
        for (int val = 0; val < n; val++) {
            if(used[val]) continue;
            if(start > 0 && val < g[start -1]) continue;
            g[start] = val;
            used[val] = true;
            gen(start + 1, n);
            used[val] = false;

        }
    }
}

void solve() {
    cin >> n >> m >> k;
    vector<vector<item>> v(n);
    string pn;
    int b, s, r;
    int idx = 0;
    int idpn = 0;
    for (int i = 0; i < n ; i++) {
        cin >> pn;
        int b, s, r;
        for (int j = 0; j < m; j++) {
            cin >> b >> s >> r;
            v[idpn].push_back({j, b, s, r});
        }
        idpn++;
    }

    for (int i = 0; i < v.size(); i++) {
        cout << "i = " << i << endl;
        for (int j = 0; j < v[0].size(); j++)  {
            cout <<"" << v[i][j].id <<  " " << v[i][j].b << " " << v[i][j].s << " " << v[i][j].r << endl;
        }
    }

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    // gen(0, 15);
    // cout << cnt << endl;
    return 0;
}