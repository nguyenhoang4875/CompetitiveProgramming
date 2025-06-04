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

const int oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;
int n, m, k;
int a[ms], b[ms];
map<int, int> mb, ma;
;

void solve() {
    ma.clear();
    mb.clear();

    cin >> n >> m >> k;
    For(i, 1, n) cin >> a[i];
    For(i, 1, m) {
        cin >> b[i];
        mb[b[i]]++;
    }

    int l = 1, r = m;
    For(i, l, r) { ma[a[i]]++; }

    int same = 0, cnt = 0;
    for (auto eb : mb) {
        if (ma.count(eb.F)) {
            same += min(eb.S, ma[eb.F]);
        }
    }
    if (same >= k) cnt++;

    for (int i = 2; i <= n - m + 1; i++) {
        ma[a[l]]--;
        if (mb.count(a[l])) {
            if (ma[a[l]] >= 0 and ma[a[l]] < mb[a[l]]) {
                same--;
            }
        }
        l++;
        r++;
        ma[a[r]]++;
        if (mb.count(a[r])) {
            if (ma[a[r]] <= mb[a[r]]) same++;
        }
        if (same >= k) cnt++;
    }
    cout << cnt << el;
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