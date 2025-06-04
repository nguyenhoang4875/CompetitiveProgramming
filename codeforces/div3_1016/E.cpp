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

const long long oo = 2e5 + 1, mod = 1e9 + 7;
const int ms = 2e5 + 5;

void solve() {
    int n, k;
    cin >> n >> k;
    vi a(n);
    for (auto& x : a) cin >> x;
    vi b(n + 5, 0);
    for(auto &x: a) if(x <= n) b[x] = 1;
    int maxMex = 0;
    for(int i = 0; i <= n + 1; i++) {
        if(b[i] == 0) {
            maxMex = i;
            break;
        }
    }


    auto check = [&](int t) {
        int mex = 0;
        int cnt = 0;
        set<int> st;
        for (int i  = 0; i < n; i++) {

            while(i < n and mex < t) {
                st.insert(a[i]);
                while(st.count(mex)) mex++;
                if(mex >= t) break;
                i++;
            }
            if(mex < t) return false;
            mex = 0;
            st.clear();
            cnt++;
            if(cnt >= k) return true;
        }
        return false;
    };

    int l = 0, r = oo;
    int ans = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        debug(mid);
        debug(check(mid));
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    cout << ans << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs = 1;
    cin >> tcs;
    while (tcs--) { solve(); }
    return 0;
}