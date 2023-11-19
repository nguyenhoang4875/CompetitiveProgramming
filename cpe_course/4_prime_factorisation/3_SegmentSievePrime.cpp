#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Prime: https://www.spoj.com/problems/PRIME1/
 * Solution: Using sieve prime number and segment
 * - make range [m, n] map to [0, n - m]
 * - then remap to take the actual value
 *
 * TC: O(sqrt(n) * log log sqrt(n))
 * MC: O(sqrt n) => max = 10^5
 */

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
const int ms = 1e5 + 5;
int n, m;

vb prime(ms + 1, 1);
vi primeNumber;
void sieve() {
    For(i, 2, ms) {
        if (prime[i]) {
            primeNumber.pb(i);
            for (int j = i * i; j <= ms; j += i) prime[j] = false;
        }
    }
}

void solve() {
    cin >> m >> n;
    vi segment(n - m + 1, 1);
    // cout << "abc" << el;

    for (auto p : primeNumber) {
        if (p * p > n) break;

        // start is first value is non prime in [m, n]
        int start = (m / p) * p;
        if (start < m) start += p;

        // p is prime number so start at: 2*p
        if (p >= m and p <= n) start = 2 * p;

        for (int i = start; i <= n; i += p) {
            segment[i - m] = 0;
        }
    }
    for (int i = m; i <= n; i++) {
        if (segment[i - m] && i > 1) {
            cout << i << el;
        }
    }
    cout << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve();
    int tcs;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}