#include <bits/stdc++.h>
#define int long long

using namespace std;

#define pb push_back
#define LSOne(x) ((x) & -(x))
#define all(x) (x).begin(), (x).end()
#define all1(x) (x).begin() + 1, (x).end()
#define sz(x) static_cast<int>((x).size())
#define el '\n'
#define F first
#define S second
#define Rep(i, n) for (int i = 0; i < (int)n; ++i)
#define For(i, a, b) for (int i = (a); i <= (int)b; ++i)
#define Rof(i, b, a) for (int i = (b); i >= (int)a; --i)
#define Fore(i, v) for (auto i = (v).begin(); i != (v).end(); ++i)

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

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vvc a(n + 1, vc(m + 1));

    For(i, 1, n) For(j, 1, m) { cin >> a[i][j]; }

    vvi pref(n + 1, vi(m + 1));
    For(i, 1, n) {
        For(j, 1, m) { pref[i][j] = (a[i][j] == '*') + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1]; }
    }

    int x = -1, y = -1;
    int best = -1;
    int kk = k - 2;  // inside racket
    for (int i = kk + 1; i <= n - 1; i++) {
        For(j, kk + 1, m - 1) {
            int num = pref[i][j] - pref[i - kk][j] - pref[i][j - kk] + pref[i - kk][j - kk];
            if (num > best) {
                best = num;
                x = i;
                y = j;
            }
        }
    }
    x += 1;
    y += 1;
    int min_x = x - k + 1, min_y = y - k + 1;
    a[min_x][min_y] = a[min_x][y] = a[x][min_y] = a[x][y] = '+';
    for (int i = min_x + 1; i < x; i++) {
        a[i][min_y] = a[i][y] = '|';
    }
    for (int i = min_y + 1; i < y; i++) {
        a[min_x][i] = a[x][i] = '-';
    }

    cout << best << el;
    For(i, 1, n) {
        For(j, 1, m) { cout << a[i][j]; }
        cout << el;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}