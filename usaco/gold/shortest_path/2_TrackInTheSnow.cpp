#include <bits/stdc++.h>
#define int long long

using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(i, a, b) for (int i = (a); i <= (int)(b); i++)
#define Rof(i, a, b) for (int i = (a); i >= (int)(b); i--)
#define Fore(it, x) for (auto it = (x).begin(); it != (x).end(); ++it)

using vb = vector<bool>;
using vvb = vector<vb>;
using vc = vector<char>;
using vvc = vector<vc>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;

//*** START CODING ***//

const long long oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;
int n, m;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void solve() {
    cin >> n >> m;
    vvc a(n, vc(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    vvi dist(n, vi(m, 0));
    deque<pii> q;
    q.push_back({0, 0});
    int ans = 0;
    dist[0][0] = 1;

    while (!q.empty()) {
        pii cur = q.front();
        q.pop_front();
        ans = max(ans, dist[cur.F][cur.S]);

        for (int i = 0; i < 4; i++) {
            int nx = cur.F + dx[i];
            int ny = cur.S + dy[i];

            if (nx < 0 or nx >= n or ny < 0 or ny >= m) continue;
            if (a[nx][ny] == '.') continue;
            if (dist[nx][ny] != 0) continue;

            if (a[cur.F][cur.S] == a[nx][ny]) {
                dist[nx][ny] = dist[cur.F][cur.S];
                q.push_front({nx, ny});
            } else {
                dist[nx][ny] = dist[cur.F][cur.S] + 1;
                q.push_back({nx, ny});
            }
        }
    }
    cout << ans << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}