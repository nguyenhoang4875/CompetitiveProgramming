#include <bits/stdc++.h>
#define int long long

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(i, a, b) for (int i = a; i <= (int)b; i++)
#define Ford(i, a, b) for (int i = a; i >= (int)b; i--)
#define Fore(it, x) for (auto it = x.begin(); it != x.end(); ++it)

using vb = vector<bool>;
using vvb = vector<vb>;
using vc = vector<char>;
using vvc = vector<vc>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;

//*** START CODING ***//

const int oo = 1e9, mod = 1e9 + 7;
const int ms = 1e3 + 5;
int n, m;
char a[ms][ms];
vvb seen;
string ans = "";
bool found = false;
vvi dist;
pii da[ms][ms];
int sr, sc;
queue<pii> qm;
vii gates;

struct node {
    int r, c;
    string path;
};

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int inBound(int r, int c) {
    if (r < 1 or r > n or c < 1 or c > m) return false;
    return true;
}
int touchBound(int r, int c) {
    if (r == 1 or r == n or c == 1 or c == m) return true;
    return false;
}

char getDirection(int i) {
    char c;
    if (i == 0) c = 'L';
    if (i == 1) c = 'R';
    if (i == 2) c = 'U';
    if (i == 3) c = 'D';
    return c;
}
pii getOppDirection(int i) {
    pii p;
    if (i == 0) return {0, 1};
    if (i == 1) return {0, -1};
    if (i == 2) return {1, 0};
    if (i == 3) return {-1, 0};
    return p;
}

void bfsMonster() {
    while (!qm.empty()) {
        pii cur = qm.front();
        qm.pop();
        For(i, 0, 3) {
            int nr = cur.F + dx[i];
            int nc = cur.S + dy[i];
            if (!inBound(nr, nc) || seen[nr][nc] || a[nr][nc] == '#') {
                continue;
            }
            seen[nr][nc] = true;
            dist[nr][nc] = dist[cur.F][cur.S] + 1;
            qm.push({nr, nc});
        }
    }
}

void bfsA() {
    da[sr][sc].F = 0;
    queue<pii> q;
    q.push({sr, sc});
    seen[sr][sc] = true;
    while (!q.empty()) {
        pii cur = q.front();
        q.pop();
        For(i, 0, 3) {
            int nr = cur.F + dx[i];
            int nc = cur.S + dy[i];
            if (!inBound(nr, nc) || seen[nr][nc] || a[nr][nc] == '#') {
                continue;
            }
            seen[nr][nc] = true;
            da[nr][nc].F = da[cur.F][cur.S].F + 1;
            da[nr][nc].S = i;
            q.push({nr, nc});
        }
    }
}

void traceBack(int gr, int gc) {
    int x = gr, y = gc;
    string path = "";
    while (!(x == sr and y == sc)) {
        path += getDirection(da[x][y].S);
        pii nxt = getOppDirection(da[x][y].S);
        x += nxt.F;
        y += nxt.S;
    }
    ans = path;
    reverse(ans.begin(), ans.end());
}

void solve() {
    cin >> n >> m;
    seen = vvb(n + 1, vb(m + 1, false));
    dist = vvi(n + 1, vi(m + 1, oo));
    memset(da, -1, sizeof(da));
    For(i, 1, n) {
        For(j, 1, m) {
            cin >> a[i][j];
            if (a[i][j] == 'M') {
                qm.push({i, j});
                dist[i][j] = 0;
                seen[i][j] = true;
            }
            if (a[i][j] == 'A') {
                sr = i;
                sc = j;
            }
            if (a[i][j] != '#' and touchBound(i, j)) {
                gates.push_back({i, j});
            }
        }
    }
    bfsMonster();
    seen = vvb(n + 1, vb(m + 1, false));
    bfsA();

    bool found = false;
    pii gate;
    for (auto e : gates) {
        if (da[e.F][e.S].F != -1 and da[e.F][e.S].F < dist[e.F][e.S]) {
            gate = e;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "NO" << el;
        return;
    }
    cout << "YES" << el;
    cout << da[gate.F][gate.S].F << el;
    seen = vvb(n + 1, vb(m + 1, false));
    traceBack(gate.F, gate.S);
    cout << ans << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
