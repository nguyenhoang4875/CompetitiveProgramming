#include <bits/stdc++.h>
#define int long long

using namespace std;

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
const int ms = 1e5 + 5;
int a[ms], b[ms], psa[ms], psb[ms];
int na, nb;

void solve() {
    cin >> na;
    For(i, 1, na) cin >> a[i];
    For(i, 1, na) psa[i] = psa[i - 1] + a[i];

    cin >> nb;
    For(i, 1, nb) cin >> b[i];
    For(i, 1, nb) psb[i] = psb[i - 1] + b[i];

    map<int, int> m;
    For(i, 1, na) m[a[i]] = i;

    int ans = 0;
    vii pos;
    pii lastPos;
    For(ib, 1, nb) {
        if (m.count(b[ib])) {
            int ia = m[b[ib]];
            if (pos.empty()) {
                ans += max(psa[ia], psb[ib]);
            } else {
                lastPos = pos.back();
                ans += max(psa[ia] - psa[lastPos.F], psb[ib] - psb[lastPos.S]);
            }
            pos.pb({ia, ib});
        }
    }
    if (!pos.empty()) {
        lastPos = pos.back();
        ans += max(psa[na] - psa[lastPos.F], psb[nb] - psb[lastPos.S]);
    } else {
        ans = max(psa[na], psb[nb]);
    }
    cout << ans << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}