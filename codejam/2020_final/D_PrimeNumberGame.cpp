#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: https://codejam.lge.com/problem/19595
 * Solution: Using sieve prime number + pre calculate
 *
 * TC: O (n log n)
 * MC: O(n)
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
int n, a, k;

vi sum;

void preCal() {
    vb a(ms, true);
    a[0] = a[1] = false;
    for (int i = 2; i * i < ms; i++) {
        if (a[i]) {
            for (int j = i * i; j <= ms; j += i) a[j] = false;
        }
    }

    vi prime;
    for (int i = 2; i <= ms; i++) {
        if (a[i]) prime.pb(i);
    }

    vb table(ms, true);
    for (int i = 0; i < (int)prime.size(); i++) {
        // fill for case bob lose
        table[prime[i]] = false;
        table[prime[i] + 1] = false;
    }

    for (int i = 2; i <= ms; i++) {
        if (!table[i]) continue;
        for (int j = 0; j < (int)prime.size(); j++) {
            if (i + prime[j] < ms) {
                // fill for case bob lose
                table[i + prime[j]] = false;
            } else
                break;
        }
    }

    sum = vi(ms, 0);
    sum[2] = table[2];
    for (int i = 3; i < ms; i++) {
        sum[i] = sum[i - 1] + table[i];
    }
}

void solve() {
    cin >> a >> k;
    n = a - k + 1;
    int maxX = 0, maxW = 0;

    for (int i = 2; i <= n; i++) {
        int w = sum[i + k - 1] - sum[i - 1];
        if (maxW < w) {
            maxW = w;
            maxX = i;
        }
    }
    cout << maxW << " " << maxX << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    preCal();

    int tcs;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}