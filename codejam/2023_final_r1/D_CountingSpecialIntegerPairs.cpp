#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define F first
#define S second

using namespace std;

//*** debug(x) ***//
#define debug(x)             \
    cout << "[" << #x << "]" \
         << " : " << (x) << endl

#if 1
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
#endif

template <typename T>
void check_here(T x) {
    cout << "------------- " << x << " -------------" << endl;
}

//*** define ***//
#define For(_i, _a, _b) for (int _i = (_a); _i <= (_b); _i++)
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
const int ms = 5e4 + 5;
int n, k;
int a[ms];

int count(int val) {
    int cnt = 0;
    For(i, 1, n) {
        int pos = upper_bound(a + i + 1, a + n + 1, a[i] - val, greater<int>()) - a;
        if(pos <= n + 1) {
         cnt += pos - 1 - i;
        }
    }
    return cnt;

}

void solve() {
    cin >> n >> k;
    For(i, 1, n) cin >> a[i];
    For(i, 1, n) {
        int tmp;
        cin >> tmp;
        a[i] -= tmp;
    } 
    sort(a + 1, a + n + 1, greater<int>());

    int l = 0, r = 1e6;
    int ans = -1;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(count(mid) >= k) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    if(count(ans) == k) cout << ans << '\n';
    else cout << "-1\n";

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