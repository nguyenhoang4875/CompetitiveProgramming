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

//*** START CODING ***//

const long long oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;

void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    vi a(n + 2);
    For(i, 1, n) cin >> a[i];

    vi preXor(n + 2);
    For(i, 1, n) { preXor[i] = preXor[i - 1] ^ a[i]; }

    if (n % 2 == 0) {
        n++;
        a[n] = preXor[n / 2];
        preXor[n] = preXor[n - 1] ^ a[n];
    }

    function<int(int)> f = [&](int x) {
        if (x <= n) return a[x];
        x /= 2;
        if (x <= n) return preXor[x];
        int ans = preXor[n];
        if (x % 2 == 0) ans ^= f(x);
        return ans;
    };

    cout << f(l) << el;
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