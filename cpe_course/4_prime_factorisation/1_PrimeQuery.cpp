#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: Give Q queries. In each query, you are given two integers A and B
 * Find the number of primes in the range [a, b]
 * Constraints
 * A, B, Q <= 10^6
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
const int ms = 1e6 + 5;
int a, b;

vector<int> primeNumber;
void preCal(int n) {
    vector<bool> prime(n + 1, true);
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p) prime[i] = false;
        }
    }
    for (int p = 2; p <= n; p++)
        if (prime[p]) primeNumber.push_back(p);
}

void solve() {
    cin >> a >> b;
    int n1 = lower_bound(all(primeNumber), a - 1) - primeNumber.begin();
    int n2 = lower_bound(all(primeNumber), b) - primeNumber.begin();
    cout << (n2 - n1) << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    preCal(ms);

    int tcs;
    cin >> tcs;
    while (tcs--) solve();
    return 0;
}