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

//*** START CODING ***//

const long long oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;

struct node {
    int type, cost, idx;
    friend ostream& operator<<(ostream& os, const node& n) {
        return os << n.type << " " << n.cost << " " << n.idx;
    }
};

void solve() {
    int n, m, k, s;
    cin >> n >> m >> k >> s;
    vi a(n + 1), b(n + 1);
    For(i, 1, n) cin >> a[i];
    For(i, 1, n) cin >> b[i];

    vector<node> vn(m + 1);
    For(i, 1, m) {
        cin >> vn[i].type >> vn[i].cost;
        vn[i].idx = i;
    };

    vi pd(n + 1), pp(n + 1, 0);
    pd[0] = pp[0] = oo;
    For(i, 1, n) {
        pd[i] = min(pd[i - 1], a[i]);
        pp[i] = min(pp[i - 1], b[i]);
    }
    // debug(pd); debug(pp);
    vi id, ip;
    auto check = [&](int mid, vector<node> vn) {
        int mnd = pd[mid];
        int mnp = pp[mid];

        sort(vn.begin() + 1, vn.end(), [&](node n1, node n2) {
            int cb1 = (n1.type == 1) ? mnd * n1.cost : mnp * n1.cost;
            int cb2 = (n2.type == 1) ? mnd * n2.cost : mnp * n2.cost;
            if (cb1 == cb2) return n1.idx < n2.idx;
            return cb1 < cb2;
        });
        // debug(mnd); debug(mnp);
        // debug(vn);
        id.clear(), ip.clear();
        int ts = s;
        For(i, 1, k) {
            if (vn[i].type == 1) {
                ts -= mnd * vn[i].cost;
                id.pb(vn[i].idx);
            } else {
                ts -= mnp * vn[i].cost;
                ip.pb((vn[i].idx));
            }
        }
        return ts >= 0;
    };

    int l = 1, r = n, ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid, vn)) {
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    cout << ans << el;
    if (ans == -1) return;
    check(ans, vn);

    int idd = -1, idp = -1;
    for (int i = 1; i <= ans; i++) {
        if (idd == -1 and a[i] == pd[ans]) idd = i;
        if (idp == -1 and b[i] == pp[ans]) idp = i;
    }
    for (auto e : id) { cout << e << " " << idd << el; }
    for (auto e : ip) { cout << e << " " << idp << el; }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs = 1;
    while (tcs--) { solve(); }
    return 0;
}