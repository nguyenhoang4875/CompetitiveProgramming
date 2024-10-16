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
int n, x;
string l, r;

/*
Find the count of numbers between L and R which have sum of digits = x

*/
int f(string& num, int idx, int x, int last) {
    if (x < 0) return 0;
    if (idx == 1) {
        if (x < 10) return 1;
        return 0;
    }

    int ans = 0;
    int till = last ? (num[num.size() - idx] - '0') : 9;
    // debug(till);
    for (int digit = 0; digit <= till; digit++) {
        ans += f(num, idx - 1, x - digit, last & (digit == till));
    }
    return ans;
}

int f1(string& num, int idx, int sum, int last) {
    debug(idx);
    debug(sum);
    if (sum > x) return 0;
    if (idx == num.size() - 1) {
        return sum == x;
    }

    int ans = 0;
    int till = last ? (num[idx] - '0') : 9;
    // debug(till);
    for (int digit = 0; digit <= till; digit++) {
        ans += f1(num, idx + 1, sum + digit, last & (digit == till));
    }
    return ans;
}

void solve() {
    cin >> l >> r;
    cin >> x;
    // cout << x << el;
    cout << f(r, r.size(), x, 1) << el;
    cout << f1(r, 0, 0, 1) << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}