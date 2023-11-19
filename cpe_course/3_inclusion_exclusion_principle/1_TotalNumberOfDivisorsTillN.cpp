#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: Given n, count total number that divisible for first 10 primes
 * Solution: Using Inclusion and Exclusion principle
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
int n;

int getBit(int mask, int pos) { return (mask >> pos) & 1; }

void solve() {
    cin >> n;
    vi primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 33};
    int m = sz(primes);

    int ans = 0;
    For(mask, 1, (1 << m) - 1) {
        int lcm = 1;
        For(j, 0, m - 1) {
            // get j-th bit that is set
            if (getBit(mask, j)) {
                lcm *= primes[j];
            }
        }
        if (__builtin_popcount(mask) & 1) {
            ans += n / lcm;
        } else
            ans -= n / lcm;
    }

    cout << ans << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}