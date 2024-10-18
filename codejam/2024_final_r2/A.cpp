#include <bits/stdc++.h>
#define int long long

using namespace std;

//*** define ***//
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(i, a, b) for (int i = (a); i <= (int)(b); i++)
#define Rof(i, a, b) for (int i = (a); i >= (int)(b); i--)
#define Fore(it, x) for (auto it = (x).begin(); it != (x).end(); ++it)

//*** custom using ***//
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
int n, m;
string w;

void solve() {
    cin >> n >> m;
    cin >> w;
    w += w;
    vii v;
    for (int i = 0; i < m; i++) {
        int s, g;
        cin >> s >> g;
        s--;  // index 0
        v.pb({s, g});
    }
    vi psa(2 * n, 0), psb(2 * n, 0);
    for (int i = 0; i < 2 * n; i++) {
        if (i == 0) {
            if (w[i] == 'A')
                psa[0] = 1;
            else
                psb[0] = 1;
            continue;
        }
        psa[i] = psa[i - 1] + (w[i] == 'A');
        psb[i] = psb[i - 1] + (w[i] == 'B');
    }

    int ret = 0;
    for (auto [s, g] : v) {
        int start = s;
        int end = s + g - 1;

        int minWin = (g + 1) / 2;
        int ma = lower_bound(psa.begin(), psa.end(), (s == 0 ? 0 : psa[s - 1]) + (minWin)) -
                 (psa.begin() + s) + 1;
        int mb = lower_bound(psb.begin(), psb.end(), (s == 0 ? 0 : psb[s - 1]) + (minWin)) -
                 (psb.begin() + s) + 1;
        ret += min(ma, mb);
    }
    cout << ret << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs = 1;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}