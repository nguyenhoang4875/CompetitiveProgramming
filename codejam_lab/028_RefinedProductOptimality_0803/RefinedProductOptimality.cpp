#include <bits/stdc++.h>
#define int long long

using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define all1(x) (x).begin() + 1, (x).end()
#define sz(x) static_cast<int>((x).size())
#define el '\n'
#define F first
#define S second
#define Rep(i, n) for (int i = 0; i < (int)n; ++i)
#define For(i, a, b) for (int i = (a); i <= (int)b; ++i)
#define Rof(i, b, a) for (int i = (b); i >= (int)a; --i)
#define Fore(i, v) for (auto i = (v).begin(); i != (v).end(); ++i)

using vb = vector<bool>;
using vvb = vector<vb>;
using vc = vector<char>;
using vvc = vector<vc>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;

//*** START CODING ***//

const long long oo = 2e18, mod = 998244353;
const int ms = 2e5 + 5;

long long power(long long a, long long b) {
    long long ans = 1;
    while (b > 0) {
        if (b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b /= 2;
    }
    return ans;
}

int modInverse(int n) { return power(n, mod - 2); }

void solve() {
    int n, q;
    cin >> n >> q;
    vi a(n);
    Rep(i, n) cin >> a[i];
    vi b(n);
    Rep(i, n) cin >> b[i];

    vi sa = a;
    sort(all(sa));
    vi sb = b;
    sort(all(sb));

    int p = 1;
    Rep(i, n) p = p * min(sa[i], sb[i]) % mod;

    cout << p << " ";

    while (q--) {
        int o, x;
        cin >> o >> x;
        --x;
        if (o == 1) {
            auto pos = upper_bound(all(sa), a[x]) - sa.begin() - 1;
            ++a[x];
            p = p * modInverse(min(sa[pos], sb[pos])) % mod;
            ++sa[pos];
            p = p * min(sa[pos], sb[pos]) % mod;
        } else {
            auto pos = upper_bound(all(sb), b[x]) - sb.begin() - 1;
            ++b[x];
            p = p * modInverse(min(sa[pos], sb[pos])) % mod;
            ++sb[pos];
            p = p * min(sa[pos], sb[pos]) % mod;
        }
        cout << p << " ";
    }
    cout << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tcs = 1;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}