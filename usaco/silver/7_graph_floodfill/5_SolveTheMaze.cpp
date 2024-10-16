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
const int ms = 50 + 5;
int n, m;
char a[ms][ms];
int totG;
bool fail;
vvb seen;

int dr[4] = {0, 0, -1, 1};
int dc[4] = {-1, 1, 0, 0};

bool inBound(int r, int c) {
    if (r < 1 or r > n or c < 1 or c > m) return false;
    return true;
}

void bfs(int r, int c) {
    seen[r][c] = true;
    queue<pii> q;
    q.push({r, c});
    a[r][c] = '#';

    while (!q.empty()) {
        pii cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = cur.F + dr[i];
            int nc = cur.S + dc[i];

            if (!inBound(nr, nc) or seen[nr][nc] or a[nr][nc] == '#') continue;
            if (a[nr][nc] == 'G') {
                fail = true;
                return;
            }
            seen[nr][nc] = true;
            if (a[nr][nc] == 'B') q.push({nr, nc});
            a[nr][nc] = '#';
        }
    }
}

bool bfs2(int r, int c) {
    seen[r][c] = true;
    queue<pii> q;
    q.push({r, c});
    int cnt = 0;

    while (!q.empty()) {
        pii cur = q.front();
        q.pop();
        if (a[cur.F][cur.S] == 'G') cnt++;

        for (int i = 0; i < 4; i++) {
            int nr = cur.F + dr[i];
            int nc = cur.S + dc[i];

            if (!inBound(nr, nc) or seen[nr][nc] or a[nr][nc] == '#') continue;
            seen[nr][nc] = true;
            q.push({nr, nc});
        }
    }
    return cnt == totG;
}

void solve() {
    cin >> n >> m;
    seen = vvb(n + 1, vb(m + 1, false));
    totG = 0;
    For(i, 1, n) For(j, 1, m) {
        cin >> a[i][j];
        if (a[i][j] == 'G') totG++;
    }
    if (totG == 0) {
        cout << "Yes" << el;
        return;
    }
    fail = false;
    For(i, 1, n) {
        For(j, 1, m) {
            if (a[i][j] == 'B') {
                bfs(i, j);
            }
            if (fail) {
                cout << "No" << el;
                return;
            }
        }
    }

    if (a[n][m] == '#') {
        cout << "No" << el;
        return;
    }

    seen = vvb(n + 1, vb(m + 1, false));
    if (bfs2(n, m)) {
        cout << "Yes" << el;
    } else {
        cout << "No" << el;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs = 1;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}