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
const int ms = 500 + 5;
int n, m;
int a[ms][ms], b[ms][ms];
vvb seen;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

bool inBound(int r, int c) {
    if (r < 1 or r > n or c < 1 or c > m) return false;
    return true;
}

void solve() {
    cin >> n >> m;
    For(i, 1, n) {
        For(j, 1, m) { cin >> a[i][j]; }
    }
    int tot1 = 0;
    int r1 = 0, c1 = 0;
    For(i, 1, n) {
        For(j, 1, m) {
            cin >> b[i][j];
            if (b[i][j] == 1) {
                tot1++;
                r1 = i;
                c1 = j;
            }
        }
    }
    if (tot1 == 0) {
        cout << 0 << el;
        return;
    }

    auto check = [&](int d) {
        seen = vvb(n + 1, vb(m + 1, false));
        seen[r1][c1] = true;
        queue<pii> q;
        q.push({r1, c1});

        int cnt = 0;
        while (!q.empty()) {
            pii cur = q.front();
            q.pop();
            if (b[cur.F][cur.S] == 1) cnt++;
            for (int i = 0; i < 4; i++) {
                int nr = cur.F + dx[i];
                int nc = cur.S + dy[i];

                if (!inBound(nr, nc) or seen[nr][nc]) continue;
                if (abs(a[nr][nc] - a[cur.F][cur.S]) > d) continue;
                seen[nr][nc] = true;
                q.push({nr, nc});
            }
        }
        return cnt == tot1;
    };

    int l = 0, r = 1e9;
    int ans = -1;

    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        } else
            l = mid + 1;
    }
    cout << ans << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("ccski.in", "r", stdin);
    freopen("ccski.out", "w", stdout);

    solve();
    return 0;
}