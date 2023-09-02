#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;

using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;
using pii = pair<int, int>;

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

//*** START CODING ***//

int tcs, n;

void solve() {
    cin >> n;
    vi odd;
    vi even;
    vi io;
    vi ie;
    for(int i = 1; i <= n; i++) {
       int x; 
       cin >> x;
       if(x & 1) {
        io.pb(i);
        odd.pb(x);
       } 
       else {
        ie.pb(i);
        even.pb(x);
       }
    }

    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());

    // debug(io);
    // debug(odd);

    // debug(ie);
    // debug(even);
    int found = true;
    int pre = 0;
    int cur = 0;
    for(int i = 1; i <= n; i++) {
        if(!io.empty() && io.front() == i) {
            cur = odd.front();
            io.erase(io.begin());
            odd.erase(odd.begin());
            if(i == 1) continue;
            if(pre > cur) {
                found = false;
                break;
            }
        }
        if(!ie.empty() && ie.front() == i) {
            cur = even.front();
            ie.erase(ie.begin());
            even.erase(even.begin());
            if(i == 1) continue;
            if(pre > cur) {
                found = false;
                break;
            }
        }
        pre = cur;
    }
    // cout << "abc" << endl;
    if(found) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}