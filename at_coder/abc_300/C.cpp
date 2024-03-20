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
const int ms = 1e2 + 5;
int n, m;
char a[ms][ms];

bool inBound(int r, int c) {
    if (r < 1 or r > n or c < 1 or c > m) return false;
    return true;
}

bool check(int r, int c, int d) {
    for (auto dr : {-d, d}) {
        for (auto dc : {-d, d}) {
            int nr = r + dr;
            int nc = c + dc;
            if (!inBound(nr, nc) or a[nr][nc] != '#') return false;
        }
    }
    return true;
}

void solve() {
    cin >> n >> m;
    For(i, 1, n) {
        For(j, 1, m) { cin >> a[i][j]; }
    }
    int asz = min(n, m);
    vi ans(asz + 1);
    For(i, 1, n) {
        For(j, 1, m) {
            if (a[i][j] != '#') continue;
            if (check(i, j, 1)) {
                int d = 1;
                while (check(i, j, d + 1)) d++;
                ans[d]++;
            }
        }
    }
    For(i, 1, asz) {
        cout << ans[i] << " ";
    }
    cout << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}