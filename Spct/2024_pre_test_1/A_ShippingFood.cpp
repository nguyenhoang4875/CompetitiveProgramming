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
const int ms = 2e5 + 5;
int n, t;
int a[ms], b[ms];

int sumPair(pii p) { return p.F + p.S; }

void solve() {
    cin >> n >> t;
    For(i, 0, n - 1) cin >> a[i];
    For(i, 0, n - 1) cin >> b[i];

    int cnt = 0, sum = 0;
    For(i, 0, n - 1) {
        int ct = 0, st = 0;
        vii v = vii(n);
        For(j, 0, n - 1) {
            int bVal = b[j];
            if (i == j) bVal = 0;
            v[j] = {a[j], bVal};
        }
        sort(all(v), [&](pii p1, pii p2) { return p1.F + p1.S < p2.F + p2.S; });

        int k = 0;
        for (k = 0; k < n; k++) {
            if (st + sumPair(v[k]) <= t) {
                st += sumPair(v[k]);
                ct++;
            } else {
                if (cnt < ct or (cnt == ct and sum > st)) {
                    cnt = ct;
                    sum = st;
                }
                break;
            }
        }
        if (k == n) {
            if (cnt < ct or (cnt == ct and sum > st)) {
                cnt = ct;
                sum = st;
            }
        }
    }
    cout << cnt << " " << sum << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}