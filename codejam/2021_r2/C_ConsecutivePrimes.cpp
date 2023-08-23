#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;
/**
 * Problem: https://codejam.lge.com/problem/21395
 * Solution: 
 *  - Using Sieve of Eratosthenes to find primes number <= n; TC: O(n*log(log(n))) (one time)
 *  - Sort input
 *  - Brute force for all case 
*/

using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;
using pii = pair<int, int>;

//*** START CODING ***//

int tcs, n;
int a[205];

vi primeNumber;
// O(n*log(log(n)))
void sieve(int n){
    vb prime(n + 1, true);
    primeNumber.clear();
    for(int p = 2; p * p <= n; p++) {
        if(prime[p]) {
            for(int i = p * p ; i <= n; i += p) prime[i] = false;
        }
    }
    for(int i = 2; i <= n ;i++) {
        if(prime[i]) primeNumber.pb(i);
    }
}

void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);

    int ans = 1e9;
    // n <= 200
    // primeNumber size = 10^4 (m)
    // 200 * 10^4 = 2 * 10 ^ 6 
    for(int i = 0; i < primeNumber.size() - n; i++) {
        int diffSum = 0;
        for(int p = 0; p < n; p++) {
            diffSum += abs(a[p] - primeNumber[i + p]);
        }
        ans = min(ans, diffSum);
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    const int MAX_PRIME = 110000;
    sieve(MAX_PRIME); // 10453 prime number
    cin >> tcs;
    while(tcs--) solve();
    return 0;
}