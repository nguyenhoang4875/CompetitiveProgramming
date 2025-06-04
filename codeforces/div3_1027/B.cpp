#include<bits/stdc++.h>
#define int long long

using namespace std;

//*** debug(x) ***//
#define DEBUG 0

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
    int n, k;
    cin >> n >> k;
    string s; 
    cin >> s;
    int c0 = 0, c1 = 0;
    for(auto &e: s) {
        if(e == '0') c0++;
        else c1++;
    }
    if(k == n / 2 and (c1 & 1)) {
        cout << "NO" << el;
        return;
    }
    if(k < n / 2 and (c0 == n or c1 == n) ) {
        cout << "NO" << el;
        return;
    }
    priority_queue<pii> q;
    q.push({c0, 0});
    q.push({c1, 1});
    debug(s);
    debug(c0, c1);
    while(k > 0 and !q.empty()) {
        auto [cnt, val] = q.top(); q.pop();
        if(cnt < 2) {
            debug(cnt, val);
            cout << "NO" << el;
            return;
        }
        k -= 1;
        q.push({cnt - 2, val});
    }
    if(q.empty()) {
        cout << "NO" << el;
        return;
    }
    if(q.size() == 1) {
        cout << "NO" << el;
        return;
    }
    if(q.top().S == 0) {
        c0 = q.top().F; q.pop();
        c1 = q.top().F; q.pop();

    } else {
        c1 = q.top().F; q.pop();
        c0 = q.top().F; q.pop();
    }
    debug(c0, c1);
    if(c0 == c1) {
        cout << "YES" << el;
    } else cout << "NO" << el;

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