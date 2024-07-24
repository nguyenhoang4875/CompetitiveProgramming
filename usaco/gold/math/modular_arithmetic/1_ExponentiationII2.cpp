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
int n;

int powerMod(int a, int n, int p) {
    int ans = 1;
    a = a % p;
    while (n > 0) {
        if (n & 1) ans = (ans * a) % p;
        n /= 2;
        a = (a * a) % p;
    }
    return ans;
}

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    // https://en.wikipedia.org/wiki/Euler's_totient_function
    // phi(primeNumber) = primeNumber - 1
    cout << powerMod(a, powerMod(b, c, mod - 1), mod) << el;
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