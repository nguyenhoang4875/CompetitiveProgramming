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

using vb = vector<bool>;
using vvb = vector<vb>;
using vc = vector<char>;
using vvc = vector<vc>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;

//*** debug(x) ***//
#if 1
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

template <typename T>
void check_here(T x) {
    cout << "------------- " << x << " -------------" << endl;
}
#endif

//*** START CODING ***//

const int oo = 1e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;
int n;
string s, t;
string sp = "atcoder";

void solve() {
    cin >> s >> t;
    map<char, int> cs;
    map<char, int> ct;
    for(auto e: s) {
        cs[e]++;
    }
    for(auto e: t) {
        ct[e]++;
    }
    int cas = cs['@'];
    int cat = ct['@'];
    int diff = 0;
    for(char c = 'a'; c <= 'z'; c++) {
        if(cs[c] == ct[c]) continue;
        bool inSide = false;
        // debug(c);
        for(auto cp: sp) {
            if(c == cp) {
                inSide = true;
                diff += abs(cs[c] - ct[c]);
            }
        }
        // debug(inSide);
        if(!inSide) {
            cout << "No" << el;
            return;
        }
    }
    // debug(diff);
    // debug(cas + cat);
    if(cas + cat >= diff) {
        cout << "Yes" << el;
    } else cout << "No" << el;


    

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}