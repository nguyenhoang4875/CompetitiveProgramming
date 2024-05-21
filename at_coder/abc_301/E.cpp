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

const int oo = 1e18, mod = 1e9 + 7;
const int ms = 3e2 + 5;
int n, m, t;
char a[ms][ms];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

bool inBound(int r, int c) {
    if (r < 0 or r >= n or c < 0 or c >= m) return false;
    return true;
}

void solve() {
    cin >> n >> m >> t;

    For(i, 0, n - 1) {
        For(j, 0, m - 1) { cin >> a[i][j]; }
    }

    const string sp = "SoG";
    vii vp;
    for (auto e : sp) {
        For(i, 0, n - 1) {
            For(j, 0, m - 1) {
                if (e == a[i][j]) {
                    vp.pb({i, j});
                }
            }
        }
    }
    int pz = sz(vp);
    vvi dist(pz, vi(pz));

    for (int i = 0; i < pz; i++) {
        queue<pii> q;
        vvi d(n, vi(m, -1));
        q.push(vp[i]);
        d[vp[i].F][vp[i].S] = 0;

        while (!q.empty()) {
            pii cur = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nx = cur.F + dx[k];
                int ny = cur.S + dy[k];
                if (!inBound(nx, ny) || d[nx][ny] != -1) continue;
                if (a[nx][ny] == '#') continue;
                d[nx][ny] = d[cur.F][cur.S] + 1;
                q.push({nx, ny});
            }
        }
        for (int j = 0; j < pz; j++) {
            dist[i][j] = d[vp[j].F][vp[j].S];
        }
    }

    // have dist all pair SoG
    vvi dp(1 << pz, vi(pz + 1, t + 1));
    dp[1][0] = 0;

    // use dp bitmask to find max candy
    int ans = -1;

    // mask alway have the last bit is 1
    for (int mask = 1; mask < (1 << pz); mask += 2) {
        if (dp[mask][pz - 1] <= t) {
            // first is S and last is G: then count bit 1 - 2
            ans = max(ans, (int)__builtin_popcount(mask) - 2);
        }
        for (int from = 0; from < pz; from++) {
            if ((mask >> from) & 1) {
                for (int to = 0; to < pz; to++) {
                    if (!((mask >> to) & 1) and dist[from][to] != -1) {
                        int newMask = mask ^ (1 << to);
                        dp[newMask][to] = min(dp[newMask][to], dp[mask][from] + dist[from][to]);
                    }
                }
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