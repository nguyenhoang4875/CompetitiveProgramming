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
const int ms = 1e6 + 5;

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

int modInv(int a) { return powerMod(a, mod - 2); }

int sumTill(int n) { return n * (n + 1) / 2; }

void solve() {
    int n;
    cin >> n;
    vii v(n);
    for (auto& x : v) cin >> x.F >> x.S;
    int num = 1, sum = 1;
    int totP = 0;
    for (auto& [f, s] : v) {
        num *= (s + 1);
        if (num > mod) num %= mod;
        sum *= (powerMod(f, s + 1) - 1) * modInv(f - 1) % mod;
        if (sum > mod) sum %= mod;
        totP += sumTill(s);
    }
    int prod = 1, cnt = 1;
    for (auto& [f, s] : v) {
        prod = powerMod(prod, s + 1) * powerMod(powerMod(f, sumTill(s)), cnt) % mod;
        cnt = cnt * (s + 1) % (mod - 1);
    }

    cout << num << " " << sum << " " << prod << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}