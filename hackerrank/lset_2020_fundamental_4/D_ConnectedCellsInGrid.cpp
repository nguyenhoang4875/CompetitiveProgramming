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
const int ms = 1e5 + 5;
int n, m;
int a[105][105];
int cnt;
vvb seen;

bool inBound(int r, int c) {
    if (r < 1 or r > n or c < 1 or c > m) return false;
    return true;
}

void dfs(int r, int c) {
    cnt++;
    seen[r][c] = true;
    For(dr, -1, 1) {
        For(dc, -1, 1) {
            if (dr == 0 and dc == 0) continue;
            int nr = r + dr;
            int nc = c + dc;
            if (!inBound(nr, nc) || seen[nr][nc] || a[nr][nc] == 0) continue;
            dfs(nr, nc);
        }
    }
}

void solve() {
    cin >> n >> m;
    For(i, 1, n) {
        For(j, 1, m) { cin >> a[i][j]; }
    }
    seen = vvb(n + 1, vb(m + 1, false));
    int ans = 0;
    For(i, 1, n) {
        For(j, 1, m) {
            cnt = 0;
            if (!seen[i][j] && a[i][j] == 1) {
                dfs(i, j);
            }
            ans = max(ans, cnt);
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