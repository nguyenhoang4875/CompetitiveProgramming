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
#define Rof(i, a, b) for (int i = a; i >= (int)b; i--)
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

const int oo = 2e18, mod = 1e9 + 7;
const int ms = 2e7 + 5;

vi mind(ms, -1);  // minimum prime divisor fo i
vi val(ms);       // the number of prime divisors of i

void init() {
    mind[1] = 1;
    for (int i = 2; i < ms; i++) {
        if (mind[i] == -1) {
            mind[i] = i;
            for (int j = i * i; j < ms; j += i) {
                if (mind[j] == -1) mind[j] = i;
                // mind[j] = i;
            }
        }
    }

    for (int i = 2; i < ms; i++) {
        int j = i / mind[i];
        val[i] = val[j] + (mind[i] != mind[j]);
    }
}

void solve() {
    int c, d, x;
    cin >> c >> d >> x;
    int ans = 0;
    for (int i = 1; i * i <= x; i++) {
        if (x % i != 0) continue;
        int k1 = i + d;
        if (k1 % c == 0) ans += 1 << val[k1 / c];
        if (i * i == x) continue;
        int k2 = x / i + d;
        if (k2 % c == 0) ans += 1 << val[k2 / c];
    }
    cout << ans << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();
    int tcs = 1;
    cin >> tcs;
    while (tcs--) solve();

    return 0;
}