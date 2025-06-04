#include <bits/stdc++.h>
#define int long long

using namespace std;

//*** debug(x) ***//
#define DEBUG 0

#if DEBUG
#define del cout << '\n'
#define debug(x) cout << "[" << #x << "]" << " : " << (x) << endl
template <class Ch, class Tr, class Container>
basic_ostream<Ch, Tr>& operator<<(basic_ostream<Ch, Tr>& os, Container const& x) {
    os << "{ ";
    for (const auto& y : x) os << y << ", ";
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
#define all(x) (x).begin(), (x).end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(i, a, b) for (int i = (a); i <= (int)(b); i++)
#define Rof(i, a, b) for (int i = (a); i >= (int)(b); i--)
#define Fore(it, x) for (auto it = (x).begin(); it != (x).end(); ++it)

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

const long long oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;
int n;
vector<int> vp2;
int init() {
    int p = 1;
    vp2.pb(p);
    for (int i = 1; i <= 60; i++) {
        p *= 2;
        vp2.pb(p);
    }
}

int min_operations(const string& n, const string& power_of_two) {
    int i = 0, j = 0;

    while (i < n.size() && j < power_of_two.size()) {
        if (n[i] == power_of_two[j]) {
            ++j;
        }
        ++i;
    }

    int deletions = n.size() - j;
    int additions = power_of_two.size() - j;

    return deletions + additions;
}

int getNumDigit(int val) {
    int ret = 0;
    while (val) {
        ret++;
        val /= 10;
    }
    return ret;
}

void solve() {
    cin >> n;
    int totDigit = getNumDigit(n);
    // debug(n);
    // debug(totDigit);
    int ans = 10;
    string sn = to_string(n);
    for (auto e : vp2) {
        string se = to_string(e);
        // int numSame = lcs(sn, se);
        // debug(numSame);
        // int val = (totDigit  - numSame) * 2+ getNumDigit(e) -  numSame;
        int val = min_operations(sn, se);
        if (val < ans) {
            // debug(numSame);
            // debug(e);
            // debug(val);
            ans = val;
        }
    }
    debug(ans);
    cout << ans << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init();

    int tcs = 1;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}