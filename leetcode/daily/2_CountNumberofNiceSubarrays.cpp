#include <bits/stdc++.h>
#define int long long

using namespace std;
//*** debug(x) ***//
#define DEBUG 1

#if DEBUG
#define del cout << '\n'
#define debug(x) cout << "[" << #x << "]" << " : " << (x) << endl
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

#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(i, a, b) for (int i = a; i <= (int)b; i++)
#define Rof(i, a, b) for (int i = a; i >= (int)b; i--)
#define Fore(it, x) for (auto it = x.begin(); it != x.end(); ++it)

using vb = vector<bool>;
using vvb = vector<vb>;
using vc = vector<char>;
using vvc = vector<vc>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;

//*** START CODING ***//

const int oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;
int n;

int numberOfSubarrays(vector<int>& a, int k) {
    int n = a.size();
    int cnt = 0;
    int numOdd = 0;
    vector<int> odds;
    for (int i = 0; i < n; i++) {
        if (a[i] & 1) odds.push_back(i);
    }
    if (odds.size() < k) {
        return 0;
    }
    int no = odds.size();
    // debug(odds);
    int l = 0;
    for (int i = 0; i < no; i++) {
        if (i - l == k - 1) {
            // debug(l);
            // debug(i);
            int rv = 0, lv = 0;
            if (i < no - 1) {
                rv = odds[i + 1] - odds[i] - 1;
            } else {
                rv = n - 1 - odds[i];
            }
            // debug(rv);
            if (l == 0) {
                lv = odds[l];
            } else {
                lv = odds[l] - odds[l - 1] - 1;
            }
            // debug(lv);
            cnt += lv * rv;
            cnt += lv + 1;
            cnt += rv;
            // debug(cnt);

            l++;
            // del;
        }
    }
    return cnt;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vi a(n);
    for (auto& x : a) cin >> x;
    cout << numberOfSubarrays(a, k) << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}