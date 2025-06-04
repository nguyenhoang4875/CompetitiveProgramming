#include<bits/stdc++.h>
#define int long long

using namespace std;

//*** debug(x) ***//
#define DEBUG 1

#if DEBUG
#define del cout <<  '\n'
#define debug(x) cout <<  "[" << #x << "]" << " : " << (x) << endl
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
#define all1(x) (x).begin() + 1, (x).end()
#define el '\n'
#define F first
#define S second
#define Rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
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

void solve() {
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();
    vi pre(m + 1, oo);
    int pos = 0;
    pre[0] = -1;
    for(int i = 1; i <= m; i++) {
        while(pos < n and a[pos] != b[i - 1]) {
            pos++;
        }
        if(pos >= n) pre[i] = oo;
        else pre[i] = pos;
        pos++;
    }

    vi suf(m + 1, -oo);
    pos = n - 1;
    suf[m] = n;
    for(int i = m - 1; i >= 0; i--) {
        while(pos >= 0 and a[pos] != b[i]) {
            pos--;
        }
        if(pos < 0) suf[i] = -oo;
        else suf[i] = pos;
        pos--;
    }

    int minLen = m + 1;
    int start = -1, end = -1;
    int j = 0;
    for(int i = 0; i <= m; i++) {
        j = max(j, i);
        while(j <= m and !(suf[j] > pre[i])) {
            j++;
        }
        if(j > m) break;
        if(j - i < minLen) {
            minLen = j - i;
            start = i;
        }
    }
    if(minLen >= m) {
        cout << "-" << el;
        return;
    }
    string ans = b.substr(0, start) + b.substr(start + minLen);
    cout << ans << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}