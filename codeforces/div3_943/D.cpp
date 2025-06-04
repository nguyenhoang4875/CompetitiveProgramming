#include<bits/stdc++.h>
#define int long long

using namespace std;

//*** debug(x) ***//
#define DEBUG 0

#if DEBUG
#define del cout <<  '\n'
#define debug(x) cout <<  "[" << #x << "]" << " : " << (x) << endl
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
#else
#define del
#define debug(x)
#endif

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

const int oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;
int n, k, pa, pb, mxa;
vi p, a;
vi s1, s2;


vi getMoves(int idx) {
    set<int> si;
    vi ans;
    ans.pb(a[idx]);
    if(mxa == a[idx]) return ans;
    si.insert(idx);
    For(i, 2, k) {
        int newIdx = p[idx];
        if(si.count(newIdx)) {
            break;
        }
        si.insert(newIdx);
        ans.pb(a[newIdx]);
        idx = newIdx;
        if(a[newIdx] == mxa) break;
    }
    return ans;
}

int calMax(vi & v) {
    int n = sz(v);
    vi ps(n);
    ps[0] = v[0];
    For(i, 1, n - 1) ps[i] = ps[i - 1] + v[i];

    int sum = v[0] * k;
    int ans = sum;
    
    for(int i = 1; i < min(sz(v), k); i++) {
        sum = ps[i - 1] + (k - i) * v[i];
        ans = max(sum, ans);
    }
    return ans;
}

void solve() {
    cin >> n >> k >> pa >> pb;
    // pa--;
    // pb--;
    p = vi(n + 2);
    a = vi(n + 2);
    For(i, 1, n) {
        int tmp;
        cin >> tmp;
        p[i] = tmp;
    }
    mxa = 0;
    For(i, 1, n) {
        cin >> a[i];
        mxa = max(a[i], mxa);
    } 

    s1.clear();
    s2.clear();
    
    s1 = getMoves(pa);
    s2 = getMoves(pb);

    debug(s1);
    debug(s2);

    int ans1 = calMax(s1);
    int ans2 = calMax(s2);

    if(ans1 == ans2) {
        cout << "Draw" << el;
        return;
    }
    if(ans1 > ans2) {
        cout << "Bodya" << el;
        return;
    }
    cout << "Sasha" << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs = 1;
    cin >> tcs;
    while(tcs--) {
        solve();
    }
    return 0;
}