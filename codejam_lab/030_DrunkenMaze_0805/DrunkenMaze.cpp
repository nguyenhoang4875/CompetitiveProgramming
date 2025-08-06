#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define all1(x) (x).begin() + 1, (x).end()
#define sz(x) static_cast<int>((x).size())
#define el '\n'
#define F first
#define S second
#define Rep(i, n) for (int i = 0; i < (int)n; ++i)
#define For(i, a, b) for (int i = (a); i <= (int)b; ++i)
#define Rof(i, b, a) for (int i = (b); i >= (int)a; --i)
#define Fore(i, v) for (auto i = (v).begin(); i != (v).end(); ++i)

using vb = vector<bool>;
using vvb = vector<vb>;
using vc = vector<char>;
using vvc = vector<vc>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;

//*** START CODING ***//

const long long oo = 1e9, mod = 1e9 + 7;
const int ms = 2e5 + 5;
using node = array<int, 5>;

void solve() {
    int n, m;
    cin >> n >> m;
    vvc a(n + 1, vc(m + 1));
    int sx, sy, tx, ty;
    For(i, 1, n) {
        For(j, 1, m) {
            cin >> a[i][j];
            if (a[i][j] == 'S') sx = i, sy = j;
            if (a[i][j] == 'T') tx = i, ty = j;
        }
    }

    const int dx[4] = {0, -1, 1, 0};  // 0: L, 1: U, 2: D, 3: R
    const int dy[4] = {-1, 0, 0, 1};

    int dist[n + 1][m + 1][4][4] = {0};  // x, y, num, dir
    For(i1, 1, n) For(i2, 1, m) Rep(i3, 4) Rep(i4, 4) dist[i1][i2][i3][i4] = oo;
    Rep(i, 3) dist[sx][sy][0][i] = 0;

    priority_queue<node, vector<node>, greater<node>> q;  // node: d, numDir,  dir, x, y
    Rep(dr, 4) q.push({0, 0, dr, sx, sy});

    while (!q.empty()) {
        auto [d, numDir, dir, x, y] = q.top();
        q.pop();
        if (x == tx and y == ty) {
            cout << d << el;
            return;
        }

        if (d > dist[x][y][numDir][dir]) continue;

        Rep(dr, 4) {
            int nx = x + dx[dr];
            int ny = y + dy[dr];

            if (nx < 1 or nx > n or ny < 1 or ny > m) continue;
            if (a[nx][ny] == '#') continue;
            int ndr, n_num = 0;
            int nd = d + 1;

            if (numDir == 3 and dr == dir) {
                ndr = 3 - dr;
                nx = x + dx[ndr];
                ny = y + dy[ndr];
            } else {
                if (dr == dir) {
                    ndr = dr;
                    n_num = numDir + 1;
                } else {
                    n_num = 1;
                    ndr = dr;
                }
            }
            if (nd < dist[nx][ny][n_num][ndr]) {
                dist[nx][ny][n_num][ndr] = nd;
                q.push({nd, n_num, ndr, nx, ny});
            }
        }
    }

    cout << -1 << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}