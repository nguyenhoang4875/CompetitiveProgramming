#include <bits/stdc++.h>
#define int long long

using namespace std;
//*** debug(x) ***//
#define DEBUG 0

#if DEBUG
#define del cout << '\n'
#define debug(x) cout << "[" << #x << "]" << " : " << (x) << endl
template <class Ch, class Tr, class Container>
basic_ostream<Ch, Tr>& operator<<(basic_ostream<Ch, Tr>& os, Container const& x) {
    os << "{ ";
    for (const auto& y : x) os << y << ", ";
    return os << "}";
}
template <class X, class Y>
ostream& operator<<(ostream& os, pair<X, Y> const& p) {
    return os << "(" << p.first << ", " << p.second << ")";
}
#else
#define del
#define debug(x)
#endif

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
const int ms = 1e2 + 5;
int n, m;
char a[ms][ms];
int dist[15][15];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int ans = oo;

int bfs(pii st, pii ed) {
    queue<vector<int>> q;
    q.push({st.first, st.second, 0});
    vector<vector<bool>> seen(n + 1, vb(m + 1, false));
    seen[st.first][st.second] = true;
    while (!q.empty()) {
        vi cur = q.front();
        q.pop();
        if (cur[0] == ed.F and cur[1] == ed.S) return cur[2];
        for (int i = 0; i < 4; i++) {
            int nx = cur[0] + dx[i];
            int ny = cur[1] + dy[i];
            if (nx < 1 or nx > n or ny < 1 or ny > m) continue;
            if (a[nx][ny] == '*') continue;
            if (seen[nx][ny]) continue;
            seen[nx][ny] = true;
            q.push({nx, ny, cur[2] + 1});
        }
    }
    return 0;
}

void solve() {
    cin >> n >> m;
    pii s;
    vector<pii> v;
    For(i, 1, n) {
        For(j, 1, m) {
            cin >> a[i][j];
            if (a[i][j] == 'S') {
                s = {i, j};
            }
            if (a[i][j] >= '1' and a[i][j] <= '9') {
                v.push_back({i, j});
            }
        }
    }
    v.push_back(s);
    debug(v);
    int vn = v.size();
    for (int i = 0; i < vn; i++) {
        for (int j = i + 1; j < vn; j++) {
            dist[i][j] = dist[j][i] = bfs(v[i], v[j]);
        }
    }
    vn--;
    vector<int> p;
    for (int i = 0; i < vn; i++) p.push_back(i);
    ans = oo;
    do {
        int ret = dist[p[0]][vn] + dist[p[vn - 1]][vn];
        for (int i = 0; i < vn - 1; i++) {
            ret += dist[p[i]][p[i + 1]];
        }
        ans = min(ans, ret);
    } while (next_permutation(p.begin(), p.end()));
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}