#include <bits/stdc++.h>
#define int long long

using namespace std;

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


//*** START CODING ***//

const long long oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;
int n;
int a[ms];

void solve() {
    cin >> n;
    For(i, 1, n) cin >> a[i];
    int l = 1, r = n;
    int ans = 0;
    while (a[l] > 0) {
        ans += a[l];
        l++;
    }
    while (a[r] < 0) {
        ans += abs(a[r]);
        r--;
    }
    int curSum = ans;

    int neg = 0, pos = 0;
    For(i, l, r) {
        if (a[i] > 0)
            pos += a[i];
        else
            neg += abs(a[i]);
    }
    ans = max(ans + pos, ans + neg);

    vi prePos(n + 2, 0), sufNeg(n + 2, false);
    For(i, l, r) {
        prePos[i] = prePos[i - 1];
        if (a[i] > 0) prePos[i] += a[i];
    }

    Rof(i, r, l) {
        sufNeg[i] = sufNeg[i + 1];
        if (a[i] < 0) sufNeg[i] += a[i];
    }
    debug(l);
    debug(r);

    debug(prePos);
    debug(sufNeg);
    

    int tSum = curSum;
    For(i, l, r) {
        if (a[i] > 0)
            tSum += a[i];
        else {
            ans = max(ans, tSum + abs(sufNeg[i]));
        }
    }
    
    ans = max(ans, tSum);
    tSum = curSum;
    Rof(i, r, l) {
        if (a[i] < 0)
            tSum += abs(a[i]);
        else {
            ans = max(ans, tSum + abs(prePos[i]));
        }
    }
    ans = max(ans, tSum);
    cout << ans << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs = 1;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}