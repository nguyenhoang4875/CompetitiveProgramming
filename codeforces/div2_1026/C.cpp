#include<bits/stdc++.h>
#define int long long

using namespace std;

//*** debug(x) ***//
#define DEBUG 1

#if DEBUG
#define del cout <<  '\n'
#define debug(...) _debug(#__VA_ARGS__, __VA_ARGS__)
template <class X, class Y>
ostream& operator<<(ostream& os, pair<X, Y> const& p) {
    return os << "(" << p.first << ", " << p.second << ")";
}
template <class Ch, class Tr, class Container>
basic_ostream<Ch, Tr>& operator<<(basic_ostream<Ch, Tr>& os, Container const& x) {
    int i = 0, n = distance(x.begin(), x.end());
    os << "{ ";
    for (const auto& y : x) os << y << (++i < n ? ", " : "");
    return os << " }";
}
template <typename... Args>
void _debug(const char* names, Args&&... args) {
    string_view s(names);
    cout << "{ ";
    size_t i = 0, cnt = 0, n = sizeof...(args);
    auto next = [&]() {
        while (i < s.size() && (s[i] == ' ' || s[i] == ',')) ++i;
        size_t st = i;
        while (i < s.size() && s[i] != ',') ++i;
        return s.substr(st, i - st);
    };
    ((cout << next() << ": " << args << (++cnt < n ? ", " : "")), ...);
    cout << " }" << '\n';
}
#else
#define del
#define debug(...)
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
    int n; cin >> n;
    vi d(n + 1);
    For(i, 1, n) cin >> d[i];
    vii a(n + 1);
    For(i, 1, n) {
        cin >> a[i].F >> a[i].S;
    }
    int cur = 0, dx = 0;
    vi dd(n + 1);
    vi pos; pos.reserve(n + 1);
    For(i, 1, n) {
        if (d[i] == -1) {
            pos.push_back(i);
        } else {
            cur += d[i];
        }
        while(cur < a[i].F) {
            if (pos.empty()) {
                cout << -1 << el;
                return;
            }
            cur += 1;
            d[pos.back()] = 1;
            pos.pop_back();
        }
        while (cur + pos.size() > a[i].S) {
            if(pos.empty()) {
                cout << -1 << el;
                return;
            }
            d[pos.back()] = 0;
            pos.pop_back();
        }
    }
    For(i, 1, n) {
        cout << max(0LL, d[i]) << " ";
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