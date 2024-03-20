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
const int ms = 3e5 + 5;
int n;

vector<int> sievePrime(int n) {
    vector<int> primeNumber;
    vector<bool> prime(n + 1, true);
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p) prime[i] = false;
        }
    }
    for (int p = 2; p <= n; p++)
        if (prime[p]) primeNumber.push_back(p);
    return primeNumber;
}

void solve() {
    cin >> n;
    vi p = sievePrime(min(n, ms));
    int psz = sz(p);
    int ans = 0;

    for (int i = 0; i < psz; i++) {
        int k = psz - 1;
        for (int j = i + 1; j < k and j < psz; j++) {
            while (j < k) {
                int v = p[i] * p[i] * p[j];
                if (v > n) {
                    k--;
                    continue;
                }
                v *= p[k];
                if (v > n) {
                    k--;
                    continue;
                }
                v *= p[k];
                if (v > n) {
                    k--;
                    continue;
                }
                break;
            }
            ans += (k - j);
        }
    }
    cout << ans << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}