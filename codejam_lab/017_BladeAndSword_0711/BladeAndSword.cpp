#include <bits/stdc++.h>
#define int long long

using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define all1(x) (x).begin() + 1, (x).end()
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

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

using node = array<int, 3>;

int solve() {
    int n, m;
    cin >> n >> m;
    vvc a(n + 1, vc(m + 1));
    vii port;
    int px, py, ex, ey;
    For(i, 1, n) {
        For(j, 1, m) {
            cin >> a[i][j];
            if (a[i][j] == 'P') {
                px = i;
                py = j;
            }
            if (a[i][j] == 'D') ex = i, ey = j;
            if (a[i][j] == '*') port.push_back({i, j});
        }
    }
    if (port.size() == 1) {
        a[port[0].F][port[0].S] = '#';
    }

    queue<pii> q;
    vvi dist(n + 1, vi(m + 1, oo));
    dist[px][py] = 0;
    q.push({px, py});
    while (q.size()) {
        auto [x, y] = q.front();
        q.pop();

        Rep(i, 4) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 1 or nx > n or ny < 1 or ny > m) continue;
            if (dist[nx][ny] != oo or a[nx][ny] == '#') continue;
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }
    if (port.size() <= 1) {
        return dist[ex][ey];
    }

    int minDis = oo;
    vii mTel;
    for (auto& [x, y] : port) {
        if (minDis > dist[x][y]) {
            minDis = dist[x][y];
            mTel.clear();
            mTel.push_back({x, y});
        } else if (minDis == dist[x][y] and minDis != oo) {
            mTel.push_back({x, y});
        }
    }

    priority_queue<node, vector<node>, greater<node>> pq;
    dist = vvi(n + 1, vi(m + 1, oo));
    dist[px][py] = 0;
    pq.push({0, px, py});
    if (mTel.size() == 1) {
        auto [x, y] = mTel[0];
        pq.push({minDis + 2, x, y});
        dist[x][y] = minDis + 2;
    }
    for (auto& [x, y] : port) {
        if (dist[x][y] != oo) continue;
        pq.push({minDis + 1, x, y});
        dist[x][y] = minDis + 1;
    }

    while (pq.size()) {
        auto [d, x, y] = pq.top();
        pq.pop();

        Rep(i, 4) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 1 or nx > n or ny < 1 or ny > m) continue;
            if (dist[nx][ny] != oo or a[nx][ny] == '#') continue;
            dist[nx][ny] = d + 1;
            pq.push({dist[nx][ny], nx, ny});
        }
    }
    return dist[ex][ey];
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs = 1;
    cin >> tcs;
    for (int i = 1; i <= tcs; i++) {
        int val = solve();
        cout << "Case " << i << ": " << (val < oo ? to_string(val) : "impossible") << el;
    }
    return 0;
}