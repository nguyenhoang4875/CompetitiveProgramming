#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;

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

const int oo = 1e18, mod = 1e9 + 7;
int n;
int x1, x2, y2, r;

struct plain {
    double x, y, p;
};
plain v[15];

struct NodeTime {
    double t;
    int id;
};
vector<NodeTime> vnt;

vector<vector<double>> t;
double calDist(double x, double y) {
    if (y == 0) {
        return x;
    }
    double ans = 0;
    if (x == x1) {
        ans = (y2 - r - y) + (x2 - x1 - 2 * r) + y2 - 2 * r + x2 - r + 3.0 / 2 * M_PI * r;
    }
    if (y == y2) {
        ans = x2 - x - r + y2 - 2 * r + x2 - r + M_PI * r;
    }
    if (x == x2) {
        ans = y - r + x2 - r + 1.0 / 2 * M_PI * r;
    }

    return ans;
}

void solve() {
    cin >> x1 >> x2 >> y2 >> r;
    double sor = 2 * (x2 - x1 + y2) - 8 * r + 2 * M_PI * r;  // square of a round
    debug(sor);

    cin >> n;
    t.resize(n + 5);
    for (int i = 1; i <= n; i++) {
        double x, y, p;
        cin >> x >> y >> p;
        v[i] = {x, y, p};
        double dist = calDist(x, y);
        debug(dist);
        double tt0 = 0;
        if(p >= dist) {
            tt0 = dist / 10;
            t[i].pb(tt0);
        }
        p -= dist;
        int cnt = 1;
        while(p >= sor) {
            double tt = tt0 + cnt * sor / 10;
            t[i].pb(tt);
            p -= sor;
            cnt++;
        }
        for(auto e: t[i]) {
            vnt.pb({e, i});
        }
    }
    for(int i = 1; i <= n; i++) debug(t[i]);


    sort(vnt.begin(), vnt.end(), [&](NodeTime n1, NodeTime n2) {
        if(n1.t == n2.t) {
            return n1.id < n2.id;
        }
        return n1.t < n2.t;
    });
    for(auto e: vnt) {
        cout << e.t << " " << e.id << '\n';
    }

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}