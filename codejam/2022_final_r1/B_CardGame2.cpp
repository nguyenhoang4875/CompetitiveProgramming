#include<bits/stdc++.h>

using namespace std;
/**
 * Problem: https://codejam.lge.com/problem/24432
 * Solution: Brute force
 *  - 1. Gen binary to sum k number of a and b
 *  - 2. Find min by merge to vector sum in #1
 *  - 3. Find min by sort vector in #2
 *  - 4. Find max
 * TC: O(2 ^ n) (n = 20 2^20 = 1048576 ~ 10 ^ 6) => AC
 * MC: O(m + n)
 * Improve: Using gen C(k, n) instead of gen binary => O(C(10, 20) ~ 2*10^5);
*/

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

//*** define ***//
#define int long long
#define pb push_back
#define FOR(_i,_a,_b) for(int _i = (_a); _i < (_b); _i++)
#define FORI(_i,_a,_b) for(int _i = (_a); _i <= (_b); _i++)
#define FORE(it,x) for(auto it = x.begin(); it != x.end(); ++it)

//*** custom using ***//
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;
using pii = pair<int, int>;

//*** START CODING ***//

const int oo = 1e18;

int tcs, n, m, k;
int a[25];
int b[25];
int ga[25];
int gb[25];
bool ca[25];
bool cb[25];

vi voa;
vi vob;

void calA() {
    int sum = 0;
    for(int i = 1; i <= k; i++) {
        sum += a[ga[i]];
    }
    voa.pb(sum);
}
void calB() {
    int sum = 0;
    for(int i = 1; i <= k; i++) {
        sum += b[gb[i]];
    }
    vob.pb(sum);
}

void gena(int idx) {
    if(idx > k) {
        // for(int i = 1; i <= k; i++) cout << ga[i] << " ";
        // cout << '\n';
        calA();
        return;
    }
    for(int val = 1; val <= n; val++) {
        if(ca[val]) continue;
        if(idx > 1 && ga[idx - 1] > val) continue;
        ca[val] = true;
        ga[idx] = val;
        gena(idx + 1);
        ca[val] = false;
    }
}
void genb(int idx) {
    if(idx > k) {
        // for(int i = 1; i <= k; i++) cout << ga[i] << " ";
        // cout << '\n';
        calB();
        return;
    }
    for(int val = 1; val <= m; val++) {
        if(cb[val]) continue;
        if(idx > 1 && gb[idx - 1] > val) continue;
        cb[val] = true;
        gb[idx] = val;
        genb(idx + 1);
        cb[val] = false;
    }
}

void clearData() {
    for(int i = 1; i < 25; i++) {
        ga[i] = gb[i] = 0;
        ca[i] = cb[i] = false;
    }
}

void solve() {
    cin >> n >> m >> k;
    voa.clear();
    vob.clear();
    clearData();
    FORI(i, 1, n) cin >> a[i];
    FORI(i, 1, m) cin >> b[i];

    gena(1);
    genb(1);

    vector<pii> vp;
    for(auto e: voa) {
        vp.pb({e, 0});
    }

    for(auto e: vob) {
        vp.pb({e, 1});
    }

    sort(vp.begin(), vp.end(), [&](pii p1, pii p2) {
        if(p1.first == p2.first) return p1.second != p2.second;
        return p1.first < p2.first;
    });
    int sz = vp.size();
    // debug(vp);
    int minAns = oo;
    for(int i = 1; i < sz; i++) {
        if(vp[i - 1].second != vp[i].second) {
            minAns = min(minAns, abs(vp[i - 1].first - vp[i].first));
            if(minAns == 0) break; // optimize when find best of min
        }
    }
    sort(voa.begin(), voa.end());
    sort(vob.begin(), vob.end());
    int maxAns = max(abs(voa.back() - vob.front()), abs(vob.back() - voa.front()));
    cout << minAns << " " << maxAns << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> tcs;
    while(tcs--) {
        solve();
    }
    return 0;
}