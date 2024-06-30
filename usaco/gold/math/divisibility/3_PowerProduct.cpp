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
const int ms = 1e5 + 5;
const int MAX = 1e5;
int n, k;
int a[ms];

void solve() {
    cin >> n >> k;
    For(i, 1, n) cin >> a[i];

    int ans = 0;
    map<vii, int> mp;

    vi maxDiv(MAX + 1, 0);  // max prime of x
    for (int i = 2; i <= MAX; i++) {
        if (maxDiv[i] == 0) {
            maxDiv[i] = i;
            for (int j = i * i; j <= MAX; j += i) {
                maxDiv[j] = i;
            }
        }
    }

    For(i, 1, n) {
        map<int, int> cnt;
        int x = a[i];

        while (x != 1) {
            cnt[maxDiv[x]]++;
            x /= maxDiv[x];
        }

        vii b, c;

        for (auto [f, s] : cnt) {
            int tmp = s % k;
            if (tmp) {
                b.pb({f, tmp});
                c.pb({f, k - tmp});
            }
        }
        ans += mp[c]; // get number fit with a[i]
        mp[b]++;
    }
    cout << ans << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}