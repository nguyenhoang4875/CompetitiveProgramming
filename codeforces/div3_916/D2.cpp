#include <bits/stdc++.h>
#define int long long

using namespace std;

//*** debug(x) ***//
#define debug(x)             \
    cout << "[" << #x << "]" \
         << " : " << (x) << endl

#if 1
template <class Ch, class Tr, class Container>
basic_ostream<Ch, Tr>& operator<<(basic_ostream<Ch, Tr>& os,
                                  Container const& x) {
    os << "{ ";
    for (auto& y : x) os << y << ", ";
    return os << "}";
}

template <class X, class Y>
ostream& operator<<(ostream& os, pair<X, Y> const& p) {
    return os << "(" << p.first << ", " << p.second << ")";
}
#endif

template <typename T>
void check_here(T x) {
    cout << "------------- " << x << " -------------" << endl;
}

//*** define ***//
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(i, a, b) for (int i = a; i <= (int)b; i++)
#define Ford(i, a, b) for (int i = a; i >= (int)b; i--)
#define Fore(it, x) for (auto it = x.begin(); it != x.end(); ++it)

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

const int oo = 1e18, mod = 1e9 + 7;
const int ms = 1e5 + 5;
int n;
int ans = 0;
int hv[10];
struct act {
    int point, id, type;
};
vector<act> a, b, c;
bool cmp(act a1, act a2) { return a1.point > a2.point; }

void gen(int i, int n) {
    if(i == n) {
        // do

        // For(i, 0, n - 1) {
        //     cout << hv[i] << " ";
        // }
        // cout << el;

        int sum = 0;
        if (a[hv[0]].id != b[hv[1]].id
                && a[hv[0]].id != c[hv[2]].id
                && b[hv[1]].id != c[hv[2]].id) {
            if (a[hv[0]].type != b[hv[1]].type &&
                a[hv[0]].type != c[hv[2]].type &&
                b[hv[1]].type != c[hv[2]].type) {
                sum += a[hv[0]].point + b[hv[1]].point + c[hv[2]].point;
                // cout << "sum = " << sum << el;
                ans = max(ans, sum);
            }
        }
        return;
    }
    for(int j = 0; j < n; j++) {
        hv[i] = j;
        gen(i + 1, n);
    }
}

void solve() {
    cin >> n;
    int x;
    a.clear();
    b.clear();
    c.clear();
    ans = 0;
    For(i, 1, n) {
        cin >> x;
        a.pb({x, i, 1});
    }
    For(i, 1, n) {
        cin >> x;
        b.pb({x, i, 2});
    }
    For(i, 1, n) {
        cin >> x;
        c.pb({x, i, 3});
    }
    sort(all(a), cmp);
    sort(all(b), cmp);
    sort(all(c), cmp);
    set<int> s_type;
    set<int> s_id;
    gen(0, 3);
    cout << ans << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs;
    cin >> tcs;
    // tcs = 1;
    while (tcs--) {
        solve();
    }
    return 0;
}