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

vii getDirections() {
    vii directions;
    For(i, -1, 1) {
        For(j, -1, 1) {
            if (i == 0 and j == 0) continue;
            directions.pb({i, j});
        }
    }
    return directions;
}

const int oo = 1e18, mod = 1e9 + 7;
const int ms = 102 + 5;
int n, m;
char a[ms][ms];
const string sa = "snuke";

bool inBound(int r, int c) {
    if (r < 1 or r > n or c < 1 or c > m) return false;
    return true;
}

bool check(int r, int c, pii drt) {
    string tmp = "";
    tmp += a[r][c];
    For(i, 1, 4) {
        int nr = r + i * drt.F;
        int nc = c + i * drt.S;
        tmp += a[nr][nc];
    }
    return tmp == sa;
}

void solve() {
    cin >> n >> m;
    For(i, 1, n) {
        For(j, 1, m) { cin >> a[i][j]; }
    }

    vii dirs = getDirections();
    For(i, 1, n) {
        For(j, 1, m) {
            if (a[i][j] != 's') continue;
            for (auto [r, c] : dirs) {
                int lastR = i + 4 * r, lastC = j + 4 * c;
                if (!inBound(lastR, lastC)) continue;
                if (check(i, j, {r, c})) {
                    For(k, 0, 4) {
                        int nr = i + k * r;
                        int nc = j + k * c;
                        cout << nr << " " << nc << el;
                    }
                    return;
                }
            }
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}