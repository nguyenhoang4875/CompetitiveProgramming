#include <bits/stdc++.h>
#define int long long

using namespace std;

//*** debug(x) ***//
#define DEBUG 1

#if DEBUG
#define del cout << '\n'
#define debug(x) cout << "[" << #x << "]" << " : " << (x) << endl
template <class X, class Y>
ostream& operator<<(ostream& os, pair<X, Y> const& p) {
    return os << "(" << p.first << ", " << p.second << ")";
}
template <class Ch, class Tr, class Container>
basic_ostream<Ch, Tr>& operator<<(basic_ostream<Ch, Tr>& os, Container const& x) {
    os << "{ ";
    for (const auto& y : x) os << y << ", ";
    return os << "}";
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
int n, d;

void solve() {
    cin >> n >> d;
    if (n ==  2) {
        int a = d * 10 + d;
        for (int i = 1; i <= 9; i += 2) {
            if (a % i == 0) {
                cout << i << " ";
            }
        }
        cout << el;
        return;
    }
    cout << 1 << " " << 3 << " ";
    if (d == 5) {
        cout << 5 << " ";
    }

    cout << 7 << " ";
    int val = d;
    if(n <= 5) {
        For(i, 1, n) val *= i;
    }
    // debug(val);
    if (n >= 6 or val % 9 == 0) {
        cout << 9 << " ";
    }
    cout << el;
}

int power(int a, int n) {
    int ans = 1;
    while (n > 0) {
        if (n & 1) ans *= a;
        n /= 2;
        a *= a;
    }
    return ans;
}

void test() {
    For(d, 1, 9) {
        For(i, 1, 12) {
            int val = d * (power(10, i) - 1) / 9;
            if(val % 7 == 0) {
                cout << val << " ";
            }
        }
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    test();

    // int tcs = 1;
    // cin >> tcs;
    // while (tcs--) {
    //     solve();
    // }
    return 0;
}