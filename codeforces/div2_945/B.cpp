#include<bits/stdc++.h>
#define int long long

using namespace std;

//*** debug(x) ***//
#define DEBUG 0

#if DEBUG
#define del cout <<  '\n'
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
#else
#define del
#define debug(x)
#endif

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
int setBit(int n, int pos) { return n |= (1 << pos); }
int clearBit(int n, int pos) { return n &= ~(1 << pos); }
int getBit(int n, int pos) { return (n >> pos) & 1; }
int toggleBit(int n, int pos) { return n ^= (1 << pos); }

const int oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;
int n;
int a[ms];
vvi cnt;

void solve() {
    cin >> n;
    For(i, 1, n) cin >> a[i];

    auto check = [&](int k) {
        debug(1);
        debug(k);
        vi ct(21, 0);
        For(i, 1, k) {
            for(int j = 0; j <= 20; j++) {
                ct[j] += getBit(a[i], j);
            }
            
        }
        // vi cur = ct;
        debug(ct);
        For(i, k + 1, n) {
            debug(i);
            debug(i - k);
            for(int j = 0; j <= 20; j++) {
                int tmp = ct[j];
                ct[j] += getBit(a[i], j);
                ct[j] -= getBit(a[i - k], j);
                debug("inside");
                debug(ct);
                if(tmp == ct[j]) continue;
                if(tmp > 0 and ct[j] == 0) return false;
                if(tmp == 0 and ct[j] > 0) return false;
            }
        }
        return true;
    };

    int ans = n;
    int l = 1, r = n;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(check(mid)) {
            ans = mid;
            debug(ans);
            r = mid - 1;
        } else l = mid + 1;
    }
    cout << ans << el;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs = 1;
    cin >> tcs;
    while(tcs--) {
        solve();
    }
    return 0;
}