#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define F first
#define S second
#define For(_i, _a, _b) for (int _i = (_a); _i <= (_b); _i++)
#define Ford(_i, _a, _b) for (int _i = (_a); _i >= (_b); _i--)
#define Fore(it, x) for (auto it = x.begin(); it != x.end(); ++it)

using namespace std;

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
const int ms = 105;
int n;
int a[ms][ms];

int check(int i, int j, int len) {
    if(i - len < 1 || i + len > n || j - len < 1 || j + len > n) return false;
    return true;
}

void solve() {
    cin >> n;
    For(i, 1, n) {
        For(j, 1, n) { cin >> a[i][j]; }
    }
    int cnt = 0;
    For(i, 1, n) {
        For(j, 1, n) {
            For(len, 0, n / 2 + 1) {
                if(!check(i, j, len)) continue;
                int sum1 = 0;
                For(r, i - len, i + len) sum1 += a[r][j];
                if(sum1 != 3 * a[i][j]) continue;
                int sum2 = 0;
                For(c, j - len, j + len) sum2 += a[i][c];
                if(sum2 == 3 * a[i][j]) cnt++;
            }
        }
    }
    cout << cnt << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}