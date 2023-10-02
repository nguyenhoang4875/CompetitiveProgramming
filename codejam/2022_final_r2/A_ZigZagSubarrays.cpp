#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;

//*** debug(x) ***//
#define debug(x)             \
    cout << "[" << #x << "]" \
         << " : " << (x) << endl

#if 1
template <class Ch, class Tr, class Container>
basic_ostream<Ch, Tr>& operator<<(basic_ostream<Ch, Tr>& os,
                                  Container const& x) {
    os << "{ ";
    for (auto& y : x) os << y << ", ";
    return os << "}";
}

template <class X, class Y>
ostream& operator<<(ostream& os, pair<X, Y> const& p) {
    return os << "(" << p.first << ", " << p.second << ")";
}
#endif

template <typename T>
void check_here(T x) {
    cout << "------------- " << x << " -------------" << endl;
}

//*** define ***//
#define FOR(_i, _a, _b) for (int _i = (_a); _i < (_b); _i++)
#define FORI(_i, _a, _b) for (int _i = (_a); _i <= (_b); _i++)
#define FORE(it, x) for (auto it = x.begin(); it != x.end(); ++it)

//*** custom using ***//
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;
using pii = pair<int, int>;

//*** START CODING ***//

const int oo = 1e18, mod = 1e9 + 7;
const int ms = 1e5 + 5;
int n;
int a[ms];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int sum = 0;
    bool reset = true;
    bool preIcr = false;
    int len = 0;
    for(int i = 1; i <= n - 1; i++) {
        if(a[i] == a[i + 1]) {
            len = 0;
            reset = true;
            continue;
        } 
        if((reset || preIcr) && a[i] > a[i + 1]) {
            reset = false;
            preIcr = false;
            len++;
            sum += len;
            continue;
        }
        if((reset || !preIcr) && a[i]  < a[i + 1]) {
            reset = false;
            preIcr = true;
            len++;
            sum += len;
            continue;
        }
        sum += 1;
        len = 1;
    }
   
    cout << sum << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tcs;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}