#include <bits/stdc++.h>
#define int long long

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define F first
#define S second
#define For(i, a, b) for (int i = (int)a; i <= (int)b; i++)
#define Ford(i, a, b) for (int i = (int)a; i >= (int)b; i--)
#define Fore(it, x) for (auto it = x.begin(); it != x.end(); ++it)




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
const int ms = 50 + 5;
int n, m;
int a[ms][ms];

pii congPs(pii p1,pii p2) {
    int tu = p1.F * p2.S+ p1.S*p2.F;
    int mau = p1.S * p2.S;
    int tmp = __gcd(tu, mau);
    tu /= tmp;
    mau /= tmp;
    return {tu, mau};
}

pii truPs(pii p1,pii p2) {
    int tu = abs(p1.F * p2.S - p1.S*p2.F);
    int mau = p1.S * p2.S;
    int tmp = __gcd(tu, mau);
    tu /= tmp;
    mau /= tmp;
    return {tu, mau};
}

bool cmpPs(pii a, pii b) {
    return a.F * b.S > b.F * a.S;
}

void solve() {
    cin >> n >> m;
    For(i, 1, m) {
        For(j, 0, n) {
            cin >> a[i][j];
        }
    }

    // For(i, 1, m) {
    //     For(j, 0, n) {
    //         cout << a[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    vii ans;
    For(i, 1, n) {
        pii p = {0, 1};
        For(j, 1, m) {
             p = congPs(p, {a[j][i] ,a[j][0]});
            // cout << a[j][i] << " " << a[j][0] << '\n';
            // cout << a[i][0] << " \n";
            // break;
        }
        // cout << '\n';
        
        // cout << p.F << " ans " << p.S << endl;
        ans.pb(p);
    }

    int sz = ans.size();
    int mMax = 0;
    int aTu = 0, aMau = 1;
    for(int i = 0; i < sz - 1; i++) {
        for(int j = i + 1; j < sz; j++) {
            // debug(ans[i]); 
            // debug(ans[j]); 
            pii tmp = truPs(ans[i], ans[j]);
            // debug(tmp);
            if(cmpPs(tmp, {aTu, aMau})) {
                aTu = tmp.F;
                aMau = tmp.S;
            }
        }
    }
    if(aTu == 0) {
        cout << "0\n";
        return;
    } 
    if(aMau == 1) {
        cout << aTu << "\n";
        return;
    }
    cout << aTu << "/" << aMau << "\n";


}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tcs;
    cin >> tcs;
    while(tcs--) solve();

    return 0;
}