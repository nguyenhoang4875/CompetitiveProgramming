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
int a, b;

int powerMod(int a, int n) {
    int ans = 1;
    a = a % mod;
    while (n > 0) {
        if (n & 1) ans = (ans * a) % mod;
        n /= 2;
        a = (a * a) % mod;
    }
    return ans;
}

map<int, int> primeFactors(int n) {
    map<int, int> factors;
    for (int i = 2; i * i < n; i++) {
        while (n % i == 0) {
            factors[i]++;
            n /= i;
        }
    }
    if (n > 1) factors[n]++;
    return factors;
}

int sumPrimePower(int p, int exp) {
    if (p % mod == 0) return 1;
    if (p % mod == 1) return (exp * (b % mod) + 1) % mod;
    return (powerMod(p, (b % (mod - 1) * exp + 1) % (mod - 1)) - 1 + mod) *
           powerMod(p - 1, mod - 2) % mod;
}

void solve() {
    cin >> a >> b;

    int ans = 1;
    map<int, int> factors = primeFactors(a);
    for (auto [p, e] : factors) {
        ans *= sumPrimePower(p, e);
        ans %= mod;
    }
    cout << ans << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("sumdiv.in", "r", stdin);
    freopen("sumdiv.out", "w", stdout);

    solve();
    return 0;
}