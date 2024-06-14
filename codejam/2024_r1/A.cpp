#include <bits/stdc++.h>
#define int long long

using namespace std;

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

//*** START CODING ***//

const int oo = 1e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;
int n;
string s;

void solve() {
    cin >> n;
    vi a(n);
    vi b(n);
    vi sfSum(n + 1);
    int sum = 0;
    For(i, 0, n - 1) cin >> a[i];
    cin >> s;
    For(i, 0, n - 1) cin >> b[i];

    Ford(i, n - 1, 0) { sfSum[i] = sfSum[i + 1] + a[i]; }

    // debug(n);
    // debug(a);
    // debug(s);
    // debug(b);
    // debug(sfSum);

    auto check = [&](int val) {
        int t = val;
        For(i, 0, n - 1) {
            if (t > sfSum[i]) return true;
            if (t > a[i]) {
                t -= a[i];
                char op = s[i];
                if (op == '+')
                    t += b[i];
                else {
                    if (t > sfSum[i] / b[i]) {
                        return true;
                    }
                    t *= b[i];
                }
            } else {
                return false;
            }
        }

        return true;
    };

    int ans = 0LL;
    int l = 0, r = oo;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        } else
            l = mid + 1;
    }
    cout << ans << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}
