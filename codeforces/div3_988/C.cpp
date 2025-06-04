#include<bits/stdc++.h>
#define int long long

using namespace std;

//*** debug(x) ***//
#define DEBUG 1

#if DEBUG
#define del cout <<  '\n'
#define debug(x) cout <<  "[" << #x << "]" << " : " << (x) << endl
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
#define For(i, a, b) for (int i = (a); i <= (int) (b); i++)
#define Rof(i, a, b) for (int i = (a); i >= (int) (b); i--)
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
    if(n < 5) {
        cout << -1 << el;
        return;
    }
    if(n == 5) {
        cout << "1 3 5 4 2" << el;
        return;
    }
    if(n == 6) {
        cout << "1 3 5 4 6 2" << el;
        return;
    }
    if(n == 7) {
        cout << "1 3 5 7 2 4 6" << el;
        return;
    }

    int t = (n & 1) ? n : n - 1;
    int no = (n + 1) / 2;
    for(int i = 1; i <= t; i += 2)  {
        cout << i << " ";
    }
    if(t % 3 == 0) {
        cout << 6 << " " << 2 << " " << 4 << " ";
    }
    if(t % 3 == 1) {
        cout << 2 << " " << 4 << " " << 6 << " ";
    }
    if(t % 3 == 2) {
        cout << 4 << " " << 2 << " " << 6 << " ";
    }
    if(n >= 8) {
        for(int i = 8; i <= n; i += 2) {
            cout << i << " ";
        }
    }
    cout << el;

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