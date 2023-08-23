#include<bits/stdc++.h>

using namespace std;
/**
 * https://codejam.lge.com/problem/21981
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
const int SOD = 86400; // seconds of a day
int tcs, n;
int t[70005];
int d[70005];

int getMod(int val) {
    int num = abs(val) / SOD;
    num += 2;
    return (val + num * SOD) % SOD;
}
void solve() {
    cin >> n;
    //            01234567
    string str;// hh:mm:ss
    int h, m, s;
    for(int i = 1; i <= n; i++) {
        cin >> str;
        // cout << str << "\n";
        h = stoi(str.substr(0, 2));
        m = stoi(str.substr(3, 2));
        s = stoi(str.substr(6, 2));
        // debug(h);
        // debug(m);
        // debug(s);
        int tts = h * 3600 + m * 60 + s; // total seconds
        t[i] = tts;
        // debug(t[i]);
    }
    for(int i = 1; i <= n; i++) {
        cin >> d[i];
    }

    vi vt;
    int cnt = 0;
    // find first time meet
    for(int s = 0; s < SOD; s++) {
        int found = true;
        int tt = getMod(t[1] + s * d[1]);
        tt % SOD;
        for(int i = 2; i <= n; i++) {
            int temp = getMod(t[i] + s * d[i]);
            if(tt != temp) {
                found = false;
                break;
            }
        }
        if(found) {
            cnt++;
            vt.pb(s);
            // debug(tt);
        }
        if(cnt == 2) break;
    }
    // debug(vt);
    if(vt.size() == 2) {
        int dr = vt[1] - vt[0];
        int time = SOD - vt[1] - 1;
        cnt += time / dr;
    }
    cout << cnt << '\n';

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