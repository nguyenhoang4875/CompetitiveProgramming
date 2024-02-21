#include<bits/stdc++.h>
#define int long long

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

struct act {
    int point, id, type;
};

bool cmp(act a1, act a2) {
    return a1.point > a2.point;
}

void solve() {
    cin >> n;
    vector<act> a, b, c;
    int x;
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
    vector<act> ans;
    int kk = min(n - 1, 3LL);
    For(i, 0, kk) {
        ans.pb(a[i]);
        ans.pb(b[i]);
        ans.pb(c[i]);
    }
    sort(all(ans), cmp);

    int sum = 0;
    set<int> s_type;
    set<int> s_id;
    for(int i = 0; i < sz(ans); i++) {
        act e = ans[i];
        if(sz(s_type) == 3) break;
        if(s_type.empty()) {
            sum += e.point;
            s_type.insert(e.type);
            s_id.insert(e.id);
        } else {
            if(s_type.count(e.type) || s_id.count(e.id)) continue;
            sum += e.point;
            s_type.insert(e.type);
            s_id.insert(e.id);
        }
    }
    cout << sum << el;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs;
    cin >> tcs;
    while(tcs--) {
        solve();
    }
    return 0;
}