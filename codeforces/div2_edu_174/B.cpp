#include<bits/stdc++.h>
#define int long long

using namespace std;

//*** debug(x) ***//
#define DEBUG 0

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
const int ms = 700 + 5;
int n, m;
int a[ms][ms];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};


void solve() {
    cin >> n >> m;
    map<int, set<pii>> cnt;
    map<int, int> com;

    auto inBound = [&](int x, int y) {
        if(x < 1 or x > n or y < 1 or y > m) return false;
        return true;
    };
    For(i, 1, n) {
        For(j, 1 , m) {
            int x;
            cin >> x;
            if(com.count(x) and com[x] == 2) continue;
            if(!cnt.count(x)) {
                cnt[x].insert({i, j});
                com[x] = 1;
            } else { 
                cnt[x].insert({i, j});
                int nx = i, ny = j;
                for(int d = 0; d < 4; d++) {
                    nx = i + dx[d];
                    ny = j + dy[d];
                    if(!inBound(nx, ny)) continue;
                    if(cnt[x].count({nx, ny})) {
                        com[x] = 2;
                        continue;
                    }
                }
            }
        }
    }
    debug(com);
    bool f2 = false;
    int ans = 0;
    for(auto [f, s]: com) {
        if(!f2 and s == 2) {
            ans += 1;
            f2 = true;
            continue;
        }
        ans += s;
    }
    cout << ans - 1 << el;

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