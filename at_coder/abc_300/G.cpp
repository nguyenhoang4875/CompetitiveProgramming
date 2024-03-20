#include <bits/stdc++.h>
#define int long long

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(i, a, b) for (int i = a; i <= (int)b; i++)
#define Ford(i, a, b) for (int i = a; i >= (int)b; i--)
#define Fore(it, x) for (auto it = x.begin(); it != x.end(); ++it)

using vb = vector<bool>;
using vvb = vector<vb>;
using vc = vector<char>;
using vvc = vector<vc>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;

//*** START CODING ***//

const int oo = 1e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;
int n, p;

vector<int> primeNumber;
void sievePrime(int n) {
    vector<bool> prime(n + 1, true);
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p) prime[i] = false;
        }
    }
    for (int p = 2; p <= n; p++)
        if (prime[p]) primeNumber.push_back(p);
}

void step(vi& a, int p, int mx) {
    int asz = sz(a);
    for (int i = 0; i < asz; i++) {
        int ad = a[i];
        while (true) {
            ad *= p;
            if (ad > mx) break;
            a.push_back(ad);
        }
    }
}

void solve() {
    cin >> n >> p;
    sievePrime(p);

    vi u{1}, v{1};
    for (auto e : primeNumber) {
        if (u.size() < v.size()) {
            step(u, e, n);
        } else {
            step(v, e, n);
        }
    }

    sort(all(u));
    sort(all(v));

    int ans = 0;
    int l = 0, r = v.size() - 1;
    while (l < sz(u) and r >= 0) {
        int mv = n / u[l];
        while (r >= 0 and mv < v[r]) r--;
        if (r < 0) break;
        ans += r + 1;
        l++;
    }
    cout << ans << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}