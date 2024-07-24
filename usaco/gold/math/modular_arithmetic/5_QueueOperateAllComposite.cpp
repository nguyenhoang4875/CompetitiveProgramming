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

const long long oo = 2e18, mod = 998244353;
const int ms = 2e5 + 5;
int n;

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

void solve() {
    cin >> n;
    int type;
    int mul = 1, con = 0;
    queue<pii> f;
    while (n--) {
        cin >> type;
        if (type == 0) {
            int a, b;
            cin >> a >> b;
            f.push({a, b});
            mul = mul * a % mod;
            con = ((con * a) % mod + b) % mod;
        } else if (type == 1) {
            pii p = f.front();
            f.pop();

            int inv = powerMod(p.F, mod - 2);  // a^(-1) modulo inversion
            mul = mul * inv % mod;
            con -= p.S * mul % mod;
            if (con < 0) con += mod;
        } else {
            int x;
            cin >> x;
            cout << (mul * x + con) % mod << el;
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}