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
const int ms = 2e5 + 5;
int n, x, y, z;
int a[ms];
int aa[ms];  // prefixSum a
// int bb[ms]; // prefixSum y

void solve() {
    cin >> n >> x >> y >> z;
    For(i, 1, n) {
        cin >> a[i];
        aa[i] = aa[i - 1] + a[i];
    }

    int maxIdx = -1, minLen = oo;
    bool found = false;

    for (int len = 1; len <= n; len++) {
        for (int i = 1; i  + len - 1 <= n; i++) {
            int temp = aa[i + len - 1] - aa[i - 1] - len * y - z;
            // debug(temp);
            if (temp >= 0 and x >= len * y) {
                if (minLen >= len) {
                    found = true;
                    if (minLen == len)
                        maxIdx = max(maxIdx, i);
                    else
                        maxIdx = i;
                    minLen = len;
                }
            }
        }
        if(found) {
            cout << maxIdx << " " << maxIdx + minLen - 1 << el;
            return;
        }
    }
    if (maxIdx == -1) {
        cout << -1 << el;
    } else {
        cout << maxIdx << " " << maxIdx + minLen - 1 << el;
    }
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