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
const int ms = 1e7 + 5;
int n;

vector<int> sieve(ms + 1, 0);  // ms: max size
void primeSieve(int n) {
    for (int i = 1; i <= n; i++) {
        sieve[i] = i;
    }

    for (int i = 2; i <= n; i++) {
        if (sieve[i] == i) {
            for (int j = i * i; j <= n; j += i) {
                if (sieve[j] == j) {
                    sieve[j] = i;
                }
            }
        }
    }
}

vector<int> getFactor(int number) {
    vector<int> factors;
    while (number != 1) {
        factors.push_back(sieve[number]);
        number /= sieve[number];
    }
    return factors;
}

void solve() {
    cin >> n;
    vi factors = getFactor(n);
    for (auto e : factors) cout << e << " ";
    cout << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    primeSieve(ms);
    int tcs;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}