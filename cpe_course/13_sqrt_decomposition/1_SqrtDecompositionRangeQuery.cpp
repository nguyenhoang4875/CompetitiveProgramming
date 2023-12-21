#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: Sum in range with sqrt decomposition in array length n
 * sum: [l, r] => O(sqrt(n))
 * update: a[i] = x; => b[i / m] += x - a[i] (m = sqrt(n) + 1)
 *
 *
 * TC: O(sqrt(n))
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
int a[ms];

void solve() {
    cin >> n;
    For(i, 0, n - 1) cin >> a[i];
    int m = sqrt(n) + 1;
    vi b(m);
    For(i, 0, n - 1) { b[i / m] += a[i]; }
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        int i = l;
        int sum = 0;
        while (i <= r) {
            // complete int a segment
            if (i % m == 0 && i + m - 1 <= r) {
                sum += b[i / m];
                i += m;
            } else {
                sum += a[i];
                i++;
            }
        }
        cout << sum << el;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs;
    tcs = 1;
    while (tcs--) {
        solve();
    }
    return 0;
}