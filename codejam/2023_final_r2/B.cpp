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
#define For(i, a, b) for (int i = (int)a; i <= (int)b; i++)
#define Ford(i, a, b) for (int i = (int)a; i >= (int)b; i--)
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

int prefixSum(int i) {
    int sum = 0;
    while (i > 0) {
        sum += tree[i];
        i -= (i & -i);  // equal: i &= ~(i & -1)  clear right most bit of i
    }
    return sum;
}

int sum(int l, int r) { return prefixSum(r) - prefixSum(l - 1); }

int get(int i) { return sum(i, i); }

void add(int i, int v) {
    while (i <= n) {
        tree[i] += v;
        i += (i & -i);
    }
}

void solve() {
    cin >> n;
    vi a(n + 1);
    tree.resize(n + 1);
    For(i, 1, n) cin >> a[i];
    For(i, 1, n) {
        add(i, a[i]);
    }
    

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}