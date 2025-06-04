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
int n;
char a[ms][ms];

void solve() {
    cin >> n;
    For(i, 1, n) {
        For(j, 1, n) { cin >> a[i][j]; }
    }
    int ans = 0;
    For(i, 1, n / 2) {
        For(j, i, n - i) {
            int zero = 0, one = 0;
            // based-index 1
            a[i][j] == '0' ? zero++ : one++;                  // rotate matrix 0 degree
            a[j][n - i + 1] == '0' ? zero++ : one++;          // rotate matrix 90 degree
            a[n - i + 1][n - j + 1] == '0' ? zero++ : one++;  // rotate matrix 180 degree
            a[n - j + 1][i] == '0' ? zero++ : one++;          // rotate matrix 270 degree
            ans += min(zero, one);
            cout << i << " " << j << el;
            // cout << j << " " << n - i + 1 << el;
            // cout << n - i + 1 << " " << n - j + 1 << el;
            // cout << n - j + 1 << " " << i << el;
            cout << el;
        }
    }
    cout << ans << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}