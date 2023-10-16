#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define F first
#define S second

using namespace std;

//*** debug(x) ***//
#if 1
#define debug(x)             \
    cout << "[" << #x << "]" \
         << " : " << (x) << endl
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

//*** define ***//
#define For(_i, _a, _b) for (int _i = (_a); _i < (_b); _i++)
#define Fori(_i, _a, _b) for (int _i = (_a); _i <= (_b); _i++)
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
int b[ms];
int d[ms];
bool found;

int i_pre, j_pre;

int nC2(int n) {
    return n * (n - 1) / 2;
}

int binarySearch(int idx, int val) {
    int pos = -1;
    int l = idx + 1, r = n;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(d[mid] - d[idx] <= val) {
            pos = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return pos;
}

bool check(int val) {
    // check val is answers
    int cnt = 0;
    for(int i = 1; i <= n - 1; i++) {
        int t = binarySearch(i, val);
        if(t == -1) continue;
        int len = t - i + 1;
        cnt += nC2(len);
    }
    debug(val);
    debug(cnt);
    debug(k);
    if(cnt == k) found = true;
    return cnt >= k;
}

void solve() {
    cin >> n >> k;
    Fori(i, 1, n) cin >> a[i];
    Fori(i, 1, n) cin >> b[i];

    Fori(i, 1, n) { d[i] = a[i] - b[i]; }

    sort(d + 1, d + n + 1);
    Fori(i, 1, n) cout << d[i] << ' ';
    cout << '\n';

    found = false;

    int l = 0, r = 2e5;
    int ans = -1;
    while(l <= r)  {
        int mid = (l + r) / 2;
        if(check(mid)) {
            // debug(mid);
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    debug(ans);
    if(!found) ans = -1;
    cout << ans << '\n';

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