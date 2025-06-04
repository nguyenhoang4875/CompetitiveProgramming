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

void solve() {
    cin >> n;
    vi a(n);
    for (auto& x : a) cin >> x;
    if (n == 1) {
        cout << 0 << el;
        return;
    }
    int minVal = oo, maxVal = 0;
    int sum = 0;
    for (auto x : a) {
        minVal = min(minVal, x);
        maxVal = max(maxVal, x);
        sum += x;
    }
    int avg = sum / n;
    if (a[0] >= avg) {
        if (a[n - 1] <= avg) {
            if (sum % n == 0) {
                cout << 0 << el;
            } else {
                cout << 1 << el;
            }
        } else {
            // a[n - 1] > avg
            int sum2 = sum - a[n - 1];
            int avg2 = sum2 / (n - 1);
            cout << a[n - 1] - avg2 << el;
        }
        return;
    }
    // a[0] < avg
    int avg2 = (sum - a[0]) / (n - 1);
    if (a[n - 1] > avg2) {
        cout << a[n - 1] - a[0] << el;
    } else {
        // a[n - 1] <= avg
        if ((sum - a[n - 1]) % (n - 1) == 0) {
            cout << avg2 - a[0] << el;
        } else {
            cout << avg2 - a[0] + 1 << el;
        }
    }
}

// auto check = [&avg](int k, vector<int> v) {
//     bool ret = true;
//     if()

// };

// int l = 0, r = maxVal - minVal;
// int ans = r;

// while(l <= r) {
//     int mid = (l + r) / 2;

//     if(check(mid)) {
//         ans = mid;
//         r = mid - 1;
//     } else {
//         l = mid + 1;
//     }
// }
// cout << ans << el;

// }

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs = 1;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}