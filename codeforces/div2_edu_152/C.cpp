#include<bits/stdc++.h>

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

//*** START CODING ***//

int tcs, n, m;

string s, ss;

struct node {
    int a, b;
};

void solve() {
    cin >> n >> m;
    cin >> s;
    ss = s;
    sort(ss.begin(), ss.end());
    cout << s << endl;
    vi v0;
    bool zf = true;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '1') {
            zf = false;
        }
        if(!zf && s[i] == '0') {
            v0.pb(i);
        }

    }

    cout << ss << endl;
    int a, b;
    vector<node> v;
    vi vc[n + 2];
    set<int> si;
    while(m--) {
        cin >> a >> b;
        v.pb({a, b});
        vc[a].pb(b);
        si.insert(a);
    }
    int ans = 0;
    int pre = 0;
    debug(si);
    for(auto e: si) {
        sort(vc[e].begin(), vc[e].end());
        int sz = vc[e].size();
        bool f = true;
        int cnt = 0;
        for(auto b: vc[e]) {
            if(f) {
                for(int l = a; l <= b; l++) {
                    if(s[l] != ss[l]) {
                        cnt++;
                        break;
                    }
                }
                f = false;

            }
            else  {
                for(int l = pre; l <= b; l++ ) {
                    if(s[l] != ss[l]) {
                        cnt++;
                        break;
                    }
                }
            }
            pre = b;
            ans += cnt;
        }
    }
    cout << ans <<'\n';


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