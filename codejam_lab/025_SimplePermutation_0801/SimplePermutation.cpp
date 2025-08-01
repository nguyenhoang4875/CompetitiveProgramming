#include <bits/stdc++.h>
#define int long long

using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define all1(x) (x).begin() + 1, (x).end()
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

const long long oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;

vector<int> prime;
void sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    for (int p = 2; p * p <= n; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i <= n; i += p) is_prime[i] = false;
        }
    }
    for (int p = 2; p <= n; p++)
        if (is_prime[p]) prime.push_back(p);
}

void solve() {
    int n;
    cin >> n;

    auto low = lower_bound(all(prime), n / 2);
    if(low != prime.begin()) low--;

    cout << *low << " ";
    int l = *low - 1, r = *low + 1;;

    while(l >= 1 or r <= n) {
        if(l >= 1) cout << l-- << " ";
        if(r <= n) cout << r++ << " ";
    }
    cout << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int mx = 1e5 + 5;
    sieve(mx);

    int tcs = 1;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}