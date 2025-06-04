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

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(i, a, b) for (int i = (a); i <= (int)(b); i++)
#define Rof(i, a, b) for (int i = (a); i >= (int)(b); i--)
#define Fore(it, x) for (auto it = (x).begin(); it != (x).end(); ++it)

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

bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    for (int i = 2; i <= sqrtl(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void solve() {
    int n, k;
    cin >> n >> k;
    if(n == 1 and k == 2) {
        cout << "YES" << el;
        return;
    } 
    if (k == 1 and isPrime(n)) {
        cout << "YES" << el;
    } else cout << "NO" << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // cout << isPrime(12)  << el;

    int tcs = 1;
    cin >> tcs;
    while (tcs--) { solve(); }
    return 0;
}