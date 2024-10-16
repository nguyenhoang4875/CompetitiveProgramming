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
int n, k, r;
vvb seen;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

bool inBound(int r, int c) {
    if (r < 1 or r > n or c < 1 or c > n) return false;
    return true;
}

void solve() {
    cin >> n >> k >> r;
    set<vi> st;

    for (int i = 1; i <= r; i++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        st.insert({r1, c1, r2, c2});
    }
    set<pii> a;
    for (int i = 1; i <= k; i++) {
        int rr, cc;
        cin >> rr >> cc;
        a.insert({rr, cc});
    }
    seen = vvb(n + 1, vb(n + 1, false));

    auto bfs = [&](int r, int c) {
        int cnt = 0;
        queue<pii> q;
        q.push({r, c});
        seen[r][c] = true;

        while (!q.empty()) {
            pii cur = q.front();
            q.pop();
            if (a.count({cur.F, cur.S})) cnt++;

            for (int i = 0; i < 4; i++) {
                int nr = cur.F + dx[i];
                int nc = cur.S + dy[i];

                if (!inBound(nr, nc) or seen[nr][nc]) continue;
                // check has road;
                if (st.count({cur.F, cur.S, nr, nc}) or st.count({nr, nc, cur.F, cur.S})) continue;
                seen[nr][nc] = true;
                q.push({nr, nc});
            }
        }
        return cnt * (cnt - 1) / 2;
    };

    int numPair = 0;
    for (auto e : a) {
        if (!seen[e.F][e.S]) numPair += bfs(e.F, e.S);
    }

    int ans = k * (k - 1) / 2 - numPair;
    cout << ans << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("countcross.in", "r", stdin);
    freopen("countcross.out", "w", stdout);

    solve();
    return 0;
}