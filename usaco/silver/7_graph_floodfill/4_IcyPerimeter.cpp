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
const int ms = 1000 + 5;
int n;
char a[ms][ms];
vvb seen;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

bool inBound(int r, int c) {
    if (r < 1 or r > n or c < 1 or c > n) return false;
    return true;
}

int calPer(int r, int c) {
    int ret = 0;
    for (int i = 0; i < 4; i++) {
        int nr = r + dx[i];
        int nc = c + dy[i];
        if (!inBound(nr, nc)) {
            ret++;
            continue;
        }
        if (a[nr][nc] == '.') ret++;
    }
    return ret;
}

pii bfs(int r, int c) {
    seen[r][c] = true;
    int area = 0, per = 0;
    queue<pii> q;
    q.push({r, c});
    while (!q.empty()) {
        pii cur = q.front();
        q.pop();

        per += calPer(cur.F, cur.S);
        area++;

        for (int i = 0; i < 4; i++) {
            int nr = cur.F + dx[i];
            int nc = cur.S + dy[i];

            if (!inBound(nr, nc) or seen[nr][nc] or a[nr][nc] == '.') continue;
            seen[nr][nc] = true;
            q.push({nr, nc});
        }
    }
    return {area, per};
}

void solve() {
    cin >> n;
    For(i, 1, n) {
        For(j, 1, n) { cin >> a[i][j]; }
    }

    seen = vvb(n + 1, vb(n + 1, false));
    int area = 0, per = 0;
    For(i, 1, n) {
        For(j, 1, n) {
            if (a[i][j] == '#' and !seen[i][j]) {
                pii tmp = bfs(i, j);
                if (tmp.F > area) {
                    area = tmp.F;
                    per = tmp.S;
                } else if (tmp.F == area) {
                    per = min(per, tmp.S);
                }
            }
        }
    }
    cout << area << " " << per << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("perimeter.in", "r", stdin);
    freopen("perimeter.out", "w", stdout);

    solve();
    return 0;
}