#include<bits/stdc++.h>

using namespace std;
/**
 * Problem: https://codejam.lge.com/problem/21979
 * Solution:
 *  - Using gen binary
 *  - Brute force to check each case
 *  - Sort and compare to check if valid or not
 * TC: O(2 ^ n) (n = 15 => AC)
 * MC: O(n)
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

int tcs, n, m;
string s;
int g[20];
int ans = 0;

string removeLeadingZero(string s) {
    while(s.size() > 1 && s[0] == '0') {
        s.erase(0, 1);
    }
    return s;
}

void cal() {
    vector<string> vs;
    vi vCut;
    for(int i = 1; i < n; i++) {
        if(g[i] == 1) {
            vCut.pb(i);
        }
    }
    if(vCut.empty()) {
        ans++;
        return;
    }
    int pre = 0;
    string temp = "";
    for(int idx: vCut) {
        temp = s.substr(pre, idx - pre);
        pre = idx;
        temp = removeLeadingZero(temp);
        vs.pb(temp);
    }
    temp = s.substr(pre, n - pre);
    temp = removeLeadingZero(temp);
    vs.pb(temp);
    // debug(vCut);
    // debug(vs);
    vector<string> vSort = vs;
    sort(vSort.begin(), vSort.end(),  [&](string &s1, string &s2) {
        if(s1.size() == s2.size()) return s1 < s2;
        return s1.size() < s2.size();
    });
    bool found = true;
    for(int i = 0; i < vs.size(); i++) {
        if(vs[i] != vSort[i]) {
            found = false;
            break;
        }
    }
    if(found) ans++;
}

void gen(int i) {
    if(i == n) {
        cal();
        return;
    }
    for(int val = 0; val <= 1; val++) {
        g[i] = val;
        gen(i + 1);
    }
}

void solve() {
    ans = 0;
    cin >> s;
    n = s.size();
    m = n - 1;
    gen(1);
    cout << ans << '\n';
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