#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * https://codeforces.com/contest/839/problem/D
 */

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
const int ms = 1e6 + 5;
vi p2(ms);

void init() {
    p2[0] = 1;
    for (int i = 1; i < ms; i++) {
        p2[i] = p2[i - 1] * 2LL % mod;
    }
}

void solve() {
    init();
    int n;
    cin >> n;
    vi cnt(ms, 0);
    For(i, 1, n) {
        int x;
        cin >> x;

        for (int y = 1; y * y <= x; y++) {
            if (x % y == 0) {
                cnt[y]++;
                if (y * y != x) cnt[x / y]++;
            }
        }
    }

    vi f(ms + 1);  // f[g] sum of strength with gcd =  g;
    for (int i = 0; i < ms; i++) {
        if (cnt[i]) {
            f[i] = 1LL * cnt[i] * p2[cnt[i] - 1] % mod;
        }
    }

    int ans = 0;
    for (int i = ms - 1; i > 1; i--) {
        for (int j = 2 * i; j < ms; j += i) {
            f[i] = (f[i] - f[j] + mod) % mod;  // remove overlap
        }
        ans += 1LL * i * f[i];
        ans %= mod;
    }
    cout << ans << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}