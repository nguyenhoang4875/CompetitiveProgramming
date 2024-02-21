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

//*** debug(x) ***//
#define debug(x) cout << "[" << #x << "]" << " : " << (x) << endl

#if 1
template <class Ch, class Tr, class Container>
basic_ostream <Ch, Tr> & operator << (basic_ostream <Ch, Tr> & os, Container const& x) {
    os << "{ ";
    for(auto& y : x)os << y << ", ";
    return os << "}";
}

template <class X, class Y>
ostream & operator << (ostream & os, pair <X, Y> const& p) {
    return os << "(" << p.first << ", " << p.second << ")" ;
}
#endif

template<typename T>
void check_here(T x){
    cout << "------------- " << x << " -------------" << endl;
}

using vb = vector<bool>;
using vvb = vector<vb>;
using vc = vector<char>;
using vvc = vector<vc>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;

//*** START CODING ***//

struct Dsu {
    Dsu(){};
    Dsu(int n) {
        parent = vector<int>(n + 1);
        size = vector<int>(n + 1);
        for(int v = 0; v < n; v++) makeSet(v);
    };

    vector<int> parent, size;
    void makeSet(int v) {
        parent[v] = v;
        size[v] = 1;  // init size = 1;
    }

    int findSet(int v) {
        return parent[v] = (parent[v] == v ? v : findSet(parent[v]));
    }

    void unionSet(int a, int b) {
        a = findSet(a);
        b = findSet(b);
        if (a != b) {
            if (size[a] < size[b])
                swap(a, b);  // set a is root of the bigger size of tree
            parent[b] = a;
            size[a] += size[b];  // update the new size of new the merge tree
        }
    }
};


const int oo = 1e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;
int n, m;
int v[ms];

struct edge {
    int u, v, w;
};
vector<edge> vp;


void solve() {
    cin >> n >> m;
    For(i, 0, n - 1) cin >> v[i];
    vp = vector<edge>(m);
    For(i, 0, m - 1) {
        int a, b, w;
        cin >> a >> b >> w;
        --a, --b; // for base-index 0
        vp[i] = {a, b, w};
    }
    int maxMask = (1 << n) - 1;
    int inSet = -1;
    int ans = 0; // for mask = 0;
    For(mask, 1, maxMask) {
        // debug(mask);
        Dsu dsu(n);
        int sum = 0;

        Ford(i, n - 1, 0) {
            if((mask >> i) & 1) {
                // debug(i);
                if(inSet == -1) {
                    inSet = i;
                } else {
                    dsu.unionSet(inSet, i);
                }
                // debug(v[i]);
                sum += v[i];
            }
        }
        for(auto e: vp) {
            int u = dsu.findSet(e.u);
            int v = dsu.findSet(e.v);
            inSet = dsu.findSet(inSet);

            // debug(inSet);
            // debug(u);
            // debug(v);
            if(u == v) continue;

            if(u == inSet) {
                sum -= e.w;
            }
            // if(v == inSet) {
            //     sum += e.w;
            // }
        }
        // debug(sum);
        ans = max(ans, sum);
    }
    cout << ans << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs;
    cin >> tcs;
    while(tcs--) solve();
    return 0;
}