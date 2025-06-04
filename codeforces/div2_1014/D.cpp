#include <bits/stdc++.h>
#define int long long

using namespace std;

//*** debug(x) ***//
#define DEBUG 0

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

const string a = "ILT";

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    set<char> se;
    for (auto u : s) se.insert(u);
    if (se.size() == 1) {
        cout << -1 << endl;
        return;
    }
    vector<int> ans;
    map<char, int> cnt;
    for (auto u : s) { cnt[u]++; }
    auto func = [&](int i) {
        for (auto u : a) {
            if (s[i] != u && s[i + 1] != u) return u;
        }
        return '$';
    };
    while (max({cnt['L'], cnt['I'], cnt['T']}) != min({cnt['L'], cnt['I'], cnt['T']})) {
        int mn = min({cnt['L'], cnt['I'], cnt['T']});
        int mx = max({cnt['L'], cnt['I'], cnt['T']});
        int ok = 0;
        for (int i = 0; i < s.size() - 1; i++) {
            char x = func(i);
            if (s[i] != s[i + 1] && cnt[x] == mn) {
                cnt[x]++;
                ok = 1;
                s.insert(s.begin() + i + 1, x);
                ans.push_back(i);
                break;
            }
        }
        if (!ok) {
            for (int i = 0; i < s.size() - 1; i++) {
                char x = func(i);
                if (s[i] != s[i + 1] && cnt[x] == mx) {
                    cnt[x]++;
                    ok = 1;
                    s.insert(s.begin() + i + 1, x);
                    ans.push_back(i);
                    break;
                }
            }
        }
    }
    cout << ans.size() << endl;
    for (auto u : ans) { cout << u + 1 << endl; }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs = 1;
    cin >> tcs;
    while (tcs--) { solve(); }
    return 0;
}