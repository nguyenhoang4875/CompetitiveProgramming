#include <bits/stdc++.h>
#define int long long

using namespace std;

//*** debug(x) ***//
#define debug(x)             \
    cout << "[" << #x << "]" \
         << " : " << (x) << endl

#if 1
template <class Ch, class Tr, class Container>
basic_ostream<Ch, Tr>& operator<<(basic_ostream<Ch, Tr>& os, Container const& x) {
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
#define F first
#define S second
#define For(_i, _a, _b) for (int _i = (_a); _i <= (_b); _i++)
#define Ford(_i, _a, _b) for (int _i = (_a); _i >= (_b); _i--)
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

vi tree;



void update(int v, int tl, int tr, int pos, int newVal) {
    if (tl == tr)
        tree[v] = newVal;
    else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(2 * v, tl, tm, pos, newVal);
        else
            update(2 * v + 1, tm + 1, tr, pos, newVal);
        tree[v] = tree[2 * v] + tree[2 * v + 1];
    }
}

int getSum(int v, int tl, int tr, int l, int r) {
    if(tl > r or tr < l) return 0;
    if(l <= tl and tr <= r) return tree[v];

    int tm = (tl + tr) / 2;
    return getSum(2 * v, tl, tm, l, r) + getSum(2 * v + 1, tm + 1, tr, l, r);
}


void solve() {
    cin >> n;
    vi a(n + 1);
    vi index[n + 1];
    tree.clear();
    tree.resize(4 * n);
    For(i, 1, n) {
        cin >> a[i];
        a[i] = min(a[i], n); // only get max value at n 
        update(1, 1, n, i, 1);
        index[a[i]].pb(i);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        // condition: a[i] >= j and a[j] >= i => a[j] in range [i + 1, a[i]]
        // only count form: [i + 1, a[i]]
        ans += getSum(1, 1, n, i + 1, a[i]);

        for (int j = 0; j < index[i].size(); j++) {
            update(1, 1, n, index[i][j], 0);
        }
    }

    cout << ans << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}