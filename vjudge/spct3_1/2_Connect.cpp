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
const int ms = 1e2 + 5;

int n;
char a[ms][ms];
int r1, c1, r2, c2;

int dr[4] = {0, 0, -1, 1};
int dc[4] = {-1, 1, 0, 0};

struct node {
    int r, c, dist;
};

bool inBound(int r, int c) {
    if (r < 1 or r > n or c < 1 or c > n) return false;
    return true;
}
set<pii> getArea(int r, int c) {
    set<pii> st;
    queue<pii> q;
    q.push({r, c});
    vvb seen(n + 1, vb(n + 1, false));
    seen[r][c] = true;
    while (!q.empty()) {
        pii cur = q.front();
        st.insert(cur);
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = cur.F + dr[i];
            int nc = cur.S + dc[i];
            if (!inBound(nr, nc) or seen[nr][nc] or a[nr][nc] == '1') continue;
            q.push({nr, nc});
            seen[nr][nc] = true;
        }
    }
    return st;
};

void solve() {
    cin >> n;
    cin >> r1 >> c1;
    cin >> r2 >> c2;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    int ans = oo;
    set<pii> st1 = getArea(r1, c1);
    set<pii> st2 = getArea(r2, c2);

    for (auto e1 : st1) {
        for (auto e2 : st2) {
            ans = min(ans, (e1.F - e2.F) * (e1.F - e2.F) + (e1.S - e2.S) * (e1.S - e2.S));
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