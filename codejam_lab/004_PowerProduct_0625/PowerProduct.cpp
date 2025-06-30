#include <bits/stdc++.h>
#define int long long

using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define all1(x) (x).begin() + 1, (x).end()
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
    int n, k;
    cin >> n >> k;
    vi a(n + 1);
    For(i, 1, n) cin >> a[i];

    const int mx = 1e5;
    vi maxDiv(mx + 1);  // max div prime of x
    maxDiv[1] = 1;
    for (int i = 2; i <= mx; i++) {
        if (maxDiv[i] != 0) continue;  // i is not prime number
        for (int j = i; j <= mx; j += i) {
            maxDiv[j] = i;
        }
    }

    map<vii, int> mapFactor;
    int ans = 0;
    For(i, 1, n) {
        map<int, int> cnt;
        int x = a[i];
        while (x != 1) {
            cnt[maxDiv[x]]++;
            x /= maxDiv[x];
        }

        vii pFactor, need;
        for (auto &[f, s] : cnt) {
            s %= k;
            if (s) {
                pFactor.pb({f, s});
                need.pb({f, k - s});
            }
        }
        ans += mapFactor[need];
        mapFactor[pFactor]++;
    }
    cout << ans << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}