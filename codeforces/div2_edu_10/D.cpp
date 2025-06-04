#include<bits/stdc++.h>
#define int long long

using namespace std;

//*** debug(x) ***//
#define DEBUG 0

#if DEBUG
#define del cout <<  '\n'
#define debug(x) cout <<  "[" << #x << "]" << " : " << (x) << endl
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
#define all1(x) (x).begin() + 1, (x).end()
#define el '\n'
#define F first
#define S second
#define Rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
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

template< typename T>
struct SegmentTree {
    int n;
    vector<T> t;
    SegmentTree() {};
    SegmentTree(int _n) {
        n = _n;
        t.resize( 4 * n);
    };
    SegmentTree(vector<T> a, int _n) {
        n = _n;
        t.resize( 4 * n);
        build(a, 1, 1, n);
    };

    void build(const vector<T>& a, int v, int tl, int tr) {
        if (tl == tr) t[v] = a[tl];
        else {
            int tm = (tl + tr) / 2;
            build(a, 2 * v, tl, tm);
            build(a, 2 * v + 1, tm + 1, tr);
            t[v] = combine(t[2 * v], t[2 * v + 1]);
        }
    }

    // !!! Important update base case for INVALID 
    T combine(T v1, T v2) { return v1 + v2; }

    T query(int v, int tl, int tr, int l, int r) {
        if (l > tr || r < tl) return 0; // INVALID
        if (l <= tl && tr <= r) return t[v];

        int tm = (tl + tr) / 2;
        return combine(query(2 * v, tl, tm, l, r), query(2 * v + 1, tm + 1, tr, l, r));
    }

    // update a[pos] = newValue and also update the value of t array
    void update(int v, int tl, int tr, int pos, T newVal) {
        if (tl == tr) t[v] = newVal;
        else {
            int tm = (tl + tr) / 2;
            if (pos <= tm) update(2 * v, tl, tm, pos, newVal);
            else update(2 * v + 1, tm + 1, tr, pos, newVal);
            t[v] = combine(t[2 * v], t[2 * v + 1]);
        }
    }

    int query(int l, int r) { return query(1, 1, n, l, r); }
    void update(int pos, T newVal) { return update(1, 1, n, pos, newVal); }
};

void solve() {
    int n; cin >> n;
    vvi a(n);
    vi vf;
    Rep(i, n) {
        int u, v;
        cin >> u >> v;
        vf.push_back(u);
        a[i] = vi({u, v, i + 1});
    }

    sort(all(a), [&](vi& p1, vi& p2) {
        if(p1[1] == p2[1]) return p1[0] > p2[0];
        return p1[1] < p2[1];
    });

    sort(all(vf));
    vf.resize(unique(all(vf)) - vf.begin());

    auto getIdx = [&vf](int& v) {
        return lower_bound(all(vf), v) - vf.begin() + 1;
    };

    vii ans;
    SegmentTree<int> st(vf.size() + 5);
    for(int i = 0; i < n; i++) {
        int sum = 0;
        int fIdx = getIdx(a[i][0]);
        debug(fi);
        int t = i - st.query(0, fIdx - 1); 
        sum = max(0LL, t);
        ans.push_back({a[i][2], sum});
        st.update(fIdx, 1);
    }
    sort(all(ans), [&](pii& p1, pii& p2) {
        return p1.F < p2.F;
    });
    for(auto [f, s]: ans) {
        cout << s << el; 
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}