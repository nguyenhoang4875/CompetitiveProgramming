#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define F first
#define S second

using namespace std;

using vb = vector<bool>;
using vvb = vector<vb>;
using vc = vector<char>;
using vvc = vector<vc>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;

int min(int &a, int &b) {
    if(a <= b) return a;
    return b;
}

//*** START CODING ***//

const int oo = 1e18, mod = 1e9 + 7;
const int ms = 205;
int n, m, q;

vector<vector<vector<int>>> minPath(ms, vvi(ms));
vvi matrix(ms, vi(ms));

void init() {
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            minPath[i][j].clear();
            matrix[i][j] = oo;
        }
    }
}

void calInitShortestPath() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j)
                minPath[i][j].pb(0);
            else
                minPath[i][j].pb(matrix[i][j]);
        }
    }
    // floyd algorithm
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                minPath[i][j][0] = min(minPath[i][j][0], minPath[i][k][0] + minPath[k][j][0]);
            }
        }
    }
}

int getSumShortestPath() {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (minPath[i][j].back() != oo) {
                sum += minPath[i][j].back();
            }
        }
    }
    return sum;
}

void updateShortestPath(int x, int y) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            minPath[i][j].back() =
                min(minPath[i][j].back(),
                    minPath[i][x].back() + minPath[x][y].back() + minPath[y][j].back());
            minPath[i][j].back() =
                min(minPath[i][j].back(),
                    minPath[i][y].back() + minPath[y][x].back() + minPath[x][j].back());
            }
    }
}

void addNewEdge(int x, int y, int c) {
    minPath[x][y].pb(min(minPath[x][y].back(), c));
    minPath[y][x].pb(min(minPath[y][x].back(), c));

    // set new minPath from previous
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == x && j == y) continue;
            if (i == y && j == x) continue;
            minPath[i][j].pb(minPath[i][j].back());
        }
    }
}

void removeLastEdge() {
    if (minPath[1][1].size() <= 1) return;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            minPath[i][j].pop_back();
        }
    }
}

void solve() {
    cin >> n >> m >> q;
    init();

    // add edges
    int x, y, c;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y >> c;
        matrix[x][y] = min(matrix[x][y], c);
        matrix[y][x] = min(matrix[y][x], c);
    }
    calInitShortestPath();

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            cout << getSumShortestPath() << " ";
        } else if (type == 2) {
            cin >> x >> y >> c;
            addNewEdge(x, y, c);
            updateShortestPath(x, y);
        } else {
            removeLastEdge();
        }
    }
    cout << '\n';
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