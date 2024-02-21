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
string s;

bool isV(char c) {
    if(c == 'a' or c == 'e') return true;
    return false;
}
bool isC(char c) {
    return !isV(c);
}

void solve() {
    cin >> n >> s;
    vector<string> ans;
    // cout << s << el;
    bool hasLast = true;
    For(i, 0, n - 1) {
        if(isV(s[i])) {
            // check_here(i);
            string temp = "";
            temp = temp + s[i - 1] + s[i];
            if((i <= n - 3) and isC(s[i + 2])) {
                // debug(s[i+2]);
                // cout << isC(s[i + 2]) << el;
                temp = temp + s[i + 1];
            }
            
            if(i <= n - 3) cout << temp << ".";
            else cout << temp;
            if(i == n - 1) hasLast = false;
        }
    }
    if(hasLast) cout << s.back();
    cout << el;

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