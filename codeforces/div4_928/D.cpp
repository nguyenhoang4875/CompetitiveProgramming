#include <bits/stdc++.h>
#define int long long

using namespace std;

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


const int oo = 1e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;
int n;
int a[ms];

bool getBit(int n, int pos) {
    return (n >> pos) & 1;
}

bool canGroup(int a, int b) {
    Ford(pos, 30, 0) {
        if(getBit(a, pos) == getBit(b, pos)) return false;
    }
    return true;
}


void solve() {
    cin >> n;
    map<int, int> mii;
    int mask = 2147483647;
    For(i, 1, n) {
        int x;
        cin >> x;
        mii[x]++;
    }
    int cnt = 0;
    for(auto [f, s]: mii) {
        int val = mask - f;
        // debug(val);
        if(mii.count(val)) {
            int t = min(s, mii[val]);
            cnt += t;
            cnt += (max(s, mii[val]) - t);

            mii[f] = 0;
            mii[val] = 0;
        } else {
            cnt += s;
        }
    }
    cout << cnt << el;



}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // cout << canGroup(1, 2) << el;

    int tcs;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}