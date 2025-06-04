#include <bits/stdc++.h>
#define int long long

using namespace std;

//*** debug(x) ***//
#define DEBUG 1

#if DEBUG
#define del cout << '\n'
#define debug(x) cout << "[" << #x << "]" << " : " << (x) << endl
template <class X, class Y>
ostream& operator<<(ostream& os, pair<X, Y> const& p) {
    return os << "(" << p.first << ", " << p.second << ")";
}
template <class Ch, class Tr, class Container>
basic_ostream<Ch, Tr>& operator<<(basic_ostream<Ch, Tr>& os, Container const& x) {
    os << "{ ";
    for (const auto& y : x) os << y << ", ";
    return os << "}";
}
#else
#define del
#define debug(x)
#endif

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
const int ms = 2e5 + 5;

void solve() {
    int n;
    cin >> n;
    vi a(n + 1), b(n + 1);
    For(i, 1, n) cin >> a[i];
    For(i, 1, n) cin >> b[i];

    vii sub;
    int sameValIdx = -1;
    bool ok = true;
    map<pii, vi> m1, m2;
    For(i, 1, n) {
        if (a[i] == b[i]) {
            if (n % 2 == 0 || sameValIdx != -1) {
                ok = false;
                break;
            }
            sameValIdx = i;
        } else {
            pii key = {min(a[i], b[i]), max(a[i], b[i])};
            if (a[i] < b[i]) m1[key].pb(i);
            else m2[key].pb(i);
        }
    }
    if (!ok) {
        cout << -1 << "\n";
        return;
    }
    for (auto& e : m1) {
        auto key = e.F;
        auto& v1 = e.S;
        auto& v2 = m2[key];
        if (v1.size() != v2.size()) {
            ok = false;
            break;
        }
        for (int j = 0; j < v1.size(); j++) {
            int i1 = v1[j], i2 = v2[j];
            if (i1 > i2) swap(i1, i2);
            sub.pb({i1, i2});
        }
    }
    for (auto& e : m2) {
        if (m1.find(e.F) == m1.end()) {
            ok = false;
            break;
        }
    }
    if (n & 1) {
        if (sub.size() != (n - 1) / 2 or sameValIdx == -1) ok = false;
    } else {
        if (sub.size() != n / 2 or sameValIdx != -1) ok = false;
    }
    if (!ok) {
        cout << -1 << el;
        return;
    }

    vi C(n + 1), pos(n + 1);
    for (int i = 1; i <= n; i++) {
        C[i] = i;
        pos[i] = i;
    }

    vi f(n + 1, 0);
    int l = 1, r = n;
    for (auto& p : sub) {
        f[p.F] = l;
        f[p.S] = r;
        l++;
        r--;
    }
    if (sameValIdx != -1) f[sameValIdx] = (n + 1) / 2;

    vector<int> D(n + 1, 0);
    for (int i = 1; i <= n; i++) D[f[i]] = i;

    vii ans;
    for (int p = 1; p <= n; p++) {
        if (C[p] == D[p]) continue;
        int x = D[p], curPos = pos[x];
        ans.pb({p, curPos});
        swap(C[p], C[curPos]);
        pos[C[p]] = p;
        pos[C[curPos]] = curPos;
    }
    cout << ans.size() << el;
    for (auto e : ans) { cout << e.F << " " << e.S << el; }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs = 1;
    cin >> tcs;
    while (tcs--) { solve(); }
    return 0;
}